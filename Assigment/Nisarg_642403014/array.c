#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void init(Array * a, int size){
    a->data = (int *)malloc(sizeof(int)*size);
    a->size = size;
    a->len = 0;
}

void  append(Array * a, int data){
    if(a->size-1 < a->len) return;
        a->data[a->len] = data;
        a->len++;

    return;
}


void  insert_at_index(Array * a, int ind,int value){
    if(ind > a->size || ind < 0) return;

        for(int i = 0;i<a->size;i++){
            if(i == ind){
                a->data[i]= value;
                a->len++;
            }
        }
        return;

}
void  remove_at_index(Array *a, int ind){
    for(int i = 0;i<a->size;i++){
            if(i == ind){
                a->data[i] = a->data[i+1];
                break;
            }
        }
        a->len--;
return;
        
}
void  display(Array * a){
    for(int i = 0;i<a->len;i++){
        printf("%d ", a->data[i]);
    }
    printf("\n");
}
int min(Array * a){
    int minmum = a->data[0];
    for(int  i = 0;i<a->len;i++){
        if(a->data[i]  <= minmum ){
            minmum  =a->data[i];
        }
    }
    return minmum ;
}
int max(Array *a){
    int maxmium  = a->data[0];
    for(int  i = 0;i<a->len;i++){
        if(a->data[i]  > maxmium ){
            maxmium  =a->data[i];
        }
    }
    return maxmium ;
}

void  reverse(Array * a){
   int l = 0, h = a->len-1;

   while(l<h){
        int temp = a->data[l];
        a->data[l] = a->data[h];
        a->data[h] =temp;
        l++;
        h--;
   }
   printf("\n");
}
// 
void  merge(Array *a, Array *b){
    a->size = a->size+b->size;
    for(int i = 0;i<b->len;i++){
        append(a,b->data[i]);
    }
    return;
}