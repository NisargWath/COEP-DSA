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
void enq(queue *q, data d1) {
    if (qfull(q)) {
        printf("Queue is full\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->d = d1;
    newNode->next = q->head;  // Circular connection for the new node

    if (q->head == NULL) {
        // If queue is empty, initialize head and tail
        q->head = newNode;
        q->tail = newNode;
        q->tail->next = q->head;  // Circular connection
    } else {
        q->tail->next = newNode;
        q->tail = newNode;  // Move tail to the new node
    }
}

data deq(queue *q) {
    data d = {"", 0};  // Initialize to avoid returning uninitialized data
    if (qempty(q)) {
        printf("Queue is empty\n");
        return d;
    }

    Node *temp = q->head;
    d = temp->d;

    if (q->head == q->tail) {
        // Only one element in the queue
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;  // Maintain circular link
    }

    free(temp);
    return d;
}
