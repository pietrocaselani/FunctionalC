//
//  binarytree.c
//  Functional C
//
//  Created by Pietro Caselani on 20/05/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include "binarytree.h"
#include "stdlib.h"

typedef struct Node Node;

void internalAddElement(BinaryTree*, Node**, void*);
void internalEachOrder(Node*, void (*)(void*));
Node* createNode(void*);

struct Node {
    void *data;
    Node *right, *left;
};

struct BinaryTree {
    Node *root;
    int(*compFunc)(const void*, const void*);
};

BinaryTree* newBinaryTree(int (*compFunc)(const void*, const void*)) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    tree->root = NULL;
    tree->compFunc = compFunc;
    return tree;
}

void releaseBinaryTree(BinaryTree *tree) {
    //TODO arrumar
    free(tree);
}

void btaddElement(BinaryTree *tree, void *element) {
    internalAddElement(tree, &(tree->root), element);
}

void bteachOrder(BinaryTree *tree, void (*ieachOrder)(void*)) {
    internalEachOrder(tree->root, ieachOrder);
}

void internalEachOrder(Node *nodo, void (*ieachOrder)(void*)) {
    if (nodo != NULL) {
        if (nodo->left != NULL) {
            internalEachOrder(nodo->left, ieachOrder);
        }
        
        ieachOrder(nodo->data);
        
        if (nodo->right != NULL) {
            internalEachOrder(nodo->right, ieachOrder);
        }
    }
}

void internalAddElement(BinaryTree *tree, Node **node, void *element) {
    if (*node == NULL) {
        *node = createNode(element);
    } else {
        int result = tree->compFunc((*node)->data, element);
        
        if (result >= 0) {
            internalAddElement(tree, &(*node)->left, element);
        } else {
            internalAddElement(tree, &(*node)->right, element);
        }

    }
}

Node* createNode(void *element) {
    Node *node = malloc(sizeof(Node));
    node->data = element;
    node->left = NULL;
    node->right = NULL;
    return node;
}