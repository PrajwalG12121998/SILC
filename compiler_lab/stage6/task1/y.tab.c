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
    OR = 297,
    TYPE = 298,
    ENDTYPE = 299,
    FREE = 300
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
#define TYPE 298
#define ENDTYPE 299
#define FREE 300

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

#line 221 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      49,    50,     2,     2,    48,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    22,    22,    33,    43,    44,    47,    48,    51,    54,
      57,    58,    61,    64,    65,    68,    69,    72,    75,    76,
      79,    80,    81,    84,    85,    86,    89,    93,    94,    97,
     101,   105,   106,   107,   110,   113,   114,   115,   118,   119,
     121,   122,   124,   126,   127,   130,   131,   132,   135,   138,
     141,   176,   177,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   192,   193,   196,   198,   200,   202,   203,
     205,   207,   209,   212,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   235,   236,   237,   240,   241,   242,   243,
     244
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
  "OR", "TYPE", "ENDTYPE", "FREE", "'{'", "'}'", "','", "'('", "')'",
  "'['", "']'", "'.'", "'&'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "TID", "FieldDeclList", "FieldDecl",
  "GDeclBlock", "GDeclList", "GDecl", "Gidlist", "Gid", "newParamList",
  "newParam", "FDefBlock", "FDef", "FID", "ParamList", "Param", "Type",
  "LDeclBlock", "LDecList", "LDecl", "IdList", "TypeName", "MainBlock",
  "Main", "Body", "Slist", "Stmt", "FIELD", "Retstmt", "Repeatstmt",
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
     295,   296,   297,   298,   299,   300,   123,   125,    44,    40,
      41,    91,    93,    46,    38
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -39,     7,    19,    -9,   -95,    -6,   -95,    18,   -95,    13,
      77,   -95,   -95,    13,   -95,   -95,   -95,    83,   -95,    46,
      34,    77,   -95,    52,   -95,    26,     8,   -95,    72,   -95,
     -95,   -16,    -3,   -95,   -95,   -95,   -95,   -95,    39,    51,
     -95,   -95,    95,   148,   110,   -95,    46,   148,    86,   -95,
     -95,   -95,   -95,     2,   -95,   126,    93,   -95,    43,   -95,
     146,   122,   148,   -95,   -95,   -95,   148,   112,   -95,    90,
     153,   -95,   -95,   122,   -95,   162,   -95,   152,   448,   115,
     153,   -95,   -95,   -95,     3,   114,   116,     5,   157,   117,
     118,   448,   154,   158,   448,     0,   448,   -95,   123,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   164,   -95,   128,
     -95,   197,    -2,     0,     0,   198,   -95,     0,     0,   457,
     -95,   -95,   385,    36,   -95,   -95,     0,   199,   318,   -95,
     -95,   203,   202,     0,   -95,   -95,   160,   170,   119,   -95,
     183,   219,   165,   166,     0,   232,   -95,     0,     0,     0,
       0,   -95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -95,   -95,   331,   204,   205,   171,   191,   192,     0,
       0,   366,    96,   -95,   482,   482,   382,   382,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   382,   382,   -95,   -95,   -95,
       0,   448,   448,   268,   281,     0,   -95,   132,    71,   412,
      15,   209,   366,   -95,   448,   212,   217,   -95,   -95,   421,
     -95,   -95,   218,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    14,     9,     0,     7,     0,     1,     0,
       0,     4,     6,     0,    47,    45,    46,     0,    16,     0,
      45,     0,    28,     0,     3,     0,     0,    11,     0,    13,
      15,    20,     0,    19,    49,    27,     2,    30,     0,     0,
       8,    10,     0,    25,     0,    17,     0,    33,     0,    12,
      37,    35,    36,     0,    24,     0,     0,    18,     0,    32,
       0,     0,     0,    21,    26,    22,     0,     0,    34,     0,
       0,    23,    31,     0,    39,     0,    41,     0,     0,     0,
       0,    38,    40,    44,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,   100,    62,
      58,    59,    56,    57,    53,    54,    55,     0,    48,     0,
      42,     0,     0,     0,     0,     0,    97,     0,     0,     0,
      60,    61,     0,    96,    90,    92,     0,     0,     0,    91,
      51,    62,     0,     0,    29,    43,     0,     0,     0,    63,
       0,     0,     0,     0,    95,     0,    89,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    64,     0,     0,     0,    98,     0,     0,     0,
       0,    94,     0,    88,    76,    77,    78,    79,    80,    81,
      82,    85,    84,    83,    86,    74,    75,    73,    71,    72,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,    93,    99,     0,     0,     0,    67,    66,     0,
      69,    70,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   211,   -95,   -95,   220,   -95,   -95,
     227,   -95,   207,   -95,   193,   -95,   224,   -95,   -95,   188,
     -44,   185,   -95,   181,   -95,    11,   238,   -95,   182,   -85,
     -94,   -95,   167,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -87,   -95,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    26,    27,    10,    17,
      18,    32,    33,    53,    54,    21,    22,    38,    58,    59,
      55,    70,    75,    76,    84,    19,    24,    25,    79,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     128,   172,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     107,     4,   130,    60,     1,    87,   119,   123,    88,   122,
      88,    45,   124,   107,     4,    14,   107,   110,   107,     8,
      14,    23,    60,     9,    28,   130,   137,   138,   130,   207,
     140,   141,    23,    43,   136,    44,   125,    28,    11,   145,
     192,   107,    15,    16,   107,    46,   163,    15,    16,   126,
      62,   111,    63,    31,   127,    40,   114,   171,   115,    37,
     174,   175,   176,   177,    13,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    34,    39,    85,    86,    87,    42,
      77,    88,   193,   194,    14,   144,    77,   114,    47,   115,
      14,    66,    89,    67,   204,    90,    91,    14,   205,    92,
      93,    48,    94,   197,   130,   130,   198,   199,   202,    49,
      95,    20,    16,   107,   107,   130,    29,    15,    16,   209,
     107,   107,    56,    74,    15,    16,   107,   147,   148,   149,
     150,   107,    61,    64,   152,   153,   154,   155,   156,   157,
     147,   148,   149,   150,   195,    65,   196,   152,   153,   154,
     155,   156,   157,    68,    69,    50,    78,   158,    73,    83,
     159,   160,   108,   112,   116,   113,   117,   118,   120,    14,
     158,   166,   121,   159,   160,   134,   132,   133,   147,   148,
     149,   150,    51,    52,   203,   152,   153,   154,   155,   156,
     157,   147,   148,   149,   150,    81,    15,    16,   152,   153,
     154,   155,   156,   157,   135,   139,   146,   161,   158,   162,
     164,   159,   160,   191,   169,   170,    12,   192,   188,   189,
     165,   158,   190,   208,   159,   160,   210,   147,   148,   149,
     150,   211,   213,   167,   152,   153,   154,   155,   156,   157,
     147,   148,   149,   150,    30,    35,    41,   152,   153,   154,
     155,   156,   157,    57,    72,    71,    82,   158,    80,    36,
     159,   160,   109,   131,     0,     0,     0,     0,     0,   168,
     158,     0,     0,   159,   160,     0,   147,   148,   149,   150,
       0,     0,   173,   152,   153,   154,   155,   156,   157,   147,
     148,   149,   150,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,   158,     0,     0,   159,
     160,     0,     0,     0,     0,     0,     0,     0,   200,   158,
       0,     0,   159,   160,     0,     0,   147,   148,   149,   150,
       0,   201,   151,   152,   153,   154,   155,   156,   157,   147,
     148,   149,   150,     0,     0,   187,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,   158,     0,     0,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,   159,   160,   147,   148,   149,   150,     0,     0,
       0,   152,   153,   154,   155,   156,   157,     0,     0,     0,
      85,    86,    87,     0,     0,    88,     0,   152,   153,   154,
     155,   156,   157,     0,   158,     0,    89,   159,   160,    90,
      91,     0,     0,    92,    93,   143,    94,    85,    86,    87,
     158,     0,    88,     0,    95,     0,    85,    86,    87,     0,
       0,    88,     0,    89,     0,     0,    90,    91,   206,     0,
      92,    93,    89,    94,     0,    90,    91,     0,   212,    92,
      93,    95,    94,    85,    86,    87,     0,     0,    88,     0,
      95,     0,    85,    86,    87,     0,     0,    88,     0,    89,
       0,     0,    90,    91,     0,     0,    92,    93,    89,    94,
       0,   142,    91,     0,     0,    92,    93,    95,    94,     0,
       0,     0,   149,   150,     0,     0,    95,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,     0,   159,   160
};

