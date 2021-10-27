#include <ofw/vararray.h>

void Ofw_VarArray_copyState(Ofw_VarArray_t *pThis, Ofw_VarArray_t *pSrc)
{
    pThis->elementSize = pSrc->elementSize;
    pThis->length = pSrc->length;
    pThis->pBuffer = pSrc->pBuffer;
}
