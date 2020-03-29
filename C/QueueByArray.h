#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H

#include <stdbool.h>

typedef struct {
    void *array;
    size_t len;
} DATA, *PDATA;

typedef struct {
    PDATA data;
    size_t front;
    size_t maxSize;
    size_t size;
} QUEUE, *PQUEUE;

PQUEUE InitQueue(size_t);
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, const void *, size_t);
bool PopQueue(PQUEUE, void *, size_t *);
void ClearQueue(PQUEUE pQueue);

#endif