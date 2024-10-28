#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    Tree tr;
    initBst(&tr);
    int a[15] = {12,2,1,5,4,3};
    for(int i = 0;i<6;i++){
        insert(&tr,a[i]);
    }
    printf("preorderTraversal :- ");
    preorderTraversal(tr.root);
    printf("\n");
    preo(tr.root);
    printf("\n");

    // delete(&tr, 3);
    inorderTraversal(tr.root);
    printf("\n");
    in(tr.root);




}