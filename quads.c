#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "quads.h"

Quadruple quadTable[MAX_QUADS];
int quadIndex = 0;

static int tempCount = 0;
static int labelCount = 0;

void addQuad(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (quadIndex < MAX_QUADS) {
        // Copy operation and arguments with bounds checking
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

// Print all quadruples in the table for debugging
void printQuads() {
    printf("\nQuadruples Table:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%d: (%s, %s, %s, %s)\n", i, quadTable[i].op, quadTable[i].arg1, quadTable[i].arg2, quadTable[i].result);
    }
}

// Check if a variable is used in any quad after a given index
static bool isVarUsedAfter(const char* var, int from) {
    for (int i = from + 1; i < quadIndex; ++i) {
        if (strcmp(quadTable[i].arg1, var) == 0 ||
            strcmp(quadTable[i].arg2, var) == 0) {
            return true;
        }
    }
    return false;
}

// Optimize the quadruple table using various optimization techniques
void optimizeQuads() {
    int writeIdx = 0;
    
    // Phase 1: Basic algebraic optimizations
    for (int readIdx = 0; readIdx < quadIndex; ++readIdx) {
        Quadruple* q = &quadTable[readIdx];
        
        // Skip self-assignments (x = x)
        if (strcmp(q->op, "=") == 0 && strcmp(q->arg1, q->result) == 0 && strlen(q->arg2) == 0) continue;
        
        // Optimize additions and subtractions with 0
        // x + 0 = x, 0 + x = x, x - 0 = x
        if ((strcmp(q->op, "+") == 0 || strcmp(q->op, "-") == 0) &&
            ((strcmp(q->arg2, "0") == 0) || (strcmp(q->arg1, "0") == 0))) {
            if (strcmp(q->arg2, "0") == 0) {
                strcpy(q->op, "="); strcpy(q->arg2, ""); strcpy(q->arg1, q->arg1);
            } else {
                strcpy(q->op, "="); strcpy(q->arg2, ""); strcpy(q->arg1, q->arg2);
            }
        }
        
        // Optimize multiplications by 1
        // x * 1 = x, 1 * x = x
        if ((strcmp(q->op, "*") == 0) &&
            ((strcmp(q->arg2, "1") == 0) || (strcmp(q->arg1, "1") == 0))) {
            if (strcmp(q->arg2, "1") == 0) {
                strcpy(q->op, "="); strcpy(q->arg2, ""); strcpy(q->arg1, q->arg1);
            } else {
                strcpy(q->op, "="); strcpy(q->arg2, ""); strcpy(q->arg1, q->arg2);
            }
        }
        
        // Optimize multiplications by 0
        // x * 0 = 0, 0 * x = 0
        if ((strcmp(q->op, "*") == 0) &&
            ((strcmp(q->arg2, "0") == 0) || (strcmp(q->arg1, "0") == 0))) {
            strcpy(q->op, "="); strcpy(q->arg1, "0"); strcpy(q->arg2, "");
        }
        
        // Keep optimized quad
        if (writeIdx != readIdx) quadTable[writeIdx] = *q;
        writeIdx++;
    }
    quadIndex = writeIdx;

    // Phase 2: Copy propagation
    // Replace uses of copied variables with their original value
    for (int i = 0; i < quadIndex; ++i) {
        Quadruple* q = &quadTable[i];
        if (strcmp(q->op, "=") == 0 && strlen(q->arg2) == 0) {
            const char* src = q->arg1;    // Original value
            const char* dest = q->result;  // Copied variable
            // Replace all uses of the copied variable with the original
            for (int j = i + 1; j < quadIndex; ++j) {
                if (strcmp(quadTable[j].arg1, dest) == 0) strcpy(quadTable[j].arg1, src);
                if (strcmp(quadTable[j].arg2, dest) == 0) strcpy(quadTable[j].arg2, src);
            }
        }
    }

    // Phase 3: Common subexpression elimination
    // Find and eliminate redundant computations
    for (int i = 0; i < quadIndex; ++i) {
        Quadruple* qi = &quadTable[i];
        if (strcmp(qi->op, "=") == 0) continue;  // Skip simple assignments
        
        for (int j = i + 1; j < quadIndex; ++j) {
            Quadruple* qj = &quadTable[j];
            // If we find the same operation with same operands
            if (strcmp(qi->op, qj->op) == 0 &&
                strcmp(qi->arg1, qj->arg1) == 0 &&
                strcmp(qi->arg2, qj->arg2) == 0) {
                // Replace all uses of the redundant result with the first computation's result
                for (int k = j + 1; k < quadIndex; ++k) {
                    if (strcmp(quadTable[k].arg1, qj->result) == 0) strcpy(quadTable[k].arg1, qi->result);
                    if (strcmp(quadTable[k].arg2, qj->result) == 0) strcpy(quadTable[k].arg2, qi->result);
                }
                qj->op[0] = '\0';  // Mark quad for removal
            }
        }
    }

    // Remove marked quads
    writeIdx = 0;
    for (int i = 0; i < quadIndex; ++i) {
        if (quadTable[i].op[0] != '\0') {
            if (writeIdx != i) quadTable[writeIdx] = quadTable[i];
            writeIdx++;
        }
    }
    quadIndex = writeIdx;

    // Phase 4: Dead code elimination
    // Remove assignments to variables that are never used afterwards
    writeIdx = 0;
    for (int i = 0; i < quadIndex; ++i) {
        Quadruple* q = &quadTable[i];
        if (strcmp(q->op, "=") == 0 && !isVarUsedAfter(q->result, i)) {
            continue;  // Skip this quad if the result is never used
        }
        if (writeIdx != i) quadTable[writeIdx] = *q;
        writeIdx++;
    }
    quadIndex = writeIdx;
}
