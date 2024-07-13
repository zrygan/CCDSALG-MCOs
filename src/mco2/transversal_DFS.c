/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * C source file for DFS transveral of graph
*/

#include "transversal_DFS.h"

DFSNode createDFSNode(String val) {
    DFSNode* node = (DFSNode*)malloc(sizeof(DFSNode));
    strcpy(node->val,val);
    node->neighbors = NULL;
    node->numNeighbors = 0;
    return *node;
}

// Function to add an edge between two nodes
void addEdge(DFSNode *node1, DFSNode *node2) {
    node1->numNeighbors++;
    node1->neighbors = (DFSNode**)realloc(node1->neighbors, node1->numNeighbors * sizeof(DFSNode*));
    node1->neighbors[node1->numNeighbors - 1] = node2;
}

// DFS function
void dfs(DFSNode* node, bool* visited, String nodes[], int numNodes) {
    // Find the index of the current node in the nodes array
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) {
        if (strcmp(nodes[i], node->val) == 0) {
            nodeIndex = i;
            break;
        }
    }

    if (nodeIndex == -1 || visited[nodeIndex]) return;

    // Mark the node as visited
    visited[nodeIndex] = true;
    printf("%s ", node->val);  // Process the node

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < node->numNeighbors; i++) {
        dfs(node->neighbors[i], visited, nodes, numNodes);
    }
}

void DFSTraversal(adjacency_matrix matrix) {
    // Create nodes from the adjacency matrix
    DFSNode nodeName[matrix.vertex];
    for (int i = 0; i < matrix.vertex; i++) {
        nodeName[i] = createDFSNode(matrix.names[i]);
    }

    // Connect the nodes
    for (int row = 0; row < matrix.vertex; row++)
    {
        for (int col = 0; col < matrix.vertex; col++)
        {
            if (matrix.matrix[row][col]) {
                addEdge(&nodeName[row], &nodeName[col]);
            }
        }
    }

    // Turn all the nodes to false for each vertex
    bool visited[matrix.vertex]; // FIXME: IF EVER MAYBE I CAN JUST ADD A BOOLEAN IN THE STRUCT ITSELF
    for (int i = 0; i < matrix.vertex; i++) {
        visited[i] = false;
    }

    // Perform the DFS Traversal
    dfs(&nodeName[2],visited, matrix.names, matrix.vertex); // FIXME: DEBUGGING ONLY!! REMOVE NODENAME. IT STARTS ON CLARK
}