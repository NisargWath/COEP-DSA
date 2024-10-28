#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exe;
    struct Node *next;  // Fixing the type here
} Node;

typedef struct poly {
    Node *head;
} poly;

void init(poly* p) {
    p->head = NULL;
    return;
}

void append(poly *p, int coef, int exe) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exe = exe;
    newNode->next = NULL;
    
    // If the list is empty, make newNode the head of the list
    if (p->head == NULL) {
        p->head = newNode;
        return;
    }

    Node *temp = p->head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void display(poly *p) {
    Node *temp = p->head;  // Start from the head of the list
    while (temp) {  // Traverse the linked list
        printf("(%d)x^%d ", temp->coef, temp->exe);
        temp = temp->next;  // Move to the next node
        if (temp) {
            printf("+ ");
        }
    }
    printf("\n");
}

poly add_poly(poly * a, poly * b){
        poly  re;
        init(&re);
        Node *temp1 = a->head;
        Node *temp2 = b->head;
        while (temp1 && temp2)
        {
            if(temp1->exe == temp2->exe){
                append(&re, temp1->coef + temp2->coef, temp1->exe);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(temp1->exe>temp2->exe){
                append(&re, temp1->coef , temp1->exe);
                temp1 = temp1->next;
            }else{
                append(&re, temp2->coef , temp2->exe);
                temp2 = temp2->next;
            }
        }

        while(temp1){
                append(&re, temp1->coef , temp1->exe);
                temp1 = temp1->next;
        }
        while(temp2){
       append(&re, temp2->coef , temp2->exe);
                temp2 = temp2->next;
        }
        

    return re;

}

int main() {
    poly a, b, sum;
    init(&a);
    init(&b);
    append(&a, 10, 2);
    append(&a, 9, 1);
    append(&b, 1, 2);
    append(&b, 2, 1);
    display(&a);  // Corrected to display the list
    display(&b);  // Corrected to display the list
    sum = add_poly(&a, &b);
    display(&sum);  // Corrected to display the list

    return 0;
}
