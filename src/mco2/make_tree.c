#include "make_tree.h"

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
char *padding(int d)
{
    if (!d)
        return "";
    char *out = malloc(4 * d + 5);
    out[0] = '\0';

    for (int i = 0; i < 4 * d; i++)
    {
        strncat(out, " ", 2);
    }

    strncat(out, "\\__ ", 5); // add the arrow
    return out;
}

/**
 * Prepares the padding of the node for printing (i.e., the number of spaced before it)
 *
 * @param d the distance of the node
 *
 * @returns the padded arrow for the node
 *
 * @author Zhean Ganituen
 */
void display_tree(tree_node *tree, int vertices, const char *curr, int distance)
{
    char *pad = padding(distance);
    printf("%s%s\n", pad, curr);

    // Create an array to store indices of child nodes
    int child_indices[vertices];
    int child_count = 0;

    // Find all child nodes
    for (int i = 0; i < vertices; i++)
    {
        if (strcmp(tree[i].root, curr) == 0)
        {
            child_indices[child_count++] = i;
        }
    }

    // Sort child nodes based on their names using bubble sort
    for (int i = 0; i < child_count - 1; i++)
    {
        for (int j = 0; j < child_count - i - 1; j++)
        {
            if (strcmp(tree[child_indices[j]].name, tree[child_indices[j + 1]].name) > 0)
            {
                int temp = child_indices[j];
                child_indices[j] = child_indices[j + 1];
                child_indices[j + 1] = temp;
            }
        }
    }

    // Display sorted child nodes
    for (int i = 0; i < child_count; i++)
    {
        display_tree(tree, vertices, tree[child_indices[i]].name, distance + 1);
    }
}

// REMEMBER TO PUT THIS IN main.c [zry]
/*
    // Find the root node and start printing
    for (int i = 0; i < n; i++) {
        if (tree[i].distance == 0) {
            display_tree(tree, n, tree[i].name, 0);
        }
    }
*/

// REMEMBER TO PUT THIS IN bfs.c [zry]
/*
    strcpy(tree[1].name, "NODE_NAME_");
    strcpy(tree[1].root, "ROOT_NAME_");
    tree[1].distance = INT_;
*/