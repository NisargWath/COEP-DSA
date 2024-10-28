#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct List{
    Node * head;
    Node * tail;
}List;

void init(List * l){
    l->head = NULL;
    l->tail = NULL;
    return;
}

void append(List *l, int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
        return;
    }
    newNode->prev = l->tail;
    l->tail->next = newNode;
    l->tail = newNode;
    return;
}

void display(List * l){
    Node * temp = l->head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

 void insertAtBeginning(List *l, int data){
    Node * newNode  = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
        return;
    }
    newNode->next = l->head;
    l->head->prev  = newNode;
    l->head = newNode;
}


void insertAtIndex(List *l, int data, int ind) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // Case: Inserting at the head (index 0)
    if (ind == 0) {
        newNode->next = l->head;
        if (l->head != NULL) {
            l->head->prev = newNode;
        }
        l->head = newNode;
        
        // If the list was empty, set tail to the new node as well
        if (l->tail == NULL) {
            l->tail = newNode;
        }
        return;
    }

    Node *temp = l->head;
    int i = 0;
    
    // Traverse to the (ind - 1)th position
    while (temp != NULL && i < ind - 1) {
        temp = temp->next;
        i++;
    }
    
    // If we've reached the end or invalid index, do nothing
    if (temp == NULL) {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    // Insert in the middle or at the end
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        // If inserting at the end, update the tail pointer
        l->tail = newNode;
    }

    temp->next = newNode;
}

 void  removeEnd(List *l){
     
     if(l->head == NULL ) return;
     
     
     if(l->head == l->tail){
         l->head = NULL;
         l->tail = NULL;
         return;
     }
     Node * temp = l->tail;
     l->tail = l->tail->prev;
     l->tail->next = NULL;
     free(temp);
 }
 
void removeBeginning(List *l){
    if(l->head == NULL) return;
    
    if(l->head == l->tail){
        l->head =NULL;
        l->tail = NULL;
        return;
    }
    Node * temp = l->head;
    l->head = l->head->next;
    l->head->prev = NULL;
    free(temp);
}

void  removeAtIndex(List *l, int ind){
     if(l->head == NULL) return;
     
     if(l->head == l->tail){
         l->head = NULL;
         l->tail =NULL;
         return;
         }
        if(ind == 0){
            Node * del = l->head;
            l->head = l->head->next;
            l->head->prev = NULL;
            free(del);
            return;
        }
        if(l->tail == NULL){
            Node * del = l->tail;
            l->tail = l->tail->prev;
            l->tail->next = NULL;
            free(del);
        }
        int i = 0;
        Node * temp = l->head;
        while(temp && i < ind){
            temp = temp->next;
            i++;
        }
            if (temp == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

            if(l->tail == NULL){
            Node * del = l->tail;
            l->tail = l->tail->prev;
            l->tail->next = NULL;
            free(del);
        }
        
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
        
        
 }
 
 void destroy(List *l){
     Node * cur =  l->head;
     Node * temp ;
     
     while(cur){
         temp = cur->next;
         free(cur);
         cur = temp;
     }
     l->head = NULL;
       
 }
 
void initASCII(List *l, char a) {
    int n = (int)a;   // Get ASCII value of character
    append(l, n);     // Append the ASCII value to the list
}

void fill(List *l, int numberOfNodes){
    if (numberOfNodes < 1) return;

    for (int i = 0; i < numberOfNodes; i++)
    {
        append(l, abs(rand() % 201 - 100));
    }

    return;    
}

void reverse(List *l) {
    Node *current = l->head;
    Node *temp = NULL;

    // Swap next and prev pointers for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Swap the head and tail pointers
    if (temp != NULL) {
        l->head = temp->prev;
    }
}


int main(){
    List  l;
    init(&l);
    append(&l,10);
    append(&l,11);
    append(&l,12);
    insertAtBeginning(&l,1000);
    display(&l);
    // insertAtIndex(&l,18,1);
    initASCII(&l, 'A');
    
    reverse(&l);
    // destroy(&l);
    display(&l);
    
}