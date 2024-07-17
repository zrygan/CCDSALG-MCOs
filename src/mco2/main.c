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
#include "traversal.h"

int main() {
    String fileName; 
    FILE *f;
    adjacency_matrix matrix;
    String start; // start vertex
    // strcpy(fileName, "graph.txt"); // used for debugging
    int start_index;

    printf("Input filename: ");
    scanf("%s", fileName);
    
    f = fopen(fileName, "r");

    if (f != NULL){
        getFile(f, &matrix);
        displayMatrix(matrix); // FIXME: REMOVE THEN WHEN DONE
        make_graph(matrix);
        printf("Input start vertex for the traversal: ");
        scanf("%s", start);
        for (start_index = 0; start_index < matrix.vertex; start_index++) { // checks if vertex exists
            if (!strcasecmp(matrix.names[start_index],start)) {
                // insert BFS traversa; @Viennbalcita
                DFSTraversal(matrix, start_index);
                printf("\n");
                BFStraversal(matrix, start_index);
                return 0;
            }
        }
        printf("%s not found", start);
    } else{
        printf("\033[31m%s not found\033[37m.", fileName);
    }

    return 0;
}
