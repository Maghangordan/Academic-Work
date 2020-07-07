#include "MatOps.h"
#include "utils.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>



int testing()
{
	//A couple of tests to show that the graph works as intended
	int i;
	int N = 5;
	int Neighbor1 = 1;
	int Neighbor2 = 2;
	int** Graph = createGraph(N);
	
	
	print(Graph);
	printf("Number of vertices:%d\n",getNumVertices(Graph));
	printf("Number of edges:%d\n", getNumEdges(Graph));
	
	addUndirectedEdge(Graph, 1, 2);
	addDirectedEdge(Graph, 1, 3);
	addDirectedEdge(Graph, 1, 4);
	print(Graph);
	printf("%d has neighbors:\n", Neighbor1);
	for (i = 0; i < N; i++)
	{
		if (getNeighbors(Graph, Neighbor1)[i] != -1)
		{
			printf("%d ", getNeighbors(Graph, Neighbor1)[i]);
		}
		
	}
	printf("\nNumber of edges:%d\n", getNumEdges(Graph));

	

	shortestPath(0,5); //Runs on its own, shortest path for maze from ex_2.
	//you can change int goal to some other value to test different cases
	
	//For finding SCC:s in ex_3
	
	int n = 5;
	int** graph = createGraph(n);
	addDirectedEdge(graph, 0, 3);
	addDirectedEdge(graph, 0, 2);
	addDirectedEdge(graph, 1, 0);
	addDirectedEdge(graph, 2, 1);
	addDirectedEdge(graph, 3, 4);
	print(graph);
	SCC(graph);
	
	
	dijkstra(); //ex_4 Single-Source Shortest Paths, uses a graph from the introduction to algorithms book
	

	return 0;
}
int print(int** Graph)
{
	int i, j, n;
	printf("\nCurrent Graph:\n");
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{

	}
	n = i;
	printf("  ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", i);
		for (j = 0; j < n; j++)
		{

			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}