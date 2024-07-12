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
 * function definition for displayMatrix, see displayMatrix in `adjacency_matrix.h`
 ******FOR DEBUGGING ***** not to be placed in the actual output
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
    char *text;

    fgets(line, sizeof(line), f);        // get the first line (contains number of vertices)
    sscanf(line, "%d", &matrix->vertex); // get the number in the first line and store in vertex

    // Initialize adjacency matrix
    for (int i = 0; i < matrix->vertex; ++i)
    {
        for (int j = 0; j < matrix->vertex; ++j)
        {
            matrix->matrix[i][j] = 0;
        }
    }

    int vertex = 0;

    // iterate through the rows in the text file
    // we can't do a single scanf that reads all text in the row since the number of text in each row is not constant
    // so what we can do is like make separate Strings from the line (separated by " ")
    // get the entire line
    while (fgets(line, sizeof(line), f))
    {
        // remove \n at the end
        line[strcspn(line, "\n")] = '\0';

        text = strtok(line, " "); // get the next text in the line that is separated by " "

        // the first text is the vertex name
        String vertexName;
        strcpy(vertexName, text);

        // get the vertex names and add in matrix->names
        int row = -1; // default to not found
        for (int i = 0; i < vertex; i++)
        {
            if (strcmp(matrix->names[i], vertexName) == 0)
            {
                row = i; // if found set it as i
                break;
            }
        }

        if (row == -1)
        {
            row = vertex;
            strcpy(matrix->names[vertex], vertexName);
            vertex++;
        }

        // process the relationships
        
        while ((text = strtok(NULL, " ")) != NULL)
        {
            if (strcmp(text, "-1") == 0)
                break; // if the col content is -1, then break loop

            // check if the name exists
            // assume not
            int col = -1;
            for(int i = 0; i < vertex; i++){
                // if it is store the ith value in col
                // then break
                if(strcmp(matrix->names[i], text) == 0){
                    col = i;
                    break;
                }
            }

            // if not add it in names
            if (col == -1){
                col = vertex;
                strcpy(matrix->names[vertex], text);
                vertex++;
            }
            
            // indicate that there's a relationship
            matrix->matrix[row][col] = 1;
        }
    }

    // make sure that the diagonals are 0
    for (int i = 0; i < matrix->vertex; ++i){
        // ???? WHY DO I NEED ++i here... doesn't work when it's i++
        matrix->matrix[i][i] = 0;
    }
}