typedef struct Node{
    int data;
    struct Node * left, *right;
}Node;

typedef struct Tree{
    Node * root;
}Tree;


void initBst(Tree * tr);
Node * generateNode(int data);

// traversal with recurssion 
void preorderTraversal(Node *tr);
void inorderTraversal(Node *tr);
void postorderTraversal(Node *tr);

// traversal with recurssion 
void preo(Node *tr);
void in(Node *tr);
void post(Node *tr);

int count(Node * tr); // This counts the number of nodes in the tree...

void insert(Tree *tr, int data);
int search(Tree * tr, int data);
void delete(Tree *t, int data);
