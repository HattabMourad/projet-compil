#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"

// Size definitions for hash tables
#define IDF_TABLE_SIZE 1000
#define KEYWORD_TABLE_SIZE 100
#define SEPARATOR_TABLE_SIZE 100
#define VECTOR_TABLE_SIZE 100

// Element structure for identifiers and constants
typedef struct element {
    int state;              // 0: empty, 1: occupied
    char* name;             // name of the entity
    char* code;             // code of the entity
    char* type;             // type of the entity
    float val;              // value if the entity is a constant
    struct element* next;   // pointer to the next element (for collision handling)
} element;

typedef struct elmt {
    int state;
    char* name;
    char* size;
    char* type;
    struct elmt* next;
} elmt;

// Element structure for keywords and separators
typedef struct elt {
    int state;
    char* name;
    char* type;
    struct elt* next;       // pointer to the next element (for collision handling)
} elt;

// Hash tables
element* tabIdf[IDF_TABLE_SIZE];
elt* tabKeyword[KEYWORD_TABLE_SIZE];
elt* tabSep[SEPARATOR_TABLE_SIZE];
elmt*tabVec[VECTOR_TABLE_SIZE];

// Hash function
unsigned int hash(char* str, int table_size) {
    unsigned int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value = hash_value * 31 + str[i];
    }
    return hash_value % table_size;
}

// Initialize all hash tables
void initialization() {
    int i;
    
    // Initialize identifiers and constants table
    for (i = 0; i < IDF_TABLE_SIZE; i++) {
        tabIdf[i] = NULL;
    }
    
    // Initialize keywords table
    for (i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        tabKeyword[i] = NULL;
    }
    
    // Initialize separators table
    for (i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        tabSep[i] = NULL;
    }

    // Initialize vectors table
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

    // Check in the appropriate table
    if (table_type == 1) { // Keyword table
        index = hash(entity, KEYWORD_TABLE_SIZE);
        current = tabKeyword[index];
    } else { // Separator table
        index = hash(entity, SEPARATOR_TABLE_SIZE);
        current = tabSep[index];
    }

    // Traverse the list to check if the entity already exists
    while (current != NULL) {
        if (strcmp(current->name, entity) == 0) {
            return 1; // Found
        }
        current = current->next;
    }

    return 0; // Not found
}

void insertSEPKEY(char entity[], char type[], int table_type) {
    // Check if the keyword or separator already exists
    if (!searchSEPKEY(entity, table_type)) {
        unsigned int index;
        elt* new_element = (elt*)malloc(sizeof(elt));
        new_element->name = strdup(entity);
        new_element->type = strdup(type);
        new_element->state = 1;
        new_element->next = NULL;

        // Insert into the appropriate table
        if (table_type == 1) { // Keyword table
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
        } else { // Separator table
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
        new_element->state = 1; // you can use this field as needed
        new_element->name = strdup(entity);
        new_element->type = strdup(type);

        // Store size as string for consistency with your struct
        char size_str[20];
        snprintf(size_str, sizeof(size_str), "%d", size);
        new_element->size = strdup(size_str);

        // Insert at the beginning of the list for simplicity
        new_element->next = tabVec[index];
        tabVec[index] = new_element;
    }
}

int searchIDF (char entity[]) {
    unsigned int index = hash(entity, IDF_TABLE_SIZE);
    element* current = tabIdf[index];
    
    while (current != NULL) {
        if (strcmp(current->name, entity) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
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

// Get the type of a variable from the symbol table
char* getVarType(char* name) {
    unsigned int index = hash(name, IDF_TABLE_SIZE);
    element* current = tabIdf[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->type;  // Return the type of the variable
        }
        current = current->next;
    }
    return NULL;  // Variable not found
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
    return 0.0;  // Default to zero if not found
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
    // Print headers for Identifiers and Constants table
    printf("\n+--------------------+--------------------+--------------------+-------------------+\n");
    printf("| Name               | Code               | Type               | Value             |\n");
    printf("+--------------------+--------------------+--------------------+-------------------+\n");
    
    // Display identifiers and constants in a table format
    for (int i = 0; i < IDF_TABLE_SIZE; i++) {
        element* current = tabIdf[i];
        while (current != NULL) {
            printf("| %-18s | %-18s | %-18s | %-17.2f |\n", current->name, current->code, current->type, current->val);
            current = current->next;
        }
    }
    
    printf("+--------------------+--------------------+--------------------+-------------------+\n");

    // Print headers for Vectors table
    printf("\n+--------------------+--------------------+--------------------+\n");
    printf("| Name               | Type               | Size               |\n");
    printf("+--------------------+--------------------+--------------------+\n");

    // Display vectors in a table format
    for(int i = 0; i < VECTOR_TABLE_SIZE; i++) {
        elmt* current = tabVec[i];
        while (current != NULL) {
            printf("| %-18s | %-18s | %-18s |\n", current ->name, current ->type , current ->size);
            current = current ->next;
        }
    }

    printf("+--------------------+--------------------+--------------------+\n");

    // Print headers for Keywords table
    printf("\n+--------------------+--------------------+\n");
    printf("| Name               | Type               |\n");
    printf("+--------------------+--------------------+\n");

    // Display keywords in a table format
    for (int i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        elt* current = tabKeyword[i];
        while (current != NULL) {
            printf("| %-18s | %-18s |\n", current->name, current->type);
            current = current->next;
        }
    }

    printf("+--------------------+--------------------+\n");

    // Print headers for Separators table
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
    // Free identifiers and constants table
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

    // Free keywords table
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

    // Free separators table
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