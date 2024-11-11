typedef struct Node{
    int dest;
    struct Node * next;
}Node;

typedef struct Graph{
    int verticesNum;
    Node ** adjList;
}Graph;

void initGraph(Graph * gp, int vertices);
void addEdge(Graph *g,int s,int d);
Node * createNode(int dest);
void display(Graph * gp);
void BFS(Graph * g, int sVertex);


// 
// Queue   for BFS
typedef struct queue
{   
    int * data;
    int size;
    int front, rear;
}queue;

void initQueue(queue *q, int size);
void enqueue(queue * q, int data);
int dequeue(queue * q);
int isempty(queue * q);
int isfull(queue * q);



