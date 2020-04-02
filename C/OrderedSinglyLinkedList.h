#ifndef ORDERED_SINGLY_LINKED_LIST_H
#define ORDERED_SINGLY_LINKED_LIST_H

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
    PNODE head;
} LIST, *PLIST;

typedef int (*COMPARE)(const void *, const void*);
typedef void (*Handler)(void *, size_t);

PLIST CreateList();
void DestoryList(PLIST);
bool AddNode(PLIST, const void *, size_t, COMPARE);
bool DelNode(PLIST, const void *, size_t);
void TraverseList(PLIST, Handler);

#endif