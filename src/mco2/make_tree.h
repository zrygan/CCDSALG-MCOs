/**
 * balcita, v.
 * ganituen, z.
 * jimenez, j.
 *
 * CCDSALG, Project 2
 *
 * Header file for tree illustration of the BFS
 */

#ifndef MAKE_TREE
#define MAKE_TREE

#include "libraries.h"
#include "traversal.h"
#include "queue.h"

void printBFS(Node *startNode, String names[], int numNodes);

void make_tree(adjacency_matrix tree, int start_index);

#endif