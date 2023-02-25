#include "i_vector.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 10

void resize(struct iVector *vector) {
    int *oldArray = vector->array;
    vector->capacity *= 2;
    vector->array = (int *)malloc(sizeof(int) * vector->capacity);
    for (int i = 0; i < vector->length; ++i) {
        vector->array[i] = oldArray[i];
    }
    free(oldArray);
}

struct iVector *iVector_new() {
    return iVector_newWithCapacity(DEFAULT_CAPACITY);
};

struct iVector *iVector_newWithCapacity(int capacity) {
    struct iVector *vector = (struct iVector *)malloc(sizeof(struct iVector));
    vector->length = 0;
    vector->array = (int *)malloc(sizeof(int) * capacity);
    vector->capacity = capacity;
    return vector;
};

struct iVector *iVector_fromArr(int *, int);

void iVector_push(struct iVector *vector, int value) {
    if (vector->length + 1 > vector->capacity) {
        resize(vector);
    }
    vector->array[vector->length] = value;
    ++vector->length;
};

int iVector_pop(struct iVector, int);

void iVector_clear(struct iVector);

int iVector_indexOf(struct iVector, int);

int iVector_get(struct iVector, int);

void iVector_add(struct iVector, int, int);

void iVector_remove(struct iVector, int);
