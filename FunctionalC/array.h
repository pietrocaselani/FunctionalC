//
//  array.h
//  FunctionalC
//
//  Created by Pietro Caselani on 04/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "functions.h"

typedef struct Array Array;

Array* newArray();
Array* newArrayWithCapacity(int);
Array* newArrayWithElements(int, ...);
void releaseArray(Array*);

int asize(Array*);
int aisEmpty(Array*);

void aaddElement(Array*, void*);
void aaddAtIndex(Array*, int, void*);
void aaddAll(Array*, int, ...);
void aappend(Array*, int, void*);
void aremoveAtIndex(Array*, int);
void aclear(Array*);

void areplace(Array*, int, void*);

void* agetElement(Array*, int);
void* afirst(Array*);
void* alast(Array*);

void asort(Array*, int (*)(const void *, const void *));