
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableSymbole.h"
#include "quads.h"
#include "codegen.h"

extern int nb_ligne;
extern int col;
extern FILE* yyin;
void yyerror(const char *s);
int yylex();
char* currentType = NULL;

// Helper for temporary variable naming
typedef struct { int count; } TempVarGen;
TempVarGen tempGen = {0};
char* newTemp() {
    static char buffer[32];
    sprintf(buffer, "T%d", tempGen.count++);
    return buffer;
}


/* Line 189 of yacc.c  */
#line 99 "synt.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 198 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 210 "synt.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    14,    17,    19,    21,    23,    25,
      30,    42,    49,    53,    55,    57,    59,    61,    63,    65,
      68,    70,    72,    74,    76,    78,    83,    85,    87,    91,
      93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
     113,   122,   130,   136,   147,   155,   157,   163,   167,   173,
     175,   177,   179,   181,   183,   185,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    13,     3,    52,     5,     4,    57,     5,
       5,    -1,    54,    -1,    52,    54,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1,    53,    26,    55,    28,    -1,
       6,    26,    13,    24,    14,    27,    14,    26,    53,    25,
      28,    -1,    10,    26,    13,    29,    56,    28,    -1,    55,
      30,    13,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    58,    -1,    57,    58,    -1,    59,    -1,
      64,    -1,    65,    -1,    66,    -1,    70,    -1,    13,    29,
      60,    28,    -1,    56,    -1,    13,    -1,    60,    61,    60,
      -1,    49,    -1,    48,    -1,    47,    -1,    46,    -1,    45,
      -1,    44,    -1,    36,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    11,    22,    63,    26,    31,    13,    23,
      28,    -1,    12,    22,    17,    26,    13,    23,    28,    -1,
      12,    22,    17,    23,    28,    -1,     7,    22,    67,    23,
      26,    57,     8,    26,    57,     5,    -1,     7,    22,    67,
      23,    26,    57,     5,    -1,    68,    -1,    67,    37,    62,
      37,    68,    -1,    36,    37,    68,    -1,    60,    37,    69,
      37,    60,    -1,    41,    -1,    40,    -1,    43,    -1,    42,
      -1,    39,    -1,    38,    -1,     9,    22,    13,    26,    14,
      26,    13,    23,    57,     5,    -1,     9,    22,    13,    26,
      14,    26,    14,    23,    57,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    64,    65,    69,    70,    71,    72,    76,
      80,    85,    93,    98,   106,   107,   108,   109,   113,   114,
     118,   119,   120,   121,   122,   126,   144,   145,   150,   173,
     174,   175,   176,   180,   181,   182,   186,   187,   188,   189,
     193,   225,   250,   259,   268,   280,   281,   286,   290,   306,
     307,   308,   309,   310,   311,   315,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATA", "CODE", "END", "VECTOR", "IF",
  "ELSE", "FOR", "CONST", "READ", "DISPLAY", "IDF", "INTEGER_VAL",
  "FLOAT_VAL", "CHAR_VAL", "STRING_VAL", "INTEGER", "FLOAT", "CHAR",
  "STRING", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "COLON", "COMMA",
  "PVG", "EGAL", "BARV", "ADR", "FORMAT_DOLLAR", "FORMAT_PERCENT",
  "FORMAT_HASH", "FORMAT_AMP", "NOT", "POINT", "DI", "EQ", "LT", "GT",
  "LE", "GE", "AND", "OR", "DIV", "MULT", "MINUS", "PLUS", "$accept",
  "program", "declarations", "type", "declaration", "list_variables",
  "constant", "instructions", "instruction", "affectation", "expression",
  "op_arithmetique", "op_logique", "format", "io_read", "io_display",
  "if_else", "conditions", "condition", "op_comparaison", "boucle", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    59,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    69,    69,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     2,     1,     1,     1,     1,     4,
      11,     6,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       8,     7,     5,    10,     7,     1,     5,     3,     5,     1,
       1,     1,     1,     1,     1,    10,    10
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     6,     7,
       8,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    20,    21,    22,    23,    24,     9,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    19,    12,     0,    11,    27,     0,    26,     0,
       0,    45,     0,    36,    37,    38,    39,     0,     0,     0,
       2,     0,     0,     0,    32,    31,    30,    29,     0,     0,
       0,     0,     0,     0,     0,    25,     0,    47,    54,    53,
      50,    49,    52,    51,     0,    28,     0,    35,    34,    33,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    44,     0,    46,     0,     0,     0,
      41,    10,     0,     0,     0,    40,     0,     0,     0,    43,
      55,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    23,    58,    31,    32,    33,
      59,    78,   100,    67,    34,    35,    36,    60,    61,    94,
      37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
      20,    24,    26,    34,   -93,    16,    19,   -93,   -93,   -93,
     -93,    29,    30,   -93,    33,    45,    55,   -93,    52,    50,
      40,   109,   -93,    13,    64,   115,    61,    63,    65,    79,
      70,    68,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    90,
      81,   -93,   -93,   -93,   -93,    82,    -8,    99,   101,   100,
      -1,   114,   -93,   -93,   127,   -93,   -93,   105,   -93,    14,
     -12,   -93,   117,   -93,   -93,   -93,   -93,   118,    -6,   -25,
     -93,   119,    -1,    85,   -93,   -93,   -93,   -93,    -1,   120,
     -26,   133,   121,   122,   135,   -93,    73,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   112,    91,   109,   -93,   -93,   -93,
     116,   125,   141,   -93,   132,   131,    -1,    59,    -1,    23,
     134,   130,   136,    91,   -93,   137,   -93,   138,   139,   140,
     -93,   -93,   109,   109,   109,   -93,    77,    93,   102,   -93,
     -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,    74,   148,   -93,   142,   -92,   -31,   -93,
     -49,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -70,   -93,
     -93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    69,    87,    85,   107,    56,    41,    42,    43,    44,
      97,    79,    56,    41,    42,    43,    44,    83,    98,    99,
      84,    74,    75,    76,    77,    80,     4,     3,    57,    95,
     126,   127,   128,     1,    16,     5,   117,   118,   116,     6,
       5,    38,    14,    39,     6,    15,    19,     7,     8,     9,
      10,    73,     7,     8,     9,    10,    18,   113,    20,    21,
      74,    75,    76,    77,   114,    22,    26,   115,    27,    25,
      28,    29,    30,    51,    24,    26,    52,    27,    40,    28,
      29,    30,   129,    46,    26,    47,    27,    48,    28,    29,
      30,     7,     8,     9,    10,    52,    52,    52,   130,    50,
      26,    49,    27,    53,    28,    29,    30,   131,    54,    26,
      55,    27,    62,    28,    29,    30,    26,    68,    27,    70,
      28,    29,    30,    88,    89,    90,    91,    92,    93,    41,
      42,    43,    44,    63,    64,    65,    66,    74,    75,    76,
      77,    71,    72,    81,    82,    86,    96,   101,   104,   106,
     103,   109,   102,   108,   110,   111,   112,   119,   120,    17,
     105,   123,   124,   122,   121,     0,     0,    45,   125
};

