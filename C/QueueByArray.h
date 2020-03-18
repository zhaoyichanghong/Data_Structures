#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef int DATA_TYPE;

typedef struct {
    DATA_TYPE *data;
    int front;
    int rear;
    int maxSize;
    int size;
} QUEUE, *PQUEUE;

PQUEUE InitQueue(int);
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, DATA_TYPE);
bool PopQueue(PQUEUE, DATA_TYPE *);

#endif