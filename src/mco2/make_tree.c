/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C file of the tree illustration of the BFS.
 */

#include "make_tree.h"

// for ascii art (remove if not needed)
#define _DASH 196 // ┐
#define _ROOT 191 // ─
#define _VERT 124 // │
#define _LAST 192 // └
#define _SPLT 195 // ├

/**
 * constructs a string output that makes the home node the parent of the dest node
 *
 * @param home the home node (or parent)
 * @param dest the destination node (or child)
 *
 * @returns a formatted string that dictates the relationship of the two nodes
 */
char *make_tree_relate(String home, String dest)
{
    // FIXME: _____OLD IMPLEMENTATION_____
    // SAVED FOR NOTES
    // char *rel;
    // String hometemp;
    // String desttemp;
    // strcpy(hometemp, home);
    // strcpy(desttemp, dest);
    // rel = strcat(hometemp, " -> ");
    // char *out = strcat(rel, desttemp);
    // return out;
    return NULL; // returned null here to avoid errors
}

/**
 * draws the tree of the BFS using GraphViz by creating a dot file
 * required GraphViz
 *
 * @param nodes[] the array of nodes and their corresponding children
 * @param n the number of nodes
 */
void make_tree(String nodes[], int n)
{
    // FIXME: _____OLD IMPLEMENTATION_____
    // SAVED FOR NOTES
    // FILE *fp = fopen("tree.dot", "w");
    // fprintf(fp, "graph {n}");

    // for (int i = 0; i < n; i++)
    // {
    //     fprintf(fp, "\t%s\t", nodes[i]);
    // }

    // fclose(fp);
}