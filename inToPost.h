/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of queue data structure.
*/

#ifndef INTOPOST
#define INTOPOST

#include "queue.h"
#include "stack.h"
#include "libraries.h"

/**isOperator
 * checks if the string is an operator or not
 * 
 * @params:
 * - str : const char* : a string of characters, which could either be an operand or operator
 * 
 * @returns:
 * - 1  : when the string is an operator
 * - 0  : when the string is an operand
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int isOperator(const char *str);

/**isOperator
 * checks the precedence of the operator
 * 
 * @params:
 * - precedence : const char* : a string of operators
 * 
 * @returns:
 * int  :   value of the precedence of the operator
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int getPrecedence(const char *precedence);

/**InfixtoPostfix
 * turns the postfix expression into an infix expression
 * 
 * @params:
 * - infix : queue : an infix expression stored in a queue
 * 
 * @returns:
 * Postfix  :   a queue containing the postfix expression of the infix expression
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
queue InfixtoPostfix(queue infix);

#endif