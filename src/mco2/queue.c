
#include "queue.h"
queue createQueue(int S)
{
    queue Queue;
    Queue.size = S;
    Queue.head = 0; // start head and tail at 0 position
    Queue.tail = 0;
    // removed elems
    return Queue;
}

void enqueue(Node elem, queue *Queue)
{
    // checks queue overflow
    if ((Queue->tail + 1) % Queue->size == Queue->head)
    {
        // printf("Queue overflow\n"); // COMMENTED THIS OUT [ZRY]
        return;
    }

    // put the element in the tail position
    Queue->nodes[Queue->tail] = elem;

    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = (Queue->tail + 1) % Queue->size;
    // dont update head
}

bool queueEmpty(queue Queue)
{
    // if queue is empty "reset" the position of head and tail.
    return Queue.head == Queue.tail;
}

Node *dequeue(queue *Queue)
{
    // check if the queue is empty

    if (queueEmpty(*Queue))
    {
        printf("Queue underflow\n");
        return NULL;
    }

    // if not, then dequeue head
    Node *elem = &Queue->nodes[Queue->head];
    Queue->head = (Queue->head + 1) % Queue->size;

    return elem;
}
