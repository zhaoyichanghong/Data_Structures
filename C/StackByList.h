#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H

#include <stdbool.h>

typedef struct {
    void *array;
    int len;
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
bool PushStack(PSTACK, const void *, int);
bool TopStack(PSTACK, void *, int *);
bool PopStack(PSTACK, void *, int *);
void ClearStack(PSTACK);

#endif