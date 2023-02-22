#ifndef I_LINKED_LIST_H
#define I_LINKED_LIST_H
#include <stddef.h>

typedef struct iLinkedListNode {
    int value;
    struct iLinkedListNode *next;
    struct iLinkedListNode *prev;
} node_t;

struct iLinkedList {
    int length;
    node_t *head;
    node_t *tail;
};

struct iLinkedList *iLinkedList_new(void);
struct iLinkedList *iLinkedList_fromArr(int *, int);
void iLinkedList_print(struct iLinkedList);
void iLinkedList_pushFront(struct iLinkedList *, int);
void iLinkedList_pushBack(struct iLinkedList *, int);
int iLinkedList_add(struct iLinkedList *, int, int);
int iLinkedList_remove(struct iLinkedList *, int);
int iLinkedList_get(struct iLinkedList, int);

#endif
