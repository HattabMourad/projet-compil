#ifndef TABLESYMBOLE_H
#define TABLESYMBOLE_H


// === Initialization ===
void initialization();

// === Insertions ===
void insertIDF (char entity[], char code[], char type[], float val);
void insertSEPKEY (char entity[], char type[], int table_type);
void insertIfNotExistsIDF (char entity[], char code[], char type[], float val);
void insertVEC(char entity[], char type[], int size);

// === Lookups ===
int searchIDF (char entity[]);
int searchVEC (char entity[]);
int doubleDeclaration (char entity[]);
char* getVarType(char* name);
float getVarValue(char* name);
void updateIDFValue(char* name, float val);

// === Display ===
void afficher();

void freeAllTables();

#endif // TABLESYMBOLE_H
