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
        printf("\nChoice 1:- apprend 2:- Display \n3:- Insert At Index 4:- Remove From Index  \n5:-Max Element 6:- Min element \n7:-reverse 8:-Merge Two array Array\t");
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
            printf("\nEnter the value and index to append: ");
        int value1, ind;
        scanf("%d%d", &value1, &ind);
        
        // Call the insert_at_index function
        insert_at_index(&a, ind, value1);
        break;
         case 4:
            printf("\nEnter the  index to Delete:-\t");
            int  ind1;
            scanf(" %d",  &ind1);
            remove_at_index(&a,ind1);
            break;
        case 5:
            printf("\nMax element in array :- %d", maxele(&a));
        break;
        case 6:
            printf("\nMax element in array :- %d", minele(&a));
        break;
        case 7: 
                printf("\nlist:-");
                display(&a);
                reverse(&a);
                printf("\nReverse list:-");
                display(&a);
        break;

        case 8:
            printf("Before Merging Array ");

            display(&a);
            printf("Merged Array ");
            merge(&a, &a);
            display(&a);

        break;
        
        default:
            printf("\nWrong Choice");
            break;
        }

        printf("\nEnter 0 to Exit");
        scanf("%d", &ch);
    }while(ch != 0);
}