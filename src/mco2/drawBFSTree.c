/*

root -┐
      ├- A -┐
      │     ├- B
      │     └- C -┐ 
      │           └- D
      ├- E -┐ 
      │     └- F
      └- G
 */

#include <stdio.h>
#include <string.h>

typedef char String[256];
#define _DASH 196 // ┐
#define _ROOT 191 // ─
#define _VERT 124 // │
#define _LAST 192 // └
#define _SPLT 195 // ├

int initRoot(String rootName){
    String rootNode;
    sprintf(rootNode, "%s %c%c", rootName, _DASH, _ROOT);
    printf("%s", rootNode);
    // get length of root

    return strlen(rootNode);
}