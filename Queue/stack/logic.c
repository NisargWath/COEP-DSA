#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void init(queue *q, int size);
int isempty(queue *q);
int isfull(queue *q);
void Enq(queue *q, int data);
int deq(queue *q);
int top(queue *q);
void display(queue *q);
void push(queue *q, int data);  
int pop(queue *q);            

void init(queue *q, int size) {
    q->data = (int *)malloc(sizeof(int) * size);
    q->size = size;
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q) {
    return (q->front == -1);
}

int isfull(queue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

void Enq(queue *q, int data) {
    if (isfull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = data;
}

int deq(queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int n = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return n;
}

int top(queue *q) {
    if (!isempty(q)) {
        return q->data[q->front];
    }
    return -1; 
}

void display(queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->data[q->rear]); 
}


void push(queue *q, int data) {

    Enq(q, data);
    

    for (int i = 0; i < (q->rear - q->front + q->size) % q->size; i++) {
        int temp = deq(q);
        Enq(q, temp);
    }
}


int pop(queue *q) {
    return deq(q);  
}


