#include <stdio.h>
#include <stdlib.h>

#include <ofw/unittest.h>
#include <ofw/bit.h>

#include "test_bit.h"

int main(int argc, char *argv[])
{
    ofw_UnitTest_init();
    ofw_UnitTest_assert(test_Bit());
    ofw_UnitTest_assert(test_DynArray());
    ofw_UnitTest_exitIfFailed();
    printf("OK\n");
    return EXIT_SUCCESS;
}
