typedef struct data {

    char name[16];
    unsigned int age;

}data;

typedef struct Node{
    data d;
    struct Node * next;
}Node;
typedef struct queue{
    Node * head;
    Node * tail;
} queue;


void qinit(queue * q);
void  enq(queue * q, data d1);
data deq(queue * q);
int  qfull(queue * q);
int qempty(queue * q);