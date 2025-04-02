/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure pour les tableaux */
typedef struct {
    int dimensions;     // Nombre de dimensions
    int size[10];       // Taille de chaque dimension (max 10 dimensions)
    char elementType[20]; // Type des éléments du tableau
} ArrayInfo;

typedef struct {
   int state;           // 0: libre, 1: occupé
   char name[20];       // Nom de l'entité
   char code[20];       // Code de l'entité
   char type[20];       // Type de l'entité
   float val;           // Valeur (pour les constantes)
   int isArray;         // 0: variable simple, 1: tableau
   ArrayInfo arrayInfo; // Information sur le tableau (si applicable)
} element;

typedef struct { 
   int state;           // 0: libre, 1: occupé
   char name[20];       // Nom de l'entité
   char type[20];       // Type de l'entité
} elt;

#define TABLE_SIZE 1000
#define KEYWORD_SIZE 40
#define SEPARATOR_SIZE 40

element tab[TABLE_SIZE];  // Table des identificateurs et constantes
elt tabs[SEPARATOR_SIZE]; // Table des séparateurs
elt tabm[KEYWORD_SIZE];   // Table des mots clés
extern char sav[20];

/***Step 2: initialisation de l'état des cases des tables des symbloles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation() {
  int i;
  for (i = 0; i < TABLE_SIZE; i++)
    tab[i].state = 0;

  for (i = 0; i < KEYWORD_SIZE; i++) {
    tabs[i].state = 0;
    tabm[i].state = 0;
  }
}

/*** Fonction de hachage pour améliorer la recherche ***/
unsigned int hash(char* str) {
    unsigned int hash = 0;
    int c;
    
    while ((c = *str++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    
    return hash % TABLE_SIZE;
}

/***Step 3: insertion des entititées lexicales dans les tables des symboles ***/
void inserer(char entite[], char code[], char type[], float val, int i, int y) {
  switch (y) { 
   case 0: /* Insertion dans la table des IDF et CONST */
       tab[i].state = 1;
       strcpy(tab[i].name, entite);
       strcpy(tab[i].code, code);
       strcpy(tab[i].type, type);
       tab[i].val = val;
       tab[i].isArray = 0; // Par défaut, ce n'est pas un tableau
       break;

   case 1: /* Insertion dans la table des mots clés */
       tabm[i].state = 1;
       strcpy(tabm[i].name, entite);
       strcpy(tabm[i].type, code);
       break; 
    
   case 2: /* Insertion dans la table des séparateurs */
      tabs[i].state = 1;
      strcpy(tabs[i].name, entite);
      strcpy(tabs[i].type, code);
      break;
  }
}

/* Fonction pour insérer un tableau dans la table des symboles */
void insererTableau(char nom[], char type[], int dimensions, int tailles[]) {
    unsigned int index = hash(nom);
    int i, originalIndex = index;
    
    // Recherche d'une case libre en utilisant le sondage linéaire
    while (tab[index].state == 1 && strcmp(tab[index].name, nom) != 0) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Erreur: Table des symboles pleine\n");
            return;
        }
    }
    
    // Si l'entité existe déjà
    if (tab[index].state == 1) {
        printf("Erreur: L'identificateur '%s' existe déjà\n", nom);
        return;
    }
    
    // Insertion
    tab[index].state = 1;
    strcpy(tab[index].name, nom);
    strcpy(tab[index].code, "IDF");
    strcpy(tab[index].type, type);
    tab[index].val = 0; // Non applicable pour les tableaux
    tab[index].isArray = 1;
    
    // Informations sur le tableau
    tab[index].arrayInfo.dimensions = dimensions;
    strcpy(tab[index].arrayInfo.elementType, type);
    
    for (i = 0; i < dimensions && i < 10; i++) {
        tab[index].arrayInfo.size[i] = tailles[i];
    }
    
    printf("Tableau '%s' inséré avec succès\n", nom);
}

