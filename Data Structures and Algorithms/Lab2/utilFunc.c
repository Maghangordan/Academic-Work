#include "utilities.h"
#include <stdio.h>
void print(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
