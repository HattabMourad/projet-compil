
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
     QUOTES = 268,
     IDF = 269,
     INTEGER_VAL = 270,
     FLOAT_VAL = 271,
     CHAR_VAL = 272,
     STRING_VAL = 273,
     INTEGER = 274,
     FLOAT = 275,
     CHAR = 276,
     STRING = 277,
     LPAREN = 278,
     RPAREN = 279,
     LBRACKET = 280,
     RBRACKET = 281,
     COLON = 282,
     COMMA = 283,
     PVG = 284,
     EGAL = 285,
     BARV = 286,
     ADR = 287,
     FORMAT_DOLLAR = 288,
     FORMAT_PERCENT = 289,
     FORMAT_HASH = 290,
     FORMAT_AMP = 291,
     NOT = 292,
     POINT = 293,
     DI = 294,
     EQ = 295,
     LT = 296,
     GT = 297,
     LE = 298,
     GE = 299,
     AND = 300,
     OR = 301,
     DIV = 302,
     MULT = 303,
     MINUS = 304,
     PLUS = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "synt.y"

  char* strVal;
  float floatVal;
  int   entier;
  char* str;
  float reel;
  struct {
    char* type;
    float val;
  } exprAttr;



/* Line 1676 of yacc.c  */
#line 116 "synt.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


