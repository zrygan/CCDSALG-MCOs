/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of infix to postfix algorithm.
*/

#include "queue.h"
#include "stack.h"
#include "inToPost.h"

/**isOperator
 * Checks if the token is an operator or an operand
 * 
 * @params:
 * - precedence : const char* : INSERT
 * 
 * 
 * @author: Vienn Balcita
 * 
 * Revisions by Jaztin Jimenez
 * - changed the paramater from integer to const char*
 * - changed the == operators to strcmp
 */
bool isOperator(char precedence){
    return precedence == '+' || precedence == '-' || precedence == '*' || precedence == '/' || precedence == '<' || precedence == '>' || 
           precedence == '=' || precedence == '!' || precedence == '&' || precedence == '|';
}

/**getPrecedence
 * Checks the precedence of the operator
 * 
 * @author: Vienn Balcita
 * 
 * Revisions by Jaztin Jimenez
 * - changed the paramter from integer to const char*
 */
int getPrecedence(char precedence){
    switch (precedence) {
        case '|': return 1;
        case '&': return 2;
        case '=': case '!': return 3;
        case '<': case '>': return 4;
        case '+': case '-': return 5;
        case '*': case '/': return 6;
        default: return 0;
    }
}

/**InfixtoPostfix
 * Checks the precedence of the operator
 * 
 * @author: Vienn Balcita
 * 
 * Revisions by Jaztin Jimenez
 * - changed the paramter from integer to const char*
 * - changed the switch cases to if statements for better readability
 */

queue InfixtoPostfix(queue infix) {
    stack stack = createStack(MAX_SIZE);
    queue Postfix = createQueue(MAX_SIZE);
    
    while (!queueEmpty(infix)) {
        char current = dequeue(&infix); // Dequeue the current character

        if (isalnum(current)) {  // Check if it's an operand
            enqueue(current, &Postfix); // Enqueue the operand to Postfix
        } else if (current == '(') {
            push(current, &stack); // Push '(' to the stack
        } else if (current == ')') {
            while (!stackEmpty(stack) && top(stack) != '(') {
                enqueue(pop(&stack), &Postfix);
            }
            pop(&stack); // Remove '('
        } else if (isOperator(current)) {
            while (!stackEmpty(stack) && getPrecedence(top(stack)) >= getPrecedence(current)) {
                enqueue(pop(&stack), &Postfix);
            }
            push(current, &stack); // Push the current operator to the stack
        }
    }

    // Enqueue any remaining operators in the stack to the postfix queue
    while (!stackEmpty(stack)) {
        enqueue(pop(&stack), &Postfix);
    }

    printf("im working!\n");
    return Postfix;
}