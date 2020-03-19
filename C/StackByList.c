#include "StackByList.h"


PSTACK InitStack() {
    PSTACK pStack = malloc(sizeof(STACK));
    if (pStack == NULL)
        return NULL;

    pStack->top = NULL;

    return pStack;
}

bool isStackEmpty(PSTACK pStack) {
    return pStack->top == NULL;
}

bool PushStack(PSTACK pStack, DATA_TYPE data) {
    PNODE pNode = malloc(sizeof(NODE));
    if (pNode == NULL)
        return false;
    
    pNode->data = data;
    pNode->next = pStack->top;
    pStack->top = pNode;
    
    return true;
}

bool TopStack(PSTACK pStack, DATA_TYPE *data) {
    if (isStackEmpty(pStack) || data == NULL)
        return false;

    *data = pStack->top->data;

    return true;
}

bool PopStack(PSTACK pStack, DATA_TYPE *data) {
    if (isStackEmpty(pStack))
        return false;

    if (data != NULL)
        *data = pStack->top->data;

    PNODE pNode = pStack->top;
    pStack->top = pStack->top->next;
    free(pNode);

    return true;
}

void ClearStack(PSTACK pStack) {
    while (!isStackEmpty(pStack))
        PopStack(pStack, NULL);
}

void DeinitStack(PSTACK pStack) {
    ClearStack(pStack);
    free(pStack);
}