/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntax.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "hashtbl.h"
#include "quads.h"
#include "target.h"
#include <string.h>

int yyerror(char *yaccProvidedMessage);
int yylex(void);
SymbolType enum_hold = 0;

extern FILE* yyin;
extern char *yytext;
extern int yylex();
extern int yylineno;

int scope=0; /*orizoume to arxiko scope */

SymTable_T table;
int number=1;
int loopcounter = 0;
int loopstart;
int loopend;
extern unsigned int currQuad;
int infunctioncounter=0;

int break_flag = 0;

int loop_label;
//struct quad *quad_head = quads;

//struct breaklist* breaklist;
//struct continuelist* continuelist;  

struct continuelist *cont_list_head;
struct breaklist *break_list_head;


#line 106 "syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    T_EOF = 0,
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    FUNCTION = 262,
    RETURN = 263,
    BREAK = 264,
    CONTINUE = 265,
    LOCAL = 266,
    TRUE = 267,
    FALSE = 268,
    NIL = 269,
    NUMBER = 270,
    ASSIGNMENT = 271,
    AND = 272,
    OR = 273,
    NOTOP = 274,
    ADD = 275,
    UMINUS = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    MOD = 280,
    EQ = 281,
    DIF = 282,
    INC = 283,
    DEC = 284,
    GR = 285,
    GREQ = 286,
    LESS = 287,
    LESSEQ = 288,
    LEFT_CURLY_BRACE = 289,
    RIGHT_CURLY_BRACE = 290,
    LEFT_BRACKET = 291,
    RIGHT_BRACKET = 292,
    RIGHT_PARENTHESIS = 293,
    LEFT_PARENTHESIS = 294,
    SEMICOLON = 295,
    COMMA = 296,
    COLON = 297,
    NAMESPACE = 298,
    DOT = 299,
    DOUBLE_DOT = 300,
    UNDERSCORE = 301,
    STRING = 302,
    COMMENT = 303,
    ID = 304,
    MULTIPLE_COMMENT = 305,
    NESTED_COMMENT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 44 "syntax.y" /* yacc.c:355  */
  

	struct expr* exprvalue;
	struct call* callvalue;
	struct for_s * forvalue;
	struct SymbolTableEntry * symbolvalue;
	int intValue;
  	double realValue; 
	char *strval;
	struct stmt_t* stmt_t;
	

