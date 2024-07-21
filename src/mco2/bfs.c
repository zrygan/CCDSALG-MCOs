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

void bfs(Node *start_node, bool *visited, String values[], int numNodes, String tree_nodes[], int *tree_count)
{
    queue queue = createQueue(numNodes);
    String home;
    String dest;
    enqueue(*start_node, &queue);

    while (!queueEmpty(queue))
    {
        Node *current_node = dequeue(&queue);
        if (!(strcmp(home, "") == 0) && (*tree_count < numNodes - 1))
        {
            strcpy(dest, current_node->val);
            if (!(strcmp(home, dest) == 0))
            {
                char *temp = node(home, dest);
                strcpy(tree_nodes[*tree_count], temp);
                (*tree_count)++;
            }
        }
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
            printf("%s ", current_node->val);
            visited[nodeindex] = true;
            strcpy(home, current_node->val);
            sortneighbors(current_node);
            // try to implement queues to implement alphabetical ordering
            for (int i = 0; i < current_node->numNeighbors; i++)
            {
                int neighborindex = -1;
                for (int j = 0; j < numNodes; j++)
                { // Find the index of the neighbor in the values array
                    if ((strcmp(values[j], current_node->neighbors[i]->val)) == 0 && !visited[j])
                    {
                        neighborindex = j;
                    }
                }
                if (neighborindex != -1 && !visited[neighborindex])
                {                                                 // If the neighbor exists and is not visited
                    enqueue(*current_node->neighbors[i], &queue); // Enqueue the neighbor
                }
            }
        }
    }
}

void BFStraversal(adjacency_matrix matrix, int start_index)
{
    // Create nodes from the adjacency matrix
    String tree_nodes[MAX_VERTICES];
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
    // Visit the root node of the traversa;
    // Perform the bfs Traversal
    bfs(&nodeName[start_index], visited, matrix.names, matrix.vertex, tree_nodes, &tree_count);

    // Checking output for BFS tree
    /*
    printf("\n");
    for(int i = 0; i < matrix.vertex; i++){
        printf("%s\n",tree_nodes[i]);
    }
    */
}
