/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C source file for trasveral helper functions
 */

#include "traversal.h"

/**
 * creates the nodes
 *
 * @param val the value that the node contains
 *
 * @return DFSNode if the function is executed
 *
 * @author Jaztin Jimenez
 */
Node createNode(String val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->val, val);
    node->neighbors = NULL;
    node->numNeighbors = 0;
    return *node;
}

/**
 * connects the DFS Nodes
 *
 * @param node1 contains the former node that will be connected with the latter node
 * @param node2 contains the latter node that will be connected with the former node
 *
 * @author Jaztin Jimenez
 */
void connectNodes(Node *node1, Node *node2)
{
    node1->numNeighbors++;                                                                       // increments the number of neighboring nodes
    node1->neighbors = (Node **)realloc(node1->neighbors, node1->numNeighbors * sizeof(Node *)); // reallocate the size of the node with the number of neighboring nodes
                                                                                                 // and reserves a memory for the neighboring node that will be connected
    node1->neighbors[node1->numNeighbors - 1] = node2;                                           // places the neighboring node to the former node
}

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
void visit_node(Node *current_node, bool *visited, String values[], int numNodes)
{
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++)
    { // Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0)
        { // If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }
    // If the current node does not exist in the values array or is already visited, and if the current node is not parent node, skip the node
    if (nodeIndex == -1 || visited[nodeIndex])
        return;
    // Mark the node as visited
    if (visited[nodeIndex] == false)
    {
        printf("%s ", current_node->val); // Process the node and printing out the node
        visited[nodeIndex] = true;
    }
}
