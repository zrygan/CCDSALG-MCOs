/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of postfix evaluation algorithm.
*/

#include "evalPost.h"

/**isOperators
 * Implementation of isOperators function, see documentation in `evalPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int isOperators(const char *str){
    return strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0 ||
           strcmp(str, "<") == 0 || strcmp(str, ">") == 0 || strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0 ||
           strcmp(str, "==") == 0 || strcmp(str, "!=") == 0 || strcmp(str, "&&") == 0 || strcmp(str, "||") == 0;

}

/**Evaluate
 * Implementation of Evaluate function, see documentation in `evalPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int Evaluate(int token1,char *operators,int token2){
    if (strcmp(operators, "+") == 0) return token1 + token2;
    if (strcmp(operators, "-") == 0) return token1 - token2;
    if (strcmp(operators, "*") == 0) return token1 * token2;
    if (strcmp(operators, "/") == 0) return token1 / token2;
    if (strcmp(operators, "<") == 0) return token1 < token2;
    if (strcmp(operators, ">") == 0) return token1 > token2;
    if (strcmp(operators, "<=") == 0) return token1 <= token2;
    if (strcmp(operators, ">=") == 0) return token1 >= token2;
    if (strcmp(operators, "==") == 0) return token1 == token2;
    if (strcmp(operators, "!=") == 0) return token1 != token2;
    if (strcmp(operators, "&&") == 0) return token1 && token2;
    if (strcmp(operators, "||") == 0) return token1 || token2;
    return -1;
}

/**EvaluatePostfix
 * Implementation of EvaluatePostfix function, see documentation in `evalPost.h`
 * 
 * @author: Vienn Balcita
 * @contributor: Jaztin Jimenez
 */
int EvaluatePostfix(queue Postfix) {
    int_stack OperandStack = createIntStack();

    while (!queueEmpty(Postfix)) { // loops until the Postfix queue is empty
        char* current = dequeue(&Postfix); // temp char 

        if (isdigit(*current)) { // checks if the dequeued string is an operand token
            int operand = atoi(current); // turns the string to an integer and stores it in operand
            intPush(operand, &OperandStack); // pushes the integer to the stack
        } else if (isOperators(current)) { // checks if the dequeued string is an operator token
            int token2 = intPop(&OperandStack); 
            int token1 = intPop(&OperandStack); 
            int result = Evaluate(token1, current, token2); // evaluates the small expression
            intPush(result, &OperandStack); // pushes the evaluated value to the stack
        }
    }

    return intPop(&OperandStack); // returns the value of the postfix expression
}