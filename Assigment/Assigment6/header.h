typedef struct heap{
    int * data;
    int rear,size;
}heap;

void initHeap(heap * h1, int size);
void swaph(heap * h1, int a, int b);
int parent(int index);
void insertInheap(heap * h1, int data);
void print_heap(heap h1);
void heapify(heap * h1);
void delete_max(heap * h1);
void heap_sort(heap *h1);
