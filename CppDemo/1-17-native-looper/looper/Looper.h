/**
 * Copyright (c) 2012-2018
 * All Rights Reserved by Thunder Software Technology Co., Ltd and its affiliates.
 * You may not use, copy, distribute, modify, transmit in any form this file
 * except in compliance with THUNDERSOFT in writing by applicable law.
 *
 */

#ifndef COM_TSDL_UTIL_LOOPER_H
#define COM_TSDL_UTIL_LOOPER_H

#include <map>
#include <mutex>
#include <queue>
#include <vector>
#include <thread>
#include <functional>

#include <Timer.h>

namespace com {

namespace tsdl {

namespace util {

class Looper {
private:
	static const std::string TAG;

	bool mPrepared;
	std::thread::id mThread;

	std::vector<std::queue<std::function<void ()>> *> mQueues;
	std::vector<std::mutex> *mQueueLocks;

	std::map<int, Timer *> mTimers;
	std::mutex mTimerLock;

	bool mQuit;

	int mPoller;
	int mEvent;

public:
	Looper(int priorities);
	~Looper();

	void prepare();

	void loop();

	void quit();

	void addEvent(int priority, std::function<void ()> event);

	void addTimer(Timer& timer);
	void addTimer(Timer *timer);

	void removeTimer(Timer& timer);
	void removeTimer(Timer *timer);
}; // class Looper

}; // namespace util

}; // namespace tsdl

}; // namespace com

#endif
