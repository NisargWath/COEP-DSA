// Reverse elements of array without using additional array. 
// Eg 
// input array – {10,45,3216,88} 
// should change to {88,16,32,45,10}


#include<stdio.h>
#include<stdlib.h>
#include "Array.h"

void reverse(Array * a){
    int low = 0, high = a->len-1;

    while(low<high){
        int temp = a->data[low];
        a->data[low] = a->data[high];
        a->data[high] = temp;
        low++;
        high--;
    }
}

int main(){
    Array  a;
    init(&a,10);
    append(&a,10);
    append(&a,45);
    append(&a,88);
    append(&a,3216);
    display(&a);
    reverse(&a);
    display(&a);

}