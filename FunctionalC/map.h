//
//  map.h
//  FunctionalC
//
//  Created by Pietro Caselani on 08/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "functions.h"
#include "array.h"

typedef struct Entry {
    void *key, *value;
}Entry;

typedef struct Map Map;

Map* newMap();
Map* newMapWithCapacity(int);
Map* newMapWithElements(int, ...);
void releaseMap(Map*);

int msize(Map*);
void mclear(Map*);

void mput(Map*, void*, void*);
void mputAll(Map*, Map*);

Array* mgetEntries(Map*);
Array* mgetKeys(Map*);
Array* mgetValues(Map*);