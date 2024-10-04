typedef struct queue{
    int front, rear,size;
    int * data;
}queue;

void qinit(queue * q, int size);
void enq(queue * q, int value);
int  deq(queue * q);
int qfull(queue * q);
int qempty(queue * q);
int peek(queue * q);
void display(queue * q);