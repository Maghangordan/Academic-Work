#include "lists.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#pragma warning( disable : 6011)

void print(struct List* printptr)
{
	while (!(printptr == NULL))
	{
		printf("%d ", printptr->L);
		printptr = printptr->next;
	}
	printf("\n");
}
bool push(struct List** headptr, int newInt)
{
	struct List* newptr = (struct List*)malloc(sizeof(struct List));
	(newptr->L) = (newInt);

	newptr->next = (*headptr);
	newptr->prev = NULL;
	if (!(*headptr == NULL))
	{
		(*headptr)->prev = newptr;
	}
	(*headptr) = newptr;
	if (newptr->L == newInt)
	{
		return true;
	}
	else
	{
		return false;
	}
}
struct List* pop(struct List** delptr, struct List* delnode)
{
	struct List* retptr = (struct List*)malloc(sizeof(struct List));
	if (((*delptr) == NULL) || (delnode == NULL))
	{
		return NULL;
	}
	if ((*delptr) == delnode)
	{
		(*delptr) = delnode->next;
		retptr = delnode->next;
	}
	if (delnode->next != NULL)
	{
		delnode->next->prev = delnode->prev;

	}
	if (delnode->prev != NULL)
	{
		delnode->prev->next = delnode->next;

	}
	free(delnode);
	return retptr;

}


void queue()
{
	int opt = 0;
	int captvar, i;
	int first = 0;
	int last = 0;
	enum QUEUESIZE { QUEUESIZE = 10 };
	int kö[QUEUESIZE];
	while (opt != 3)
	{
		printf("\n1.Enqueue(Enter)\n2.Dequeue\n3.Exit\n");
		captvar = scanf("%d", &opt);
		if (opt == 1) //Enqueue
		{
			if (last == QUEUESIZE)
			{
				printf("\nQueue is full.");
			}
			else
			{
				printf("Enter element to enqueue:\n");
				captvar = scanf("%d", &kö[last]);
				last++;
			}
		}
		if (opt == 2) //Dequeue
		{
			if (first == last)
			{
				printf("\nQueue is Empty.");
			}
			else
			{
				for (i = first; i < last; i++)
				{
					kö[i] = kö[i + 1];
				}
				last--;
			}
		}
		printf("\nCurrent queue:\n"); //print
		if (first == last)
		{
			printf("\nQueue is Empty.");
		}
		else
		{
			for (i = first; i < last; i++)
			{
				printf("%d ", kö[i]);
			}
		}

	}
}
void stack()
{
	int opt = 0;
	struct List* stackptr = NULL;
	int input;
	int captvar;
	while (opt != 3)
	{
		printf("\nCurrent stack: ");
		print(stackptr);
		printf("\n1.Push(Enter)\n2.Pop(Remove)\n3.Go to queues\n");
		printf("Enter an option:\n");
		captvar = scanf("%d", &opt);
		if (opt == 1)
		{
			printf("Enter value:\n");
			captvar = scanf("%d", &input);
			push(&stackptr, input);
		}
		if (opt == 2)
		{
			pop(&stackptr, stackptr);
		}
	}
	free(stackptr);
}


