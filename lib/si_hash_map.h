#ifndef SI_HASH_MAP_H
#define SI_HASH_MAP_H

typedef struct siHashMapEntry {
    char *key;
    int value;
} siHashMapEntry_t;

struct siHashMap {
    int capacity;
    int size;
    siHashMapEntry_t *entries;
};

struct siHashMap *iHashMap_new(void);
struct siHashMap *iHashMap_fromArr(int *, int);
void iHashMap_put(struct iHashMap *, char[]);
int iHashMap_get(struct iHashMap);

#endif
