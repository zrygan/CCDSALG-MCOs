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

bool isOperators(const char *str){
    return strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0 ||
           strcmp(str, "<") == 0 || strcmp(str, ">") == 0 || strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0 ||
           strcmp(str, "==") == 0 || strcmp(str, "!=") == 0 || strcmp(str, "&&") == 0 || strcmp(str, "||") == 0;

}

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

int EvaluatePostfix(queue Postfix) {
    int_stack OperandStack = createIntStack();

    while (!queueEmpty(Postfix)) {
        char* current = dequeue(&Postfix);

        if (isdigit(*current)) {
            int operand = atoi(current);
            intPush(operand, &OperandStack);
        } else if (isOperators(current)) {
            int token2 = intPop(&OperandStack);
            int token1 = intPop(&OperandStack);
            int result = Evaluate(token1, current, token2);
            intPush(result, &OperandStack);
        }
    }

    return intPop(&OperandStack);
}