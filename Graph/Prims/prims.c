#include<stdlib.h>
#include<stdio.h>


typedef struct  Node
{
    int vertices;
    int weight;
    struct Node * next;
} Node;


typedef struct Graph{
    int numVertices;
    Node ** adjlist;
}Graph;

void initGraph(Graph * gp, int vertices){
         gp->numVertices = vertices;
         gp->adjlist = (Node **)malloc(sizeof(Node *) * vertices);
         
         for(int i = 0;i<vertices;i++){
            gp->adjlist[i] =  NULL;
         }
         return;
}

Node * GenrateNode(int vertices, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertices = vertices;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Graph * gp, int src, int dest, int weight){
    Node * newNode = GenrateNode(dest,weight);
    newNode->next = gp->adjlist[src];
    gp->adjlist[src] = newNode;

    newNode = GenrateNode(src, weight);
    newNode->next = gp->adjlist[dest];
    gp->adjlist[dest] = newNode;

    return;
}

void display(Graph * gp){
  for (int i = 0; i < gp->numVertices; i++) {
        Node* temp = gp->adjlist[i];
        printf("\n Vertices: %d ", i);
        while (temp) {
            printf("-> %d (weight: %d)", temp->vertices, temp->weight); // Fixed printing issue
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(Graph * gp, int sVertex){
    int * visited  = calloc(gp->numVertices , sizeof(int));
    for(int i = 0;i<gp->numVertices;i++){
        visited[i] = 0;
    }
    int stack[100];
    int top = -1;
    stack[++top] = sVertex;
    while(top>=0){
        int i = stack[top--];
        if(!visited[i]){
            printf(" %d ", i);
            visited[i] = 1;
        }

        Node * temp = gp->adjlist[i];
        while(temp){
            int adj = temp->vertices;
            if(visited[adj] ==0){
                stack[++top] = adj;
            }
            temp = temp->next;
        }
    }
free(visited);
}
int minKey(int* key, int* visited, int V) {
    int min = INT8_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(Graph* gp) {
    int V = gp->numVertices;
    int parent[V];
    int key[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT8_MAX;
        visited[i] = 0;
    }

    key[0] = 0;       // Start from the first vertex
    parent[0] = -1;   // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited, V); // Pick the minimum key vertex not yet included in MST
        visited[u] = 1;

        Node* temp = gp->adjlist[u];
        while (temp != NULL) {
            int v = temp->vertices;
            int weight = temp->weight;

            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            printf("%d - %d \t%d \n", parent[i], i, key[i]);
        }
    }
}
int main(){
    Graph gp;
    initGraph(&gp, 9);
    insertNode(&gp, 0,1,1);
    insertNode(&gp, 1,2,5);
    insertNode(&gp, 1,7,6);
    insertNode(&gp, 2,8,2);
    insertNode(&gp, 2,3,10);
    insertNode(&gp, 3,4,3);
    insertNode(&gp, 3,5,7);
    insertNode(&gp, 4,5,8);
    insertNode(&gp, 5,6,12);
    insertNode(&gp, 5,8,8);
    insertNode(&gp,7,8,3);
    insertNode(&gp,7,6,7);
    insertNode(&gp, 0,7,6);
    printf("\n");

    // display(&gp);
    DFS(&gp, 0);
    primMST(&gp);



}