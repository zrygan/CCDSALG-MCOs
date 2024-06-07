/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of stack data structure.
*/

#ifndef STACK
#define STACK

#include "libraries.h"

/** stack
 * struct data type for a stack
 * 
 * @fields:
 *  - items[MAX_SIZE] : int : array of integers, with maximum size of MAX_SIZE = 256
 *  - top             : int : the most recent addition in the items array 
 *  - size            : int : the actual maximum size of the stack
 *  - elems           : int : current number of elements in the stack, 
 *                    constraint: elems < size
 *                    constraint: elems > 0
 */
typedef struct
{
    int items[MAX_SIZE];
    int top;
    int size;
    int elems;
} stack;

/** createStack
 * creates an empty stack with size `S` and top 0
 * 
 * @params:
 *  - S : int : the size/capacity of the stack
 * 
 * @returns:
 *  - *Stack : the stack created
 * 
 * @author: Zhean Ganituen
 */
stack create(int S);

/**push
 * inserts an element `elem` in the stack `Stack`.
 * 
 * @params:
 *  - elem  : int   : the element to insert in the stack
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - 1 : for successful push
 *  - -1 : for unsuccessful push (caused by overflow)
 * 
 * @author: Zhean Ganituen
 */
int push(int elem, stack *Stack);

/**pop
 * deletes the top element in the stack and returns the element
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - removed : the deleted element
 *  - -999999 : for unseccessful pop (caused by underflow)
 * 
 * @author: Zhean Ganituen
 */
int pop(stack *Stack);

/**isEmpty
 * checks if the stack is empty
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - true : when top is 0; stack is empty
 *  - else : otherwise
 * 
 * @author: Zhean Ganituen
*/
bool isEmpty(stack Stack);


/**isFull
 * checks if the stack is full
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - true : when top is 0; stack is full
 *  - else : otherwise
 * 
 * @author: Zhean Ganituen
*/
bool isFull(stack Stack);

#endif