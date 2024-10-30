typedef struct heap{
    int * data;
    int rear;
    int size;
}heap;


void init_heap(heap *h1, int k);
void insert_heap(heap *h1, int k);
int parent(int index);
void swaph(heap *h1, int a, int b);
void heapify(heap *h1);//Heapify from top to bottom
void delete_max(heap *h1);
void print_heap(heap h1);
void heap_sort(heap *h1);