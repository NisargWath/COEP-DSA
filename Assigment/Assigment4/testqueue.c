#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structure for queue elements
typedef struct data {
    char name[16];
    unsigned int age;
} data;

// Define node structure for each element in the queue
typedef struct Node {
    data d;
    struct Node *next;
} Node;

// Define queue structure with head and tail pointers
typedef struct queue {
    Node *head;
    Node *tail;
} queue;

// Initialize the queue
void qinit(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Check if the queue is full (always returns 0 for linked list)
int qfull(queue *q) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        return 1;  // Memory allocation failed, so queue is "full"
    } else {
        free(temp);
        return 0;  // Memory allocation succeeded, queue is not full
    }
}

// Check if the queue is empty
int qempty(queue *q) {
    return q->head == NULL;
}

// Enqueue (add) an element to the queue
void enq(queue *q, data d1) {
    if (qfull(q)) {
        printf("Queue is full\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->d = d1;
    newNode->next = q->head;  // New node points to head (for circular link)

    if (q->head == NULL) {
        // If queue is empty, initialize head and tail
        q->head = newNode;
        q->tail = newNode;
        q->tail->next = q->head;  // Complete circular connection
    } else {
        q->tail->next = newNode;  // Tail points to new node
        q->tail = newNode;        // Update tail to new node
        q->tail->next = q->head;  // Maintain circular link
    }
}

// Dequeue (remove) an element from the queue
data deq(queue *q) {
    data d = {"", 0};  // Initialize to avoid returning uninitialized data
    if (qempty(q)) {
        printf("Queue is empty\n");
        return d;
    }

    Node *temp = q->head;
    d = temp->d;

    if (q->head == q->tail) {
        // Only one element in the queue
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;    // Move head to the next node
        q->tail->next = q->head;    // Maintain circular link
    }

    free(temp);  // Free the dequeued node
    return d;
}

// Main function
int main() {
    queue q;
    data d;

    qinit(&q);
    printf("Enter the name and age (e.g., Alice 25). Type EOF (Ctrl+D) to stop:\n");

    // Input loop for adding elements to the queue
    while (scanf("%s %u", d.name, &(d.age)) != EOF) {
        if (!qfull(&q)) {
            enq(&q, d);
        }
    }

    // Output loop for dequeuing and displaying elements from the queue
    printf("\nQueue contents:\n");
    while (!qempty(&q)) {
        d = deq(&q);
        printf("%s %u\n", d.name, d.age);
    }

    return 0;
}
