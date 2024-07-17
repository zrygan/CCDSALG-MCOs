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
void dfs(Node* start_node, bool* visited, String values[], int numNodes) {
    // Find the index of the current node in the values array
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) {
        if (strcmp(values[i], start_node->val) == 0) {
            nodeIndex = i;
            break;
        }
    }

    // If the current node does not exist in the values array or is already visited, skip the node
    if (nodeIndex == -1 || visited[nodeIndex]) return;

    // Mark the node as visited
    visited[nodeIndex] = true;
    printf("%s ", start_node->val);  // Process the node

    
    String temp;
    strcpy(temp,start_node->neighbors[0]->val);

    // Recur for all the vertices adjacent to this vertex
    for (int small_index = 0; small_index < start_node->numNeighbors; small_index++) {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < start_node->numNeighbors; i++) {
            if (strcmp(temp,start_node->neighbors[i]->val) > 0 && !visited[i]) {
                strcpy(temp,start_node->neighbors[i]->val);
                small_index = i;
            }
        }
        dfs(start_node->neighbors[small_index], visited, values, numNodes); 
    }
}

void DFSTraversal(adjacency_matrix matrix, int start_index) {
    // Create nodes from the adjacency matrix
    Node nodeName[matrix.vertex];
    for (int i = 0; i < matrix.vertex; i++) {
        nodeName[i] = createNode(matrix.names[i]);
    }

    // Connect the nodes
    for (int row = 0; row < matrix.vertex; row++)
    {
        for (int col = 0; col < matrix.vertex; col++)
        {
            if (matrix.matrix[row][col]) {
                connectNodes(&nodeName[row], &nodeName[col]);
            }
        }
    }

    // Turn all the nodes to false for each vertex
    bool visited[matrix.vertex]; // FIXME: IF EVER MAYBE I CAN JUST ADD A BOOLEAN IN THE STRUCT ITSELF
    for (int i = 0; i < matrix.vertex; i++) {
        visited[i] = false;
    }

    // Perform the DFS Traversal
    dfs(&nodeName[start_index],visited, matrix.names, matrix.vertex); 
}