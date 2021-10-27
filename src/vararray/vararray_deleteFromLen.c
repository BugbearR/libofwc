#include <ofw/vararray.h>

Ofw_Result_t Ofw_VarArray_deleteFromLen(Ofw_VarArray_t *pThis, int32_t from, int32_t length, Ofw_Error_t *pOutError)
{
    Ofw_Result_t myResult = Ofw_Result_FAILED;
    Ofw_Error_t myError = Ofw_Error_UNKNOWN;
    if (!pThis)
    {
        goto EXIT_FUNC;
    }

    if (from < 0 || pThis->length < from)
    {
        myError = Ofw_Error_OUT_OF_RANGE | Ofw_Error_PARAM2;
        goto EXIT_FUNC;
    }

    if (length < 0 || pThis->length < from + length)
    {
        myError = Ofw_Error_OUT_OF_RANGE | Ofw_Error_PARAM3;
        goto EXIT_FUNC;
    }

    pThis->elementSize = elementSize;
    pThis->length = length;
    pThis->pBuffer = pBuffer;

    myError = Ofw_Error_NONE;
    myResult = Ofw_Result_SUCCEEDED;

EXIT_FUNC:
    if (pOutError)
    {
        *pOutError = myError;
    }

    return myResult;
}
