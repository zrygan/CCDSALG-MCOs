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

void visit_node(Node* current_node, bool* visited, String values[], int numNodes){
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) { //Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0) { //If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }
    // If the current node does not exist in the values array or is already visited, and if the current node is not parent node, skip the node
    if (nodeIndex == -1 || visited[nodeIndex]) return;
    // Mark the node as visited
    if(visited[nodeIndex]==false){
    printf("%s ", current_node->val);  // Process the node and printing out the node
    visited[nodeIndex] = true;
    }
}

//function for bfs itself
void bfs(Node* current_node, bool* visited, String values[], int numNodes, int visited_count,String tree_nodes[],int tree_count) {
    // Find the index of the current node in the values array
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++) { //Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0) { //If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }
    //If the node does not exist, return
    if (nodeIndex == -1)return;
    //If all the nodes have been visited, return
    if (visited_count>numNodes){
        return;
    }
    String temp;
    int count = 0;
    strcpy(temp,current_node->neighbors[0]->val);
    //visit all the neighboring nodes of the current node in alphabetical order
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++) {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->numNeighbors; i++) {
            if (strcmp(temp,current_node->neighbors[i]->val) > 0 && !visited[i]) {
                strcpy(temp,current_node->neighbors[i]->val);
                small_index = i;
            }
        }
    visit_node(current_node->neighbors[small_index], visited, values, numNodes);
    count++;
    //this is not working
    //TODO: tree implementation
    if(current_node!=current_node->neighbors[small_index]){
        strcpy(tree_nodes[tree_count],node(current_node->val,current_node->neighbors[small_index]->val)); // 
        tree_count++;
    }
    visited_count++;
    //If there are still neighboring nodes to visit, search thru neighbors again
    if (count<current_node->numNeighbors){
        small_index = -1;
    }
    }
    count = 0;
    strcpy(temp,current_node->neighbors[0]->val);
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++) {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->numNeighbors; i++) {
            if (strcmp(temp,current_node->neighbors[i]->val) > 0 && !visited[i]) {
                strcpy(temp,current_node->neighbors[i]->val);
                small_index = i;
            }
        }
    //Recur BFS on the neighboring nodes
    bfs(current_node->neighbors[small_index], visited, values, numNodes,visited_count,tree_nodes,tree_count);
    count++;
    if ((visited_count==numNodes)==1)return;
    if (count<current_node->numNeighbors){
        small_index = -1;
    }
    }
}


void BFStraversal(adjacency_matrix matrix, int start_index) {
    // Create nodes from the adjacency matrix
    String tree_nodes[MAX_WIDTH];
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
    //Visit the root node of the transversal
    visit_node(&nodeName[start_index],visited, matrix.names, matrix.vertex);
    // Perform the bfs Traversal
    bfs(&nodeName[start_index],visited, matrix.names, matrix.vertex,1,tree_nodes,0); 
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