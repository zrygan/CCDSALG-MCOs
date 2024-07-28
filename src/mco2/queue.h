#ifndef QUEUE
#define QUEUE

#include "libraries.h"
#include "traversal.h"

/**
 * struct data type for a queue
 *
 * @fields:
 *  - {nodes} array of Node, with maximum size of MAX_VERTICES = 21
 *  - {head} index where the next element to be dequeued
 *  - {tail} index where the next element to be inserted
 *  - {size} actual max size of the queue
 *
 * @author: Zhean Ganituen
 */
typedef struct
{
    Node nodes[MAX_VERTICES];
    int head;
    int tail;
    int size;
} queue;

/**
 * creates an empty queue with head and tail at 0
 *
 * @param S size of queue
 *
 * @returns the queue created
 *
 * @author: Zhean Ganituen
 */
queue createQueue(int S);

/**
 * adds an element in the tail position
 *
 * @param elem element to be insterted
 * @param queue* the queue
 *
 * @returns:
 *  - none
 *
 * @author: Zhean Ganituen
 */
void enqueue(Node elem, queue *Queue);

/**
 * checks if the queue is empty
 *
 * @param queue the queue
 *
 * @returns:
 *  - true  : when the queue is empty
 *  - false : otherwise
 *
 * @author: Zhean Ganituen
 */
bool queueEmpty(queue Queue);

/**
 * deletes element in the head position
 *
 *
 *  @param queue* the queue
 *  @param buffer* the buffer for the char
 *
 * @returns:
 *  - removed : char* : the element removed
 *
 * @author: Zhean Ganituen, Jaztin Jimenez
 */
Node *dequeue(queue *Queue);

#endif