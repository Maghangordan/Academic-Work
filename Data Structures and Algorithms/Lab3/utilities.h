
#include "bst.h"
#define MAX_NUM_ELEMENTS 100

//used for loading the random number file
int* load_file(const char* fName);

//tests the basic dynamic operations
void testOps();

//Loads file, adds it to a bst, prints the numbers out using treeWalk()
void testLoad();

void SDD(BST*,int); //Search, Delete, Display tree

