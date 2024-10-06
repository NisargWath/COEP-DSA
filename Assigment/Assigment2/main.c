#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main(){
    ASCII L1;
 init_ASCII(&L1);
 ASCII_of(&L1, 'A');
 traverse(&L1);
 Destroy(&L1);
 traverse(&L1);
return 0;
}