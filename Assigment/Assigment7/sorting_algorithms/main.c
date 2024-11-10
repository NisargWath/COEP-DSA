#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    Array a;
    init(&a,50);
    int n[10] = {12,1,3,4,13,6,7,8,19,20};
    for(int i = 0;i<10;i++){
        append(&a, n[i]);
    }
    printf("Element in Array\n");
    display(&a);
    // printf("\nBubble Sort:\n");
    //  Bubble_Sort(&a);
    // display(&a);
    // printf("\nSelection Sort:\n");
    // Selection_Sort(&a);
    // display(&a);
    // printf("\nInsertion_Sort:\n");
    // Insertion_Sort(&a);
    // display(&a);
    printf("\nQuick_Sort:\n");
    quick_sort(&a, 0, a.len-1);
    display(&a);
    // printf("\nHeap_Sort:\n");
    // heap_sort(&a);
    // display(&a);
        

}