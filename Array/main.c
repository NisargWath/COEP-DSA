#include<stdio.h>
#include<stdlib.h>
#include "Array.h"


int main(){
    Array a;
    int size, ch;


    printf("Array ADT Program**\n");
    printf("Enter the size of the Array\t");
    scanf("%d", &size);
    init(&a, size);
    
    do{
        int n ;
        printf("\nChoice 1:- apprend 2:- Display 3:- Insert At Index 4:- Remove From Index \t");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the value to append:-\t");
            int value;
            scanf("%d", &value);
            append(&a, value);
            break;
        case 2:
            printf("\nArray:-\t");
            display(&a);
            break;
         case 3:
            printf("\nEnter the value and index to append:-\t");
            int value1, ind;
            scanf("%d, %d", &value1, &ind);
            insert_at_index(&a,ind, value1);
            break;
         case 4:
            printf("\nEnter the  index to Delete:-\t");
            int  ind1;
            scanf(" %d",  &ind1);
            remove_at_index(&a,ind1);
            break;
   
        
        default:
            printf("\nWrong Choice");
            break;
        }

        printf("\nEnter 0 to Exit");
        scanf("%d", &ch);
    }while(ch != 0);
}