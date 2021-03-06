#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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
    PNODE tail;
} LIST, *PLIST;

typedef void (*Handler)(void *, size_t);

PLIST CreateList();
void DestoryList(PLIST);
bool AddNodeToHead(PLIST, const void *, size_t);
bool AddNodeToTail(PLIST, const void *, size_t);
bool DelNode(PLIST, const void *, size_t);
void TraverseList(PLIST, Handler);
PLIST RevertList1(PLIST);
void RevertList2(PLIST);

#endif