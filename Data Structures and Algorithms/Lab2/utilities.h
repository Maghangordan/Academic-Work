#ifndef HEADER_UTIL_FILE
#define HEADER__UTIL_FILE


//Utility function
void print(int A[], int size);

/*----- Testing functions------ */

//Testing the implementation with SSN and and lists given in lab 1. See ex_4.txt for more info.
void ex_4();


//load file function for loading random arrays. See ex_5.txt for more info.
#define MAX_NUM_ELEMENTS		100000
int* load_file(const char* fName);

//Exercise 5 function for utilizing load_file for a file that
// randomly generates arrays and then testing insertion sort vs merge sort. See ex_5.txt for more info. 
int tester();
#endif