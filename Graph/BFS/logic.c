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

void initQueue(queue *q, int size) {
    q->data = (int *)malloc(sizeof(int) * size);
    if (q->data == NULL) {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
    q->size = size;
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q) {
    return q->rear == -1;
}

int isfull(queue *q) {
    return q->rear == q->size - 1;
}

void enqueue(queue *q, int data) {
    if (isfull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = data;
}

int dequeue(queue *q) {
    if (isempty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int data = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

void BFS(Graph *g, int sVertex) {
    int k, i;
    queue q;
    initQueue(&q, g->verticesNum);
    int *isvisited = (int *)calloc(g->verticesNum, sizeof(int));
    isvisited[sVertex] = 1;
    enqueue(&q, sVertex);
    printf("%d ", sVertex);

    while (!isempty(&q)) {
        k = dequeue(&q);
        Node *p = g->adjList[k];
        while (p) {
            i = p->dest;
            if (!isvisited[i]) {
                printf("%d ", i);
                enqueue(&q, i);
                isvisited[i] = 1;
            }
            p = p->next;
        }
    }
    free(isvisited);
}
