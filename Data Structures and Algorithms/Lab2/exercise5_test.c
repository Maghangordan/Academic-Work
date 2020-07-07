#include "sortingAlg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
int tester()
{ 
	//We want to test one of every magnitude,10,100,1000,10 000,100 000 numbers
	int errorTest = 0;
	int i,j;
	char problem[6][25];
	strcpy(problem[1], "test-10-1-problem");
	strcpy(problem[2], "test-100-1-problem");
	strcpy(problem[3], "test-1000-1-problem");
	strcpy(problem[4], "test-10000-1-problem");
	strcpy(problem[5], "test-100000-1-problem");

	char solution[6][25];
	strcpy(solution[1], "test-10-1-solution");
	strcpy(solution[2], "test-100-1-solution");
	strcpy(solution[3], "test-1000-1-solution");
	strcpy(solution[4], "test-10000-1-solution");
	strcpy(solution[5], "test-100000-1-solution");

	int* a;
	int size;
	int* b;
	//insertionSort(a,size+1) due to starting index
	//mergeSort(a,1,size) due to starting index

	//testing
	for (i = 1; i <= 5; i++)
	{
		a = load_file(problem[i]);
		size = a[0];
		errorTest = 0;
		b = load_file(solution[i]);

		//a[0] = NULL; b[0] = NULL;
		
		//insertionSort(a, size + 1); requires null declarations on a[0] and b[0] 
		//because a[0]=num_elements from load_file. If needed,
		//remove the comments on row 39 and discard first element which will be 0
		//tested to work as intended
		mergeSort(a, 1, size);
		for (j = 0; j <= size; j++)
		{
			if (a[j]!=b[j])
			{
				errorTest++;
			}
		}
		printf("For %d numbers, %d errors found\n",size,errorTest);
	}
}