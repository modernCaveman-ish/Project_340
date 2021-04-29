/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include "hashtbl.h"
#include <string.h>

int yyerror(char *yaccProvidedMessage);
//int yylex(void);

SymbolType enum_hold = 0;

extern FILE* yyin;
extern char *yytext;
extern int yylex();
extern int yylineno;

int scope=0; /*orizoume to arxiko scope */
//HASHTBL *hashtbl; /*dhlwnoume ton hashtable*/

SymTable_T table;
int number=1;


#line 94 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ASSIGNMENT = 270,
    OR = 271,
    AND = 272,
    NOTOP = 273,
    ADD = 274,
    UMINUS = 275,
    SUB = 276,
    MUL = 277,
    DIV = 278,
    MOD = 279,
    EQ = 280,
    DIF = 281,
    INC = 282,
    DEC = 283,
    GR = 284,
    GREQ = 285,
    LESS = 286,
    LESSEQ = 287,
    LEFT_CURLY_BRACE = 288,
    RIGHT_CURLY_BRACE = 289,
    LEFT_BRACKET = 290,
    RIGHT_BRACKET = 291,
    RIGHT_PARENTHESIS = 292,
    LEFT_PARENTHESIS = 293,
    SEMICOLON = 294,
    COMMA = 295,
    COLON = 296,
    NAMESPACE = 297,
    DOT = 298,
    DOUBLE_DOT = 299,
    UNDERSCORE = 300,
    NUMBER = 301,
    LETTER = 302,
    QUOTE = 303,
    STRING = 304,
    COMMENT = 305,
    ID = 306,
    MULTI_LINE_COMMENT = 307,
    ONE_LINE_COMMENT = 308,
    NESTED_COMMENT = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "syntax.y"
  
	int intValue;
        double realValue; 
        char *strval;

