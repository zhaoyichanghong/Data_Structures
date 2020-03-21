#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef int DATA_TYPE;

typedef struct {
    DATA_TYPE *data;
    int front;
    int maxSize;
    int size;
    int sum;
} QUEUE, *PQUEUE;

PQUEUE InitQueue(int);
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, DATA_TYPE);
bool PopQueue(PQUEUE, DATA_TYPE *);
void ClearQueue(PQUEUE pQueue);
int GetMovingAverage(PQUEUE, unsigned short);

#endif