
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
     WHILE = 264,
     DO = 265,
     POINT = 266,
     FOR = 267,
     CONST = 268,
     READ = 269,
     DISPLAY = 270,
     IDF = 271,
     CST = 272,
     INTEGER_VAL = 273,
     FLOAT_VAL = 274,
     CHAR_VAL = 275,
     STRING_VAL = 276,
     INTEGER = 277,
     FLOAT = 278,
     CHAR = 279,
     STRING = 280,
     LPAREN = 281,
     RPAREN = 282,
     LBRACKET = 283,
     RBRACKET = 284,
     COLON = 285,
     COMMA = 286,
     PVG = 287,
     EGAL = 288,
     BARV = 289,
     ADR = 290,
     PLUS = 291,
     MINUS = 292,
     MULT = 293,
     DIV = 294,
     FORMAT_DOLLAR = 295,
     FORMAT_PERCENT = 296,
     FORMAT_HASH = 297,
     FORMAT_AMP = 298,
     OR = 299,
     AND = 300,
     NOT = 301,
     GE = 302,
     LE = 303,
     GT = 304,
     LT = 305,
     EQ = 306,
     DI = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


