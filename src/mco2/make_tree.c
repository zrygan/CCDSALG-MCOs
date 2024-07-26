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
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    queue queue = createQueue(numNodes);
    enqueue(*startNode, &queue);

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
    char result[1000] = "";
    strcat(result, startNode->val);
    strcat(result, "\n");

    while (!queueEmpty(queue)) {
        Node *currentNode = dequeue(&queue);
        int currentNodeIndex = -1;
        for (int j = 0; j < numNodes; j++) {
            if (strcmp(names[j], currentNode->val) == 0) {
                currentNodeIndex = j;
                break;
            }
        }
        if (currentNodeIndex == -1) {
            strcat(result, "Error: Current node not found in names array.\n");
            continue;
        }

        // Print children of the current node
        for (int j = 0; j < currentNode->numNeighbors; j++) {
            Node *neighbor = currentNode->neighbors[j];
            int neighborIndex = -1;
            for (int k = 0; k < numNodes; k++) {
                if (strcmp(names[k], neighbor->val) == 0) {
                    neighborIndex = k;
                    break;
                }
            }
            if (neighborIndex == -1) {
                strcat(result, "Error: Neighbor node not found in names array.\n");
                continue;
            }

            if (!visited[neighborIndex]) {
                // Print the node with proper indentation
                char temp[100] = "";
                for (int k = 0; k < depth[currentNodeIndex] + 1; k++) strcat(temp, "|   ");
                strcat(temp, "L__ ");
                strcat(temp, neighbor->val);
                strcat(temp, "\n");
                strcat(result, temp);

                visited[neighborIndex] = true;
                depth[neighborIndex] = depth[currentNodeIndex] + 1;
                enqueue(*neighbor, &queue);
            }
        }
    }

    printf("%s", result);
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

    printBFS(&nodes[start_index], tree.names, tree.vertex * tree.vertex);
}