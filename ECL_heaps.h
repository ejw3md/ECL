typedef struct heapnode
{
    void * val;
    int nodesUnder;
    struct heapnode * left;
    struct heapnode * right;
} HeapNode;

typedef struct heap
{
    struct heapnode * contents;
} Heap;

Heap * initHeap();
void heapPush(Heap * heap, void * val, int (*compare)(void *, void *));
void * heapPop(Heap * heap, int (*compare)(void *, void *));
void freeHeap(Heap * heap);
int heapEmpty(Heap * heap);
