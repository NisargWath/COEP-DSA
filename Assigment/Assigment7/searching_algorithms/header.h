typedef struct Array{
    int * data;
    int size;
    int len;
    
}Array;

void init(Array * a, int size);
void append(Array * a, int data);
void display(Array *arr);
void sort(Array * arr);
void Linear_Search(Array * a, int key);
void Binary_Search(Array * a, int key);