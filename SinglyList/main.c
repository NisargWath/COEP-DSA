#include<stdio.h>
#include<stdlib.h>
#include "List.h"


int main(){
    // list 1
    link *  head =  init() ;
    
    append(head,10);
    append(head,11);
    append(head,12);
    append(head,13);
    display(head);
    int n = findlength(head);
    int m = search(head, 11);
    printf("Length of List :- %d\n", n);
    printf("Element searched is  on index :- %d\n", m);
    // remove_end(head);
    // display(head);
    // remove_index(head, 0);
    // display(head);
    insert_Index(head,3,69);
    display(head);

    printf("\nList 2\n");
        // list 1
    link *  head1 =  init() ;
    
    append(head1,1);
    append(head1,11);
    append(head1,2);
    append(head1,3);
    display(head1);
    mergeTwoLists(head, head1);
    display(head);



}