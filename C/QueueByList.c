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

bool isQueueEmpty(PQUEUE pQueue) {
    return pQueue->front == pQueue->rear;
}

bool PushQueue(PQUEUE pQueue, DATA_TYPE data) {
    pQueue->rear->next = malloc(sizeof(NODE));
    if (pQueue->rear->next == NULL)
        return false;

    pQueue->rear->next->data = data;
    pQueue->rear->next->next = NULL;
    pQueue->rear = pQueue->rear->next;

    return true;
}

bool PopQueue(PQUEUE pQueue, DATA_TYPE *data) {
    if (isQueueEmpty(pQueue))
        return false;

    if (data != NULL)
        *data = pQueue->front->next->data;

    PNODE pNode = pQueue->front->next;
    pQueue->front->next = pNode->next;
    if (pQueue->rear == pNode)
        pQueue->rear = pQueue->front;
    free(pNode);

    return true;
}

void ClearQueue(PQUEUE pQueue) {
    while (!isQueueEmpty(pQueue))
        PopQueue(pQueue, NULL);
}

void DeinitQueue(PQUEUE pQueue) {
    ClearQueue(pQueue);
    free(pQueue->front);
    free(pQueue);
}