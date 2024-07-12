/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 *
 * CCDSALG, Project 2
 *
 * C file of the graph visualization.
 */

#include "adjacency_matrix.h" // no need to put libraries.h since adjacency_matrix.h
                              // already has that (circular import)

/* verify
 * verifies if the name of the node is LOGGED already (to remove duplicates of the node name)
 * 
 * @param 
 * 
*/
bool verify(String logger[][2], String base, String connection, int total){
    for (int log = 0; log < total; log++){
        if ((strcmp(logger[log][0], base) == 0 && strcmp(logger[log][1], connection) == 0) || 
            (strcmp(logger[log][0], connection) == 0 && strcmp(logger[log][1], base) == 0)){
            return false;
        }
    }

    return true;
}

void make_graph(adjacency_matrix matrix){
    FILE *fp = fopen("graph.dot", "w");
    fprintf(fp, "graph {\n");

    // adjacency is commutable for undirected graphs
    // i.e., bruce -- diana == diana -- bruce
    // make a checker to not add it if a commutative equivalent is already done

    // for logging if commutable equivalent is already added 
    String (*logger)[2] = malloc(matrix.vertex * matrix.vertex * sizeof(*logger)); // there are a total of n^2 possible relationships
                                                                                   // including commutative equivalents
                                                                                   // logger = [[<base>, <connection>], [<base>, <connection>]]
    // init logger
    for (int i = 0; i < matrix.vertex * matrix.vertex; ++i) {
        strcpy(logger[i][0], "none");
        strcpy(logger[i][1], "none");
    }

    int logs = 0;

    for (int row = 0; row < matrix.vertex; row++){
        for (int col = 0; col < matrix.vertex; col++){
            if(matrix.matrix[row][col] == 1 && verify(logger, matrix.names[row], matrix.names[col], matrix.vertex * matrix.vertex)){
                // if there is a connection
                fprintf(fp, " %s -- %s;\n", matrix.names[row], matrix.names[col]);
                strcpy(logger[logs][0], matrix.names[row]); // copy the name of the current line in the logger
                strcpy(logger[logs][1], matrix.names[col]);
                logs++;
            }
        }
    }

    fprintf(fp, "}");
    fclose(fp);

    // run the CLI command to compile the DOT file as PNG
    // THIS LINE NEEDS GRAPHVIZ
    system("dot -Tpng graph.dot -o graph.png");

    // delete the DOT file
    // we can remove this if we want to keep it, but i don't
    // think it's necessary
    system("del graph.dot");
}