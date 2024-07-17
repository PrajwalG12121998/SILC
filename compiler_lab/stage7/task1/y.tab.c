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
struct Classtable *Cptr = NULL;

#line 81 "y.tab.c" /* yacc.c:339  */

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
    CLASS = 300,
    ENDCLASS = 301,
    SELF = 302,
    EXTENDS = 303,
    DELETE = 304,
    NEW = 305
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
#define CLASS 300
#define ENDCLASS 301
#define SELF 302
#define EXTENDS 303
#define DELETE 304
#define NEW 305

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

#line 232 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      53,    54,     2,     2,    55,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    23,    23,    37,    51,    52,    55,    56,    59,    62,
      63,    66,    67,    70,    71,    72,    75,    76,    79,    80,
      81,    84,    85,    88,    89,    92,    93,    96,    99,   102,
     103,   106,   109,   110,   113,   114,   117,   120,   121,   124,
     125,   126,   129,   130,   131,   134,   138,   139,   142,   147,
     148,   149,   152,   156,   157,   158,   161,   164,   165,   166,
     169,   170,   172,   173,   175,   177,   178,   181,   182,   183,
     186,   189,   192,   227,   228,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   245,   255,   256,
     259,   260,   261,   263,   265,   267,   269,   270,   272,   274,
     276,   279,   282,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   307,   308,   309,   312,   313,   314,   315,
     316
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
  "OR", "TYPE", "ENDTYPE", "CLASS", "ENDCLASS", "SELF", "EXTENDS",
  "DELETE", "NEW", "'{'", "'}'", "'('", "')'", "','", "'['", "']'", "'.'",
  "'&'", "$accept", "Program", "ClassDefBlock", "ClassDefList", "ClassDef",
  "Cname", "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "TypeDefBlock", "TypeDefList", "TypeDef", "TID", "FieldDeclList",
  "FieldDecl", "GDeclBlock", "GDeclList", "GDecl", "Gidlist", "Gid",
  "newParamList", "newParam", "FDefBlock", "FDef", "TypeF", "FID",
  "ParamList", "Param", "Type", "LDeclBlock", "LDecList", "LDecl",
  "IdList", "TypeName", "MainBlock", "Main", "Body", "Slist", "Stmt",
  "FIELD", "FieldFunction", "Retstmt", "Repeatstmt", "Dowhilestmt",
  "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt", "AsgStmt",
  "newAsgStmt", "expr", "ArgList", "loc", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   123,   125,    40,    41,    44,    91,    93,    46,    38
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    80,   117,    76,  -157,    11,  -157,    81,  -157,  -157,
      91,  -157,  -157,    56,    22,    56,   132,  -157,  -157,  -157,
       8,  -157,   134,    94,  -157,  -157,   102,   186,  -157,   138,
    -157,   136,  -157,   132,  -157,   173,  -157,   122,  -157,  -157,
     178,   192,   208,  -157,  -157,    60,     2,  -157,  -157,  -157,
    -157,  -157,   161,   176,  -157,  -157,  -157,   198,   238,  -157,
     138,   198,   200,   239,  -157,  -157,  -157,   -41,  -157,   245,
     196,  -157,   -22,  -157,   252,   222,   253,   268,   275,  -157,
     289,  -157,  -157,   198,  -157,  -157,   217,   198,  -157,   331,
     280,    69,    72,    78,   277,  -157,   279,   283,  -157,  -157,
     222,  -157,  -157,   334,  -157,   284,  -157,   235,  -157,   198,
    -157,   198,  -157,   198,   240,    47,   241,   242,   280,  -157,
    -157,  -157,     6,   389,  -157,    83,   135,   174,  -157,  -157,
    -157,   246,  -157,   285,   244,   251,    42,   293,   254,   255,
    -157,   291,   292,  -157,     0,   256,   260,  -157,  -157,   321,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   313,   317,
     318,   320,  -157,  -157,    15,     0,     0,    31,  -157,     0,
       0,   416,  -157,  -157,   105,   121,  -157,  -157,   269,     0,
     328,  -157,   442,  -157,   329,    33,  -157,    -1,  -157,  -157,
    -157,   286,   153,    86,   287,  -157,   193,   207,   296,  -157,
     300,     0,    37,   330,   247,  -157,     0,     0,     0,     0,
    -157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -157,   287,   302,   304,   458,   347,   357,   319,   351,   355,
       0,     0,   493,   182,   -27,   335,   336,  -157,   504,   504,
     168,   168,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   168,
     168,   362,   376,  -157,  -157,  -157,     0,  -157,  -157,   261,
     301,  -157,     0,     0,     0,     0,  -157,   337,   140,   323,
     353,     5,   379,   493,   184,   187,   189,   383,  -157,  -157,
     384,   392,  -157,  -157,  -157,  -157,  -157,  -157,   380,  -157,
    -157,   398,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      24,     0,     0,     5,    28,     0,    26,     0,     1,     7,
      33,    23,    25,     0,     0,     0,     0,    69,    67,    68,
       0,    30,     0,     9,     4,     6,     0,     0,    35,     0,
      51,    49,    50,     0,    47,     0,     3,     0,    27,    29,
       0,     0,     0,    32,    34,    39,     0,    38,    71,    46,
       2,    52,     0,     0,    31,    10,    12,    44,     0,    36,
       0,    55,     0,     0,    59,    57,    58,     0,    43,     0,
       0,    37,     0,    54,     0,     0,     0,     0,     0,    11,
       0,    17,    40,     0,    45,    41,     0,     0,    56,     0,
       0,     0,     0,     0,     0,    22,     0,     0,    16,    42,
       0,    53,    61,     0,    63,     0,    74,     0,    13,    55,
      15,    55,    14,    55,     0,     0,     0,     0,     0,    60,
      62,    66,     0,     0,    70,     0,     0,     0,    49,     8,
      21,     0,    64,     0,     0,     0,   126,     0,     0,     0,
      74,     0,     0,    74,     0,     0,     0,    73,   130,    86,
      80,    81,    78,    79,    75,    76,    77,    82,     0,     0,
       0,     0,    48,    65,     0,     0,     0,     0,   127,     0,
       0,     0,    84,    85,     0,   126,   119,   121,     0,     0,
       0,   122,     0,   120,     0,     0,    72,     0,    18,    20,
      19,     0,     0,     0,    89,    88,     0,     0,     0,    86,
       0,   125,     0,     0,     0,   118,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,   124,     0,    89,    88,    87,   117,   105,   106,
     107,   108,   109,   110,   111,   114,   113,   112,   115,   103,
     104,     0,     0,   101,    99,   100,     0,    74,    74,     0,
       0,   116,     0,   125,   125,   125,    83,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   129,    74,
       0,     0,    95,    94,    91,    92,    90,   102,     0,    97,
      98,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   344,
    -157,  -157,  -157,   410,  -157,  -157,   396,  -157,  -157,   403,
    -157,   343,  -157,   342,  -157,   -30,  -157,  -157,    87,   345,
     -49,   333,  -157,   332,  -157,   -10,   401,  -157,   324,  -139,
    -157,  -146,  -157,   308,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -142,  -156,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    14,    25,    26,    63,    79,    80,    81,
     115,     3,     5,     6,     7,    20,    21,    16,    27,    28,
      46,    47,    67,    68,    33,    34,    35,    52,    72,    73,
      74,    90,   103,   104,   122,    22,    36,    37,   107,   123,
     147,   148,   181,   199,   150,   151,   152,   153,   154,   155,
     156,   157,   232,   233,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     158,   171,   182,    49,   174,    29,   175,   175,    69,   137,
     137,   176,   176,    82,    83,    17,    59,    29,     4,   282,
     132,   195,   136,   192,   193,   137,   263,   196,   197,    23,
     258,   167,    86,    87,    69,   177,   177,   204,   194,   222,
     221,   191,    18,    19,   234,   224,   178,   178,   158,   223,
       1,   158,   179,   179,    30,    11,   235,    60,   180,   180,
      38,   133,   145,    17,   238,   239,   240,   241,    24,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   145,   105,
     145,   128,    32,   108,   145,   130,   110,     4,   259,   260,
      18,    19,   112,   105,   206,   207,   208,   209,   166,   129,
     167,   211,   212,   213,   214,   215,   216,   274,   275,   276,
     134,   135,   136,    57,   268,   137,    58,     8,   269,   270,
     273,     9,   109,    15,   217,   111,   138,   218,   219,   139,
     140,   113,    13,   141,   142,   200,   143,   159,    87,    30,
     288,    40,    41,   227,   144,    45,   158,   158,   206,   207,
     208,   209,   145,    42,   146,   211,   212,   213,   214,   215,
     216,   206,   207,   208,   209,   158,    31,    32,   211,   212,
     213,   214,   215,   216,   201,    53,    48,   166,   217,   202,
      51,   218,   219,   211,   212,   213,   214,   215,   216,   160,
      87,   217,    54,    17,   218,   219,   125,   278,   126,    55,
     127,   206,   207,   208,   209,    64,   217,   226,   211,   212,
     213,   214,   215,   216,    61,   206,   207,   208,   209,    43,
      18,    19,   211,   212,   213,   214,   215,   216,   161,    87,
      62,   217,    65,    66,   218,   219,   261,   262,   284,   262,
      56,   285,   262,   286,   262,   217,    76,   228,   218,   219,
      70,    75,    84,    85,    89,   206,   207,   208,   209,    88,
      91,   229,   211,   212,   213,   214,   215,   216,   100,   206,
     207,   208,   209,    77,    78,    92,   211,   212,   213,   214,
     215,   216,    93,   106,   114,   217,   116,   124,   218,   219,
     117,   121,   163,   109,   111,   113,    94,   164,   162,   217,
     168,   237,   218,   219,   165,   172,   173,   169,   170,   206,
     207,   208,   209,   185,   184,   271,   211,   212,   213,   214,
     215,   216,    95,    96,    97,   186,   187,   203,   134,   135,
     136,   188,   189,   137,   190,   205,   220,   236,    17,   217,
     225,    17,   218,   219,   138,   167,   279,   139,   140,   230,
     280,   141,   142,   231,   143,   272,   251,   252,   134,   135,
     136,   254,   144,   137,   102,    18,    19,   119,    18,    19,
     145,   255,   146,   257,   138,   256,   266,   139,   140,   281,
     258,   141,   142,   267,   143,   134,   135,   136,   264,   265,
     137,   277,   144,   283,   134,   135,   136,   287,   289,   137,
     145,   138,   146,    71,   139,   140,   290,   291,   141,   142,
     138,   143,   292,   139,   140,    12,    39,   141,   142,   144,
     143,   134,   135,   136,    98,    99,   137,   145,   144,   146,
      44,   149,   101,   118,    50,   120,   145,   138,   146,     0,
     198,   140,   131,     0,   141,   142,     0,   143,     0,     0,
     206,   207,   208,   209,     0,   144,   210,   211,   212,   213,
     214,   215,   216,   145,     0,   146,   206,   207,   208,   209,
       0,     0,   253,   211,   212,   213,   214,   215,   216,     0,
     217,     0,     0,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,     0,   218,
     219,   206,   207,   208,   209,     0,     0,     0,   211,   212,
     213,   214,   215,   216,   208,   209,     0,     0,     0,   211,
     212,   213,   214,   215,   216,     0,     0,     0,     0,     0,
       0,   217,     0,     0,   218,   219,     0,     0,     0,     0,
       0,     0,   217,     0,     0,   218,   219
};

