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
 * constructs a string output that makes the home node the parent of the dest node
 *
 * @param home the home node (or parent)
 * @param dest the destination node (or child)
 *
 * @returns a formatted string that dictates the relationship of the two nodes
 */
char *node(String home, String dest);

/**
 * draws the tree of the BFS using GraphViz by creating a dot file
 * required GraphViz
 *
 * @param nodes[] the array of nodes and their corresponding children
 * @param n the number of nodes
 */
void make_tree(String nodes[], int n);

#endif