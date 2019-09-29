#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 10

int main()
{
	Stack *s = initStack();
	int * arr = malloc(sizeof(int) * SIZE);
	for(int i=0; i<SIZE; i++)
	{
		arr[i] = i;
		stackPush(s, &arr[i]);
	}

	for(int i=0; i<SIZE; i++)
	{
		printf("%d\n", (*(int *)stackPop(s)));
	}
	freeStack(s);
}
