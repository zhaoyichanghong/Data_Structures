#include <stdlib.h>
#include <string.h>
#include "StackByArray.h"

PSTACK InitStack(int stackSize) {
    if (stackSize == 0)
        return NULL;

    PSTACK pStack = malloc(sizeof(STACK));
    if (pStack == NULL)
        return NULL;

    pStack->maxSize = stackSize;
    pStack->data = calloc(pStack->maxSize, sizeof(DATA));
    if (pStack->data == NULL) {
        free(pStack);
        return NULL;
    }

    pStack->top = -1;
    return pStack;
}

static bool IsStackFull(PSTACK pStack) {
    if (pStack == NULL)
        return false;
        
    return pStack->top == pStack->maxSize - 1;
}

static bool IsStackEmpty(PSTACK pStack) {
    if (pStack == NULL)
        return true;

    return pStack->top == -1;
}

bool PushStack(PSTACK pStack, void *data, int nBytes) {
    if (pStack == NULL || IsStackFull(pStack) || data == NULL)
        return false;

    void *mem = malloc(nBytes);
    if (mem == NULL)
        return false;

    memcpy(mem, data, nBytes);
    ++(pStack->top);
    pStack->data[pStack->top].array = mem;
    pStack->data[pStack->top].len = nBytes;

    return true;
}

bool TopStack(PSTACK pStack, void *data, int *nBytes) {
    if (pStack == NULL || IsStackEmpty(pStack) || data == NULL || nBytes == NULL)
        return false;

    if (*nBytes < pStack->data[pStack->top].len) {
        *nBytes = pStack->data[pStack->top].len;
        return false;
    }

    memcpy(data, pStack->data[pStack->top].array, pStack->data[pStack->top].len);

    return true;
}

bool PopStack(PSTACK pStack, void *data, int *nBytes) {
    if (pStack == NULL || IsStackEmpty(pStack))
        return false;

    if (data != NULL && nBytes != NULL) {
        if (*nBytes < pStack->data[pStack->top].len) {
            *nBytes = pStack->data[pStack->top].len;
            return false;
        }

        memcpy(data, pStack->data[pStack->top].array, pStack->data[pStack->top].len);
    }

    free(pStack->data[pStack->top].array);
    pStack->top--;

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

    free(pStack->data);
    free(pStack);
}