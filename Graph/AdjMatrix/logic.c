#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Graph * gp, int vertices){
    gp->numVertices = vertices;
    gp->adjMatric = (int **)malloc(sizeof(int *)* vertices);
    for(int  i = 0; i<vertices;i++){
        gp->adjMatric[i] = (int *)malloc(sizeof(int) * vertices);
        for(int j = 0;j<vertices;j++){
            gp->adjMatric[i][j] = 0;
        }
    }

}
void addEdge(Graph * gp, int src, int dest){
    gp->adjMatric[src][dest] = 1;
    gp->adjMatric[dest][src] = 1;

}
void remoeveEdge(Graph * gp, int src, int dest){
    gp->adjMatric[src][dest] = 0;
    gp->adjMatric[dest][src] = 0;

}
void displayGraph(Graph * gp){
    printf("Adjacency Matrix:\n");
for(int i = 0;i<gp->numVertices;i++){
    for(int j = 0;j<gp->numVertices;j++){
        printf("%d ", gp->adjMatric[i][j]);
    }
    printf("\n");
}
}
void freegraph(Graph * gp){
for(int i = 0;i<gp->numVertices;i++){
    free(gp->adjMatric[i]);
}
free(gp->adjMatric);
}