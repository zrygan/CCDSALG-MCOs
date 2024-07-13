/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * Header file for DFS transveral of graph
*/

#ifndef TRANSVERSAL_DFS
#define TRANSVERSAL_DFS


#include "libraries.h"
#include "adjacency_matrix.h"

/**
 * 
 * @author Jaztin Jimenez
 */
typedef struct
{
    String val;
    struct DFSNode** neighbors;
    int numNeighbors;
} DFSNode;

DFSNode* createDFSNode(String val);

void addEdge(DFSNode* node1, DFSNode* node2);

void dfs(DFSNode* node, bool* visited, char* nodes[], int numNodes);

#endif