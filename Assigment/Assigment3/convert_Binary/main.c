#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(){
    int n;

    // Input a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert and print binary representation
    printf("Binary representation of %d: ", n);
    int str[32];  // Array to store binary number (32 bits for typical integer)
    int i = 0;

    // Handle the special case for 0
    if (n == 0) {
        printf("0");

    }


    while (n > 0) {
        str[i] = n % 2;   // Store remainder (0 or 1)
        n = n / 2;           // Divide the number by 2
        i++;
    }

    Stack s;
    init(&s,100);

    for(int i = 0;i<n;i++){
        push(&s, str[i]);
    }
    for(int i = 0;i<n;i++){
        str[i] = pop(&s); 
    }
      printf("%s", str);
}