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
#include "libraries.h"

/**
 * function definition for displayMatrix, see displayMatrix in `adjacency_matrix.h`
 *
 * @param matrix the adjency matrix
 *
 * @author Zhean Ganituen
 */
void displayMatrix(adjacency_matrix matrix)
{
    printf("Adjacency Matrix:\n");

    // Print column headers (vertex names)
    printf("\t");
    for (int col = 0; col < matrix.vertex; col++)
    {
        printf("%s\t", matrix.names[col]);
    }
    printf("\n");

    // Print matrix rows
    for (int row = 0; row < matrix.vertex; row++)
    {
        printf("%s ", matrix.names[row]);

        for (int col = 0; col < matrix.vertex; col++)
        {
            printf("\t%d ", matrix.matrix[row][col]);
        }
        printf("\n");
    }
}

/**
 * Function definition for getFile, see getFile in `libraries.h`
 *
 * @param fileName The name of the file to get.
 * @param matrix The adjacency matrix to populate.
 *
 * @author Zhean Ganituen
 */
void getFile(FILE *f, adjacency_matrix *matrix)
{
    String line;
    fgets(line, sizeof(line), f);        // get the first line (contains number of vertices)
    sscanf(line, "%d", &matrix->vertex); // get the number in the first line and store in vertex
    int row = 0;
    // iterate through the rows in the text file
    // we can't do a single scanf that reads all text in the row since the number of text in each row
    // so what we can do is like make separate Strings from the line (separated by " ")
    // get the entire line
    while (fgets(line, sizeof(line), f))
    {
        // remove \n at the end
        line[strcspn(line, "\n")] = '\0';

        char *text = strtok(line, " "); // get the next text in the line that is separated by " "
        int col = 0;
        while (text != NULL)
        {
            if (strcmp(text, "-1") == 0)
                break; // if the col content is -1, then break loop

            // check if the name is new, if so add in the list of names
            int finder = 0;

            // do linear search of name in names
            for (int i = 0; i < matrix->vertex; i++)
            {
                if (strcmp(matrix->names[i], text) == 0)
                {
                    // if it is found then add 1 in the position of the name in the list
                    if (row != i)
                        matrix->matrix[row][i] = 1;
                    finder = 1;
                    break;
                }
            }
            if (finder == 0)
            {
                // if name not in names
                // add name in names
                strcpy(matrix->names[col], text);

                // insert 1 at the column number (matrix->vertex) to denote the connection
                matrix->matrix[row][col] = 1;
                col++;
            }

            text = strtok(NULL, " ");
        }

        // make sure that the vertex is not connected to itself
        if (matrix->matrix[row][row] == 1)
        {
            matrix->matrix[row][row] = 0;
        }

        row++;
    }
}