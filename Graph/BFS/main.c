#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main() {
    Graph g;
    initGraph(&g, 6);  // Initialize graph with 6 vertices

    // Adding edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);
    
    // Perform BFS traversal starting from vertex 0
    printf("BFS Traversal starting from vertex 0:\n");
    BFS(&g, 0); // Expected output: 0 1 2 3 4 5

    return 0;
}