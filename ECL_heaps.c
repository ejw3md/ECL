#include <stdlib.h>

#include "ECL_heaps.h"

static HeapNode* createNode(void * val)
{
    HeapNode* new = malloc(sizeof(HeapNode));

    new->val = val;
    new->nodesUnder = 0;
    new->left = NULL;
    new->right = NULL;

    return new;
}

static HeapNode* addHeapNode(HeapNode* heap, void * val, int (*compare)(void *, void *))
{
    if(heap == NULL)
    {
        return createNode(val);
    }

    heap->nodesUnder++;

    if((*compare)(val, heap->val))
    {
        void * temp = val;
        val = heap->val;
        heap->val = temp;
    }

    if( heap->left == NULL )
    {
        heap->left = createNode(val);
    }

    else if(heap->right == NULL)
    {
        heap->right = createNode(val);
    }

    else
    {
        if(heap->right->nodesUnder < heap->left->nodesUnder)
        {
            addHeapNode(heap->right, val, compare);
        }
        else
        {
            addHeapNode(heap->left, val, compare);
        }
    }
    return heap;
}

static void * popHeapNode(HeapNode** heap, int (*compare)(void *, void *))
{
    if(*heap == NULL)
    {
        return NULL;
    }
    void * val = (*heap)->val;
    (*heap)->nodesUnder--;
    if((*heap)->right == NULL && (*heap)->left == NULL)
    {
        free(*heap);
        *heap = NULL;
        return val;
    }
    else if((*heap)->right == NULL)
    {
        (*heap)->val = popHeapNode(&(*heap)->left, compare);

    }
    else if((*heap)->left == NULL)
    {
        (*heap)->val = popHeapNode(&(*heap)->right, compare);
    }
    else
    {
        if((*compare)((*heap)->left->val, (*heap)->right->val))
        {
            (*heap)->val = popHeapNode(&(*heap)->left, compare);
        }
        else
        {
            (*heap)->val = popHeapNode(&(*heap)->right, compare);
        }
    }
    return val;
}

static void freeHeapNodes(HeapNode * heap)
{
    if(heap !=NULL)
    {
        freeHeapNodes(heap->right);
        freeHeapNodes(heap->left);
        free(heap);
    }
}
Heap * initHeap()
{
    Heap * heap = malloc(sizeof(heap));
    heap->contents = NULL;
    return heap;
}

void heapPush(Heap * heap, void * val, int (*compare)(void *, void *))
{
    heap->contents = addHeapNode(heap->contents, val, compare);
}

void * heapPop(Heap * heap, int (*compare)(void *, void *))
{
    return popHeapNode(&heap->contents, compare);
}

void freeHeap(Heap * heap)
{
    freeHeapNodes(heap->contents);
    free(heap);
}

int heapEmpty(Heap * heap)
{
    return heap->contents == NULL;
}
