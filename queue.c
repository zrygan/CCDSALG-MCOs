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
    queue *Queue = malloc(sizeof(queue));

    Queue->size = S-1; // init size as S-1 (since max index for size S is S-1)

    Queue->head = 0; // start head and tail at 0 position
    Queue->tail = 0;
    Queue->elems = 0;

    return *Queue;
}

/**enqueue
 * Implementation of enqueue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
void enqueue(char elem, queue *Queue){
    // put the element in the tail position
    Queue->items[Queue->tail] = elem;
    Queue->elems++;

    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = (Queue->tail + 1) % (Queue->size + 1);
    // dont update head
}

/**denqueue
 * Implementation of denqueue function, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char dequeue(queue *Queue){
    char buffer;
    if (!queueEmpty(*Queue)) {
        strcpy(&buffer, &Queue->items[(Queue->head)++]);
    }
    return buffer;
}

/**queueEmpty
 * Checks if queue is empty, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
bool queueEmpty(queue Queue){
    if (Queue.elems == 0) return true;
    else return false;
}

/**queueFull
 * Checks if queue is full, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
bool queueFull(queue Queue){
    if (Queue.elems == Queue.size) return true;
    else return false;
}

/**queueHead
 * Gets current value in head, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
char queueHead(queue Queue){
    return Queue.items[Queue.head];
}

/**queueTail
 * Gets current value in tail, see documentation in `queue.h`
 * 
 * @author: Zhean Ganituen
 */
int queueTail(queue Queue){
    return Queue.items[Queue.tail];
}