#line 212 "syntax.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   150,   158,   160,   165,   168,   172,   176,
     180,   199,   213,   217,   220,   226,   230,   238,   246,   253,
     261,   269,   287,   304,   317,   331,   349,   367,   385,   404,
     409,   410,   416,   422,   443,   464,   484,   505,   509,   529,
     533,   534,   538,   541,   544,   570,   596,   620,   623,   628,
     636,   638,   647,   650,   663,   671,   674,   679,   689,   691,
     702,   710,   713,   721,   724,   734,   748,   762,   764,   773,
     779,   779,   794,   799,   813,   844,   844,   850,   857,   871,
     874,   878,   881,   884,   889,   905,   907,   907,   923,   925,
     933,   938,   942,   949,   952,   955,   957,   963,   972,   980,
     985,   989,  1000,  1010,  1019
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "LOCAL", "TRUE", "FALSE",
  "NIL", "NUMBER", "ASSIGNMENT", "AND", "OR", "NOTOP", "ADD", "UMINUS",
  "SUB", "MUL", "DIV", "MOD", "EQ", "DIF", "INC", "DEC", "GR", "GREQ",
  "LESS", "LESSEQ", "\"{\"", "\"}\"", "\"LEFT_BRACKET\"",
  "\"RIGHT_BRACKET\"", "RIGHT_PARENTHESIS", "LEFT_PARENTHESIS", "\";\"",
  "\",\"", "\":\"", "\"::\"", "\".\"", "\"..\"", "\"_\"", "\"string\"",
  "\"comment\"", "ID", "\"multiple comment\"", "\"nested comment\"",
  "$accept", "program", "statements", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall", "ID2",
  "methodcall", "elists", "elist", "objectdef", "indexeds", "indexed",
  "indexedelem", "block", "$@1", "funcname", "funcprefix", "funcargs",
  "$@2", "funcbody", "funcdef", "const", "idlists", "idlist", "$@3",
  "ifprefix", "if", "elseprefix", "loopstart", "loopend", "loopstmt",
  "whilestart", "whilecond", "while", "N", "M", "forprefix", "for",
  "returnstmt", YY_NULLPTR
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
     305,   306
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,     5,   164,  -164,    -9,  -164,    -5,   -42,    13,    -4,
      -3,     2,  -164,  -164,  -164,  -164,   254,   254,   -10,   -10,
    -164,   215,   203,  -164,     6,  -164,  -164,  -164,   323,  -164,
    -164,  -164,   152,  -164,   -23,  -164,  -164,    15,  -164,  -164,
     164,  -164,    19,  -164,  -164,  -164,  -164,   254,   254,  -164,
    -164,  -164,   342,  -164,  -164,  -164,  -164,  -164,    24,   -27,
     -23,   -27,  -164,   254,   303,     7,    22,  -164,   380,    25,
    -164,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,  -164,   254,  -164,  -164,   254,   254,
      16,    17,  -164,  -164,  -164,   254,   254,    17,  -164,    30,
      63,   254,  -164,   254,   397,    28,  -164,    46,   117,   282,
     254,  -164,  -164,  -164,    53,  -164,    61,   500,    65,    23,
      23,  -164,  -164,  -164,   514,   514,   255,   255,   255,   255,
     486,   431,    64,  -164,  -164,    62,   449,    66,  -164,    54,
    -164,  -164,  -164,   164,   414,   164,  -164,    67,  -164,  -164,
      61,  -164,   254,   303,    73,   254,  -164,  -164,   254,  -164,
    -164,  -164,    72,  -164,  -164,  -164,  -164,   254,   467,  -164,
    -164,    76,    77,  -164,  -164,  -164,  -164,   361,  -164,  -164,
    -164,    75,  -164,  -164,    68,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    96,     0,    73,     0,     0,
       0,     0,    82,    83,    81,    79,     0,     0,     0,     0,
      70,    63,     0,    14,     0,    80,    44,     3,     0,    29,
      15,    37,    39,    47,    40,    41,    12,     0,    13,    43,
       0,     6,     0,     7,    99,     8,     9,     0,    63,    72,
      74,   103,     0,    10,    11,    45,    32,    31,     0,    33,
       0,    35,     4,     0,    61,     0,     0,    67,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,    34,    36,     0,    63,
       0,     0,    53,    55,    56,     0,    63,     0,    75,     0,
      90,     0,    93,    63,     0,     0,   104,     0,     0,     0,
       0,    62,    64,    65,    68,    30,    42,    23,    24,    16,
      17,    18,    19,    20,    21,    22,    28,    25,    26,    27,
      38,     0,     0,    48,    58,     0,     0,     0,    50,    88,
      77,    78,    91,     0,     0,     0,    98,     0,    89,   100,
       0,    71,     0,    61,     0,    63,    49,    57,    63,    51,
      52,    86,     0,    92,    97,    94,    99,     0,     0,    60,
      66,     0,     0,    85,    76,    95,    93,     0,    69,    54,
      59,    87,    99,   101,     0,   102,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,    56,   -32,    -2,  -164,  -164,  -164,    -8,  -164,
       4,  -164,  -164,    36,  -164,   -34,   -46,  -164,  -164,  -164,
     -33,    35,  -164,  -164,  -164,  -164,  -164,  -164,   -18,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   -41,  -164,
    -164,  -164,  -163,  -164,  -164,  -164,  -164
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    64,    29,    30,    31,    32,    33,
      34,    92,    93,   135,    94,   111,    65,    35,   114,    66,
      67,    36,    62,    50,    37,    99,   139,   141,    38,    39,
     181,   162,   173,    40,    41,   143,   145,   175,   146,    42,
     102,    43,   103,   167,    44,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    11,   105,   176,    69,     3,    52,    49,   100,    88,
      59,    61,    89,    95,    56,    57,    96,    90,    91,   185,
      68,    97,    60,    60,    11,    12,    13,    14,    15,    58,
      47,     7,    16,    24,    48,    17,    53,    54,    28,    26,
     107,    18,    19,   132,   112,   104,    75,    76,    77,    21,
     137,    55,    22,    51,    98,    70,    24,   147,   101,   113,
      25,   109,    26,   116,    20,   133,   134,   142,   149,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    71,   130,   150,    73,   131,    74,    75,    76,
      77,    78,    79,   136,   154,    80,    81,    82,    83,   144,
     155,   158,   157,   161,   160,   166,    28,    63,   153,   171,
     174,   163,   172,   165,   179,   180,   184,   186,   108,   169,
       4,   170,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   138,   140,   182,    16,     0,     0,    17,
       0,    28,     0,    28,     0,    18,    19,     0,     0,     0,
     168,    20,   151,    21,     0,     0,    22,    23,     0,     0,
      24,     0,     0,     0,    25,   177,    26,     4,    85,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      86,    87,     0,    16,     0,     0,    17,     0,    88,     0,
       0,    89,    18,    19,     0,     0,    90,    91,    20,     0,
      21,     0,     0,    22,    23,     0,     0,    24,     0,     0,
       7,    25,     0,    26,    11,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,    17,    11,    12,    13,    14,
      15,    18,    19,     0,    16,     0,     0,    17,     0,    21,
       0,     0,    22,    18,    19,     0,    24,     0,     0,    63,
      25,    21,    26,     0,    22,     0,     0,     0,    24,     0,
       0,     0,    25,     0,    26,    11,    12,    13,    14,    15,
       0,     0,     0,    16,     0,    73,    17,    74,    75,    76,
      77,     0,    18,    19,     0,    -1,    -1,    -1,    -1,     0,
      21,     0,     0,    22,     0,     0,     0,    24,     0,    71,
      72,    25,    73,    26,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,     0,     0,     0,     0,
      71,    72,     0,    73,   152,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,     0,     0,     0,
      71,    72,     0,    73,   110,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,     0,     0,    71,
      72,     0,    73,    84,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,     0,     0,    71,    72,
       0,    73,   106,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,     0,     0,    71,    72,     0,
      73,   183,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    71,    72,     0,    73,   115,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    71,    72,     0,    73,   148,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    71,    72,
       0,    73,   164,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,     0,    71,    72,   156,    73,
       0,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,    82,    83,     0,    71,    72,   159,    73,     0,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,     0,   178,    71,    72,     0,    73,     0,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      73,     0,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    73,     0,    74,    75,    76,    77,
      -1,    -1,     0,     0,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       2,    11,    48,   166,    22,     0,     8,    49,    40,    36,
      18,    19,    39,    36,    16,    17,    39,    44,    45,   182,
      22,    44,    18,    19,    11,    12,    13,    14,    15,    39,
      39,     7,    19,    43,    39,    22,    40,    40,    40,    49,
      58,    28,    29,    89,    37,    47,    23,    24,    25,    36,
      96,    49,    39,    40,    39,    49,    43,   103,    39,    37,
      47,    63,    49,    38,    34,    49,    49,     4,    40,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    17,    85,    38,    20,    88,    22,    23,    24,
      25,    26,    27,    95,    41,    30,    31,    32,    33,   101,
      39,    39,    38,    49,    38,    38,   108,    34,   110,   155,
      38,   143,   158,   145,    38,    38,    41,    49,    62,   153,
       3,   154,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    97,    99,   176,    19,    -1,    -1,    22,
      -1,   143,    -1,   145,    -1,    28,    29,    -1,    -1,    -1,
     152,    34,    35,    36,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    47,   167,    49,     3,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      28,    29,    -1,    19,    -1,    -1,    22,    -1,    36,    -1,
      -1,    39,    28,    29,    -1,    -1,    44,    45,    34,    -1,
      36,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,    -1,
       7,    47,    -1,    49,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    11,    12,    13,    14,
      15,    28,    29,    -1,    19,    -1,    -1,    22,    -1,    36,
      -1,    -1,    39,    28,    29,    -1,    43,    -1,    -1,    34,
      47,    36,    49,    -1,    39,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    49,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    20,    22,    22,    23,    24,
      25,    -1,    28,    29,    -1,    30,    31,    32,    33,    -1,
      36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    17,
      18,    47,    20,    49,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    42,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,
      17,    18,    -1,    20,    41,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    17,
      18,    -1,    20,    40,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    17,    18,
      -1,    20,    40,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    17,    18,    -1,
      20,    40,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    17,    18,    -1,    20,    38,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    17,    18,    -1,    20,    38,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    17,    18,
      -1,    20,    38,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    17,    18,    37,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    17,    18,    37,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    35,    17,    18,    -1,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    19,    22,    28,    29,
      34,    36,    39,    40,    43,    47,    49,    55,    56,    57,
      58,    59,    60,    61,    62,    69,    73,    76,    80,    81,
      85,    86,    91,    93,    96,    97,    98,    39,    39,    49,
      75,    40,    56,    40,    40,    49,    56,    56,    39,    60,
      62,    60,    74,    34,    56,    68,    71,    72,    56,    80,
      49,    17,    18,    20,    22,    23,    24,    25,    26,    27,
      30,    31,    32,    33,    40,    16,    28,    29,    36,    39,
      44,    45,    63,    64,    66,    36,    39,    44,    39,    77,
      55,    39,    92,    94,    56,    68,    40,    80,    54,    56,
      41,    67,    37,    37,    70,    38,    38,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    68,    49,    49,    65,    56,    68,    65,    78,
      73,    79,     4,    87,    56,    88,    90,    68,    38,    40,
      38,    35,    42,    56,    41,    39,    37,    38,    39,    37,
      38,    49,    83,    55,    38,    55,    38,    95,    56,    67,
      72,    68,    68,    84,    38,    89,    94,    56,    35,    38,
      38,    82,    90,    40,    41,    94,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    65,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      74,    73,    75,    75,    76,    78,    77,    79,    80,    81,
      81,    81,    81,    81,    82,    82,    84,    83,    83,    85,
      86,    87,    86,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     1,     5,
       3,     0,     2,     0,     3,     3,     3,     0,     2,     5,
       0,     4,     1,     0,     2,     0,     4,     1,     3,     1,
       1,     1,     1,     1,     3,     0,     0,     3,     0,     4,
       2,     1,     4,     0,     0,     3,     1,     3,     3,     0,
       0,     7,     7,     2,     3
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
#line 147 "syntax.y" /* yacc.c:1646  */
    {printf("Start Program\n");}
