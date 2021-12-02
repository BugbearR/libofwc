#ifndef ofw_Memory_H_
#define ofw_Memory_H_

#include <stddef.h>

/**
 * @brief Swap memory
 *
 * @param p1 pointer of the memory 1
 * @param p2 pointer of the memory 2
 * @param size length in char units
 */
void ofw_Memory_swap(void *p1, void *p2, size_t length);

#endif /* ofw_Memory_H_ */
