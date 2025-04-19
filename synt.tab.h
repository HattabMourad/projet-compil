
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DATA = 258,
     CODE = 259,
     END = 260,
     VECTOR = 261,
     IF = 262,
     ELSE = 263,
     FOR = 264,
     CONST = 265,
     READ = 266,
     DISPLAY = 267,
     IDF = 268,
     INTEGER_VAL = 269,
     FLOAT_VAL = 270,
     CHAR_VAL = 271,
     STRING_VAL = 272,
     INTEGER = 273,
     FLOAT = 274,
     CHAR = 275,
     STRING = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACKET = 279,
     RBRACKET = 280,
     COLON = 281,
     COMMA = 282,
     PVG = 283,
     EGAL = 284,
     BARV = 285,
     ADR = 286,
     FORMAT_DOLLAR = 287,
     FORMAT_PERCENT = 288,
     FORMAT_HASH = 289,
     FORMAT_AMP = 290,
     NOT = 291,
     POINT = 292,
     DI = 293,
     EQ = 294,
     LT = 295,
     GT = 296,
     LE = 297,
     GE = 298,
     AND = 299,
     OR = 300,
     DIV = 301,
     MULT = 302,
     MINUS = 303,
     PLUS = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 26 "synt.y"

  int   entier;
  int   boolVal;
  char* str;
  float reel;
  struct {
    char* type;
    float val;
    char result[32];
  } exprAttr;



/* Line 1676 of yacc.c  */
#line 115 "synt.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


