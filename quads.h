#ifndef QUADS_H
#define QUADS_H

#define MAX_QUADS 1000

typedef struct {
    char op[10];
    char arg1[32];
    char arg2[32];
    char result[32];
} Quadruple;

extern Quadruple quadTable[MAX_QUADS];
extern int quadIndex;

void addQuad(const char* op, const char* arg1, const char* arg2, const char* result);
void printQuads();
void optimizeQuads();

#endif
