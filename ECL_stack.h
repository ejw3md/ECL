
typedef struct stacknode
{
    void * val;
    struct stacknode * next;
} StackNode;

typedef struct stack
{
    struct stacknode * contents;
} Stack;

Stack * initStack();
void stackPush(Stack * s, void * val);
void * stackPop(Stack * s);
void freeStack(Stack * s);
int stackEmpty(Stack * q);
