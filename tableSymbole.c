#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"

#define IDF_TABLE_SIZE 1000
#define KEYWORD_TABLE_SIZE 100
#define SEPARATOR_TABLE_SIZE 100
#define VECTOR_TABLE_SIZE 100

typedef struct element {
    int state;              
    char* name;             
    char* code;             
    char* type;            
    float val;              
    struct element* next;  
} element;

typedef struct elmt {
    int state;
    char* name;
    char* size;
    char* type;
    struct elmt* next;
} elmt;

typedef struct elt {
    int state;
    char* name;
    char* type;
    struct elt* next;      
} elt;

element* tabIdf[IDF_TABLE_SIZE];
elt* tabKeyword[KEYWORD_TABLE_SIZE];
elt* tabSep[SEPARATOR_TABLE_SIZE];
elmt*tabVec[VECTOR_TABLE_SIZE];

unsigned int hash(char* str, int table_size) {
    unsigned int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value = hash_value * 31 + str[i];
    }
    return hash_value % table_size;
}

void initialization() {
    int i;
    
    for (i = 0; i < IDF_TABLE_SIZE; i++) {
        tabIdf[i] = NULL;
    }
    
    for (i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        tabKeyword[i] = NULL;
    }
    
    for (i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        tabSep[i] = NULL;
    }

    for (i = 0; i< VECTOR_TABLE_SIZE; i++) {
        tabVec[i] = NULL;
    }
}

