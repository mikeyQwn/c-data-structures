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

struct iVector *iVector_fromArr(int *array, int length) {
    struct iVector *vector = iVector_newWithCapacity(length * 2);
    for (int i = 0; i < length; ++i) {
        iVector_push(vector, array[i]);
    }
    return vector;
};

void iVector_push(struct iVector *vector, int value) {
    if (vector->length + 1 > vector->capacity) {
        resize(vector);
    }
    vector->array[vector->length] = value;
    ++vector->length;
};

int iVector_pop(struct iVector *vector) {
    int result = vector->array[vector->length - 1];
    vector->array[vector->length - 1] = 0;
    --vector->length;
    return result;
};

void iVector_clear(struct iVector *vector) {
    for (int i = 0; i < vector->length; ++i) {
        vector->array[i] = 0;
    }
    vector->length = 0;
};

int iVector_indexOf(struct iVector vector, int value) {
    for (int i = 0; i < vector.length; ++i)
        if (vector.array[i] == value)
            return i;
    return -1;
};

int iVector_get(struct iVector vector, int index) {
    if (index >= vector.length || index < 0)
        return -1;
    return vector.array[index];
};

int iVector_add(struct iVector *vector, int index, int value) {
    if (index > vector->length || index < 0)
        return -1;
    if (vector->length + 1 > vector->capacity) {
        resize(vector);
    }
    int prev = vector->array[index];
    vector->array[index] = value;

    for (int i = index + 1; i < vector->length + 1; ++i) {
        vector->array[i] += prev;
        prev = vector->array[i] - prev;
        vector->array[i] -= prev;
    }
    ++vector->length;
    return 0;
};

int iVector_remove(struct iVector *vector, int index) {
    if (index >= vector->length || index < 0)
        return -1;
    int result = vector->array[index];
    for (int i = index; i < vector->length; ++i)
        vector->array[i] = vector->array[i + 1];
    --vector->length;
    return result;
};
