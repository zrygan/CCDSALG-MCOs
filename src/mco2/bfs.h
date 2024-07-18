/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * Header file for the bfs implementation
*/

#ifndef BFS
#define BFS

#include "libraries.h"
#include "traversal.h"


typedef struct{
    Node nodes[MAX_VERTICES];
    int head;
    int tail;
    int size;
} queue;

queue createQueue(int S);

void enqueue(Node elem, queue *Queue);

bool queueEmpty(queue Queue);

Node* dequeue(queue *Queue);

void bfs(Node* current_node, bool* visited, String values[], int numNodes,String tree_nodes[],int tree_count);

void BFStraversal(adjacency_matrix matrix, int start_index);

#endif