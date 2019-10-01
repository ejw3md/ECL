#include <stdlib.h>

#include "queue.h"

static QueueNode * createQueueNode(void * val)
{
    QueueNode * new = malloc(sizeof(QueueNode));
    new->next = NULL;
    new->val = val;
    return new;
}

void queuePush(Queue * q, void * val)
{
    QueueNode * new = createQueueNode(val);
    if(q->contents == NULL)
    {
        q->contents = new;
        new->next = new;
    }
    else
    {
        new->next = q->contents->next;
        q->contents->next = new;
        q->contents = new;
    }
}

void * queuePop(Queue * q)
{
    if(q->contents == NULL)
        return NULL;
    void * ret = q->contents->next->val;
    QueueNode * temp = q->contents->next;
    if(q->contents == q->contents->next)
    {
        q->contents = NULL;
    }
    else
    {
        q->contents->next = q->contents->next->next;
    }
    free(temp);
    return ret;
}

Queue *initQueue()
{
    Queue * q = malloc(sizeof(Queue));
    q->contents = NULL;
    return q;
}

void freeQueue(Queue *q)
{
    QueueNode * itr = q->contents;
    QueueNode *tempitr = q->contents;
    while(itr)
    {
        itr = itr->next;
        free(tempitr);
        tempitr = itr;
    }
    free(q);
}
