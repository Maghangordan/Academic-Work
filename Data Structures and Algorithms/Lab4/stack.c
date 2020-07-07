#include "utils.h"
#include <stdlib.h>
#include <limits.h>

struct Stack* createStack(unsigned numElements)
{
	struct Stack* stack = malloc(sizeof(struct Stack));
	if (stack == NULL)
	{
		exit(10);
	}
	stack->cap = numElements;
	stack->top = -1; //First time
	stack->array = malloc(stack->cap * sizeof(int));
	return stack;
}
int isFull(struct Stack* stack)
{
	return stack->top == stack->cap - 1;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
	{
		return;
	}
	stack->array[++stack->top] = item;
	//printf("%d pushed to stack\n",item);
}
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
	{
		return INT_MIN;
	}
	return stack->array[stack->top--];
}
