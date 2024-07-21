
/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * User defined functions to make a image (png) of the grapg
 */

#ifndef MAKE_GRAPH
#define MAKE_GRAPH

/**
 * makes a dot file and png of the matrix
 * requires Graphviz
 *
 * @param matrix the matrix
 *
 * @author Zhean Ganituen
 */
void make_graph(adjacency_matrix matrix);

/**
 * verifies if the relationship of the two vertices are already drawn
 *
 * @param logger an array of logged relationships
 * @param base the "home" vertex
 * @param connection the "adjacent" vertex
 * @param total the total relationships in the graph
 *
 * @return {true} if there's no relationship drawn yet, {false} otherwise
 */
bool verify(String logger[][2], String base, String connection, int total);

#endif
