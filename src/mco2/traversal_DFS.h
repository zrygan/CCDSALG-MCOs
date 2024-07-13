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
 * a structure of the DFS Nodes
 * 
 * @fields: val :   String  :   the value that the node contains
 * @fields: neighbors   :   DFSNode**   : a self-reference of the struct containing its neighboring nodes
 * @fields: numNeighbors    :   int     : contains the number of neighbors
 * 
 * @author Jaztin Jimenez
 */
typedef struct DFSNode
{
    String val;
    struct DFSNode** neighbors;
    int numNeighbors;
} DFSNode;

/**
 * creates the DFS Nodes
 * 
 * @param val   :   String  :   the value that the node contains
 * 
 * @return DFSNode if the function is executed
 * 
 * @author Jaztin Jimenez
 */
DFSNode createDFSNode(String val);

/**
 * connects the DFS Nodes
 * 
 * @param node1 :   DFSNode*    :   contains the former node that will be connected with the latter node
 * @param node2 :   DFSNode*    :   contains the latter node that will be connected with the former node
 * 
 * @author Jaztin Jimenez
 */
void connectNodes(DFSNode* node1, DFSNode* node2);

/**
 * executes the DFS Traversal
 * 
 * @param start_node    :   DFSNode*    :   contains the starting node for the DFS Traversal
 * @param visited   :   bool*   :   contains an array of booleans that checks if the node has been visited or not
 * @param names :   String[]    :   contains the values of the nodes
 * @param numNodes  :   int     :   the total number of nodes in the matrix
 * 
 * @author Jaztin Jimenez
 */
void dfs(DFSNode* start_node, bool* visited, String values[], int numNodes);

/**
 * executes the formalities for the DFS Traversal // FIXME: MEDYO DI KO GUSTO HOW I DID THIS WBSJSAHSAH
 * 
 * @param matrix    :   adjacency_matrix    :   contains the adjacency matrix to be traversed
 * @param start_index   :   int             :   contains the node to start the traversing with
 * 
 * @author Jaztin Jimenez
 */
void DFSTraversal(adjacency_matrix matrix, int start_index);

#endif