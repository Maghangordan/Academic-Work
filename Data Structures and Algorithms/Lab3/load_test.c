#include "utilities.h"
#include "bst.h"
#include <stdio.h>

void testLoad()
{
	int* loadArray = load_file("test-10-1-problem");
	int size = loadArray[0];

	BST* thisTree = initTree();

	printf("\nLoading file with elements:\n");
	for (int i = 1; i <= size; i++) {
		node* thisNode = initNode(loadArray[i]);
		printf("%d, ",loadArray[i]);
		treeInsert(thisTree, thisNode);

	}
	printf("\nSorted list:\n");
	treeWalk(thisTree->root);
	
}