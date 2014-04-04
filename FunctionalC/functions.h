//
//  functions.h
//  FunctionalC
//
//  Created by Pietro Caselani on 03/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef int (*Comparator)(const void*, const void*);

#define lforEach(list, e) \
for (void *index = 0, *e; (int)index < lsize(list), e = lgetElement(list, (int)index); index++)

#define aforEach(array, e) \
for (void *index = 0, *e; (int)index < asize(array), e = agetElement(array, (int)index); index++)

#define lforEachIndex(list, e, index) \
for (void *index = 0, *e; (int)index < lsize(list), e = lgetElement(list, (int)index); index++)

#define aforEachIndex(array, e, index) \
for (void *index = 0, *e; (int)index < asize(array), e = agetElement(array, (int)index); index++)

#define literate(list, e, index, stop) \
for (void *index = 0, *e, *stop = 0; (int)index < lsize(list), e = lgetElement(list, (int)index), !stop; index++)

#define aiterate(array, e, index, stop) \
for (void *index = 0, *e, *stop = 0; (int)index < asize(array), e = agetElement(array, (int)index), !stop; index++)

#define lfilter(list, e, predicate) \
lforEach(list, e) { \
if (!(predicate)) lremoveAtIndex(list, (int) index--); \
}

#define afilter(array, e, predicate) \
aforEach(array, e) { \
if (!(predicate)) aremoveAtIndex(array, (int) index--); \
}

#define lfind(list, e, outputE, predicate) \
void *outputE; \
lforEach(list, e) { \
if ((predicate)) { \
outputE = e; \
break; \
} \
}

#define afind(array, e, outputE, predicate) \
void *outputE; \
aforEach(array, e) { \
if ((predicate)) { \
outputE = e; \
break; \
} \
}

#define lremoveElement(list, e, predicate) \
lforEachIndex(list, e, index) { \
if ((predicate)) { \
lremoveAtIndex(list, (int) index); \
break; \
} \
}

#define aremoveElement(array, e, predicate) \
aforEachIndex(array, e, index) { \
if ((predicate)) { \
aremoveAtIndex(array, (int) index); \
break; \
} \
}

#define lindexOf(list, e, indexOf, predicate) \
int indexOf = -1;\
lforEach(list, e) { \
if ((predicate)) { \
indexOf = (int) index; \
break; \
} \
}

#define aindexOf(array, e, indexOf, predicate) \
int indexOf = -1;\
aforEach(array, e) { \
if ((predicate)) { \
indexOf = (int) index; \
break; \
} \
}

#define lcontains(list, e, contains, predicate) \
int contains = 0;\
lforEach(list, e) { \
if ((predicate)) { \
contains = 1; \
break; \
} \
}

#define acontains(array, e, contains, predicate) \
int contains = 0;\
aforEach(array, e) { \
if ((predicate)) { \
contains = 1; \
break; \
} \
}

#define lmap(list, e, outputList, function) \
List *outputList = newList(); \
lforEach(list, e) laddElement(outputList, (void*) function);

#define amap(array, e, outputArray, function) \
Array *outputArray = newArrayWithCapacity(asize(array)); \
aforEach(array, e) aaddElement(outputArray, (void*) function);

#define lreduce(list, result, aux, identity, accumulator) \
void *result = (void*) identity; \
lforEach(list, aux) result = accumulator;

#define areduce(array, result, aux, identity, accumulator) \
void *result = (void*) identity; \
aforEach(array, aux) result = accumulator;