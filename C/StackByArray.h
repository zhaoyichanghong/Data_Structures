#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include <stdbool.h>

typedef struct Data {
    void *array;
    int len;
} DATA, *PDATA;

typedef struct {
    PDATA data;
    int top;
    int maxSize;
} STACK, *PSTACK;

PSTACK InitStack(int);
void DeinitStack(PSTACK);
bool PushStack(PSTACK, void *, int);
bool TopStack(PSTACK, void *, int *);
bool PopStack(PSTACK, void *, int *);
void ClearStack(PSTACK pStack);

#endif