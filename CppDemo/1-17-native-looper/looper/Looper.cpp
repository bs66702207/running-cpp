/**
 * Copyright (c) 2012-2018
 * All Rights Reserved by Thunder Software Technology Co., Ltd and its affiliates.
 * You may not use, copy, distribute, modify, transmit in any form this file
 * except in compliance with THUNDERSOFT in writing by applicable law.
 */

#include <Looper.h>

#include <assert.h>

#include <algorithm>
#include <system_error>

#include <unistd.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>

#include <compiler.h>
#include <Autolock.h>
#include <Exceptions.h>

namespace com {

namespace tsdl {

namespace util {

using namespace std;
using namespace com::tsdl::err;

const string Looper::TAG = "Looper";

static inline void add_to_epoll(int epoll, int fd)
{
	struct epoll_event event = { EPOLLIN, {0} };

	event.data.fd = fd;

	epoll_ctl(epoll, EPOLL_CTL_ADD, fd, &event);
}

static inline void remove_from_epoll(int epoll, int fd)
{
	epoll_ctl(epoll, EPOLL_CTL_DEL, fd, NULL);
}

Looper::Looper(int priorities)
		: mPrepared(false), mQuit(false)
{
	if (priorities <= 0)
		throw invalid_argument("Priorities cannot be larger than 0.");

	mPoller = epoll_create1(EPOLL_CLOEXEC);
	if (mPoller < 0)
		throw system_error(errno, system_category(),
				"Calling epoll_create1(EPOLL_CLOEXEC) failed.");

#ifndef EFD_SEMAPHORE
#define EFD_SEMAPHORE (1 << 0)
#endif
	mEvent = eventfd(0, EFD_CLOEXEC | EFD_SEMAPHORE);
	if (mEvent < 0) {
		close(mPoller);
		throw system_error(errno, system_category(),
				"Calling eventfd(0, EFD_CLOEXEC | EFD_SEMAPHORE) failed.");
	}

	add_to_epoll(mPoller, mEvent);

	mQueues.reserve(priorities);
	mQueues.resize(priorities);
	generate(mQueues.begin(), mQueues.end(), [] () {
		return new queue<function<void ()>>();
	});

	mQueueLocks = new vector<mutex>(priorities);
}

Looper::~Looper()
{
	for_each(mQueues.begin(), mQueues.end(),
			[] (queue<function<void ()>> *queue) {
		// Will destroy all elements in the queue
		delete queue;
	});
	mQueues.erase(mQueues.begin(), mQueues.end());

	delete mQueueLocks;

	close(mEvent);

	close(mPoller);
}

void Looper::prepare()
{
	if (mPrepared)
		throw illegal_state("Already in use.");

	mPrepared = true;
	mThread = this_thread::get_id();
}

static inline void consumeEvents(int fd)
{
	uint64_t events;

restart:
	auto ret = read(fd, &events, sizeof events);
	if (unlikely(ret < 0)) {
		assert(errno == EINTR);
		goto restart;
	}
}

void Looper::loop()
{
	if (!mPrepared)
		throw illegal_state("Not prepared.");

	if (mThread != this_thread::get_id())
		throw illegal_state("Used in another thread.");

	function<void ()> handler;
	while (!mQuit) {
		struct epoll_event event;

		for (;;) {
			int ret = epoll_wait(mPoller, &event, 1, -1);
			if (likely(ret > 0))
				break;
			assert(errno == EINTR);
		}

		if (event.data.fd == mEvent) {
			for (auto priority = 0; priority < mQueues.capacity(); priority++) {
				auto queue = mQueues[priority];
				if (queue->empty())
					continue;

				{
					Autolock lock((*mQueueLocks)[priority]);
					handler = queue->front();
					queue->pop();
				}
				break;
			}
		} else {
			Autolock lock(mTimerLock);
			if (unlikely(!mTimers.count(event.data.fd)))
				// The time has been just removed
				continue;
			Timer *timer = mTimers[event.data.fd];
			handler = timer->getHandler();
		}

		consumeEvents(event.data.fd);
		handler();
	}
}

void Looper::quit()
{
	addEvent(0, [this] () { mQuit = true; });
}

static inline void notifyEvent(int fd)
{
	uint64_t event = 1;

restart:
	auto ret = write(fd, &event, sizeof event);
	if (unlikely(ret < 0)) {
		assert(errno == EINTR);
		goto restart;
	}
}

void Looper::addEvent(int priority, function<void ()> handler)
{
	if (!handler)
		throw invalid_argument("Handler is invalid.");

	if (priority < 0 || priority >= mQueues.capacity())
		throw invalid_argument("Priority is out of range.");

	{
		Autolock lock((*mQueueLocks)[priority]);
		mQueues[priority]->push(handler);
	}

	notifyEvent(mEvent);
}

void Looper::addTimer(Timer& timer)
{
	addTimer(&timer);
}

void Looper::addTimer(Timer *timer)
{
	add_to_epoll(mPoller, timer->getFd());
	Autolock lock(mTimerLock);
	mTimers[timer->getFd()] = timer;
}

void Looper::removeTimer(Timer& timer)
{
	removeTimer(&timer);
}

void Looper::removeTimer(Timer *timer)
{
	remove_from_epoll(mPoller, timer->getFd());
	Autolock lock(mTimerLock);
	mTimers.erase(timer->getFd());
}

}; // namespace util

}; // namespace tsdl

}; // namespace com
