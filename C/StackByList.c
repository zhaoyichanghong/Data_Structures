#include <stdlib.h>
#include <string.h>
#include "StackByList.h"

PSTACK InitStack() {
    PSTACK pStack = malloc(sizeof(STACK));
    if (pStack == NULL)
        return NULL;

    pStack->top = NULL;

    return pStack;
}

static bool IsStackEmpty(PSTACK pStack) {
    if (pStack == NULL)
        return true;

    return pStack->top == NULL;
}

bool PushStack(PSTACK pStack, const void *data, int nBytes) {
    if (pStack == NULL || data == NULL)
        return false;

    PNODE pNode = malloc(sizeof(NODE));
    if (pNode == NULL)
        return false;
    
    void *mem = malloc(nBytes);
    if (mem == NULL) {
        free(pNode);
        return false;
    }

    memcpy(mem, data, nBytes);
    pNode->data.array = mem;
    pNode->data.len = nBytes;
    pNode->next = pStack->top;
    pStack->top = pNode;
    
    return true;
}

bool TopStack(PSTACK pStack, void *data, int *nBytes) {
    if (pStack == NULL || IsStackEmpty(pStack) || data == NULL || nBytes == NULL)
        return false;

    if (*nBytes < pStack->top->data.len) {
        *nBytes = pStack->top->data.len;
        return false;
    }

    memcpy(data, pStack->top->data.array, pStack->top->data.len);

    return true;
}

bool PopStack(PSTACK pStack, void *data, int *nBytes) {
    if (pStack == NULL || IsStackEmpty(pStack))
        return false;

    if (data != NULL && nBytes != NULL) {
        if (*nBytes < pStack->top->data.len) {
            *nBytes = pStack->top->data.len;
            return false;
        }

        memcpy(data, pStack->top->data.array, pStack->top->data.len);
    }

    PNODE pNode = pStack->top;
    pStack->top = pStack->top->next;
    free(pNode->data.array);
    free(pNode);

    return true;
}

void ClearStack(PSTACK pStack) {
    if (pStack == NULL)
        return;

    while (!IsStackEmpty(pStack))
        PopStack(pStack, NULL, NULL);
}

void DeinitStack(PSTACK pStack) {
    if (pStack == NULL)
        return;

    ClearStack(pStack);
    free(pStack);
}