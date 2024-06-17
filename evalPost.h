/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Header file of stack data structure.
*/

#ifndef EVALPOST
#define EVALPOST

#include "queue.h"
#include "stack.h"
#include "libraries.h"

bool isOperators(char precedence);

int Evaluate(int token1,int operators, int token2);

int EvaluatePostfix(queue Postfix);

#endif