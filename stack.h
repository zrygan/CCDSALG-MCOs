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