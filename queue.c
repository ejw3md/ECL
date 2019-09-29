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
    if(q->front == NULL)
    {
        q->front = new;
        q->back = new;
    }
    else
    {
        q->back->next = new;
        q->back = new;
    }
}

void * queuePop(Queue * q)
{
    if(q->front == NULL)
        return NULL;
    void * ret = q->front->val;
    QueueNode * temp = q->front;
    q->front = q->front->next;
    free(temp);
    return ret;
}

Queue *initQueue()
{
    Queue * q = malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;
    return q;
}

void freeQueue(Queue *q)
{
    QueueNode * itr = q->front;
    QueueNode *tempitr = q->front;
    while(itr)
    {
        itr = itr->next;
        free(tempitr);
        tempitr = itr;
    }
    free(q);
}
