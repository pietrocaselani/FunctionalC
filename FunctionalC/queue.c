//
//  queue.c
//  FunctionalC
//
//  Created by Pietro Caselani on 09/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "queue.h"
#include "array.h"
#include "stdlib.h"

#define kDefaultSize 12

struct Queue {
    Array *elements;
};

Queue* newQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->elements = newArray();
    return queue;
}

void releaseQueue(Queue *queue) {
    releaseArray(queue->elements);
    free(queue);
}

void qadd(Queue *queue, void *element) {
    aappend(queue->elements, asize(queue->elements), element);
}

void* qpeek(Queue *queue) {
    return agetElement(queue->elements, 0);
}

void* qpool(Queue *queue) {
    void *element = qpeek(queue);
    aremoveAtIndex(queue->elements, 0);
    return element;
}

int qsize(Queue *queue) {
    return asize(queue->elements);
}

int qisEmpty(Queue *queue) {
    return aisEmpty(queue->elements);
}