static const yytype_int16 yycheck[] =
{
     123,   140,   144,    33,   143,    15,     7,     7,    57,    10,
      10,    12,    12,    54,    55,     7,    14,    27,     7,    14,
      14,   167,     7,   165,   166,    10,    53,   169,   170,     7,
      25,    58,    54,    55,    83,    36,    36,   179,     7,   185,
       7,   164,    34,    35,     7,   187,    47,    47,   171,    50,
      43,   174,    53,    53,     7,    44,   202,    55,    59,    59,
      52,    55,    47,     7,   206,   207,   208,   209,    46,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    47,    89,
      47,    34,    35,    14,    47,   115,    14,     7,   230,   231,
      34,    35,    14,   103,     8,     9,    10,    11,    56,    52,
      58,    15,    16,    17,    18,    19,    20,   263,   264,   265,
       5,     6,     7,    53,   256,    10,    56,     0,   257,   258,
     262,    45,    53,    32,    38,    53,    21,    41,    42,    24,
      25,    53,    51,    28,    29,    30,    31,    54,    55,     7,
     279,     7,    48,    57,    39,     7,   269,   270,     8,     9,
      10,    11,    47,    51,    49,    15,    16,    17,    18,    19,
      20,     8,     9,    10,    11,   288,    34,    35,    15,    16,
      17,    18,    19,    20,    53,    53,    40,    56,    38,    58,
       7,    41,    42,    15,    16,    17,    18,    19,    20,    54,
      55,    38,    14,     7,    41,    42,   109,    57,   111,     7,
     113,     8,     9,    10,    11,     7,    38,    54,    15,    16,
      17,    18,    19,    20,    53,     8,     9,    10,    11,    33,
      34,    35,    15,    16,    17,    18,    19,    20,    54,    55,
      54,    38,    34,    35,    41,    42,    54,    55,    54,    55,
      32,    54,    55,    54,    55,    38,     7,    54,    41,    42,
      12,    51,     7,    57,    32,     8,     9,    10,    11,     7,
       7,    54,    15,    16,    17,    18,    19,    20,    51,     8,
       9,    10,    11,    34,    35,     7,    15,    16,    17,    18,
      19,    20,     7,     3,     7,    38,     7,    52,    41,    42,
       7,     7,     7,    53,    53,    53,     7,    53,    52,    38,
       7,    54,    41,    42,    53,    14,    14,    53,    53,     8,
       9,    10,    11,    53,    58,    54,    15,    16,    17,    18,
      19,    20,    33,    34,    35,     4,    13,    58,     5,     6,
       7,    14,    14,    10,    14,     7,     7,     7,     7,    38,
      54,     7,    41,    42,    21,    58,    23,    24,    25,    53,
      27,    28,    29,    53,    31,    54,    54,    53,     5,     6,
       7,    14,    39,    10,    33,    34,    35,    33,    34,    35,
      47,    14,    49,    22,    21,    56,    14,    24,    25,    26,
      25,    28,    29,     7,    31,     5,     6,     7,    53,    53,
      10,    54,    39,    14,     5,     6,     7,    14,    14,    10,
      47,    21,    49,    60,    24,    25,    14,    27,    28,    29,
      21,    31,    14,    24,    25,     5,    20,    28,    29,    39,
      31,     5,     6,     7,    80,    83,    10,    47,    39,    49,
      27,   123,    87,   100,    33,   103,    47,    21,    49,    -1,
      24,    25,   118,    -1,    28,    29,    -1,    31,    -1,    -1,
       8,     9,    10,    11,    -1,    39,    14,    15,    16,    17,
      18,    19,    20,    47,    -1,    49,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    61,    71,     7,    72,    73,    74,     0,    45,
      62,    44,    73,    51,    63,    32,    77,     7,    34,    35,
      75,    76,    95,     7,    46,    64,    65,    78,    79,    95,
       7,    34,    35,    84,    85,    86,    96,    97,    52,    76,
       7,    48,    51,    33,    79,     7,    80,    81,    40,    85,
      96,     7,    87,    53,    14,     7,    32,    53,    56,    14,
      55,    53,    54,    66,     7,    34,    35,    82,    83,    90,
      12,    81,    88,    89,    90,    51,     7,    34,    35,    67,
      68,    69,    54,    55,     7,    57,    54,    55,     7,    32,
      91,     7,     7,     7,     7,    33,    34,    35,    69,    83,
      51,    89,    33,    92,    93,    95,     3,    98,    14,    53,
      14,    53,    14,    53,     7,    70,     7,     7,    91,    33,
      93,     7,    94,    99,    52,    88,    88,    88,    34,    52,
      85,    98,    14,    55,     5,     6,     7,    10,    21,    24,
      25,    28,    29,    31,    39,    47,    49,   100,   101,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   114,    54,
      54,    54,    52,     7,    53,    53,    56,    58,     7,    53,
      53,    99,    14,    14,    99,     7,    12,    36,    47,    53,
      59,   102,   112,   114,    58,    53,     4,    13,    14,    14,
      14,   114,   112,   112,     7,   101,   112,   112,    24,   103,
      30,    53,    58,    58,   112,     7,     8,     9,    10,    11,
      14,    15,    16,    17,    18,    19,    20,    38,    41,    42,
       7,     7,   101,    50,   112,    54,    54,    57,    54,    54,
      53,    53,   112,   113,     7,   101,     7,    54,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,    54,    53,    14,    14,    14,    56,    22,    25,   112,
     112,    54,    55,    53,    53,    53,    14,     7,   112,    99,
      99,    54,    54,   112,   113,   113,   113,    54,    57,    23,
      27,    26,    14,    14,    54,    54,    54,    14,    99,    14,
      14,    27,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      65,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    81,    82,    82,    82,    83,    84,    84,    85,    86,
      86,    86,    87,    88,    88,    88,    89,    90,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    95,    95,    95,
      96,    97,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   103,   104,   105,   106,   106,   107,   108,
     109,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   114,
     114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     2,     0,     8,     1,
       3,     2,     0,     3,     3,     3,     2,     1,     6,     6,
       6,     2,     0,     3,     0,     2,     1,     4,     1,     2,
       1,     3,     3,     0,     2,     1,     3,     3,     1,     1,
       4,     4,     3,     1,     0,     2,     2,     1,     9,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       3,     2,     2,     1,     3,     3,     1,     1,     1,     1,
       7,     2,     4,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     2,     1,     3,     3,     3,
       6,     6,     6,     3,     7,     7,    10,     8,     8,     5,
       5,     4,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     2,     1,
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
#line 23 "exprtree.y" /* yacc.c:1646  */
    {/* $$=makeConnectedNode(CONN_,$3,$4);
                                            fptr = fopen("target_file.xsm","w+");
                                            fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                            //fprintf(fptr, "BRKP\n");
                                            //print_typeTable();
                                            printf("\n");
                                            //printSymbolTable();
                                            //infix_form($$);
                                            printf("\n");
                                            codeGen($$,fptr); 
                                            printf("Executed successfully\n");
                                            fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                            */
                                          }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 37 "exprtree.y" /* yacc.c:1646  */
    { /*fptr = fopen("target_file.xsm","w+");
                                              fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                              codeGen($3,fptr);
                                              fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                              print_typeTable();
                                              printf("\n");
                                              printSymbolTable();*/
                                              printf("\n");
                                              printClassTable();
                                              printf("\n");
                                              printSymbolTable();
                                              printf("Executed successfully\n");}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 51 "exprtree.y" /* yacc.c:1646  */
    {Cptr = NULL;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "exprtree.y" /* yacc.c:1646  */
    { addField_and_Method_count(Cptr,classFieldcount,Methodcount); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[0])->varname,NULL); classFieldcount=0; Methodcount=0;TInstall((yyvsp[0])->varname,1,NULL);}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[-2])->varname,(yyvsp[0])->varname); classFieldcount=0; Methodcount=0;TInstall((yyvsp[-2])->varname,1,NULL);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "exprtree.y" /* yacc.c:1646  */
    {classFieldcount++;}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 70 "exprtree.y" /* yacc.c:1646  */
    {Class_FInstall(Cptr,(yyvsp[-2])->varname,(yyvsp[-1])->varname);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "exprtree.y" /* yacc.c:1646  */
    {Class_FInstall(Cptr,"str",(yyvsp[-1])->varname);}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "exprtree.y" /* yacc.c:1646  */
    {Class_FInstall(Cptr,"int",(yyvsp[-1])->varname);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "exprtree.y" /* yacc.c:1646  */
    {Methodcount++;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "exprtree.y" /* yacc.c:1646  */
    {Methodcount++;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 79 "exprtree.y" /* yacc.c:1646  */
    {Class_MInstall(Cptr,(yyvsp[-4])->varname,(yyvsp[-5])->varname,(yyvsp[-2]));}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "exprtree.y" /* yacc.c:1646  */
    {Class_MInstall(Cptr,(yyvsp[-4])->varname,"str",(yyvsp[-2]));LInstall((yyvsp[-4])->varname,"str","self",getArgOffset());}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "exprtree.y" /* yacc.c:1646  */
    {Class_MInstall(Cptr,(yyvsp[-4])->varname,"int",(yyvsp[-2]));LInstall((yyvsp[-4])->varname,"int","self",getArgOffset());}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 96 "exprtree.y" /* yacc.c:1646  */
    { /*Tptr = TInstall(tname,size,$3);*/ }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 99 "exprtree.y" /* yacc.c:1646  */
    {currUserDef = strdup((yyvsp[0])->varname); TInstall((yyvsp[0])->varname,1,NULL);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "exprtree.y" /* yacc.c:1646  */
    { addField(currUserDef,(yyvsp[-1])->varname,(yyvsp[-2])->varname);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 124 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[0])->varname,currType, 1, 1,NULL);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 125 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,currType, 0,0, (yyvsp[-1]));  }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 126 "exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,currType, (yyvsp[-1])->val,1, NULL);}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 129 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = (yyvsp[-2]); (yyval) = (yyvsp[0]);}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 130 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = NULL; (yyval)=(yyvsp[0]);}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 131 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 134 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type1 = paramDatatype;(yyvsp[0])->type = TLookup(currType1);(yyval) = (yyvsp[0]);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 138 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 139 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "exprtree.y" /* yacc.c:1646  */
    { (yyval)=makeFuncDefNode(currType2,currFunc,(yyvsp[-1]),(yyvsp[-5]),Cptr);
                                                              LInstall(currFunc,currType1,"self",getArgOffset());
                                                              /*printf("This is Function\n");*/ }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(inttype);currType2 = strdup("int");}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 148 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(stringtype);currType2 = strdup("str");}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);currType2 = strdup((yyvsp[0])->varname);}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 152 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup((yyvsp[0])->varname); lTableInstall((yyvsp[0])->varname,Cptr,currType2);
             localOffset = 1; argOffset = -3;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 156 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType1,(yyvsp[0])->varname,getArgOffset()); (yyvsp[0])->left = (yyvsp[-2]); (yyval)=(yyvsp[0]);(yyvsp[0])->type = TLookup(currType1);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 157 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType1,(yyvsp[0])->varname,getArgOffset()); (yyval) = (yyvsp[0]); (yyvsp[0])->left=NULL;(yyvsp[0])->type = TLookup(currType1);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 158 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 161 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->type = paramDatatype;(yyval) = (yyvsp[0]);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 164 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup("int");}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 165 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup("str");}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 166 "exprtree.y" /* yacc.c:1646  */
    {currType1 = strdup((yyvsp[0])->varname);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 169 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 170 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 175 "exprtree.y" /* yacc.c:1646  */
    {}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 177 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType,(yyvsp[0])->varname,getlocalOffset());}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 178 "exprtree.y" /* yacc.c:1646  */
    {LInstall(currFunc,currType,(yyvsp[0])->varname,getlocalOffset());}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(inttype);currType = strdup("int");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeTypeNode(stringtype);currType = strdup("str");}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);currType = strdup((yyvsp[0])->varname);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "exprtree.y" /* yacc.c:1646  */
    { (yyval) = makeFuncDefNode("int","main",(yyvsp[-1]),NULL,NULL);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 189 "exprtree.y" /* yacc.c:1646  */
    {currFunc = strdup("main");lTableInstall("main",NULL,"int");GInstall("main","int",0,0,NULL);
                       localOffset = 1; argOffset = -3;}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 192 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeFuncBodyNode(BODY_,(yyvsp[-2]),(yyvsp[-1])); }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 227 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(CONN_,(yyvsp[-1]),(yyvsp[0]));}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 228 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 231 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 232 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 233 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 236 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 237 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 238 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 240 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(break_,NULL,NULL);}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 241 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConnectedNode(continue_,NULL,NULL);}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 242 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 245 "exprtree.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = makeVariableNode(VAR_,"self",NULL); (yyvsp[-2])->cond = (yyvsp[0]); (yyvsp[0])->cond=NULL;  (yyval) = (yyvsp[-2]); 
                       if(Cptr==NULL){ 
                         printf("Self cannot be used outside class\n"); exit(1);
                       }else{
                         if(Class_FLookup(Cptr,(yyvsp[0])->varname)==NULL){
                          printf("%s Field not declared in %s class\n",(yyvsp[0])->varname,Cptr->name);
                          exit(1);
                         }  
                      }
                     }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 255 "exprtree.y" /* yacc.c:1646  */
    {printf("Hi in field 3\n");(yyvsp[-2])->cond = (yyvsp[0]); (yyval) = (yyvsp[-2]);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 256 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-2])->cond = (yyvsp[0]); (yyvsp[0])->cond=NULL; (yyval)=(yyvsp[-2]);printf("Hi in field 4\n");}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 259 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-5]) = makeVariableNode(VAR_,"self",NULL); (yyvsp[-5])->cond = (yyvsp[-3]); (yyvsp[-3])->cond=NULL;  (yyval) = (yyvsp[-5]);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 260 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=makeMethodCallNode((yyvsp[-5]),(yyvsp[-3])->varname,(yyvsp[-1]));}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 261 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-5])->cond = (yyvsp[-3]); (yyval)=(yyvsp[-5]);}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 263 "exprtree.y" /* yacc.c:1646  */
    {printf("I m in ret node %s\n",(yyvsp[-1])->type->name);(yyval) = makeRetNode((yyvsp[-1]));}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 265 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(repeatUntil_,(yyvsp[-2]),(yyvsp[-5]));}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 267 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(doWhile_,(yyvsp[-2]),(yyvsp[-5]));}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 269 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_t_Else,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 270 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeConditionalNode(If_then,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 272 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWhileNode(while_,(yyvsp[-5]),(yyvsp[-2]));}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 274 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(READ_,(yyvsp[-2]));}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 276 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeWrite_ReadNode(WRITE_,(yyvsp[-2]));}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 279 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(ASSIGN_,"void",(yyvsp[-3]),(yyvsp[-1]));}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 282 "exprtree.y" /* yacc.c:1646  */
    { (yyvsp[-4])=makeFuncCallNode("new",(yyvsp[-2]));
                                                      (yyval) = makeOperatorNode(ASSIGN_,"void",(yyvsp[-6]),(yyvsp[-4])); }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 285 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(AND_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 286 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(OR_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 287 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(PLUS_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 288 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MINUS_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 289 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MUL_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 290 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(DIV_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 291 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LT_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 292 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GT_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 293 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(EQ_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 294 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(GE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 295 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(LE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 296 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(NE_,"bool",(yyvsp[-2]),(yyvsp[0]));}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 297 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(MOD_,"int",(yyvsp[-2]),(yyvsp[0]));}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 298 "exprtree.y" /* yacc.c:1646  */
    {printf("I am in FCALL %s\n",(yyvsp[-3])->varname);(yyval)=makeFuncCallNode((yyvsp[-3])->varname,(yyvsp[-1]));}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 299 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 300 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_ADD_; (yyval) = (yyvsp[0]);}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 301 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 302 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 303 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 307 "exprtree.y" /* yacc.c:1646  */
    { (yyvsp[0])->middle = (yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 308 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->middle=NULL;(yyval) = (yyvsp[0]);}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 309 "exprtree.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 312 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->left = NULL;(yyval) = (yyvsp[0]);/*printf("%s\n",$1->varname);*/}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 313 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0])->nodetype = POI_VAL_; (yyval) = (yyvsp[0]);}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 314 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-3])->left = (yyvsp[-1]); (yyval)->right=NULL; (yyval)=(yyvsp[-3]);}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 315 "exprtree.y" /* yacc.c:1646  */
    {(yyvsp[-6])->left = (yyvsp[-4]); (yyvsp[-6])->right = (yyvsp[-1]); (yyval)=(yyvsp[-6]);}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 316 "exprtree.y" /* yacc.c:1646  */
    {(yyval) = makeUserDefinedNode((yyvsp[0])); printf("In field 2\n");}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2262 "y.tab.c" /* yacc.c:1646  */
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
#line 318 "exprtree.y" /* yacc.c:1906  */


yyerror(char const* s){
	printf("yyerror %s\n",s);
}

int main(int argc,char *argv[]){ 
  yyin = fopen(argv[1],"r");
  TypeTableCreate();
	yyparse();
	return 0;
}
