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
 *
 * @authors Vienn Balcita, Jaztin Jimenez
 */
void sortneighbors(Node *Node);

/**
 * Executes the BFS traversal algorithm
 *
 * @param start_node The starting node for the BFS traversal
 * @param visited contains an array of booleans that checks if the node has been visited or not
 * @param values contains the values of the nodes
 * @param numNodes the total number of nodes in the matrix
 * @param tree_count the number of BFS traversal relatioins
 * @param tree the BFS tree structure array
 * @param m the output file
 *
 * @authors Vienn Balcita, Jaztin Jimenez, Zhean Ganituen (BFS Tree, File I/O)
 */
void bfs(Node *start_node, bool *visited, String values[], int numNodes, int *tree_count, tree_node *tree, FILE *m);

/**
 * executes the formalities for the BFS Traversal
 *
 * @param matrix contains the adjacency matrix to be traversed
 * @param start_index contains the node to start the traversing with
 * @param tree the BFS tree structure array
 * @param m the output file
 *
 * @authors Vienn Balcita, Jaztin Jimenez, Zhean Ganituen (BFS Tree, File I/O)
 */
void BFStraversal(adjacency_matrix matrix, int start_index, tree_node *tree, FILE *m);

#endif