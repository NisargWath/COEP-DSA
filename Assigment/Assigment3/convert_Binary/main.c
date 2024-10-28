#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int n;

    // Input a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    printf("Binary representation of %d: ", n);
    int str[32];  // Array to store binary number (32 bits for typical integer)
    int i = 0;

    // Handle the special case for 0
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    // Convert to binary
    while (n > 0) {
        str[i] = n % 2;   // Store remainder (0 or 1)
        n = n / 2;        // Divide the number by 2
        i++;
    }

    Stack s;
    init(&s, 32);

    // Push binary digits into the stack
    for (int j = 0; j < i; j++) {
        push(&s, str[j]);
    }

    // Pop from the stack and print binary digits in reverse order
    printf("Reversed Binary: ");
    while (!isEmpty(s)) {
        printf("%d", pop(&s));
    }
    printf("\n");

    return 0;
}
