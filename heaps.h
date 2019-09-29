typedef struct heapnode
{
    void * val;
    int nodesUnder;
    struct heapnode * left;
    struct heapnode * right;
} HeapNode;

HeapNode* addElement(HeapNode* heap, void * val, int (*compare)(void *, void *));
void * popElement(HeapNode** heap, int (*compare)(void *, void *));
void freeHeap(HeapNode * heap);
