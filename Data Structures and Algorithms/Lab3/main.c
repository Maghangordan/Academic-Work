#include "bst.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
	testOps(); //tesing dynamic operations
	testLoad(); //loading file and sorting

	//srand(time(NULL)); // Seeding the rand() function for random keys
	
	/*
	--- Testing the BST implementation using rand() function: ------------

	int* loadArray = load_file("test-10-1-problem");
	int size = loadArray[0];

	BST* thisTree = initTree();

	#define TSIZE 100
	for (int i = 1; i <= TSIZE; i++) {
		node* thisNode = initNode(loadArray[i]);
		//node* thisNode = initNode(rand() % 50); //for a random number list
		treeInsert(thisTree, thisNode);

	}
	treeWalk(thisTree->root);
	---------------------------------------------------------------------*/
	
}
