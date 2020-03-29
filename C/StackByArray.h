#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include <stdbool.h>

typedef struct {
    void *array;
    size_t len;
} DATA, *PDATA;

typedef struct {
    PDATA data;
    size_t top;
    size_t maxSize;
} STACK, *PSTACK;

PSTACK InitStack(size_t);
void DeinitStack(PSTACK);
bool PushStack(PSTACK, void *, size_t);
bool TopStack(PSTACK, void *, size_t *);
bool PopStack(PSTACK, void *, size_t *);
void ClearStack(PSTACK pStack);

#endif