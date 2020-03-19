#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int DATA_TYPE;

typedef struct Node{
    DATA_TYPE data;
    struct Node *next;
} NODE, *PNODE;

typedef struct {
    PNODE top;
} STACK, *PSTACK;

PSTACK InitStack();
void DeinitStack(PSTACK);
bool PushStack(PSTACK, DATA_TYPE);
bool TopStack(PSTACK, DATA_TYPE *);
bool PopStack(PSTACK, DATA_TYPE *);
void ClearStack(PSTACK);

#endif