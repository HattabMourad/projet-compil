#include <stdio.h>
#include <string.h>
#include "quads.h"
#include "codegen.h"

void generateAssembly(const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Cannot open %s for writing.\n", filename);
        return;
    }
    fprintf(f, "; Assembly generated from quadruples\n");
    for (int i = 0; i < quadIndex; i++) {
        Quadruple* q = &quadTable[i];
        if (strcmp(q->op, "+") == 0) {
            fprintf(f, "MOV AX, %s\n", q->arg1);
            fprintf(f, "ADD AX, %s\n", q->arg2);
            fprintf(f, "MOV %s, AX\n", q->result);
        } else if (strcmp(q->op, "-") == 0) {
            fprintf(f, "MOV AX, %s\n", q->arg1);
            fprintf(f, "SUB AX, %s\n", q->arg2);
            fprintf(f, "MOV %s, AX\n", q->result);
        } else if (strcmp(q->op, "*") == 0) {
            fprintf(f, "MOV AX, %s\n", q->arg1);
            fprintf(f, "IMUL AX, %s\n", q->arg2);
            fprintf(f, "MOV %s, AX\n", q->result);
        } else if (strcmp(q->op, "/") == 0) {
            fprintf(f, "MOV AX, %s\n", q->arg1);
            fprintf(f, "CWD\n");
            fprintf(f, "IDIV %s\n", q->arg2);
            fprintf(f, "MOV %s, AX\n", q->result);
        } else if (strcmp(q->op, "=") == 0) {
            fprintf(f, "MOV %s, %s\n", q->result, q->arg1);
        } else {
            fprintf(f, "; Unhandled quad: (%s, %s, %s, %s)\n", q->op, q->arg1, q->arg2, q->result);
        }
    }
    fclose(f);
    printf("Assembly code written to %s\n", filename);
}
