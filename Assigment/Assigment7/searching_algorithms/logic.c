#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Array * a, int size){
    a->data = (int *)malloc(sizeof(int) * size);
    a->size = size;
    a->len = 0;
}
void append(Array * a, int data){
    if(a->len > a->size)
    return;

    a->data[a->len++] = data;
}

void Linear_Search(Array * a, int key){
    
    for(int i = 0;i<a->len;i++){
        if(a->data[i] == key){
            printf("Element found at %d place\n", i);
        }
    }
}

void Binary_Search(Array *a, int key) {
    int low = 0;
    int high = a->len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a->data[mid] == key) {
            printf("Element Found at %d place", mid);
            return;  
        }
        if (a->data[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found\n"); 
}

void sort(Array * arr){
    for(int i  = 0;i<arr->len-1;i++){
        for(int j = 0;j<arr->len-i-1;j++){
            if(arr->data[j]>arr->data[j+1]){
                int temp = arr->data[j+1];
                arr->data[j+1] =arr->data[j];
                arr->data[j] = temp;
            }
        }
    }
    return;
}


void display(Array *a){
    for(int i = 0;i<a->len;i++){
        printf("%d ",a->data[i]);
    }
    printf("\n");
}
