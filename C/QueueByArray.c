#include <stdlib.h>
#include <string.h>
#include "QueueByArray.h"

PQUEUE InitQueue(size_t queueSize) {
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

static bool IsQueueFull(PQUEUE pQueue) {
    if (pQueue == NULL)
        return false;

    return pQueue->size == pQueue->maxSize;
}

static bool IsQueueEmpty(PQUEUE pQueue) {
    if (pQueue == NULL)
        return true;

    return pQueue->size == 0;
}

bool PushQueue(PQUEUE pQueue, const void *data, size_t nBytes) {
    if (pQueue == NULL || IsQueueFull(pQueue) || data == NULL)
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

bool PopQueue(PQUEUE pQueue, void *data, size_t *nBytes) {
    if (pQueue == NULL || IsQueueEmpty(pQueue))
        return false;

    if (data != NULL && nBytes != NULL) {
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

    while (!IsQueueEmpty(pQueue))
        PopQueue(pQueue, NULL, NULL);
}

void DeinitQueue(PQUEUE pQueue) {
    if (pQueue == NULL)
        return;

    ClearQueue(pQueue);
    free(pQueue->data);
    free(pQueue);
}