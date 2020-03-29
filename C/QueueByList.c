#include <stdlib.h>
#include <string.h>
#include "QueueByList.h"

PQUEUE InitQueue() {
    PQUEUE pQueue = malloc(sizeof(QUEUE));
    if (pQueue == NULL)
        return NULL;

    pQueue->front = pQueue->rear = malloc(sizeof(NODE));
    if (pQueue->front == NULL) {
        free(pQueue);
        return NULL;
    }

    pQueue->front->next = NULL;
    return pQueue;
}

bool IsQueueEmpty(PQUEUE pQueue) {
    if (pQueue == NULL)
        return true;

    return pQueue->front == pQueue->rear;
}

bool PushQueue(PQUEUE pQueue, const void *data, size_t nBytes) {
    if (pQueue == NULL || data == NULL)
        return false;

    pQueue->rear->next = malloc(sizeof(NODE));
    if (pQueue->rear->next == NULL)
        return false;

    void *mem = malloc(nBytes);
    if (mem == NULL) {
        free(pQueue->rear->next);
        return false;
    }

    memcpy(mem, data, nBytes);
    pQueue->rear->next->data.array = mem;
    pQueue->rear->next->data.len = nBytes;
    pQueue->rear->next->next = NULL;
    pQueue->rear = pQueue->rear->next;

    return true;
}

bool PopQueue(PQUEUE pQueue, void *data, size_t *nBytes) {
    if (pQueue == NULL || IsQueueEmpty(pQueue))
        return false;

    if (data != NULL && nBytes != NULL) {
        if (*nBytes < pQueue->front->next->data.len) {
            *nBytes = pQueue->front->next->data.len;
            return false;
        }

        memcpy(data, pQueue->front->next->data.array, pQueue->front->next->data.len);
    }

    PNODE pNode = pQueue->front->next;
    pQueue->front->next = pNode->next;
    if (pQueue->rear == pNode)
        pQueue->rear = pQueue->front;
    free(pNode);

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
    free(pQueue->front);
    free(pQueue);
}