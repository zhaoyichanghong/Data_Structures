#include <stdlib.h>
#include "BinarySearch.h"

size_t BinarySearch(void *array, size_t nItems, size_t size, void *data, COMPARE compare) {
    if (array == NULL || nItems == 0 || size == 0 || data == NULL || compare == NULL)
        return -1;

    size_t left = 0;
    size_t right = nItems - 1;
    while (left <= right) {
        size_t mid = (right + left) / 2;

        int ret = compare((char *)array + size * mid, data);
        if (ret == 0)
            return mid;

        if (ret < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}