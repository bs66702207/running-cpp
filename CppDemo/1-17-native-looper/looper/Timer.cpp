/**
 * Copyright (c) 2012-2018
 * All Rights Reserved by Thunder Software Technology Co., Ltd and its affiliates.
 * You may not use, copy, distribute, modify, transmit in any form this file
 * except in compliance with THUNDERSOFT in writing by applicable law.
 */

#include <Timer.h>

#include <system_error>

#include <unistd.h>

#include <compiler.h>

namespace com {

namespace tsdl {

namespace util {

using namespace std;

Timer::Timer(int clockid, function<void ()> handler)
{
	if (unlikely(handler == nullptr))
		throw invalid_argument("Handler must not be null");

	mTimer = timerfd_create(clockid, TFD_CLOEXEC);
	if (unlikely(mTimer < 0))
		throw system_error(errno, system_category(),
					"Calling timerfd_create() failed.");

	mHandler = handler;
}

Timer::~Timer()
{
	close(mTimer);
}

int Timer::setTime(int flags,
		const struct itimerspec *new_value,
					struct itimerspec *old_value)
{
	return timerfd_settime(mTimer, flags, new_value, old_value);
}

int Timer::getTime(struct itimerspec *curr_value)
{
	return timerfd_gettime(mTimer, curr_value);
}

void Timer::cancel()
{
	struct itimerspec ts = { { 0, 0 }, { 0, 0 } };

	timerfd_settime(mTimer, 0, &ts, NULL);
}

}; // namespace util

}; // namespace tsdl

}; // namespace com
