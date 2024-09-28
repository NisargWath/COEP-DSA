typedef struct  Stack{
        int * data;
        int top;
        int size;
}Stack;

void init(Stack *s, int size);
void  push(Stack *s, int data);
int  pop(Stack *s);
int  peek(Stack *s);
int empty(Stack *s);
int full(Stack *s);
void  display(Stack *s);
void sort(Stack *s);

