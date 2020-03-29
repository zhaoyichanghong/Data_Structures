#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H

#include <stdbool.h>

typedef struct Data {
    void *array;
    int len;
} DATA, *PDATA;

typedef struct {
    PDATA data;
    int front;
    int maxSize;
    int size;
} QUEUE, *PQUEUE;

PQUEUE InitQueue(int);
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, const void *, int);
bool PopQueue(PQUEUE, void *, int *);
void ClearQueue(PQUEUE pQueue);

#endif