#line 208 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   117,   118,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     148,   149,   150,   151,   152,   153,   154,   155,   158,   160,
     161,   162,   163,   164,   167,   191,   215,   239,   242,   243,
     244,   245,   248,   249,   250,   253,   254,   257,   259,   261,
     262,   265,   266,   269,   269,   271,   272,   274,   277,   279,
     279,   284,   309,   309,   284,   310,   322,   322,   310,   324,
     325,   326,   327,   328,   332,   354,   356,   356,   376,   378,
     379,   381,   383,   385,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"if\"", "\"else\"",
  "\"while\"", "\"for\"", "\"function\"", "\"return\"", "\"break\"",
  "\"continue\"", "\"local\"", "\"true\"", "\"false\"", "\"nil\"",
  "ASSIGNMENT", "OR", "AND", "NOTOP", "ADD", "UMINUS", "SUB", "MUL", "DIV",
  "MOD", "EQ", "DIF", "INC", "DEC", "GR", "GREQ", "LESS", "LESSEQ",
  "\"{\"", "\"}\"", "\"LEFT_BRACKET\"", "\"RIGHT_BRACKET\"",
  "\"RIGHT_PARENTHESIS\"", "\"LEFT_PARENTHESIS\"", "\";\"", "\",\"",
  "\":\"", "\"::\"", "\".\"", "\"..\"", "\"_\"", "NUMBER", "\"letter\"",
  "\"quote\"", "\"string\"", "\"comment\"", "ID", "\"multiple comm\"",
  "\"single line comm\"", "\"nested comm\"", "$accept", "program",
  "statements", "stmt", "expr", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elists",
  "elist", "objectdef", "indexeds", "indexed", "indexedelem", "block",
  "$@1", "funcdef", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "const",
  "idlists", "idlist", "$@8", "ifstmt", "whilestmt", "forstmt",
  "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -141,     1,   153,  -141,   -33,   -21,    -1,   -11,   194,     5,
      15,     0,  -141,  -141,  -141,   276,   276,    -8,    -8,  -141,
     235,    11,  -141,     8,  -141,  -141,  -141,  -141,   348,  -141,
    -141,  -141,   182,  -141,    12,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,   276,   276,   276,  -141,    18,  -141,   367,
    -141,  -141,  -141,  -141,  -141,    54,   -28,    12,   -28,  -141,
     276,   328,    27,    28,  -141,   405,    42,  -141,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,  -141,   276,  -141,  -141,   276,   276,    14,    30,  -141,
    -141,  -141,   276,   276,    40,   422,   439,    57,    59,  -141,
    -141,    61,   100,   307,   276,  -141,  -141,  -141,    75,  -141,
      78,   527,    63,     4,     4,  -141,  -141,  -141,   541,   541,
     277,   277,   277,   277,   511,   456,    62,  -141,    79,   474,
      83,  -141,   153,   153,   276,  -141,    71,    78,  -141,   276,
     328,    90,   276,  -141,  -141,   276,  -141,  -141,   120,  -141,
     386,    71,  -141,    88,   492,  -141,  -141,    89,    92,   153,
     276,    99,  -141,  -141,  -141,  -141,  -141,  -141,   103,  -141,
     101,   110,   153,   110,    93,  -141,  -141,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,    75,     0,     0,
       0,     0,    82,    83,    81,     0,     0,     0,     0,    69,
      62,     0,    14,     0,    79,    80,    44,     3,     0,    29,
      15,    37,    39,    47,    40,    41,    12,    13,    43,     6,
       7,     8,     9,     0,     0,    62,    71,     0,    93,     0,
      10,    11,    45,    32,    31,     0,    33,     0,    35,     4,
       0,    60,     0,     0,    66,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,    34,    36,     0,    62,     0,     0,    53,
      55,    56,     0,    62,     0,     0,     0,     0,     0,    76,
      94,     0,     0,     0,     0,    61,    63,    64,    67,    30,
      42,    24,    23,    16,    17,    18,    19,    20,    21,    22,
      28,    25,    26,    27,    38,     0,     0,    48,     0,     0,
       0,    50,     0,     0,     0,    72,    88,     0,    70,     0,
      60,     0,    62,    49,    57,    62,    51,    52,    89,    91,
       0,    88,    86,     0,     0,    59,    65,     0,     0,     0,
      62,     0,    85,    77,    68,    54,    58,    90,     0,    73,
      87,     0,     0,     0,     0,    78,    92,    74,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,    86,  -124,    -2,  -141,  -141,  -141,    -6,  -141,
       3,  -141,  -141,  -141,     7,   -41,  -141,  -141,  -141,     9,
    -140,  -141,   -19,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,    -3,  -141,  -141,  -141,  -141,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    61,    29,    30,    31,    32,    33,
      34,    89,    90,    91,   105,    62,    35,   108,    63,    64,
      36,    59,    37,    98,   151,   173,    47,   136,   171,    38,
     170,   153,   162,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,     3,    66,    11,    97,    43,    49,    85,   148,   149,
      86,    56,    58,    53,    54,    87,    88,    44,     7,    65,
      57,    57,    11,    12,    13,    14,    72,    73,    74,    15,
      55,   175,    16,   177,    23,   167,   101,    45,    17,    18,
      46,    95,    96,    26,    50,   126,    20,    92,   176,    21,
      93,    52,   130,    23,    51,    94,    99,    24,   103,    67,
      25,     7,    26,   106,   107,   127,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   110,
     124,   128,    70,   125,    71,    72,    73,    74,    75,    76,
     129,   131,    77,    78,    79,    80,   134,   135,   137,   144,
      28,   157,   140,     4,   158,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   141,   142,   145,    15,   168,
     147,    16,   152,    60,   159,   163,   165,    17,    18,   166,
      28,    28,   150,    19,   138,    20,   169,   154,    21,    22,
     172,   174,    23,    19,   178,   102,    24,   155,   161,    25,
     156,    26,     0,     0,     0,     0,     4,    28,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      28,    15,     0,     0,    16,     0,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,     0,     0,    23,     0,    82,     0,    24,
       0,     0,    25,     0,    26,    11,    12,    13,    14,    83,
      84,     0,    15,     0,     0,    16,     0,    85,     0,     0,
      86,    17,    18,     0,     0,    87,    88,     0,     0,    20,
       0,     0,    21,    48,     0,     0,    23,     0,     0,     0,
      24,     0,     0,    25,     0,    26,    11,    12,    13,    14,
       0,     0,     0,    15,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,    60,     0,
      20,     0,     0,    21,     0,     0,     0,    23,     0,     0,
       0,    24,     0,     0,    25,     0,    26,    11,    12,    13,
      14,     0,     0,     0,    15,     0,    70,    16,    71,    72,
      73,    74,     0,    17,    18,     0,    -1,    -1,    -1,    -1,
       0,    20,     0,     0,    21,     0,     0,     0,    23,     0,
       0,     0,    24,    68,    69,    25,    70,    26,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    79,    80,
       0,     0,     0,     0,    68,    69,     0,    70,   139,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,    79,
      80,     0,     0,     0,    68,    69,     0,    70,   104,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,    79,
      80,     0,     0,    68,    69,     0,    70,    81,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    79,    80,
       0,     0,    68,    69,     0,    70,   100,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,     0,
       0,    68,    69,     0,    70,   160,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,    79,    80,    68,    69,
       0,    70,   109,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    68,    69,     0,    70,   132,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
      79,    80,    68,    69,     0,    70,   133,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,     0,
      68,    69,   143,    70,     0,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,    79,    80,     0,    68,    69,
     146,    70,     0,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,     0,   164,    68,    69,     0,
      70,     0,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,    69,     0,    70,     0,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    79,    80,
      70,     0,    71,    72,    73,    74,    -1,    -1,     0,     0,
      77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
       2,     0,    21,    11,    45,    38,     8,    35,   132,   133,
      38,    17,    18,    15,    16,    43,    44,    38,     7,    21,
      17,    18,    11,    12,    13,    14,    22,    23,    24,    18,
      38,   171,    21,   173,    42,   159,    55,    38,    27,    28,
      51,    43,    44,    51,    39,    86,    35,    35,   172,    38,
      38,    51,    93,    42,    39,    43,    38,    46,    60,    51,
      49,     7,    51,    36,    36,    51,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    37,
      82,    51,    19,    85,    21,    22,    23,    24,    25,    26,
      92,    51,    29,    30,    31,    32,    39,    38,    37,    37,
     102,   142,   104,     3,   145,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    40,    38,    38,    18,   160,
      37,    21,    51,    33,     4,    37,    37,    27,    28,    37,
     132,   133,   134,    33,    34,    35,    37,   139,    38,    39,
      37,    40,    42,    33,    51,    59,    46,   140,   151,    49,
     141,    51,    -1,    -1,    -1,    -1,     3,   159,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
     172,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    42,    -1,    15,    -1,    46,
      -1,    -1,    49,    -1,    51,    11,    12,    13,    14,    27,
      28,    -1,    18,    -1,    -1,    21,    -1,    35,    -1,    -1,
      38,    27,    28,    -1,    -1,    43,    44,    -1,    -1,    35,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    -1,    51,    11,    12,    13,    14,
      -1,    -1,    -1,    18,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    -1,    51,    11,    12,    13,
      14,    -1,    -1,    -1,    18,    -1,    19,    21,    21,    22,
      23,    24,    -1,    27,    28,    -1,    29,    30,    31,    32,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    16,    17,    49,    19,    51,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    16,    17,    -1,    19,    41,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    16,    17,    -1,    19,    40,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    16,    17,    -1,    19,    39,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    16,    17,    -1,    19,    39,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    16,    17,    -1,    19,    39,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    16,    17,
      -1,    19,    37,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    16,    17,    -1,    19,    37,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    16,    17,    -1,    19,    37,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    -1,
      16,    17,    36,    19,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    29,    30,    31,    32,    -1,    16,    17,
      36,    19,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    -1,    34,    16,    17,    -1,
      19,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    17,    -1,    19,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      19,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    56,    57,     0,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    18,    21,    27,    28,    33,
      35,    38,    39,    42,    46,    49,    51,    58,    59,    60,
      61,    62,    63,    64,    65,    71,    75,    77,    84,    88,
      89,    90,    91,    38,    38,    38,    51,    81,    39,    59,
      39,    39,    51,    59,    59,    38,    63,    65,    63,    76,
      33,    59,    70,    73,    74,    59,    77,    51,    16,    17,
      19,    21,    22,    23,    24,    25,    26,    29,    30,    31,
      32,    39,    15,    27,    28,    35,    38,    43,    44,    66,
      67,    68,    35,    38,    43,    59,    59,    70,    78,    38,
      39,    77,    57,    59,    40,    69,    36,    36,    72,    37,
      37,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    70,    51,    51,    59,
      70,    51,    37,    37,    39,    38,    82,    37,    34,    41,
      59,    40,    38,    36,    37,    38,    36,    37,    58,    58,
      59,    79,    51,    86,    59,    69,    74,    70,    70,     4,
      39,    86,    87,    37,    34,    37,    37,    58,    70,    37,
      85,    83,    37,    80,    40,    75,    58,    75,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    74,    76,
      75,    78,    79,    80,    77,    81,    82,    83,    77,    84,
      84,    84,    84,    84,    85,    85,    87,    86,    86,    88,
      88,    89,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     5,     3,
       0,     2,     0,     3,     3,     3,     0,     2,     5,     0,
       4,     0,     0,     0,     9,     0,     0,     0,     8,     1,
       1,     1,     1,     1,     3,     0,     0,     3,     0,     5,
       7,     5,     9,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 113 "syntax.y"
                                                   {printf("Start Program\n");}
