typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct List{
    Node * head;
    Node * tail;
}List;

void init(List *l);
int isEmpty(List * l);
void display(List *l);
void insert_from_front(List *l, int data);
int find_length(List * l);
void reverse_display(List * l);
void insert_using_rear_end(List *l, int data);