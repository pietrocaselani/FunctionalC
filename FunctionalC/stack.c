//
//  stack.c
//  FunctionalC
//
//  Created by Pietro Caselani on 09/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "stack.h"
#include "array.h"
#include "stdlib.h"

struct Stack {
    Array *elements;
};

Stack* newStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->elements = newArray();
    return stack;
}

void releaseStack(Stack *stack) {
    releaseArray(stack->elements);
    free(stack);
}

void* spush(Stack *stack, void *element) {
    aappend(stack->elements, 0, element);
    return element;
}

void* speek(Stack *stack) {
    return afirst(stack->elements);
}

void* spop(Stack *stack) {
    void *element = afirst(stack->elements);
    aremoveAtIndex(stack->elements, 0);
    return element;
}

int ssize(Stack *stack) {
    return asize(stack->elements);
}

int sisEmpty(Stack *stack) {
    return aisEmpty(stack->elements);
}