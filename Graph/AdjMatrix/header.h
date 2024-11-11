typedef struct  Graph
{
  int  numVertices;
  int **adjMatric;
} Graph;

void init(Graph * gp, int vertices);
void addEdge(Graph * gp, int src, int dest);
void remoeveEdge(Graph * gp, int src, int dest);
void displayGraph(Graph * gp);
void freegraph(Graph * gp);

