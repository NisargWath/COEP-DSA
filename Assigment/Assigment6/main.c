#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void read_file_to_heap(char *filename, heap *h1) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(1);
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        insertInheap(h1, num);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int maxSize = 100;  
    heap h1;
    initHeap(&h1, maxSize);

    read_file_to_heap(filename, &h1);
    printf("Heap before sorting:\n");
    print_heap(h1);

    printf("Heap after sorting:\n");
    heap_sort(&h1);


    free(h1.data);
    return 0;
}
