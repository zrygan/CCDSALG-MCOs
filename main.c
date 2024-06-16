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
#include "inToPost.c"
#include "evalPost.c"

int main(){
    
    bool loop = true;
    char infix[MAX_SIZE];
    queue infixQueue = createQueue(MAX_SIZE); queue postfixQueue = createQueue(MAX_SIZE);
    
    while(loop)
    {
        scanf("%s", infix);
            if (strcmp(infix,"QUIT") != 0) {
                infixQueue = tokenize(infix);

                postfixQueue = InfixtoPostfix(infixQueue);
                
                char resetPostfix[MAX_SIZE] = "";

                // turns the postfix queue into a string
                while (!queueEmpty(postfixQueue)) { 
                    char token[MAX_SIZE];
                    char c = dequeue(&infixQueue);
                    strcpy(token,&c);
                    strcat(resetPostfix, token);
                }

                printf("%s\n", resetPostfix);

                //resets the dequeued postfix queue
                postfixQueue = tokenize(resetPostfix);
                
                //insert evaluate functions here
                int result = EvaluatePostfix(postfixQueue);

                printf("%d\n", result);
            }
            else {
                loop = false;
            }

    }

    return 0;
}