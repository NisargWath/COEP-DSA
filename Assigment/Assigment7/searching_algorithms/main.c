#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    Array a;
    init(&a,50);
    int n[10] = {12,1,3,4,3,6,7,8,19,20};
    for(int i = 0;i<10;i++){
        append(&a, n[i]);
    }
    printf("Element in Array\n");
    display(&a);
    printf("\nLinear Search\n");
    Linear_Search(&a, 19);
    printf("\nBinary Search\n");
     printf("sort the element  elementElement in Array for Binary Search\n");
    display(&a);
    sort(&a);

    Binary_Search(&a,12);
}