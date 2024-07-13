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
#include "transversal_DFS.h" 

int main() {
    String fileName; 
    FILE *f;
    adjacency_matrix matrix;
    String start; // start vertex
    // strcpy(fileName, "graph.txt"); // used for debugging

    printf("Input filename: ");
    scanf("%s", fileName);
    
    f = fopen(fileName, "r");

    if (f != NULL){
        getFile(f, &matrix);
        displayMatrix(matrix); // FIXME: REMOVE THEN WHEN DONE
        make_graph(matrix);
        printf("Input start vertex for the traversal: ");
        scanf("%s", start);
        for (int i = 0; i < matrix.vertex; i++) { // checks if vertex exists
            if (!strcasecmp(matrix.names[i],start)) {
                // insert BFS Transversal @Viennbalcita
                DFSTraversal(matrix, i);
                return 0;
            }
        }
        printf("%s not found", start);
    } else{
        printf("\033[31m%s not found\033[37m.", fileName);
    }

    return 0;
}
