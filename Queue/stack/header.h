typedef struct queue{
    int *data;
    int size;
    int front;
    int rear;
}queue;

void init(queue * q, int size);
int isempty(queue *q);
int isfull(queue * q);
void Enq(queue * q, int data);
int deq(queue * q);
int top(queue *q);
void display(queue *q);
void push(queue *q, int data);  
int pop(queue *q);   