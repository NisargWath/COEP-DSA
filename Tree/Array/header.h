typedef struct Node{
    int * data;
    int size ;
    int len ;
}Node;

void init(Node * tr, int size);
tr
void insertNode(Node * tr, int data);
void removeNode(Node * tr);
void inordertraverse(Node * tr, int n);
void posttraverse(Node * tr, int n);
void pretraverse(Node * tr, int n);
void destroyTree(Node * tr);
