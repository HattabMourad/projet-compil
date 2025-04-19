%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"

extern int nb_ligne;
extern int col;
extern FILE* yyin;
void yyerror(const char *s);
int yylex();
char* currentType = NULL;
%}

%union {
  char* strVal;
  float floatVal;
  int   entier;
  char* str;
  float reel;
  struct {
    char* type;
    float val;
  } exprAttr;
}


%token DATA CODE END VECTOR IF ELSE FOR CONST READ DISPLAY
%token <str>IDF <entier>INTEGER_VAL <reel>FLOAT_VAL CHAR_VAL <str>STRING_VAL
%token <str>INTEGER <str>FLOAT <str>CHAR <str>STRING
%token LPAREN RPAREN LBRACKET RBRACKET COLON COMMA PVG EGAL BARV ADR
%token FORMAT_DOLLAR FORMAT_PERCENT FORMAT_HASH FORMAT_AMP
%token NOT POINT
%left PLUS MINUS MULT DIV OR AND GE LE GT LT EQ DI
%type <str> type 
%type <str> op_arithmetique
%type <str> op_logique
%type <str> op_comparaison
%type <str> format
%type <exprAttr> expression
%type <exprAttr> constant
%start program

%%

program:
      IDF DATA declarations END CODE instructions END END
      { printf("Program parsed successfully!\n"); }
    ;

declarations:
      declaration
    | declarations declaration
    ;
    
type:
      INTEGER { currentType = $1; $$ = $1; }
    | FLOAT { currentType = $1; $$ = $1; }
    | CHAR { currentType = $1; $$ = $1; }
    | STRING { currentType = $1; $$ = $1; }
    ;

declaration:
      type COLON list_variables PVG
      {
        currentType = NULL;
      }
    | VECTOR COLON IDF LBRACKET INTEGER_VAL COMMA INTEGER_VAL COLON type RBRACKET PVG
      {
        if(searchVEC($3)) { printf ("Error on line %d: Vector %s already exists /n", nb_ligne, $3); }
        else { insertVEC($3, $9, $7); }
      }
    | CONST COLON IDF EGAL constant PVG
      {
        if(doubleDeclaration($3)) { printf("Error on line %d: Variable %s already declared\n", nb_ligne, $3); }
        else {insertIfNotExistsIDF($3, "CONST", currentType, $5.val); }
      }
    ;

list_variables:
      list_variables BARV IDF
      {
        if(doubleDeclaration($3)){ printf("Error on line %d: Variable %s already declared\n", nb_ligne, $3); }
        else {insertIfNotExistsIDF($3, "IDF", currentType, 0); }
      }
    | IDF
      {
        if(doubleDeclaration($1)){ printf("Error on line %d: Variable %s already declared\n", nb_ligne, $1); }
        else {insertIfNotExistsIDF($1, "IDF", currentType, 0); }
      }
    ;

constant:
      INTEGER_VAL { $$.type = "INTEGER"; $$.val = $1; }
    | FLOAT_VAL   { $$.type = "FLOAT";   $$.val = $1; }
    | CHAR_VAL    { $$.type = "CHAR";    $$.val = $1; }
    | STRING_VAL  { $$.type = "STRING";  $$.val = 0;  }
    ;

instructions:
      instruction
    | instructions instruction
    ;

instruction:
      affectation
    | io_read
    | io_display
    | if_else
    | boucle
    ;

affectation:
      IDF EGAL expression PVG
      {
        char* type1 = getVarType($1);
        char* type2 = $3.type;
        if (type1 == NULL || type2 == NULL) {
            printf("Error on line %d: Variable %s not declared or constant type mismatch\n", nb_ligne, $1);
        }
        else if (strcmp(type1, type2) != 0) {
            printf("Error on line %d: Type mismatch between %s and %s\n", nb_ligne, $1, $3.type);
        }
        else {
            updateIDFValue($1, $3.val);
        }
      }
    ;

expression:
      constant { $$.type = $1.type; $$.val = $1.val; }
    | IDF { 
        $$.type = getVarType($1); 
        $$.val = getVarValue($1); 
      }
    | expression op_arithmetique expression {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type mismatch in expression on line %d\n", nb_ligne);
            exit(1);
        }
        $$.type = $1.type;
        if (strcmp($2, "+") == 0) $$.val = $1.val + $3.val;
        else if (strcmp($2, "-") == 0) $$.val = $1.val - $3.val;
        else if (strcmp($2, "*") == 0) $$.val = $1.val * $3.val;
        else if (strcmp($2, "/") == 0) {
            if ($3.val != 0) $$.val = $1.val / $3.val;
            else {
                printf("Error on line %d: Division by zero\n", nb_ligne);
                exit(1);
            }
        }
      }
    ;

