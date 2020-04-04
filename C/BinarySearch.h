#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

typedef int (*COMPARE)(const void *, const void*);

size_t BinarySearch(void *, size_t, size_t, void *, COMPARE);

#endif