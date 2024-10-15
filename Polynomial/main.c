#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main() {
    Poly p, q, sub, sum;
    int size1 = 2, size2 = 2;

    init(&p, size1);
    init(&q, size2);

    append(&p, 10, 2);
    append(&p, 9, 3);

    append(&q, 1, 2);
    append(&q, 2, 3);

    display(&p);
    display(&q);

    sub = sub_poly(&p, &q);
    sum = add_poly(&p, &q);

    printf("Sum of the polynomials are:-  ");
    display(&sum);
    printf("Sum of the polynomials are:-  ");
    display(&sub);

    // Free memory after use
    freePolynomial(&p);
    freePolynomial(&q);
    freePolynomial(&sub);

    return 0;
}