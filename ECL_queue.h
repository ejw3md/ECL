typedef struct queuenode
{
    void * val;
    struct queuenode * next;
} QueueNode;

typedef struct queue
{
    QueueNode * contents;
} Queue;

Queue * initQueue();
void queuePush(Queue * q, void * val);
void * queuePop(Queue * q);
void freeQueue(Queue * q);
