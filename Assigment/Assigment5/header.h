typedef struct TreeNode {
    char month[10];
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

typedef struct BST {
    TreeNode *root;
} BST;


void initBST(BST* tr);

void insertNode(BST *tree, char *month);
void removeNode(BST *tree, char *month);
void traverse(BST *tree);

void destroyTree(TreeNode *node);
void destroyBST(BST *tree);
