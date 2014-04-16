//
//  main.c
//  FunctionalC
//
//  Created by Pietro Caselani on 02/04/14.
//  Copyright (c) 2014 Pietro Caselani. All rights reserved.
//

#include <stdio.h>
#include "list.h"
#include "array.h"
#include "map.h"
#include "queue.h"
#include "stack.h"
#include "linkedqueue.h"
#include "strings.h"
#include "stdlib.h"

void emptyLines(int lines) {
    int i;
    for (i = 0; i < lines; i++) printf("\n");
}

int compareNames(const void *a, const void *b) {
    return strcmp(b, a);
}

void testSimpleList() {
    List *list = newList();
    
    printf(lisEmpty(list) ? "Vazia\n\n" : "Não vazia\n\n");
    
    laddElement(list, "Pietro");
    laddElement(list, "Roger");
    
    lappend(list, 0, "Guilherme");
    
    lappend(list, 1, "Marcus");
    
    printf(lisEmpty(list) ? "Vazia\n\n" : "Não vazia\n\n");
    
    lforEach(list, name, {
        printf("%s\n", name);
    })
    
    releaseList(list);
}

void testNamesList() {
    void *data;
    List *list = newList();
    
    data = lgetElement(list, 0);
    if (data == NULL) {
        printf("OK!\n\n");
    }
    
    laddElement(list, "PC");
    laddElement(list, "Guilherme");
    laddElement(list, "Pietro");
    laddElement(list, "Fin");
    laddElement(list, "Felipe");
    
    lsort(list, compareNames);
    
    lforEach(list, e, {
        printf("%s\n", e);
    })
    
    emptyLines(2);
    
    lreplace(list, 2, "Pietro Caselani");
    
    lforEach(list, e, printf("%s\n", e););
    
    emptyLines(2);
    
    lfilter(list, name, strlen(name) > 5)
    
    lforEach(list, e, printf("%s\n", e);)
    
    emptyLines(2);
    
    lfind(list, e, x, strcmp(e, "Guilherme") == 0)
    printf("Find = %s\n", x);
    
    emptyLines(2);
    
    lindexOf(list, n, pcIndex, strcmp(n, "Pietro Caselani") == 0)
    printf("%d\n\n", pcIndex);
    
    emptyLines(2);
    
    lcontains(list, e, c, strcmp(e, "Felipe") == 0)
    printf(c ? "Tem Felipe" : "Não tem Felipe");
    emptyLines(2);
    
    lforEach(list, e, printf("%s\n", e);)
    
    printf("Removendo o Pietro...\n\n");
    lremoveElement(list, name, strcmp(name, "Pietro") == 0)
    
    lforEach(list, elemento, printf("%s\n", elemento);)
    
    lforEach(list, elemento, printf("%s\n", elemento);)
    
    emptyLines(3);
    printf("Test map nomes para lengths!");
    emptyLines(3);
    
    lmap(list, name, lengths, strlen(name));
    
    lforEachIndex(lengths, len, lenIndex, {
        char *name = lgetElement(list, (int) lenIndex);
        printf("%s tem %d chars\n", name, (int) len);
    })
    
    releaseList(list);
}

int compareNumbers(const void *a, const void *b) {
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    return a1 - b1;
}

void testNumbersList() {
    List *numbers = newListWithElements(5, 4, 1, 3, 5, 2);
    
    laddAll(numbers, 3, 10, 7, 9);
    
    lforEach(numbers, n, printf("%d\n", (int) n);)
    
    lreduce(numbers, n, n1, 0, (int)n + (int)n1);
    printf("Soma = %d\n\n", (int) n);
    
    lsort(numbers, compareNumbers);
    lforEach(numbers, n, printf("%d\n", (int) n);)
    
    releaseList(numbers);
}

void testNamesArray() {
    Array *array = newArrayWithElements(5, "PC", "Guilherme", "Pietro", "Fin", "Felipe");
    
    aforEach(array, name, printf("%s\n", name);)
    
    emptyLines(2);
    
    aaddElement(array, "Roger");
    
    afind(array, name, namePC, strcmp(name, "Fin") == 0);
    
    printf("%s\n", namePC);
    
    aforEachIndex(array, name, nameIndex, printf("%s no index %d\n", name, nameIndex);)
    
    emptyLines(2);
    
    aiterate(array, name, i, shouldStop, {
        shouldStop = strcmp(name, "PC") == 0;
        printf("%s\n", name);
    });
    
    emptyLines(4);
    
    aforEach(array, name, printf("%s\n", name);)
    
    emptyLines(2);
    
    aappend(array, 2, "Rodolfo");
    
    aforEach(array, name, printf("%s\n", name);)
    
    emptyLines(2);
    
    aappend(array, 0, "Mirim");
    
    aforEach(array, name, printf("%s\n", name);)
    
    emptyLines(2);
    
    aappend(array, asize(array), "Natan");
    aappend(array, asize(array), "Pati");
    aappend(array, asize(array), "Rogian");
    
    aforEach(array, name, printf("%s\n", name);)
    
    releaseArray(array);
}

