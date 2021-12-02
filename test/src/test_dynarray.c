#include <ofw/unittest.h>
#include <ofw/dynarray.h>

int test_DynArray_insertFromLen1() {
    ofw_Result_t subResult;
    ofw_Error_t subError = 0;
    ofw_DynArray_t a;
    int32_t i;

    ofw_UnitTest_init();

    ofw_DynArray_init(&a, sizeof(int32_t));
    int32_t v;

    for (i = 0; i < 10; i++)
    {
        subResult = ofw_DynArray_insertFromLen(&a, 0, 1, &subError);
        ofw_UnitTest_assert(ofw_Result_isSucceeded(subResult));
        ofw_UnitTest_assertEqualsError(subError, 0);
        ofw_UnitTest_assert(a.pBuffer);
        ofw_UnitTest_assert(a.length == i + 1);
        ofw_UnitTest_assert(a.capacity >= a.length);
        ofw_UnitTest_exitIfFailed();
        *(int32_t *)ofw_DynArray_getPtrM(&a, 0) = i;
    }

    for (i = 0; i < 10; i++)
    {
        ofw_UnitTest_assertEqualsInt32(*(int32_t *)ofw_DynArray_getPtrM(&a, i), 9 - i);;
    }

    ofw_DynArray_final(&a);
    ofw_UnitTest_return();
}

int test_DynArray() {
    ofw_UnitTest_init();
    ofw_UnitTest_assert(test_DynArray_insertFromLen1());
    ofw_UnitTest_return();
}