#line 1516 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "syntax.y" /* yacc.c:1646  */
    {
	
						(yyval.stmt_t) = make_stmt((yyval.stmt_t));
						(yyval.stmt_t)->breaklist = mergelist((yyvsp[-1].stmt_t)->breaklist, (yyvsp[0].stmt_t)->breaklist);
						(yyval.stmt_t)->contlist = mergelist((yyvsp[-1].stmt_t)->contlist, (yyvsp[0].stmt_t)->contlist);

						
						}
#line 1529 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = make_stmt((yyval.stmt_t));}
#line 1535 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 160 "syntax.y" /* yacc.c:1646  */
    { 
						(yyval.stmt_t) = make_stmt((yyval.stmt_t));
						printf("EXPRESSION SEMICOLON ");
						resettemp();
						}
#line 1545 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = make_stmt((yyval.stmt_t));
							printf("Line %d: if Statement\n", yylineno);
						}
#line 1553 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
							printf("Line %d: while Statement\n", yylineno);
						}
#line 1562 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 172 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: for Statement\n", yylineno);
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
						}
#line 1571 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 176 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: return statement\n", yylineno);
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
						}
#line 1580 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 180 "syntax.y" /* yacc.c:1646  */
    {
							
							break_flag = 1;
							printf("Line %d: break statement\n", yylineno);
							//na paroyme to label apo th lista quad
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
							//make_stmt(&$1); //edw den pairnei ena struct stmt_t*? nai
							//make_stmt(stmt_t.breaklist);
							(yyval.stmt_t)->breaklist = newlist(nextquad());
				 			emit(jump_op, NULL, NULL, NULL, 0, yylineno);


							if(loopcounter==0){
								printf("ERROR in line %d: BREAK outside of the loop \n", yylineno);
							}

							//$break.breaklist = newlist(nextquad()); emit(jump,NULL,NULL,0); 

						}
#line 1604 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "syntax.y" /* yacc.c:1646  */
    {
							//printf("Line %d:continue statement\n", yylineno);
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
						
							
							if(loopcounter==0){
								printf("ERROR in line %d: CONTINUE outside of the loop \n", yylineno);
							}
							
							(yyval.stmt_t)->contlist = newlist(nextquad());
				 			emit(jump_op, NULL, NULL, NULL, 0, yylineno);
						}
#line 1621 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 213 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.stmt_t) = (yyvsp[0].stmt_t);
							printf("Line %d: block \n", yylineno);
						}
#line 1630 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));printf("Line %d: function definition statement\n", yylineno);
						}
#line 1638 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 220 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.stmt_t) = make_stmt((yyval.stmt_t));
							//printf("Line %d: Semicolon\n", yylineno);
						}
#line 1647 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 226 "syntax.y" /* yacc.c:1646  */
    {
					    printf("Line %d: Assignment expression\n", yylineno);
					   	(yyval.exprvalue)=(yyvsp[0].exprvalue);
					   }
#line 1656 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 230 "syntax.y" /* yacc.c:1646  */
    {	
						        printf("Line %d: Add expression\n", yylineno);
					  	
							(yyval.exprvalue) = newexpr(arithexpr_e);
							(yyval.exprvalue)->sym = newtemp();
						  	emit(add_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue),0,yylineno); 
						  
						}
#line 1669 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 238 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Sub expression\n", yylineno);

					                (yyval.exprvalue) = newexpr(arithexpr_e);
						  	(yyval.exprvalue)->sym = newtemp();
						  	emit(sub_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue),0,yylineno);

                                                }
#line 1682 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "syntax.y" /* yacc.c:1646  */
    {
						 	printf("Line %d: Multiply expression\n", yylineno);

						  	(yyval.exprvalue) = newexpr(arithexpr_e);
						  	(yyval.exprvalue)->sym = newtemp();
						  	emit(mul_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue),0,yylineno);
						}
#line 1694 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 253 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Division expression\n", yylineno);

					                (yyval.exprvalue) = newexpr(arithexpr_e);
						  	(yyval.exprvalue)->sym = newtemp();
						  	emit(div_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue),0,yylineno);

						}
#line 1707 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 261 "syntax.y" /* yacc.c:1646  */
    {
							 printf("Line %d: Modulo expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(arithexpr_e);
						 	(yyval.exprvalue)->sym = newtemp();
						 	emit(mod_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue),0,yylineno);
						}
#line 1719 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Equal expression\n", yylineno);

						    	(yyval.exprvalue) = newexpr(boolexpr_e);
						   	(yyval.exprvalue)->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;
							tmpexprtrue = newexpr_constbool(1);//true
							tmpexprfalse = newexpr_constbool(0);//false 	
							

							emit(if_eq_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue),NULL, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, (yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,(yyval.exprvalue),0,yylineno);						     
							
						}
