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

            if (!visited[neighborIndex]) {
                for (int k = 0; k < currentDepth; k++) printf("|   ");
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