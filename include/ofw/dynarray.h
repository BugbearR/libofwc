#ifndef ofw_DynArray_H_
#define ofw_DynArray_H_

#ifdef ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdint.h>

#ifndef ofw_Base_H
#include "ofw/base.h"
#endif

typedef struct ofw_DynArray_tag
{
    int32_t elementSize;
    int32_t length;
    int32_t capacity;
    void *pBuffer;
} ofw_DynArray_t;

/**
 * @brief initialize
 * 
 * @param[in,out] pThis Object
 * @param elementSize size of element
 */
void ofw_DynArray_init(ofw_DynArray_t *pThis, int32_t elementSize);

/**
 * @brief finalize
 * 
 * @param[in,out] pThis Object
 */
void ofw_DynArray_final(ofw_DynArray_t *pThis);

/**
 * @brief set state
 * 
 * @param[out] pThis Object
 * @param elementSize size of element
 * @param length count of element
 * @param pBuffer pointer to buffer
 */
void ofw_DynArray_setState(ofw_DynArray_t *pThis, int32_t elementSize, int32_t length, void *pBuffer);

/**
 * @brief copy state
 * 
 * @param[out] pThis Object
 * @param[in] pSrc source object
 * @param[out] pOutError error code
 */
ofw_Result_t ofw_DynArray_moveState(ofw_DynArray_t *pThis, ofw_DynArray_t *pSrc, ofw_Error_t *pOutError);

/**
 * @brief get pointer to element
 * 
 * @param pThis Object
 * @param index index of element
 * @return void* pointer to element 
 */
void *ofw_DynArray_getPtr(ofw_DynArray_t *pThis, int32_t index);

/**
 * @brief get pointer to element (macro ver.)
 * 
 * @param pThis Object
 * @param index index of element
 * @return void* pointer to element 
 */
#define ofw_DynArray_getPtrM(pThis, index) ((void*)(((char*)pThis->pBuffer) + pThis->elementSize * (index)))



/**
 * @brief insert
 * 
 * @param pThis Object
 * @param from start index
 * @param length length
 * @param[out] pOutError error code
 * @return result
 */
ofw_Result_t ofw_DynArray_insertFromLen(ofw_DynArray_t *pThis, int32_t from, int32_t length, ofw_Error_t *pOutError);

/**
 * @brief delete
 * 
 * @param pThis Object
 * @param from from index
 * @param length length
 * @param[out] pOutError error code
 * @return result
 */
ofw_Result_t ofw_DynArray_deleteFromLen(ofw_DynArray_t *pThis, int32_t from, int32_t length, ofw_Error_t *pOutError);

/**
 * @brief delete
 * 
 * @param pThis Object
 * @param from from index
 * @param to to index
 * @param[out] pOutError error code
 * @return result
 */
#define ofw_DynArray_deleteFromTo(pThis, from, to, pOutError) \
    ofw_DynArray_deleteFromLen(pThis, from, to - from, pOutError)

#endif /* ofw_DynArray_H_ */
