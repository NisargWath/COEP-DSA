typedef struct Stack{
    char * data;
    int size;
    int top;
}Stack;

void init(Stack *s, int size);
void push(Stack *s, char ch);
char pop(Stack * s);
char peek(Stack * s);
int precedence(char op);
void infixToPostfix(char infix[], char postfix[]);


