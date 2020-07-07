#pragma once
//Prints graph
int print(int** Graph);
//Tests functions from ex_1
int testing();
//In Graph, finds finds the shortest path between source and goal if possible
//int* mazer(int sx, int sy, int dx, int dy);
int* shortestPath(int goal, int source);
//SCC
int* SCC(int** Graph);
//Stack
struct Stack
{
	int top;
	unsigned cap;
	int* array;
};
struct Stack* createStack(unsigned capacity);
void push(struct Stack* stack, int item);
//Checks if stack is full, returns 1 if full, 0 if not full
int isFull(struct Stack* stack);
//Checks if stack is empty, returns 1 if empty, 0 if not empty
int isEmpty(struct Stack* stack);
//Pops top element
int pop(struct Stack* stack);
//SSSP algorithm
int* dijkstra();
