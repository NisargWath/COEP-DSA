// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * left, *right;
} Node;

typedef struct Tree{
    Node * root;
}Tree;

void init(Tree * tr){
    tr->root = NULL;
    return;
}

Node * generateNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Tree * tr, int data){
    if(tr->root == NULL){
        tr->root = generateNode(data);
        return;
    }
    Node * temp = tr->root;
    Node * q;
    while(temp){
        q= temp;
        if(temp->data> data){
            temp = temp->left;
        }else if(temp->data < data){
            temp = temp->right;
        }else{
            printf("Data is present int the List");
            return;
        }
    }
    
    if(data > q->data){
        q->right = generateNode(data);
    }else{
        q->left = generateNode(data);
    }
    return;
}

Node * findmin(Node * root){
    while(root->left != NULL){
        root= root->left;
    }
    return root;
}

Node * deleteNodeHelper(Node * root, int data){
    if(root == NULL) return root;
    if(data<root->data){
        root->left = deleteNodeHelper(root->left,data);
    }
    else if (data>root->data){
        root->right = deleteNodeHelper(root->right,data);
    }else{
        if(root->left == NULL){
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node * temp = root->left;
            free(root);
            return temp;
        }
        
        Node * temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNodeHelper(root->right,temp->data);
    }
    return root;
    
}

void deleteNode(Tree * tr, int data){
    
    tr->root = deleteNodeHelper(tr->root, data);
    
    
}


void preorderTraversal(Node * tr){
    if(tr == NULL) return;
    printf("%d ", tr->data);
    preorderTraversal(tr->left);
    preorderTraversal(tr->right);
}
void inorderTraversal(Node * tr){
    if(tr == NULL) return;

    preorderTraversal(tr->left);
        printf("%d ", tr->data);
    preorderTraversal(tr->right);
}
void postorderTraversal(Node * tr){
    if(tr == NULL) return;
    preorderTraversal(tr->left);
    preorderTraversal(tr->right);
    printf("%d ", tr->data);
}


// non recursive 
void delete(Tree * tr ,int data){
    Node * temp = tr->root;
    Node * q;
    if(temp == NULL) return;
    char dir ;
    while(temp &&temp->data != data){
        q= temp;
        if(temp->data>data){
            temp = temp->left;
            dir = 'l';
        }else{
            temp = temp->right;
            dir = 'r';
            }
    }
    
    if(!temp) return;
    
    // Case1: wiht No Child;
    if(temp->left == NULL && temp->right == NULL){
        if(!temp){
            tr->root = NULL;
        }
        else if(dir == 'l'){
            q->left = NULL;
        }else{
            q->right = NULL;
        }
        free(temp);
        printf("\nDeleted!!");
        return;
    }
    
    // case2: With one child
    if(temp->left == NULL || temp->right == NULL){
        Node *child = (temp->left) ?temp->left : temp->right;
        
        if(!temp){
            tr->root = child;
        }else if(dir == 'l'){
            q->left = child;
        }
        else{
            q->right = child;
        }
        free(temp);
        printf("\nDeleted!!");
        return;
    }
    
    // case3: With two Child;
    Node * sparent = temp;
    Node * s2 = temp->right;
    while(s2->left){
        sparent = s2;
        s2 = s2->left;
    }
    temp->data = s2->data;
    if(sparent->left == s2){
        sparent->left = s2->right;
    }else{
         sparent->right = s2->left;
    }
    free(s2);
    printf("Node deleted successfully.\n");
    
}


void preo(Node * tr){
    if(tr == NULL) return;
    Node * stack[100];
    int top=-1;
    stack[++top] = tr;
    while(top>=0){
        Node *cur = stack[top--];
        printf("%d ",cur->data);
        if(cur->right){
            stack[++top] = cur->right;
        }
        if(cur->left){
            stack[++top] = cur->left;
        }
    }
}

void ineo(Node * tr){
    if(tr == NULL) return;
    Node * stack[100];
    int top=-1;
    Node * cur = tr;
    while(cur || top>=0){
          while(cur){
        stack[++top] = cur;
        cur= cur->left;
        }
        cur= stack[top--];
        printf("%d ", cur->data);
        cur = cur->right;
    }
}


void post(Node * root){
    if(root ==NULL) return;
    
    Node * stack1[100], * stack2[100];
    int top1= -1,top2=-1;
    stack1[++top1] = root;
    while(top1>=0){
        Node * temp = stack1[top1--];
        stack2[++top2] = temp;
        
        if(temp->left) stack1[++top1] = temp->left;
        if(temp->right) stack1[++top1] = temp->right;
    }
    while(top2>=0){
        Node * node=stack2[top2--];
        printf(" %d ", node->data);
    }
}

int count_leaf(Node *tr) {
    if (tr == NULL) return 0; // Base case: empty tree has no leaf nodes

    // Check if the current node is a leaf
    if (tr->left == NULL && tr->right == NULL) {
        return 1;
    }

    // Recurse for left and right subtrees
    return count_leaf(tr->left) + count_leaf(tr->right);
}

int height(Node *tr) {
    if (tr == NULL) return -1;  
    int leftHeight = height(tr->left);
    int rightHeight = height(tr->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}



int main() {
    Tree tr;
    init(&tr);
    insert(&tr, 12);
    insert(&tr, 10);
    insert(&tr, 7);
    insert(&tr, 11);
    insert(&tr, 16);
    insert(&tr, 15);
   
    // preorderTraversal(tr.root);
    // printf("\nPreorder traversal:\n");
    // inorderTraversal(tr.root);
      printf("\nPostorder traversal:\n");
    // postorderTraversal(tr.root);

    
    // delete(&tr,0);
    post(tr.root);
    printf("\n %d ", count_leaf(tr.root));
     printf("\n %d ", height(tr.root));
        printf("\n %d ", height(tr.root) -count_leaf(tr.root));
}




