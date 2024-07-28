/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C file of the adjency matrix implementation of the graph.
 */

#include "adjacency_matrix.h"

/**
 * Populate an adjacency matrix from a file.
 *
 * @param f The file pointer.
 * @param matrix The adjacency matrix to populate.
 *
 * @author Zhean Ganituen
 */
void make_adjacency_matrix(FILE *f, adjacency_matrix *matrix)
{
    String line, vertexName;

    fscanf(f, "%d", &matrix->vertex); // get the number in the first line and store in vertex
    fgetc(f);

    // Initialize adjacency matrix
    for (int i = 0; i < matrix->vertex; ++i)
    {
        for (int j = 0; j < matrix->vertex; ++j)
        {
            matrix->matrix[i][j] = 0;
        }
    }

    // Create a mapping of node names to indices
    char **node_names = (char **)malloc(matrix->vertex * sizeof(char *));
    for (int i = 0; i < matrix->vertex; i++)
    {
        node_names[i] = (char *)malloc(256 * sizeof(char));
    }

    int node_index = 0;

    // iterate through the rows in the text file
    while (fgets(line, sizeof(line), f))
    {
        // remove \n at the end
        line[strcspn(line, "\n")] = '\0';

        char *text = strtok(line, " "); // get the next text in the line that is separated by " "
        strcpy(vertexName, text);       // the first text is the vertex name

        int row = -1;
        for (int i = 0; i < node_index; i++)
        {
            if (strcmp(node_names[i], vertexName) == 0)
            {
                row = i; // if found set it as i
                break;
            }
        }

        if (row == -1)
        {
            strcpy(node_names[node_index], vertexName);
            row = node_index;
            node_index++;
        }

        // process the relationships
        while ((text = strtok(NULL, " ")) != NULL)
        {
            if (strcmp(text, "-1") == 0)
                break; // if the col content is -1, then break loop

            int col = -1;
            for (int i = 0; i < node_index; i++)
            {
                // if it is store the ith value in col
                // then break
                if (strcmp(node_names[i], text) == 0)
                {
                    col = i;
                    break;
                }
            }

            if (col == -1)
            {
                strcpy(node_names[node_index], text);
                col = node_index;
                node_index++;
            }

            // indicate that there's a relationship
            matrix->matrix[row][col] = 1;
        }
    }

    // Copy node names to matrix->names
    for (int i = 0; i < matrix->vertex; i++)
    {
        strcpy(matrix->names[i], node_names[i]);
        free(node_names[i]);
    }
    free(node_names);

    diagonals_as_zero(matrix);
}

/**
 * sets the diagonals of the adjacency_matrix as zero.
 *
 * @param matrix the pointer to the adjacency matrix
 *
 * @author Zhean Ganituen
 */
void diagonals_as_zero(adjacency_matrix *matrix)
{
    // make sure that the diagonals are 0
    for (int i = 0; i < matrix->vertex; i++)
    {
        matrix->matrix[i][i] = 0;
    }
}

/**
 * calculates the degrees of each parent node in the adjacency matrix
 *
 * @param matrix the adjacency matrix
 * @param degree an array, the degrees of each parent node in the adjacency matrix
 *
 * @author Zhean Ganituen
 */
void calculate_degrees(adjacency_matrix matrix, int *degrees)
{
    for (int i = 0; i < matrix.vertex; i++)
    {
        int degree = 0;
        for (int j = 0; j < matrix.vertex; j++)
        {
            degree += matrix.matrix[i][j];
        }
        degrees[i] = degree;
    }
}