#line 1742 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 287 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Not equal expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(boolexpr_e);
						        (yyval.exprvalue)->sym = newtemp();
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_noteq_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue),NULL, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, (yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,(yyval.exprvalue),0,yylineno);						
						}
#line 1763 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 304 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: And expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(boolexpr_e);
						        (yyval.exprvalue)->sym = newtemp();							
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 
							emit(and_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue), 0, yylineno);						
	
						}
#line 1781 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 317 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Or expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(arithexpr_e);
						        (yyval.exprvalue)->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 
							emit(or_op, (yyvsp[-2].exprvalue), (yyvsp[0].exprvalue), (yyval.exprvalue), 0, yylineno);					
	
						}
#line 1800 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 331 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Greater equal expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(boolexpr_e);
						        (yyval.exprvalue)->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_greatereq_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue),NULL, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, (yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,(yyval.exprvalue),0,yylineno);					
						}
#line 1822 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 349 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Less expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(boolexpr_e);
						        (yyval.exprvalue)->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_less_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue), NULL, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, (yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,(yyval.exprvalue),0,yylineno); 
						}
#line 1844 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 367 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Less equal expression\n", yylineno);

						        (yyval.exprvalue) = newexpr(boolexpr_e);
						        (yyval.exprvalue)->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_lesseq_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue),NULL, nextquad()+3,yylineno);
							emit(assign_op,tmpexprfalse,NULL,(yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op, tmpexprtrue,NULL, (yyval.exprvalue),0,yylineno); 						
						}
#line 1866 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 385 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: Greater expression\n", yylineno);

						  	 (yyval.exprvalue) = newexpr(boolexpr_e);
						  	 (yyval.exprvalue)->sym = newtemp();
								
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_greater_op, (yyvsp[-2].exprvalue) , (yyvsp[0].exprvalue),NULL, nextquad()+3,yylineno);
							emit(assign_op,tmpexprfalse,NULL,(yyval.exprvalue),0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno); 
							emit(assign_op, tmpexprtrue,NULL, (yyval.exprvalue),0,yylineno); 								
						}
#line 1888 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 404 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.exprvalue) = (yyvsp[0].exprvalue);
						}
#line 1896 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue) = (yyvsp[-1].exprvalue);}
#line 1902 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 410 "syntax.y" /* yacc.c:1646  */
    {
						        check_arith((yyvsp[0].exprvalue));
                                			(yyval.exprvalue) = newexpr(arithexpr_e);
					            	(yyval.exprvalue)->sym = newtemp();
						      emit(uminus_op, (yyvsp[0].exprvalue), NULL, (yyval.exprvalue), 0, yylineno);
						}
#line 1913 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "syntax.y" /* yacc.c:1646  */
    {
						  printf("Line %d: Not Expression\n", yylineno);
						        (yyval.exprvalue) = newexpr(boolexpr_e);
				                        (yyval.exprvalue)->sym = newtemp();
						        emit(not_op, (yyvsp[0].exprvalue), NULL, (yyval.exprvalue), 0, yylineno);
				                 }
#line 1924 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 422 "syntax.y" /* yacc.c:1646  */
    {
							printf("Line %d: ++ lvalue\n", yylineno);
						 	check_arith((yyvsp[0].exprvalue));
							if ((yyvsp[0].exprvalue)->type == tableitem_e) {
								(yyval.exprvalue) = emit_iftableitem((yyvsp[0].exprvalue));
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);
								emit(add_op, (yyval.exprvalue), tmpexpr, (yyval.exprvalue),0,yylineno);
								emit(tablesetelem_op, (yyvsp[0].exprvalue), (yyvsp[0].exprvalue)->index, (yyval.exprvalue),0,yylineno);
							}
							else {
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);

								emit(add_op, (yyvsp[0].exprvalue),tmpexpr, (yyvsp[0].exprvalue),0,yylineno);
								(yyval.exprvalue) = newexpr(arithexpr_e);
								(yyval.exprvalue)->sym = newtemp();
								emit(assign_op, (yyvsp[0].exprvalue), NULL, (yyval.exprvalue),0,yylineno);
							} 

						}
#line 1950 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 443 "syntax.y" /* yacc.c:1646  */
    {        
							       printf("Line %d: lvalue++\n", yylineno);
							       check_arith((yyvsp[-1].exprvalue));
							       (yyval.exprvalue) = newexpr(var_e);
								(yyval.exprvalue)->sym = newtemp();
								if ((yyvsp[-1].exprvalue)->type == tableitem_e) {
								     struct expr* tmpexpr;
						                     tmpexpr = newexpr_constnum(1);
	 	
							             expr* val = emit_iftableitem((yyvsp[-1].exprvalue));
								     emit(assign_op, val, NULL, (yyval.exprvalue),0,yylineno);
                                                                     emit(add_op, val,tmpexpr, val,0,yylineno);
								     emit(tablesetelem_op, (yyvsp[-1].exprvalue), (yyvsp[-1].exprvalue)->index, val,0,yylineno);
								}
								else {
									struct expr* tmpexpr;
						                        tmpexpr = newexpr_constnum(1);
									emit(assign_op, (yyvsp[-1].exprvalue), NULL, (yyval.exprvalue),0,yylineno);
									emit(add_op, (yyvsp[-1].exprvalue), tmpexpr, (yyvsp[-1].exprvalue),0,yylineno);
								}  
                            }
#line 1976 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 464 "syntax.y" /* yacc.c:1646  */
    {
						         printf("Line %d: --lvalue\n", yylineno);
						    	check_arith((yyvsp[0].exprvalue));
							if ((yyvsp[0].exprvalue)->type == tableitem_e) {
								(yyval.exprvalue) = emit_iftableitem((yyvsp[0].exprvalue));
								struct expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);
								emit(sub_op, (yyval.exprvalue),tmpexpr, (yyval.exprvalue),0,yylineno);
								emit(tablesetelem_op, (yyvsp[0].exprvalue), (yyvsp[0].exprvalue)->index, (yyval.exprvalue),0,yylineno);
							}
							else {
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);

								emit(sub_op, (yyvsp[0].exprvalue),tmpexpr, (yyvsp[0].exprvalue),0,yylineno);
								(yyval.exprvalue) = newexpr(arithexpr_e);
								(yyval.exprvalue)->sym = newtemp();
								emit(assign_op, (yyvsp[0].exprvalue), NULL, (yyval.exprvalue),0,yylineno);
							}  
                        }
