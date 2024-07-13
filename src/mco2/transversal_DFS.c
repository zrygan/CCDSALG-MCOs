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

DFSNode* createDFSNode(char* val) {
    DFSNode* node = (DFSNode*)malloc(sizeof(DFSNode));
    node->val = strdup(val);  // Allocate and copy the string value
    node->neighbors = NULL;
    node->numNeighbors = 0;
    return node;
}

// Function to add an edge between two nodes
void addEdge(DFSNode* node1, DFSNode* node2) {
    node1->numNeighbors++;
    node1->neighbors = (DFSNode**)realloc(node1->neighbors, node1->numNeighbors * sizeof(DFSNode*));
    node1->neighbors[node1->numNeighbors - 1] = node2;
}

// DFS function
void dfs(DFSNode* node, bool* visited, char* nodes[], int numNodes) {
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