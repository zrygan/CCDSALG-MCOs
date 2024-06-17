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
bool isOperators(char precedence){
    return precedence == '+' || precedence == '-' || precedence == '*' || precedence == '/' || precedence == '<' || precedence == '>' || 
           precedence == '=' || precedence == '!' || precedence == '&' || precedence == '|';
}

int Evaluate(int token1,int operators,int token2){
    int result;
    switch(operators){
        case '+': result = token1 + token2; return result; break;
        case '-': result = token1 - token2; return result; break;
        case '*': result = token1 * token2; return result; break;
        case '/': result = token1 / token2; return result; break;
        case '<': result = token1 < token2; return result; break;
        case '>': result = token1 > token2; return result; break;
        case '&': result = token1 && token2; return result; break;
        case '|': result = token1 || token2; return result; break;
        case '=': result = token1 == token2; return result; break;
        case '!': result = token1 != token2; return result; break;
        default: return -1;
    }
}

int EvaluatePostfix(queue Postfix){
    stack Output = createStack(MAX_SIZE);

    while (!queueEmpty(Postfix)) {
        char current = dequeue(&Postfix);

        if (isdigit(current)) {
            // Convert character to integer before pushing to stack
            push(current - '0', &Output);
        } else if (isOperators(current)) {
            int token2 = pop(&Output);
            int token1 = pop(&Output);
            int result = Evaluate(token1, current, token2);
            push(result, &Output);
        }
    }

    return pop(&Output);
}