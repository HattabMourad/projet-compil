%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"
#include "synt.tab.h"

int nb_ligne = 1;
int col = 1;
extern YYSTYPE yylval;
%}

%option noyywrap

IDF     [A-Z][a-zA-Z0-9]{0,7}
INTEGER [0-9]+
FLOAT   [0-9]+\.[0-9]+
CHAR    \'(.|\\n|\\t)\'
STRING  \"([^\"\\]|\\.)*\"

%%

"DATA"      { insertSEPKEY(yytext, "KEYWORD", 1); col ++; return DATA; }
"CODE"      { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return CODE; }
"END"       { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return END; }
"VECTOR"    { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return VECTOR; }
"CONST"     { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return CONST; }
"READ"      { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return READ; }
"DISPLAY"   { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return DISPLAY; }
"INTEGER"   { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); yylval.str = strdup("INTEGER"); return INTEGER; }
"FLOAT"     { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); yylval.str = strdup("FLOAT"); return FLOAT; }
"CHAR"      { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); yylval.str = strdup("CHAR"); return CHAR; }
"STRING"    { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); yylval.str = strdup("STRING"); return STRING; }
"IF"        { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return IF; }
"ELSE"      { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return ELSE; }
"FOR"       { insertSEPKEY(yytext, "KEYWORD", 1); col += strlen(yytext); return FOR; }

"OR"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return OR; }
"AND"       { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return AND; }
"NOT"       { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return NOT; }
"GE"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return GE; }
"LE"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return LE; }
"GT"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return GT; }
"LT"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return LT; }
"EQ"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return EQ; }
"DI"        { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return DI; }
"("         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return LPAREN; }
")"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return RPAREN; }
"["         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return LBRACKET; }
"]"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return RBRACKET; }
":"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return COLON; }
","         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return COMMA; }
";"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return PVG; }
"="         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return EGAL; }
"|"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return BARV; }
"@"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return ADR; }
"."         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return POINT; }

"+"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return PLUS; }
"-"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return MINUS; }
"*"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return MULT; }
"/"         { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return DIV; }
\"          { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return QUOTES; }
"\"$\""     { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return FORMAT_DOLLAR; }
"\"%\""     { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return FORMAT_PERCENT; }
"\"#\""     { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return FORMAT_HASH; }
"\"&\""     { insertSEPKEY(yytext, "SEPARATOR", 2); col += strlen(yytext); return FORMAT_AMP; }

"§"[^\n]*   { /* Comment line: skip */ }

{IDF}       {  
                col += strlen(yytext); 
                yylval.str = strdup(yytext);
                return IDF; 
            }
{INTEGER}   { 
                insertIfNotExistsIDF(yytext, "CONST", "INTEGER", atoi(yytext));
                col += strlen(yytext);
                yylval.entier = atoi(yytext); return INTEGER_VAL; 
            }
{FLOAT}     {
                insertIfNotExistsIDF(yytext, "CONST", "FLOAT", atof(yytext));
                col += strlen(yytext);
                yylval.reel = atof(yytext); return FLOAT_VAL; 
            }
{CHAR}      { 
                insertIfNotExistsIDF(yytext, "", "CHAR", yytext[1]);
                col += strlen(yytext);
                return CHAR_VAL;
            }
{STRING}    { 
                insertIfNotExistsIDF(yytext, "STRING", "STRING", 0);
                col += strlen(yytext);
                yylval.str = strdup(yytext); return STRING_VAL; 
            }


\n          { nb_ligne++; col = 1; }
[ \t]+      { col += yyleng; }

.           { printf("Lexical error at line %d, column %d: %s\n", nb_ligne, col, yytext); exit(1); }

%%