#ifndef QUEUE_BY_LIST_H
#define QUEUE_BY_LIST_H

#include <stdbool.h>

typedef struct {
    void *array;
    size_t len;
} DATA, *PDATA;

typedef struct Node{
    DATA data;
    struct Node *next;
} NODE, *PNODE;

typedef struct {
    PNODE front;
    PNODE rear;
} QUEUE, *PQUEUE;

PQUEUE InitQueue();
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, const void *, size_t);
bool PopQueue(PQUEUE, void *, size_t *);
void ClearQueue(PQUEUE pQueue);

#endif