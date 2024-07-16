/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * Header file for transveral of graph
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

void bfs(Node* start_node, bool* visited, int visitedCount, String values[], int numNodes, Node* parent_node, int index, int treeCount);

void BFStraversal(adjacency_matrix matrix, int start_index);


#endif