#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    Array a;
    int size;
    printf("\nEnter the Size of the Array:\t");
    scanf("%d", &size);
    init(&a, size);
    int choice , r;
    do
    {
       printf("Enter 1)Append 2)Insert At Index \n3)Remove At Index 4)Display \n5)Max 5)Min \n7)Reverse the list 8)Merge the list");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
           append(&a, rand());
        break;
       case 2:
       printf("\nEnter index and value to append:-\t");
       int ind, val;
       scanf("%d %d", &ind, &val);
            insert_at_index(&a, ind, val);
        break;

        case 3:
            printf("\nEnter index to delete:-\t");
            int in;
       scanf("%d", &in);

            remove_at_index(&a, in);
        break;

        case 4:
            printf("List :-\t");
            display(&a);
        break;
        case 5:
            printf("max element is :-\t");
          printf("\n%d \n", max(&a));
        break;
         case 6:
            printf("minimum element is :-\t");
            printf("\n%d \n", min(&a));

        break;
         case 7:
            printf("Before Reverse list is :-\t");
            display(&a);
            printf("After Reverse list is :-\t");
            reverse(&a);
            display(&a);

        break;
        break;
         case 8:
            printf("before Merging list is :-\t");
            display(&a);
            printf("After Merging list is :-\t");
            merge(&a,&a);
            display(&a);

        break;

       
       default:
       printf("Invalid!!");
        break;
       }
        printf("Enter 0  to exit !!");
        scanf("%d",&r);

    } while (r != 0);
    


    return 0;
}