//
//  LinkedQueue.h
//  FunctionalC
//
//  Created by Pietro Caselani on 15/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef struct LinkedQueue LinkedQueue;

LinkedQueue* newLinkedQueue();
void releaseLinkedQueue(LinkedQueue*);

void lqadd(LinkedQueue*, void*);
void* lqpeek(LinkedQueue*);
void* lqpool(LinkedQueue*);
int lqsize(LinkedQueue*);
int lqisEmpty(LinkedQueue*);