#include "sortingAlg.h"
#include "utilities.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void ex_4()
{
	// lab 1 lists:
	int A[] = { 3,1,5,10,8,7 }; //arrays to sort
	int B[] = { 5,2,9,6,1,2 }; //arrays to sort
	int arrSizeA = sizeof(A) / sizeof(A[0]);
	int arrSizeB = sizeof(B) / sizeof(B[0]);
	
	//my personal code number
	int Pnum[] = { 1,9,9,6,0,9,1,0,1,1,1,9 }; //arrays to sort
	int arrSizePnum = sizeof(Pnum) / sizeof(Pnum[0]);

	//lists from Lab 1
	printf("List 1 unsorted:\n");
	print(A, arrSizeA);
	printf("List 1 sorted:\n");
	insertionSort(A, arrSizeA);
	print(A, arrSizeA);
	printf("\n");

	printf("List 2 unsorted:\n");
	print(B, arrSizeB);
	printf("List 2 sorted:\n");
	mergeSort(B, 0, arrSizeB - 1);
	print(B, arrSizeB);
	printf("\n");
	//personal number
	printf("My personal number:\n");
	print(Pnum, arrSizePnum);
	printf("My merge sorted personal number:\n");
	mergeSort(Pnum,0,arrSizePnum-1);
	print(Pnum, arrSizePnum);
	



}