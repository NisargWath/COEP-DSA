#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  

typedef struct {
    char *data;
    int size;
    int top;
} Stack;

void init(Stack *s, int size) {
    s->data = (char *)malloc(sizeof(char) * size);
    s->size = size;
    s->top = -1;
}

void push(Stack *st, char ch) {
    if (st->top == st->size - 1) {  
        printf("Stack is full\n");
    } else {
        st->data[++st->top] = ch;  
    }
}

char pop(Stack *st) {
    if (st->top == -1) {  
        printf("Stack is empty\n");
        return '\0'; 
    } 
    return st->data[st->top--];
}

char peek(Stack *st) {
    if (st->top == -1) {  
        return '\0';  // Empty stack
    }
    return st->data[st->top];
}

int c(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, 100);  // Initialize stack with size 100
    
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        // If operand, add to postfix output
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } 
        // If '(' push to stack
        else if (infix[i] == '(') {
            push(s, infix[i]);
        } 
        // If ')', pop until '(' is found
        else if (infix[i] == ')') {
            while (peek(s) != '(' && s->top != -1) {
                postfix[j++] = pop(s);
            }
            pop(s);  // Discard the '('
        } 
        // If operator, pop all operators from stack with higher or equal precedence
        else {
            while (s->top != -1 && precedence(peek(s)) >= precedence(infix[i])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
        i++;
    }
    
    // Pop all remaining operators from the stack
    while (s->top != -1) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';  // Null terminate the postfix string
    
    free(s->data);  // Free dynamically allocated memory for stack
    free(s);        // Free the stack structure
}

