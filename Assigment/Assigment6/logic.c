#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void initHeap(heap * h1, int size){
    h1->data = (int *)malloc(sizeof(int) * size);
    h1->rear =-1;
    h1->size=size;
    return;
}

void swaph(heap * h1, int a, int b){
    if(a>=h1->size || b>=h1->size) return;

    int temp = h1->data[a];
    h1->data[a] =h1->data[b];
    h1->data[b] = temp;
    return;
}


int parent(int index){
    return ((index -1)/2);
}


void insertInheap(heap * h1, int data){
    if(h1->rear == h1->size-1) return;
    h1->rear++;
    h1->data[h1->rear] = data;
    int i = h1->rear;
    while(i>0 && h1->data[i]> h1->data[parent(i)]){
        swaph(h1, i,parent(i));
        i = parent(i);
    }

}
void print_heap(heap h1){
    for(int i =0;i<h1.rear;i++){
        printf("%d ",h1.data[i]);
    }
    printf("\n");
}

void heapify(heap * h1){
    if(h1->rear ==0 || h1->rear ==-1) return;
    int i = 0;
    while(i<=(h1->rear)){
        int l = 2*i+1;
        int r = 2*i+2;
        if(l>h1->rear){
            return;
        }
        if(r>=h1->rear){
            if(h1->data[i]<h1->data[l]){
            swaph(h1,i,l);
            }
            return;
        }
        if(h1->data[l]>h1->data[r]){
            swaph(h1,i,l);
            i = l;
        }else{
            swaph(h1,i,r);
            i =r;
        }
    }
}
void delete_max(heap * h1){
    if(h1->rear==-1)return;
    h1->data[0]  = h1->data[h1->rear];
    h1->rear--;
    heapify(h1);
    return;
}
void heap_sort(heap *h1){
    int  k = h1->rear;
    if(h1->rear == -1) return;
    for(int i = h1->rear;i>0;i++){
        swaph(h1, i,0);
        h1->rear--;
        heapify(h1);
    }
    h1->rear = k;
    print_heap(*h1);
    return;
}