#line 2001 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 484 "syntax.y" /* yacc.c:1646  */
    {
						        printf("Line %d: lvalue--\n", yylineno);
						
							       check_arith((yyvsp[-1].exprvalue));
							       (yyval.exprvalue) = newexpr(var_e);
								(yyval.exprvalue)->sym = newtemp();
								if ((yyvsp[-1].exprvalue)->type == tableitem_e) {
								     struct expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);
							            expr* val = emit_iftableitem((yyvsp[-1].exprvalue));
								     emit(assign_op, val, NULL, (yyval.exprvalue),0,yylineno);
                                     emit(sub_op, val,tmpexpr, val,0,yylineno);
								     emit(tablesetelem_op, (yyvsp[-1].exprvalue), (yyvsp[-1].exprvalue)->index, val,0,yylineno);
								}
								else {
									struct expr* tmpexpr;
						                        tmpexpr = newexpr_constnum(1);
									emit(assign_op, (yyvsp[-1].exprvalue), NULL, (yyval.exprvalue),0,yylineno);
									emit(sub_op, (yyvsp[-1].exprvalue), tmpexpr, (yyvsp[-1].exprvalue),0,yylineno);
								}  
						}
#line 2027 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 505 "syntax.y" /* yacc.c:1646  */
    {//printf("Line %d: Primary\n", yylineno);
							(yyval.exprvalue) = (yyvsp[0].exprvalue);
						}
#line 2035 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 509 "syntax.y" /* yacc.c:1646  */
    {
						
							if ((yyvsp[-2].exprvalue)->type == tableitem_e){
								emit(
								tablesetelem_op,(yyvsp[-2].exprvalue),(yyvsp[-2].exprvalue)->index,(yyvsp[0].exprvalue),0,yylineno);
								(yyval.exprvalue) = emit_iftableitem((yyvsp[-2].exprvalue)); 
								(yyval.exprvalue)->type = assignexpr_e;
                        	}
						     else {
								emit( 
								  assign_op,(yyvsp[0].exprvalue),
								  NULL,
								 (yyvsp[-2].exprvalue),0,yylineno
							    );
								(yyval.exprvalue) = newexpr(assignexpr_e);
								(yyval.exprvalue)->sym = newtemp();
								emit(assign_op, (yyvsp[-2].exprvalue), NULL, (yyval.exprvalue),0,yylineno);
							}    
						}
#line 2059 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 529 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.exprvalue)=emit_iftableitem((yyvsp[0].exprvalue));
						
						}
#line 2068 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 533 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(yyvsp[0].exprvalue);}
#line 2074 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 534 "syntax.y" /* yacc.c:1646  */
    {	
							
							(yyval.exprvalue) = (yyvsp[0].exprvalue);
						}
#line 2083 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 538 "syntax.y" /* yacc.c:1646  */
    {
									(yyval.exprvalue) = newexpr(programfunc_e);
									(yyval.exprvalue)->sym = (yyvsp[-1].symbolvalue);}
#line 2091 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 541 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(yyvsp[0].exprvalue);}
#line 2097 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 544 "syntax.y" /* yacc.c:1646  */
    { 
							int dummy_scope = scope;
							int enum_scope;
							int flag = 0; /*0 gia false, 1 gia true*/
							SymbolTableEntry *e;
							//printf("Mphke ID dummy_scope = %d\n", dummy_scope);
							
							/*psakse ean yparxei genika ston table*/
							for(dummy_scope; dummy_scope >= 0; dummy_scope--){

								if(e=SymTable_contains2(table, yytext, dummy_scope)){
									printf("ID %s already exists in table\n", yytext);
									flag = 1;
									break;
								}
							}
							
							if(flag == 0){
								if(scope == 0) enum_scope = 0;
								else if(scope > 0) enum_scope = 1;

								e=SymTable_put(table, yytext, yylineno, scope, enum_scope);
							}
							(yyval.exprvalue)=lvalue_expr(e);

						}
#line 2128 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 570 "syntax.y" /* yacc.c:1646  */
    {
								//printf("\n\n%s\n\n", yytext);
								struct SymbolTableEntry *tmp;
									
									if(scope!=0 ){
										tmp = SymTable_get(table,yytext,0);
										if(tmp !=NULL && tmp->type == LIBFUNC && scope != 0){
											yyerror("ERROR LIBFUNC");
											exit(0);
										}
									}

								SymbolType type = 0;
								SymbolTableEntry *e;
								tmp = SymTable_get(table,yytext,scope);

									if(tmp == NULL){
										if(scope==0){ type = GLOBAL; } else { type = LOCAL2; }

										e=SymTable_put(table, yytext, yylineno, scope, type );
										(yyval.exprvalue)=lvalue_expr(e);
									}else{
										(yyval.exprvalue)=lvalue_expr(tmp);
									}
								}
#line 2158 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 596 "syntax.y" /* yacc.c:1646  */
    { 				/*GLOBAL*/
							struct SymbolTableEntry *temp;
						//	int contains = 0; /*0 = false || 1 = true */

							/*Kane eisagwgh sth lista afou prwta elegkseis ean einai hdh mesa*/
						//	contains = SymTable_contains2(table, yytext, 0);
							
							if( SymTable_contains2(table, yytext, 0)){
								temp = SymTable_get(table, yytext, 0);
								
								/*
								printf("Printing what found for NAMESPACE: ");
								SymTableEntry_print(temp);
								*/
								
								printf("Found\n");
							} else {
								printf("ERROR %s NOT FOUND", yytext);
								yyerror("");
								//exit(0);
							}
							(yyval.exprvalue)=lvalue_expr(temp);
						}
#line 2186 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 620 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(yyvsp[0].exprvalue);}
#line 2192 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 623 "syntax.y" /* yacc.c:1646  */
    {
						printf("%s\n", yytext);
						 printf("Line %d: lvalue.ID\n", yylineno); 
						 (yyval.exprvalue) = member_item((yyvsp[-2].exprvalue),yytext);
						}
#line 2202 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 628 "syntax.y" /* yacc.c:1646  */
    {
						printf("Line %d: lvalue table expression\n\n", yylineno);
						 
						(yyvsp[-3].exprvalue) = emit_iftableitem((yyvsp[-3].exprvalue));
						(yyval.exprvalue) = newexpr(tableitem_e);
						(yyval.exprvalue)->sym = (yyvsp[-3].exprvalue)->sym;
						(yyval.exprvalue)->index = (yyvsp[-1].exprvalue); 
						}
