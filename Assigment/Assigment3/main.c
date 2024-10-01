#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    twoStacks  s;
    init(&s,10);
    push1(&s, 5);  
    push2(&s, 10); 
    push1(&s, 15); 
    push2(&s, 20); 
    display1(&s);
    display2(&s);
    printf("Popped element from stack1: %d\n", pop1(&s)); 
    printf("Popped element from stack2: %d\n", pop2(&s)); 

}