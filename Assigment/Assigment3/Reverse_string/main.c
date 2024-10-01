#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include<string.h>

int main(){
    char str[] ="Data Structures";
    Stack s;
    init(&s,100);
    int n = strlen(str);
    for(int i = 0;i<n;i++){
        push(&s, str[i]);
    }
    for(int i = 0;i<n;i++){
        str[i] = pop(&s); 
    }
      printf("%s", str);

}