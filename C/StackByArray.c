#include "StackByArray.h"

PSTACK InitStack(int stackSize) {
    PSTACK pStack = malloc(sizeof(STACK));
    if (pStack == NULL)
        return NULL;

    pStack->maxSize = stackSize;
    pStack->data = calloc(pStack->maxSize, sizeof(DATA_TYPE));
    if (pStack->data == NULL) {
        free(pStack);
        return NULL;
    }

    pStack->top = -1;
    return pStack;
}

bool isStackFull(PSTACK pStack) {
    return pStack->top == pStack->maxSize;
}

bool isStackEmpty(PSTACK pStack) {
    return pStack->top == -1;
}

bool PushStack(PSTACK pStack, DATA_TYPE data) {
    if (isStackFull(pStack))
        return false;

    pStack->data[++(pStack->top)] = data;

    return true;
}

bool TopStack(PSTACK pStack, DATA_TYPE *data) {
    if (isStackEmpty(pStack))
        return false;

    *data = pStack->data[pStack->top];

    return true;
}

bool PopStack(PSTACK pStack, DATA_TYPE *data) {
    if (isStackEmpty(pStack))
        return false;

    *data = pStack->data[(pStack->top)--];

    return true;
}

void DeinitStack(PSTACK pStack) {
    free(pStack->data);
    free(pStack);
}