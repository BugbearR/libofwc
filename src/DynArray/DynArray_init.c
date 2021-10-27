#include <ofw/DynArray.h>

void ofw_DynArray_init(ofw_DynArray_t *pThis, int32_t elementSize)
{
    *pThis = (ofw_DynArray_t){
        .elementSize = elementSize
    };
}
