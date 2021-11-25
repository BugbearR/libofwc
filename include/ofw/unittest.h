#ifndef ofw_UnitTest_H_
#define ofw_UnitTest_H_

#ifdef ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdlib.h>
#include <stdio.h>

#define ofw_UnitTest_init() \
    int ofw_UnitTest_isSucceededFlag = 1;

#define ofw_UnitTest_return() \
    return ofw_UnitTest_isSucceededFlag;

#define ofw_UnitTest_returnIfFailed() \
    if (!ofw_UnitTest_isSucceededFlag) return 0;

#define ofw_UnitTest_exitIfFailed() \
    if (!ofw_UnitTest_isSucceededFlag) exit(EXIT_FAILURE);

#define ofw_UnitTest_assert(expr) \
    do { \
        if (!(expr)) { \
            printf("%s(%d):%s:%s failed.\n", __FILE__, __LINE__, __func__, #expr); \
            ofw_UnitTest_isSucceededFlag = 0; \
        } \
    } while (0)

#define ofw_UnitTest_assertExit(expr) \
    do { \
        if (!(expr)) { \
            printf("%s(%d):%s:%s failed.\n", __FILE__, __LINE__, __func__, #expr); \
            return 0; \
        } \
    } while (0)

#define ofw_UnitTest_assertEquals(type, pritype, expr, exprStr, expected) \
    do { \
        type actual = (expr); \
        if (actual != (expected)) { \
            printf("%s(%d):%s:Failed. expr: \"%s\", actual: %" pritype ", expected: %" pritype "\n", __FILE__, __LINE__, __func__, exprStr, actual, expected); \
            ofw_UnitTest_isSucceededFlag = 0; \
        } \
    } while (0)

#define ofw_UnitTest_assertEqualsInt32(expr, expected) \
    ofw_UnitTest_assertEquals(int32_t, PRId32, expr, #expr, expected)

#define ofw_UnitTest_assertEqualsUint32(expr, expected) \
    ofw_UnitTest_assertEquals(uint32_t, PRIu32, expr, #expr, expected)

#endif /* ofw_UnitTest_H_ */