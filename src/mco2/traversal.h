/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * Header file for trasveral helper functions
 */

#ifndef TRAVERSAL
#define TRAVERSAL

#include "libraries.h"
#include "adjacency_matrix.h"

/**
 * a structure of the DFS Nodes
 *
 * @fields:
 *  {val} the value that the node contains
 *  {neighbors} a self-reference of the struct containing its neighboring nodes
 *  {numNeighbors} contains the number of neighbors
 *
 * @author Jaztin Jimenez
 */
typedef struct Node
{
    String val;
    struct Node **neighbors;
    int numNeighbors;
} Node;

/**
 * creates the nodes
 *
 * @param val the value that the node contains
 *
 * @return DFSNode if the function is executed
 *
 * @author Jaztin Jimenez
 */
Node createNode(String val);

/**
 * connects the DFS Nodes
 *
 * @param node1 contains the former node that will be connected with the latter node
 * @param node2 contains the latter node that will be connected with the former node
 *
 * @author Jaztin Jimenez
 */
void connectNodes(Node *node1, Node *node2);

/**
 * visits a node
 *
 * @param current_node the current node
 * @param visited checks if the node is visited
 * @param values the nodes
 * @param numNodes the number of nodes
 *
 * @author Jaztin Jimenez
 */
void visit_node(Node *current_node, bool *visited, String values[], int numNodes);

#endif