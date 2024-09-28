 //  Write code to find second largest element in a 1D Array 
#include<stdio.h>
#include<stdlib.h>
#include "Array.h"
#include <limits.h>


    
void secondLargest(Array *a){
    int largest = 0;
    int second_largest = 0;
    for(int i  = 0;i<a->len;i++){
       if(a->data[i]>largest){
        second_largest = largest;
        largest = a->data[i];
       }else if (a->data[i] > second_largest && a->data[i] != largest)
       {
        second_largest = a->data[i];
       }
    }
    printf("Second shortest element is %d\n",second_largest);
}

int main(){
    Array  a ;
    init(&a,10);
    // int lesser, greater;
    append(&a,10);
    append(&a,5);
    append(&a,8);
    append(&a,32);
    append(&a,13);
    secondLargest(&a);

    display(&a);
    return 0;
}