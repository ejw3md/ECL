
typedef struct stacknode
{
    void * val;
    struct stacknode * next;
} StackNode;

typedef struct stack
{
    struct stacknode * contents;
} Stack;

void stackPush(Stack * s, void * val);
void * stackPop(Stack * s);
Stack * initStack();
void freeStack(Stack * s);
