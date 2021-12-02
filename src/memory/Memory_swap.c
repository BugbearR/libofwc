#include <ofw/memory.h>

void ofw_Memory_swap(void *p1, void *p2, size_t length)
{
    char *p1w = p1;
    char *p2w = p2;
    char tmp;
    size_t lw;

    for (lw = length; lw > 0; --lw)
    {
        tmp = *p1w;
        *p1w++ = *p2w;
        *p2w++ = tmp;
    }
}
