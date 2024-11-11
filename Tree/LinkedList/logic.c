#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void initBst(Tree * tr){
    tr->root =NULL;
    return;
}
Node * generateNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right =NULL;
    return newNode;
}

// traversal
void preorderTraversal(Node * tr){

    if(tr == NULL) return;


    printf("%d ", tr->data);
    preorderTraversal(tr->left);
    preorderTraversal(tr->right);
}
void inorderTraversal(Node *tr){
     if(tr == NULL) return;

    inorderTraversal(tr->left);
    printf("%d ", tr->data);
   inorderTraversal(tr->right);
}
void postorderTraversal(Node *tr){
     if(tr == NULL) return;

    postorderTraversal(tr->left);
   postorderTraversal(tr->right);
    printf("%d ", tr->data);
}
int count(Node  * tr){
    int c = 0;

        c++;
       count(tr->left);
      count(tr->right);
        return c;
}

void insert(Tree *tr, int data){
    if(tr->root == NULL){
        tr->root = generateNode(data);
        return;
    }
    Node * temp = tr->root, * q;

    while(temp){
        q= temp;
        if(temp->data >data){
           temp =  temp->left;
        }else if(temp->data < data){
            temp =temp->right;
        }else{
            printf("Data is present in the tree !!\n");
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
int search(Tree * tr, int data){
    Node * temp= tr->root;
    if(temp == NULL) return 0;
    if(temp->data == data) return 1;

    while(temp){
        if(temp->data == data) return 1;
        else if(temp->data > data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return 0;t
}

void delete(Tree *t, int data) {
    Node *temp1 = t->root;
    Node *temp2 = NULL;
    if (temp1 == NULL) return;

    char direction;

    // Search for the node to delete
    while (temp1 && temp1->data != data) {
        temp2 = temp1;
        if (temp1->data > data) {
            temp1 = temp1->left;
            direction = 'l';
        } else {
            temp1 = temp1->right;
            direction = 'r';
        }
    }

    // Node not found
    if (!temp1) return;

    // Case 1: Node with no children (leaf node)
    if (temp1->left == NULL && temp1->right == NULL) {
        if (!temp2) {
            t->root = NULL;
        } else if (direction == 'l') {
            temp2->left = NULL;
        } else {
            temp2->right = NULL;
        }
        free(temp1);
        printf("Node deleted successfully.\n");
        return;
    }

    // Case 2: Node with only one child
    if (temp1->left == NULL || temp1->right == NULL) {
        Node *child = (temp1->left) ? temp1->left : temp1->right;

        if (!temp2) {
            t->root = child;
        } else if (direction == 'l') {
            temp2->left = child;
        } else {
            temp2->right = child;
        }
        free(temp1);
        printf("Node deleted successfully.\n");
        return;
    }

    // Case 3: Node with two children
    // Find the in-order successor (smallest in right subtree)
    Node *successorParent = temp1;
    Node *successor = temp1->right;
    while (successor->left) {
        successorParent = successor;
        successor = successor->left;
    }

    // Copy the successor's data to temp1
    temp1->data = successor->data;

    // Adjust the parent's pointer
    if (successorParent->left == successor) {
        successorParent->left = successor->right;
    } else {
        successorParent->right = successor->right;
    }
    free(successor);

    printf("Node deleted successfully.\n");
}



// without recurssion 
void preo(Node *tr){
    if(tr == NULL) return;
    Node * stack[100];
    int top=-1;
    stack[++top] = tr;
    while(top>=0){
        Node * cur = stack[top--];
         printf("%d ", cur->data);
         if(cur->right){
            stack[++top] = cur->right;
         }
         if(cur->left){
            stack[++top] = cur->left;
         }
    }
}


void in(Node * tr){
    if(tr == NULL) return;
    Node * stack[100];
    int top =-1;
     Node *cur = tr;
    while(cur!= NULL || top>=0){
    
    while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur= stack[top--];
        printf("%d ", cur->data);
            cur = cur->right;

    }

}
void post(Node *root) {
    if (root == NULL) return;

    // Stacks for holding nodes
    Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    // Traverse the tree
    while (top1 >= 0) {
        Node *current = stack1[top1--];
        stack2[++top2] = current;

        // Push left and right children to stack1
        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }
    // Print all elements from stack2
    while (top2 >= 0) {
        Node *node = stack2[top2--];
        printf("%d ", node->data);
    }
}




// recursive  Delete
Node * findHelper(Node * root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node * recurHelper(Node * root, int data){
    if(root == NULL) return root;

    if(data<root->data){
        root->left = recurHelper(root->left,data);
    }
    else if(data>root->data){
        root->right = recurHelper(root->right,data);
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

        Node * temp = findHelper(root->right);
        root->data = temp->data;
        root->right = recurHelper(root->right, temp->data);
    }
    return root;
}

void recursiveDelete(Tree * tr,int data){
    tr->root = recurHelper(tr->root,data);
}
