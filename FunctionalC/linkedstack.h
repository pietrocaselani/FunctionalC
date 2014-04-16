//
//  linkedstack.h
//  FunctionalC
//
//  Created by Pietro Caselani on 16/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef struct LinkedStack LinkedStack;

LinkedStack* newLinkedStack();
void releaseLinkedStack(LinkedStack*);

void* lspush(LinkedStack*, void*);
void* lspeek(LinkedStack*);
void* lspop(LinkedStack*);
int lssize(LinkedStack*);
int lsisEmpty(LinkedStack*);