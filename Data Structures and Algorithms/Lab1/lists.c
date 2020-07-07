#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#define MAX 100

listAmount = 0;
list* ListArray[MAX * sizeof(list*)];

void listmenu() {
	int choice = 0, index = 0;
	char input[MAX] = "";

	while (choice != 9) {
		displayLists();

		printf("\n1. Create new list.\n");
		printf("2. search a list.\n");
		printf("3. Insert into a list.\n");
		printf("4. Delete from a list.\n");
		printf("5. Find maximum in a list.\n");
		printf("6. Find minimum in a list.\n");
		printf("7. Find successor in a list.\n");
		printf("8. Find predecessor in a list.\n");
		printf("9. Go to stack & Queues.\n");
		printf("10. Run the lab tests.\n");

		fgets(input, MAX, stdin);
		choice = atoi(input);

		if (listAmount == 0 && choice > 1 && choice != 9) {
			printf("You need to create a list before doing that.\n");
			choice = 1;
		}

		switch (choice) {
		case 1:
			create_list();
			break;
		case 2:
			if (listAmount > 1) { index = chooseList(); }

			printf("Which key value to search for? : ");

			fgets(input, MAX, stdin);
			int key = atoi(input);

			if (searchK(ListArray[index], key) == NULL) printf("Key couldn't be found.\n");
			else printf("Key %d found.\n", key);
			break;
		case 3:
			if (listAmount > 1) { index = chooseList(); }

			insert(ListArray[index], create_node());
			break;

		case 4:
			if (listAmount > 1) { index = chooseList(); }

			printf("Which element (key) to delete? : ");

			fgets(input, MAX, stdin);
			key = atoi(input);

			node* deleted = searchK(ListArray[index], key);

			if (deleted == NULL) {
				printf("Key couldn't be found.\n");
				break;
			}

			deleted = delete(ListArray[index], deleted);

			free(deleted);

			break;
		case 5:
			if (listAmount > 1) { index = chooseList(); }

			node* maxNode = maximum(ListArray[index]);

			printf("Maximum is %d.\n", maxNode->key); // Vad händer vid en tom lista?

			break;
		case 6:
			if (listAmount > 1) { index = chooseList(); }

			node* minNode = minimum(ListArray[index]);

			printf("Minimum is %d.\n", minNode->key); // Vad händer vi en tom lista?

			break;
		case 7:
			if (listAmount > 1) { index = chooseList(); }

			printf("Which element's successor to find? : ");

			fgets(input, MAX, stdin);
			key = atoi(input);

			node* element = searchK(ListArray[index], key);
			if (element == NULL) {
				printf("Key couldn't be found.\n");
				break;
			}

			node* successorElement = successor(ListArray[index], element);
			if (successorElement == NULL) {
				printf("It's the maximum value, so no successor could be found.\n");
				break;
			}

			printf("Successor of %d is %d\n", element->key, successorElement->key);

			break;

		case 8:
			if (listAmount > 1) { index = chooseList(); }

			printf("Which element's predecessor to find? : ");

			fgets(input, MAX, stdin);
			key = atoi(input);

			element = searchK(ListArray[index], key);
			if (element == NULL) {
				printf("Key couldn't be found.\n");
				break;
			}

			node* predecessorElement = predecessor(ListArray[index], element);
			if (predecessorElement == NULL) {
				printf("It's the minimum value, so no predecessor could be found.\n");
				break;
			}

			printf("Predecessor of %d is %d\n", element->key, predecessorElement->key);


			break;
		case 10:

			list * L1 = ListArray[0];
			list* L2 = ListArray[1];

			node* L1Max = maximum(L1);
			node* L1Min = minimum(L1);

			printf("Of L1, minimum is %d, maximum is %d.\n", L1Min->key, L1Max->key);

			node* L2Max = maximum(L2);
			node* L2Min = minimum(L2);

			printf("Of L2, minimum is %d, maximum is %d.\n", L2Min->key, L2Max->key);

			node* node5 = searchK(L1, 5);

			node* pre5 = predecessor(L1, node5);
			node* suc5 = successor(L1, node5);

			printf("The successor is %d, and predecessor is %d of node with key 5 in L1.\n",
				suc5->key, pre5->key);

			node* node9 = searchK(L2, 9);

			node* pre9 = predecessor(L2, node9);

			printf("The successor is none, and predecessor is %d of node with key 9 in L2.\n",
				pre9->key);

			node* maxx = maximum(L1);
			node* preMaxx = predecessor(L2, maxx);

			printf("The key of the predecessor in L2 of the maximum of L1 is %d.\n", preMaxx->key);

			maxx = maximum(L2);
			preMaxx = predecessor(L1, maxx);

			printf("The key of the predecessor in L1 of the maximum of L2 is %d.\n\n", preMaxx->key);


			break;
		}
	}
}



