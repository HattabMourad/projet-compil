#include <stdio.h>
#include <string.h>
#include "quads.h"

Quadruple quadTable[MAX_QUADS];
int quadIndex = 0;

void addQuad(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (quadIndex < MAX_QUADS) {
        strncpy(quadTable[quadIndex].op, op, 9);
        quadTable[quadIndex].op[9] = '\0';
        strncpy(quadTable[quadIndex].arg1, arg1, 31);
        quadTable[quadIndex].arg1[31] = '\0';
        strncpy(quadTable[quadIndex].arg2, arg2, 31);
        quadTable[quadIndex].arg2[31] = '\0';
        strncpy(quadTable[quadIndex].result, result, 31);
        quadTable[quadIndex].result[31] = '\0';
        quadIndex++;
    }
}

void printQuads() {
    printf("\nQuadruples Table:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%d: (%s, %s, %s, %s)\n", i, quadTable[i].op, quadTable[i].arg1, quadTable[i].arg2, quadTable[i].result);
    }
}
