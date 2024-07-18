/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C source file for the bfs implementation
 */

#include "bfs.h"

// function for bfs itself
void bfs(Node *current_node, bool *visited, String values[], int numNodes, int visited_count, String tree_nodes[], int tree_count)
{
    // Find the index of the current node in the values array
    int nodeIndex = -1;
    for (int i = 0; i < numNodes; i++)
    { // Go through all the nodes
        if (strcmp(values[i], current_node->val) == 0)
        { // If the name[i] is found to be same as the node continue with same index
            nodeIndex = i;
            break;
        }
    }
    // If the node does not exist, return
    if (nodeIndex == -1)
        return;
    // If all the nodes have been visited, return
    if (visited_count > numNodes)
    {
        return;
    }
    String temp;
    int count = 0;
    strcpy(temp, current_node->neighbors[0]->val);
    // visit all the neighboring nodes of the current node in alphabetical order
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++)
    {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->numNeighbors; i++)
        {
            if (strcmp(temp, current_node->neighbors[i]->val) > 0 && !visited[i])
            {
                strcpy(temp, current_node->neighbors[i]->val);
                small_index = i;
            }
        }
        visit_node(current_node->neighbors[small_index], visited, values, numNodes);
        // this is not working
        // TODO: tree implementation
        String home;
        String dest;
        String temp;
        if (current_node != current_node->neighbors[small_index])
        {
            strcpy(home, current_node->val);
            strcpy(dest, current_node->neighbors[small_index]->val);
            strcpy(temp, node(home, dest));
            if (checkTreeNode(tree_nodes, tree_count, temp) == true || tree_count == 0)
            {
                strcpy(tree_nodes[tree_count], temp);
                // printf("%s\n", tree_nodes[tree_count]);
                tree_count++;
            }
        }
        count++;
        visited_count++;
        // If there are still neighboring nodes to visit, search thru neighbors again
        if (count < current_node->numNeighbors)
        {
            small_index = -1;
        }
    }
    count = 0;
    strcpy(temp, current_node->neighbors[0]->val);
    for (int small_index = 0; small_index < current_node->numNeighbors; small_index++)
    {
        // Get the unvisited lowest vertex ID
        for (int i = 0; i < current_node->numNeighbors; i++)
        {
            if (strcmp(temp, current_node->neighbors[i]->val) > 0 && !visited[i])
            {
                strcpy(temp, current_node->neighbors[i]->val);
                small_index = i;
            }
        }
        // Recur BFS on the neighboring nodes
        bfs(current_node->neighbors[small_index], visited, values, numNodes, visited_count, tree_nodes, tree_count);
        count++;
        if ((visited_count == numNodes) == 1)
            return;
        if (count < current_node->numNeighbors)
        {
            small_index = -1;
        }
    }
}

void BFStraversal(adjacency_matrix matrix, int start_index)
{
    // Create nodes from the adjacency matrix
    String tree_nodes[MAX_VERTICES];
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
    bool visited[matrix.vertex]; // FIXME: IF EVER MAYBE I CAN JUST ADD A BOOLEAN IN THE STRUCT ITSELF
    for (int i = 0; i < matrix.vertex; i++)
    {
        visited[i] = false;
    }
    // Visit the root node of the traversa;
    visit_node(&nodeName[start_index], visited, matrix.names, matrix.vertex);
    // Perform the bfs Traversal
    bfs(&nodeName[start_index], visited, matrix.names, matrix.vertex, 1, tree_nodes, 0);
}
