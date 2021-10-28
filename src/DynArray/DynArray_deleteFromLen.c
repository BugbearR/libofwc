#include <ofw/DynArray.h>

#include <ofw/error.h>

ofw_Result_t ofw_DynArray_deleteFromLen(ofw_DynArray_t *pThis, int32_t from, int32_t length, ofw_Error_t *pOutError)
{
    ofw_Result_t myResult = ofw_Result_FAILED;
    ofw_Error_t myError = ofw_Error_UNKNOWN;
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

    if (length < 0 || pThis->length < from + length)
    {
        myError = ofw_Error_OUT_OF_RANGE | ofw_Error_PARAM3;
        goto EXIT_FUNC;
    }

    if (length > 0)
    {
        void *pSrc = ofw_DynArray_getPtrM(pThis, from + length);
        void *pDst = ofw_DynArray_getPtrM(pThis, from);
        size_t charLen = pThis->elementSize * length;
        memmove(pDst, pSrc, charLen);
        pThis->length -= length;
    }

    myError = ofw_Error_NONE;
    myResult = ofw_Result_SUCCEEDED;

EXIT_FUNC:
    if (pOutError)
    {
        *pOutError = myError;
    }

    return myResult;
}
