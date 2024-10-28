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
    if(a->len > a->size-1) return;
        a->data[a->len] = value;
        a->len++;

     
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
	if(ind > a->size || ind < 0) {
		return;
	}

   int i = a->size - 1;

	while(i > ind) {
		a->data[i + 1] = a->data[i];
		i--;
	}

	a->data[ind] = value;
	a->len++;
	return;
    
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

int maxele(Array * arr){
    int max = arr->data[0];
    for(int i = 1;i<arr->size;i++){
        if(arr->data[i] >max){
            max = arr->data[i];
        }
    }
    return max;
}


int minele(Array * arr){
        int min = arr->data[0];
    for(int i = 1;i<arr->size;i++){
        if(arr->data[i] < min){
            min = arr->data[i];
        }
    }
    return min;
}

void reverse(Array * arr){
    int l = 0, h= arr->len-1;

    while(l<h){
        int temp = arr->data[l];
        arr->data[l] = arr->data[h];
        arr->data[h] = temp;
        l++;
        h--;
    }
}

void merge(Array *a, Array *b) {
    // Append each element of array 'b' to array 'a'
    for (int i = 0; i < b->len; i++) {
        append(a, b->data[i]);  // Assumes append will handle resizing if needed
    }
    display(a);
}
void mov_neg(Array * a){
    Array * c, *b;
    init(c,20);
    init(b,20);

    for(int i = 0;i<a->len;i++){
        if(a->data[i] < 0){
            append(c,a->data[i]);
        }
        else{
            append(b,a->data[i]);
        }
    }
    int i = 0, j = 0;
    while(i<c->len){
        a->data[i]  = c->data[i]; 
        i++;
    }
    while(j<b->len){
        a->data[i] = c->data[j];
        j++;
        i++;
    }

}


