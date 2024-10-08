#include<stdio.h>
#include "queue.h"
#include<stdlib.h>


void qinit(queue * q){
    q->head = NULL;
    q->tail = NULL;
    return;
}

int  qfull(queue * q){
        Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {

        return 1;
    } else {
        free(temp);
        return 0;
    }
}
int qempty(queue * q){
    if(q->head == NULL) return 1;

    return 0;
}

void  enq(queue * q, data d1){
    if(qfull(q)){
        printf("queue is full");
        return;
    }
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->d =d1;
    newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }else{
        newNode->next = q->head;
        q->tail->next = newNode;
        q->head = newNode;
    }
}
data deq(queue * q){
    data d;
    if(qempty(q)){
        printf("queue is full");
        return d;
    }
    Node* temp = q->head;
    d = temp->d;

    if (q->head == q->tail) {

        q->head = NULL;
        q->tail = NULL;
    } else {

        q->head = q->head->next;
        q->tail->next = q->head;
    }

    free(temp);
    return d;
}

