#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    queue  q;
    init(&q, 5);
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    printf("Queue after pushing elements (acting as stack):\n");
    display(&q);
    
    printf("Popped element: %d\n", pop(&q));
    printf("Queue after popping an element:\n");
    display(&q);





}