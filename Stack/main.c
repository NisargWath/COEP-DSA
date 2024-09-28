#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int  main(){
    Stack s;
    int size;

    printf("Welcome to Stack program\nEnter the size of the stack:-\t");
    scanf("%d", &size);
    init(&s,size);
    int ch;
    int np;
    do{
        printf("Enter the numbers\n1)Push\n2Pop\n3)Peek\n4)display\n5)Sort\n:-");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter element");
                int m;
                scanf("%d",&m);
                push(&s,m);
            break;
        
            case 2:
                pop(&s);
            break;
            case 3:
                peek(&s);
            break;
            case 4:
                display(&s);
            break;
            case 5:
                sort(&s);
                display(&s);
            break;
        default:
        printf("!invalid ch");
            break;
        

    }
        printf("\nEnter 0 to exist");
        scanf("%d", &np);
}while(np != 0);
}