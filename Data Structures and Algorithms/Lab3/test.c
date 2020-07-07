#include "bst.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

void testOps()
{
	BST* thisTree = initTree();
	
	treeWalk(thisTree->root); //Should display nothing

	//testing insert
	node* thisNode = initNode(5);
	treeInsert(thisTree, thisNode);
	printf("Current treeWalk:");
	treeWalk(thisTree->root);
	printf("\n");

	//testing search
	if (treeSearch(thisTree->root, 5) != NULL)
	{
		printf("Found the key %d\n", treeSearch(thisTree->root, 5)->key);
	}
	
	//testing delete
	printf("Current tree:");
	treeWalk(thisTree->root);
	printf("\n");
	treeDelete(thisTree, treeSearch(thisTree->root, 5));
	printf("Tree after deletion:\n");
	treeWalk(thisTree->root);

	//testing minimum
	for (int i = 1; i < 10; i++) //inserting values into the bst
	{
		thisNode = initNode(i);
		treeInsert(thisTree, thisNode);
	} 
	
	printf("Current tree: ");
	treeWalk(thisTree->root);
	printf("\n");
	if (treeMin(thisTree->root) != NULL)
	{
		printf("Minimum of the tree is %d\n", treeMin(thisTree->root)->key);
	}
	
	//testing maximum
	if (treeMax(thisTree->root) != NULL)
	{
		printf("Maximum of the tree is %d\n", treeMax(thisTree->root)->key);
	}
	//testing successor
	int successor = 8;
	if (treeSuccessor(treeSearch(thisTree->root, successor)) != NULL)
	{
		printf("Successor of %d is %d\n",successor, treeSuccessor(treeSearch(thisTree->root, successor))->key);
	}
	//testing predecessor
	int predecessor = 5;
	if (treePredecessor(treeSearch(thisTree->root, predecessor))!=NULL)
	{
		printf("Predecessor of %d is %d\n", predecessor, treePredecessor(treeSearch(thisTree->root, predecessor))->key);
	}

	//Finding depth
	printf("Depth is %d.\n", treeDepth(thisTree->root));

	printf("Size is %d", treeSize(thisTree->root));

}


void SDD(BST* thisTree, int key) {
	node* search = treeSearch(thisTree->root, key);
	treeDelete(thisTree, search);
	treeWalk(thisTree->root);
	printf("\n");
}