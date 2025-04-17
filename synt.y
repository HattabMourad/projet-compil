%{
#include <stdio.h>
#include <stdlib.h>
#include "tableSymbole.h"

extern int nb_ligne;
extern int col;
extern FILE* yyin;
void yyerror(const char *s);
int yylex();
%}

%union{
  int entier;
  char* str;
  float reel;
}

%token DATA CODE END VECTOR IF ELSE FOR CONST READ DISPLAY 
%token <str>IDF <entier>INTEGER_VAL <reel>FLOAT_VAL CHAR_VAL STRING_VAL
%token <str>INTEGER <str>FLOAT <str>CHAR <str>STRING 
%token LPAREN RPAREN LBRACKET RBRACKET COLON COMMA PVG EGAL BARV ADR
%token FORMAT_DOLLAR FORMAT_PERCENT FORMAT_HASH FORMAT_AMP
%token NOT POINT
%left PLUS MINUS MULT DIV OR AND GE LE GT LT EQ DI

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

declaration:
      type COLON list_variables PVG
    | VECTOR COLON IDF LBRACKET INTEGER_VAL COMMA INTEGER_VAL COLON type RBRACKET PVG
    | CONST COLON IDF EGAL constant PVG
    ;

list_variables:
      IDF
    | IDF BARV list_variables
    ;

type:
      INTEGER
    | FLOAT
    | CHAR
    | STRING
    ;

constant:
      INTEGER_VAL
    | FLOAT_VAL
    | CHAR_VAL
    | STRING_VAL
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
      { printf("Affectation: IDF = expression;\n"); }
    ;

expression:
      constant
    | IDF
    | IDF op_arithmetique constant
    | IDF op_arithmetique IDF
    ;

op_arithmetique:
      PLUS
    | MINUS
    | MULT
    | DIV
    ;

op_logique:
      OR
    | AND
    | NOT
    ;

io_read:
      READ LPAREN format COLON ADR IDF RPAREN PVG
      { printf("Read Instruction\n"); }
    ;

io_display:
      DISPLAY LPAREN STRING_VAL COLON IDF RPAREN PVG
    | DISPLAY LPAREN STRING_VAL RPAREN PVG
      { printf("Display Instruction\n"); }
    ;

format:
      FORMAT_DOLLAR
    | FORMAT_PERCENT
    | FORMAT_HASH
    | FORMAT_AMP
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
      GT
    | LT
    | GE
    | LE
    | EQ
    | DI
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
        printf("\n=== SYMBOL TABLES ===\n");
        display();
    }
    
    // Free all allocated memory
    freeAllTables();
    
    return 0;
}