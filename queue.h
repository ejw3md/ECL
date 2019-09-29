typedef struct queuenode
{
    void * val;
    struct queuenode * next;
} QueueNode;

typedef struct queue
{
    QueueNode * contents;
} Queue;

void queuePush(Queue * q, void * val);
void * queuePop(Queue * q);
Queue * initQueue();
void freeQueue(Queue * q);
