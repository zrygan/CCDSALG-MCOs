/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * C source code for BFS transveral of graph
*/

#include "traversal_BFS.h"

//function to create bfs node
BFSNode createBFSNode(String val) {
    BFSNode* node = (BFSNode*)malloc(sizeof(BFSNode)); //Initializes a bfs node
    strcpy(node->val,val); //copies the name(val) to the node
    node->neighbors = NULL;//initializes the neighbor of the node to be NULL
    node->numNeighbors = 0;//initializes the number of neighbors of the node to be zero
    return *node;//returns the pointer to the node
}

// Function to add an edge between two nodes
void connectNodes(BFSNode *node1, BFSNode *node2) {
    node1->numNeighbors++; // increments the number of neighboring nodes
    node1->neighbors = (BFSNode**)realloc(node1->neighbors, node1->numNeighbors * sizeof(BFSNode*)); // reallocate the size of the node with the number of neighboring nodes 
                                                                                                    // and reserves a memory for the neighboring node that will be connected
    node1->neighbors[node1->numNeighbors - 1] = node2; // places the neighboring node to the former node
}

//function for bfs itself
void bfs(BFSNode* start_node, bool* visited, int visitedCount, String values[], int numNodes, BFSNode* parent_node, int index, int treeCount) {
    // Find the index of the current node in the values array
    char *nodes[MAX_WIDTH];
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) { //Go through all the nodes
        if (strcmp(values[i], start_node->val) == 0) { //If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }

    // If the current node does not exist in the values array or is already visited, and if the current node is not parent node, skip the node
    if ((nodeIndex == -1 || visited[nodeIndex]) && (start_node!=parent_node)) return;

    // Mark the node as visited
    if(visited[nodeIndex]==false){
        visited[nodeIndex] = true;
        visitedCount++;
        printf("%s ", start_node->val);  // Process the node and printing out the node
        //ToDo: Add to the tree/store the sequence in a string array (Ung sinabi ni zhean)
        if(start_node!=parent_node){
            strcpy(nodes[treeCount],node(parent_node->val,start_node->val));
            treeCount++;
        }
    }

    //if the visited count is equal to the amount of neighbors of the parent node, move on
    if((visitedCount)==parent_node->numNeighbors){
        bfs(parent_node->neighbors[0], visited,-1, values, numNodes, parent_node, -1,treeCount);
    }
    //if it is not equal then move on to the next neighbor of the parent node
    else{
        bfs(parent_node->neighbors[index+1],visited,visitedCount, values, numNodes, parent_node, index+1,treeCount);
    }
}


void bfstraversal(adjacency_matrix matrix, int start_index) {
    // Create nodes from the adjacency matrix
    BFSNode nodeName[matrix.vertex];
    for (int i = 0; i < matrix.vertex; i++) {
        nodeName[i] = createBFSNode(matrix.names[i]);
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
    bfs(&nodeName[start_index],visited, -1, matrix.names, matrix.vertex, &nodeName[start_index], -1, 0); 
    
}