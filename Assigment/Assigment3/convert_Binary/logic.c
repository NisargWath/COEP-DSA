#include <stdio.h>
#include <stdlib.h>
#include "header.h"



int isEmpty(Stack s){
    if(s.top == -1) return TRUE;

    return FALSE;
}


void init(Stack *s, int size) {
    s->data = (char *)malloc(size * sizeof(char));  // Allocate memory for 'size' characters
    s->top = -1;
    s->size = size;
}


void push(Stack *s, char value) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow!!\n");
        return;
    }
    s->data[++(s->top)] = value;
}


char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is Empty!\n");
        return '\0';
    }
    return s->data[s->top--];
}


char peek(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->data[s->top];
}



