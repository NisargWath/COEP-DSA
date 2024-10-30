#include<stdio.h>
#include<stdlib.h>
#include "header.h"



void init(Node * tr, int size){
    tr->data = (int *)malloc(sizeof(int) * size);
    tr->size = size;
    tr->len = 0;

    for(int i = 0;i<size;i++){
        tr->data[i] = -1;
    }
}

void insertNode(Node * tr, int data){
    if(tr->len > tr->size){
         printf("Tree is full, cannot insert %d\n", data);
        return;
    }
    int i = 0;
    while(i<tr->size && tr->data[i] !=-1){
        if(data<tr->data[i]){
            i = 2*i+1;
        }else{
            i = 2*i+2;
        }
    }
    if(i<tr->size){
        tr->data[i] = data;
        tr->len++;
    }
    else {
        printf("Tree is full, cannot insert %d\n", data);
    }
}
// void removeNode(Node * tr){
    
// }
void inordertraverse(Node * tr, int i){

        if(i>=tr->size|| tr->data[i] == -1) return;

        inordertraverse(tr, 2* i+1);
        printf("%d ", tr->data[i]);
        inordertraverse(tr, 2* i+2);

}
void posttraverse(Node * tr, int i){
    if(i>=tr->size|| tr->data[i] == -1) return;

        printf("%d ", tr->data[i]);
        posttraverse(tr, 2* i+1);
        posttraverse(tr, 2* i+2);
}
void pretraverse(Node * tr, int i){
    if(i>=tr->size|| tr->data[i] == -1) return;

        pretraverse(tr, 2* i+1);
        pretraverse(tr, 2* i+2);
        printf("%d ", tr->data[i]);

}

void destroyTree(Node * tr){
    free(tr->data);
    tr->data =NULL;
    tr->size = 0;
    tr->len = 0;
}
 

int count_leaf(Node * tr, int i){
    if(i>=tr->len || tr->data[i] == -1)
        return 0;
    
    if( (2*i+1 >= tr->len || tr->data[2*i+1] == -1)  &&  (2*i+2 >= tr->len || tr->data[2*i+2] == -1) ){
        return 1;
    }
    return count_leaf(tr,2*i+1) + count_leaf(tr, 2*i+2);
}
int count_nonleaf(Node * tr){
    return height(tr,0) - count_leaf(tr,0);
}


int height(Node *tr, int i) {
    if (i >= tr->len || tr->data[i] == -1)  // Base case for null nodes
        return -1;

    int leftHeight = height(tr, 2 * i + 1);
    int rightHeight = height(tr, 2 * i + 2);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}
