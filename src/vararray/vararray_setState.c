#include <ofw/vararray.h>

void Ofw_VarArray_setState(Ofw_VarArray_t *pThis, int32_t elementSize, int32_t length, void *pBuffer)
{
    pThis->elementSize = elementSize;
    pThis->length = length;
    pThis->pBuffer = pBuffer;
}
