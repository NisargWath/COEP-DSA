#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    Stack s ;
    init(&s);
     int ch;
    int np;
    do{
        printf("Enter the numbers\n1)Push\n2Pop\n3)Peek\n4)display\n:-");
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
               printf("\nElement popes if %d\n", pop(&s));
            break;
            case 3:
               printf("\nElement at to of stack is %d\n", peek(&s));    
            break;
            case 4:
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