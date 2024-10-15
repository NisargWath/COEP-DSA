#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef Node * list;

void init(list * head){
    *head = NULL;
    return;
}

void append(list * head, int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void display(list  head){
    Node * temp  = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatBeg(list * head,int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
    return;
    
}

void insertIndex(list * head , int ind, int value){
    Node * newNode  = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    

    if(ind  == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node * temp = *head;
    int i = 0;
    while(temp !=NULL && i < ind-1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
   printf("Index out of bounds\n");
        free(newNode); 
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void removehead(list * head){
    if(* head == NULL) return;
    Node * newNode = *head;
    *head = (*head)->next;
    free(newNode);
    return;
}
void removeEnd(list * head){
    if(*head == NULL) return;
    Node * temp = *head;
    while(temp->next->next){
        temp = temp->next;
    }
    Node * del = temp->next->next;
    temp->next = NULL;
    free(del);
}

void removeInd(list * head, int ind){
    if(*head == NULL) return;
    
    if(ind == 0){
        Node * newNode = *head;
        *head = (*head)->next;
        return;
    }
    int i = 0;
    Node * temp = *head;
    while(temp->next->next && i<ind-1){
        temp = temp->next;
        i++;
    }
    Node * del = temp->next;
    temp->next = temp->next->next;
    free(del);
    
}


void removeElem(list * head, int elem){
    if(*head == NULL) return;
    
    if((*head)->data == elem){
        Node * newNode = *head;
        *head = (*head)->next;
        return;
    }
    int i = 0;
    Node * temp = *head;
    while(temp->next->next && temp->data == elem){
        temp = temp->next;
        i++;
    }
    Node * del = temp->next;
    temp->next = temp->next->next;
    free(del);
    
}


void  findLength(list * head){
    int i = 0;
    Node * temp = *head;
    while(temp){
        temp = temp->next;
        i++;
    }
    printf("\nLength of LinkedInlist %d", i);
}


void deleteList(list *l){
    Node *current = *l;
    Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *l = NULL;
}


void palindrome(list * head){
    if(*head == NULL){
        printf("Empty list!!");
    }
    Node * temp = *head;
    int len = 0;
    while(temp){
        len++;
        temp= temp->next;
    }
    
    int * a = (int *)malloc(len * sizeof(int));
    
    temp = *head;
    int i = 0;
    while(temp){
        a[i] = temp->data;
        temp = temp->next;
        i++;
    }
    
    temp = *head;
    int j = len-1;
    int flag = 0;
    while(temp){
        if(temp->data != a[j]){flag = 1;
            printf("It is not a Palindrome\n");
            break;
        }
        j--;
        temp = temp->next;
    }
    if(flag == 0)
{
    printf("It is a Palindrome\n");
    return;
}}


int main(){
    list l;
    init(&l);
    append(&l,1);
    append(&l,21);
    append(&l,2);
    append(&l,2);
    append(&l,1);
    // insertatBeg(&l,12);
    // insertIndex(&l,3,2);

    display(l);
    palindrome(&l);
    // removeElem(&l, 11);
    // display(l);
    // deleteList(&l);
    // display(l);
    
}