//Return true if list is empty, else false
bool isEmpty(list* L) {
	return (L->head == NULL);
}

//Allocates space for list struct, asking user for how many nodes in list
list* create_list() {

	list* thisList = malloc(sizeof(list));
	printf("How many elements in the list? : ");

	char input[MAX] = "";
	fgets(input, MAX, stdin);

	thisList->length = atoi(input);
	thisList->head = NULL;

	for (int i = 0; i < thisList->length; i++) {

		node* thisNode = create_node();

		insert(thisList, thisNode);
	}

	//Increases list amount so displayLists() work fine.
	if (listAmount <= MAX) {
		ListArray[listAmount] = thisList;
		listAmount++;
	}
	else { printf("Max amount of lists is %d, error!", MAX); exit(1); }

	return thisList;
}

//Allocates space for new node and asks user for key
node* create_node() {
	node* tmp = malloc(sizeof(node));
	if (tmp == NULL) { printf("Error allocating node.\n");  exit(1); } //checks allocation faults

	tmp->next = NULL;
	tmp->prev = NULL;

	printf("Chose key for new node: ");
	char input[MAX] = "";
	fgets(input, MAX, stdin);

	tmp->key = atoi(input);

	return tmp;
}



//Inserts node into list, return true if successful
bool insert(list* L, node* x) {
	x->next = L->head;

	if (L->head != NULL) {
		L->head->prev = x;
	}
	L->head = x;
	x->prev = NULL;

	return true;
}

//Returns a pointer to the node N if key K is in the list, else it'll return NULL since x.next will be a NULL ptr
node* searchK(list* L, int k) {
	node* x = L->head;
	while (x != NULL && x->key != k)
		x = x->next;
	return x;
}

/* Returns a pointer to the node N if the node N is in the list, else NULL
node* searchN(list* L, node* x) {
	node* tmp = L->head;
	while (x != NULL && tmp->key != x->key)
		tmp = tmp->next;
	return tmp;
}*/

int chooseList() {
	char input[MAX] = "";

	printf("Which list? : ");
	fgets(input, MAX, stdin);

	int index = atoi(input) - 1;

	if (index + 1 > listAmount) {
		printf("Can't choose that.\n");
		exit(1);
	}

	return index;
}

//Deletes a node x in a list L, requires search to find the right node ptr if we're not deleting just the first one. TODO: Also free the node is important after.
node* delete(list* L, node* x) {
	if (x->prev != NULL) {
		x->prev->next = x->next;
	}
	else L->head = x->next;

	if (x->next != NULL) {
		x->next->prev = x->prev;
	}
	return x;
}


void displayLists() {
	printf("Your current lists are:\n");

	if (listAmount == 0) {
		printf("None\n");
	}
	else {
		for (int i = 0; i < listAmount; i++)
		{
			printf("%d. { ", i + 1);

			for (node* tmp = ListArray[i]->head;
				tmp != NULL; tmp = tmp->next) {
				printf("%d, ", tmp->key);
			}
			printf("}\n");
		}
	}
}


node* maximum(list* L) {

	node* maxNode = L->head; // Fungerar inte ?

	for (node* tmp = L->head;
		tmp != NULL; tmp = tmp->next) {

		if (maxNode->key < tmp->key) {
			maxNode = tmp;
		}
	}
	return maxNode;
}


node* minimum(list* L) {
	node* minNode = L->head;

	for (node* tmp = L->head;
		tmp != NULL; tmp = tmp->next) {

		if (minNode->key > tmp->key) {
			minNode = tmp;
		}
	}
	return minNode;
}


node* successor(list* L, node* x) {
	node* successor = maximum(L);

	bool test = false;

	for (node* tmp = L->head;
		tmp != NULL;
		tmp = tmp->next) {

		if (tmp->key > x->key) {
			if (successor->key >= tmp->key) {
				successor = tmp;
				test = true;
			}
		}
	}
	if (test)
		return successor;
	else
		return NULL;
}

node* predecessor(list* L, node* x) {
	node* predecessor = minimum(L);

	bool test = false;

	for (node* tmp = L->head;
		tmp != NULL;
		tmp = tmp->next) {

		if (tmp->key < x->key) {
			if (predecessor->key <= tmp->key) {
				predecessor = tmp;
				test = true;
			}
		}
	}
	if (test)
		return predecessor;
	else
		return NULL;
}
