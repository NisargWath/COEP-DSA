typedef struct Node{
    int * data;
    int size ;
    int len ;
}Node;

void init(Node * tr, int size);

void insertNode(Node * tr, int data);
void removeNode(Node * tr);
void inordertraverse(Node * tr, int n);
void posttraverse(Node * tr, int n);
void pretraverse(Node * tr, int n);
void destroyTree(Node * tr);
int count_leaf(Node * tr, int i); 
int count_nonleaf(Node * tr);
int height(Node * tr,int i);
