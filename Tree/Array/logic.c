#include<stdio.h>
#include<stdlib.h>
#include "header.h"



void init(Node * tr, int size){
    tr->data = (int *)malloc(sizeof(int) * size);
    tr->size = size;
    tr->len = 0;

    for(int i = 0;i<size;i++){
        tr->data[i] = -1;
    }
}

void insertNode(Node * tr, int data){
    if(tr->len > tr->size){
         printf("Tree is full, cannot insert %d\n", data);
        return;
    }
    int i = 0;
    while(i<tr->size && tr->data[i] !=-1){
        if(data<tr->data[i]){
            i = 2*i+1;
        }else{
            i = 2*i+2;
        }
    }
    if(i<tr->size){
        tr->data[i] = data;
        tr->len++;
    }
    else {
        printf("Tree is full, cannot insert %d\n", data);
    }
}



void deleteNode(Node *tr, int data) {
    int i = 0;
    while(i<tr->size && tr->data[i]!=data){
        if(data<tr->data[i]){
            i = 2*i+1;
        }else{
            i = 2*2+1;
        }
    }
    if(i>tr->len && tr->data[i] == -1){
        return;
    }
    int last = tr->len;
    tr->data[i] = tr->data[last];
    tr->data[last] = -1;
    tr->len--;

    int current  =i;
    while(current<tr->len){
        int left = 2 * current +1;
        int right = 2 * current +2;
        int swap  = current;
        if(left<tr->len && tr->data[left]!=-1 && tr->data[left]>tr->data[swap]){
            swap = left;
        }
        if(right<tr->len && tr->data[right]!=-1 && tr->data[right]>tr->data[swap]){
            swap = right;
        }
        if(swap == current){
            break;
        }
        int temp = tr->data[current];
         tr->data[current] = tr->data[swap];
         tr->data[swap] =temp;
 