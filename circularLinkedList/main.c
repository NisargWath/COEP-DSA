#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    List  l;
    init(&l);
    append(&l, 10);
     append(&l, 11);
      append(&l, 12);
       append(&l, 13);
       display(&l);
       insertAtBeginning(&l,1);
       insertAtBeginning(&l,2);
    
       display(&l);
      printf("\n%d\n" ,removeBeginning(&l));
          display(&l);

        //   display(&l);
        // printf("Length %d ", length(&l));
            del_odd(&l);
          display(&l);

}