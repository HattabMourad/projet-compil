%{
#include <stdio.h>
#include <stdlib.h>
#include "synt.tab.h"

int nb_ligne = 1;
int col = 1;
%}

%option noyywrap

IDF     [A-Z][a-zA-Z0-9]{0,7}
INTEGER [0-9]+
FLOAT   [0-9]+\.[0-9]+
CHAR    \'(.|\\n|\\t)\'
STRING  \"[^\"]{2,}\"

%%

"DATA"      { return DATA; }
"CODE"      { return CODE; }
"END"       { return END; }
"VECTOR"    { return VECTOR; }
"CONST"     { return CONST; }
"READ"      { return READ; }
"DISPLAY"   { return DISPLAY; }
"INTEGER"   { return INTEGER; }
"FLOAT"     { return FLOAT; }
"CHAR"      { return CHAR; }
"STRING"    { return STRING; }
"IF"        { return IF; }
"ELSE"      { return ELSE; }
"FOR"       { return FOR; }
"OR"        { return OR; }
"AND"       { return AND; }
"NOT"       { return NOT; }
"GE"        { return GE; }
"LE"        { return LE; }
"GT"        { return GT; }
"LT"        { return LT; }
"EQ"        { return EQ; }
"DI"        { return DI; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
":"         { return COLON; }
","         { return COMMA; }
";"         { return PVG; }
"="         { return EGAL; }
"|"         { return BARV; }
"@"         { return ADR; }
"."         { return POINT; }

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }

"\"$\""     { return FORMAT_DOLLAR; }
"\"%\""     { return FORMAT_PERCENT; }
"\"#\""     { return FORMAT_HASH; }
"\"&\""     { return FORMAT_AMP; }

"§"[^\n]*   { /* Ignore comments */ }

{IDF}       { return IDF; }
{INTEGER}   { return INTEGER_VAL; }
{FLOAT}     { return FLOAT_VAL; }
{CHAR}      { return CHAR_VAL; }
{STRING}    { return STRING_VAL; }

\n          { nb_ligne++; col = 1; }
[ \t]+      { col += yyleng; }

.           { printf("Syntax Error at line %d, column %d: %s\n", nb_ligne, col, yytext); exit(1); }

%%
