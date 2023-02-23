#ifndef I_VECTOR_H
#define I_VECTOR_H

struct iVector {
    int *array;
    int length;
    int capacity;
};

struct iVector *iVector_new();
struct iVector *iVector_newWithCapacity();
struct iVector *iVector_fromArr(int *, int);
void iVector_push(struct iVector, int);
int iVector_pop(struct iVector, int);
void iVector_clear(struct iVector);
int iVector_indexOf(struct iVector, int);
int iVector_get(struct iVector, int);
void iVector_add(struct iVector, int, int);
void iVector_remove(struct iVector, int);

#endif
