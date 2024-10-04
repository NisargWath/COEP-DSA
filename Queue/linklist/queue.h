typedef struct  Node{
    int data;
    int size;
    struct Node *rear;


}Node;

typedef struct queue {
    Node * head  ;
    Node * tail;
}queue;

queue  * qinit();
void enq(queue * q, int value);
int  deq(queue * q);
int qfull(queue * q) ;
int qempty(queue * q);
int peek(queue * q);
void display(queue * q);