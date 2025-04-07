#ifndef TABLE_SYMBOLE_H
#define TABLE_SYMBOLE_H

// Initialize all symbol tables
void initialization();

// Insert an entity into the appropriate symbol table
void insert(char entity[], char code[], char type[], float val, int table_type);

// Search if an entity exists in a given symbol table (0: not found, 1: found)
int search(char entity[], int table_type);

// Search and return an identifier (returns NULL if not found)
struct element* searchIdf(char entity[]);

// Insert if the entity does not already exist
void insertIfNotExists(char entity[], char code[], char type[], float val, int table_type);

// Display all symbol tables
void display();

// Free all dynamically allocated memory in the symbol tables
void freeAllTables();

#endif // TABLE_SYMBOLE_H
