#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include <string.h>

void initBST(BST *tree) {
    tree->root = NULL;
}

TreeNode* createNode(char *month) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->month, month);
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}


void insertNode(BST *tree, char *month) {
    TreeNode *newNode = createNode(month);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    TreeNode *current = tree->root;
    TreeNode *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (strcmp(month, current->month) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (strcmp(month, parent->month) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

TreeNode* findMin(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


void removeNode(BST *tree, char *month) {
    TreeNode *current = tree->root;
    TreeNode *parent = NULL;


    while (current != NULL && strcmp(current->month, month) != 0) {
        parent = current;
        if (strcmp(month, current->month) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Node with month %s not found.\n", month);
        return;
    }


    TreeNode *child;
    if (current->left == NULL || current->right == NULL) {
        child = current->left ? current->left : current->right;
        

        if (parent == NULL) {
            tree->root = child;
        }

        else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        
        if (child != NULL) {
            child->parent = parent;
        }
        free(current);
    }

    else {
        TreeNode *successor = findMin(current->right);
        strcpy(current->month, successor->month);  
        removeNode(tree, successor->month);         
    }

    printf("Node with month %s removed.\n", month);
}


void traverse(BST *tree) {
    if (tree->root == NULL) return;

    TreeNode *current = tree->root;
    TreeNode *stack[100];  
    int top = -1;

    while (current != NULL || top != -1) {

        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }


        current = stack[top--];
        printf("%s ", current->month);  


        current = current->right;
    }
}


void destroyTree(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    destroyTree(node->left);
    destroyTree(node->right);
    free(node);
}
void destroyBST(BST *tree) {
    destroyTree(tree->root);
    tree->root = NULL;
    printf("Tree destroyed.\n");
}