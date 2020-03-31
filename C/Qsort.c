#include <string.h>
#include <stdlib.h>
#include "Qsort.h"

static void sort(void *array, size_t size, size_t low, size_t high, COMPARE compare) {
    if (array == NULL || size == 0 || compare == NULL || low >= high)
        return;
        
    void *key = malloc(size);
    if (key == NULL)
        return;
    memcpy(key, (char *)array + low * size, size);

    size_t first = low;
    size_t last = high;
    while (first < last) {
        while (first < last && compare(key, (char *)array + last * size) <= 0)
            last--;
        memcpy((char *)array + first * size, (char *)array + last * size, size);

        while (first < last && compare((char *)array + first * size, key) <= 0)
            first++;
        memcpy((char *)array + last * size, (char *)array + first * size, size);
    }

    memcpy((char *)array + first * size, key, size);

    sort(array, size, low, first - 1, compare);
    sort(array, size, first + 1, high, compare);
}

void Qsort(void *array, size_t nItems, size_t size, COMPARE compare) {
    if (array == NULL || nItems == 0 || size == 0 || compare == NULL)
        return;

    sort(array, size, 0, nItems - 1, compare);
}