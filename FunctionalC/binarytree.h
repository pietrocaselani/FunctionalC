//
//  binarytree.h
//  Functional C
//
//  Created by Pietro Caselani on 20/05/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

typedef struct BinaryTree BinaryTree;

BinaryTree* newBinaryTree(int (*)(const void*, const void*));
void releaseBinaryTree(BinaryTree*);

void btaddElement(BinaryTree*, void*);

void bteachOrder(BinaryTree*, void (*)(void*));