#ifndef ofw_Base_H_
#define ofw_Base_H_

#ifdef ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdint.h>

/**
 * @brief suppress unused parameter warning
 */
#define ofw_UNUSED(x) ((void)(sizeof(x)))

/** simple result code (r<0: error, r>=0: no error) */
typedef int32_t ofw_Result_t;

// FAIL, FAILED, FAILURE, ERROR
#define ofw_Result_FAILED (-1)
// SUCCEED, SUCCEEDED, SUCCESS, SUCCESSFUL, OK
#define ofw_Result_SUCCEEDED (0)

#define ofw_Result_isFailed(result) (result < 0)
#define ofw_Result_isSucceeded(result) (result >= 0)

typedef int32_t ofw_Error_t;

#endif /* ofw_Base_H_ */
