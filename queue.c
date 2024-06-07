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

void enqueue(int elem, queue *Queue){
    // put the element in the tail position
    Queue->items[Queue->tail] = elem;
    Queue->elems++;

    // update tail position
    // move the position by 1 and make it loop around if it exeeds size
    Queue->tail = Queue->tail++ % Queue->size + 1;
    // dont update head
}

int dequeue(queue *Queue){
    // store removed value
    int removed = Queue->items[Queue->head];

    // remove the element in the head position
    Queue->items[Queue->head] = 0;
    Queue->elems--;

    // update head position
    // same formula as with enqueue (moving tail)
    Queue->head = Queue->head++ % Queue->size + 1;
    // dont update tail

    return removed;
}

bool queueEmpty(queue Queue){
    if (Queue.elems == 0) return true;
    else return false;
}

bool queueFull(queue Queue){
    if (Queue.elems == Queue.size) return true;
    else return false;
}

int queueHead(queue Queue){
    return Queue.items[Queue.head];
}

int queueTail(queue Queue){
    return Queue.items[Queue.tail];
}
