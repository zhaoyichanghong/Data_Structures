#ifndef QSORT_H
#define QSORT_H

typedef int (*COMPARE)(const void *, const void*);

void Qsort(void *, size_t, size_t, COMPARE);

#endif