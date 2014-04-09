//
//  functions.h
//  FunctionalC
//
//  Created by Pietro Caselani on 03/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#define lforEach(list, e, block) \
{ int index; void *e; \
for (index = 0; index < lsize(list), e = lgetElement(list, index); index++) { block } }

#define aforEach(array, e, block) \
{ int index; void *e; \
for (index = 0; index < asize(array), e = agetElement(array, index); index++) { block } }

#define lforEachIndex(list, e, index, block) \
{ int index; void *e; \
for (index = 0; index < lsize(list), e = lgetElement(list, index); index++) { block } }

#define aforEachIndex(array, e, index, block) \
{ int index; void *e; \
for (index = 0; index < asize(array), e = agetElement(array, index); index++) { block } }

#define literate(list, e, index, stop, block) \
{ int index, *stop; void *e; \
for (index = 0, stop = 0; (index < lsize(list) || !stop), e = lgetElement(list, index); index++) { block } }

#define aiterate(array, e, index, stop, block) \
{ int index, stop; void *e; \
for (index = 0, stop = 0, e = NULL; index < asize(array) && stop == 0 && (e = agetElement(array, index)) != NULL; index++) { block } }

#define lfilter(list, e, predicate) \
lforEach(list, e, { \
if (!(predicate)) lremoveAtIndex(list, index--); \
})

#define afilter(array, e, predicate) \
aforEach(array, e, { \
if (!(predicate)) aremoveAtIndex(array, index--); \
})

#define lfind(list, e, outputE, predicate) \
void *outputE = NULL; \
lforEach(list, e, { \
if ((predicate)) { \
outputE = e; \
break; \
}})

#define afind(array, e, outputE, predicate) \
void *outputE = NULL; \
aforEach(array, e, { \
if ((predicate)) { \
outputE = e; \
break; \
}})

#define lremoveElement(list, e, predicate) \
lforEachIndex(list, e, index, { \
if ((predicate)) { \
lremoveAtIndex(list, (int) index); \
break; \
}})

#define aremoveElement(array, e, predicate) \
aforEachIndex(array, e, index, { \
if ((predicate)) { \
aremoveAtIndex(array, (int) index); \
break; \
}})

#define lindexOf(list, e, indexOf, predicate) \
int indexOf = -1;\
lforEach(list, e, { \
if ((predicate)) { \
indexOf = (int) index; \
break; \
}})

#define aindexOf(array, e, indexOf, predicate) \
int indexOf = -1;\
aforEach(array, e, { \
if ((predicate)) { \
indexOf = (int) index; \
break; \
}})

#define lcontains(list, e, contains, predicate) \
int contains = 0;\
lforEach(list, e, { \
if ((predicate)) { \
contains = 1; \
break; \
}})

#define acontains(array, e, contains, predicate) \
int contains = 0;\
aforEach(array, e, { \
if ((predicate)) { \
contains = 1; \
break; \
}})

#define lmap(list, e, outputList, function) \
List *outputList = newList(); \
lforEach(list, e, laddElement(outputList, (void*) function);)

#define amap(array, e, outputArray, function) \
Array *outputArray = newArrayWithCapacity(asize(array)); \
aforEach(array, e, aaddElement(outputArray, (void*) function);)

#define lreduce(list, result, aux, identity, accumulator) \
void *result = (void*) identity; \
lforEach(list, aux, result = accumulator;)

#define areduce(array, result, aux, identity, accumulator) \
void *result = (void*) identity; \
aforEach(array, aux, result = accumulator;)

#define mget(map, outputV, k, predicate) \
void *outputV = NULL; \
{ void *k; \
aiterate(mgetEntries(map), entry, index, stop, { \
k = ((Entry*)entry)->key; \
if (predicate) {stop = 1; outputV = ((Entry*) entry)->value; }});}

#define mforEach(map, entryV, block) \
{Entry *entryV; \
aforEach(mgetEntries(map), e, { \
entryV = (Entry*) e; block\
})}

#define mremove(map, k, predicate) \
{ void *k; \
mforEach(map, entry, { \
k = entry->key; \
if (predicate) { aremoveAtIndex(mgetEntries(map), index); break; }})}