//
//  Graph.h
//  practice_programming
//
//  Created by Vishal Srivastav on 2/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "LinkList.h"


// APIs listed here create the graph node with vertex value same as the node number

typedef struct Graph {
    Node** adjacencyList;
    int numVertex;
    bool* visited;
    int* preVisit;
    int* postVisit;
    int* dist;
    int* prevNode;
} Graph;

Graph* CreateGraph(int numVertices);
void   AddEdgesUndirected(Graph* graph, int src, int dest, int len);
void   PrintAdjacencyList(Graph* graph);
void   AddEdgesDirected(Graph* graph, int src, int dest, int len);

#include "DFS.h"
#include "BFS.h"

#endif /* Graph_h */
