#include<stdio.h>
#include<stdlib.h>
#include "Array.h"

void init(Array *a, int size){
    a->data = (int *)malloc(size * sizeof(int));
    a->len = 0;
    a->size = size;
    return;

}

void append(Array *a, int value){
    if(a->len < a->size){
        a->data[a->len] = value;
        a->len++;
    }else{
        printf("\nOut of Bound");
    }
    return;

}

void display(Array * a){
    for(int i = 0 ;i<a->len;i++){
        printf("%d\t", a->data[i]);
    }
    printf("\n");
    return;

}
void insert_at_index(Array * a, int ind, int value){
    if(a->len < a->size){
    for(int i = 0;i<a->size;i++){
        if(i == ind){
            a->data[i] = value;
        }
    }
    }else{
        printf("\nOut of Bound");
    }


}

void remove_at_index(Array * a, int ind){
    for(int i  =0 ;i<a->size;i++){
        if(i == ind){
            a->data[i] = a->data[i+1];
            break;
        }
    }
    a->len--;
    return;
}






