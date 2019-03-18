#ifndef COM_TSDL_UTIL_COMPILER_H
#define COM_TSDL_UTIL_COMPILER_H

#ifndef likely
#define likely(x)   __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#endif
