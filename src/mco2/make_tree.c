/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C file of the tree illustration of the BFS.
 */

#include "make_tree.h"

// for ascii art (remove if not needed)
#define _DASH 196 // ┐
#define _ROOT 191 // ─
#define _VERT 124 // │
#define _LAST 192 // └
#define _SPLT 195 // ├

void printBFS(Node *startNode, String names[], int numNodes) {
    bool visited[numNodes];
    bool islast[numNodes];
    for(int i = 0; i < numNodes;i++){
        islast[i] = false;
    }
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    queue Queue = createQueue(numNodes);
    enqueue(*startNode, &Queue);

    int depth[numNodes];
    for (int i = 0; i < numNodes; i++) {
        depth[i] = 0;
    }

    int startIndex = -1;
    for (int i = 0; i < numNodes; i++) {
        if (strcmp(names[i], startNode->val) == 0) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("Error: Start node not found in names array.\n");
        return;
    }

    visited[startIndex] = true;

    printf("%s\n", startNode->val);

    while (!queueEmpty(Queue)) {
        Node *current_node = dequeue(&Queue);
        int currentNodeIndex = -1;
        for (int i = 0; i < numNodes; i++) {
            if (strcmp(names[i], current_node->val) == 0) {
                currentNodeIndex = i;
                break;
            }
        }
        if (currentNodeIndex == -1) {
            printf("Error: Current node not found in names array.\n");
            return;
        }
        int currentDepth = depth[currentNodeIndex];
        
        //sort neighbors
        int i, j, min;
        String temp;

        // One by one move the boundary of the unsorted subarray
        for (i = 0; i < current_node->numNeighbors - 1; i++)
        {
            // Find the minimum element in the unsorted array
            min = i;
            for (j = i + 1; j < current_node->numNeighbors; j++)
            {
                if (strcmp(current_node->neighbors[j]->val, current_node->neighbors[min]->val) < 0)
                    min = j;
            }
            // Swap the found minimum element with the first element
            strcpy(temp, current_node->neighbors[i]->val);
            strcpy(current_node->neighbors[i]->val, current_node->neighbors[min]->val);
            strcpy(current_node->neighbors[min]->val, temp);
        }
        
        for (int i = 0; i < current_node->numNeighbors; i++) {
            Node *neighbor = current_node->neighbors[i];
            int neighborIndex = -1;
            for (int j = 0; j < numNodes; j++) {
                if (strcmp(names[j], neighbor->val) == 0) {
                    neighborIndex = j;
                    break;
                }
            }
            if (neighborIndex == -1) {
                printf("Error: Neighbor node not found in names array.\n");
                continue;
            }
            if(i==current_node->numNeighbors - 1) {
                islast[neighborIndex] = true;
            }     
            if (!visited[neighborIndex]) {
                for (int k = 0; k < currentDepth; k++){
                    if(islast[k] == false){
                        printf("|   ");
                    }
                }
                printf("L__ %s\n", neighbor->val);
                visited[neighborIndex] = true;
                depth[neighborIndex] = currentDepth + 1;
                enqueue(*neighbor, &Queue);
            }
        }
    }
}

void make_tree(adjacency_matrix tree, int start_index) {
    Node nodes[MAX_VERTICES];
    for (int i = 0; i < tree.vertex; i++) {
        nodes[i] = createNode(tree.names[i]);
    }

    for (int i = 0; i < tree.vertex; i++) {
        for (int j = 0; j < tree.vertex; j++) {
            if (tree.matrix[i][j] == 1) {
                connectNodes(&nodes[i], &nodes[j]);
            }
        }
    }

    printBFS(&nodes[start_index], tree.names, tree.vertex);
}