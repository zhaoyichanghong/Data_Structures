#include "QueueByArray.h"

PQUEUE InitQueue(int queueSize) {
    PQUEUE pQueue = malloc(sizeof(QUEUE));
    if (pQueue == NULL)
        return NULL;

    pQueue->maxSize = queueSize;
    pQueue->data = calloc(pQueue->maxSize, sizeof(DATA_TYPE));
    if (pQueue->data == NULL) {
        free(pQueue);
        return NULL;
    }

    pQueue->front = pQueue->rear = 0;
    return pQueue;
}

bool isQueueFull(PQUEUE pQueue) {
    return (pQueue->rear + 1) % pQueue->maxSize == pQueue->front;
}

bool isQueueEmpty(PQUEUE pQueue) {
    return pQueue->front == pQueue->rear;
}

bool PushQueue(PQUEUE pQueue, DATA_TYPE data) {
    if (isQueueFull(pQueue))
        return false;

    pQueue->data[pQueue->rear] = data;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxSize;

    return true;
}

bool PopQueue(PQUEUE pQueue, DATA_TYPE *data) {
    if (isQueueEmpty(pQueue))
        return false;

    *data = pQueue->data[pQueue->front];
    pQueue->front = (pQueue->front + 1) % pQueue->maxSize;

    return true;
}

void DeinitQueue(PQUEUE pQueue) {
    free(pQueue->data);
    free(pQueue);
}