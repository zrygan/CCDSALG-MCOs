/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 2
 * 
 * Header file of the adjency matrix implementation of the graph.
*/

#ifndef ADJENCY_MATRIX
#define ADJENCY_MATRIX

#include "libraries.h"

/**
 * a structure of the adjacency_matrix implementation
 * 
 * @fields: matrix[][] the adjency matrix
 * @fields: vertex the number of vertices in the matrix 
 * 
 * @author Zhean Ganituen
 */
typedef struct
{
    String names[MAX_WIDTH];            // the names in the matrix
    int matrix[MAX_WIDTH][MAX_LENGTH];  // the adjency matrix
    int vertex;                         // number of vertices (i.e., the actual width and length of the matrix)
} adjacency_matrix;

/**
 * displays the adjency matrix
 * 
 * @param matrix the adjency matrix
 * 
 * @author Zhean Ganituen
 */
void displayMatrix(adjacency_matrix matrix);

/**
 * reads the file and makes the adjacency_matrix from the text file content
 * 
 * @param fileName the name of the file 
 * 
 * @author Zhean Ganituen
 */
void getFile(String fileName, adjacency_matrix *matrix);

#endif