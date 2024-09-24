typedef struct Array{
    int * data;
    int size;
    int len;
} Array;


void init(Array *a, int size);
void append(Array *a, int value);
void insert_at_index(Array * a, int ind, int value);
void remove_at_index(Array * a, int ind);
void display(Array *arr);
int maxele(Array * arr); 
int minele(Array * arr); 
void reverse(Array * arr);
void merge(Array * a, Array *b); 

