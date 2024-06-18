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
        1. initialize top as -1
        2. return the stack created
    */
    stack Stack;
    Stack.top = -1; // init top as -1

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

/**top
 * Implementation to check the element at the top of the stack, see documentation in `stack.h`
 * 
 * @author: Zhean Ganituen
 */
char* top(stack Stack) {
    if (!stackEmpty(Stack)) {
        return Stack.items[Stack.top];
    } else {
        printf("Stack is empty\n");
        return NULL;
    }
}

/**createIntStack
 * Implementation of create int stack function, see documentation in `stack.h`
 * 
 * @author: Jaztin Jimenez
 */
int_stack createIntStack() {
    int_stack Stack;
    Stack.top = -1;
    return Stack;
}

/**intStackEmpty
 * Implementation to check if the stack is empty, see documentation in `stack.h`
 * 
 * @author: Jaztin Jimenez
 */
bool intStackEmpty(int_stack Stack) {
    return Stack.top == -1;
}

/**intPush
 * Implementation to check if the stack is empty, see documentation in `stack.h`
 * 
 * @author: Jaztin Jimenez
 */
void intPush(int elem, int_stack* Stack) {
    if (Stack->top < MAX_SIZE - 1) {
        Stack->items[++(Stack->top)] = elem;
    } else {
        printf("Stack overflow\n");
    }
}

/**intPop
 * Implementation to remove and return the integer at the top of the stack, see documentation in `stack.h`
 * 
 * @author: Jaztin Jimenez
 */
int intPop(int_stack* Stack) {
    if (!intStackEmpty(*Stack)) {
        return Stack->items[(Stack->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

/**intTop
 * Implementation to return the integer at the top of the stack, see documentation in `stack.h`
 * 
 * @author: Jaztin Jimenez
 */
int intTop(int_stack Stack) {
    if (!intStackEmpty(Stack)) {
        return Stack.items[Stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
