#include <ofw/vararray.h>

void Ofw_VarArray_init(Ofw_VarArray_t *pThis, int32_t elementSize)
{
    *pThis = (Ofw_VarArray_t){
        .elementSize = elementSize
    };
}
