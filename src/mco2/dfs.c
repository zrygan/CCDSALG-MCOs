/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C source file for the dfs implementation
 */

#include "dfs.h"

// DFS function
void dfs(Node *start_node, bool *visited, String values[], int numNodes, FILE *m)
{
    // Find the index of the current node in the values array
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++)
    {
        if (strcmp(values[i], start_node->val) == 0)
        {
            nodeIndex = i;
            break;
        }
    }

    // If the current node does not exist in the values array or is already visited, skip the node
    if (nodeIndex == -1 || visited[nodeIndex])
        return;

    // Mark the node as visited
    visited[nodeIndex] = true;
    fprintf(m, "%s ", start_node->val); // Process the node

    // Find the unvisited neighbor with the lowest value
    while (1)
    {
        Node *lowest_neighbor = NULL;
        for (int i = 0; i < start_node->numNeighbors; i++)
        {
            Node *neighbor = start_node->neighbors[i];
            int neighborIndex = -1;
            for (int j = 0; j < numNodes; j++)
            {
                if (strcmp(values[j], neighbor->val) == 0)
                {
                    neighborIndex = j;
                    break;
                }
            }
            if (neighborIndex != -1 && !visited[neighborIndex])
            {
                if (lowest_neighbor == NULL || strcmp(neighbor->val, lowest_neighbor->val) > 0)
                {
                    lowest_neighbor = neighbor;
                }
            }
        }

        if (lowest_neighbor == NULL)
            break;

        dfs(lowest_neighbor, visited, values, numNodes, m);
    }
}

void DFSTraversal(adjacency_matrix matrix, int start_index, FILE *m)
{
    // Create nodes from the adjacency matrix
    Node nodeName[matrix.vertex];
    for (int i = 0; i < matrix.vertex; i++)
    {
        nodeName[i] = createNode(matrix.names[i]);
    }

    // Connect the nodes
    for (int row = 0; row < matrix.vertex; row++)
    {
        for (int col = 0; col < matrix.vertex; col++)
        {
            if (matrix.matrix[row][col])
            {
                connectNodes(&nodeName[row], &nodeName[col]);
            }
        }
    }

    // Turn all the nodes to false for each vertex
    bool visited[matrix.vertex];
    for (int i = 0; i < matrix.vertex; i++)
    {
        visited[i] = false;
    }

    // Perform the DFS Traversal
    dfs(&nodeName[start_index], visited, matrix.names, matrix.vertex, m);
}