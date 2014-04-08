//
//  list.h
//  FunctionalC
//
//  Created by Pietro Caselani on 02/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "functions.h"

typedef struct List List;

List* newList();
List* newListWithElements(int, ...);
void releaseList(List*);

int lsize(List*);

void laddElement(List*, void*);
void laddAll(List*, int, ...);
void lremoveAtIndex(List*, int);
void lclear(List*);

void lreplace(List*, int, void*);

void* lgetElement(List*, int);

void lsort(List*, int (*)(const void *, const void *));