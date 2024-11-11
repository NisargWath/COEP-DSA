#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int *data;
    int size;
    int len;
} tree;

void init(tree *t, int size) {
    t->data = (int *)malloc(sizeof(int) * size);
    t->size = size;
    t->len = 0;
    for (int i = 0; i < size; i++) {
        t->data[i] = -1;
    }
}

void insertNode(tree *tr, int data) {
    if (tr->len >= tr->size) {
        printf("Tree is full\n");
        return;
    }

    int i = 0;
    while (i < tr->size && tr->data[i] != -1) {
        if (data < tr->data[i]) {
            i = 2 * i + 1;
        } else {
            i = 2 * i + 2;
        }
    }

    if (i < tr->size) {
        tr->data[i] = data;
        tr->len++;
    } else {
        printf("Tree is full, cannot insert %d\n", data);
    }
}

void inordertraverse(tree *tr, int i) {
    if (i >= tr->size || tr->data[i] == -1) return;
    inordertraverse(tr, 2 * i + 1);
    printf("%d ", tr->data[i]);
    inordertraverse(tr, 2 * i + 2);
}

void preordertraverse(tree *tr, int i) {
    if (i >= tr->size || tr->data[i] == -1) return;
    printf("%d ", tr->data[i]);
    preordertraverse(tr, 2 * i + 1);
    preordertraverse(tr, 2 * i + 2);
}

void postordertraverse(tree *tr, int i) {
    if (i >= tr->size || tr->data[i] == -1) return;
    postordertraverse(tr, 2 * i + 1);
    postordertraverse(tr, 2 * i + 2);
    printf("%d ", tr->data[i]);
}
int count_nodes(tree* root,int i) {
    if (root == NULL) return 0;
    return 1 + count_nodes(root , 2*2+1) + count_nodes(root,  2*2+1);
}

int count_leaf(tree * tr, int i){
    if(i>=tr->len || tr->data[i] == -1)
        return 0;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    if ((leftChild >= tr->size || tr->data[leftChild] == -1) &&
        (rightChild >= tr->size || tr->data[rightChild] == -1)) {
        return 1;
    }
    
    return count_leaf(tr,2+i+1) + count_leaf(tr,2+i+2);
}

int height_trr(tree * tr, int i){
    if(i>tr->len || tr->data[i] == -1)
        return 0 ;
    int left = height_trr(tr,2*i+1);
    int right = height_trr(tr,2*i+2);
    return 1 + ((left>right) ? left : right);
}

int non_leaf(tree * tr, int i){
    if(i>tr->len || tr->data[i] == -1)
        return 0;
    
    return height_trr(tr,0) - count_leaf(tr,0);
}
void deleteNode(tree *tr, int data){
    int i = 0;
    while(i<tr->size && tr->data[i] != data){
        if(data<tr->data[i]){
            i = 2*i+1;
        }else{
            i=2*i+2;
        }
    }
    if(i>=tr->len && tr->data[i] == -1){
    printf("Node %d not found in the tree.\n", data);
        return;
    }
    
    int lastNode = tr->len-1;
    tr->data[i] = tr->data[lastNode];
    tr->data[lastNode] = -1;
    tr->len--;
    int current =i;
    while(current <tr->len){
        int left = 2* current +1;
        int right = 2* current +2;
        int swap = current;
        if(left<tr->len && tr->data[left] != -1&& tr->data[left] > tr->data[swap]){
            swap = left;
        }
         if(right<tr->len && tr->data[right] != -1&& tr->data[right] > tr->data[swap]){
            swap = right;
        }
        
        if(swap == current){
            break;
        }
        int temp = tr->data[current];
        tr->data[current] = tr->data[swap];
        tr->data[swap] = tr->data[current];
        current =swap;
    }
}

int main() {
    tree t;
    init(&t, 20);

    insertNode(&t, 12);
    insertNode(&t, 10);
    insertNode(&t, 3);
    insertNode(&t, 5);
    insertNode(&t, 6);
    insertNode(&t, 16);
    insertNode(&t, 26);
    insertNode(&t, 1);

    printf("Inorder traversal:\n");
    inordertraverse(&t, 0);
    printf("\n");

    printf("Postorder traversal:\n");
    postordertraverse(&t, 0);
    printf("\n");

    printf("Preorder traversal:\n");
    preordertraverse(&t, 0);
    printf("\n");

    // Deleting a node
    


    printf("Preorder traversal:\n");
    preordertraverse(&t, 0);
    printf("\n");

      // Free allocated memory
    
    printf("\n%d ", non_leaf(&t,0));
     printf("\n%d ", count_nodes(&t,0));
}
