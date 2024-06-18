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

/**printQueue
 * prints the expression inside the items[] inside of the queue
 * 
 * @params:
 * - q   : queue    : a queue containing the expression to be printed
 * 
 * @returns:
 * none
 * 
 * @author: Jaztin Jimenez
 */
void printQueue(queue q) {
  if (queueEmpty(q)) { // checks if the queue is empty
    printf("Empty\n");
    return;
  }
  for (int i = q.head; i <= q.tail; i++) {
    printf("%s ", q.items[i]); // prints out all of the strings inside queue
  }
  printf("\n");
}

int main() {
    bool loop = true; // loop for the program

    while (loop) {
        char infixExpression[MAX_SIZE];
        scanf("%s", infixExpression);

        if (strcmp(infixExpression, "QUIT") == 0) {
            loop = false;
        } else {
            queue infixQueue = createQueue(MAX_SIZE);
            
            // Store infix expression into infixQueue
            char num[MAX_SIZE]; // Temporary array to store numbers
            int numIndex = 0;
            for (int i = 0; infixExpression[i] != '\0'; i++) { // Loop until the end of the string
                if (isdigit(infixExpression[i])) {
                num[numIndex++] = infixExpression[i]; // Increment and add the integer to the array
                } else {
                    if (numIndex > 0) {
                        num[numIndex] = '\0'; // Null terminate the string
                        enqueue(num, &infixQueue);
                        numIndex = 0; // Reset index for next number
                    }
                    // Check if it's a two-character operator
                    if (i < strlen(infixExpression) - 1 &&
                        (infixExpression[i] == '>' || infixExpression[i] == '<' || infixExpression[i] == '!' ||
                        infixExpression[i] == '=' || infixExpression[i] == '|' || infixExpression[i] == '&')) {
                        char op[3] = {infixExpression[i], infixExpression[i + 1], '\0'};
                        enqueue(op, &infixQueue);
                        i++; // Skip the second character
                    } else {
                        char op[2] = {infixExpression[i], '\0'};
                        enqueue(op, &infixQueue);
                    }
                }
            }

            // Don't forget to enqueue the last number in the expression
            if (numIndex > 0) {
                num[numIndex] = '\0';
                enqueue(num, &infixQueue);
            }
            
            queue postfixQueue = InfixtoPostfix(infixQueue);

            printQueue(postfixQueue);

            int result = EvaluatePostfix(postfixQueue);

            if (result == -99999999) {
                printf("Division by zero error!\n");
            }
            else {
                printf("%d\n", result); // FOR TRACK PURPOSES (soon to be deleted)
            }

            printf("\n");
        }
    }

    return 0;
}