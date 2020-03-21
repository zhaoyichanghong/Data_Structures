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

    pQueue->front = 0;
    pQueue->size = 0;
    pQueue->sum = 0;
    return pQueue;
}

bool isQueueFull(PQUEUE pQueue) {
    return pQueue->size == pQueue->maxSize;
}

bool isQueueEmpty(PQUEUE pQueue) {
    return pQueue->size == 0;
}

bool PushQueue(PQUEUE pQueue, DATA_TYPE data) {
    if (isQueueFull(pQueue))
        return false;

    pQueue->data[(pQueue->front + pQueue->size) % pQueue->maxSize] = data;
    pQueue->size++;
    pQueue->sum += data;

    return true;
}

bool PopQueue(PQUEUE pQueue, DATA_TYPE *data) {
    if (isQueueEmpty(pQueue))
        return false;

    pQueue->sum -= pQueue->data[pQueue->front];
    if (data != NULL)
        *data = pQueue->data[pQueue->front];

    pQueue->front = (pQueue->front + 1) % pQueue->maxSize;
    pQueue->size--;

    return true;
}

void ClearQueue(PQUEUE pQueue) {
    pQueue->front = 0;
    pQueue->size = 0;
    pQueue->sum = 0;
}

int GetMovingAverage(PQUEUE pQueue, unsigned short data) {
	if (isQueueFull(pQueue))
		PopQueue(pQueue, NULL);

	PushQueue(pQueue, data);
    
	return pQueue->sum / pQueue->size;
}

void DeinitQueue(PQUEUE pQueue) {
    free(pQueue->data);
    free(pQueue);
}