#include <ofw/dynarray.h>

#include <stdlib.h>
#include <ofw/error.h>

ofw_Result_t ofw_DynArray_shrink(ofw_DynArray_t *pThis, ofw_Error_t *pOutError)
{
    ofw_Error_t myError = ofw_Error_ERROR;
    ofw_Result_t myResult = ofw_Result_FAILED;

    if (!pThis)
    {
        myError = ofw_Error_INVALID_OBJECT | ofw_Error_PARAM1;
        goto EXIT_FUNC;
    }

    if (pThis->length == 0)
    {
        if (pThis->pBuffer)
        {
            free(pThis->pBuffer);
            pThis->capacity = 0;
            pThis->pBuffer = NULL;
        }
    }
    else
    {
        size_t charLen = (size_t)pThis->elementSize * (size_t)pThis->length;

        void *pNewBuffer = realloc(pThis->pBuffer, charLen);
        if (!pNewBuffer)
        {
            myError = ofw_Error_OUT_OF_MEMORY;
            goto EXIT_FUNC;
        }

        pThis->capacity = pThis->capacity;
        pThis->pBuffer = pNewBuffer;
    }

    myResult = ofw_Result_SUCCEEDED;
    myError = ofw_Error_NO_ERROR;

EXIT_FUNC:
    if (pOutError && myError != ofw_Error_NO_ERROR)
    {
        *pOutError = myError;
    }

    return myResult;
}
