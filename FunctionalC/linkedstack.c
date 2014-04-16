//
//  linkedstack.c
//  FunctionalC
//
//  Created by Pietro Caselani on 16/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "linkedstack.h"
#include "list.h"
#include "stdlib.h"

struct LinkedStack {
    List *elements;
};

LinkedStack* newLinkedStack() {
    LinkedStack *stack = malloc(sizeof(LinkedStack));
    stack->elements = newList();
    return stack;
}

void releaseLinkedStack(LinkedStack *stack) {
    releaseList(stack->elements);
    free(stack);
}

void* lspush(LinkedStack *stack, void *element) {
    lappend(stack->elements, 0, element);
    return element;
}

void* lspeek(LinkedStack *stack) {
    return lfirst(stack->elements);
}

void* lspop(LinkedStack *stack) {
    void *element = lfirst(stack->elements);
    lremoveAtIndex(stack->elements, 0);
    return element;
}

int lssize(LinkedStack *stack) {
    return lsize(stack->elements);
}

int lsisEmpty(LinkedStack *stack) {
    return lisEmpty(stack->elements);
}