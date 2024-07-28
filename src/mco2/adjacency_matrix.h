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
    String names[MAX_VERTICES];             // the names (or vertices) in the matrix
    int matrix[MAX_VERTICES][MAX_VERTICES]; // the adjency matrix
    int vertex;                             // number of vertices (i.e., the actual width and length of the matrix)
} adjacency_matrix;

/**
 * displays the adjency matrix
 * ___FOR DEBUGGING___
 * @param matrix the adjency matrix
 *
 * @author Zhean Ganituen
 */
void display_matrix(adjacency_matrix matrix);

/**
 * Populate an adjacency matrix from a file.
 *
 * @param f The file pointer.
 * @param matrix The adjacency matrix to populate.
 *
 * @author Zhean Ganituen
 */
void make_adjacency_matrix(FILE *f, adjacency_matrix *matrix);

/**
 * sets the diagonals of the adjacency_matrix as zero.
 *
 * @param matrix the pointer to the adjacency matrix
 */
void diagonals_as_zero(adjacency_matrix *matrix);

/**
 * calculates the degrees of each parent node in the adjacency matrix
 *
 * @param matrix the adjacency matrix
 * @param degree an array, the degrees of each parent node in the adjacency matrix
 */
void calculate_degrees(adjacency_matrix matrix, int *degrees);

#endif