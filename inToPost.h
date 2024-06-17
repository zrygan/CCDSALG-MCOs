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

bool isOperator(char precedence);

queue tokenize(const char* infix);

int getPrecedence(char precedence);

queue InfixtoPostfix(queue infix);

#endif