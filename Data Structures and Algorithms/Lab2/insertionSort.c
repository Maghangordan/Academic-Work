#include "sortingAlg.h"
#include <stdio.h>
#include <math.h>

void insertionSort(int A[], int size)
{
	int j; int i; int key;
	
	for (j = 1; j < size; j++)
	{
		
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
