#include <ofw/vararray.h>

void Ofw_VarArray_final(Ofw_VarArray_t *pThis)
{
    if (!pThis) return;

    if (pThis->pBuffer) {
        free(pThis->pBuffer);
        pThis->pBuffer = 0;
        pThis->length = 0;
    }
}
