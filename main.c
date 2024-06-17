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

int main() {
    bool loop = true;

    while(loop) {
        char infixExpression[MAX_SIZE];
        printf("Enter an infix expression (or QUIT to exit): ");
        scanf("%s", infixExpression);

        if (strcmp(infixExpression, "QUIT") == 0) {
            loop = false;
        } else {
            queue infixQueue = createQueue(MAX_SIZE);
            for (int i = 0; i < strlen(infixExpression); i++) {
                enqueue(infixExpression[i], &infixQueue);
            }

            queue postfixQueue = InfixtoPostfix(infixQueue);

            char postfixString[MAX_SIZE] = "";
            while (!queueEmpty(postfixQueue)) {
                char c = dequeue(&postfixQueue);
                strncat(postfixString, &c, 1);
            }

            printf("POSTFIX STRING: %s\n", postfixString);

            // Reset postfix queue for evaluation
            queue evaluationQueue = createQueue(MAX_SIZE);
            for (int i = 0; i < strlen(postfixString); i++) {
                enqueue(postfixString[i], &evaluationQueue);
            }

            int result = EvaluatePostfix(evaluationQueue);

            printf("Evaluation Result: %d\n", result);
        }
    }

    return 0;
}