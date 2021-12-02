#include <ofw/unittest.h>
#include <ofw/bit.h>

int test_Bit_toBaseMask() {
    ofw_UnitTest_init();
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toBaseMask(UINT32, 0), UINT32_C(0x00000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toBaseMask(UINT32, 1), UINT32_C(0x00000001));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toBaseMask(UINT32, 2), UINT32_C(0x00000003));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toBaseMask(UINT32, 30), UINT32_C(0x3fffffff));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toBaseMask(UINT32, 31), UINT32_C(0x7fffffff));
    ofw_UnitTest_return();
}

int test_Bit_toMask() {
    ofw_UnitTest_init();
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 1, 0), UINT32_C(0x00000001));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 1, 31), UINT32_C(0x80000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 2, 0), UINT32_C(0x00000003));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 2, 30), UINT32_C(0xc0000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 31, 0), UINT32_C(0x7fffffff));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_toMask(UINT32, 31, 1), UINT32_C(0xfffffffe));
    ofw_UnitTest_return();
}

int test_Bit_getMasked() {
    ofw_UnitTest_init();
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 1, 0), UINT32_C(0x00000001));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 1, 31), UINT32_C(0x80000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xfffffffe, 1, 0), UINT32_C(0x00000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0x7fffffff, 1, 31), UINT32_C(0x00000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 2, 0), UINT32_C(0x00000003));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 2, 30), UINT32_C(0xc0000000));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 31, 0), UINT32_C(0x7fffffff));
    ofw_UnitTest_assertEqualsUInt32(ofw_Bit_getMasked(UINT32, 0xffffffff, 31, 1), UINT32_C(0xfffffffe));
    ofw_UnitTest_return();
}

int test_Bit() {
    ofw_UnitTest_init();
    ofw_UnitTest_assert(test_Bit_toBaseMask());
    ofw_UnitTest_assert(test_Bit_toMask());
    ofw_UnitTest_assert(test_Bit_getMasked());
    ofw_UnitTest_return();
}
