#pragma once
#include <stdbool.h>
//Creates a n x n graph with all 0:s and returns it
int** createGraph(int n);
//Takes a n x n Graph and returns an integer with number of vertices
int getNumVertices(int** Graph);
//Takes a n x n Graph and returns an integer with number of edges
int getNumEdges(int** Graph);
//From Graph, finds all nodes neighboring selected node
int* getNeighbors(int** Graph, int node);
//From Graph, finds all nodes that selected node is connected towards
int* getOutNeighbors(int** Graph, int node);
//From Graph, finds all nodes connected TOWARDS selected node  in a directed graph
int* getInNeighbors(int** Graph, int node);
//In Graph, connects node1 to node2
int** addDirectedEdge(int** Graph,int node1, int node2);
//In Graph, connects node1 to node2, AND connects node2 to node1
int** addUndirectedEdge(int** Graph, int node1, int node2);
//In Graph, checks if node1 is connected to node2
bool hasEdge(int** Graph, int node1, int node2);





