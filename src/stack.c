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
#include "libraries.h"

/**create
 * Implementation of create stack function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
stack create(int S){
    /* what we need to do:
        1. allocate memory for the stack
        2. initialize top as 0
        3. initialize size as S
        4. return the stack created
    */
    stack *Stack = malloc(sizeof(stack)); // allocate memory for the stack created

    Stack->top = 0; // init top as 0
    Stack->size = S; // init size as what ever S is

    Stack->elems = 0; // init number of elements as 0

    return *Stack;
}

/**push
 * Implementation for the push element function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
int push(int elem, stack Stack){
    /* what we need to do:
        1. check wether an element can still be added
        2. add elem in the top index
        3. make top gets elem
        4. increment elems (current number of elements)
    */
    
    // check constraint elems (current number of elements) < size (maximum number of elements)
    if(Stack.elems++ < Stack.size){
        // if an element can be added
        Stack.items[Stack.elems] = elem;
        Stack.top = elem;
        
        // increment elems
        Stack.elems++;
        
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
int pop(stack Stack){
    /*
        1. check whether an element can still be removed
    */

    if (Stack.elems > 0){
        // if an element can still be removed
        
        // store element to be removed
        int removed = Stack.items[Stack.elems];
        
        Stack.items[Stack.elems] = 0;
        Stack.elems--;
        Stack.top = Stack.items[Stack.elems];

        return removed;
    }

    return -999999;   
}