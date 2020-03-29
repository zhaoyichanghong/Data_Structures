#include <stdlib.h>
#include <string.h>
#include "QueueByArray.h"

PQUEUE InitQueue(int queueSize) {
    if (queueSize == 0)
        return NULL;

    PQUEUE pQueue = malloc(sizeof(QUEUE));
    if (pQueue == NULL)
        return NULL;

    pQueue->maxSize = queueSize;
    pQueue->data = calloc(pQueue->maxSize, sizeof(DATA));
    if (pQueue->data == NULL) {
        free(pQueue);
        return NULL;
    }

    pQueue->front = 0;
    pQueue->size = 0;
    return pQueue;
}

bool isQueueFull(PQUEUE pQueue) {
    if (pQueue == NULL)
        return false;

    return pQueue->size == pQueue->maxSize;
}

bool isQueueEmpty(PQUEUE pQueue) {
    if (pQueue == NULL)
        return true;

    return pQueue->size == 0;
}

bool PushQueue(PQUEUE pQueue, const void *data, int nBytes) {
    if (pQueue == NULL || isQueueFull(pQueue))
        return false;

    void *mem = malloc(nBytes);
    if (mem == NULL)
        return false;

    memcpy(mem, data, nBytes);
    pQueue->data[(pQueue->front + pQueue->size) % pQueue->maxSize].array = mem;
    pQueue->data[(pQueue->front + pQueue->size) % pQueue->maxSize].len = nBytes;
    pQueue->size++;

    return true;
}

bool PopQueue(PQUEUE pQueue, void *data, int *nBytes) {
    if (pQueue == NULL || isQueueEmpty(pQueue))
        return false;

    if (data != NULL) {
        if (*nBytes < pQueue->data[pQueue->front].len) {
            *nBytes = pQueue->data[pQueue->front].len;
            return false;
        }

        memcpy(data, pQueue->data[pQueue->front].array, pQueue->data[pQueue->front].len);
    }

    pQueue->front = (pQueue->front + 1) % pQueue->maxSize;
    pQueue->size--;

    return true;
}

void ClearQueue(PQUEUE pQueue) {
    if (pQueue == NULL)
        return;

    while (!isQueueEmpty(pQueue))
        PopQueue(pQueue, NULL, NULL);
}

void DeinitQueue(PQUEUE pQueue) {
    if (pQueue == NULL)
        return;

    ClearQueue(pQueue);
    free(pQueue->data);
    free(pQueue);
}