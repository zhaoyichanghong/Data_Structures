#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedList.h"

PLIST CreateList() {
    PLIST pList = malloc(sizeof(LIST));
    if (pList == NULL)
        return NULL;

    pList->head = malloc(sizeof(NODE));
    if (pList->head == NULL) {
        free(pList);
        return NULL;
    }

    pList->head->next = NULL;

    return pList;
}

bool AddNode(PLIST pList, const void *data, size_t nBytes) {
    if (pList == NULL)
        return false;

    PNODE pNode = malloc(sizeof(NODE));
    if (pNode == NULL)
        return false;
    
    pNode->data.array = malloc(nBytes);
    if (pNode->data.array == NULL) {
        free(pNode);
        return false;
    }
    memcpy(pNode->data.array, data, nBytes);
    pNode->data.len = nBytes;

    pNode->next = pList->head->next;
    pList->head->next = pNode;
    
    return true;
}

bool DelNode(PLIST pList, const void *data, size_t nBytes) {
    if (pList == NULL)
        return false;

    for (PNODE p = pList->head; p->next != NULL; p = p->next) {
        if (memcmp(p->next->data.array, data, nBytes) == 0) {
            PNODE q = p->next;
            p->next = q->next;
            free(q->data.array);
            free(q);
            break;
        } 
    }

    return true;
}

void TraverseList(PLIST pList, Handler handler) {
    for (PNODE p = pList->head; p->next != NULL; p = p->next)
        handler(p->next->data.array, p->next->data.len);
}

void DestoryList(PLIST pList) {
    if (pList == NULL)
        return;

    while (pList->head->next != NULL) {
        PNODE p = pList->head->next;
        pList->head->next = p->next;
        free(p->data.array);
        free(p);
    }
    
    free(pList->head);
    free(pList);
}

PLIST RevertList1(PLIST pList) {
    if (pList == NULL)
        return NULL;

    PLIST result = CreateList();
    if (result == NULL)
        return NULL;

    for (PNODE p = pList->head; p->next != NULL;) {
        PNODE tmp = p->next->next;
        p->next->next = result->head->next;
        result->head->next = p->next;
        p->next = tmp;
    }

    return result;
}