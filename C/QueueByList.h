#ifndef QUEUE_BY_LIST_H
#define QUEUE_BY_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int DATA_TYPE;

typedef struct Node{
    DATA_TYPE data;
    struct Node *next;
} NODE, *PNODE;

typedef struct {
    PNODE front;
    PNODE rear;
} QUEUE, *PQUEUE;

PQUEUE InitQueue();
void DeinitQueue(PQUEUE);
bool PushQueue(PQUEUE, DATA_TYPE);
bool PopQueue(PQUEUE, DATA_TYPE *);
void ClearQueue(PQUEUE pQueue);

#endif