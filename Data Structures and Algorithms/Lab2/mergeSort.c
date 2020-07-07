#include "sortingAlg.h"
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int merge(int A[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L; int* R;
	L = malloc(sizeof(int) * n1);
	R = malloc(sizeof(int) * n2);
	
	for (i = 0; i < n1; i++)
		L[i] = A[p + i]; //adds left side of A to L
	for (j = 0; j < n2; j++)
		R[j] = A[q + 1 + j]; //adds right side of A to R

	i = j = 0;   
	k = p; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	for(i;i<n1;i++) //adds remaining
	{
		A[k] = L[i];
		k++;
	}
	for (j; j < n2;j++) //adds remaining
	{
		A[k] = R[j];
		k++;
	}
	
}
int mergeSort(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q =(p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);

		merge(A, p, q, r);
	}
}
