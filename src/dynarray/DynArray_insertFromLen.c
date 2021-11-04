#include <ofw/dynarray.h>

#include <stddef.h>
#include <memory.h>
#include <ofw/error.h>
#include <ofw/safecalc.h>

ofw_Result_t ofw_DynArray_insertFromLen(ofw_DynArray_t *pThis, int32_t from, int32_t length, ofw_Error_t *pOutError)
{
    ofw_Result_t myResult = ofw_Result_FAILED;
    ofw_Error_t myError = ofw_Error_ERROR;
    ofw_Result_t subResult = ofw_Result_SUCCEEDED;
    ofw_Error_t subError = ofw_Error_NO_ERROR;

    if (!pThis)
    {
        myError = ofw_Error_INVALID_OBJECT | ofw_Error_PARAM1;
        goto EXIT_FUNC;
    }

    if (from < 0 || pThis->length < from)
    {
        myError = ofw_Error_OUT_OF_RANGE | ofw_Error_PARAM2;
        goto EXIT_FUNC;
    }

    if (length < 0)
    {
        myError = ofw_Error_OUT_OF_RANGE | ofw_Error_PARAM3;
        goto EXIT_FUNC;
    }

    if (length > 0)
    {
        if (!ofw_SafeCalc_canAdd_int32(pThis->length, length))
        {
            myError = ofw_Error_OVERFLOW | ofw_Error_PARAM3;
            goto EXIT_FUNC;
        }

        if (ofw_Result_isFailed(ofw_DynArray_setCapacity(pThis->length + length, &subError)))
        {
            myError = subError;
            goto EXIT_FUNC;
        }

        if (!ofw_SafeCalc_canMul_size((size_t)pThis->elementSize, (size_t)length))
        {
            myError = ofw_Error_OVERFLOW | ofw_Error_PARAM3;
            goto EXIT_FUNC;
        }

        size_t charLen = pThis->elementSize * (pThis->length - from);
        if (charLen > 0)
        {
            void *pDst = pThis->pBuffer + pThis->elementSize * from;
            void *pSrc = pThis->pBuffer + pThis->elementSize * (from + length);
            memmove(pDst, pSrc, charLen);
        }
        pThis->length -= length;
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