/***Step 4: La fonction Rechercher permet de verifier si l'entité existe dèja dans la table des symboles */
void rechercher(char entite[], char code[], char type[], float val, int y) {
    int i, originalIndex;

    switch(y) {
        case 0: /* Recherche dans la table des IDF et CONST avec hachage */
            originalIndex = hash(entite);
            i = originalIndex;
            
            // Recherche avec sondage linéaire
            do {
                if (tab[i].state == 0) {
                    // Case libre trouvée
                    inserer(entite, code, type, val, i, 0);
                    return;
                } else if (strcmp(entite, tab[i].name) == 0) {
                    // Entité trouvée
                    printf("Attention: L'identificateur '%s' existe déjà\n", entite);
                    return;
                }
                
                i = (i + 1) % TABLE_SIZE;
            } while (i != originalIndex);
            
            printf("Erreur: Table des symboles pleine\n");
            break;

        case 1: /* Recherche dans la table des mots clés */
            for (i = 0; i < KEYWORD_SIZE; i++) {
                if (tabm[i].state == 0) {
                    // Case libre trouvée
                    inserer(entite, code, type, val, i, 1);
                    return;
                } else if (strcmp(entite, tabm[i].name) == 0) {
                    // Entité trouvée
                    printf("Attention: Le mot clé '%s' existe déjà\n", entite);
                    return;
                }
            }
            printf("Erreur: Table des mots clés pleine\n");
            break;
    
        case 2: /* Recherche dans la table des séparateurs */
            for (i = 0; i < SEPARATOR_SIZE; i++) {
                if (tabs[i].state == 0) {
                    // Case libre trouvée
                    inserer(entite, code, type, val, i, 2);
                    return;
                } else if (strcmp(entite, tabs[i].name) == 0) {
                    // Entité trouvée
                    printf("Attention: Le séparateur '%s' existe déjà\n", entite);
                    return;
                }
            }
            printf("Erreur: Table des séparateurs pleine\n");
            break;
    }
}

/* Fonction pour rechercher une entité dans la table des symboles */
int rechercherEntite(char entite[], int y) {
    int i, originalIndex;

    switch(y) {
        case 0: /* Recherche dans la table des IDF et CONST */
            originalIndex = hash(entite);
            i = originalIndex;
            
            do {
                if (tab[i].state == 1 && strcmp(tab[i].name, entite) == 0) {
                    return i; // Entité trouvée
                }
                if (tab[i].state == 0) {
                    return -1; // Case libre = entité non trouvée
                }
                
                i = (i + 1) % TABLE_SIZE;
            } while (i != originalIndex);
            
            return -1; // Table pleine, entité non trouvée
            
        case 1: /* Recherche dans la table des mots clés */
            for (i = 0; i < KEYWORD_SIZE; i++) {
                if (tabm[i].state == 1 && strcmp(tabm[i].name, entite) == 0) {
                    return i; // Entité trouvée
                }
            }
            return -1; // Entité non trouvée
            
        case 2: /* Recherche dans la table des séparateurs */
            for (i = 0; i < SEPARATOR_SIZE; i++) {
                if (tabs[i].state == 1 && strcmp(tabs[i].name, entite) == 0) {
                    return i; // Entité trouvée
                }
            }
            return -1; // Entité non trouvée
    }
    
    return -1;
}

/***Step 5 L'affichage du contenue de la table des symboles ***/
void afficher() {
    int i;

    printf("/***************Table des symboles IDF et CONST*************/\n");
    printf("_______________________________________________________________________________\n");
    printf("| Nom_Entite | Code_Entite | Type_Entite | Val_Entite | Est_Tableau | Dimensions |\n");
    printf("_______________________________________________________________________________\n");
  
    for(i = 0; i < TABLE_SIZE; i++) {
        if(tab[i].state == 1) {
            printf("| %-10s | %-11s | %-11s | %-10.2f | %-11d |", 
                   tab[i].name, tab[i].code, tab[i].type, tab[i].val, tab[i].isArray);
                   
            if (tab[i].isArray) {
                printf(" %-10d |\n", tab[i].arrayInfo.dimensions);
                // Affichage des dimensions si nécessaire
                // ...
            } else {
                printf(" %-10s |\n", "N/A");
            }
        }
    }

    printf("\n/***************Table des symboles mots clés*************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite | CodeEntite |\n");
    printf("_____________________________________\n");
  
    for(i = 0; i < KEYWORD_SIZE; i++) {
        if(tabm[i].state == 1) { 
            printf("| %-10s | %-11s |\n", tabm[i].name, tabm[i].type);               
        }
    }

    printf("\n/***************Table des symboles séparateurs*************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite | CodeEntite |\n");
    printf("_____________________________________\n");
  
    for(i = 0; i < SEPARATOR_SIZE; i++) {
        if(tabs[i].state == 1) { 
            printf("| %-10s | %-11s |\n", tabs[i].name, tabs[i].type);
        }
    }
}