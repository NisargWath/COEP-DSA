#include<stdio.h>
#include<stdlib.h>

#include "List.h"

int main(){
    List l ;
    init(&l);
    insert_from_front(&l,10);
    insert_from_front(&l,11);
    insert_from_front(&l,12);
    printf("LinkedList Element :-\t");
    display(&l);
    printf("length = %d \n", find_length(&l));
    printf("LinkedList Element :-\t");
    reverse_display(&l);
    insert_using_rear_end(&l, 1000);
    insert_using_rear_end(&l, 100);
    printf("LinkedList Element :-\t");
    display(&l);
    printf("Element found at index :- %d",search(&l, 11));
}