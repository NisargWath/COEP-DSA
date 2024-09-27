// Display array elements in reverse. ie from last to first
// Display elements of array in triangle pattern. Use formatting to get a uniform display. 
// Eg: 
// A = {60,700,80,900,10} 
// Output: 
 
// 60 
// 60  700 
// 60  700  80 
// 60  700  80  900 
// 60  700  80  900   10
#include<stdio.h>
#include<stdlib.h>
#include "Array.h"


void reverse(Array *a){
    for(int i = a->len-1;i>=0;i--){
        printf("%d\t", a->data[i]);
    }
    printf("\n");
}

void pattern(Array *a){
    for(int i = 0;i<a->len;i++){
        for(int j = 0;j<i+1;j++){
            printf("%d ", a->data[j]);
        }
        printf("\n");
    }
}

int main(){
    Array a;
    init(&a, 10);
    append(&a, 60);
    append(&a, 700);
    append(&a, 80);
    append(&a, 900);
    append(&a, 10);

    printf("Reverse List =:- \t");
    reverse(&a);
    printf("\nPattern:-\n");
    pattern(&a);
    
}