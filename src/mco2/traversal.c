/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * C source file for DFS transveral of graph
*/

#include "traversal.h"

Node createNode(String val) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->val,val);
    node->neighbors = NULL;
    node->numNeighbors = 0;
    return *node;
}

// Function to add an edge between two nodes
void connectNodes(Node *node1, Node *node2) {
    node1->numNeighbors++; // increments the number of neighboring nodes
    node1->neighbors = (Node**)realloc(node1->neighbors, node1->numNeighbors * sizeof(Node*)); // reallocate the size of the node with the number of neighboring nodes 
                                                                                                    // and reserves a memory for the neighboring node that will be connected
    node1->neighbors[node1->numNeighbors - 1] = node2; // places the neighboring node to the former node
}

void visit_childnode(Node* current_node, bool* visited, String values[], int numNodes,int treenode_count){
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) { //Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0) { //If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }
    // If the current node does not exist in the values array or is already visited, and if the current node is not parent node, skip the node
    if (nodeIndex == -1 || visited[nodeIndex]) return;
    // && (strcmp(current_node->val,parent_node->val)==0)) return;
    // Mark the node as visited
    if(visited[nodeIndex]==false){
    //printf("%s visited\n", start_node->val);
    printf("%s ", current_node->val);  // Process the node and printing out the node
    visited[nodeIndex] = true;
    }
}

//function for bfs itself
void bfs(Node* current_node, bool* visited, String values[], int numNodes, int treenode_count) {
    // Find the index of the current node in the values array
    //char *nodes[MAX_WIDTH];
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) { //Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0) { //If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }

    // If the current node does not exist in the values array or is already visited, and if the current node is not parent node, skip the node
    //if ((nodeIndex == -1 || visited[nodeIndex])) return;
    //&& (start_node!=parent_node))
    if (nodeIndex == -1 || visited[nodeIndex])return;
    // Mark the node as visited
    if(visited[nodeIndex]==false){
    //printf("%s visited\n", start_node->val);
    printf("%s ", current_node->val);  // Process the node and printing out the node
    visited[nodeIndex] = true;
    }
    //ToDo: Add to the tree/store the sequence in a string array (Ung sinabi ni zhean)
    //if(start_node!=parent_node){
    //   strcpy(nodes[treeCount],node(parent_node->val,start_node->val)); // FIXME: @Viennbalcita
    //    treeCount++;
    //}
    /*
    //if the visited count is equal to the amount of neighbors of the parent node, move on
    if((visitedCount)==parent_node->numNeighbors){
        bfs(parent_node->neighbors[0], visited,-1, values, numNodes, parent_node, -1,treeCount);
    }
    //if it is not equal then move on to the next neighbor of the parent node
    else{
        bfs(parent_node->neighbors[index+1],visited,visitedCount, values, numNodes, treenode_count);
    }
    */

    String temp;
    strcpy(temp,current_node->neighbors[0]->val);
    //visit all the child nodes of the parent
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++) {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->numNeighbors; i++) {
            if (strcmp(temp,current_node->neighbors[i]->val) > 0 && !visited[i]) {
                strcpy(temp,current_node->neighbors[i]->val);
                small_index = i;
            }
        }
    printf("\nits going to: %s\n",current_node->neighbors[small_index]->val);
    printf("coming from: %s\n", current_node->val);
    visit_childnode(current_node->neighbors[small_index], visited, values, numNodes,treenode_count);
    }

    strcpy(temp,current_node->neighbors[0]->neighbors[0]->val);
    int j = 0;
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++,j++) {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->neighbors[small_index]->numNeighbors; i++) {
            if ((strcmp(temp,current_node->neighbors[small_index]->neighbors[i]->val) > 0 && !visited[i])) {
                strcpy(temp,current_node->neighbors[small_index]->neighbors[i]->val);
                small_index = i;
            }
        }
    bfs(current_node->neighbors[j]->neighbors[small_index], visited, values, numNodes,treenode_count);
    }
}


void BFStraversal(adjacency_matrix matrix, int start_index) {
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
    // Perform the bfs Traversal
    bfs(&nodeName[start_index],visited, matrix.names, matrix.vertex,0); 
    
}

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