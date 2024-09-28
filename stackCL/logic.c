#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Stack * s){
    s->head = (Node *)malloc(sizeof(Node));
    s->head->next = NULL;
    return;
}

int isempty(Stack * s){
    if(s != NULL){
        return 1;
    }
    return 0;
}
void push(Stack *s, int data){

        Node * newNode = (Node *)malloc(sizeof(Node));

        newNode->data= data;
        newNode->next = s->head;
        s->head = newNode;
}

int pop(Stack *s){
    if(!isempty(s)){
        printf("\nStack is empty!\n");
        return 0;
    }
        int temp = s->head->data;
        Node * node  = s->head;
        s->head = s->head->next;
        free(node);
    
    return temp;

}

void display(Stack *s){
    Node * temp = s->head;
    while(temp->next!= NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(Stack *s){
    if(!isempty(s)){
        return 0;
    }
    return s->head->data;
}
