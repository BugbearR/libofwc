#include <ofw/dynarray.h>

void ofw_DynArray_setState(ofw_DynArray_t *pThis, int32_t elementSize, int32_t length, void *pBuffer)
{
    pThis->elementSize = elementSize;
    pThis->length = length;
    pThis->pBuffer = pBuffer;
}
