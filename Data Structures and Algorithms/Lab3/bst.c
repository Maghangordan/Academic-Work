#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

BST* initTree(){
	BST* thisTree = malloc(sizeof(BST)); //Creating tree to insert nodes into
	if (thisTree == NULL) exit(-1);

	thisTree->root = NULL;
	return thisTree;
}

node* initNode(int key) { //Creating node to insert into tree
	node* thisNode = malloc(sizeof(node));
	if (thisNode == NULL) exit(-1);

	thisNode->left = NULL;
	thisNode->right = NULL;
	thisNode->parent = NULL;
	thisNode->key = key;
	return thisNode;
}


void treeWalk(node* x){ //In-order Tree Walk, i.e. prints out the sorted set
	if (x != NULL) {
		treeWalk(x->left);
		printf("%d, ", x->key);
		treeWalk(x->right);
	}
}

int treeSize(node* x) { //Recursively counts all the nodes in the tree
	if (x == NULL) {
		return 0;
	}
	return 1 + treeSize(x->right) + treeSize(x->left);
}


node* treeSearch(node* x, int key){ //Searches the tree, returns a pointer to the first node with matching key
	if (x == NULL) {
		printf("%d couldn't be found.\n", key);
		//exit(-1);
		return NULL;
	}
	if (key == x->key) {
		return x;
	}
	if (key < x->key) {
		return treeSearch(x->left, key);
	}
	return treeSearch(x->right, key);
}

node* treeMin(node* x){ //finds min, checks for empty tree
	if (x == NULL)
	{
		printf("Could not find min, tree is empty.\n");
		return NULL;
	}
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

node* treeMax(node* x){ //finds max, checks for empty tree
	if (x == NULL)
	{
		printf("Could not find max, tree is empty.\n");
		return NULL;
	}
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

node* treeSuccessor(node* x) { //Finds successor to the input node, checks if node is min
	if (x == NULL||(x->left==NULL && x->right==NULL))
	{
		printf("Successor could not be found.\n");
		return NULL;
	}
	
	if (x->right != NULL) {
		return treeMin(x->right);
	}
	node* y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

node* treePredecessor(node* x) { //finds predecessor, checks if node is max
	if (x == NULL)
	{
		printf("Predecessor could not be found.\n");
		return NULL;
	}
	if (x->left != NULL) {
		return treeMax(x->left);
	}
	node* y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}

int treeDepth(node* x){ //recursively finds depth of tree

	if (x == NULL) {
		return 0;
	}
	int leftDepth = treeDepth(x->left);
	int rightDepth = treeDepth(x->right);

	if (leftDepth > rightDepth) {
		return leftDepth + 1;
	}
	return rightDepth + 1;
}

void transplant(BST* T, node* u, node* v){
	if (u->parent == NULL) {
		T->root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else if (u == u->parent->right) {
		u->parent->right = v;
	}
	if (v != NULL) {
		v->parent = u->parent;
	}
}

int treeDelete(BST* T, node* z){
	if (z == NULL)
	{
		printf("Could not find node to delete\n");
		return 0;
	}
	if (z->left == NULL) {
		transplant(T, z, z->right);
	}
	else if (z->right == NULL) {
		transplant(T, z, z->left);
	}
	else {
		node* y = treeMin(z->right);
		if (y->parent != z) {
			transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	return 0;
}

int treeInsert(BST* T, node* z){
	if (T == NULL) exit(-1);

	node* y = NULL;
	node* x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL) {
		T->root = z; //Tree T was empty
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}

	return 0;
}

