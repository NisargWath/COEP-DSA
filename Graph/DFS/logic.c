#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void initGraph(Graph *gp, int vertices) {
    gp->verticesNum = vertices;
    gp->adjList = (Node **)malloc(sizeof(Node *) * vertices);
    if (gp->adjList == NULL) {
        printf("Memory allocation failed for adjList.\n");
        exit(1);
    }
    for (int i = 0; i < vertices; i++) {
        gp->adjList[i] = NULL;
    }
}

Node* createNode(int dest) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for newNode.\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph *gp, int s, int d) {



    Node* newNode = createNode(d);
    newNode->next = gp->adjList[s];
    gp->adjList[s] = newNode;


    newNode = createNode(s);
    newNode->next = gp->adjList[d];
    gp->adjList[d] = newNode;
}

// Stack for DFS


void initStack(Stack * st, int size){
    st->data = (int *)malloc(size * sizeof(int));
    st->size =size;
    st->top = -1;
}
int isempty(Stack* st){
    return st->top == -1;
}
int isfull(Stack* st){
    return st->top ==  st->size-1;
}
void push(Stack* st, int data){
    if(isfull(st)){
        return;
    }
    st->data[++st->top] = data;
}
int pop(Stack* st){
    if(isempty(st)){
        return -1;
    }
    return st->data[st->top--];
}


void DFS(Graph * gp, int sVertex){
    Stack s;
    int i, k;
    initStack(&s, gp->verticesNum);
    int *visisted = (int *)calloc(gp->verticesNum,sizeof(int));
    visisted[sVertex] = 1;
    push(&s,sVertex);
    printf("%d ", sVertex);
    while (!isempty(&s))
    {    k = pop(&s);
        if(visisted[k] == 0){
            visisted[k] = 1;
            printf("%d ", k);
        }
        Node * p = gp->adjList[k];
        while(p){
            i = p->dest;
            if(visisted[i] == 0){
                push(&s, i);
            }
            p = p->next;
        }
    }
    
}