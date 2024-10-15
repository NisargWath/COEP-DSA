#include<stdio.h>
#include<stdlib.h>

typedef struct Array{
    int *data;
    int size; 
    int len;
} Array;

void init(Array *a, int size){
    a->data = (int *)malloc(sizeof(int) * size);
    a->size = size;
    a->len = 0;
}

void append(Array *a, int value){
    if(a->len < a->size){
        a->data[a->len] = value;
        a->len++;
    }
    return;
}

void display(Array *a){
    for(int i = 0; i < a->len; i++){
        printf("%d ", a->data[i]);
    }
    printf("\n");
}

int check(Array *b, int elem, int ind){
    for(int i = 0; i < ind; i++){
        if(b->data[i] == elem){
            return 1;
        }
    }
    return 0;
}

void duplicate(Array *b){
    int i = 0;
    while(i < b->len){
        if(check(b, b->data[i], i)){
            for(int j = i; j < b->len - 1; j++){
                b->data[j] = b->data[j + 1];
            }
            b->len--;
        } else {
            i++;
        }
    }
}

void divisible(Array *a, Array *b){
    for(int i = 0; i < a->len; i++){
        if(a->data[i] % 8 == 0 || a->data[i] % 15 == 0){
            append(b, a->data[i]);
        }
    }
}

int main() {
    Array a, b;
    init(&a, 100);
    init(&b, 100);

    for(int i = 1; i <= 100; i++){
        append(&a, i);
    }

    divisible(&a, &b);
    
    for(int i = 1; i <= 10; i++){
        append(&b, 8 * i);
    }

    printf("Original Array:\n");
    display(&a);

    printf("\nElements divisible by 8 or 15:\n");
    display(&b);

    duplicate(&b);
    
    printf("\nArray after removing duplicates:\n");
    display(&b);

    return 0;
}
