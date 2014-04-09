//
//  map.c
//  FunctionalC
//
//  Created by Pietro Caselani on 08/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "map.h"
#include "stdlib.h"
#include "stdarg.h"

#define kDefaultSize        12

void putEntry(Map*, Entry*);

struct Map {
    Array *entries;
};

Map* newMap() {
    return newMapWithCapacity(kDefaultSize);
}

Map* newMapWithCapacity(int capacity) {
    Map *map = malloc(sizeof(Map));
    map->entries = newArrayWithCapacity(capacity);
    return map;
}

Map* newMapWithElements(int count, ...) {
    Map *map = newMapWithCapacity(count);
    
    int i, size = count;
	count *= 2;
	
	va_list arguments;
	va_start(arguments, count);
	void *key, *value;
	
	for (i = 0; i < size; i++) {
		key = va_arg(arguments, char*);
		value = va_arg(arguments, char*);
		mput(map, key, value);
	}
	
	va_end(arguments);
    
    return NULL;
}

void releaseMap(Map *map) {
    aforEach(map->entries, entry, free(entry););
    
    releaseArray(map->entries);
    free(map);
}

int msize(Map *map) {
    return asize(map->entries);
}

int misEmpty(Map *map) {
    return aisEmpty(map->entries);
}

void mclear(Map *map) {
    aclear(map->entries);
}

void mput(Map *map, void *key, void *value) {
    Entry *entry = malloc(sizeof(Entry));
    
    entry->key = key;
    entry->value = value;
    
    putEntry(map, entry);
}

void mputAll(Map *destinyMap, Map *sourceMap) {
    aforEach(sourceMap->entries, entry, putEntry(destinyMap, entry);)
}

Array* mgetEntries(Map *map) {
    return map->entries;
}

Array* mgetKeys(Map *map) {
    Array *keys = newArrayWithCapacity(msize(map));
    
    aforEach(map->entries, entry, aaddElement(keys, ((Entry*) entry)->key););
    
    return keys;
}

Array* mgetValues(Map *map) {
    Array *values = newArrayWithCapacity(msize(map));
    
    aforEach(map->entries, entry, aaddElement(values, ((Entry*) entry)->value););
    
    return values;
}

void putEntry(Map *map, Entry *entry) {
	aaddElement(map->entries, (void*)entry);
}