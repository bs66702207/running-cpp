/**
 * Copyright (c) 2012-2018
 * All Rights Reserved by Thunder Software Technology Co., Ltd and its affiliates.
 * You may not use, copy, distribute, modify, transmit in any form this file
 * except in compliance with THUNDERSOFT in writing by applicable law.
 */

#ifndef COM_TSDL_ERR_EXCEPTIONS_H
#define COM_TSDL_ERR_EXCEPTIONS_H

#include <exception>

namespace com {

namespace tsdl {

namespace err {

class illegal_state : public std::exception {
public:
	illegal_state(const char *_desc) : desc(_desc) {};
	illegal_state(const std::string& _desc) : desc(_desc) {};

	inline virtual const char *what() const noexcept {
		return desc.c_str();
	}

private:
	const std::string desc;
};

}; // namespace err

}; // namespace tsdl

}; // namespace com

#endif
