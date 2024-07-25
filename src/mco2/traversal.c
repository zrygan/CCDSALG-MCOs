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

Node createNode(String val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->val, val);
    node->neighbors = NULL;
    node->numNeighbors = 0;
    return *node;
}

// Function to add an edge between two nodes
void connectNodes(Node *node1, Node *node2)
{
    node1->numNeighbors++;                                                                       // increments the number of neighboring nodes
    node1->neighbors = (Node **)realloc(node1->neighbors, node1->numNeighbors * sizeof(Node *)); // reallocate the size of the node with the number of neighboring nodes
                                                                                                 // and reserves a memory for the neighboring node that will be connected
    node1->neighbors[node1->numNeighbors - 1] = node2;                                           // places the neighboring node to the former node
}

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