#line 1592 "syntax.tab.c"
    break;

  case 3:
#line 117 "syntax.y"
                                                {}
#line 1598 "syntax.tab.c"
    break;

  case 4:
#line 118 "syntax.y"
                                                  {}
#line 1604 "syntax.tab.c"
    break;

  case 5:
#line 120 "syntax.y"
                                                       {printf("EXPRESSION SEMICOLON ");}
#line 1610 "syntax.tab.c"
    break;

  case 6:
#line 121 "syntax.y"
                                                         {printf("Line %d: if Statement\n", yylineno);}
#line 1616 "syntax.tab.c"
    break;

  case 7:
#line 122 "syntax.y"
                                                            {printf("Line %d: while Statement\n", yylineno);}
#line 1622 "syntax.tab.c"
    break;

  case 8:
#line 123 "syntax.y"
                                                            {printf("Line %d: for Statement\n", yylineno);}
#line 1628 "syntax.tab.c"
    break;

  case 9:
#line 124 "syntax.y"
                                                              {printf("Line %d: return statement\n", yylineno);}
#line 1634 "syntax.tab.c"
    break;

  case 10:
#line 125 "syntax.y"
                                                                   {printf("Line %d: break statement\n", yylineno);}
#line 1640 "syntax.tab.c"
    break;

  case 11:
