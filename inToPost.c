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

//Does not consider tokens with two characters yet
bool isOperator(int operator){
    if (operator == '+' || operator == '-' || operator == '/' || operator == '^' || operator == '%' || 
    operator == '*' || operator == '<' || operator == '>'){
        return true;
    }
    else{
        return false;
    }
}

int getPrecedence(int precedence){
    switch(precedence){
        case '(':
        case ')': return 8;
        case '!': return 7;
        case '^': return 6;
        case '%':
        case '*':
        case '/': return 5;
        case '+':
        case '-': return 4;
        case '<':
        case '>':
        case ">=":
        case "<=":
        case "!=":
        case "==": return 3;
        case "&&": return 2;
        case "||": return 1;
        default: return 0;
    }
}

queue InfixtoPostfix(queue infix){
stack Operators = createStack(infix.elems);
queue Postfix = createQueue(infix.elems);

while(!queueEmpty(infix)){
    //Opening Parenthesis not needed
    if(queueHead(infix)=='('){
        dequeue(&infix);
    }
    else if(isOperator(queueHead(infix))){
        //If top of operator stack precedence is higher than head of infix queue
        if(getPrecedence(top(Operators))>getPrecedence(queueHead(infix))){
            //Pop the operator stack, enqueue to post fix queue
            enqueue(pop(&Operators),&Postfix);
        }
        // if not, push the operator to the operator stack
        else{
            push(dequeue(&infix),&Operators);
        }
    }
    //If the token is an operand, add it to the the postfix queue
    else{
        enqueue(dequeue(&infix),&Postfix);
    }
}
//Any operators left in stack get enqueued to the postfix queue
while(!stackEmpty(Operators)){
    enqueue(pop(&Operators),&Postfix);
}
return Postfix;
}
