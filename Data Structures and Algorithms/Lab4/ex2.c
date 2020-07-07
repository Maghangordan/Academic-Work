#include "MatOps.h"
#include "utils.h"
#include <limits.h>
#include <stdio.h>
#define LARGENUMBER 999
#define n 100


int* shortestPath(int goal, int source)
{
	int** graph = createGraph(n);
	//int source = 0;
	//int goal = 5; //x=5,y=0; goal=15 => x=1,y=5 on maze map starting from 0,0
	int dist[n]; int prev[n];
	int visited[n]; int counter; int min, next, i, j;
	int noder[n][n];


	//Adding all horisontal edges
	for (int j = 0; j < 100; j = j + 10) {
		for (int i = j; i < j + 9; i++) {
			if (i != 3 &&    /*Line on row 4*/
				i != 13 &&
				i != 23 &&
				i != 33 &&
				i != 43 &&
				i != 53 &&
				i != 63 &&
				i != 73 &&

				i != 4 && /*Line on row 5*/
				i != 14 &&
				i != 24 &&
				i != 34 &&
				i != 44 &&
				i != 54 &&
				i != 64 &&
				i != 74 &&
				i != 84 &&

				i != 80 && /*(1, 9) left corner*/

				i != 48 /* (10,5) right middle*/
				) {
				addUndirectedEdge(graph, i, i + 1);
			}
		}
	}

	//Adding all vertical edges
	for (int j = 0; j < 90; j = j + 10) {
		for (int i = j; i < j + 9; i++) {
			if (i != 71 && /*Row 8, 2-4*/
				i != 72 &&
				i != 73 &&

				i != 81 && /*row 9, 2-5*/
				i != 82 &&
				i != 83 &&
				i != 84 &&


				i != 35 && /*Row 4, 6-9*/
				i != 36 &&
				i != 37 &&
				i != 38 &&

				i != 45 && /*row 5, 6-9*/
				i != 46 &&
				i != 47 &&
				i != 48) {
				addUndirectedEdge(graph, i, i + 10);
			}
		}
	}

	addUndirectedEdge(graph, 99, 89);
	addUndirectedEdge(graph, 79, 89);
	addUndirectedEdge(graph, 59, 69);
	addUndirectedEdge(graph, 49, 59);
	addUndirectedEdge(graph, 49, 59);
	addUndirectedEdge(graph, 39, 49);
	addUndirectedEdge(graph, 29, 39);
	addUndirectedEdge(graph, 19, 29);
	addUndirectedEdge(graph, 9, 19); 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (graph[i][j] == 0)
			{
				noder[i][j] = LARGENUMBER;

			}
			else
			{
				noder[i][j] = graph[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		dist[i] = noder[source][i];
		prev[i] = source;
		visited[i] = 0;
	}
	dist[source] = 0;
	visited[source] = 1;
	counter = 1;
	while (counter < n - 1)
	{
		min = LARGENUMBER;
		for (i = 0; i < n; i++)
			if (dist[i] < min && !visited[i])
			{
				min = dist[i];
				next = i;
			}
		visited[next] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (min + noder[next][i] < dist[i])
				{
					dist[i] = min + noder[next][i];
					prev[i] = next;
				}
		counter++;
	}
	for (i = 0; i < n; i++)
	{
		if (i ==goal)
		{
			if (dist[i] >= LARGENUMBER)
			{
				printf("Node %d is unaccessable.\n",i);
				return ;
			}
			printf("\nDistance of node%d = %d", i, dist[i]);
			printf("\nPath=%d", i);
			j = i;
			do
			{
				j = prev[j];
				printf("->%d", j);
			} while (j != source);
		}
	}

}