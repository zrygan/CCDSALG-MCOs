/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * Header file for the bfs implementation
 */

#ifndef BFS
#define BFS

#include "libraries.h"
#include "traversal.h"

void sortneighbors(Node *Node);
void bfs(Node *current_node, bool *visited, String values[], int numNodes, String tree_nodes[], int *tree_count);

void BFStraversal(adjacency_matrix matrix, int start_index);

#endif