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
#include "bfs.h"
#include "dfs.h"

int main()
{
    String fileName;         // the file name
    FILE *f;                 // the file pointer
    adjacency_matrix matrix; // the adjaacency matrix
    int start_index;         // start index : the index where the traversal starts
    String start;            // start vertex

    printf("Input filename: ");
    scanf("%s", fileName);

    f = fopen(fileName, "r");

    if (f != NULL)
    {
        make_adjacency_matrix(f, &matrix); 

        display_graph(matrix); // _____FOR ADDITIONAL FEATURE 1 (makes the graph)_____
                               // REMOVE IF NOT NEEDED

        printf("Input start vertex for the traversal: ");
        scanf("%s", start);

        // OUTPUT: the degrees
        int *degrees = malloc(matrix.vertex * sizeof(int));
        calculate_degrees(matrix, degrees);
        for (int i = 0; i < matrix.vertex; i++)
        {
            printf("%s\t%d\n", matrix.names[i], degrees[i]);
        }
        printf("\n");

        // OUTPUT: the BFS and DFS path
        for (start_index = 0; start_index < matrix.vertex; start_index++)
        { // checks if vertex exists
            if (!strcasecmp(matrix.names[start_index], start))
            {
                BFStraversal(matrix, start_index);
                printf("\n\n");
                DFSTraversal(matrix, start_index);
                
                // PRINTING THE TREE
                printf("\n\nTree:\n");
                makeTree(matrix, start_index);
                break;

                return 0;
            }
        }
        printf("%s not found.", start); // node name not found
    }
    else
    {
        printf("%s not found.", fileName); // file not found
    }

    return 0;
}
