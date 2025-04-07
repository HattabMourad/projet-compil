#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"

// Size definitions for hash tables
#define IDF_TABLE_SIZE 1000
#define KEYWORD_TABLE_SIZE 100
#define SEPARATOR_TABLE_SIZE 100

// Element structure for identifiers and constants
typedef struct element {
    int state;              // 0: empty, 1: occupied
    char* name;             // name of the entity
    char* code;             // code of the entity
    char* type;             // type of the entity
    float val;              // value if the entity is a constant
    struct element* next;   // pointer to the next element (for collision handling)
} element;

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
}

// Insert entity into appropriate hash table
void insert(char entity[], char code[], char type[], float val, int table_type) {
    unsigned int index;
    
    switch (table_type) {
        case 0: // Insert into identifiers and constants table
            index = hash(entity, IDF_TABLE_SIZE);
            
            // Create new element
            element* new_element = (element*)malloc(sizeof(element));
            if (new_element == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            
            new_element->state = 1;
            new_element->name = strdup(entity);  // Use strdup to dynamically allocate memory
            new_element->code = strdup(code);
            new_element->type = strdup(type);
            new_element->val = val;
            new_element->next = NULL;
            
            // Insert at beginning of linked list
            if (tabIdf[index] == NULL) {
                tabIdf[index] = new_element;
            } else {
                new_element->next = tabIdf[index];
                tabIdf[index] = new_element;
            }
            break;
            
        case 1: // Insert into keywords table
            index = hash(entity, KEYWORD_TABLE_SIZE);
            
            // Create new element
            elt* new_keyword = (elt*)malloc(sizeof(elt));
            if (new_keyword == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            
            new_keyword->state = 1;
            new_keyword->name = strdup(entity);
            new_keyword->type = strdup(code);
            new_keyword->next = NULL;
            
            // Insert at beginning of linked list
            if (tabKeyword[index] == NULL) {
                tabKeyword[index] = new_keyword;
            } else {
                new_keyword->next = tabKeyword[index];
                tabKeyword[index] = new_keyword;
            }
            break;
            
        case 2: // Insert into separators table
            index = hash(entity, SEPARATOR_TABLE_SIZE);
            
            // Create new element
            elt* new_sep = (elt*)malloc(sizeof(elt));
            if (new_sep == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            
            new_sep->state = 1;
            new_sep->name = strdup(entity);
            new_sep->type = strdup(code);
            new_sep->next = NULL;
            
            // Insert at beginning of linked list
            if (tabSep[index] == NULL) {
                tabSep[index] = new_sep;
            } else {
                new_sep->next = tabSep[index];
                tabSep[index] = new_sep;
            }
            break;
    }
}

// Search if entity exists in appropriate hash table
int search(char entity[], int table_type) {
    unsigned int index;
    
    switch (table_type) {
        case 0: // Search in identifiers and constants table
            index = hash(entity, IDF_TABLE_SIZE);
            element* current_idf = tabIdf[index];
            
            while (current_idf != NULL) {
                if (strcmp(current_idf->name, entity) == 0) {
                    return 1; // Found
                }
                current_idf = current_idf->next;
            }
            return 0; // Not found
            
        case 1: // Search in keywords table
            index = hash(entity, KEYWORD_TABLE_SIZE);
            elt* current_keyword = tabKeyword[index];
            
            while (current_keyword != NULL) {
                if (strcmp(current_keyword->name, entity) == 0) {
                    return 1; // Found
                }
                current_keyword = current_keyword->next;
            }
            return 0; // Not found
            
        case 2: // Search in separators table
            index = hash(entity, SEPARATOR_TABLE_SIZE);
            elt* current_sep = tabSep[index];
            
            while (current_sep != NULL) {
                if (strcmp(current_sep->name, entity) == 0) {
                    return 1; // Found
                }
                current_sep = current_sep->next;
            }
            return 0; // Not found
    }
    
    return 0; // Default: not found
}

// Insert entity if it doesn't exist already
void insertIfNotExists(char entity[], char code[], char type[], float val, int table_type) {
    if (!search(entity, table_type)) {
        insert(entity, code, type, val, table_type);
    } else {
        printf("Entity '%s' already exists in table %d\n", entity, table_type);
    }
}

// Display contents of all symbol tables
void display() {
    int i;
    element* current_idf;
    elt* current_keyword;
    elt* current_sep;
    
    // Display identifiers and constants table
    printf("/***************Table of symbols for Identifiers and Constants*************/\n");
    printf("____________________________________________________________________\n");
    printf("| Entity_Name |  Entity_Code | Entity_Type | Entity_Value\n");
    printf("____________________________________________________________________\n");
    
    for (i = 0; i < IDF_TABLE_SIZE; i++) {
        current_idf = tabIdf[i];
        while (current_idf != NULL) {
            printf("|%15s |%13s | %11s | %12.4f\n",
                   current_idf->name, current_idf->code, current_idf->type, current_idf->val);
            current_idf = current_idf->next;
        }
    }
    
    // Display keywords table
    printf("\n/***************Table of symbols for Keywords*************/\n");
    printf("_____________________________________\n");
    printf("| Entity_Name |  Entity_Code | \n");
    printf("_____________________________________\n");
    
    for (i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        current_keyword = tabKeyword[i];
        while (current_keyword != NULL) {
            printf("|%12s |%13s | \n", current_keyword->name, current_keyword->type);
            current_keyword = current_keyword->next;
        }
    }
    
    // Display separators table
    printf("\n/***************Table of symbols for Separators*************/\n");
    printf("_____________________________________\n");
    printf("| Entity_Name | Entity_Code | \n");
    printf("_____________________________________\n");
    
    for (i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        current_sep = tabSep[i];
        while (current_sep != NULL) {
            printf("|%12s |%13s | \n", current_sep->name, current_sep->type);
            current_sep = current_sep->next;
        }
    }
}

// Free all allocated memory
void freeAllTables() {
    int i;
    element* current_idf, *temp_idf;
    elt* current_keyword, *temp_keyword;
    elt* current_sep, *temp_sep;
    
    // Free identifiers and constants table
    for (i = 0; i < IDF_TABLE_SIZE; i++) {
        current_idf = tabIdf[i];
        while (current_idf != NULL) {
            temp_idf = current_idf;
            current_idf = current_idf->next;
            free(temp_idf->name);
            free(temp_idf->code);
            free(temp_idf->type);
            free(temp_idf);
        }
        tabIdf[i] = NULL;
    }
    
    // Free keywords table
    for (i = 0; i < KEYWORD_TABLE_SIZE; i++) {
        current_keyword = tabKeyword[i];
        while (current_keyword != NULL) {
            temp_keyword = current_keyword;
            current_keyword = current_keyword->next;
            free(temp_keyword->name);
            free(temp_keyword->type);
            free(temp_keyword);
        }
        tabKeyword[i] = NULL;
    }
    
    // Free separators table
    for (i = 0; i < SEPARATOR_TABLE_SIZE; i++) {
        current_sep = tabSep[i];
        while (current_sep != NULL) {
            temp_sep = current_sep;
            current_sep = current_sep->next;
            free(temp_sep->name);
            free(temp_sep->type);
            free(temp_sep);
        }
        tabSep[i] = NULL;
    }
}