#line 126 "syntax.y"
                                                                     {printf("Line %d:continue statement\n", yylineno);}
#line 1646 "syntax.tab.c"
    break;

  case 14:
#line 129 "syntax.y"
                                                            {printf("Line %d: Semicolon\n", yylineno);}
#line 1652 "syntax.tab.c"
    break;

  case 15:
#line 132 "syntax.y"
                                           {printf("Line %d: Assignment expression: ", yylineno);}
#line 1658 "syntax.tab.c"
    break;

  case 16:
#line 133 "syntax.y"
                                                                {printf("Line %d: Add expression: ", yylineno);}
#line 1664 "syntax.tab.c"
    break;

  case 17:
#line 134 "syntax.y"
                                                                {printf("Line %d: subtract expression: ", yylineno);}
#line 1670 "syntax.tab.c"
    break;

  case 18:
#line 135 "syntax.y"
                                                                {printf("Line %d: multiply expression: ", yylineno);}
#line 1676 "syntax.tab.c"
    break;

  case 19:
#line 136 "syntax.y"
                                                                {printf("Line %d: Division expression: ", yylineno);}
#line 1682 "syntax.tab.c"
    break;

  case 20:
#line 137 "syntax.y"
                                                                {printf("Line %d: Modulo expression: ", yylineno);}
#line 1688 "syntax.tab.c"
    break;

  case 21:
#line 138 "syntax.y"
                                                              {printf("Line %d: Equal expression: ", yylineno);}
#line 1694 "syntax.tab.c"
    break;

  case 22:
#line 139 "syntax.y"
                                                               {printf("Line %d: Different than expression: ", yylineno);}
#line 1700 "syntax.tab.c"
    break;

  case 23:
#line 140 "syntax.y"
                                                                {printf("Line %d: And expression: ", yylineno);}
#line 1706 "syntax.tab.c"
    break;

  case 24:
#line 141 "syntax.y"
                                                              {printf("Line %d: OR expression: ", yylineno);}
#line 1712 "syntax.tab.c"
    break;

  case 25:
#line 142 "syntax.y"
                                                                {printf("Line %d: Greater than expression: ", yylineno);}
#line 1718 "syntax.tab.c"
    break;

  case 26:
#line 143 "syntax.y"
                                                                {printf("Line %d: Less than expression: ", yylineno);}
