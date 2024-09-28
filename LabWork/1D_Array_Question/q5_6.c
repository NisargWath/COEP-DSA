
// 5.  You know size of integer array. Can you find number of elements in it? How? 
// 6.  Write C program to shift all elements of an array by n locations to right or left in 
// circular fashion. Take all inputs from user.

#include<stdio.h>
#include<stdlib.h>
#include "Array.h"
int length(Array *a) {
    return a->len;  // This is already tracked in the `len` attribute
}

// Function to shift elements in circular fashion by `n` locations
void shift(Array *a, int n) {
    int temp[a->len];

    // Handle negative shifts (left shift) by converting to an equivalent right shift
    if (n < 0) {
        n = (n % a->len + a->len) % a->len;
    }

    // Perform the circular shift
    for (int i = 0; i < a->len; i++) {
        int newIndex = (i + n) % a->len;
        temp[newIndex] = a->data[i];
    }

    // Copy the shifted elements back into the original array
    for (int i = 0; i < a->len; i++) {
        a->data[i] = temp[i];
    }
}

int main() {
    Array a;
    init(&a, 10);

    // Adding elements to the array
    append(&a, 60);
    append(&a, 700);
    append(&a, 80);
    append(&a, 900);
    append(&a, 5);

    printf("Original Array: ");
    display(&a);

    printf("Length of the Array: %d\n", length(&a));

    int n;
    printf("Enter the number of positions to shift the array: ");
    scanf("%d", &n);

    shift(&a, n);

    printf("Array after shifting by");
    display(&a);
}