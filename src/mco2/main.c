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
#include "libraries.h"

int main() {
    String fileName; 
    adjacency_matrix matrix;
    strcpy(fileName, "graph.txt"); // used for debugging

    // printf("Input filename: ");
    // scanf("%s", fileName);
    
    getFile(fileName, &matrix);
    displayMatrix(matrix);

    for(int i = 0; i < matrix.vertex; i++){
        printf("%s, ", matrix.names[i]);
    }

    return 0;
}