void insertIDF (char entity[], char code[], char type[], float val) {
    unsigned int index = hash(entity, IDF_TABLE_SIZE);
    element* new_element = (element*)malloc(sizeof(element));
    new_element->name = strdup(entity);
    new_element->code = strdup(code);
    new_element->type = strdup(type);
    new_element->val = val;
    new_element->state = 1;
    new_element->next = NULL;

    if (tabIdf[index] == NULL) {
        tabIdf[index] = new_element;
    } else {
        element* current = tabIdf[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
}

int searchSEPKEY(char entity[], int table_type) {
    unsigned int index;
    elt* current;

    if (table_type == 1) {
        index = hash(entity, KEYWORD_TABLE_SIZE);
        current = tabKeyword[index];
    } else {
        index = hash(entity, SEPARATOR_TABLE_SIZE);
        current = tabSep[index];
    }

    while (current != NULL) {
        if (strcmp(current->name, entity) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void insertSEPKEY(char entity[], char type[], int table_type) {
    if (!searchSEPKEY(entity, table_type)) {
        unsigned int index;
        elt* new_element = (elt*)malloc(sizeof(elt));
        new_element->name = strdup(entity);
        new_element->type = strdup(type);
        new_element->state = 1;
        new_element->next = NULL;

        if (table_type == 1) {
            index = hash(entity, KEYWORD_TABLE_SIZE);
            if (tabKeyword[index] == NULL) {
                tabKeyword[index] = new_element;
            } else {
                elt* current = tabKeyword[index];
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_element;
            }
        } else {
            index = hash(entity, SEPARATOR_TABLE_SIZE);
            if (tabSep[index] == NULL) {
                tabSep[index] = new_element;
            } else {
                elt* current = tabSep[index];
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_element;
            }
        }
    }
}

int searchVEC (char entity[]){
    unsigned int index = hash(entity, VECTOR_TABLE_SIZE);
    elmt* current = tabVec[index];

    while (current != NULL) {
        if(strcmp(current->name, entity) == 0) {
            return 1;
        }
        current = current -> next;
    }
    return 0;
}

void insertVEC(char entity[], char type[], int size) {
    if (!searchVEC(entity)) {
        unsigned int index = hash(entity, VECTOR_TABLE_SIZE);
        elmt* new_element = (elmt*)malloc(sizeof(elmt));
        if (new_element == NULL) {
            printf("Memory allocation error for vector %s\n", entity);
            return;
        }
        new_element->state = 1;
        new_element->name = strdup(entity);
        new_element->type = strdup(type);

        char size_str[20];
        snprintf(size_str, sizeof(size_str), "%d", size);
        new_element->size = strdup(size_str);

        new_element->next = tabVec[index];
        tabVec[index] = new_element;
    }
}

int searchIDF (char entity[]) {
    unsigned int index = hash(entity, IDF_TABLE_SIZE);
    element* current = tabIdf[index];
    
    while (current != NULL) {
        if (strcmp(current->name, entity) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void insertIfNotExistsIDF (char entity[], char code[], char type[], float val) {
    if (!searchIDF(entity)) {
        insertIDF(entity, code, type, val);
    }
}

int doubleDeclaration (char entity[]) {
    if (searchIDF(entity)) {
        return 1;
    }
    return 0;
}

char* getVarType(char* name) {
    unsigned int index = hash(name, IDF_TABLE_SIZE);
    element* current = tabIdf[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->type;
        }
        current = current->next;
    }
    return NULL;
}

float getVarValue(char* name) {
    unsigned int index = hash(name, IDF_TABLE_SIZE);
    element* current = tabIdf[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->val;
        }
        current = current->next;
    }
    return 0.0;
}

void updateIDFValue(char* name, float val) {
    unsigned int index = hash(name, IDF_TABLE_SIZE);
    element* current = tabIdf[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->val = val;
            return;
        }
        current = current->next;
    }
}

void afficher() {
    printf("\n+--------------------+--------------------+--------------------+-------------------+\n");
    printf("| Name               | Code               | Type               | Value             |\n");
    printf("+--------------------+--------------------+--------------------+-------------------+\n");
    
    for (int i = 0; i < IDF_TABLE_SIZE; i++) {
        element* current = tabIdf[i];
        while (current != NULL) {
            printf("| %-18s | %-18s | %-18s | %-17.2f |\n", current->name, current->code, current->type, current->val);
            current = current->next;
        }
    }
    
    printf("+--------------------+--------------------+--------------------+-------------------+\n");

    printf("\n+--------------------+--------------------+--------------------+\n");
    printf("| Name               | Type               | Size               |\n");
    printf("+--------------------+--------------------+--------------------+\n");

    for(int i = 0; i < VECTOR_TABLE_SIZE; i++) {
        elmt* current = tabVec[i];
        while (current != NULL) {
            printf("| %-18s | %-18s | %-18s |\n", current ->name, current ->type , current ->size);
            current = current ->next;
        }
    }

    printf("+--------------------+--------------------+--------------------+\n");

    printf("\n+--------------------+--------------------+\n");
    printf("| Name               | Type               |\n");
    printf("+--------------------+--------------------+\n");

    for (int i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        elt* current = tabKeyword[i];
        while (current != NULL) {
            printf("| %-18s | %-18s |\n", current->name, current->type);
            current = current->next;
        }
    }

    printf("+--------------------+--------------------+\n");

    printf("\n+--------------------+--------------------+\n");
    printf("| Name               | Type               |\n");
    printf("+--------------------+--------------------+\n");

    // Display separators in a table format
    for (int i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        elt* current = tabSep[i];
        while (current != NULL) {
            printf("| %-18s | %-18s |\n", current->name, current->type);
            current = current->next;
        }
    }

    printf("+--------------------+--------------------+\n");
}


void freeAllTables() {
    for (int i = 0; i < IDF_TABLE_SIZE; i++) {
        element* current = tabIdf[i];
        while (current != NULL) {
            element* temp = current;
            current = current->next;
            free(temp->name);
            free(temp->code);
            free(temp->type);
            free(temp);
        }
    }

    for (int i = 0; i < VECTOR_TABLE_SIZE; i++) {
        elmt* current = tabVec[i];
        while (current != NULL) {
            elmt* temp = current;
            current = current->next;
            free(temp->name);
            free(temp->size);
            free(temp->type);
            free(temp);
        }
    }

    for (int i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        elt* current = tabKeyword[i];
        while (current != NULL) {
            elt* temp = current;
            current = current->next;
            free(temp->name);
            free(temp->type);
            free(temp);
        }
    }

    for (int i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        elt* current = tabSep[i];
        while (current != NULL) {
            elt* temp = current;
            current = current->next;
            free(temp->name);
            free(temp->type);
            free(temp);
        }
    }
}