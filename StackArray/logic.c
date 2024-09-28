#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void init(Stack *s, int size){
    s->data = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return;
}

int  empty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}
int full(Stack *s){
     if(s->top == s->size-1){
        return 1;
    }
    return 0;
}


void  push(Stack *s, int data){
    if(full(s)){
        printf("\nStack is Overflowed\n");
    }else{
        s->data[++s->top] = data;
    }
    return;
}
int pop(Stack *s){
    int temp = 0 ;
    if(empty(s)){
        printf("\nStack is Empty\n");
    }else{
     temp = s->data[s->top];
        s->top--;
        printf("\n%d is poped\n", temp);
    }
    return temp;
}
int  peek(Stack *s){
    if(empty(s)){
        printf("\nStack is Empty\n");

    }
    printf("\nTo of Stack is %d\n", s->data[s->top]);

    return s->data[s->top];

}

void  display(Stack *s){
    for(int i = 0;i<s->size;i++){
        printf("%d\t", s->data[i]);
    }
}

void sort(Stack *s) {
    Stack st;
    init(&st, s->size);  // Initialize a temporary stack with the same size

    // Main sorting loop
    while (!empty(s)) {
        int temp = pop(s);  // Pop the top element from the original stack

        // Move elements from temp stack back to original stack until we find the right place for temp
        while (!empty(&st) && peek(&st) > temp) {
            push(s, pop(&st));  // Move elements from st back to s
        }

        // Push temp into its correct position in the temp stack
        push(&st, temp);
    }

    // Move the sorted elements back to the original stack
    while (!empty(&st)) {
        push(s, pop(&st));
    }
}

