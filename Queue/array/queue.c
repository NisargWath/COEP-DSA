#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

#define true 1
#define false 0

void qinit(queue * q, int size){
    q->data = (int *)malloc(sizeof(int) *size);
    q->size = size;
    q->front = -1;
    q->rear = -1;
    return;
}
int qfull(queue * q){
    if(q->rear == q->size-1) return true;

    return false;
}
int  qempty(queue * q){
    if( q->front ==  -1) return true;

    return false;
}

void enq(queue * q, int value){
    if(qfull(q)){
        printf("Queue is FULL");
        return;
    }
    else if(q->front == -1){
        q->front  =0;
    }

        q->data[++q->rear] = value;
    return;
}
int  deq(queue * q){
    if(qempty(q)){
        printf("Queue is Empty!");
        return -1;
    }

    int x = q->data[q->front];
    q->front++;
    if(q->front > q->rear){
        q->front = q->rear = -1;
    }
    return x;
}


void display(queue * q){
    for(int i = q->front ;i<=q->rear;i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int peek(queue * q){
    if(qempty(q)){
        printf("Queue is Empty!");
        return -1;
    }
    return q->data[q->front];
}