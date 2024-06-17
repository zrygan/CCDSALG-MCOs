#ifndef INTSTACK
#define INTSTACK

#include "libraries.h"

typedef struct {
    int items[MAX_SIZE];
    int top;
} int_stack;

int_stack createIntStack();

bool intStackEmpty(int_stack Stack);

void intPush(int elem, int_stack* Stack);

int intPop(int_stack* Stack);

int intTop(int_stack Stack);

#endif