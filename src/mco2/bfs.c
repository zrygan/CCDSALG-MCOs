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


queue createQueue(int S){
    queue Queue;
    Queue.size = S;
    Queue.head = 0; // start head and tail at 0 position
    Queue.tail = 0;
    // removed elems
    return Queue;
}

void enqueue(Node elem, queue *Queue){
    // checks queue overflow
    if ((Queue->tail + 1)  % Queue->size == Queue->head) {
    printf("Queue overflow\n");
    return;
    }

    // put the element in the tail position
    Queue->nodes[Queue->tail]=elem;
    
    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = (Queue->tail + 1) % Queue->size;
    // dont update head


}


bool queueEmpty(queue Queue){
    // if queue is empty "reset" the position of head and tail.
    return Queue.head == Queue.tail;
}

Node* dequeue(queue *Queue){
    // check if the queue is empty

    if (queueEmpty(*Queue)) {
        printf("Queue underflow\n");
        return NULL;
    }

    // if not, then dequeue head
    Node* elem = &Queue->nodes[Queue->head];
    Queue->head = (Queue->head + 1) % Queue->size;
    
    return elem;
}


void bfs(Node *current_node, bool *visited, String values[], int numNodes, String tree_nodes[], int tree_count){
queue queue = createQueue(numNodes);

enqueue(*current_node, &queue);

while(!queueEmpty(queue)){
    Node* visit_node = dequeue(&queue);
    int nodeindex = -1;
    for(int i = 0;i< numNodes;i++){
        if (strcmp(values[i],visit_node->val)==0){
            nodeindex = i;
            break;
        }
    }
    //if the node exists and it is not visited yet then proceed
    if (nodeindex != -1 && !visited[nodeindex]){
        printf("%s ", visit_node->val);
        visited[nodeindex] = true;
        for(int i = 0;i < visit_node->numNeighbors;i++){
            int neighborindex = -1;
            for (int j = 0; j < numNodes; j++) {  // Find the index of the neighbor in the values array
                if ((strcmp(values[j], visit_node->neighbors[i]->val)) == 0 && !visited[j]) {
                    neighborindex = j;
                }
            }
            if (neighborindex != -1 && !visited[neighborindex]) {  // If the neighbor exists and is not visited
                enqueue(*visit_node->neighbors[i],&queue);  // Enqueue the neighbor
                char* temp = node(visit_node->val,visit_node->neighbors[i]->val);
                strcpy(tree_nodes[tree_count],temp);
                tree_count++;
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
    //visit_node(&nodeName[start_index], visited, matrix.names, matrix.vertex);
    // Perform the bfs Traversal
    bfs(&nodeName[start_index], visited, matrix.names, matrix.vertex, tree_nodes, 0);

}
