#ifndef SI_HASH_MAP_H
#define SI_HASH_MAP_H

typedef struct siHashMapEntry {
    char *key;
    int value;
    struct siHashMapEntry *next;
} siHashMapEntry_t;

struct siHashMap {
    int capacity;
    int size;
    siHashMapEntry_t **entries;
};

struct siHashMap *siHashMap_new(void);
struct siHashMap *siHashMap_newWithCapacity(int);
struct siHashMap *siHashMap_fromArr(int *, int);
void siHashMap_put(struct siHashMap *, char *, int);
int siHashMap_get(struct siHashMap, char *);

#endif
