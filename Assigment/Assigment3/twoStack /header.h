typedef struct  twoStacks{
    char *data;
    int size;
    int top1;
    int top2;

} twoStacks;

void init(twoStacks *s, int size);
void push1(twoStacks *s, char value);
int pop1(twoStacks *s);
void push2(twoStacks *s, char value);
int pop2(twoStacks *s);
int peek(twoStacks *s);
void display1(twoStacks *s);
void display2(twoStacks *s);
