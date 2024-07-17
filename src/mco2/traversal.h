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
#include "make_tree.h"

/**
 * a structure of the DFS Nodes
 * 
 * @fields: val :   String  :   the value that the node contains
 * @fields: neighbors   :   DFSNode**   : a self-reference of the struct containing its neighboring nodes
 * @fields: numNeighbors    :   int     : contains the number of neighbors
 * 
 * @author Jaztin Jimenez
 */
typedef struct Node
{
    String val;
    struct Node** neighbors;
    int numNeighbors;
} Node;

/**
 * creates the nodes
 * 
 * @param val   :   String  :   the value that the node contains
 * 
 * @return DFSNode if the function is executed
 * 
 * @author Jaztin Jimenez
 */
Node createNode(String val);

/**
 * connects the DFS Nodes
 * 
 * @param node1 :   DFSNode*    :   contains the former node that will be connected with the latter node
 * @param node2 :   DFSNode*    :   contains the latter node that will be connected with the former node
 * 
 * @author Jaztin Jimenez
 */
void connectNodes(Node* node1, Node* node2);

void visit_node(Node* current_node, bool* visited, String values[], int numNodes);

#endif