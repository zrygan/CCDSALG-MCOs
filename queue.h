/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of queue data structure.
*/

#ifndef QUEUE
#define QUEUE

#include "libraries.h"

/**queue
 * struct data type for a queue
 * 
 * @fields:
 *  - items[MAX_SIZE] : int : array of integers, with maximum size of MAX_SIZE = 256
 *  - head            : int : index where the next element to be dequeued
 *  - tail            : int : index where the next element to be inserted
 *  - size            : int : actual max size of the queue
 *  - elems           : int : current number of elements in the queue
 * 
 * @author: Zhean Ganituen
 */
typedef struct{
    char items[MAX_SIZE];
    int head;
    int tail;
    int size;
    int elems;
} queue;

/**createQueue
 * creates an empty queue with head and tail at 0
 * 
 * @params:
 *  - S : int : size of queue
 * 
 * @returns:
 *  - *Queue : the queue created 
 * 
 * @author: Zhean Ganituen
*/
queue createQueue(int S);

/**enqueue
 * adds an element in the tail position
 * 
 * @params:
 *  - elem  : char    : element to be insterted
 *  - Queue : queue* : the queue
 * 
 * @returns:
 *  - none
 * 
 * @author: Zhean Ganituen
 */
void enqueue(char elem, queue *Queue);

/**dequeue
 * deletes element in the head position
 * 
 * @params:
 *  - Queue : queue* : the queue
 *  - buffer : buffer* : the buffer for the char
 * 
 * @returns:
 *  - removed : char : the element removed
 */
char dequeue(queue *Queue);

/**queueEmpty
 * checks if the queue is empty
 * 
 * @params:
 *  - Queue : queue : the queue
 * 
 * @returns:
 *  - true  : when the queue is empty
 *  - false : otherwise
 */
bool queueEmpty(queue Queue);


/**queueFull
 * checks if the queue is full
 * 
 * @params:
 *  - Queue : queue : the queue
 * 
 * @returns:
 *  - true  : when the queue is full
 *  - false : otherwise
 */
bool queueFull(queue Queue);

/**queueHead
 * returns the value at the head
 * 
 * @params:
 *  - queue : queue : the queue
 * 
 * @returns:
 *  - val : int : the value at the head
 */
int queueHead(queue Queue);

/**queueTail
 * returns the value at the tail
 * 
 * @params:
 *  - queue : queue : the queue
 * 
 * @returns:
 *  - val : int : the value at the tail
 */
int queueTail(queue Queue);

#endif