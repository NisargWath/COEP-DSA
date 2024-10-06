typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct ASCII{
 Node * head;
 Node * tail;
}ASCII ;


void init_ASCII(ASCII * l);
void  ASCII_of(ASCII * l, char a);
void  traverse(ASCII * l);
void Destroy(ASCII * l);


