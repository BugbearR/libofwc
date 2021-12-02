#ifndef ofw_QuickSort_H_
#define ofw_QuickSort_H_

#include <stddef.h>

typedef int (*ofw_QuickSort_compareFn_t)(void *pObj, size_t idx1, size_t idx2);
typedef void (*ofw_QuickSort_swapFn_t)(void *pObj, size_t idx1, size_t idx2);

void ofw_QuickSort_sort(void *pObj, size_t n,
    ofw_QuickSort_compareFn_t compareFn,
    ofw_QuickSort_swapFn_t swapFn);

#endif /* ofw_QuickSort_H_ */
