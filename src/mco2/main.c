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
#include "make_tree.h"

int main()
{
    String fileName;         // the file name
    FILE *f;                 // the input file pointer
    FILE *m;                 // the output file pointer
    adjacency_matrix matrix; // the adjaacency matrix
    tree_node *tree;
    int start_index; // start index : the index where the traversal starts
    String start;    // start vertex

    printf("Input filename: ");
    scanf("%s", fileName);

    f = fopen(fileName, "r");

    if (f != NULL)
    {
        make_adjacency_matrix(f, &matrix);
        fclose(f);

        // initialize the tree
        tree = malloc(matrix.vertex * sizeof(tree_node));

        printf("Input start vertex for the traversal: ");
        scanf("%s", start);
        printf("\n"); // spacer

        // OUTPUT: the BFS and DFS path
        for (start_index = 0; start_index < matrix.vertex; start_index++)
        { // checks if vertex exists
            if (!strcasecmp(matrix.names[start_index], start))
            {  
                // OUTPUT: the degrees
                m = fopen("TRAVERSALS.txt", "w");

                int *degrees = malloc(matrix.vertex * sizeof(int));
                calculate_degrees(matrix, degrees);
                for (int i = 0; i < matrix.vertex; i++)
                {
                    fprintf(m, "%s\t%d\n", matrix.names[i], degrees[i]);
                }
                fprintf(m,"\n");

                BFStraversal(matrix, start_index, tree, m); // OUTPUT: BFS
                fprintf(m,"\n\n");                          // SPACER
                DFSTraversal(matrix, start_index, m);       // OUTPUT: DFS
                
                // _____ADDITIONAL FEATURE_____
                // (makes the graph)
                // COMMENT OUT, IF NOT NEEDED
                printf("Graph:\n");
                display_graph(matrix);

                // _____ADDITIONAL FEATURE_____ <start>
                // (makes the graph)
                // COMMENT OUT, IF NOT NEEDED
                printf("Tree:\n");
                for (int i = 0; i < matrix.vertex; i++)
                {
                    if (tree[i].distance == 0)
                    {
                        display_tree(tree, matrix.vertex, tree[i].name, 0);
                    }
                }

                fclose(m);
                return 0;
            }
        }
        printf("Vertex %s not found.", start); // node name not found
    }
    else
    {
        printf("%s not found.", fileName); // file not found
    }

    return 0;
}