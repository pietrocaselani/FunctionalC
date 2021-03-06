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

#define kDefaultSize    12

void reallocData(Array*);
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
    
    for (i = 0; i < count; i++) aappend(array, array->size, va_arg(arguments, void*));
    
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

int aisEmpty(Array *array) {
    return array->size == 0;
}

void aaddElement(Array *array, void *element) {
    aappend(array, array->size, element);
}

void aaddAll(Array *array, int count, ...) {
    va_list arguments;
    va_start(arguments, count);
    int i;
    
    for (i = 0; i < count; i++) aappend(array, array->size, va_arg(arguments, void*));
    
    va_end(arguments);
}

void aappend(Array *array, int index, void *element) {
    if (index < 0 || index > array->size) return;
    
    if (index + 1 >= array->capacity) {
        reallocData(array);
    }
    
    int i;
    for (i = array->size - 1; i >= index; i--) {
        array->data[i + 1] = array->data[i];
    }
    
    array->data[index] = element;
    array->size++;
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
    if (array->size == 0 || index < 0 || index >= array->size) return;
    
    array->data[index] = element;
}

void* agetElement(Array *array, int index) {
    return index < 0 || index >= array->size ? NULL : array->data[index];
}

void* afirst(Array *array) {
    return agetElement(array, 0);
}

void* alast(Array *array) {
    return agetElement(array, array->size - 1);
}

void asort(Array *array, int (*compFunc)(const void *, const void *)) {
    qsort(array->data, array->size, sizeof(array->data), compFunc);
}

void reallocData(Array *array) {
    int currentCapacity = array->capacity;
    int increment = (currentCapacity < (kDefaultSize / 2) ? kDefaultSize : currentCapacity >> 1);
    int newCapacity = currentCapacity + increment;
    array->data = realloc(array->data, sizeof(void*) * newCapacity);
    array->capacity = newCapacity;
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