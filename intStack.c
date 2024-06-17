#include "intStack.h"

int_stack createIntStack() {
    int_stack Stack;
    Stack.top = -1;
    return Stack;
}

bool intStackEmpty(int_stack Stack) {
    return Stack.top == -1;
}

void intPush(int elem, int_stack* Stack) {
    if (Stack->top < MAX_SIZE - 1) {
        Stack->items[++(Stack->top)] = elem;
    } else {
        printf("Stack overflow\n");
    }
}

int intPop(int_stack* Stack) {
    if (!intStackEmpty(*Stack)) {
        return Stack->items[(Stack->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int intTop(int_stack Stack) {
    if (!intStackEmpty(Stack)) {
        return Stack.items[Stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
