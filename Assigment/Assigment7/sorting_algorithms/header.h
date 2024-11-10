typedef struct Array{
    int * data;
    int size;
    int len;
    
}Array;

void init(Array * a, int size);
void append(Array * a, int data);
void display(Array *arr);
void Bubble_Sort(Array * arr);
void Selection_Sort(Array * arr);
void Insertion_Sort(Array * arr);
void swap(int* a, int* b);
int partition(Array * arr, int low, int high);
void quick_sort(Array * a, int low, int high);
void heap_sort(Array * arr);
void heapify(Array * arr, int n, int i);


