#include<stdio.h>
#include<stdlib.h>
#include "queue.h"


int main(){
    queue q;
    

    int size;

    printf("Welcome to Queue program\nEnter the size of the stack:-\t");
    scanf("%d", &size);
    qinit(&q,size);
    int ch;
    int np;
    do{
        printf("Enter the numbers\n1)Enqueue\n2Dequeue\n3)Peek\n4)display\n:-");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter element");
                int m;
                scanf("%d",&m);
                enq(&q,m);
            break;
        
            case 2:
                deq(&q);
            break;
            case 3:
                printf("Peek of queue is %d\n", peek(&q));
            break;
            case 4:
                display(&q);
            break;
        default:
        printf("!invalid ch");
            break;
        

    }
        printf("\nEnter 0 to exist");
        scanf("%d", &np);
}while(np != 0);
}