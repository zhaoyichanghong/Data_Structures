#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H

#include <stdbool.h>

typedef struct {
    void *array;
    size_t len;
} DATA, *PDATA;

typedef struct Node{
    DATA data;
    struct Node *next;
} NODE, *PNODE;

typedef struct {
    PNODE top;
} STACK, *PSTACK;

PSTACK InitStack();
void DeinitStack(PSTACK);
bool PushStack(PSTACK, const void *, size_t);
bool TopStack(PSTACK, void *, size_t *);
bool PopStack(PSTACK, void *, size_t *);
void ClearStack(PSTACK);

#endif