#line 2215 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 636 "syntax.y" /* yacc.c:1646  */
    { printf("Line %d: Call.ID\n", yylineno); 
							(yyval.exprvalue) = member_item((yyvsp[-2].exprvalue), (yyvsp[0].strval));}
#line 2222 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 638 "syntax.y" /* yacc.c:1646  */
    { 
							printf("Line %d: Call table Expression\n", yylineno);
							 
							(yyvsp[-3].exprvalue) = emit_iftableitem((yyvsp[-3].exprvalue));
							(yyval.exprvalue) = newexpr(tableitem_e);
							(yyval.exprvalue)->sym = (yyvsp[-3].exprvalue)->sym;
							(yyval.exprvalue)->index = (yyvsp[-1].exprvalue); 
						}
#line 2235 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 647 "syntax.y" /* yacc.c:1646  */
    {
						 (yyval.exprvalue)=make_call((yyvsp[-3].exprvalue),(yyvsp[-1].exprvalue));
						}
#line 2243 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 650 "syntax.y" /* yacc.c:1646  */
    {
						
							(yyvsp[-1].exprvalue) = emit_iftableitem((yyvsp[-1].exprvalue)); 
							if ((yyvsp[0].callvalue)->method ){
								struct expr* t = (yyvsp[-1].exprvalue);
								(yyvsp[-1].exprvalue) = emit_iftableitem(member_item(t, (yyvsp[0].callvalue)->name));
								t->next=(yyvsp[0].callvalue)->elist;
								(yyvsp[0].callvalue)->elist = t; 
							}
							(yyval.exprvalue)= make_call((yyvsp[-1].exprvalue), (yyvsp[0].callvalue)->elist);
							//$2->elist->next=NULL;
						}
#line 2260 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 663 "syntax.y" /* yacc.c:1646  */
    {
						   struct expr* tmpfunction;
							tmpfunction = newexpr(programfunc_e);
							tmpfunction->sym = (yyvsp[-4].symbolvalue);
							(yyval.exprvalue) = make_call(tmpfunction, (yyvsp[-1].exprvalue)); 
						}
#line 2271 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 671 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.callvalue)=(yyvsp[0].callvalue);
						}
#line 2279 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 674 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.callvalue)=(yyvsp[0].callvalue);
						}
#line 2287 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 679 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.callvalue) = malloc(sizeof(struct call));
						if((yyvsp[-1].exprvalue) == (expr*)0xfff)
							(yyval.callvalue)->elist = NULL; 
						else
							(yyval.callvalue)->elist = (yyvsp[-1].exprvalue); 
						(yyval.callvalue)->method = 0;
						(yyval.callvalue)->name = NULL;						
					}
#line 2301 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 689 "syntax.y" /* yacc.c:1646  */
    {(yyval.strval)=strdup(yytext);}
#line 2307 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 691 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.callvalue) = malloc(sizeof(struct call));
						if((yyvsp[-1].exprvalue) == (expr*)0xfff)
							(yyval.callvalue)->elist = NULL; 
						else
							(yyval.callvalue)->elist = (yyvsp[-1].exprvalue); 
						
						(yyval.callvalue)->method = 1;
						(yyval.callvalue)->name = (yyvsp[-3].strval);
					}
#line 2322 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 702 "syntax.y" /* yacc.c:1646  */
    { 
							(yyval.exprvalue)=NULL;
							(yyvsp[-1].exprvalue)->next=NULL;
							if((yyvsp[0].exprvalue) != (expr*) 0xfff)
							(yyvsp[-1].exprvalue)->next=(yyvsp[0].exprvalue);
							(yyval.exprvalue)=(yyvsp[-1].exprvalue);
						
						}
#line 2335 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 710 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(expr*)0xfff;}
#line 2341 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 713 "syntax.y" /* yacc.c:1646  */
    {	
							(yyval.exprvalue)=NULL;
							(yyvsp[-1].exprvalue)->next=NULL;
							if((yyvsp[0].exprvalue) != (expr*)0xfff)
							(yyvsp[-1].exprvalue)->next=(yyvsp[0].exprvalue);
							(yyval.exprvalue)=(yyvsp[-1].exprvalue);

						}
#line 2354 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 721 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(expr*)0xfff;}
#line 2360 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 724 "syntax.y" /* yacc.c:1646  */
    {
						struct expr* t = newexpr(newtable_e);
						t->sym = newtemp();
						emit(tablecreate_op, t, NULL, NULL,0,yylineno);
						int i;
						for (i = 0; (yyvsp[-1].exprvalue) && (yyvsp[-1].exprvalue)!=(expr*)0xfff; (yyvsp[-1].exprvalue) = (yyvsp[-1].exprvalue)->next){
							emit(tablesetelem_op, t, newexpr_constnum(i++), (yyvsp[-1].exprvalue),0,yylineno);
						}
							(yyval.exprvalue) = t;
					}
#line 2375 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 734 "syntax.y" /* yacc.c:1646  */
    {
						//tablemake
						struct expr* t = newexpr(newtable_e);
						t->sym = newtemp();
						emit(tablecreate_op, t, NULL, NULL,0,yylineno);
						
						int i;
						for (i = 0; (yyvsp[-1].exprvalue) && (yyvsp[-1].exprvalue)!=(expr*)0xfff; (yyvsp[-1].exprvalue) = (yyvsp[-1].exprvalue)->next){
							emit(tablesetelem_op, (yyvsp[-1].exprvalue), (yyvsp[-1].exprvalue)->index, t,0,yylineno);
						}					
						(yyval.exprvalue) = t;

					}
#line 2393 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 748 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.exprvalue)=NULL;
							(yyvsp[0].exprvalue)->next=NULL;
							if((yyvsp[-2].exprvalue) != (expr*) 0xfff){
								expr* e = (yyvsp[-2].exprvalue);
								while(e!=NULL&&e->next!=NULL){
									e=e->next;	
								}
								e->next=(yyvsp[0].exprvalue);
								(yyval.exprvalue)=(yyvsp[-2].exprvalue);
							}else{
								(yyval.exprvalue)=(yyvsp[0].exprvalue);
							}
}
#line 2412 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 762 "syntax.y" /* yacc.c:1646  */
    {(yyval.exprvalue)=(expr*)0xfff;}