static const yytype_int16 yycheck[] =
{
      31,    50,    72,    28,    96,    13,    14,    15,    16,    17,
      36,    23,    13,    14,    15,    16,    17,    23,    44,    45,
      26,    46,    47,    48,    49,    37,     0,     3,    36,    78,
     122,   123,   124,    13,     5,     6,    13,    14,   108,    10,
       6,    28,    26,    30,    10,    26,    13,    18,    19,    20,
      21,    37,    18,    19,    20,    21,    26,   106,    13,     4,
      46,    47,    48,    49,     5,    13,     7,     8,     9,    29,
      11,    12,    13,     5,    24,     7,   107,     9,    14,    11,
      12,    13,     5,    22,     7,    22,     9,    22,    11,    12,
      13,    18,    19,    20,    21,   126,   127,   128,     5,    29,
       7,    22,     9,    13,    11,    12,    13,     5,    27,     7,
      28,     9,    13,    11,    12,    13,     7,    17,     9,     5,
      11,    12,    13,    38,    39,    40,    41,    42,    43,    14,
      15,    16,    17,    32,    33,    34,    35,    46,    47,    48,
      49,    14,    37,    26,    26,    26,    26,    14,    13,    37,
      28,    26,    31,    37,    13,    23,    25,    23,    28,    11,
      86,    23,    23,    26,    28,    -1,    -1,    25,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    51,     3,     0,     6,    10,    18,    19,    20,
      21,    52,    53,    54,    26,    26,     5,    54,    26,    13,
      13,     4,    13,    55,    24,    29,     7,     9,    11,    12,
      13,    57,    58,    59,    64,    65,    66,    70,    28,    30,
      14,    14,    15,    16,    17,    56,    22,    22,    22,    22,
      29,     5,    58,    13,    27,    28,    13,    36,    56,    60,
      67,    68,    13,    32,    33,    34,    35,    63,    17,    60,
       5,    14,    37,    37,    46,    47,    48,    49,    61,    23,
      37,    26,    26,    23,    26,    28,    26,    68,    38,    39,
      40,    41,    42,    43,    69,    60,    26,    36,    44,    45,
      62,    14,    31,    28,    13,    53,    37,    57,    37,    26,
      13,    23,    25,    60,     5,     8,    68,    13,    14,    23,
      28,    28,    26,    23,    23,    28,    57,    57,    57,     5,
       5,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 60 "synt.y"
    { printf("Program parsed successfully!\n"); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 69 "synt.y"
    { currentType = (yyvsp[(1) - (1)].str); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 70 "synt.y"
    { currentType = (yyvsp[(1) - (1)].str); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 71 "synt.y"
    { currentType = (yyvsp[(1) - (1)].str); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 72 "synt.y"
    { currentType = (yyvsp[(1) - (1)].str); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 77 "synt.y"
    {
        currentType = NULL;
      ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 81 "synt.y"
    {
        if(searchVEC((yyvsp[(3) - (11)].str))) { printf ("Error on line %d: Vector %s already exists /n", nb_ligne, (yyvsp[(3) - (11)].str)); }
        else { insertVEC((yyvsp[(3) - (11)].str), (yyvsp[(9) - (11)].str), (yyvsp[(7) - (11)].entier)); }
      ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 86 "synt.y"
    {
        if(doubleDeclaration((yyvsp[(3) - (6)].str))) { printf("Error on line %d: Variable %s already declared\n", nb_ligne, (yyvsp[(3) - (6)].str)); }
        else {insertIfNotExistsIDF((yyvsp[(3) - (6)].str), "CONST", currentType, (yyvsp[(5) - (6)].exprAttr).val); }
      ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 94 "synt.y"
    {
        if(doubleDeclaration((yyvsp[(3) - (3)].str))){ printf("Error on line %d: Variable %s already declared\n", nb_ligne, (yyvsp[(3) - (3)].str)); }
        else {insertIfNotExistsIDF((yyvsp[(3) - (3)].str), "IDF", currentType, 0); }
      ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "synt.y"
    {
        if(doubleDeclaration((yyvsp[(1) - (1)].str))){ printf("Error on line %d: Variable %s already declared\n", nb_ligne, (yyvsp[(1) - (1)].str)); }
        else {insertIfNotExistsIDF((yyvsp[(1) - (1)].str), "IDF", currentType, 0); }
      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 106 "synt.y"
    { (yyval.exprAttr).type = "INTEGER"; (yyval.exprAttr).val = (yyvsp[(1) - (1)].entier); sprintf((yyval.exprAttr).result, "%d", (yyvsp[(1) - (1)].entier)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 107 "synt.y"
    { (yyval.exprAttr).type = "FLOAT";   (yyval.exprAttr).val = (yyvsp[(1) - (1)].reel); sprintf((yyval.exprAttr).result, "%f", (yyvsp[(1) - (1)].reel)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 108 "synt.y"
    { (yyval.exprAttr).type = "CHAR";    (yyval.exprAttr).val = (yyvsp[(1) - (1)].reel); sprintf((yyval.exprAttr).result, "%c", (yyvsp[(1) - (1)].reel)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 109 "synt.y"
    { (yyval.exprAttr).type = "STRING";  (yyval.exprAttr).val = 0;  strncpy((yyval.exprAttr).result, (yyvsp[(1) - (1)].str), 31); (yyval.exprAttr).result[31] = '\0'; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 127 "synt.y"
    {
        char* type1 = getVarType((yyvsp[(1) - (4)].str));
        char* type2 = (yyvsp[(3) - (4)].exprAttr).type;
        if (type1 == NULL || type2 == NULL) {
            printf("Error on line %d: Variable %s not declared or constant type mismatch\n", nb_ligne, (yyvsp[(1) - (4)].str));
        }
        else if (strcmp(type1, type2) != 0) {
            printf("Error on line %d: Type mismatch between %s and %s\n", nb_ligne, (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprAttr).type);
        }
        else {
            updateIDFValue((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprAttr).val);
            addQuad("=", (yyvsp[(3) - (4)].exprAttr).result[0] ? (yyvsp[(3) - (4)].exprAttr).result : "", "", (yyvsp[(1) - (4)].str));
        }
      ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 144 "synt.y"
    { (yyval.exprAttr).type = (yyvsp[(1) - (1)].exprAttr).type; (yyval.exprAttr).val = (yyvsp[(1) - (1)].exprAttr).val; strncpy((yyval.exprAttr).result, (yyvsp[(1) - (1)].exprAttr).result, 31); (yyval.exprAttr).result[31] = '\0'; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 145 "synt.y"
    { 
        (yyval.exprAttr).type = getVarType((yyvsp[(1) - (1)].str)); 
        (yyval.exprAttr).val = getVarValue((yyvsp[(1) - (1)].str)); 
        strncpy((yyval.exprAttr).result, (yyvsp[(1) - (1)].str), 31); (yyval.exprAttr).result[31] = '\0';
      ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 150 "synt.y"
    {
        if (strcmp((yyvsp[(1) - (3)].exprAttr).type, (yyvsp[(3) - (3)].exprAttr).type) != 0) {
            printf("Type mismatch in expression on line %d\n", nb_ligne);
            exit(1);
        }
        (yyval.exprAttr).type = (yyvsp[(1) - (3)].exprAttr).type;
        char* temp = newTemp();
        addQuad((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].exprAttr).result[0] ? (yyvsp[(1) - (3)].exprAttr).result : "", (yyvsp[(3) - (3)].exprAttr).result[0] ? (yyvsp[(3) - (3)].exprAttr).result : "", temp);
        strcpy((yyval.exprAttr).result, temp);
        if (strcmp((yyvsp[(2) - (3)].str), "+") == 0) (yyval.exprAttr).val = (yyvsp[(1) - (3)].exprAttr).val + (yyvsp[(3) - (3)].exprAttr).val;
        else if (strcmp((yyvsp[(2) - (3)].str), "-") == 0) (yyval.exprAttr).val = (yyvsp[(1) - (3)].exprAttr).val - (yyvsp[(3) - (3)].exprAttr).val;
        else if (strcmp((yyvsp[(2) - (3)].str), "*") == 0) (yyval.exprAttr).val = (yyvsp[(1) - (3)].exprAttr).val * (yyvsp[(3) - (3)].exprAttr).val;
        else if (strcmp((yyvsp[(2) - (3)].str), "/") == 0) {
            if ((yyvsp[(3) - (3)].exprAttr).val != 0) (yyval.exprAttr).val = (yyvsp[(1) - (3)].exprAttr).val / (yyvsp[(3) - (3)].exprAttr).val;
            else {
                printf("Error on line %d: Division by zero\n", nb_ligne);
                exit(1);
            }
        }
      ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 173 "synt.y"
    { (yyval.str) = "+"; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 174 "synt.y"
    { (yyval.str) = "-"; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 175 "synt.y"
    { (yyval.str) = "*"; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 176 "synt.y"
    { (yyval.str) = "/"; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 180 "synt.y"
    { (yyval.str) = "OR"; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 181 "synt.y"
    { (yyval.str) = "AND"; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 182 "synt.y"
    { (yyval.str) = "NOT"; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 186 "synt.y"
    { (yyval.str) = "$"; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 187 "synt.y"
    { (yyval.str) = "%"; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 188 "synt.y"
    { (yyval.str) = "#"; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 189 "synt.y"
    { (yyval.str) = "&"; ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 194 "synt.y"
    {
        char* idf_type = getVarType((yyvsp[(6) - (8)].str));
        if (strcmp((yyvsp[(3) - (8)].str), "$") == 0) {
            if (strcmp(idf_type, "INTEGER") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected INTEGER for $ format\n", nb_ligne);
            }
        } else if (strcmp((yyvsp[(3) - (8)].str), "%") == 0) {
            if (strcmp(idf_type, "FLOAT") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected FLOAT for %% format\n", nb_ligne);
            }
        } else if (strcmp((yyvsp[(3) - (8)].str), "#") == 0) {
            if (strcmp(idf_type, "CHAR") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected CHAR for # format\n", nb_ligne);
            }
        } else if (strcmp((yyvsp[(3) - (8)].str), "&") == 0) {
            if (strcmp(idf_type, "STRING") == 0) {
                printf("Read instruction parsed\n");
            } else {
                printf("Error on line %d: type mismatch, expected STRING for & format\n", nb_ligne);
            }
        }
      ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 226 "synt.y"
    {
        char* str = (yyvsp[(3) - (7)].str);
        int len = strlen(str);
        char fmt = 0;
        if (len > 2 && (str[len-2] == '$' || str[len-2] == '%' || str[len-2] == '#' || str[len-2] == '&')) {
            fmt = str[len-2];
            str[len-2] = '\0';
            str[len-1] = '\0';
        }
        char* phrase = str + 1;
        char* idf_type = getVarType((yyvsp[(5) - (7)].str));
        if (fmt) {
            if ((fmt == '$' && strcmp(idf_type, "INTEGER") == 0) ||
                (fmt == '%' && strcmp(idf_type, "FLOAT") == 0) ||
                (fmt == '#' && strcmp(idf_type, "CHAR") == 0) ||
                (fmt == '&' && strcmp(idf_type, "STRING") == 0)) {
                printf("Display: %s %f\n", phrase, getVarValue((yyvsp[(5) - (7)].str)));
            } else {
                printf("Error: Type mismatch for display format (expected %c for %s)\n", fmt, idf_type);
            }
        } else {
            printf("Display: %s\n", phrase);
        }
      ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 251 "synt.y"
    {
        char* phrase = (yyvsp[(3) - (5)].str) + 1;
        phrase[strlen(phrase) - 1] = '\0';
        printf("Display: %s\n", phrase);
      ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 260 "synt.y"
    {
        if ((yyvsp[(3) - (10)].boolVal)) {
            printf("IF condition true, executing first block\n");
        } else {
            printf("IF condition false, executing else block\n");
        }
        printf("IF parsed\n");
      ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 269 "synt.y"
    {
        if ((yyvsp[(3) - (7)].boolVal)) {
            printf("IF condition true, executing block\n");
        } else {
            printf("IF condition false, skipping block\n");
        }
        printf("IF parsed\n");
      ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 280 "synt.y"
    { (yyval.boolVal) = (yyvsp[(1) - (1)].boolVal); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 282 "synt.y"
    {
        if (strcmp((yyvsp[(3) - (5)].str), "AND") == 0) (yyval.boolVal) = (yyvsp[(1) - (5)].boolVal) && (yyvsp[(5) - (5)].boolVal);
        else if (strcmp((yyvsp[(3) - (5)].str), "OR") == 0) (yyval.boolVal) = (yyvsp[(1) - (5)].boolVal) || (yyvsp[(5) - (5)].boolVal);
      ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 286 "synt.y"
    { (yyval.boolVal) = !(yyvsp[(3) - (3)].boolVal); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 291 "synt.y"
    {
        if (strcmp((yyvsp[(3) - (5)].str), "GT") == 0)  (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val > (yyvsp[(5) - (5)].exprAttr).val);
        else if (strcmp((yyvsp[(3) - (5)].str), "LT") == 0) (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val < (yyvsp[(5) - (5)].exprAttr).val);
        else if (strcmp((yyvsp[(3) - (5)].str), "GE") == 0) (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val >= (yyvsp[(5) - (5)].exprAttr).val);
        else if (strcmp((yyvsp[(3) - (5)].str), "LE") == 0) (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val <= (yyvsp[(5) - (5)].exprAttr).val);
        else if (strcmp((yyvsp[(3) - (5)].str), "EQ") == 0) (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val == (yyvsp[(5) - (5)].exprAttr).val);
        else if (strcmp((yyvsp[(3) - (5)].str), "DI") == 0) (yyval.boolVal) = ((yyvsp[(1) - (5)].exprAttr).val != (yyvsp[(5) - (5)].exprAttr).val);
        else {
            printf("Error on line %d: Unknown comparison operator %s\n", nb_ligne, (yyvsp[(3) - (5)].str));
            (yyval.boolVal) = 0;
        }
      ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 306 "synt.y"
    { (yyval.str) = "GT"; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 307 "synt.y"
    { (yyval.str) = "LT"; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 308 "synt.y"
    { (yyval.str) = "GE"; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 309 "synt.y"
    { (yyval.str) = "LE"; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 310 "synt.y"
    { (yyval.str) = "EQ"; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 311 "synt.y"
    { (yyval.str) = "DI"; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 316 "synt.y"
    { 
        insertIfNotExistsIDF((yyvsp[(3) - (10)].str), "IDF", "INTEGER", 0);
        char* idf_type = getVarType((yyvsp[(7) - (10)].str));
        if (strcmp(idf_type, "INTEGER") != 0) {
            printf("Error on line %d: Type mismatch in FOR loop, expected INTEGER\n", nb_ligne);
        } else {
            int start = (yyvsp[(5) - (10)].entier);
            int end = (int)getVarValue((yyvsp[(7) - (10)].str));
            if (start > end) {
                printf("Error on line %d: FOR loop start value greater than end value\n", nb_ligne);
            } else {
                for (int i = start; i <= end; i++) {
                    updateIDFValue((yyvsp[(3) - (10)].str), i);
                }
            }
        }
      ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 334 "synt.y"
    { 
        insertIfNotExistsIDF((yyvsp[(3) - (10)].str), "IDF", "INTEGER", 0);
        int start = (yyvsp[(5) - (10)].entier);
        int end = (yyvsp[(7) - (10)].entier);
        if (start > end) {
            printf("Error on line %d: FOR loop start value greater than end value\n", nb_ligne);
        } else {
            for (int i = start; i <= end; i++) {
                updateIDFValue((yyvsp[(3) - (10)].str), i);
            }
        }
      ;}
    break;



/* Line 1455 of yacc.c  */
#line 2001 "synt.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 348 "synt.y"


void yyerror(const char *s) {
    printf("Syntax Error at line %d, column %d: %s\n", nb_ligne, col, s);
}

int main(int argc, char *argv[]) {
    printf("PHYLOG Compiler\n");
    
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Cannot open file %s\n", argv[1]);
            exit(1);
        }
        printf("Parsing file: %s\n", argv[1]);
    } else {
        printf("Enter your PHYLOG program (standard input):\n");
        yyin = stdin;
    }
    
    initialization();
    
    if (yyparse() == 0) {
        afficher();
        printQuads();
        optimizeQuads();
        printQuads();
        generateAssembly("output.asm");
    }
    
    freeAllTables();
    
    return 0;
}
