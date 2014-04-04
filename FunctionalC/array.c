//
//  array.c
//  FunctionalC
//
//  Created by Pietro Caselani on 04/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "array.h"
#include "stdlib.h"
#include "stdarg.h"

#include <stdio.h>

#define kDefaultSize    12

void internalRemove(Array*, int, int);

struct Array {
    int capacity, size;
    void **data;
};

Array* newArray() {
    return newArrayWithCapacity(kDefaultSize);
}

Array* newArrayWithCapacity(int capacity) {
    Array *array = malloc(sizeof(Array));
    array->capacity = capacity;
    array->size = 0;
    array->data = malloc(sizeof(void*) * capacity);
    
    int i;
    for (i = 0; i < capacity; i++) array->data[i] = NULL;
    
    return array;
}

Array* newArrayWithElements(int count, ...) {
    Array *array = newArrayWithCapacity(count);
    
    va_list arguments;
    va_start(arguments, count);
    int i;
    
    for (i = 0; i < count; i++) aaddAtIndex(array, array->size, va_arg(arguments, void*));
    
    va_end(arguments);
    
    return array;
}

void releaseArray(Array *array) {
    free(array->data);
    free(array);
}

int asize(Array *array) {
    return array->size;
}

void aaddElement(Array *array, void *element) {
    aaddAtIndex(array, array->size, element);
}

void aaddAtIndex(Array *array, int index, void *element) {
    if (index >= array->capacity) {
        array->data = realloc(array->data, array->capacity * 2);
        array->capacity *= 2;
    }
    
    array->data[index] = element;
    array->size++;
}

void aaddAll(Array *array, int count, ...) {
    va_list arguments;
    va_start(arguments, count);
    int i;
    
    for (i = 0; i < count; i++) aaddAtIndex(array, array->size, va_arg(arguments, void*));
    
    va_end(arguments);
}
void aremoveAtIndex(Array *array, int index) {
    if (index < 0 || index >= array->size) return;
    
    int size = array->size, i;
    
    for (i = 0; i < size; i++) {
		if (i == index) {
			internalRemove(array, i, size);
			break;
		}
	}
}

void aclear(Array *array) {
    int i, size = array->size;
    
    for (i = 0; i < size; i++) array->data[i] = NULL;
    
    array->size = 0;
}

void areplace(Array *array, int index, void *element) {
    //TODO
    if (array->size == 0 || index < 0 || index >= array->size) return;
    
    array->data[index] = element;
}

void* agetElement(Array *array, int index) {
    return index < 0 || index >= array->size ? NULL : array->data[index];
}

void asort(Array *array, Comparator compFunc) {
    qsort(array->data, array->size, sizeof(array->data), compFunc);
}

void internalRemove(Array *array, int fromIndex, int toIndex) {
    int i, size = toIndex - 1;
	void *e;
	
	for (i = fromIndex; i < size; i++) {
		e = array->data[i + 1];
		array->data[i] = e;
	}
	
	for (i = toIndex; i < array->capacity; i++) {
		array->data[i] = NULL;
	}
	
	array->size = size;
}