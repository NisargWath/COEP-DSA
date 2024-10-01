// Write a program to check if elements of an array are same or not it read from front or 
// back. E.g.- 
// 2 3 15 15 3 2

#include<stdio.h>
#include<stdlib.h>
#include "Array.h"

void palindrome(Array *a) {
    int l = 0, h = a->len - 1;
    while (l < h) {
        if (a->data[l] != a->data[h]) {
            printf("Not a Palindrome!!"); // Not a palindrome
            break;
        }
        l++;
        h--;
    }
    printf("It is a Palindrome"); // Is a palindrome
}

int main(){
    
    Array a;
    init(&a, 10);  
    append(&a, 1);
    append(&a, 2);
    append(&a, 5);
    append(&a, 2);
    append(&a, 1);
    palindrome(&a);

    printf("Array: ");
    display(&a);

}