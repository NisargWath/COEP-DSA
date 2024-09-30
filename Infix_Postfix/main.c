#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    char infix[100] = "(A+B)/C-D^E*F";
    char postfix[100]; 
    infixToPostfix(infix,postfix);
    printf("Post Expression %s\n", postfix);
    return 0;
}