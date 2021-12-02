#include <ofw/quicksort.h>

static size_t partition(void *pObj, size_t fromIdx, size_t toIdx,
    ofw_QuickSort_compareFn_t compareFn,
    ofw_QuickSort_swapFn_t swapFn)
{
    if (toIdx - fromIdx <= 1) {
        return fromIdx + 1;
    }

    size_t lo = fromIdx;
    size_t hi = toIdx - 1;
    size_t mid = fromIdx + (hi - lo) / 2;

    if (compareFn(pObj, lo, mid) > 0)
    {
        swapFn(pObj, lo, mid);
    }
    if (compareFn(pObj, mid, hi) > 0)
    {
        swapFn(pObj, mid, hi);
        if (compareFn(pObj, lo, mid) > 0)
        {
            swapFn(pObj, lo, mid);
        }
    }

    for (;;)
    {
        while (compareFn(pObj, lo, mid) < 0)
        {
            lo++;
        }
        while (compareFn(pObj, mid, hi) < 0)
        {
            hi--;
        }
        if (lo >= hi)
        {
            return hi + 1;
        }

        swapFn(pObj, lo, hi);

        // if mid is swapped, update mid.
        if (lo == mid)
        {
            mid = hi;
        }
        else if (hi == mid)
        {
            mid = lo;
        }

        lo++;
        hi--;
    }
}

static void quickSort(void *pObj, size_t fromIdx, size_t toIdx,
    ofw_QuickSort_compareFn_t compareFn,
    ofw_QuickSort_swapFn_t swapFn)
{
    if (toIdx - fromIdx <= 1)
    {
        return;
    }
    size_t partIdx = partition(pObj, fromIdx, toIdx, compareFn, swapFn);
    quickSort(pObj, fromIdx, partIdx, compareFn, swapFn);
    quickSort(pObj, partIdx, toIdx, compareFn, swapFn);
}

void ofw_QuickSort_sort(void *pObj, size_t n,
    ofw_QuickSort_compareFn_t compareFn,
    ofw_QuickSort_swapFn_t swapFn)
{
    if (n <= 1)
    {
        return;
    }
    quickSort(pObj, 0, n, compareFn, swapFn);
}
