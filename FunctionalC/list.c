//
//  list.c
//  FunctionalC
//
//  Created by Pietro Caselani on 02/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "list.h"
#include "stdlib.h"
#include "stdarg.h"

typedef struct Node Node;

struct Node {
    void *data;
    Node *next;
};

struct List {
    Node *start;
    int size;
};

List* newList() {
    List *list = malloc(sizeof(List));
    list->start = NULL;
    list->size = 0;
    return list;
}

List* newListWithElements(int count, ...) {
    List *list = newList();
    
    va_list arguments;
    va_start(arguments, count);
	int i;
    
    for (i = 0; i < count; i++) laddElement(list, va_arg(arguments, void*));
	
	va_end(arguments);
    
    return list;
}

void releaseList(List *list) {
    lclear(list);
    
    free(list);
}

int lsize(List *list) {
    return list->size;
}

void laddElement(List *list, void *element) {
    Node *aux = malloc(sizeof(Node));
    aux->data = element;
    aux->next = NULL;
    
    if (list->size == 0) {
        list->start = aux;
    } else {
        Node *current = list->start;
        
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = aux;
    }
    
    list->size++;
}

void laddAll(List *list, int count, ...) {
    va_list arguments;
    va_start(arguments, count);
	int i;
    
    for (i = 0; i < count; i++) laddElement(list, va_arg(arguments, void*));
	
	va_end(arguments);
}

void lremoveAtIndex(List *list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size) return;
    
    Node *current = list->start, *prev = NULL;
    int count = 0;
    
    while (current != NULL && count++ != index) {
        prev = current;
        current = current->next;
    }
    
    if (prev == NULL) {
        list->start = current->next;
    } else {
        prev->next = current->next;
    }
    
    list->size--;
    
    free(current);
}

void lclear(List *list) {
    Node *current = list->start, *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    list->start = NULL;
    list->size = 0;
}

void lreplace(List *list, int index, void *element) {
    if (list->size == 0 || index < 0 || index >= list->size) return;
    
    Node *current = list->start;
    int count = 0;
    
    while (count++ < index) current = current->next;
    
    current->data = element;
}

void* lgetElement(List *list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size) return NULL;
    
    Node *current = list->start;
    int count = 0;
    void *data = current->data;
    
    while (count++ < index) {
        current = current->next;
        data = current->data;
    }
    
    return data;
}

void lsort(List *list, Comparator compFunc) {
    int size = list->size;
    void **data = malloc(sizeof(void*) * size);
    
    lforEachIndex(list, e, index) {
        data[(int)index] = e;
    }
    
    qsort(data, size, sizeof(data), compFunc);
    
    for (int i = 0; i < size; i++) lreplace(list, i, data[i]);
}