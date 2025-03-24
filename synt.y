%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char *s);
%}

%token DATA CODE END VECTOR IF ELSE WHILE DO FOR CONST READ DISPLAY 
%token IDF CST INTEGER_VAL FLOAT_VAL CHAR_VAL STRING_VAL
%token INTEGER FLOAT CHAR STRING 
%token LPAREN RPAREN LBRACKET RBRACKET COLON COMMA PVG EGAL BARV ADR
%token PLUS MINUS MULT DIV FORMAT_DOLLAR FORMAT_PERCENT FORMAT_HASH FORMAT_AMP
%token OR AND NOT GE LE GT LT EQ DI
%token OPCOND 
%%

program:
    IDF DATA statement_list END CODE statement_list END END
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    
    | affectation
    | entree
    | sortie
    | if_else
    | boucle
    ;

type:
    INTEGER
    | FLOAT
    | CHAR
    | STRING
    ;

list_variables:
    IDF 
    | IDF BARV list_variables
    ;  

op_arithmetique:
    PLUS
    | MINUS
    | MULT
    | DIV
    ;

op_logique:
    AND
    | OR
    | NOT
    ;

op_comparaison:
    GT
    | LT
    | GE
    | LE
    | EQ
    | DI
    ;

declaration: 
    type COLON list_variables
    ;

declaration_tableaux:
    VECTOR COLON IDF LBRACKET INTEGER COMMA INTEGER type RBRACKET PVG
    ;

declaration_contantes:
    CONST COLON affectation PVG
    ;

instruction:
    IDF EGAL CST PVG 
    { printf("Instruction: IDF = CST;\n"); }
    | IDF EGAL IDF PLUS CST PVG
    { printf("Instruction: IDF = IDF + CST;\n"); }
    | IDF EGAL IDF MINUS CST PVG
    { printf("Instruction: IDF = IDF - CST;\n"); }
    | IDF EGAL IDF MULT CST PVG
    { printf("Instruction: IDF = IDF * CST;\n"); }
    | IDF EGAL IDF DIV CST PVG
    { printf("Instruction: IDF = IDF / CST;\n"); }
    ;

list_instruction:
    instruction
    | list_instruction instruction
    ;

condition:
    IDF op_comparaison CST  
    { printf("Condition: IDF OPCOND CST\n"); }
    | CST op_comparaison CST 
    { printf("Condition: CST OPCOND CST\n"); }
    ;

expression:
    | CHAR
    | STRING
    ;

affectation:
    IDF EGAL expression PVG
    { printf("Affectation: IDF = CST;\n"); }
    ;

entree:
    READ LPAREN STRING COLON ADR IDF RPAREN PVG
    { printf("Enter: READ(\"format\": @idf);\n"); }
    ;

sortie:
    DISPLAY LPAREN STRING COLON IDF RPAREN PVG
    { printf("DISPLAY(\"message\": idf);\n"); }
    ;

if_else:
    IF LPAREN condition RPAREN COLON instruction ELSE COLON instruction END
    { printf("If-Else: IF(condition): instruction ELSE: instruction END\n"); }
    ;

boucle:
    FOR LPAREN IDF COLON INTEGER COLON condition RPAREN instruction END
    { printf("FOR loop: IDF: step: condition instruction END\n"); }
    ;

%%

void yyerror(const char *s) {
    printf("Error: syntax error\n");
}

int main() {
    printf("Enter your code:\n");
    yyparse();
    return 0;
}
