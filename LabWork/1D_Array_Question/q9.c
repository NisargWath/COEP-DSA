// Take 20 integer inputs from user and print the following: 
// number of positive numbers 
// number of negative numbers 
// number of odd numbers 
// number of even numbers 
// number of 0.

#include<stdio.h>
#include<stdlib.h>
#include "Array.h"


void postive(Array *a){
    printf("\nPostive Number are:- ");
    for(int i = 0;i<a->len;i++){
        if(a->data[i]>0){
            printf("%d ",a->data[i]);
        }
    }
    printf("\n");
}


void negative(Array *a){
    printf("\nNegative Number are:- ");
    for(int i = 0;i<a->len;i++){
        if(a->data[i]<0){
            printf("%d ",a->data[i]);
        }

    }
    printf("\n");
}

void odd(Array *a){
    printf("\nOdd Number are:- ");
    for(int i = 0;i<a->len;i++){
        if(a->data[i]%2 != 0){
            printf("%d ",a->data[i]);
        }
    }
    printf("\n");
}


void even(Array *a){
    printf("\nEven Number are:- ");
    for(int i = 0;i<a->len;i++){
        if(a->data[i]%2 == 0){
            printf("%d ",a->data[i]);
        }

    }
    printf("\n");
}



int main(){
    Array * a;
    init(a,10);
    append(a,10);
    append(a,-1);
    append(a,3);
    append(a,-12);
    append(a,-2);
    odd(a);
    even(a);
    postive(a);
    negative(a);


}