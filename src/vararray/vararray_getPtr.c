#include <ofw/vararray.h>

void *Ofw_VarArray_getPtr(Ofw_VarArray_t *pThis, int32_t pos)
{
    assert(!pThis);
    assert(0 <= pos && pos < pThis->length);
    return (void*)(((char*)pThis->pBuffer) + pThis->elementSize * pos);
}
