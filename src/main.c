/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Main C file of Part 1 of the project.
*/

#include "libraries.h"
#include "stack.h"
#include "queue.h"

int main(){
    stack myStack = create(10);
    push(1, myStack);
    push(10, myStack);
    push(56, myStack);
    printf("%d", pop(myStack));
    printf("%d", pop(myStack));

    return 0;
}