#line 1724 "syntax.tab.c"
    break;

  case 27:
#line 144 "syntax.y"
                                                                  {printf("Line %d: Less or Equal expression: ", yylineno);}
#line 1730 "syntax.tab.c"
    break;

  case 28:
#line 145 "syntax.y"
                                                                {printf("Line %d: Greater expression: ", yylineno);}
#line 1736 "syntax.tab.c"
    break;

  case 32:
#line 150 "syntax.y"
                                                                {printf("Line %d: Not Expression\n", yylineno);}
#line 1742 "syntax.tab.c"
    break;

  case 33:
#line 151 "syntax.y"
                                                                {printf("Line %d: ++ lvalue\n", yylineno);}
#line 1748 "syntax.tab.c"
    break;

  case 34:
#line 152 "syntax.y"
                                                                {printf("Line %d: lvalue++\n", yylineno);}
#line 1754 "syntax.tab.c"
    break;

  case 35:
#line 153 "syntax.y"
                                                                {printf("Line %d: --lvalue\n", yylineno);}
#line 1760 "syntax.tab.c"
    break;

  case 36:
#line 154 "syntax.y"
                                                                {printf("Line %d: lvalue--\n", yylineno);}
#line 1766 "syntax.tab.c"
    break;

  case 44:
#line 167 "syntax.y"
                                   { /*KSANA DES TO DEN BRISKEI EAN YPARXEI HDH TO KANEI KATAXWRHSH ETSI KI ALLIWS*/
							int dummy_scope = scope;
							int enum_scope;
							int flag = 0; /*0 gia false, 1 gia true*/

							printf("\nMphke ID dummy_scope = %d eimaste gia yytext:%s se line %d\n", dummy_scope, yytext, yylineno);
							
							/*psakse ean yparxei genika ston table*/
							for(dummy_scope; dummy_scope >= 0; dummy_scope--){
								if(SymTable_contains2(table, yytext, dummy_scope)){
									printf("ID %s already exists in table\n", yytext);
									flag = 1;
									break;
								}
							}
							
							if(flag == 0){
								if(scope == 0) enum_scope = 0;
								else if(scope > 0) enum_scope = 1;

								SymTable_put(table, yytext, yylineno, scope, enum_scope);
							}
							
						}
#line 1795 "syntax.tab.c"
    break;

  case 45:
#line 191 "syntax.y"
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
								tmp = SymTable_get(table,yytext,scope);

									if(tmp == NULL){
										if(scope==0){ type = GLOBAL; } else { type = LOCAL2; }

										SymTable_put(table, yytext, yylineno, scope, type );
									}
									
								}
#line 1822 "syntax.tab.c"
    break;

  case 46:
#line 215 "syntax.y"
                                                                { 				/*GLOBAL*/
							struct SymbolTableEntry *temp;
							int contains = 0; /*0 = false || 1 = true */

							/*Kane eisagwgh sth lista afou prwta elegkseis ean einai hdh mesa*/
							contains = SymTable_contains2(table, yytext, 0);
							
							if(contains == 1){
								temp = SymTable_get(table, yytext, 0);
								
								/*
								printf("Printing what found for NAMESPACE: ");
								SymTableEntry_print(temp);
								*/
								
								printf("Found\n");
							} else if(contains == 0) {
								printf("ERROR %s NOT FOUND\n", yytext);
								//yyerror("ERRORr");
								//exit(0);
							}
							
						}
#line 1850 "syntax.tab.c"
    break;

  case 48:
#line 242 "syntax.y"
                                                        { printf("Line %d: lvalue.ID\n", yylineno); }
#line 1856 "syntax.tab.c"
    break;

  case 49:
#line 243 "syntax.y"
                                                                                 {printf("Line %d: lvalue [Expression]\n\n", yylineno);}
#line 1862 "syntax.tab.c"
    break;

  case 50:
#line 244 "syntax.y"
                                                               { printf("Line %d: Call.ID\n", yylineno); }
#line 1868 "syntax.tab.c"
    break;

  case 51:
#line 245 "syntax.y"
                                                                                       { printf("Line %d: Call [Expression]\n", yylineno);}
#line 1874 "syntax.tab.c"
    break;

  case 60:
#line 262 "syntax.y"
                                                         {}
