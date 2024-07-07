/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of infix to postfix algorithm.
*/

#include "inToPost.h"

/**isOperator
 * Implementation of isOperator function, see documentation in `inToPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int isOperator(const char *str){
    return strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0 ||
           strcmp(str, "%") == 0 || strcmp(str, "^") == 0 || strcmp(str, "<") == 0 || strcmp(str, ">") == 0 ||
           strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0 || strcmp(str, "==") == 0 || strcmp(str, "!=") == 0 ||
           strcmp(str, "&&") == 0 || strcmp(str, "||") == 0 || strcmp(str, "!") == 0;
}

/**getPrecedence
 * Implementation of getPrecedence function, see documentation in `inToPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int getPrecedence(const char *precedence){
    if (strcmp(precedence, "^") == 0) return 8;
    if (strcmp(precedence, "!") == 0) return 7;
    if (strcmp(precedence, "*") == 0 || strcmp(precedence, "/") == 0 || strcmp(precedence, "%") == 0) return 6;
    if (strcmp(precedence, "+") == 0 || strcmp(precedence, "-") == 0) return 5;
    if (strcmp(precedence, "<") == 0 || strcmp(precedence, ">") == 0 || strcmp(precedence, "<=") == 0 || strcmp(precedence, ">=") == 0) return 4;
    if (strcmp(precedence, "==") == 0 || strcmp(precedence, "!=") == 0) return 3;
    if (strcmp(precedence, "&&") == 0) return 2;
    if (strcmp(precedence, "||") == 0) return 1;
    return 0;
}

/**gInfixtoPostfix
 * Implementation of InfixtoPostfix function, see documentation in `inToPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
queue InfixtoPostfix(queue infix) {
    stack stack = createStack();
    queue Postfix = createQueue(MAX_SIZE);

    while (!queueEmpty(infix)) {
        char *current = dequeue(&infix);

        if (isdigit(*current)) {
            enqueue(current, &Postfix); // Directly enqueue digits to output queue
        } else if (isOperator(current)) {
            while (!stackEmpty(stack) && getPrecedence(top(stack)) >= getPrecedence(current)) {
                enqueue(pop(&stack), &Postfix); // Pop operators with higher or equal precedence
            }
            push(current, &stack); // Push current operator onto the stack
        } else if (*current == '(') {
            push(current, &stack); // Push '(' onto the stack
        } else if (*current == ')') {
            while (!stackEmpty(stack) && strcmp(top(stack), "(") != 0) {
                enqueue(pop(&stack), &Postfix); // Pop until '(' is encountered
            }
            pop(&stack); // Pop '(' from the stack (discard it)
        }
    }

    // Pop all remaining operators from the stack to the output queue
    while (!stackEmpty(stack)) {
        enqueue(pop(&stack), &Postfix);
    }

    return Postfix;
}