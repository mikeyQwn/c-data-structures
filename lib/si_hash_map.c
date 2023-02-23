#include "si_hash_map.h"
#include <malloc.h>
#include <string.h>

#define DEFAULT_CAPACITY 16
#define DEFAULT_LOAD_FACTOR 0.75

void resize(struct siHashMap *map) {
    siHashMapEntry_t **oldEntries = map->entries;

    map->capacity *= 2;
    map->entries =
        (siHashMapEntry_t **)malloc(sizeof(siHashMapEntry_t) * map->capacity);

    for (int i = 0; i < map->capacity / 2; ++i) {
        for (siHashMapEntry_t *entry = oldEntries[i]; entry != NULL;
             entry = entry->next) {
            siHashMap_put(map, entry->key, entry->value);
        }
    }

    free(oldEntries);
}

unsigned int getHash(char *string) {
    unsigned int result = 543;
    for (int i = 0; i < strlen(string); ++i) {
        result = (result << 6) + result + (int)string[i];
    }
    return result;
}

struct siHashMap *siHashMap_newWithCapacity(int capacity) {
    struct siHashMap *map =
        (struct siHashMap *)malloc(sizeof(struct siHashMap));
    map->size = 0;
    map->capacity = capacity;
    map->entries =
        (siHashMapEntry_t **)malloc(sizeof(siHashMapEntry_t *) * map->capacity);
    return map;
}

struct siHashMap *siHashMap_new() {
    return siHashMap_newWithCapacity(DEFAULT_CAPACITY);
};

void siHashMap_put(struct siHashMap *map, char *key, int value) {
    siHashMapEntry_t *entry =
        (siHashMapEntry_t *)malloc(sizeof(siHashMapEntry_t));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    if ((float)(map->size + 1) / (float)map->capacity > DEFAULT_LOAD_FACTOR)
        resize(map);

    unsigned int index = getHash(key) % map->capacity;
    if (map->entries[index] == NULL) {
        map->entries[index] = entry;
        ++map->size;
        return;
    }
    siHashMapEntry_t *iter = map->entries[index];
    while (iter->next != NULL)
        iter = iter->next;
    iter->next = entry;
    ++map->size;
};

int siHashMap_get(struct siHashMap map, char *key) {
    unsigned int index = getHash(key) % map.capacity;
    siHashMapEntry_t *iter = map.entries[index];
    while (!(strcmp(iter->key, key) == 0))
        iter = iter->next;
    return iter->value;
};