void testBigArray() {
    int i;
    
    Array *a = newArray();
    
    for (i = 0; i < 100; i++) {
        int *x = malloc(sizeof(int));
        *x = i * 2;
        aaddElement(a, x);
    }
    
    printf("Size = %d\n\n\n", asize(a));
    
    aforEachIndex(a, n, i, {
        printf("a[%d] = %d\n", i, *(int*) n);
    })
    
    aforEach(a, n, {
        free(n);
    })
    
    releaseArray(a);
}

void testMap() {
    Map *map = newMap();
    
    mput(map, (void*) 1, "Um");
    mput(map, (void*) 2, "Dois");
    mput(map, (void*) 5, "Cinco");
    mput(map, (void*) 3, "Três");
    
    mget(map, literal, chave, (int)chave == 2)
    
    printf("Valor = %s\n", literal);
    
    mforEach(map, entry, {
        void *key = entry->key;
        void *value = entry->value;
        
        printf("%d -> %s\n", (int) key, value);
    });
    
    mremove(map, key, (int) key == 2)
    
    emptyLines(2);
    
    mforEach(map, entry, {
        void *key = entry->key;
        void *value = entry->value;
        
        printf("%d -> %s\n", (int) key, value);
    });
    
    releaseMap(map);
}

void testQueue() {
    int size, element;
    
    Queue *queue = newQueue();
    
    qadd(queue, (void*) 3);
    qadd(queue, (void*) 5);
    qadd(queue, (void*) 8);
    qadd(queue, (void*) 12);
    
    size = qsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) qpeek(queue);
    printf("Elemento no topo sem remover: %d\n\n", element);
    
    size = qsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) qpool(queue);
    printf("Elemento no topo removido: %d\n\n", element);
    
    size = qsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) qpeek(queue);
    printf("Elemento no topo sem remover: %d\n\n", element);
    
    releaseQueue(queue);
}

void testLinkedQueue() {
    int size, element;
    
    LinkedQueue *queue = newLinkedQueue();
    
    lqadd(queue, (void*) 3);
    lqadd(queue, (void*) 5);
    lqadd(queue, (void*) 8);
    lqadd(queue, (void*) 12);
    
    size = lqsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) lqpeek(queue);
    printf("Elemento no topo sem remover: %d\n\n", element);
    
    size = lqsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) lqpool(queue);
    printf("Elemento no topo removido: %d\n\n", element);
    
    size = lqsize(queue);
    printf("Queue size = %d\n\n", size);
    
    element = (int) lqpeek(queue);
    printf("Elemento no topo sem remover: %d\n\n", element);
    
    element = (int) lqpool(queue);
    printf("Elemento no topo removido: %d\n\n", element);
    
    element = (int) lqpool(queue);
    printf("Elemento no topo removido: %d\n\n", element);
    
    element = (int) lqpool(queue);
    printf("Elemento no topo removido: %d\n\n", element);
    
    size = lqsize(queue);
    printf("Queue size = %d\n\n", size);
    
    releaseLinkedQueue(queue);
}

void testStack() {
    int size, element;
    
    Stack *stack = newStack();
    
    spush(stack, (void*) 3);
    spush(stack, (void*) 5);
    spush(stack, (void*) 8);
    spush(stack, (void*) 12);
    
    size = ssize(stack);
    
    printf("Stack size = %d\n", size);
    
    element = (int) speek(stack);
    
    printf("Peek = %d\n", element);
    
    size = ssize(stack);
    
    printf("Stack size = %d\n", size);
    
    element = (int) spop(stack);
    size = ssize(stack);
    printf("Pop = %d\n", element);
    printf("Stack size = %d\n", size);
    
    element = (int) spop(stack);
    size = ssize(stack);
    printf("Peek = %d\n", element);
    printf("Stack size = %d\n", size);
    
    element = (int) spop(stack);
    size = ssize(stack);
    printf("Peek = %d\n", element);
    printf("Stack size = %d\n", size);
    
    element = (int) spop(stack);
    size = ssize(stack);
    printf("Peek = %d\n", element);
    printf("Stack size = %d\n", size);
    
    element = (int) spop(stack);
    size = ssize(stack);
    printf("Peek = %d\n", element);
    printf("Stack size = %d\n", size);
    
    releaseStack(stack);
}

int main(int argc, const char * argv[]) {
//    testSimpleList();
//    testNamesList();
//    testNumbersList();
    
//    testNamesArray();
//    testBigArray();
//    testMap();
//    testQueue();
//    testStack();
    
    testLinkedQueue();
    
    return 0;
}