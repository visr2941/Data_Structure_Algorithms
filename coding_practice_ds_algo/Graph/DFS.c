//
//  DFS.c
//  practice_programming
//
//  Created by Vishal Srivastav on 2/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "DFS.h"

/*
 The DFS algorithm works as follows:

 - Start by putting any one of the graph's vertices on top of a stack.
 - Take the top item of the stack and add it to the visited list.
 - Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the top of stack.
 - Keep repeating steps 2 and 3 until the stack is empty.
 
*/

void DFS_Util(Graph* graph, int startNode)
{
    //base class
    if(graph->visited[startNode] == 1)
        return;
    
    graph->visited[startNode] = 1;
    printf("%d->", startNode);
    
    // choose
    Node* nodeChosen = graph->adjacencyList[startNode];

    // explore
    while(nodeChosen != NULL)
    {
        DFS_Util(graph, nodeChosen->val);
        nodeChosen = nodeChosen->next;
    }
}

void DFS(Graph* graph, int startNode)
{
    memset((void *)graph->visited, 0, graph->numVertex);
    
    DFS_Util(graph, startNode);
    printf("END\n");

    memset(graph->visited, 0, graph->numVertex);
}
