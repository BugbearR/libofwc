#include <ofw/DynArray.h>

void ofw_DynArray_final(ofw_DynArray_t *pThis)
{
    if (!pThis) return;

    if (pThis->pBuffer) {
        free(pThis->pBuffer);
        pThis->pBuffer = 0;
        pThis->length = 0;
    }
}
