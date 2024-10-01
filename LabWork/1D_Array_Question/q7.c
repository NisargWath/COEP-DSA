// Delete all duplicate elements from an array retaining the first occurrence. Note: 
// Array elements cannot be deleted. shift and replace can be done

#include<stdio.h>
#include<stdlib.h>
#include "Array.h"


    
void duplicate(Array * a){

        for (int i = 0; i < a->len; i++) {
        for (int j = i + 1; j < a->len; j++) {
            if (a->data[i] == a->data[j]) {

                for (int k = j; k < a->len - 1; k++) {
                    a->data[k] = a->data[k + 1];
                }
                a->len--;  
                j--; 
            }
        }
    }

}
int main(){
    Array  a;
    init(&a,10);
    append(&a,1);
    append(&a,12);
    append(&a,1);
    append(&a,13);
    append(&a,12);
    printf("Before");
    display(&a);
    duplicate(&a);
    printf("After");

    display(&a);

}