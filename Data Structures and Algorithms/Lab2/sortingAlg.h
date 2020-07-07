#ifndef HEADER_FILE
#define HEADER_FILE


/*--- Implementation functions ---- */

//Insertion sort. Complexity of O(n^2) see ex_1.txt for more info.
void insertionSort(int A[], int size);

//Merge sort functions. Complexity of O(nlog(n)). See ex_2.txt for more info.
int merge(int A[], int p, int q, int r);
int mergeSort(int A[], int p, int r);





#endif