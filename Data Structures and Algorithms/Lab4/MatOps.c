#include "MatOps.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "utils.h"


int** createGraph(int n)
{
	int** graph = malloc(n * sizeof(int*)); //Allocating
	if (graph == NULL)
	{
		exit(1);
	}
	int i, j;
	for (i = 0; i < n+1; i++)
	{
		graph[i] = malloc(n * sizeof(int)); //Allocating
		if (graph[i] == NULL)
		{
			exit(2);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			graph[i][j] = 0; //declaring
			
			
		}
	}
	
	
	graph[0][n] = INT_MIN; //We cannot access size of rows and columns otherwise. Matrix is n+1 x n+1 sized
	graph[n][0] = INT_MIN;
	
	return graph;
}
int getNumVertices(int** Graph)
{
	int i, columns, rows;
	columns = 0; rows = 0;
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{

	}
	columns = i;
	
	return columns;
}
int getNumEdges(int** Graph)
{
	int i, j;
	int edges = 0;
	for (i = 0; Graph[i][0] != INT_MIN; i++)
	{
		for (j = 0; Graph[0][j] != INT_MIN; j++)
		{
			if (Graph[i][j] != 0)
			{
				edges++;
			}
		}

	}
	return edges;
}
int* getNeighbors(int** Graph, int node)
{
	int i, size;
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{
	}
	size = i;
	if (node > size - 1)
	{
		printf("\n%d is not in graph\n", node);
		return 0;
	}
	int* NeighBors = malloc(size * sizeof(int));
	if (NeighBors == NULL)
	{
		exit(4);
	}
	for (i = 0; i < size; i++)
	{
		NeighBors[i] = malloc(size * sizeof(int)); //Allocating
		if (NeighBors[i] == NULL)
		{
			exit(5);
		}
	}
	int* InNeighbors = getInNeighbors(Graph, node);
	int* OutNeighbors = getOutNeighbors(Graph, node);
	for (i = 0; i < size; i++)
	{
		NeighBors[i] = InNeighbors[i];
		if (OutNeighbors[i] != -1)
		{
			NeighBors[i] = OutNeighbors[i];
		}
	}
	return NeighBors;

}
int* getInNeighbors(int** Graph, int node)
{
	int i, size;
	
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{
	}
	size = i;
	if (node > size-1)
	{
		printf("\n%d is not in graph\n",node);
		return 0;
	}
	int* InNeighBors = malloc(size * sizeof(int));
	if (InNeighBors == NULL)
	{
		exit(6);
	}
	for (i = 0; i < size ; i++)
	{
		InNeighBors[i] = malloc(size * sizeof(int)); //Allocating
		if (InNeighBors[i] == NULL)
		{
			exit(7);
		}
		if (Graph[i][node] != 0)
		{

			InNeighBors[i] = i;
		}
		else
		{
			InNeighBors[i] = -1;
		}
	}
	return InNeighBors;
}
int* getOutNeighbors(int** Graph, int node)
{
	int i,  size;
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{
	}
	size = i;
	if (node > size - 1)
	{
		printf("\n%d is not in graph\n", node);
		return 0;
	}
	int* OutNeighBors = malloc(size * sizeof(int));
	if (OutNeighBors == NULL)
	{
		exit(8);
	}
	for (i = 0; i < size; i++)
	{
		OutNeighBors[i] = malloc(size * sizeof(int)); //Allocating
		if (OutNeighBors[i] == NULL)
		{
			exit(9);
		}
		if (Graph[node][i] != 0)
		{
			OutNeighBors[i] = i;
		}
		else
		{
			OutNeighBors[i] = -1;
		}
	}
	return OutNeighBors;

}
int** addDirectedEdge(int** Graph,int node1, int node2)
{
	int i, size;
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{
	}
	size = i;
	if (node1 > size - 1||node2>size-1)
	{
		printf("\n%d or %d is not in graph\n", node1,node2);
		return NULL;
	}
	if (Graph[node1][node2]==0)
	{
		Graph[node1][node2] = 1;
	}
	return Graph;
}
int** addUndirectedEdge(int** Graph, int node1, int node2)
{
	int i, size;
	for (i = 0; Graph[i][0] != INT_MIN; i++) //Acquiring size
	{
	}
	size = i;
	if (node1 > size - 1 || node2 > size - 1)
	{
		printf("\n%d or %d is not in graph\n", node1, node2);
		return NULL;
	}
	if (Graph[node1][node2] == 0)
	{
		Graph[node1][node2] = 1;
	}
	if (Graph[node2][node1] == 0)
	{
		Graph[node2][node1] = 1;
	}
	return Graph;
}
bool hasEdge(int** Graph,int node1, int node2)
{
	if (Graph[node1][node2] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



