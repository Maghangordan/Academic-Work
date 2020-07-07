#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdbool.h>

typedef struct node {
	int key;
	struct node* next;
	struct node* prev;
} node;

typedef struct list {
	node* head;
	int length;
} list;

int listAmount;


void listmenu();
bool isEmpty(list* L);
list* create_list();
node* create_node();
bool insert(list* L, node* x);
node* searchK(list* L, int k);
int chooseList();
node* delete(list* L, node* x);

void displayLists();

node* maximum(list* L);
node* minimum(list* L);
node* successor(list* L, node* x);
node* predecessor(list* L, node* x);


//Queues and stacks
struct List
{
	int L;
	struct List* next;
	struct List* prev;

};

void print(struct List* printptr);
bool push(struct List** headptr, int newInt);
struct List* pop(struct List** delptr, struct List* delnode);
void stack();


void queue();



#endif