#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef int DATA_TYPE;

typedef struct {
    DATA_TYPE *data;
    int top;
    int maxSize;
} STACK, *PSTACK;

PSTACK InitStack(int stackSize);
void DeinitStack(PSTACK pStack);
bool PushStack(PSTACK pStack, DATA_TYPE data);
bool TopStack(PSTACK pStack, DATA_TYPE *data);
bool PopStack(PSTACK pStack, DATA_TYPE *data);

#endif