// Write a program that calculates the sum of squares of the elements of an integer array 
// of size 10.
#include<stdio.h>
#include<stdlib.h>
#include "Array.h"
#define size 10

int sum_of_square(Array *a){
    int sum = 0;
    for(int i = 0;i<a->len;i++){
        sum += (a->data[i] * a->data[i]);
    }
    return sum;

}
int main(){
    Array  a;
    init(&a, size);
    for(int i = 1;i<=size;i++){
        append(&a,i);
    }
    printf("Sum of square of %d", sum_of_square(&a));


}