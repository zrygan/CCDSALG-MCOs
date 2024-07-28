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
typedef struct tree_node
{
    String name;
    int distance;
    String root;
    bool checker;
} tree_node;

void display_tree(tree_node *tree, int vertices, const char *curr, int distance);

char *padding(int d);

#endif