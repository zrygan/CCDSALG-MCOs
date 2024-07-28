/**
 * balcita, v.
 * ganituen, z.
 * jimenez, j.
 *
 * CCDSALG, Project 2
 *
 * Header file for tree illustration of the BFS
 */

#ifndef MAKE_TREE
#define MAKE_TREE

#include "libraries.h"

/**
 * A structure for the tree_node, a tree is an array of this struct
 *
 * @fields:
 *  {name} the name of the node
 *  {distance} the distance of the node from the root node (if node is root, distance == 0)
 *  {root} the root node of the node (if it is a child, if it is the root then "")
 *
 * @author Zhean Ganituen
 */
typedef struct tree_node
{
    String name;
    int distance;
    String root;
} tree_node;

/**
 * Displays the tree created
 *
 * @param tree a pointer to the tree (an array of tree_nodes)
 * @param vertices the number of vertices in the adj. matrix (graph)
 * @param curr the current node
 * @param distance the distance of the current node
 *
 * @author Zhean Ganituen
 */
void display_tree(tree_node *tree, int vertices, const char *curr, int distance);

/**
 * Prepares the padding of the node for printing (i.e., the number of spaced before it)
 *
 * @param d the distance of the node
 *
 * @returns the padded arrow for the node
 *
 * @author Zhean Ganituen
 */
char *padding(int d);

#endif