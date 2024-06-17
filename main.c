/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Main C file of Part 1 of the project.
*/

#include "libraries.h"
#include "stack.h"
#include "queue.h"
#include "inToPost.h"
#include "evalPost.h"

void printQueue(queue q) {
  printf("Queue: ");
  if (queueEmpty(q)) {
    printf("Empty\n");
    return;
  }
  for (int i = q.head; i <= q.tail; i++) {
    printf("%s ", q.items[i]);
  }
  printf("\n");
}

int main() {
    bool loop = true;

    while (loop) {
        char infixExpression[MAX_SIZE];
        printf("Enter an infix expression (or QUIT to exit): ");
        scanf("%s", infixExpression);

        if (strcmp(infixExpression, "QUIT") == 0) {
            loop = false;
        } else {
            queue infixQueue = createQueue(MAX_SIZE);
            
            // Store infix expression into infixQueue
            char num[MAX_SIZE]; // Temporary array to store numbers
            int numIndex = 0;
            for (int i = 0; infixExpression[i] != '\0'; i++) {
                if (isdigit(infixExpression[i])) {
                num[numIndex++] = infixExpression[i];
                } else {
                if (numIndex > 0) {
                    num[numIndex] = '\0'; // Null terminate the string
                    enqueue(num, &infixQueue);
                    numIndex = 0; // Reset index for next number
                }
                char op[2] = {infixExpression[i], '\0'};
                enqueue(op,&infixQueue);
                }
            }
            // Don't forget to enqueue the last number in the expression
            if (numIndex > 0) {
                num[numIndex] = '\0';
                enqueue(num, &infixQueue);
            }

            printf("Infix expression: ");
            printQueue(infixQueue);
            
            queue postfixQueue = InfixtoPostfix(infixQueue);

            printf("Postfix expression: ");
            printQueue(postfixQueue);

            int result = EvaluatePostfix(postfixQueue);
            printf("Evaluation Result: %d\n", result);
        }
    }

    return 0;
}