#ifndef QUEUE
#define QUEUE

#include "libraries.h"
#include "traversal.h"

/**queue
 * struct data type for a queue
 * 
 * @fields:
 *  - items[MAX_VERTICES] : Node: array of Node, with maximum size of MAX_VERTICES = 21
 *  - head                      : int  : index where the next element to be dequeued
 *  - tail                      : int  : index where the next element to be inserted
 *  - size                      : int  : actual max size of the queue
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
 *  - elem  : Node    : element to be insterted
 *  - Queue : queue* : the queue
 * 
 * @returns:
 *  - none
 * 
 * @author: Zhean Ganituen
 */
void enqueue(Node elem, queue *Queue);
/**queueEmpty
 * checks if the queue is empty
 * 
 * @params:
 *  - Queue : queue : the queue
 * 
 * @returns:
 *  - true  : when the queue is empty
 *  - false : otherwise
 * 
 * @author: Zhean Ganituen
 */
bool queueEmpty(queue Queue);
/**dequeue
 * deletes element in the head position
 * 
 * @params:
 *  - Queue : queue* : the queue
 *  - buffer : buffer* : the buffer for the char
 * 
 * @returns:
 *  - removed : char* : the element removed
 * 
 * @author: Zhean Ganituen, Jaztin Jimenez
 */
Node *dequeue(queue *Queue);

#endif