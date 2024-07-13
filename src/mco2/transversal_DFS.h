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

/**
 * a structure of the adjacency_matrix implementation
 * 
 * @fields: matrix[][] the adjency matrix
 * @fields: vertex the number of vertices in the matrix 
 * 
 * @author Jaztin Jimenez
 */
typedef struct
{
    char* val;
    struct DFSNode** neighbors;
    int numNeighbors;
} DFSNode;

DFSNode* createDFSNode(char* val);

void addEdge(DFSNode* node1, DFSNode* node2);


#endif