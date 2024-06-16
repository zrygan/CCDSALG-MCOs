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

/**tokenize
 * Tokenize the infix expression and enqueue the tokens into a queue
 * 
 * @params:
 * - infix : const char* infix : an infix expression
 * 
 * @author: Jaztin Jimenez
 */
queue tokenize(const char* infix){
    queue infixQueue = createQueue(MAX_SIZE);

    int i = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            enqueue(infix[i], &infixQueue);
        } else if ((isOperator(infix[i]) == true) || infix[i] == '(' || infix[i] == ')') {
            enqueue(infix[i], &infixQueue);
        }
        i++;
    }

    return infixQueue;
}


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
    if ( (strcmp(&precedence, "+") == 0) || (strcmp(&precedence, "-") == 0) || (strcmp(&precedence, "*") == 0) || (strcmp(&precedence, "/") == 0) || 
    (strcmp(&precedence, "<") == 0) || (strcmp(&precedence, ">") == 0) || (strcmp(&precedence, "<=") == 0) || (strcmp(&precedence, ">=") == 0) ||
    (strcmp(&precedence, "==") == 0) || (strcmp(&precedence, "!=") == 0) || (strcmp(&precedence, "&&") == 0) || (strcmp(&precedence, "||") == 0)){
        return true;
    }
    else{
        return false;
    }
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
queue InfixtoPostfix(queue infix){
    stack stack = createStack(MAX_SIZE);
    queue Postfix = createQueue(MAX_SIZE);

    while(!queueEmpty(infix)){

        if (isalnum(queueHead(infix))) { //isalnum() just checks if its an integer or an alphabet which works perfectly if its an operator or not
            enqueue(dequeue(&infix), &Postfix); // queues the operands
        }
        else if (queueHead(infix)=='('){
            push(dequeue(&infix),&stack); // pushes the '(' to the stack
        }
        else if(queueHead(infix)==')'){
            while (!stackEmpty(stack) && top(stack) != '(') {
                enqueue(pop(&stack), &Postfix); 
            }
            pop(&stack); // removes the '('
        }
        else if(isOperator((queueHead(infix)))){

            //If top of operator stack precedence is higher than head of infix queue
            if(getPrecedence(top(stack))>getPrecedence(queueHead(infix))){
                //Pop the operator stack, enqueue to post fix queue
                enqueue(pop(&stack),&Postfix);
            }
            // if not, push the operator to the operator stack
            else{
                push(dequeue(&infix),&stack);
            }
        }

    //Any operators left in stack get enqueued to the postfix queue
    while(!stackEmpty(stack)){
            enqueue(pop(&stack),&Postfix);
        }
    
    }
    return Postfix;
}

//