op_arithmetique:
      PLUS   { $$ = "+"; }
    | MINUS  { $$ = "-"; }
    | MULT   { $$ = "*"; }
    | DIV    { $$ = "/"; }
    ;

op_logique:
      OR   { $$ = "OR"; }
    | AND  { $$ = "AND"; }
    | NOT  { $$ = "NOT"; }
    ;

format:
      FORMAT_DOLLAR   { $$ = "$"; }
    | FORMAT_PERCENT  { $$ = "%"; }
    | FORMAT_HASH     { $$ = "#"; }
    | FORMAT_AMP      { $$ = "&"; }
    ;

io_read:
      READ LPAREN format COLON ADR IDF RPAREN PVG
      {
        char* idf_type = getVarType($6);
        if (strcmp($3, "$") == 0) {
            if (strcmp(idf_type, "INTEGER") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected INTEGER for $ format\n", nb_ligne);
            }
        } else if (strcmp($3, "%") == 0) {
            if (strcmp(idf_type, "FLOAT") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected FLOAT for %% format\n", nb_ligne);
            }
        } else if (strcmp($3, "#") == 0) {
            if (strcmp(idf_type, "CHAR") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected CHAR for # format\n", nb_ligne);
            }
        } else if (strcmp($3, "&") == 0) {
            if (strcmp(idf_type, "STRING") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected STRING for & format\n", nb_ligne);
            }
        }
      }
    ;

io_display:
      DISPLAY LPAREN STRING_VAL COLON IDF RPAREN PVG
      {
        // Extract the format sign from the string if present
        char* str = $3;
        int len = strlen(str);
        char fmt = 0;
        if (len > 2 && (str[len-2] == '$' || str[len-2] == '%' || str[len-2] == '#' || str[len-2] == '&')) {
            fmt = str[len-2];
            str[len-2] = '\0'; // Remove format sign from string
            str[len-1] = '\0'; // Remove closing quote
        }
        // Remove opening quote
        char* phrase = str + 1;
        char* idf_type = getVarType($5);
        if (fmt) {
            if ((fmt == '$' && strcmp(idf_type, "INTEGER") == 0) ||
                (fmt == '%' && strcmp(idf_type, "FLOAT") == 0) ||
                (fmt == '#' && strcmp(idf_type, "CHAR") == 0) ||
                (fmt == '&' && strcmp(idf_type, "STRING") == 0)) {
                printf("Display: %s %f\n", phrase, getVarValue($5));
            } else {
                printf("Error: Type mismatch for display format (expected %c for %s)\n", fmt, idf_type);
            }
        } else {
            printf("Display: %s\n", phrase);
        }
      }
    | DISPLAY LPAREN STRING_VAL RPAREN PVG
      {
        char* phrase = $3 + 1;
        phrase[strlen(phrase) - 1] = '\0';
        printf("Display: %s\n", phrase);
      }
    ;

if_else:
      IF LPAREN conditions RPAREN COLON instructions ELSE COLON instructions END
    | IF LPAREN conditions RPAREN COLON instructions END
      { printf("IF-ELSE parsed\n"); }
    ;

conditions:
      condition
    | conditions POINT op_logique POINT condition
    | NOT POINT condition
    ;

condition:
      expression POINT op_comparaison POINT expression
    ;

op_comparaison:
      GT   { $$ = "GT"; }
    | LT   { $$ = "LT"; }
    | GE   { $$ = "GE"; }
    | LE   { $$ = "LE"; }
    | EQ   { $$ = "EQ"; }
    | DI   { $$ = "DI"; }
    ;

boucle:
      FOR LPAREN IDF COLON INTEGER_VAL COLON expression RPAREN instructions END
      { printf("FOR Loop parsed\n"); }
    ;

%%

void yyerror(const char *s) {
    printf("Syntax Error at line %d, column %d: %s\n", nb_ligne, col, s);
}

int main(int argc, char *argv[]) {
    printf("PHYLOG Compiler\n");
    
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Cannot open file %s\n", argv[1]);
            exit(1);
        }
        printf("Parsing file: %s\n", argv[1]);
    } else {
        printf("Enter your PHYLOG program (standard input):\n");
        yyin = stdin;
    }
    
    // Initialize the symbol tables
    initialization();
    
    // Parse the input
    if (yyparse() == 0) {
        afficher();
    }
    
    // Free all allocated memory
    freeAllTables();
    
    return 0;
}