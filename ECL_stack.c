#include <stdlib.h>

#include "ECL_stack.h"

static StackNode * createStack(void * val)
{
    StackNode * new = malloc(sizeof(StackNode));
    new->next = NULL;
    new->val = val;
    return new;
}

void stackPush(Stack * s, void * val)
{
    StackNode * new = createStack(val);
    new->next = s->contents;
    s->contents = new;
}

void * stackPop(Stack * s)
{
    if(s->contents == NULL)
        return NULL;
    void * ret = s->contents->val;
    StackNode * temp = s->contents;
    s->contents = s->contents->next;
    free(temp);
    return ret;
}

Stack *initStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->contents = NULL;
}

void freeStack(Stack *s)
{
    StackNode * itr = s->contents;
    StackNode *tempitr = s->contents;
    while(itr)
    {
        itr = itr->next;
        free(tempitr);
        tempitr = itr;
    }
    free(s);
}
