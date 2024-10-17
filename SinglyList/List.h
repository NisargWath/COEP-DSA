typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct link{
    Node * head;
}link;



void  init(link * l);
void append(link * l, int data);
void display(link *l);
int findlength(link *l);
int search(link  * l, int key);
void insert_Index(link * l, int ind, int value);
void remove_head(link * l);
void remove_end(link * l);
void remove_index(link * l,int ind);
link * mergeTwoLists(link *list1, link *list2);



