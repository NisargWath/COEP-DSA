typedef struct Array{
    int * data;
    int size;
    int len;
}Array;

void init(Array * a, int size);
void  append(Array * a, int data);
void  insert_at_index(Array * a, int ind,int value);
void remove_at_index(Array *a, int ind);
void  display(Array * a);
int max(Array * a); 
int  min (Array *a);
void  reverse(Array * a) ;
void  merge(Array *a, Array *b);
