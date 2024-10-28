#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void sort_exp(Poly *p); // Forward declaration

void init(Poly *p, int size) {
    p->p = (node *)malloc(sizeof(node) * size);
    p->len = 0;
    p->size = size;
}

void append(Poly *p, int coef, int exp) {
    if (p->len < p->size) {
        int i = p->len;
        p->p[i].coef = coef;
        p->p[i].exp = exp;
        p->len++;
    }
    return;
}

void display(Poly *p) {
    sort_exp(p); // Sorting before displaying
    int i;
    printf("\n");
    for (i = 0; i < p->len - 1; i++) {
        printf("(%d)x^%d  ", p->p[i].coef, p->p[i].exp);
    }
    printf("(%d)x^%d\n\n", p->p[i].coef, p->p[i].exp);
    return;
}

void sort_exp(Poly *p) {
    int n = p->len;
    node *temp = p->p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {  // Changed loop to n - 1
            if (temp[j].exp < temp[j + 1].exp) {
                int coe, ex;
                ex = temp[j].exp;
                coe = temp[j].coef;
                temp[j].exp = temp[j + 1].exp;
                temp[j].coef = temp[j + 1].coef;
                temp[j + 1].exp = ex;
                temp[j + 1].coef = coe;
            }
        }
    }
    return;
}




Poly add_poly(Poly *p, Poly *q) {
    Poly result;
    init(&result, p->len + q->len);
    int i = 0, j = 0;

    while (i < p->len && j < q->len) {
        if (p->p[i].exp == q->p[j].exp) {
            append(&result, p->p[i].coef + q->p[j].coef, p->p[i].exp); // Combine coefficients
            i++;
            j++;  // Move both indexes forward when combined
        } else if (p->p[i].exp > q->p[j].exp) {
            append(&result, p->p[i].coef, p->p[i].exp); // Append the higher exponent from p
            i++;
        } else {
            append(&result, q->p[j].coef, q->p[j].exp); // Append the higher exponent from q
            j++;
        }
    }

    // Append remaining terms if any
    while (i < p->len) {
        append(&result, p->p[i].coef, p->p[i].exp);
        i++;
    }
    while (j < q->len) {
        append(&result, q->p[j].coef, q->p[j].exp);
        j++;
    }

    return result;
}

Poly sub_poly(Poly *p, Poly *q) {

    Poly result;
    init(&result, p->len + q->len);
    int i = 0, j = 0;

    // Loop through both polynomials
    while (i < p->len && j < q->len) {
        if (p->p[i].exp == q->p[j].exp) {
            append(&result, p->p[i].coef - q->p[j].coef, p->p[i].exp); // Subtract coefficients
            i++;
            j++;  
        } else if (p->p[i].exp > q->p[j].exp) {
            append(&result, p->p[i].coef, p->p[i].exp); 
            i++;
        } else {
            append(&result, -q->p[j].coef, q->p[j].exp); 
            j++;
        }
    }


    while (i < p->len) {
        append(&result, p->p[i].coef, p->p[i].exp);
        i++;
    }


    while (j < q->len) {
        append(&result, -q->p[j].coef, q->p[j].exp);
        j++;
    }

    return result;
}


void freePolynomial(Poly *p) {
    free(p->p);
}

