#include "MatOps.h"
#include "utils.h"
#define n 5
#define LARGENUMBER 999
#include <limits.h>
#include <string.h>
#include <stdio.h>


int* dijkstra()
{
	int** graph = createGraph(n);
	int source = 0;
	int dist[n]; int prev[n];
	int visited[n]; int counter; int min, next, i, j;
	int noder[n][n];
	//addDirectededge() does not support adding weight to the adjacency matrix representation
	//thus we create the graph "by hand"
	//Example from book, figure 24.2(A) from page 648 in Introduction to algorithms
	//s=0 t=1 x=2 z=3 y=4
	
	graph[0][1] = 3; graph[0][4] = 5; graph[1][2] = 6; graph[1][4] = 2; graph[2][3] = 2; graph[3][2] = 7; graph[3][0] = 3; graph[4][1] = 1; graph[4][3] = 6; graph[4][2] = 4;
	
	print(graph);
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
		for(i=0;i<n;i++)
			if(!visited[i])
				if (min + noder[next][i] < dist[i])
				{
					dist[i] = min + noder[next][i];
					prev[i] = next;
				}
		counter++;
	}
	for (i = 0; i < n; i++)
	{
		if (i != source)
		{
			printf("\nDistance of node%d=%d",i,dist[i]);
			printf("\nPath=%d",i);
			j = i;
			do
			{
				j = prev[j];
				printf("<-%d", j);
			} while (j != source);
		}
	}
	
}