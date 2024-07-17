/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2 
 * 
 * User-defined header file for the DFS implementation.
*/

#ifndef DFS
#define DFS

#include "libraries.h"
#include "traversal.h"

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
void dfs(Node* start_node, bool* visited, String values[], int numNodes);

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
