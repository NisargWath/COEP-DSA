#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    heap h1;
    init_heap(&h1,10);
    int a[7] = {10,20,15,12,40,25,18};
    for(int i = 0;i<7;i++){
        insert_heap(&h1, a[i]);
    }
    print_heap(h1);
    heap_sort(&h1);
    delete_max(&h1);
    print_heap(h1);

}