#include "make_tree.h"

char *padding(int d){
    if (!d) return "";
    char *out = malloc(4*d+5);
    out[0] = '\0';
    
    for (int i = 0; i < 4 * d; i++){
        strcat(out, " ");
    }
    
    strcat(out, "\\__ "); // add the arrow
    strcat(out, "\0");
    return out;
}

void display_tree(tree_node *tree, int vertices, const char *curr, int distance){
    char *pad = padding(distance);
    printf("%s%s\n", pad, curr);
    free(pad); // free the allocated memory

    for (int i = 0; i < vertices; i++){
        if (strcmp(tree[i].root, curr) == 0){
            display_tree(tree, vertices, tree[i].name, distance + 1);
        }
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