#pragma once

/*---DATASTRUCTURES---*/
typedef struct node {
	int key;

	struct node* parent;
	struct node* left;
	struct node* right;
} node;

typedef struct BST {
	node* root;
} BST;

/*---INITIALIZING OPERATIONS---*/
BST* initTree();//Creating tree to insert nodes into
node* initNode(int);//Creating node to insert into tree
void treeWalk(node*); //display function to walk the tree in the order of smallest to largest number


/*---QUERIES---*/
/*Requires tree->root as input if purpose is to query the whole tree*/


node* treeSearch(node*, int);//Searches the tree, returns a pointer to the first node with matching key
node* treeMin(node*);//finds min, checks for empty tree
node* treeMax(node*);//finds max, checks for empty tree
node* treeSuccessor(node*);//Finds successor to the input node, checks if node is max
node* treePredecessor(node*);//finds predecessor, checks if node is min
int treeDepth(node*);//recursively finds depth of tree
int treeSize(node*);//Recursively counts all the nodes in the tree



/*---MODIFYING OPERATIONS---*/

//Deletion
void transplant(BST*, node*, node*); //Transplants nodes in tree
int treeDelete(BST*, node*); // utilizing transplant, it deletes node from tree

//Insertion
int treeInsert(BST*, node*); //inserts into tree
