#include<stdlib.h>
#include<stdio.h>
#include "header.h"


int main(){
    Graph g;
    initGraph(&g, 4);
    addEdge(&g, 0,1);
    addEdge(&g, 0,2);
    addEdge(&g, 1,2);
    addEdge(&g, 2,3);
     displayGraph(&g);

    freeGraph(&g);

}