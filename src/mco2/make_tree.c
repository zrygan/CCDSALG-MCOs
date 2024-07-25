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

bool checkTreeNode(String tree_nodes[], int tree_count, String node)
{
    for (int i = 0; i < tree_count; i++)
    {
        if (strcmp(tree_nodes[i], node) == 0)
        {
            return false;
        }
    }
    return true;
}

void bfsTree(Node *startNode, String values[], int numNodes) {

    bool visited[MAX_VERTICES] = {false};
    queue Queue = createQueue(MAX_VERTICES);
    enqueue(*startNode, &Queue);

    String tree_nodes[MAX_VERTICES] = {""};
    int tree_count = 0;

    while (!queueEmpty(Queue)) {
        Node *current_node = dequeue(&Queue);
        int nodeIndex = -1;
        for (int i = 0; i < numNodes; i++) {
            if (strcmp(values[i], current_node->val) == 0) {
                nodeIndex = i;
                break;
            }
        }

        if (nodeIndex == -1 || visited[nodeIndex]) continue;
        visited[nodeIndex] = true;
        if (checkTreeNode(tree_nodes, tree_count, current_node->val)) {
            printf("%s\n", current_node->val);
            strcpy(tree_nodes[tree_count++], current_node->val);
        }

        for (int i = 0; i < current_node->numNeighbors; i++) {
            Node *neighbor = current_node->neighbors[i];
            int neighborIndex = -1;
            for (int j = 0; j < numNodes; j++) {
                if (strcmp(values[j], neighbor->val) == 0) {
                    neighborIndex = j;
                    break;
                }
            }
            if (neighborIndex != -1 && !visited[neighborIndex]) {
                printf("|");
                for (int j = 0; j < tree_count; j++) {
                    if (strcmp(tree_nodes[j], current_node->val) == 0) {
                        for (int k = 0; k <= j; k++) {
                            if (k == j) {
                                printf("L__ ");
                            } else {
                                printf("|    ");
                            }
                        }
                        printf("%s\n", neighbor->val);
                    }
                }
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
    bfsTree(&nodes[start_index], tree.names, tree.vertex);
}