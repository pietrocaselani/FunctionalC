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

int lisEmpty(List *list) {
    return list->size == 0;
}

void laddElement(List *list, void *element) {
    lappend(list, list->size, element);
}

void laddAll(List *list, int count, ...) {
    va_list arguments;
    va_start(arguments, count);
	int i;
    
    for (i = 0; i < count; i++) lappend(list, list->size, va_arg(arguments, void*));
	
	va_end(arguments);
}

void lappend(List *list, int index, void *element) {
    if (index < 0 || index > list->size) return;
    
    Node *aux = malloc(sizeof(Node));
    aux->data = element;
    aux->next = NULL;
    
    if (list->size == 0) {
        list->start = aux;
    } else {
        Node *current = list->start, *prev = NULL;
        int i = 0;
        
        while (i++ < index) {
            prev = current;
            current = current->next;
        }
        
        aux->next = current;
        
        if (index == 0) list->start = aux;
        
        if (prev != NULL) prev->next = aux;
    }
    
    list->size++;
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

void* lfirst(List *list) {
    return lgetElement(list, 0);
}

void* llast(List *list) {
    return lgetElement(list, list->size - 1);
}

void lsort(List *list, int (*compFunc)(const void *, const void *)) {
    int size = list->size, i;
    void **data = malloc(sizeof(void*) * size);
    
    lforEachIndex(list, e, index, {
        data[index] = e;
    })
    
    qsort(data, size, sizeof(data), compFunc);
    
    for (i = 0; i < size; i++) lreplace(list, i, data[i]);
}