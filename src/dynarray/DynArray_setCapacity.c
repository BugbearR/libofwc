#include <ofw/dynarray.h>

#include <stdlib.h>
#include <ofw/error.h>
#include <ofw/safecalc.h>

ofw_Result_t ofw_DynArray_setCapacity(ofw_DynArray_t *pThis, int32_t capacity, ofw_Error_t *pOutError)
{
    ofw_Error_t myError = ofw_Error_ERROR;
    ofw_Result_t myResult = ofw_Result_FAILED;

    if (!pThis)
    {
        myError = ofw_Error_INVALID_OBJECT | ofw_Error_PARAM1;
        goto EXIT_FUNC;
    }

    if (capacity < pThis->length)
    {
        myError = ofw_Error_TOO_SMALL | ofw_Error_PARAM2;
        goto EXIT_FUNC;
    }

    if (pThis->capacity != capacity)
    {
        if (!ofw_SafeCalc_canMul_size((size_t)pThis->elementSize, (size_t)capacity))
        {
            myError = ofw_Error_OVERFLOW | ofw_Error_PARAM3;
            goto EXIT_FUNC;
        }

        size_t charLen = (size_t)pThis->elementSize * (size_t)capacity;

        void *pNewBuffer = realloc(pThis->pBuffer, charLen);
        if (!pNewBuffer)
        {
            myError = ofw_Error_OUT_OF_MEMORY;
            goto EXIT_FUNC;
        }

        pThis->capacity = capacity;
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
