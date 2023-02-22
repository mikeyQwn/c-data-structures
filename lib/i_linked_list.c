#include "i_linked_list.h"
#include <malloc.h>
#include <stdio.h>

struct iLinkedList *iLinkedList_new() {
    struct iLinkedList *list =
        (struct iLinkedList *)malloc(sizeof(struct iLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

struct iLinkedList *iLinkedList_fromArr(int *arr, int length) {
    struct iLinkedList *result = iLinkedList_new();
    for (int i = 0; i < length; ++i) {
        iLinkedList_pushFront(result, arr[i]);
    }
    return result;
}

void iLinkedList_print(struct iLinkedList list) {
    node_t *temp = list.tail;
    int index = 0;
    while (temp != NULL) {
        printf("%d: %d\n", index++, temp->value);
        temp = temp->next;
    }

    if (list.length == 0) {
        printf("List is empty\n");
    }
}

void iLinkedList_pushFront(struct iLinkedList *list, int value) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->value = value;
    temp->next = NULL;
    temp->prev = list->head;

    if (list->tail == NULL)
        list->tail = temp;
    if (list->head != NULL)
        list->head->next = temp;
    list->head = temp;
    ++list->length;
}

void iLinkedList_pushBack(struct iLinkedList *list, int value) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->value = value;
    temp->next = list->tail;
    temp->prev = NULL;

    if (list->tail != NULL)
        list->tail->prev = temp;
    if (list->head == NULL)
        list->head = temp;
    list->tail = temp;
    ++list->length;
}

int iLinkedList_add(struct iLinkedList *list, int index, int value) {
    if (index > list->length || index < 0)
        return -1;
    if (index == list->length) {
        iLinkedList_pushFront(list, value);
        return 0;
    }
    if (index == 0) {
        iLinkedList_pushBack(list, value);
        return 0;
    }

    int i = 0;
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->value = value;
    node_t *iter = list->tail;

    while (iter != NULL) {
        if (i != index) {
            ++i;
            iter = iter->next;
            continue;
        }
        temp->prev = iter->prev;
        temp->next = iter;

        temp->prev->next = temp;
        temp->next->prev = temp;
        ++list->length;
        return 0;
    }
    return -1;
}

int iLinkedList_remove(struct iLinkedList *list, int index) {
    if (index >= list->length || index < 0)
        return -1;
    int i = 0;
    node_t *iter = list->tail;

    while (iter != NULL) {
        if (i != index) {
            ++i;
            iter = iter->next;
            continue;
        }
        if (iter->prev == NULL & iter->next == NULL) {
            list->tail = list->head = NULL;
            free(iter);
            --list->length;
            return 0;
        }
        if (iter->prev == NULL) {
            list->tail = iter->next;
            list->tail->prev = NULL;
            free(iter);
            --list->length;
            return 0;
        }
        if (iter->next == NULL) {
            list->head = iter->prev;
            list->head->next = NULL;
            free(iter);
            --list->length;
            return 0;
        }
        iter->prev->next = iter->next;
        free(iter);
        --list->length;
        return 0;
    }
    return -1;
}

int iLinkedList_get(struct iLinkedList list, int index) {
    if (index >= list.length || index < 0)
        return -1;

    int i = 0;
    node_t *iter = list.tail;

    while (iter != NULL) {
        if (i != index) {
            ++i;
            iter = iter->next;
            continue;
        }
        return iter->value;
    }

    return -1;
}
