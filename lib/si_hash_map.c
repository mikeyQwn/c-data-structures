#include "si_hash_map.h"
#include <malloc.h>

#define DEFAULT_CAPACITY 16

struct siHashMap *siHashMap_newWithCapacity(int capacity) {
    struct siHashMap *map =
        (struct siHashMap *)malloc(sizeof(struct siHashMap));
    map->size = 0;
    map->capacity = capacity;
    map->entries = malloc(sizeof(int) * map->capacity);
    return map;
}

struct siHashMap *siHashMap_new() {
    return siHashMap_newWithCapacity(DEFAULT_CAPACITY);
};

struct siHashMap *siHashMap_fromArr(int *, int);
void siHashMap_put(struct siHashMap *, char[]);
int siHashMap_get(struct siHashMap);
