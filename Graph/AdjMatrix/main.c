#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
    Graph g;
    init(&g, 4);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 0);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    displayGraph(&g);
    freegraph(&g);
}