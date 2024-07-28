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
#include "make_tree.h"

/**
 * Alphabetically sorts the neighbors of the given node
 * 
 * @param Node : Node* : The node whose neighobors are to be sorted
 */
void sortneighbors(Node *Node);
/**
 * Executes the BFS traversal algorithm
 * 
 * @param current_node : Node* : The starting node for the BFS traversal
 * @param visited : bool*: contains an array of booleans that checks if the node has been visited or not
 * @param names :   String[]    :   contains the values of the nodes
 * @param numNodes  :   int     :   the total number of nodes in the matrix
 * @param tree_count : int* : the number of BFS traversal relatioins
 */
void bfs(Node *start_node, bool *visited, String values[], int numNodes, int *tree_count, tree_node *tree);

/**
 * executes the formalities for the BFS Traversal
 *
 * @param matrix    :   adjacency_matrix    :   contains the adjacency matrix to be traversed
 * @param start_index   :   int             :   contains the node to start the traversing with
 *
 */
void BFStraversal(adjacency_matrix matrix, int start_index, tree_node *tree);

#endif