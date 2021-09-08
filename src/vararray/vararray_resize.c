#include <ofw/vararray.h>

Ofw_Result_t Ofw_VarArray_resize(Ofw_VarArray_t *pThis, int32_t length, Ofw_Error_t *pOutError)
{
    Ofw_Error_t myError = Ofw_Error_UNKNOWN;
    if (pThis->length == length)
    {
        return Ofw_Result_SUCCEEDED;
    }

    void *pNewBuffer = realloc(pThis->pBuffer, pThis->elementSize * length);
    if (!pNewBuffer)
    {
        myError = Ofw_Error_NO_MEMORY;
        goto EXIT_FUNC;
    }

    pThis->elementSize = elementSize;
    pThis->length = length;
    pThis->pBuffer = pBuffer;
}
