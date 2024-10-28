typedef struct Stack{
    char * data;
    int size;
    int top;

}Stack;


void init(Stack *s, int size);
void push(Stack * s, char value);
char pop(Stack *s);
int isEmpty(Stack s);