static const yytype_int16 yycheck[] =
{
      78,     7,    96,    47,    43,     7,    91,     7,    10,    94,
      10,    14,    12,    91,     7,     7,    94,    14,    96,     0,
       7,    10,    66,    32,    13,   119,   113,   114,   122,    14,
     117,   118,    21,    49,   112,    51,    36,    26,    44,   126,
      25,   119,    34,    35,   122,    48,   133,    34,    35,    49,
      48,    48,    50,     7,    54,    47,    51,   144,    53,     7,
     147,   148,   149,   150,    46,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    40,    49,     5,     6,     7,     7,
      69,    10,   169,   170,     7,    49,    75,    51,    49,    53,
       7,    48,    21,    50,    23,    24,    25,     7,    27,    28,
      29,    50,    31,   190,   198,   199,   191,   192,   195,    14,
      39,    34,    35,   191,   192,   209,    33,    34,    35,   204,
     198,   199,    12,    33,    34,    35,   204,     8,     9,    10,
      11,   209,    46,     7,    15,    16,    17,    18,    19,    20,
       8,     9,    10,    11,    48,    52,    50,    15,    16,    17,
      18,    19,    20,     7,    32,     7,     3,    38,    46,     7,
      41,    42,    47,    49,     7,    49,    49,    49,    14,     7,
      38,    52,    14,    41,    42,    47,    53,    13,     8,     9,
      10,    11,    34,    35,    52,    15,    16,    17,    18,    19,
      20,     8,     9,    10,    11,    33,    34,    35,    15,    16,
      17,    18,    19,    20,     7,     7,     7,     4,    38,     7,
      50,    41,    42,    22,    49,    49,     5,    25,    14,    14,
      50,    38,    51,    14,    41,    42,    14,     8,     9,    10,
      11,    14,    14,    50,    15,    16,    17,    18,    19,    20,
       8,     9,    10,    11,    17,    21,    26,    15,    16,    17,
      18,    19,    20,    46,    66,    62,    75,    38,    73,    21,
      41,    42,    80,    96,    -1,    -1,    -1,    -1,    -1,    50,
      38,    -1,    -1,    41,    42,    -1,     8,     9,    10,    11,
      -1,    -1,    50,    15,    16,    17,    18,    19,    20,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    38,
      -1,    -1,    41,    42,    -1,    -1,     8,     9,    10,    11,
      -1,    50,    14,    15,    16,    17,    18,    19,    20,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
       5,     6,     7,    -1,    -1,    10,    -1,    15,    16,    17,
      18,    19,    20,    -1,    38,    -1,    21,    41,    42,    24,
      25,    -1,    -1,    28,    29,    30,    31,     5,     6,     7,
      38,    -1,    10,    -1,    39,    -1,     5,     6,     7,    -1,
      -1,    10,    -1,    21,    -1,    -1,    24,    25,    26,    -1,
      28,    29,    21,    31,    -1,    24,    25,    -1,    27,    28,
      29,    39,    31,     5,     6,     7,    -1,    -1,    10,    -1,
      39,    -1,     5,     6,     7,    -1,    -1,    10,    -1,    21,
      -1,    -1,    24,    25,    -1,    -1,    28,    29,    21,    31,
      -1,    24,    25,    -1,    -1,    28,    29,    39,    31,    -1,
      -1,    -1,    10,    11,    -1,    -1,    39,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    56,    57,     7,    58,    59,    60,     0,    32,
      63,    44,    59,    46,     7,    34,    35,    64,    65,    80,
      34,    70,    71,    80,    81,    82,    61,    62,    80,    33,
      65,     7,    66,    67,    40,    71,    81,     7,    72,    49,
      47,    62,     7,    49,    51,    14,    48,    49,    50,    14,
       7,    34,    35,    68,    69,    75,    12,    67,    73,    74,
      75,    46,    48,    50,     7,    52,    48,    50,     7,    32,
      76,    69,    74,    46,    33,    77,    78,    80,     3,    83,
      76,    33,    78,     7,    79,     5,     6,     7,    10,    21,
      24,    25,    28,    29,    31,    39,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    97,    47,    83,
      14,    48,    49,    49,    51,    53,     7,    49,    49,    84,
      14,    14,    84,     7,    12,    36,    49,    54,    95,    97,
      85,    87,    53,    13,    47,     7,    97,    95,    95,     7,
      95,    95,    24,    30,    49,    95,     7,     8,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    38,    41,
      42,     4,     7,    95,    50,    50,    52,    50,    50,    49,
      49,    95,    96,    50,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    14,    14,    14,
      51,    22,    25,    95,    95,    48,    50,    95,    84,    84,
      50,    50,    95,    52,    23,    27,    26,    14,    14,    84,
      14,    14,    27,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    67,    68,    68,    68,    69,    70,    70,    71,
      72,    73,    73,    73,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    79,    79,    80,    80,    80,    81,    82,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    88,    89,    90,    90,
      91,    92,    93,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    97,
      97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     4,     1,
       2,     1,     3,     3,     0,     2,     1,     3,     3,     1,
       1,     4,     4,     3,     1,     0,     2,     2,     1,     9,
       1,     3,     1,     0,     2,     1,     1,     1,     3,     2,
       2,     1,     3,     3,     1,     1,     1,     1,     7,     2,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     3,     3,     3,     7,     7,    10,     8,
       8,     5,     5,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     2,
       1,     1,     1,     3,     1,     0,     1,     2,     4,     7,
       1
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
#line 22 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));
                                            fptr = fopen("target_file.xsm","w+");
                                            fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                            //fprintf(fptr, "BRKP\n");
                                            print_typeTable();
                                            printSymbolTable();
                                            //infix_form($$);
                                            codeGen((yyval),fptr); 
                                            printf("Executed successfully\n");
                                            //fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                          }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 33 "exprtree.y" /* yacc.c:1646  */
    { fptr = fopen("target_file.xsm","w+");
                                              fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                              codeGen((yyvsp[0]),fptr);
                                              fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                              print_typeTable();
                                              printf("\n");
                                              printSymbolTable();
                                              printf("Executed successfully\n");}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 51 "exprtree.y" /* yacc.c:1646  */
    { /*Tptr = TInstall(tname,size,$3);*/ }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "exprtree.y" /* yacc.c:1646  */
    {currUserDef = strdup((yyvsp[0])->varname); TInstall((yyvsp[0])->varname,1,NULL);}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 61 "exprtree.y" /* yacc.c:1646  */
    { addField(currUserDef,(yyvsp[-1])->varname,(yyvsp[-2])->varname);}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[0])->varname,currType, 1, 1,NULL);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,currType, 0,0, (yyvsp[-1]));  }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,currType, (yyvsp[-1])->val,1, NULL);}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = (yyvsp[-2]); (yyval) = (yyvsp[0]);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = NULL; (yyval)=(yyvsp[0]);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type1 = paramDatatype;(yyvsp[0])->type = TLookup(currType1);(yyval) = (yyvsp[0]);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 93 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 94 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeFuncDefNode(currType,currFunc,(yyvsp[-1]),(yyvsp[-5]));
                                                                 /*printf("This is Function\n");*/ }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 101 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup((yyvsp[0])->varname); lTableInstall((yyvsp[0])->varname);
             localOffset = 1; argOffset = -3;}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType1,(yyvsp[0])->varname,getArgOffset()); (yyvsp[0])->left = (yyvsp[-2]); (yyval)=(yyvsp[0]);(yyvsp[0])->type = TLookup(currType1);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType1,(yyvsp[0])->varname,getArgOffset()); (yyval) = (yyvsp[0]); (yyvsp[0])->left=NULL;(yyvsp[0])->type = TLookup(currType1);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type = paramDatatype;(yyval) = (yyvsp[0]);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup("int");}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup("str");}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 115 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup((yyvsp[0])->varname);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 118 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 119 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType,(yyvsp[0])->varname,getlocalOffset());}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType,(yyvsp[0])->varname,getlocalOffset());}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(inttype);currType = strdup("int");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(stringtype);currType = strdup("str");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);currType = strdup((yyvsp[0])->varname);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = makeFuncDefNode("int","main",(yyvsp[-1]),NULL);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 138 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup("main");lTableInstall("main");GInstall("main","int",0,0,NULL);
                       localOffset = 1; argOffset = -3;}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 141 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeFuncBodyNode(BODY_,(yyvsp[-2]),(yyvsp[-1])); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 176 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 177 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 180 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 181 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 182 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 183 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 185 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 186 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 187 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(break_,NULL,NULL);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 188 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(continue_,NULL,NULL);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 189 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 192 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-2])->cond = (yyvsp[0]); (yyvsp[0])->cond=NULL;(yyval)=(yyvsp[-2]);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 193 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-2])->cond = (yyvsp[0]); (yyval)= (yyvsp[-2]);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 196 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeRetNode((yyvsp[-1]));}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 198 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(repeatUntil_,(yyvsp[-2]),(yyvsp[-5]));}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 200 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(doWhile_,(yyvsp[-2]),(yyvsp[-5]));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 202 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_t_Else,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 203 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_then,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 205 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(while_,(yyvsp[-5]),(yyvsp[-2]));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 207 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(READ_,(yyvsp[-2]));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 209 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(WRITE_,(yyvsp[-2]));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(ASSIGN_,"void",(yyvsp[-3]),(yyvsp[-1]));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 214 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(AND_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 215 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(OR_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 216 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(PLUS_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 217 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MINUS_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 218 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MUL_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(DIV_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 220 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LT_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 221 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GT_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 222 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(EQ_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 223 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 224 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 225 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(NE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 226 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MOD_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 227 "exprtree.y" /* yacc.c:1646  */
    {printf("I am in FCALL %s\n",(yyvsp[-3])->varname);(yyval)=makeFuncCallNode((yyvsp[-3])->varname,(yyvsp[-1]));}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 228 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 229 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_ADD_; (yyval) = (yyvsp[0]);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 230 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 231 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 232 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 235 "exprtree.y" /* yacc.c:1646  */
    { (yyvsp[0])->middle = (yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 236 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->middle=NULL;(yyval) = (yyvsp[0]);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 237 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 240 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = NULL;(yyval) = (yyvsp[0]);/*printf("%s\n",$1->type->name);*/}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 241 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_VAL_; (yyval) = (yyvsp[0]);}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 242 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-3])->left = (yyvsp[-1]); (yyval)->right=NULL; (yyval)=(yyvsp[-3]);}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 243 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-6])->left = (yyvsp[-4]); (yyvsp[-6])->right = (yyvsp[-1]); (yyval)=(yyvsp[-6]);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 244 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeUserDefinedNode((yyvsp[0]));}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2035 "y.tab.c" /* yacc.c:1646  */
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
#line 246 "exprtree.y" /* yacc.c:1906  */


yyerror(char const* s){
	printf("yyerror %s\n",s);
}

int main(int argc,char *argv[]){ 
  yyin = fopen(argv[1],"r");
  TypeTableCreate();
	yyparse();
	return 0;
}
