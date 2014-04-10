//
//  stack.h
//  FunctionalC
//
//  Created by Pietro Caselani on 09/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef struct Stack Stack;

Stack* newStack();
void releaseStack(Stack*);

void* spush(Stack*, void*);
void* speek(Stack*);
void* spop(Stack*);
int ssize(Stack*);
int sisEmpty(Stack*);