/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of stack data structure.
*/

#include "stack.h"

/**create
 * Implementation of create stack function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
stack createStack(int S){
    /* what we need to do:
        1. allocate memory for the stack
        2. initialize top as 0
        3. initialize size as S
        4. return the stack created
    */
    stack Stack;
    Stack.top = -1; // init top as 0
    // REMOVED ELEMS AND SIZE

    return Stack;
}

/**push
 * Implementation for the push element function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
int push(char elem, stack *Stack){
    /* what we need to do:
        1. check whether an element can still be added
        2. add elem in the top index
        3. make top gets elem
        4. increment elems (current number of elements)
    */
    
    // check constraint elems (current number of elements) < size (maximum number of elements)
    if(Stack->top < MAX_SIZE - 1){
        // if an element can be added
        Stack->items[++(Stack->top)] = elem;
        
        return 1;
    } 

    // if an element cannot be added anymore
    return -1;
}

/**pop
 * Implementation for the pop element function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
int pop(stack *Stack){
    /*
        1. check whether an element can still be removed
    */
    if (!stackEmpty(*Stack)){
        return Stack->items[(Stack->top)--];
    }

    return -999999;   
}

/**isEmpty
 * Implementation to check if the stack is empty, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
bool stackEmpty(stack Stack){
    return Stack.top == -1;
}

// Removed stackFull

char top(stack Stack){
    if (stackEmpty(Stack)) {
        printf("Stack is empty\n");
    }
    return Stack.items[Stack.top];
}