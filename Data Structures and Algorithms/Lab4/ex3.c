#include "MatOps.h"
#include "utils.h"
#include <stdio.h>

#define NODES 5

int min(int i, int j) //utility function
{

	return (i < j) ? i : j;
}
void findSCC(int** Graph,int u, int discovered[], int lower[], struct Stack* stack, bool stackElement[])
{
	static int time = 0; //Keeping track through iterations of recursion
	discovered[u] = lower[u] = ++time;

	push(stack, u); //for current u=i from driver function
	stackElement[u] = true; //ie visited
	int i;


	for (i = 0; i < NODES; i++)
	{
		if (Graph[u][i])
		{
			if (discovered[i] == -1)
			{

				findSCC(Graph, i, discovered, lower, stack, stackElement); //run it again
				lower[u] = min(lower[u], lower[i]);
			}
			else if (stackElement[i])
			{
				lower[u] = min(lower[u], discovered[i]);
			}
		}
	}
	int poppedElement = 0;

	if (lower[u] == discovered[u])
	{
		while (stack->array[stack->top != u]) //Prints resulting stack in order

		{

			poppedElement = stack->array[stack->top];
			printf("%d ",poppedElement);
			stackElement[poppedElement] = false;
			pop(stack);
		}
		poppedElement = stack->array[stack->top];
		printf("%d \n", poppedElement);
		stackElement[poppedElement] = false;
		pop(stack);
	}
}
int* SCC(int** Graph) //Driver function, uses findSCC()
{
	struct Stack* stacken = createStack(100); //stack-implementation from stack.c

	int disc[NODES], lower[NODES];
	bool stackElement[NODES];
	int i;

	for (i = 0; i < NODES; i++)
	{
		disc[i] = lower[i] = -1;
		stackElement[i] = false;
	}

	for (i = 0; i < NODES; i++)
	{
		if (disc[i] == -1)
		{
			findSCC(Graph,i, disc, lower, stacken, stackElement);
		
		}

	}
	



}