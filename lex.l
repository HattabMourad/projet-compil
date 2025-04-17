%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"
#include "synt.tab.h"

extern int yylval;

int nb_ligne = 1;
int col = 1;
%}

%option noyywrap

IDF     [A-Z][a-zA-Z0-9]{0,7}
INTEGER [0-9]+
FLOAT   [0-9]+\.[0-9]+
CHAR    \'(.|\\n|\\t)\'
STRING  \"([^\"\\]|\\.)*\"

%%

"DATA"      { insertIfNotExists(yytext, "DATA", "Keyword", 0, 1); return DATA; }
"CODE"      { insertIfNotExists(yytext, "CODE", "Keyword", 0, 1); return CODE; }
"END"       { insertIfNotExists(yytext, "END", "Keyword", 0, 1); return END; }
"VECTOR"    { insertIfNotExists(yytext, "VECTOR", "Keyword", 0, 1); return VECTOR; }
"CONST"     { insertIfNotExists(yytext, "CONST", "Keyword", 0, 1); return CONST; }
"READ"      { insertIfNotExists(yytext, "READ", "Keyword", 0, 1); return READ; }
"DISPLAY"   { insertIfNotExists(yytext, "DISPLAY", "Keyword", 0, 1); return DISPLAY; }
"INTEGER"   { insertIfNotExists(yytext, "INTEGER", "Keyword", 0, 1); return INTEGER; }
"FLOAT"     { insertIfNotExists(yytext, "FLOAT", "Keyword", 0, 1); return FLOAT; }
"CHAR"      { insertIfNotExists(yytext, "CHAR", "Keyword", 0, 1); return CHAR; }
"STRING"    { insertIfNotExists(yytext, "STRING", "Keyword", 0, 1); return STRING; }
"IF"        { insertIfNotExists(yytext, "IF", "Keyword", 0, 1); return IF; }
"ELSE"      { insertIfNotExists(yytext, "ELSE", "Keyword", 0, 1); return ELSE; }
"FOR"       { insertIfNotExists(yytext, "FOR", "Keyword", 0, 1); return FOR; }
"OR"        { insertIfNotExists(yytext, "OR", "Keyword", 0, 1); return OR; }
"AND"       { insertIfNotExists(yytext, "AND", "Keyword", 0, 1); return AND; }
"NOT"       { insertIfNotExists(yytext, "NOT", "Keyword", 0, 1); return NOT; }
"GE"        { insertIfNotExists(yytext, "GE", "Keyword", 0, 1); return GE; }
"LE"        { insertIfNotExists(yytext, "LE", "Keyword", 0, 1); return LE; }
"GT"        { insertIfNotExists(yytext, "GT", "Keyword", 0, 1); return GT; }
"LT"        { insertIfNotExists(yytext, "LT", "Keyword", 0, 1); return LT; }
"EQ"        { insertIfNotExists(yytext, "EQ", "Keyword", 0, 1); return EQ; }
"DI"        { insertIfNotExists(yytext, "DI", "Keyword", 0, 1); return DI; }

"("         { insertIfNotExists(yytext, "LPAREN", "Separator", 0, 2); return LPAREN; }
")"         { insertIfNotExists(yytext, "RPAREN", "Separator", 0, 2); return RPAREN; }
"["         { insertIfNotExists(yytext, "LBRACKET", "Separator", 0, 2); return LBRACKET; }
"]"         { insertIfNotExists(yytext, "RBRACKET", "Separator", 0, 2); return RBRACKET; }
":"         { insertIfNotExists(yytext, "COLON", "Separator", 0, 2); return COLON; }
","         { insertIfNotExists(yytext, "COMMA", "Separator", 0, 2); return COMMA; }
";"         { insertIfNotExists(yytext, "PVG", "Separator", 0, 2); return PVG; }
"="         { insertIfNotExists(yytext, "EGAL", "Separator", 0, 2); return EGAL; }
"|"         { insertIfNotExists(yytext, "BARV", "Separator", 0, 2); return BARV; }
"@"         { insertIfNotExists(yytext, "ADR", "Separator", 0, 2); return ADR; }
"."         { insertIfNotExists(yytext, "POINT", "Separator", 0, 2); return POINT; }

"+"         { insertIfNotExists(yytext, "PLUS", "Separator", 0, 2); return PLUS; }
"-"         { insertIfNotExists(yytext, "MINUS", "Separator", 0, 2); return MINUS; }
"*"         { insertIfNotExists(yytext, "MULT", "Separator", 0, 2); return MULT; }
"/"         { insertIfNotExists(yytext, "DIV", "Separator", 0, 2); return DIV; }

\"$\"       { insertIfNotExists(yytext, "FORMAT_DOLLAR", "Separator", 0, 2); return FORMAT_DOLLAR; }
\"%\"       { insertIfNotExists(yytext, "FORMAT_PERCENT", "Separator", 0, 2); return FORMAT_PERCENT; }
\"#\"       { insertIfNotExists(yytext, "FORMAT_HASH", "Separator", 0, 2); return FORMAT_HASH; }
\"&\"       { insertIfNotExists(yytext, "FORMAT_AMP", "Separator", 0, 2); return FORMAT_AMP; }

"§"[^\n]*   { /* Comment line: skip */ }

{IDF}       { insertIfNotExists(yytext, "IDF", "Identifier", 0, 0); return IDF; }
{INTEGER}   { insertIfNotExists(yytext, "INTEGER_VAL", "Integer", atof(yytext), 0); return INTEGER_VAL; }
{FLOAT}     { insertIfNotExists(yytext, "FLOAT_VAL", "Float", atof(yytext), 0); return FLOAT_VAL; }
{CHAR}      { insertIfNotExists(yytext, "CHAR_VAL", "Char", 0, 0); return CHAR_VAL; }
{STRING}    { insertIfNotExists(yytext, "STRING_VAL", "String", 0, 0); return STRING_VAL; }

\n          { nb_ligne++; col = 1; }
[ \t]+      { col += yyleng; }

.           { printf("Lexical error at line %d, column %d: %s\n", nb_ligne, col, yytext); exit(1); }

%%