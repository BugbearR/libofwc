#include <ofw/dynarray.h>

#include <stddef.h>
#include <ofw/error.h>

ofw_Result_t ofw_DynArray_moveState(ofw_DynArray_t *pThis, ofw_DynArray_t *pSrc, ofw_Error_t *pOutError)
{
    ofw_Result_t myResult = ofw_Result_FAILED;
    ofw_Error_t myError = ofw_Error_ERROR;

    if (!pThis)
    {
        myError = ofw_Error_INVALID_OBJECT | ofw_Error_PARAM1;
        goto EXIT_FUNC;
    }

    if (!pSrc)
    {
        myError = ofw_Error_INVALID_OBJECT | ofw_Error_PARAM2;
        goto EXIT_FUNC;
    }

    pThis->elementSize = pSrc->elementSize;
    pThis->length = pSrc->length;
    pThis->capacity = pSrc->capacity;
    pThis->pBuffer = pSrc->pBuffer;

    pSrc->length = 0;
    pSrc->capacity = 0;
    pSrc->pBuffer = NULL;

    myResult = ofw_Result_SUCCEEDED;
    myError = ofw_Error_NO_ERROR;

EXIT_FUNC:
    if (pOutError && myError != ofw_Error_NO_ERROR)
    {
        *pOutError = myError;
    }

    return myResult;
}
