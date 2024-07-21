#ifndef QUEUE
#define QUEUE

#include "libraries.h"
#include "traversal.h"

typedef struct
{
    Node nodes[MAX_VERTICES];
    int head;
    int tail;
    int size;
} queue;

queue createQueue(int S);

void enqueue(Node elem, queue *Queue);

bool queueEmpty(queue Queue);

Node *dequeue(queue *Queue);

#endif