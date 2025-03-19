%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nb_ligne = 1;
int col = 1;
%}

IDF [A-Z][a-zA-Z0-9]{0,7}
INTEGER [0-9]+
FLOAT [0-9]+\.[0-9]+
CHAR \'(.|\\n|\\t)\'
STRING \"[^\"]{2,}\"

%%

"DATA"      { printf("DATA\n"); }
"CODE"      { printf("CODE\n"); }
"END"       { printf("END\n"); }
"VECTOR"    { printf("VECTOR\n"); }
"INTEGER"   { printf("INTEGER\n"); }
"FLOAT"     { printf("FLOAT\n"); }
"CONST"     { printf("CONST\n"); }
"READ"      { printf("READ\n"); }
"DISPLAY"   { printf("DISPLAY\n"); }
"CHAR"      { printf("CHAR\n"); }
"STRING"    { printf("STRING\n"); }
"IF"        { printf("IF\n"); }
"ELSE"      { printf("ELSE\n"); }
"FOR"       { printf("FOR\n"); }

"OR"        { printf("OR\n"); }
"AND"       { printf("AND\n"); }
"NOT"       { printf("NOT\n"); }
"GE"        { printf("GE\n"); }
"LE"        { printf("LE\n"); }
"G"         { printf("GT\n"); }
"L"         { printf("LT\n"); }
"EQ"        { printf("EQ\n"); }
"DI"        { printf("DI\n"); }

"("         { printf("(\n"); }
")"         { printf(")\n"); }
"["         { printf("[\n"); }
"]"         { printf("]\n"); }
":"         { printf(":\n"); }
","         { printf(",\n"); }
";"         { printf(";\n"); }
"="         { printf("=\n"); }
"|"         { printf("|\n"); }
"@"         { printf("@\n"); }

"+"         { printf("+\n"); }
"-"         { printf("-\n"); }
"*"         { printf("*\n"); }
"/"         { printf("/\n"); }
"\"$\""     { printf("FORMAT: $\n"); }
"\"%\""     { printf("FORMAT: %%\n"); }
"\"#\""     { printf("FORMAT: #\n"); }
"\"&\""     { printf("FORMAT: &\n"); }



"§"[^\n]*    { /* ignore comments */ }

{IDF}       { printf("IDF: %s\n", yytext); }
{INTEGER}   { printf("INTEGER: %s\n", yytext); }
{FLOAT}     { printf("FLOAT: %s\n", yytext); }
{CHAR}      { printf("CHAR: %s\n", yytext); }
{STRING}    { printf("STRING: %s\n", yytext); }

\n          { nb_ligne++; col = 1; }
[ \t]+      { col += yyleng; }

.           { printf("Erreur lexicale ligne %d colonne %d: %s\n", nb_ligne, col, yytext); exit(1); }

%%

int main ()
{
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
