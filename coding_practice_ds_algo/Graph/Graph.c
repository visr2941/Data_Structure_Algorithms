//
//  Graph.c
//  practice_programming
//
//  Created by Vishal Srivastav on 2/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "Graph.h"

Graph* CreateGraph(int numVertices)
{
    Graph* graph = (Graph *)malloc(sizeof(Graph));
    
    graph->numVertex = numVertices;
    graph->adjacencyList = (Node** )malloc(sizeof(numVertices*sizeof(Node*)));
    graph->visited   = NULL;
    graph->preVisit  = NULL;
    graph->postVisit = NULL;
    graph->dist      = NULL;
    graph->prevNode  = NULL;
    
    for(int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void AddEdgesUndirected(Graph* graph, int src, int dest, int len)
{
    if(src >= graph->numVertex || dest >= graph->numVertex)
    {
        printf("WARNING: src or des is greater than the number of vertices!");
        return;
    }
    
    Node* newNodeSrc = CreateNode(dest); // this will the link list node with data = src
    newNodeSrc->next =  graph->adjacencyList[src];
    newNodeSrc->val  = len;
    graph->adjacencyList[src] = newNodeSrc;

    Node* newNodeDst = CreateNode(src); // this will the link list node with data = src
    newNodeDst->next =  graph->adjacencyList[dest];
    newNodeDst->val  = len;
    graph->adjacencyList[dest] = newNodeDst;
}

void AddEdgesDirected(Graph* graph, int src, int dest, int len)
{
    if(src >= graph->numVertex || dest >= graph->numVertex)
    {
        printf("WARNING: src or des is greater than the number of vertices!");
        return;
    }
    
    Node* newNodeSrc = CreateNode(dest); // this will the link list node with data = src
    newNodeSrc->next =  graph->adjacencyList[src];
    newNodeSrc->val  = len;
    graph->adjacencyList[src] = newNodeSrc;
}

void PrintAdjacencyList(Graph* graph)
{
    for(int i = 0; i < graph->numVertex; i++)
    {
        Node* temp = graph->adjacencyList[i];
        
        printf("Node s%d is connected to", i);
        
        while(temp != NULL)
        {
            printf(" %d", temp->val);
            temp = temp->next;
        }
        printf(".\n");
    }
}

