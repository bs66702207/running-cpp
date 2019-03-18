/**
 * Copyright (c) 2012-2018
 * All Rights Reserved by Thunder Software Technology Co., Ltd and its affiliates.
 * You may not use, copy, distribute, modify, transmit in any form this file
 * except in compliance with THUNDERSOFT in writing by applicable law.
 *
 */

#ifndef COM_TSDL_UTIL_TIMER_H
#define COM_TSDL_UTIL_TIMER_H

#include <sys/timerfd.h>

#include <functional>

namespace com {

namespace tsdl {

namespace util {

class Timer {
private:
	int mTimer;
	std::function<void ()> mHandler;

public:
	Timer(int clockid, std::function<void ()> handler);
	~Timer();

	inline int getFd() {
		return mTimer;
	}

	inline std::function<void ()> getHandler() {
		return mHandler;
	}

	int setTime(int flags, const struct itimerspec *new_value,
					struct itimerspec *old_value);
	int getTime(struct itimerspec *curr_value);

	void cancel();
};

}; // namespace util

}; // namespace tsdl

}; // namespace com

#endif
