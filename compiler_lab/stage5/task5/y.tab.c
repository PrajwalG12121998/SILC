/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "exprtree.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exprtree.h"
#include "symbolTable.h"
#include "exprtree.c"	
#include "symbolTable.c"
int yylex(void);
extern FILE *yyin;
FILE *fptr;
int datatype=0,paramDatatype=0;

#line 80 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGINS = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    ID = 262,
    PLUS = 263,
    MINUS = 264,
    MUL = 265,
    DIV = 266,
    NUM = 267,
    ASSIGN = 268,
    SEMICOLON = 269,
    LT = 270,
    GT = 271,
    EQ = 272,
    NE = 273,
    LE = 274,
    GE = 275,
    IF = 276,
    THEN = 277,
    Else = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    ENDIF = 282,
    BREAK = 283,
    CONTINUE = 284,
    UNTIL = 285,
    REPEAT = 286,
    DECL = 287,
    ENDDECL = 288,
    INTEGER = 289,
    STR = 290,
    STRING = 291,
    DQUOTES = 292,
    MOD = 293,
    RETURN = 294,
    MAIN = 295,
    AND = 296,
    OR = 297
  };
#endif
/* Tokens.  */
#define BEGINS 258
#define END 259
#define READ 260
#define WRITE 261
#define ID 262
#define PLUS 263
#define MINUS 264
#define MUL 265
#define DIV 266
#define NUM 267
#define ASSIGN 268
#define SEMICOLON 269
#define LT 270
#define GT 271
#define EQ 272
#define NE 273
#define LE 274
#define GE 275
#define IF 276
#define THEN 277
#define Else 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define ENDIF 282
#define BREAK 283
#define CONTINUE 284
#define UNTIL 285
#define REPEAT 286
#define DECL 287
#define ENDDECL 288
#define INTEGER 289
#define STR 290
#define STRING 291
#define DQUOTES 292
#define MOD 293
#define RETURN 294
#define MAIN 295
#define AND 296
#define OR 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      44,    45,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    30,    33,    34,    37,    38,    41,    44,
      45,    48,    49,    50,    53,    54,    55,    58,    61,    62,
      65,    69,    74,    75,    76,    79,    82,    83,    86,    87,
      89,    90,    92,    94,    95,    98,    99,   102,   105,   108,
     143,   144,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   159,   161,   163,   165,   166,   168,   170,   172,
     175,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     198,   199,   200,   203,   204,   205,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGINS", "END", "READ", "WRITE", "ID",
  "PLUS", "MINUS", "MUL", "DIV", "NUM", "ASSIGN", "SEMICOLON", "LT", "GT",
  "EQ", "NE", "LE", "GE", "IF", "THEN", "Else", "WHILE", "DO", "ENDWHILE",
  "ENDIF", "BREAK", "CONTINUE", "UNTIL", "REPEAT", "DECL", "ENDDECL",
  "INTEGER", "STR", "STRING", "DQUOTES", "MOD", "RETURN", "MAIN", "AND",
  "OR", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "'&'", "$accept",
  "Program", "GDeclBlock", "GDeclList", "GDecl", "Gidlist", "Gid",
  "newParamList", "newParam", "FDefBlock", "FDef", "FID", "ParamList",
  "Param", "Type", "LDeclBlock", "LDecList", "LDecl", "IdList", "TypeName",
  "MainBlock", "Main", "Body", "Slist", "Stmt", "Retstmt", "Repeatstmt",
  "Dowhilestmt", "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt",
  "AsgStmt", "expr", "ArgList", "loc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    44,    40,    41,    91,    93,   123,   125,
      38
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,    35,    24,    60,   -77,   -77,     2,   -77,     3,   -77,
     -26,    60,   -77,    21,   -77,   -12,   -77,   -77,   -19,   -13,
     -77,   -77,   -77,   -77,   -77,     1,    -7,    62,    38,   -77,
       3,    62,     8,   -77,   -77,   -14,   -77,    68,    43,   -77,
      16,   -77,    91,    71,    62,   -77,   -77,   -77,    62,    56,
     -77,    14,   102,   -77,   -77,    71,   -77,    53,   -77,    99,
     460,    58,   102,   -77,   -77,   -77,    -9,    67,    73,    66,
     112,    76,    83,   460,   125,   126,   460,    10,   460,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   115,   -77,
      92,   -77,   141,     5,    10,    10,   -77,    10,    10,   487,
     -77,   -77,   412,     9,   -77,   -77,    10,   142,   315,   -77,
     -77,   146,    10,   -77,   -77,   106,   162,   114,   175,   213,
     109,   110,    10,   226,   -77,    10,    10,    10,    10,   -77,
      10,    10,    10,    10,    10,    10,    10,    10,    10,   -77,
     328,   143,   144,   113,   138,   137,    10,    10,   363,    46,
     -77,   512,   512,    47,    47,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    47,    47,   -77,   -77,   -77,    10,   460,   460,
     264,   277,    10,   -77,   127,   385,   424,    -6,   149,   363,
     -77,   460,   150,   152,   -77,   -77,   451,   -77,   -77,   153,
     -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,    35,    36,     0,     7,     0,     1,
      35,     0,    19,     0,     3,     0,     4,     6,    11,     0,
      10,    38,    18,     2,    21,     0,     0,    16,     0,     8,
       0,    24,     0,    26,    27,     0,    15,     0,     0,     9,
       0,    23,     0,     0,     0,    12,    17,    13,     0,     0,
      25,     0,     0,    14,    22,     0,    29,     0,    31,     0,
       0,     0,     0,    28,    30,    34,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      51,    47,    48,    45,    46,    42,    43,    44,     0,    37,
       0,    32,     0,     0,     0,     0,    84,     0,     0,     0,
      49,    50,     0,    83,    77,    79,     0,     0,     0,    78,
      40,    51,     0,    20,    33,     0,     0,     0,     0,     0,
       0,     0,    82,     0,    76,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,    85,     0,     0,     0,     0,    81,     0,
      75,    63,    64,    65,    66,    67,    68,    69,    72,    71,
      70,    73,    61,    62,    60,    58,    59,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,    80,
      86,     0,     0,     0,    54,    53,     0,    56,    57,     0,
      55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   169,   -77,   157,   -77,   132,   -77,
     177,   -77,   -77,   148,   -27,   134,   -77,   140,   -77,     0,
     187,   -77,   139,   -67,   -76,   121,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -54,   -77,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    19,    20,    35,    36,    11,
      12,    25,    40,    41,    37,    52,    57,    58,    66,     8,
      14,    15,    61,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   108,   149,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    29,   110,    13,    42,    91,    99,     1,   184,   102,
      18,    13,    69,    88,    21,    70,    88,   103,    88,   169,
      70,    42,   104,   110,     9,    27,   110,    28,    24,    44,
      30,    45,    26,   115,    92,    16,     4,     5,    32,    88,
     116,   117,    88,   118,   119,    31,   105,    56,     4,     5,
      38,    59,   123,   122,   106,    95,    43,    59,   140,    48,
     107,    49,   130,   131,   132,   133,   134,   135,   148,     4,
       5,   151,   152,   153,   154,    46,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   136,    63,     4,     5,   172,
      47,   173,   170,   171,    10,     5,    33,    34,    50,   110,
     110,   175,   176,    51,    55,    60,    65,    89,    88,    88,
     110,    93,    95,   174,   186,    88,    88,    94,   179,    96,
      97,    88,   125,   126,   127,   128,    88,    98,   112,   130,
     131,   132,   133,   134,   135,   125,   126,   127,   128,   100,
     101,   113,   130,   131,   132,   133,   134,   135,   114,   124,
     139,   141,   136,   146,   147,   137,   138,   165,   166,   167,
     168,   143,   169,   185,   187,   136,   188,   190,   137,   138,
     125,   126,   127,   128,   180,    17,    53,   130,   131,   132,
     133,   134,   135,   125,   126,   127,   128,    39,    22,    62,
     130,   131,   132,   133,   134,   135,    54,    64,    23,   111,
     136,    90,     0,   137,   138,     0,     0,   142,     0,     0,
       0,     0,     0,   136,     0,     0,   137,   138,     0,     0,
     144,   125,   126,   127,   128,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   125,   126,   127,   128,     0,     0,
       0,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,   136,     0,     0,   137,   138,     0,     0,   145,     0,
       0,     0,     0,     0,   136,     0,     0,   137,   138,     0,
       0,   150,   125,   126,   127,   128,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   125,   126,   127,   128,     0,
       0,     0,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,   136,     0,     0,   137,   138,     0,     0,   177,
       0,     0,     0,     0,     0,   136,     0,     0,   137,   138,
       0,     0,   178,   125,   126,   127,   128,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   125,   126,   127,   128,
       0,     0,   164,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,   136,     0,     0,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,   137,
     138,   125,   126,   127,   128,     0,     0,     0,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,    70,     0,     0,     0,     0,
       0,   136,     0,     0,   137,   138,    71,     0,   181,    72,
      73,     0,   182,    74,    75,     0,    76,    67,    68,    69,
       0,     0,    70,     0,    77,     0,     0,     0,     0,    67,
      68,    69,     0,    71,    70,     0,    72,    73,     0,     0,
      74,    75,   121,    76,     0,    71,     0,     0,    72,    73,
     183,    77,    74,    75,     0,    76,    67,    68,    69,     0,
       0,    70,     0,    77,     0,    67,    68,    69,     0,     0,
      70,     0,    71,     0,     0,    72,    73,     0,   189,    74,
      75,    71,    76,     0,    72,    73,     0,     0,    74,    75,
      77,    76,    67,    68,    69,     0,     0,    70,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
       0,   120,    73,     0,     0,    74,    75,     0,    76,     0,
       0,     0,   127,   128,     0,     0,    77,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,     0,     0,   137,   138
};

