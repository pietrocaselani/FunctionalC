//
//  linkedqueue.c
//  FunctionalC
//
//  Created by Pietro Caselani on 15/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "linkedqueue.h"
#include "list.h"
#include "stdlib.h"

struct LinkedQueue {
    List *elements;
};

LinkedQueue* newLinkedQueue() {
    LinkedQueue *queue = malloc(sizeof(LinkedQueue));
    queue->elements = newList();
    return queue;
}

void releaseLinkedQueue(LinkedQueue *list) {
    releaseList(list->elements);
    free(list);
}

void lqadd(LinkedQueue *queue, void *element) {
    lappend(queue->elements, lsize(queue->elements), element);
}

void* lqpeek(LinkedQueue *queue) {
    return lgetElement(queue->elements, 0);
}

void* lqpool(LinkedQueue *queue) {
    void *element = lqpeek(queue);
    lremoveAtIndex(queue->elements, 0);
    return element;
}

int lqsize(LinkedQueue *queue) {
    return lsize(queue->elements);
}

int lqisEmpty(LinkedQueue *queue) {
    return lisEmpty(queue->elements);
}