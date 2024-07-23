
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
 * Creates a graphical visualization of the graph using a linked list
 *
 * @param matrix the matrix
 *
 * @author Zhean Ganituen
 */
void display_graph(adjacency_matrix matrix);

/**
 * Creates a border line for the graph visualization
 * 
 * @param len the length of the line
 * 
 * @returns the border line created
 */
char *make_border_line(int len);

/**
 * Creates a name box for the graph visualization
 * 
 * @param len the name
 * 
 * @returns the name box created
 */
char *make_name(String name);


#endif