#line 2418 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 764 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.exprvalue)=NULL;
							(yyvsp[-1].exprvalue)->next=NULL;
							if((yyvsp[0].exprvalue) != (expr*)0xfff)
							(yyvsp[-1].exprvalue)->next=(yyvsp[0].exprvalue);
							(yyval.exprvalue)=(yyvsp[-1].exprvalue);
						}
#line 2430 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 773 "syntax.y" /* yacc.c:1646  */
    {
							(yyval.exprvalue) = (yyvsp[-3].exprvalue);
							(yyval.exprvalue)->index = (yyvsp[-1].exprvalue);
				}
#line 2439 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 779 "syntax.y" /* yacc.c:1646  */
    {++scope;}
#line 2445 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 779 "syntax.y" /* yacc.c:1646  */
    {
							SymTable_hide(table, scope--);
							//printf("Line %d: Block\n", yylineno);
							/*
							printf("I AM IN LINE %d yytext %s\n", yylineno, yytext);
							
							if(break_flag == 1){
								printf("EMIT BREAK\n");
								emit(jump_op, NULL, NULL, NULL,0, yylineno);
								break_flag = 0; 
							}
							*/
							(yyval.stmt_t)=(yyvsp[-1].stmt_t);
					}
#line 2464 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 794 "syntax.y" /* yacc.c:1646  */
    {

					(yyval.strval)=yytext;
	
				 	}
#line 2474 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 801 "syntax.y" /* yacc.c:1646  */
    {
						printf("Line %d: no name function at scope %d \n", yylineno, scope);
						char tempname[200];
						
						//struct SymbolTableEntry *tmp1;
						sprintf(tempname,"_f%u",number);//opou to number ayksanetai
					  	//SymTable_put(table, tempname, yylineno, scope, USERFUNC);
						number++;
						(yyval.strval)=strdup(tempname);
					
					}
#line 2490 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 813 "syntax.y" /* yacc.c:1646  */
    {

						struct SymbolTableEntry *tmp1;
							
							if(SymTable_contains2(table, (yyvsp[0].strval), scope) == 0){
									tmp1=SymTable_put(table, (yyvsp[0].strval), yylineno, scope, USERFUNC);
							}else {
								tmp1 = SymTable_get(table, (yyvsp[0].strval), scope);
								if(tmp1->type == LIBFUNC){
									yyerror("SHADOWS LIBFUNC");
									//exit(0);
								} else if(tmp1->type == USERFUNC){
									printf("ERROR USERFUNC %s ALREADY DEFINED\n", (yyvsp[0].strval));
								}else{
									printf("ERROR VARIABLE WITH THAT NAME %s IS ALREADY DEFINED\n", (yyvsp[0].strval));
									//exit(0);
								}  
							}
							(yyval.symbolvalue) = tmp1;
							struct expr *fp = newexpr(programfunc_e); 
							fp->sym=tmp1;
							//$$ = newsymbol($2, function_s);
							(yyval.symbolvalue)->iaddress = nextquad(); 
							emit(funcstart_op, fp, NULL, NULL, 0, yylineno);
							push(currscopeoffset()); 
							//printf("\n\n->>>%d\n", currscopeoffset());
							enterscopespace(); 
							resetformalargsoffset(); 
				    	
						}
#line 2525 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 844 "syntax.y" /* yacc.c:1646  */
    {scope++;}
#line 2531 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 844 "syntax.y" /* yacc.c:1646  */
    {
	 					scope--;
						infunctioncounter++;
						enterscopespace(); 
			        	resetfunctionlocalsoffset();
				    }
#line 2542 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 850 "syntax.y" /* yacc.c:1646  */
    {
						
						(yyval.intValue) = currscopeoffset(); 
						exitscopespace();
						infunctioncounter--;
				    }
#line 2553 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 857 "syntax.y" /* yacc.c:1646  */
    {
				     
					exitscopespace();// Exiting function definition space
					(yyvsp[-2].symbolvalue)->totalLocals = (yyvsp[0].intValue); //Store #locals in symbol entry
					int offset = pop(); // pop and get pre scope offset
					//	printf("\n\n->>>%d\n", offset);
					restorecurrscopeoffset(offset); // Restore previous scope offset
					(yyval.symbolvalue) = (yyvsp[-2].symbolvalue); // The function definition returns the symbol
					struct expr *fp = newexpr(programfunc_e); 
					fp->sym=(yyvsp[-2].symbolvalue);
					emit(funcend_op, fp, NULL, NULL,0,yylineno);
					
					}
#line 2571 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 871 "syntax.y" /* yacc.c:1646  */
    {
						   (yyval.exprvalue)=newexpr_constnum((yyvsp[0].realValue));
						}
#line 2579 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 874 "syntax.y" /* yacc.c:1646  */
    { printf("Line %d: String\n", yylineno);
							(yyval.exprvalue)=newexpr_conststring((yyvsp[0].strval));

						}
#line 2588 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 878 "syntax.y" /* yacc.c:1646  */
    {printf("Line %d: Nil\n", yylineno);
							(yyval.exprvalue)=newexpr_constnil();
						}
#line 2596 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 881 "syntax.y" /* yacc.c:1646  */
    {printf("Line %d: True\n", yylineno);
							(yyval.exprvalue)=newexpr_constbool(1);
						}
#line 2604 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 884 "syntax.y" /* yacc.c:1646  */
    {printf("Line %d: False\n", yylineno);
							(yyval.exprvalue)=newexpr_constbool(0);
						}
#line 2612 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 889 "syntax.y" /* yacc.c:1646  */
    {
		
							enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
							//printf("%d\n", scope);
							if(SymTable_contains2(table, yytext, scope) == 0){
								struct SymbolTableEntry *tmp = SymTable_get(table,yytext,0);
								if(tmp !=NULL && tmp->type == LIBFUNC){
									yyerror("ERROR LIBFUNC");
									exit(0);
								}
								SymTable_put(table, yytext, yylineno, scope, enum_hold); 
							}else{
								yyerror ("FORMAL ERROR");
							}	
						}
#line 2633 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 907 "syntax.y" /* yacc.c:1646  */
    {

						enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
                                                        // printf("%d\n", scope);
							if(SymTable_contains2(table, yytext, scope) == 0){
								struct SymbolTableEntry *tmp = SymTable_get(table,yytext,0);
								if(tmp !=NULL && tmp->type == LIBFUNC){
									yyerror("ERROR LIBFUNC");
									exit(0);
								}
								SymTable_put(table, yytext, yylineno, scope, enum_hold); 
							}else{
								yyerror ("FORMAL ERROR");
							}

						}
