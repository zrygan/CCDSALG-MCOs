/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of Evaluation Postfix function
*/

#ifndef EVALPOST
#define EVALPOST

#include "queue.h"
#include "stack.h"
#include "libraries.h"

/**isOperators
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
int isOperators(const char *str);

/**Evaluate
 * evaluates parts of the postfix expression
 * 
 * @params:
 * - token1   : int    : an operand to be evaluated
 * - operators: char *  : an operator to be evaluated
 * - token2     : int   : an operand to be evaluated
 * 
 * @returns:
 * - 1  : when the string is an operator
 * - 0  : when the string is an operand
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int Evaluate(int token1,char *operators,int token2);

/**EvaluatePostfix
 * evaluates an postfix expression
 * 
 * @params:
 * - Postfix    :   queue   :   a postfix expression stored in a queue
 * 
 * @returns:
 * - intPop(&OperandStack)  :   the evaluated value of the postfix expression
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int EvaluatePostfix(queue Postfix);

#endif