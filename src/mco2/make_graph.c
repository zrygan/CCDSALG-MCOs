/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C file of the graph visualization.
 */

#include "adjacency_matrix.h" // no need to put libraries.h since display_graph.h
                              // already has that (circular import)
#include "make_graph.h"

#define _ARROW " -----> "
#define _SEPRT "        " // same length as the arrow (for separating)

/**
 * function definition for display_graph, see display_graph in `make_graph.h`
 *
 * @param matrix the adjency matrix
 *
 * @author Zhean Ganituen
 */
void display_graph(adjacency_matrix matrix)
{
    for (int i = 0; i < matrix.vertex; i++){
        char *border = (char*)malloc(100 * sizeof(char));
        char *content = (char*)malloc(100 * sizeof(char));

        border[0] = '\0';
        content[0] = '\0';
        strcat(border, make_border_line(strlen(matrix.names[i])));
        strcat(content, make_name(matrix.names[i]));

        strcat(border, _SEPRT);
        strcat(content, _ARROW);
        for (int j = 0; j < matrix.vertex; j++){
            if (matrix.matrix[i][j]){
                strcat(border, make_border_line(strlen(matrix.names[j])));
                strcat(content, make_name(matrix.names[j]));

                strcat(border, _SEPRT);
                strcat(content, _ARROW);
            }
        }
        String null = "NULL";
        strcat(border, make_border_line(strlen(null)));
        strcat(content, make_name(null));

        printf("%s\n%s\n%s\n\n", border, content, border);

        free(border);
        free(content);
    }
}

char *make_border_line(int len){
    char *out = (char*)malloc((len + 5) * sizeof(char));
    out[0] = '\0';

    for (int i = 0; i < len + 4; i++) {
        strcat(out, "-");
    }

    return out;
}

char *make_name(String name){
    char *out = (char*)malloc((strlen(name) + 5) * sizeof(char));
    out[0] = '\0';

    strcat(out, "- ");
    strcat(out, name);
    strcat(out, " -");

    return out;
}