//
//  queue.h
//  FunctionalC
//
//  Created by Pietro Caselani on 09/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef struct Queue Queue;

Queue* newQueue();
void releaseQueue(Queue*);

void qadd(Queue*, void*);
void* qpeek(Queue*);
void* qpool(Queue*);
int qsize(Queue*);
int qisEmpty(Queue*);