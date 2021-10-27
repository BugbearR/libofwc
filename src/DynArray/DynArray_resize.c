#include <ofw/DynArray.h>

ofw_Result_t ofw_DynArray_resize(ofw_DynArray_t *pThis, int32_t length, ofw_Error_t *pOutError)
{
    ofw_Error_t myError = ofw_Error_UNKNOWN;
    if (pThis->length == length)
    {
        return ofw_Result_SUCCEEDED;
    }

    void *pNewBuffer = realloc(pThis->pBuffer, pThis->elementSize * length);
    if (!pNewBuffer)
    {
        myError = ofw_Error_NO_MEMORY;
        goto EXIT_FUNC;
    }

    pThis->elementSize = elementSize;
    pThis->length = length;
    pThis->pBuffer = pBuffer;
}
