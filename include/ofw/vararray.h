#ifndef Ofw_VarArray_H_
#define Ofw_VarArray_H_ 1

#ifdef Ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdint.h>

#ifndef Ofw_Base_H
#include "ofw/base.h"
#endif

typedef struct Ofw_VarArray_tag
{
    int32_t elementSize;
    int32_t length;
    void *pBuffer;
} Ofw_VarArray_t;

/**
 * @brief initialize
 * 
 * @param[in,out] pThis Object
 * @param elementSize size of element
 */
void Ofw_VarArray_init(Ofw_VarArray_t *pThis, int32_t elementSize);

/**
 * @brief finalize
 * 
 * @param[in,out] pThis Object
 */
void Ofw_VarArray_final(Ofw_VarArray_t *pThis);

/**
 * @brief set state
 * 
 * @param pThis Object
 * @param elementSize size of element
 * @param length count of element
 * @param pBuffer pointer to buffer
 */
void Ofw_VarArray_setState(Ofw_VarArray_t *pThis, int32_t elementSize, int32_t length, void *pBuffer);

/**
 * @brief copy state
 * 
 * @param pThis Object
 * @param pSrc source object
 */
void Ofw_VarArray_copyState(Ofw_VarArray_t *pThis, Ofw_VarArray_t *pSrc);

/**
 * @brief get pointer to element
 * 
 * @param pThis Object
 * @param index index of element
 * @return void* pointer to element 
 */
void *Ofw_VarArray_getPtr(Ofw_VarArray_t *pThis, int32_t index);

/**
 * @brief get pointer to element (macro ver.)
 * 
 * @param pThis Object
 * @param index index of element
 * @return void* pointer to element 
 */
#define Ofw_VarArray_getPtrM(pThis, index) ((void*)(((char*)pThis->pBuffer) + pThis->elementSize * (index)))

#endif /* Ofw_VarArray_H_ */
