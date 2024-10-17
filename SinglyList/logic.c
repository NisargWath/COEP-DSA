#include<stdio.h>
#include<stdlib.h>
 
#include "List.h"


void init(link * l){

    l->head = NULL;

}

void append(link * l, int data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if(l->head == NULL ){
        l->head = newnode;
    }
    else{
        newnode->next = l->head;
        l->head = newnode;
    }
    return;

}

void display(link * l){
    Node * temp = l->head;
    while(temp  != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int findlength(link *l){
    Node * temp = l->head;
    int count= 0 ;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}


int search(link * l, int key){
    int  i =  0;
    Node * temp = l->head;
    while(temp != NULL){

        if(temp->data == key){
            return i;
        }
        i++;
        temp = temp->next;
    }
    return i;
}



void remove_head(link * l){
    if(l->head == NULL){
        printf("\nList is empty\n");
        return;
    }
    Node * delNode = l->head;
    l->head = l->head->next;
    free(delNode);
    return;
}

void remove_end(link * l){
    if(l->head == NULL){
        printf("Out of bound");
        return;
    }
    Node * temp = l->head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node * del = temp->next;
    temp->next = NULL;
    free(del);
    return;
}

void remove_index(link * l,int ind){
    if(!l){
        printf("Out of bound");
        return;
    }
    if(ind == 0){
        Node * newnode = l->head;
        l->head = l->head->next;
        free(newnode);
        return;
    }

    Node * temp = l->head;
    int i = 0;
    while(temp->next != NULL && i == ind){
            i++;
            temp = temp->next;
    }
    if(temp->next == NULL){
         Node * newNode  =  temp->next;
         temp->next = NULL;
         free(newNode);
         return;
    }
     Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}


void insert_Index(link * l, int ind, int value){

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data= value;

    if(ind == 0){
        newNode->next =l->head;
        l->head = newNode;
        return;
    }
    int i = 0;
    Node * temp = l->head;
    while(temp != NULL && i <= ind -1 ){
        temp = temp->next;
        i++;
    }
        if (temp == NULL) {
        printf("Index out of bounds\n");
        free(newNode); 
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

link * mergeTwoLists(link *l1, link *l2){

        Node * temp2 = l2->head;

   
        while(temp2!= NULL){
            append(l1, temp2->data);
            temp2 = temp2->next;
        }

        return l1;
}


