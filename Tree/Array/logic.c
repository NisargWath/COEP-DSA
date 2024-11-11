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



void deleteNode(Node *tr, int data) {
    int i = 0;
    while(i<tr->size && tr->data[i]!=data){
        if(data<tr->data[i]){
            i = 2*i+1;
        }else{
            i = 2*2+1;
        }
    }
    if(i>tr->len && tr->data[i] == -1){
        return;
    }
    int last = tr->len;
    tr->data[i] = tr->data[last];
    tr->data[last] = -1;
    tr->len--;

    int current  =i;
    while(current<tr->len){
        int left = 2 * current +1;
        int right = 2 * current +2;
        int swap  = current;
        if(left<tr->len && tr->data[left]!=-1 && tr->data[left]>tr->data[swap]){
            swap = left;
        }
        if(right<tr->len && tr->data[right]!=-1 && tr->data[right]>tr->data[swap]){
            swap = right;
        }
        if(swap == current){
            break;
        }
        int temp = tr->data[current];
         tr->data[current] = tr->data[swap];
         tr->data[swap] =temp;
         current = swap;
    }

}




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




// Non recursive

int inorder(Node * tr, int i){
    int  n = tr->size;
    int * stack = (int *)malloc(sizeof(int)* n );
    int top = -1;
    int cur = i;
    while(cur != -1 || top != -1){
        if(cur!= -1){
            stack[++top] = cur;
            cur = cur * 2+1;
        }else{
            cur = stack[top--];
            if(tr->data[cur]!= -1){
                printf("%d ", tr->data[cur]);
            }
            cur = 2 * cur+2;
        }
    }
}


void preorder(Node * tr, int i){
    int *stack =(int *)malloc(sizeof(int) * tr->size);
    int top= -1;
    stack[++top] =-1;
    stack[++top] = -1;
    while(top!=-1){
        int cur = stack[top--];
        if(tr->data[cur] != -1){
            printf("%d", tr->data[cur]);
        }
        int right = 2* cur +2;
        if(right<tr->size&& tr->data[right] != -1){
            stack[+top] = right;
        }
        int left = 2*cur+1;
        if(right<tr->size&& tr->data[right] != -1){
            stack[+top] = right;
        }
    }
    free(stack);
}



void postordertraverse(Node *tr, int i) {
    if (i >= tr->size || tr->data[i] == -1) return;


    int *stack1 = (int *)malloc(sizeof(int) * tr->size);
    int *stack2 = (int *)malloc(sizeof(int) * tr->size);
    int top1 = -1, top2 = -1;

    stack1[++top1] = i; // Start with the root
    while (top1 != -1) {
        int current = stack1[top1--];
        if (tr->data[current] != -1) {
            stack2[++top2] = current; // Store in second stack for post-order
        }

        // Push left and right children in the first stack
        int leftChild = 2 * current + 1;
        if (leftChild < tr->size && tr->data[leftChild] != -1) {
            stack1[++top1] = leftChild;
        }

        int rightChild = 2 * current + 2;
        if (rightChild < tr->size && tr->data[rightChild] != -1) {
            stack1[++top1] = rightChild;
        }
    }

    // Print elements from stack2 (postorder)
    while (top2 != -1) {
        printf("%d ", tr->data[stack2[top2--]]);
    }

    free(stack1);
    free(stack2);
}