#line 2655 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 923 "syntax.y" /* yacc.c:1646  */
    {}
#line 2661 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 925 "syntax.y" /* yacc.c:1646  */
    {
	 					struct expr* tmpexpr;
						tmpexpr = newexpr_constbool(1); 
						emit(if_eq_op, tmpexpr,NULL,(yyvsp[-1].exprvalue), nextquad() + 2,yylineno);
						(yyval.intValue) = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno);
					}
#line 2673 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 934 "syntax.y" /* yacc.c:1646  */
    {
						patchlabel((yyvsp[-1].intValue), nextquad());
					}
#line 2681 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 938 "syntax.y" /* yacc.c:1646  */
    {	(yyval.intValue) = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno);
					}
#line 2689 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 942 "syntax.y" /* yacc.c:1646  */
    {

					patchlabel((yyvsp[-3].intValue), (yyvsp[-1].intValue) + 1);
					patchlabel((yyvsp[-1].intValue), nextquad());

					}
#line 2700 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 949 "syntax.y" /* yacc.c:1646  */
    { ++loopcounter; }
#line 2706 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 952 "syntax.y" /* yacc.c:1646  */
    { --loopcounter; }
#line 2712 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 955 "syntax.y" /* yacc.c:1646  */
    { (yyval.stmt_t) = (yyvsp[-1].stmt_t); }
#line 2718 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 958 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.intValue) = nextquad();
						
					}
#line 2727 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 964 "syntax.y" /* yacc.c:1646  */
    {   struct expr* tmpexpr;
						tmpexpr = newexpr_constbool(1);
						emit(if_eq_op, (yyvsp[-1].exprvalue), tmpexpr,NULL, nextquad() + 2,yylineno);
						(yyval.intValue) = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno); 
					}
#line 2738 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 973 "syntax.y" /* yacc.c:1646  */
    {   // printf("Line %d: While Expression\n", yylineno);
						emit(jump_op, NULL, NULL, NULL,(yyvsp[-2].intValue),yylineno);
						patchlabel((yyvsp[-1].intValue), nextquad());
						patchlist((yyvsp[0].stmt_t)->breaklist, nextquad());
						patchlist((yyvsp[0].stmt_t)->contlist, (yyvsp[-2].intValue)); 
					}
#line 2749 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 980 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.intValue) = nextquad();
						emit(jump_op, NULL, NULL, NULL, 0, yylineno);
					}
#line 2758 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 985 "syntax.y" /* yacc.c:1646  */
    {
						(yyval.intValue) = nextquad();
					}
#line 2766 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 990 "syntax.y" /* yacc.c:1646  */
    {       struct expr* tmpexpr;
						tmpexpr=newexpr_constbool(1);
						struct for_s *fors;
						fors=(struct for_s*)malloc(sizeof(struct for_s));
						(yyval.forvalue)=fors;
						(yyval.forvalue)->test = (yyvsp[-2].intValue);
						(yyval.forvalue)->enter = nextquad();
						emit(if_eq_op, (yyvsp[-1].exprvalue), tmpexpr,NULL, 0,yylineno);
					}
#line 2780 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1001 "syntax.y" /* yacc.c:1646  */
    {
						patchlabel((yyvsp[-6].forvalue)->enter, (yyvsp[-2].intValue)+1); //true jump
						patchlabel((yyvsp[-5].intValue), nextquad());//false jump
						patchlabel((yyvsp[-2].intValue), (yyvsp[-6].forvalue)->test);  //loop jump
						patchlabel((yyvsp[0].intValue), (yyvsp[-5].intValue)+1);  //closure jump
						patchlist((yyvsp[-1].stmt_t)->breaklist, nextquad());
						patchlist((yyvsp[-1].stmt_t)->contlist, (yyvsp[-5].intValue)+1);
					}
#line 2793 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1010 "syntax.y" /* yacc.c:1646  */
    {
						
						if(infunctioncounter==0){
								printf("Line %d: ERROR return outside of function\n", yylineno);
						}else{
							printf("Line %d: Return expression\n", yylineno);
							emit(ret_op, NULL, NULL, NULL, 0, yylineno);
							}
				        }
#line 2807 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1019 "syntax.y" /* yacc.c:1646  */
    {
						if(infunctioncounter==0){
							printf("Line %d: ERROR return outside of function\n", yylineno);

							}else{

							printf("Line %d: Return expression\n", yylineno);
							 emit(ret_op,(yyvsp[-1].exprvalue),NULL,NULL,0,yylineno); 
						}
					}
#line 2822 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2826 "syntax.tab.c" /* yacc.c:1646  */
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
#line 1031 "syntax.y" /* yacc.c:1906  */


	int yyerror(char *yaccProvidedMessage){
		puts(yaccProvidedMessage);
		return 1;
	}

   int main(int argc, char* argv[]) {

    int token;
    struct alpha_token_t* head = NULL;
    struct alpha_token_t* temp = NULL;

    if(argc > 1){
        yyin = fopen(argv[1], "r");

        if(yyin == NULL){
            printf("Error with opening text file...\n");
            return -1;
        }
    }else if(argc == 0) {
        printf("File to read from not entered...\n");
        return -1;
    }

	table = SymTable_new();

	SymTable_put(table, "print",0,0, LIBFUNC);
 	SymTable_put(table, "input",0,0, LIBFUNC);
	SymTable_put(table, "objectmemberkeys",0,0, LIBFUNC);
	SymTable_put(table, "objecttotalmembers",0,0, LIBFUNC);
	SymTable_put(table, "objectcopy",0,0, LIBFUNC);
	SymTable_put(table, "totalarguments",0,0, LIBFUNC);
	SymTable_put(table, "argument",0,0, LIBFUNC);
	SymTable_put(table, "typeof",0,0, LIBFUNC);
	SymTable_put(table, "strtonum",0,0, LIBFUNC);
	SymTable_put(table, "sqrt",0,0, LIBFUNC);
	SymTable_put(table, "cos",0,0, LIBFUNC);
	SymTable_put(table, "sin",0,0, LIBFUNC);

    yyparse();
 
	SymTable_Print(table);
	Quad_Print();
	generate_all();
	Instruction_Print();

	print_instruction();

    fclose(yyin);
    
	
	
	return 0;
}

