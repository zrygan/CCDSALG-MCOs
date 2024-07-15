/**
 * balcita, v.
 * ganituen, z.
 * jimenez, j.
 * 
 * CCDSALG, Project 2
 * 
 * header file for bfs transveral of graph
*/

#ifndef TRANSVERAL_BFS
#define TRANSVERAL_BFS

#include "libraries.h"
#include "adjacency_matrix.h"
#include "make_tree.h"


typedef struct BFSNode
{
    String val;
    struct BFSNode** neighbors;
    int numNeighbors;
} BFSNode;

DFSNode createDFSNode(String val);

void connectNodes(BFSNode *node1, BFSNode *node2);

void bfs(BFSNode* start_node, bool* visited, int visitedCount, String values[], int numNodes, BFSNode* parent_node, int index, int treeCount);

void BFStraversal(adjacency_matrix matrix, int start_index);

#endif