#include<stdio.h>
#include<stdlib.h>
#include "List.h"

void  init(List * l){
    l->head = NULL;
    l->tail = NULL;
    return;
}


int isEmpty(List * l){
    if(l->head  ==  NULL){
        return 1;
    }
    return 0;
}


void insert_from_front(List *l, int data){
    Node * newNode =  (Node *)malloc(sizeof(Node));
    if(newNode){
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = data;
    }else{
        return;
    }
    if(isEmpty(l)){
        l->head = newNode;
        l->tail = newNode;
        return;
    }
    else{
        Node * temp = l->head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next =  newNode;
        newNode->prev = temp;
        l->tail = newNode;
    }
    return;

}



void display(List * l){
    Node * temp = l->head;
    while(temp != NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int find_length(List * l){
    int cnt = 0;
    Node * te = l->head;
    while(te != NULL){
        cnt++;
        te = te->next;
    }
    return cnt;
}


void reverse_display(List * l){
    Node * temp = l->tail;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insert_using_rear_end(List *l, int data){
        Node * newNode = (Node *)malloc(sizeof(Node));
        if(newNode){
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;
        }

        if(isEmpty(l)){
            l->head = NULL;
            l->tail = NULL;
            return;
        }
        else{
            l->tail->next = newNode;
            newNode->prev = l->tail;
            l->tail = newNode;
        }
        return;
}

int search(List *l, int key){
    int i = 0;
    Node * temp = l->head;
    while(temp != NULL){
        if(temp->data == key){
            return i;
        }
        i++;
        temp = temp->next;
    }
    return 0;
}

    
