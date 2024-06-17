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
#include "intStack.h"
#include "libraries.h"

bool isOperators(const char *str);

int Evaluate(int token1,char *operators,int token2);

int EvaluatePostfix(queue Postfix);

#endif