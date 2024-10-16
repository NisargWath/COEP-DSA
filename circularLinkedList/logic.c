#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(List *ls){
    ls->head = NULL;
    return;
}

void display(List *ls){
    if(ls->head == NULL) return;

    Node * temp = ls->head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != ls->head);
    printf("\n");
}

void append(List * l, int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;


    if(l->head ==  NULL){
        l->head = newNode;
        newNode->next = l->head;
        return;
    }
    Node * temp = l->head;
    while(temp->next != l->head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = l->head;
    return;
}

void insertAtBeginning(List *l, int data){
    Node * newNode = (Node *)malloc(sizeof(Node));\
    newNode->data  =  data;

    if(l->head == NULL){
        l->head = newNode;
        newNode->next = l->head;
        return;
    }
    Node * temp = l->head;
    while(temp->next != l->head){
        temp = temp->next;
    }

    newNode->next = l->head;
    l->head = newNode;
    temp->next = l->head;
    return;
}

int removeEnd(List *l){
    if(l->head == NULL) return -1;
   Node * temp = l->head;

   if(temp ->next == l->head){
    int n = temp->data;
    free(temp);
    l->head = NULL;
    return n;
   }

   while(temp->next->next != l->head){
    temp = temp->next;
   }
   int n = temp->next->data;
   Node * del = temp->next;
   temp->next = l->head;
   free(del);
   return n;

}

int removeBeginning(List *l){
    if(l->head == NULL) return -1;
    Node * temp = l->head;
    if(temp->next == l->head){
        int n = temp->data;
        free(temp);
        l->head = NULL;
        return n;
    }

    while(temp->next != l->head){
        temp = temp->next;
    }
   int n = l->head->data;
   Node * del = l->head;
   temp->next =del->next;
   l->head = del->next;
   free(del);
   return n;
}

int length(List *l) {
    if (l->head == NULL) {
        return 0;  // List is empty
    }

    Node *temp = l->head;
    int i = 1;
    while (temp->next != l->head) {
        temp = temp->next;
        i++;
    }
    return i;
}


void fill(List *l, int n){
    if(n < 0) return;
    for(int i = 0;i<n;i++){
        append(l, rand()% 200 -100);
    }

    return;
}

void destroy(List *l){
    Node * cur = l->head;
    Node * temp;
    while(cur->next != l->head){
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    free(cur);
    l->head = NULL;
    return;
}
void del_odd(List * l){
    Node * temp = l->head;

    while(temp->next != l->head){
        if(temp->data % 2 != 0){
            Node * del = temp;
            temp = temp->next;
            free(del);
        }
        temp = temp->next;
    }
}