
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
     POINT = 264,
     FOR = 265,
     CONST = 266,
     READ = 267,
     DISPLAY = 268,
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
     PLUS = 288,
     MINUS = 289,
     MULT = 290,
     DIV = 291,
     FORMAT_DOLLAR = 292,
     FORMAT_PERCENT = 293,
     FORMAT_HASH = 294,
     FORMAT_AMP = 295,
     OR = 296,
     AND = 297,
     NOT = 298,
     GE = 299,
     LE = 300,
     GT = 301,
     LT = 302,
     EQ = 303,
     DI = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


