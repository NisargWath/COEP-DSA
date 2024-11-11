#include<stdio.h>
#include<stdlib.h>
#include "header.h"

Node* createNode(int dest){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->dest =dest;
    newNode->next = NULL;
    return newNode;
}
void initGraph(Graph* gp, int vertices){
    gp->adjList = (Node **)malloc(sizeof(Node *) * vertices);
    gp->numVertices =vertices;

    for(int i = 0;i<vertices;i++){
        gp->adjList[i] = NULL;
    }
}
void addEdge(Graph* gp, int src, int dest){
    Node * newNode = createNode(dest);
    newNode->next  = gp->adjList[src];
    gp->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = gp->adjList[dest];
    gp->adjList[dest] = newNode;
}
void displayGraph(Graph* gp){
    for(int i = 0;i<gp->numVertices;i++){
        Node * temp =gp->adjList[i];
        printf("Vertext %d: ", i);
        while(temp){
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}
void freeGraph(Graph* gp){
    for(int i = 0;i<gp->numVertices;i++){
        Node * temp = gp->adjList[i];
        while(temp){
            Node * ch = temp;
            free(temp);
            temp = ch;
        }
    }
    free(gp->adjList);
}
