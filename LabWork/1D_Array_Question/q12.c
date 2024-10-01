// C program to find nearest lesser and greater element in an array. 

#include<stdio.h>
#include<stdlib.h>
#include "Array.h"
#include <limits.h>


void findNearestElements(Array *a, int size, int target, int *lesser, int *greater) {
    *lesser = INT_MIN;
    *greater = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (a->data[i] < target && a->data[i] > *lesser) {
            *lesser = a->data[i];
        }
        if (a->data[i] > target && a->data[i] < *greater) {
            *greater = a->data[i];
        }
    }
}

int main(){
    Array  a;
    init(&a,10);
    int lesser, greater;
    append(&a,10);
    append(&a,45);
    append(&a,88);
    append(&a,3);
    int t = 12;
    findNearestElements(&a,a->len,t,&lesser,&greater);
    if (lesser != INT_MIN)
        printf("Nearest lesser element to %d: %d\n", t, lesser);
    else
        printf("No lesser element found.\n");

    if (greater != INT_MAX)
        printf("Nearest greater element to %d: %d\n", t, greater);
    else
        printf("No greater element found.\n");

    return 0;

}
