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
        // read entire line
        fgets(line, sizeof(line), f);
        sscanf(line, "%s", matrix->names[i]);
        for (int j = 0; j < matrix->vertex; ++j)
        {
            matrix->matrix[i][j] = 0;
        }
    }

    // Reset file pointer to the beginning
    rewind(f);

    fscanf(f, "%d", &matrix->vertex); // get the number again to skip the vertex count line
    fgetc(f);                         // consume newline after reading vertex count

    // iterate through the rows in the text file
    // we can't do a single scanf that reads all text in the row since the number of text in each row is not constant
    // so what we can do is like make separate Strings from the line (separated by " ")
    // get the entire line
    while (fgets(line, sizeof(line), f))
    {
        // remove \n at the end
        line[strcspn(line, "\n")] = '\0';

        char *text = strtok(line, " "); // get the next text in the line that is separated by " "
        strcpy(vertexName, text);       // the first text is the vertex name

        // no need to default to not found or handle if the name is not found
        // since we initialized the names at the start
        int row;
        for (int i = 0; i < matrix->vertex; i++)
        {
            if (strcmp(matrix->names[i], vertexName) == 0)
            {
                row = i; // if found set it as i
                break;
            }
        }

        // process the relationships
        while ((text = strtok(NULL, " ")) != NULL)
        {
            if (strcmp(text, "-1") == 0)
                break; // if the col content is -1, then break loop

            int col;
            for (int i = 0; i < matrix->vertex; i++)
            {
                // if it is store the ith value in col
                // then break
                if (strcmp(matrix->names[i], text) == 0)
                {
                    col = i;
                    break;
                }
            }

            // indicate that there's a relationship
            matrix->matrix[row][col] = 1;
        }
    }

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