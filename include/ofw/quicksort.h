#ifndef ofw_QuickSort_H_
#define ofw_QuickSort_H_

#include <stddef.h>

/**
 * @brief compare
 * @param pObj object
 * @param idx1 target index 1
 * @param idx1 target index 2
 * @returns minus: obj[idx1] < obj[idx2], 0: obj[idx1] == obj[idx2], plus: obj[idx1] > obj[idx2]
 */
typedef int (*ofw_QuickSort_compareFn_t)(void *pObj, size_t idx1, size_t idx2);

/**
 * @brief swap
 * @param pObj object
 * @param idx1 target index 1
 * @param idx1 target index 2
 */
typedef void (*ofw_QuickSort_swapFn_t)(void *pObj, size_t idx1, size_t idx2);

/**
 * @brief sort
 * @param pObj object
 * @param n dataCount
 * @param compareFn compare function
 * @param swapFn swap function
 */
void ofw_QuickSort_sort(void *pObj, size_t n,
    ofw_QuickSort_compareFn_t compareFn,
    ofw_QuickSort_swapFn_t swapFn);

#endif /* ofw_QuickSort_H_ */