static const yytype_int16 yycheck[] =
{
      60,    14,    78,     3,    31,    14,    73,    32,    14,    76,
       7,    11,     7,    73,    40,    10,    76,     7,    78,    25,
      10,    48,    12,    99,     0,    44,   102,    46,     7,    43,
      43,    45,    44,    93,    43,    33,    34,    35,    45,    99,
      94,    95,   102,    97,    98,    44,    36,    33,    34,    35,
      12,    51,   106,    44,    44,    46,    48,    57,   112,    43,
      50,    45,    15,    16,    17,    18,    19,    20,   122,    34,
      35,   125,   126,   127,   128,     7,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    38,    33,    34,    35,    43,
      47,    45,   146,   147,    34,    35,    34,    35,     7,   175,
     176,   168,   169,    32,    48,     3,     7,    49,   168,   169,
     186,    44,    46,   167,   181,   175,   176,    44,   172,     7,
      44,   181,     8,     9,    10,    11,   186,    44,    13,    15,
      16,    17,    18,    19,    20,     8,     9,    10,    11,    14,
      14,    49,    15,    16,    17,    18,    19,    20,     7,     7,
       4,    45,    38,    44,    44,    41,    42,    14,    14,    46,
      22,    47,    25,    14,    14,    38,    14,    14,    41,    42,
       8,     9,    10,    11,    47,     6,    44,    15,    16,    17,
      18,    19,    20,     8,     9,    10,    11,    30,    11,    55,
      15,    16,    17,    18,    19,    20,    48,    57,    11,    78,
      38,    62,    -1,    41,    42,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,
      45,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    45,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    -1,    45,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    21,    -1,    23,    24,
      25,    -1,    27,    28,    29,    -1,    31,     5,     6,     7,
      -1,    -1,    10,    -1,    39,    -1,    -1,    -1,    -1,     5,
       6,     7,    -1,    21,    10,    -1,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    21,    -1,    -1,    24,    25,
      26,    39,    28,    29,    -1,    31,     5,     6,     7,    -1,
      -1,    10,    -1,    39,    -1,     5,     6,     7,    -1,    -1,
      10,    -1,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    21,    31,    -1,    24,    25,    -1,    -1,    28,    29,
      39,    31,     5,     6,     7,    -1,    -1,    10,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    24,    25,    -1,    -1,    28,    29,    -1,    31,    -1,
      -1,    -1,    10,    11,    -1,    -1,    39,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    52,    53,    34,    35,    54,    55,    70,     0,
      34,    60,    61,    70,    71,    72,    33,    55,     7,    56,
      57,    40,    61,    71,     7,    62,    44,    44,    46,    14,
      43,    44,    45,    34,    35,    58,    59,    65,    12,    57,
      63,    64,    65,    48,    43,    45,     7,    47,    43,    45,
       7,    32,    66,    59,    64,    48,    33,    67,    68,    70,
       3,    73,    66,    33,    68,     7,    69,     5,     6,     7,
      10,    21,    24,    25,    28,    29,    31,    39,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    86,    49,
      73,    14,    43,    44,    44,    46,     7,    44,    44,    74,
      14,    14,    74,     7,    12,    36,    44,    50,    84,    86,
      75,    76,    13,    49,     7,    86,    84,    84,    84,    84,
      24,    30,    44,    84,     7,     8,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    38,    41,    42,     4,
      84,    45,    45,    47,    45,    45,    44,    44,    84,    85,
      45,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    14,    14,    14,    46,    22,    25,
      84,    84,    43,    45,    84,    74,    74,    45,    45,    84,
      47,    23,    27,    26,    14,    14,    74,    14,    14,    27,
      14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    60,    60,
      61,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    78,    79,    79,    80,    81,    82,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     2,     1,     3,     3,
       1,     1,     4,     4,     3,     1,     0,     2,     2,     1,
       9,     1,     3,     1,     0,     2,     1,     1,     3,     2,
       2,     1,     3,     3,     1,     1,     1,     7,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     7,     7,    10,     8,     8,     5,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     1,     1,     1,
       3,     1,     0,     1,     2,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 20 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));
                                            fptr = fopen("target_file.xsm","w+");
                                            fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                            //fprintf(fptr, "BRKP\n");
                                            //printSymbolTable();
                                            //infix_form($$);
                                            codeGen((yyval),fptr); 
                                            printf("Executed successfully\n");
                                            fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                          }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 30 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[0])->varname,datatype, 1, 1,NULL); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 49 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,datatype, 0,0, (yyvsp[-1]));  }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 50 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,datatype, (yyvsp[-1])->val,1, NULL);}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 53 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = (yyvsp[-2]); (yyval) = (yyvsp[0]);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 54 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = NULL; (yyval)=(yyvsp[0]);}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 58 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type = paramDatatype;(yyval) = (yyvsp[0]);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 61 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 62 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeFuncDefNode((yyvsp[-8])->type,currFunc,(yyvsp[-1]),(yyvsp[-5]));
                                                                 /*printf("This is Function\n");*/ }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 69 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup((yyvsp[0])->varname); lTableInstall((yyvsp[0])->varname);
             localOffset = 1; argOffset = -3;}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,(yyvsp[0])->type,(yyvsp[0])->varname,getArgOffset()); (yyvsp[0])->left = (yyvsp[-2]); (yyval)=(yyvsp[0]);}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 75 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,(yyvsp[0])->type,(yyvsp[0])->varname,getArgOffset()); (yyval) = (yyvsp[0]); (yyvsp[0])->left=NULL;}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 76 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type = paramDatatype;(yyval) = (yyvsp[0]);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "exprtree.y" /* yacc.c:1646  */
    {paramDatatype = inttype;}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "exprtree.y" /* yacc.c:1646  */
    {paramDatatype = stringtype;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 86 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 87 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 92 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 94 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,datatype,(yyvsp[0])->varname,getlocalOffset());}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 95 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,datatype,(yyvsp[0])->varname,getlocalOffset());}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 98 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(inttype);datatype = inttype;}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 99 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(stringtype);datatype = stringtype;}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 102 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = makeFuncDefNode(inttype,"main",(yyvsp[-1]),NULL);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 105 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup("main");lTableInstall("main");GInstall("main",inttype,0,0,NULL);
                       localOffset = 1; argOffset = -3;}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeFuncBodyNode(BODY_,(yyvsp[-2]),(yyvsp[-1])); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 147 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 148 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 149 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 150 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 153 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 154 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(break_,NULL,NULL);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(continue_,NULL,NULL);}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 156 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeRetNode((yyvsp[-1]));}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 161 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(repeatUntil_,(yyvsp[-2]),(yyvsp[-5]));}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 163 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(doWhile_,(yyvsp[-2]),(yyvsp[-5]));}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 165 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_t_Else,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_then,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(while_,(yyvsp[-5]),(yyvsp[-2]));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 170 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(READ_,(yyvsp[-2]));}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(WRITE_,(yyvsp[-2]));}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 175 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(ASSIGN_,inttype,(yyvsp[-3]),(yyvsp[-1]));}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 177 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(AND_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 178 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(OR_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 179 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(PLUS_,inttype,(yyvsp[-2]),(yyvsp[0]));}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 180 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MINUS_,inttype,(yyvsp[-2]),(yyvsp[0]));}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 181 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MUL_,inttype,(yyvsp[-2]),(yyvsp[0]));}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 182 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(DIV_,inttype,(yyvsp[-2]),(yyvsp[0]));}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 183 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LT_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 184 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GT_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 185 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(EQ_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GE_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 187 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LE_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 188 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(NE_,booltype,(yyvsp[-2]),(yyvsp[0]));}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 189 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MOD_,inttype,(yyvsp[-2]),(yyvsp[0]));}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 190 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=makeFuncCallNode((yyvsp[-3])->varname,(yyvsp[-1])); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 191 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 192 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_ADD_; (yyval) = (yyvsp[0]);}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 193 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 198 "exprtree.y" /* yacc.c:1646  */
    { (yyvsp[0])->cond = (yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 199 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->cond=NULL;(yyval) = (yyvsp[0]);}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 200 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 203 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 204 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_VAL_; (yyval) = (yyvsp[0]);}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 205 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-3])->left = (yyvsp[-1]); (yyval)->right=NULL; (yyval)=(yyvsp[-3]);}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 206 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-6])->left = (yyvsp[-4]); (yyvsp[-6])->right = (yyvsp[-1]); (yyval)=(yyvsp[-6]);}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1962 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 208 "exprtree.y" /* yacc.c:1906  */


yyerror(char const* s){
	printf("yyerror %s\n",s);
}

int main(int argc,char *argv[]){ 
  yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}