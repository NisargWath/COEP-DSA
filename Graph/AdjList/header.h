typedef struct Node{
    int dest;
    struct Node * next;
}Node;

typedef struct Graph{
    int numVertices;
    Node ** adjList;
    
}Graph;

Node* createNode(int dest);
void initGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);
