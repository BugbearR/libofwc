#include <ofw/DynArray.h>

void *ofw_DynArray_getPtr(ofw_DynArray_t *pThis, int32_t pos)
{
    assert(!pThis);
    assert(0 <= pos && pos < pThis->length);
    return (void*)(((char*)pThis->pBuffer) + pThis->elementSize * pos);
}
