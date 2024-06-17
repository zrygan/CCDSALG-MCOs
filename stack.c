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
stack createStack(){
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
void push(char* elem, stack* Stack) {
    if (Stack->top < MAX_SIZE - 1) {
        Stack->items[++(Stack->top)] = elem;
    } else {
        printf("Stack overflow\n");
    }
}

/**pop
 * Implementation for the pop element function, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
char* pop(stack* Stack) {
    if (!stackEmpty(*Stack)) {
        return Stack->items[(Stack->top)--];
    } else {
        printf("Stack underflow\n");
        return NULL;
    }
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

char* top(stack Stack) {
    if (!stackEmpty(Stack)) {
        return Stack.items[Stack.top];
    } else {
        printf("Stack is empty\n");
        return NULL;
    }
}