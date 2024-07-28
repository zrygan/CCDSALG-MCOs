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
#include "queue.h"
#include "make_tree.h"

/*
    Goodness gracious can we use a standard code formatter
    to make the code monsters more manageable hahahaha
    - zry
*/

void sortneighbors(Node *Node)
{
    int i, j, min;
    String temp;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < Node->numNeighbors - 1; i++)
    {
        // Find the minimum element in the unsorted array
        min = i;
        for (j = i + 1; j < Node->numNeighbors; j++)
        {
            if (strcmp(Node->neighbors[j]->val, Node->neighbors[min]->val) < 0)
                min = j;
        }
        // Swap the found minimum element with the first element
        strcpy(temp, Node->neighbors[i]->val);
        strcpy(Node->neighbors[i]->val, Node->neighbors[min]->val);
        strcpy(Node->neighbors[min]->val, temp);
    }
}

void bfs(Node *start_node, bool *visited, String values[], int numNodes, int *tree_count, tree_node *tree)
{
    queue queue = createQueue(numNodes);
    enqueue(*start_node, &queue);
    //Do until all the nodes have been visited
    while (!queueEmpty(queue))
    {
        //Dequeue the next node to be visited
        Node *current_node = dequeue(&queue);

        //Search for the node index in the values array
        int nodeindex = -1;
        for (int i = 0; i < numNodes; i++)
        {
            if (strcmp(values[i], current_node->val) == 0)
            {
                nodeindex = i;
                break;
            }
        }
        // if the node exists and it is not visited yet then proceed
        if (nodeindex != -1 && !visited[nodeindex])
        {
            // Print the node to be visited and set it to visited in the visited array
            printf("%s ", current_node->val);
            visited[nodeindex] = true;
            // Sort the neighbors of the current node aphabetically
            sortneighbors(current_node);
            // try to implement queues to implement alphabetical ordering
            for (int i = 0; i < current_node->numNeighbors; i++)
            {
                int neighborindex = -1;
                for (int j = 0; j < numNodes; j++)
                { // Find the index of the neighbor in the values array and it is not visited yet
                    if ((strcmp(values[j], current_node->neighbors[i]->val)) == 0 && !visited[j])
                    {
                        neighborindex = j;
                    }
                }
                if (neighborindex != -1 && !visited[neighborindex])
                {                                                 // If the neighbor exists and is not visited
                    enqueue(*current_node->neighbors[i], &queue); // Enqueue the neighbor
                    // Add the neighbor to the tree
                    strcpy(tree[*tree_count].name, current_node->neighbors[i]->val);
                    strcpy(tree[*tree_count].root, current_node->val);
                    tree[*tree_count].distance = 1; // Distance from the parent node
                    (*tree_count)++;
                }
            }
        }
    }
}

void BFStraversal(adjacency_matrix matrix, int start_index, tree_node *tree)
{
    // Create nodes from the adjacency matrix
    Node nodeName[matrix.vertex];
    int tree_count = 0;
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
    // Visit the root node of the traversal
    // Add the root node to the tree
    strcpy(tree[tree_count].name, matrix.names[start_index]);
    strcpy(tree[tree_count].root, ""); // Set the root of the tree
    tree[tree_count].distance = 0; // Distance from the root node
    tree_count++;

    // Perform the bfs Traversal
    bfs(&nodeName[start_index], visited, matrix.names, matrix.vertex, &tree_count, tree);
}