/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of the stack data structure.
*/

#ifndef STACK
#define STACK

#include "libraries.h"

/** stack
 * struct data type for a stack
 * 
 * @fields:
 *  - items[MAX_SIZE] : char* : array of characters, with maximum size of MAX_SIZE = 256
 *  - top             : int   : the index of the most recent addition in the items array 
 * 
 * @author: Zhean Ganituen
 */
typedef struct
{
    char* items[MAX_SIZE];
    int top;
} stack;

/** createStack
 * creates an empty stack with size `S` and top 0
 * 
 * 
 * @returns:
 *  - Stack : the stack created
 * 
 * @author: Zhean Ganituen
 */
stack createStack();

/**push
 * inserts an element `elem` in the stack `Stack`.
 * 
 * @params:
 *  - elem  : char*   : the element to insert in the stack
 *  - Stack : stack* : the stack
 * 
 * @returns:
 *  none
 * 
 * @author: Zhean Ganituen
 */
void push(char *elem, stack *Stack);

/**pop
 * deletes the top element in the stack and returns the element
 * 
 * @params:
 *  - Stack : stack* : the stack
 * 
 * @returns:
 *  - Stack->items[(Stack->top)--] : the deleted element
 *  - NULL : for unseccessful pop (caused by underflow)
 * 
 * @author: Zhean Ganituen
 */
char* pop(stack* Stack);

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
bool stackEmpty(stack Stack);

/**top
 * checks the element at the top of the stack
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @returns:
 *  - Stack.items[Stack.top]    :   char*   :   the string at the top of the stack
 *  - NULL  :   no element on top of the stack (stack is empty)
 * 
 * @author: Zhean Ganituen
 */
char* top(stack Stack);

/**int_stack
 * struct data type for an int stack
 * 
 * @params:
 *  - Stack : stack : the stack
 * 
 * @fields:
 *  - items[MAX_SIZE] : int : array of integers, with maximum size of MAX_SIZE = 256
 *  - top             : int : the most recent addition in the items array 
 */
typedef struct {
    int items[MAX_SIZE];
    int top;
} int_stack;

/**createIntStack
 * creates the int stack and initializes the values
 * 
 * @returns:
 *  - int_stack :   the int stack created
 * 
 * @author: Jaztin Jimenez
 */
int_stack createIntStack();

/**intStackEmpty
 * checks if the stack is empty
 * 
 * @params:
 *  - Stack :   int_stack   :   the stack for integers
 * 
 * @returns:
 *  - true : when the stack is empty
 *  - else : otherwise
 * 
 * @author: Jaztin Jimenez
 */
bool intStackEmpty(int_stack Stack);

/**intStackEmpty
 * checks if the stack is empty
 * 
 * @params:
 *  - elem  :   int :   the element to be pushed in the stack
 *  - Stack :   int_stack*   :   the stack for integers
 * 
 * @author: Jaztin Jimenez
 */
void intPush(int elem, int_stack* Stack);

/**intPop
 * removes the top integer of the stack
 * 
 * @params:
 *  - Stack :   int_stack*   :   the stack for integers
 * 
 * @returns:
 *  - Stack->items[(Stack->top)--]  :   int     : the integer on top of the stack
 *  - -1    :   int     :   unsuccessful pop (stack underflow)
 * 
 * @author: Jaztin Jimenez
 */
int intPop(int_stack* Stack);

/**intTop
 * returns the top integer of the stack
 * 
 * @params:
 *  - Stack :   int_stack   :   the stack for integers
 * 
 * @returns:
 *  - Stack.items[Stack.top]  :   int     : the integer on top of the stack
 *  - -1    :   int     :   unsuccessful pop (stack is empty)
 * 
 * @author: Jaztin Jimenez
 */
int intTop(int_stack Stack);


#endif