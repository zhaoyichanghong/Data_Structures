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

PSTACK InitStack(int);
void DeinitStack(PSTACK);
bool PushStack(PSTACK, DATA_TYPE);
bool TopStack(PSTACK, DATA_TYPE *);
bool PopStack(PSTACK, DATA_TYPE *);

#endif