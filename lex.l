%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "synt.tab.h"

int nb_ligne = 1;
int col = 1;
%}

%option noyywrap

IDF     [A-Z][a-zA-Z0-9]{0,7}
INTEGER [-+]?[0-9]+
FLOAT   [-+]?[0-9]+\.[0-9]+
CHAR    \'(.|\\n|\\t)\'
STRING  \"[^\"]{2,}\"

%%

"DATA"      { printf("DATA\n"); return DATA; }
"CODE"      { printf("CODE\n"); return CODE; }
"END"       { printf("END\n"); return END; }
"VECTOR"    { printf("VECTOR\n"); return VECTOR; }
"CONST"     { printf("CONST\n"); return CONST; }
"READ"      { printf("READ\n"); return READ; }
"DISPLAY"   { printf("DISPLAY\n"); return DISPLAY; }
"INTEGER"   { printf("INTEGER\n"); return INTEGER; }
"FLOAT"     { printf("FLOAT\n"); return FLOAT; }
"CHAR"      { printf("CHAR\n"); return CHAR; }
"STRING"    { printf("STRING\n"); return STRING; }
"IF"        { printf("IF\n"); return IF; }
"ELSE"      { printf("ELSE\n"); return ELSE; }
"FOR"       { printf("FOR\n"); return FOR; }

"OR"        { printf("OR\n"); return OR; }
"AND"       { printf("AND\n"); return AND; }
"NOT"       { printf("NOT\n"); return NOT; }
"GE"        { printf("GE\n"); return GE; }
"LE"        { printf("LE\n"); return LE; }
"G"         { printf("GT\n"); return GT; }
"L"         { printf("LT\n"); return LT; }
"EQ"        { printf("EQ\n"); return EQ; }
"DI"        { printf("DI\n"); return DI; }

"("         { printf("(\n"); return LPAREN; }
")"         { printf(")\n"); return RPAREN; }
"["         { printf("[\n"); return LBRACKET; }
"]"         { printf("]\n"); return RBRACKET; }
":"         { printf(":\n"); return COLON; }
","         { printf(",\n"); return COMMA; }
";"         { printf(";\n"); return PVG; }
"="         { printf("=\n"); return EGAL; }
"|"         { printf("|\n"); return BARV; }
"@"         { printf("@\n"); return ADR; }
"."         { printf(".\n"); return POINT; } 

"+"         { printf("+\n"); return PLUS; }
"-"         { printf("-\n"); return MINUS; }
"*"         { printf("*\n"); return MULT; }
"/"         { printf("/\n"); return DIV; }

"\"$\""     { printf("FORMAT: $\n"); return FORMAT_DOLLAR; }
"\"%\""     { printf("FORMAT: %%\n"); return FORMAT_PERCENT; }
"\"#\""     { printf("FORMAT: #\n"); return FORMAT_HASH; }
"\"&\""     { printf("FORMAT: &\n"); return FORMAT_AMP; }

"§"[^\n]*   { /* ignore comments */ }

{IDF}       { printf("IDF: %s\n", yytext); return IDF; }
{INTEGER}   { printf("INTEGER: %s\n", yytext); return INTEGER_VAL; }
{FLOAT}     { printf("FLOAT: %s\n", yytext); return FLOAT_VAL; }
{CHAR}      { printf("CHAR: %s\n", yytext); return CHAR_VAL; }
{STRING}    { printf("STRING: %s\n", yytext); return STRING_VAL; }

\n          { nb_ligne++; col = 1; }
[ \t]+      { col += yyleng; }

.           { printf("Erreur lexicale ligne %d colonne %d: %s\n", nb_ligne, col, yytext); exit(1); }

%%

