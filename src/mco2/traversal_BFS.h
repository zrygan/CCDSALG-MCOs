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

#endif