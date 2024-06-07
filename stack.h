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

#define MAX_SIZE 256 // define the maximum size of a stack as 256

/** stack
 * struct data type for a stack
 * 
 * @fields:
 *  - items[MAX_SIZE] : int : array of integers, with maximum size of MAX_SIZE = 256
 *  - top : int : the most recent addition in the items array 
 */
typedef struct stack
{
    int items[MAX_SIZE];
    int top;
};


/** createStack
 * creates an empty stack with size `S`
 * 
 * @params:
 *  - S : int : the size/capacity of the stack
 * 
 * @returns:
 *  - none
 */
void create(int S);

/**push
 * inserts an element `elem` in the stack `Stack`.
 * 
 * @params:
 *  - elem : int : the element to insert in the stack
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - 1 : for successful push
 *  - -1 : for unsuccessful push (caused by overflow)
 */
int push(int elem, stack Stack);

/**pop
 * deletes the top element in the stack and returns the element
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - top : the top element; the deleted element
 *  - -999999 : for unseccessful pop (caused by underflow)
 */
int pop(stack Stack);

#endif