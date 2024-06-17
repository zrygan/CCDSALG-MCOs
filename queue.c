/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of queue data structure .
*/

#include "queue.h"

/**createQueue
 * Implementation of create queue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
queue createQueue(int S){
    queue Queue;
    // removed size
    Queue.head = 0; // start head and tail at 0 position
    Queue.tail = 0;
    // removed elems
    return Queue;
}

/**enqueue
 * Implementation of enqueue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
void enqueue(char elem, queue *Queue){
    // checks queue overflow
    if ((Queue->tail + 1) % MAX_SIZE == Queue->head) {
    printf("Queue overflow\n");
    return;
    }
    // put the element in the tail position
    Queue->items[Queue->tail] = elem;

    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = (Queue->tail + 1) % MAX_SIZE;
    // dont update head
}

/**dequeue
 * Implementation of denqueue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char dequeue(queue *Queue){
    if (queueEmpty(*Queue)) {
        printf("Queue underflow\n");
    }
    char elem = Queue->items[Queue->head];
    Queue->head = (Queue->head + 1) % MAX_SIZE;
    
    return elem;
}

/**queueEmpty
 * Checks if queue is empty, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
bool queueEmpty(queue Queue){
    return Queue.head == Queue.tail;
}

// removed queueFull

/**queueHead
 * Gets current value in head, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char queueHead(queue Queue){
    if (queueEmpty(Queue)) {
        printf("Queue empty\n");
    }
    return Queue.items[Queue.head];
}

/**queueTail
 * Gets current value in tail, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
int queueTail(queue Queue){
    if (queueEmpty(Queue)) {
        printf("Queue empty\n");
    }
    return Queue.items[Queue.tail];
}
