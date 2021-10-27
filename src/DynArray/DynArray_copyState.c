#include <ofw/DynArray.h>

void ofw_DynArray_copyState(ofw_DynArray_t *pThis, ofw_DynArray_t *pSrc)
{
    pThis->elementSize = pSrc->elementSize;
    pThis->length = pSrc->length;
    pThis->pBuffer = pSrc->pBuffer;
}
