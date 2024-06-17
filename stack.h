#ifndef STACK
#define STACK

#include "libraries.h"

typedef struct
{
    char* items[MAX_SIZE];
    int top;
} stack;

stack createStack();

void push(char *elem, stack *Stack);

char* pop(stack* Stack);

bool stackEmpty(stack Stack);

char* top(stack Stack);

#endif