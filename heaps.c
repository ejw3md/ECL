#include <stdlib.h>

#include "heaps.h"

static HeapNode* createHeapNode(void * val)
{
    HeapNode* new = malloc(sizeof(HeapNode));

    new->val = val;
    new->nodesUnder = 0;
    new->left = NULL;
    new->right = NULL;

    return new;
}

HeapNode* addElement(HeapNode* heap, void * val, int (*compare)(void *, void *))
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
            addElement(heap->right, val, compare);
        }
        else
        {
            addElement(heap->left, val, compare);
        }
    }
    return heap;
}

void * popElement(HeapNode** heap, int (*compare)(void *, void *))
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
        (*heap)->val = popElement(&(*heap)->left, compare);

    }
    else if((*heap)->left == NULL)
    {
        (*heap)->val = popElement(&(*heap)->right, compare);
    }
    else
    {
        if((*compare)((*heap)->left->val, (*heap)->right->val))
        {
            (*heap)->val = popElement(&(*heap)->left, compare);
        }
        else
        {
            (*heap)->val = popElement(&(*heap)->right, compare);
        }
    }
    return val;
}

void freeHeap(HeapNode * heap)
{
    if(heap !=NULL)
    {
        freeHeap(heap->right);
        freeHeap(heap->left);
        free(heap);
    }
}
