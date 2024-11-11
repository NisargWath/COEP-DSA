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
void DFS(Graph * g, int sVertex);


// 
// Stack    for DFS
typedef struct stack
{   
    int * data;
    int size;
    int top;
}Stack;

void initStack(Stack*q, int size);
void push(Stack* q, int data);
int pop(Stack* q);
int isempty(Stack* q);
int isfull(Stack* q);



