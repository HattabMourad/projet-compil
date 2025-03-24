
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
     FOR = 266,
     CONST = 267,
     READ = 268,
     DISPLAY = 269,
     IDF = 270,
     CST = 271,
     INTEGER_VAL = 272,
     FLOAT_VAL = 273,
     CHAR_VAL = 274,
     STRING_VAL = 275,
     INTEGER = 276,
     FLOAT = 277,
     CHAR = 278,
     STRING = 279,
     LPAREN = 280,
     RPAREN = 281,
     LBRACKET = 282,
     RBRACKET = 283,
     COLON = 284,
     COMMA = 285,
     PVG = 286,
     EGAL = 287,
     PIPE = 288,
     ADR = 289,
     PLUS = 290,
     MINUS = 291,
     MULT = 292,
     DIV = 293,
     FORMAT_DOLLAR = 294,
     FORMAT_PERCENT = 295,
     FORMAT_HASH = 296,
     FORMAT_AMP = 297,
     OR = 298,
     AND = 299,
     NOT = 300,
     GE = 301,
     LE = 302,
     GT = 303,
     LT = 304,
     EQ = 305,
     DI = 306,
     OPCOND = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


