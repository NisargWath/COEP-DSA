#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init_ASCII(ASCII *l) {
    l->head = NULL;
    l->tail = NULL;
}

void ASCII_of(ASCII *l, char a) {
    int b = (int)a;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = b;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    }
}

void traverse(ASCII *l) {
    Node *temp = l->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Destroy(ASCII *l) {
    Node *temp = l->head;
    while (temp != NULL) {
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    l->head = NULL;
    l->tail = NULL;
}
