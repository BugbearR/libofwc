#include <ofw/dynarray.h>

#include <stddef.h>
#include <memory.h>
#include <ofw/error.h>
#include <ofw/safecalc.h>

ofw_Result_t ofw_DynArray_deleteFromLen(ofw_DynArray_t *pThis, int32_t from, int32_t length, ofw_Error_t *pOutError)
{
    ofw_Result_t myResult = ofw_Result_FAILED;
    ofw_Error_t myError = ofw_Error_ERROR;

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

    if (length < 0 || pThis->length - from < length)
    {
        myError = ofw_Error_OUT_OF_RANGE | ofw_Error_PARAM3;
        goto EXIT_FUNC;
    }

    if (length > 0)
    {
        int32_t moveCount = pThis->length - (from + length);
        if (moveCount > 0)
        {
            void *pDst = ofw_DynArray_getPtrM(pThis, from);
            void *pSrc = ofw_DynArray_getPtrM(pThis, from + length);
            size_t charLen = (size_t)pThis->elementSize * (size_t)moveCount;
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
