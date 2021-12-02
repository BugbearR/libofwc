#ifndef ofw_Base_H_
#define ofw_Base_H_

#ifdef ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdint.h>
#include <inttypes.h>

#include <ofw/local/base.h>

/* redefine raw type to single name */
typedef char char_t;
typedef short short_t;
typedef int int_t;
typedef long long_t;
typedef long long llong_t;

typedef signed char schar_t;

typedef unsigned char uchar_t;
typedef unsigned short ushort_t;
typedef unsigned int uint_t;
typedef unsigned long ulong_t;
typedef unsigned long long ullong_t;

/**
 * @brief suppress unused parameter warning
 */
#define ofw_UNUSED(x) ((void)(sizeof(x)))

/** simple result code (r<0: error, r>=0: no error) */
typedef int32_t ofw_Result_t;
#define ofw_Result_PRId PRId32

// FAIL, FAILED, FAILURE, ERROR
#define ofw_Result_FAILED (-1)
// SUCCEED, SUCCEEDED, SUCCESS, SUCCESSFUL, OK
#define ofw_Result_SUCCEEDED (0)

#define ofw_Result_isFailed(result) (result < 0)
#define ofw_Result_isSucceeded(result) (result >= 0)

typedef int32_t ofw_Error_t;
#define ofw_Error_PRIx PRIx32

#define ofw_Array_getLength(a) (sizeof(a)/sizeof((a)[0]))

#endif /* ofw_Base_H_ */
