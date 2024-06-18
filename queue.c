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
    Queue.size = S;
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
void enqueue(char *elem, queue *Queue){
    // checks queue overflow
    if ((Queue->tail + 1)  % Queue->size == Queue->head) {
    printf("Queue overflow\n");
    return;
    }

    // put the element in the tail position
    strcpy(Queue->items[Queue->tail], elem);
    
    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = (Queue->tail + 1) % Queue->size;
    // dont update head

    
}

/**dequeue
 * Implementation of denqueue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char* dequeue(queue *Queue){
    if (queueEmpty(*Queue)) {
        printf("Queue underflow\n");
        return NULL;
    }
    char *elem = Queue->items[Queue->head];
    Queue->head = (Queue->head + 1) % Queue->size;
    
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

/**queueHead
 * Gets current value in head, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char* queueHead(queue Queue){
    static char headItem[MAX_SIZE]; // Static array to hold the result
    if (queueEmpty(Queue)) {
        printf("Queue empty\n");
        return NULL;
    }
    strncpy(headItem, Queue.items[Queue.head], MAX_SIZE); // Copy the item to static array
    return headItem;
}
