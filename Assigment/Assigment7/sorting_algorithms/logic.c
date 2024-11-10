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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Bubble_Sort(Array * arr){
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
    
void Selection_Sort(Array * arr){
    for(int i = 0; i<arr->len;i++){
        int key =  i;
        for(int j = i+1;j<arr->len;j++){
            if(arr->data[j]< arr->data[key]){
                key = j;
            }
        }
        int temp = arr->data[i];
        arr->data[i] = arr->data[key];
        arr->data[key] =  temp; 
        return;
    }
}


void Insertion_Sort(Array * arr){
    for(int i = 1;i<arr->len;i++){
        int key = arr->data[i];
        int j = i-1;

        while(j>=0 && arr->data[j] > key){
            arr->data[j+1] = arr->data[j];
            j = j-1;
        }
        arr->data[j+1] = key;
    }
}


int partition(Array * arr, int low, int high) {
    int pivot  = arr->data[high];
    int i = low-1;

    for(int j = low;j<high;j++){
        if(arr->data[j]< pivot){
            i++;
            int temp = arr->data[i];
            arr->data[i] = arr->data[j];
            arr->data[j] = temp;
        }
    }
           i++;
            int temp = arr->data[i];
            arr->data[i] =  pivot;
            arr->data[high] = temp;
            return i;
}


void quick_sort(Array * a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}






void heapify(Array * arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  


    if (left < n && arr->data[left] > arr->data[largest]) {
        largest = left;
    }


    if (right < n && arr->data[right] > arr->data[largest]) {
        largest = right;
    }


    if (largest != i) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[largest];
        arr->data[largest] = temp;

        heapify(arr, n, largest);  
    }
}


void heap_sort(Array * arr) {
    int n = arr->size;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {

        int temp = arr->data[0];
        arr->data[0] = arr->data[i];
        arr->data[i] = temp;
        heapify(arr, i, 0);
    }
}






void display(Array *a){
    for(int i = 0;i<a->len;i++){
        printf("%d ",a->data[i]);
    }
    printf("\n");
}