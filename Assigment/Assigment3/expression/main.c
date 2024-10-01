#include <stdio.h>
#include <stdlib.h>
#include "header.h"




int main() {
    char expression[] =  "[()]{}{[()()]()}";
    
    if (check(expression)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
