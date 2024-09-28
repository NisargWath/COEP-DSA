typedef struct Node{
    int data;
    struct Node * next; 
}Node;

typedef struct Stack{
    Node * head;
}Stack;

void init(Stack * s);
int isempty(Stack * s);
void push(Stack *s, int data);
int pop(Stack * s);
int peek(Stack * s);
void display(Stack *s);