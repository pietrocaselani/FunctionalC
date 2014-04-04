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
#include "strings.h"

void emptyLines(int lines) {
    for (int i = 0; i < lines; i++) printf("\n");
}

int compareNames(const void *a, const void *b) {
    return strcmp(b, a);
}

void testNames() {
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
    
    lforEach(list, e) {
        printf("%s\n", e);
    }
    
    emptyLines(2);
    
    lreplace(list, 2, "Pietro Caselani");
    
    lforEach(list, e) printf("%s\n", e);
    
    emptyLines(2);
    
    lfilter(list, name, strlen(name) > 5)
    
    lforEach(list, e) printf("%s\n", e);
    
    emptyLines(2);
    
    lfind(list, e, x, strcmp(e, "Pietro") == 0)
    printf("Find = %s\n", x);
    
    emptyLines(2);
    
    lindexOf(list, n, pcIndex, strcmp(n, "Pietro") == 0)
    printf("%d\n\n", pcIndex);
    
    emptyLines(2);
    
    lcontains(list, e, c, strcmp(e, "XPietro") == 0)
    printf(c ? "Tem Pietro" : "Não tem Pietro");
    emptyLines(2);
    
    lforEach(list, e) printf("%s\n", e);
    
    printf("Removendo o Pietro...\n\n");
    lremoveElement(list, name, strcmp(name, "Pietro") == 0)
    
    lforEach(list, elemento) printf("%s\n", elemento);
    
    lforEach(list, elemento) printf("%s\n", elemento);
    
    emptyLines(3);
    printf("Test map nomes para lengths!");
    emptyLines(3);
    
    lmap(list, name, lengths, strlen(name));
    
    lforEachIndex(lengths, len, lenIndex) {
        char *name = lgetElement(list, (int) lenIndex);
        printf("%s tem %d chars\n", name, (int) len);
    }
    
    releaseList(list);
}

int compareNumbers(const void *a, const void *b) {
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    return a1 - b1;
}

void testNumbers() {
    List *numbers = newListWithElements(5, 4, 1, 3, 5, 2);
    
    laddAll(numbers, 3, 10, 7, 9);
    
    lforEach(numbers, n) printf("%d\n", (int) n);
    
    lreduce(numbers, n, n1, 0, (int)n + (int)n1);
    printf("Soma = %d\n\n", (int) n);
    
    lsort(numbers, compareNumbers);
    lforEach(numbers, n) printf("%d\n", (int) n);
    
    releaseList(numbers);
}

void testArrayNames() {
    Array *array = newArrayWithElements(5, "PC", "Guilherme", "Pietro", "Fin", "Felipe");
    
    aforEach(array, name) printf("%s\n", name);
    
    emptyLines(2);
    
    aaddElement(array, "Roger");
    
    afind(array, name, namePC, strcmp(name, "Fin") == 0);
    
    printf("%s\n", namePC);
    
    asort(array, compareNames);
    
    aforEachIndex(array, name, nameIndex) printf("%s no index %d\n", name, (int) nameIndex);
    
    emptyLines(2);
    
    releaseArray(array);
}

int main(int argc, const char * argv[]) {
    testNames();
//    testNumbers();
//    testArrayNames();
    
    return 0;
}