#line 1880 "syntax.tab.c"
    break;

  case 62:
#line 266 "syntax.y"
                                                         {}
#line 1886 "syntax.tab.c"
    break;

  case 69:
#line 279 "syntax.y"
                                                         {++scope;}
#line 1892 "syntax.tab.c"
    break;

  case 70:
#line 279 "syntax.y"
                                                                                                 {
								SymTable_hide(table, scope--);
								//printf("Line %d: Block\n", yylineno);
                                                                }
#line 1901 "syntax.tab.c"
    break;

  case 71:
#line 284 "syntax.y"
                                                    { 
						struct SymbolTableEntry *tmp1;
						/*
						tmp1 = SymTable_get(table,yytext,0);
							if(tmp1 !=NULL && tmp1->type == LIBFUNC){
								yyerror("ERROR LIBFUNC");
								exit(0);
							}
						*/
							
							if(SymTable_contains2(table, yytext, scope) == 0){
									SymTable_put(table, yytext, yylineno, scope, USERFUNC);
							}else {
										tmp1 = SymTable_get(table, yytext, scope);
										if(tmp1->type == LIBFUNC){
											yyerror("SHADOWS LIBFUNC");
											//exit(0);
										} else if(tmp1->type == USERFUNC){
											printf("ERROR USERFUNC %s ALREADY DEFINED\n", yytext);
										}else{
											printf("ERROR VARIABLE WITH THAT NAME %s IS ALREADY DEFINED\n", yytext);
											//exit(0);
										}
							}

								}
#line 1932 "syntax.tab.c"
    break;

  case 72:
#line 309 "syntax.y"
                                                                                   {scope++;}
#line 1938 "syntax.tab.c"
    break;

  case 73:
#line 309 "syntax.y"
                                                                                                                        {scope--;}
#line 1944 "syntax.tab.c"
    break;

  case 75:
#line 310 "syntax.y"
                                                           {
						 
						    printf("Line %d: no name function at scope %d \n", yylineno, scope);
						    char tempname[200];
							struct SymbolTableEntry *tmp1;
							sprintf(tempname,"_f%u",number);

						   if(tmp1!=NULL){
							SymTable_put(table, tempname, yylineno, scope, USERFUNC);
							number++;
						   }

						}
#line 1962 "syntax.tab.c"
    break;

  case 76:
#line 322 "syntax.y"
                                                                   {scope++;}
#line 1968 "syntax.tab.c"
    break;

  case 77:
#line 322 "syntax.y"
                                                                                                       {scope--;}
#line 1974 "syntax.tab.c"
    break;

  case 80:
#line 325 "syntax.y"
                                                         { printf("Line %d: String\n", yylineno);}
#line 1980 "syntax.tab.c"
    break;

  case 81:
#line 326 "syntax.y"
                                                      {printf("Line %d: Nil\n", yylineno);}
#line 1986 "syntax.tab.c"
    break;

  case 82:
#line 327 "syntax.y"
                                                       {printf("Line %d: True\n", yylineno);}
#line 1992 "syntax.tab.c"
    break;

  case 83:
#line 328 "syntax.y"
                                                        {printf("Line %d: False\n", yylineno);}
#line 1998 "syntax.tab.c"
    break;

  case 84:
#line 332 "syntax.y"
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
#line 2025 "syntax.tab.c"
    break;

  case 86:
#line 356 "syntax.y"
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
#line 2051 "syntax.tab.c"
    break;

  case 88:
#line 376 "syntax.y"
                                                                   {}
#line 2057 "syntax.tab.c"
    break;

  case 89:
#line 378 "syntax.y"
                                                                                        {printf("Line %d: if statement\n", yylineno);}
#line 2063 "syntax.tab.c"
    break;

  case 90:
#line 379 "syntax.y"
                                                                                                            {printf("Line %d: Else statement\n", yylineno);}
#line 2069 "syntax.tab.c"
    break;

  case 91:
#line 381 "syntax.y"
                                                                                           {printf("Line %d: While statement\n", yylineno);}
#line 2075 "syntax.tab.c"
    break;

  case 92:
#line 383 "syntax.y"
                                                                                                                     {printf("Line %d: for statement \n", yylineno);}
#line 2081 "syntax.tab.c"
    break;


#line 2085 "syntax.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 390 "syntax.y"


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

    fclose(yyin);
    return 0;
}