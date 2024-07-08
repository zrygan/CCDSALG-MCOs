/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * Main C file of Part 2 of the project.
*/

#include "adjacency_matrix.h"
#include "make_graph.h"
#include "libraries.h"

int main() {
    String fileName; 
    FILE *f;
    adjacency_matrix matrix;
    // strcpy(fileName, "graph.txt"); // used for debugging

    printf("Input filename: ");
    scanf("%s", fileName);
    
    f = fopen(fileName, "r");

    if (f != NULL){
        getFile(f, &matrix);
        displayMatrix(matrix);
        make_graph(matrix);
    } else{
        printf("\033[31m%s not found\033[37m.", fileName);
    }

    return 0;
}
