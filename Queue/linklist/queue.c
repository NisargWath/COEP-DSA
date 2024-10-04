#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#define true 1
#define false 0

queue * qinit(){
    queue * qu = (queue *)malloc(sizeof(queue));
    qu->head = NULL;
    qu->tail = NULL;
    return qu;
}

int qfull(queue *q) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {

        return true;
    } else {
        free(temp);
        return false;
    }
}


int qempty(queue * q){
    if(q->head == NULL) return  true;

    return false;
}
void enq(queue * q, int value){
    Node * newNode  = (Node *)malloc(sizeof(Node));
    newNode->data =value;
    newNode->rear = NULL;
    if(qfull(q)) {
    printf("Stack is full");
    return ;
}
    if(q->tail == NULL){
        q->head = newNode;
        q->tail =  newNode;
    }else{
        q->tail->rear = newNode;
        q->tail = newNode;
    }
}
int  deq(queue * q){
    if(qempty(q)){
        printf("quueue is empty!!");
        return -1;
    }

    int value = q->head->data;
    Node * temp= q->head;
    q->head =q->head->rear;
    if (q->head == NULL) {
        q->tail = NULL; // Queue is now empty
    }
    
    free(temp);
    return value;
}



void display(queue * q){
    Node * temp =  q->head;
      while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->rear;
    }
    printf("\n");
}