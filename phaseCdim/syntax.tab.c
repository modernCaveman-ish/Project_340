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
#include "quads.h"
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

int loopCounter = 0;


#line 95 "syntax.tab.c"

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
    NUMBER = 258,
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    FUNCTION = 263,
    RETURN = 264,
    BREAK = 265,
    CONTINUE = 266,
    LOCAL = 267,
    TRUE = 268,
    FALSE = 269,
    NIL = 270,
    ASSIGNMENT = 271,
    OR = 272,
    AND = 273,
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
    LETTER = 302,
    QUOTE = 303,
    STRING = 304,
    COMMENT = 305,
    ID = 306,
    MULTIPLE_COMMENT = 307,
    NESTED_COMMENT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "syntax.y"
  

	struct expr* exprvalue;
	struct call* callvalue;
	struct symbol* symbolvalue;
	int intValue;
    double realValue; 
	char *strval;
 

#line 213 "syntax.tab.c"

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
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   133,   134,   136,   149,   152,   155,   158,
     161,   167,   173,   176,   179,   184,   188,   201,   207,   212,
     218,   224,   231,   238,   245,   252,   259,   266,   273,   280,
     285,   286,   294,   300,   316,   333,   348,   364,   368,   389,
     390,   391,   392,   393,   396,   421,   445,   468,   471,   472,
     473,   474,   477,   478,   479,   482,   483,   486,   488,   490,
     491,   494,   495,   498,   498,   500,   501,   503,   506,   508,
     508,   559,   584,   584,   559,   585,   615,   615,   585,   617,
     618,   619,   620,   621,   625,   660,   662,   662,   682,   684,
     685,   699,   707,   709,   712
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "NUMBER", "\"if\"",
  "\"else\"", "\"while\"", "\"for\"", "\"function\"", "\"return\"",
  "\"break\"", "\"continue\"", "\"local\"", "\"true\"", "\"false\"",
  "\"nil\"", "ASSIGNMENT", "OR", "AND", "NOTOP", "ADD", "UMINUS", "SUB",
  "MUL", "DIV", "MOD", "EQ", "DIF", "INC", "DEC", "GR", "GREQ", "LESS",
  "LESSEQ", "\"{\"", "\"}\"", "\"LEFT_BRACKET\"", "\"RIGHT_BRACKET\"",
  "\"RIGHT_PARENTHESIS\"", "\"LEFT_PARENTHESIS\"", "\";\"", "\",\"",
  "\":\"", "\"::\"", "\".\"", "\"..\"", "\"_\"", "\"letter\"", "\"quote\"",
  "\"string\"", "\"comment\"", "ID", "\"multiple comment\"",
  "\"nested comment\"", "$accept", "program", "statements", "stmt", "expr",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elists", "elist", "objectdef",
  "indexeds", "indexed", "indexedelem", "block", "$@1", "funcdef", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "const", "idlists", "idlist", "$@8",
  "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,     2,   181,  -163,  -163,   -23,   -22,   -20,   -16,    10,
     -10,    -7,   -14,  -163,  -163,  -163,   281,   281,    -3,    -3,
    -163,   222,   240,  -163,    -8,  -163,  -163,  -163,   352,  -163,
    -163,  -163,    69,  -163,   -18,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,   281,   281,   281,  -163,     8,  -163,   371,
    -163,  -163,  -163,  -163,  -163,    43,   -33,   -18,   -33,  -163,
     281,   332,    20,    23,  -163,   409,    26,  -163,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,  -163,   281,  -163,  -163,   281,   281,    14,    28,  -163,
    -163,  -163,   281,   281,    30,   426,   443,    42,    45,  -163,
    -163,    48,   132,   311,   281,  -163,  -163,  -163,    46,  -163,
      49,   531,   545,    31,    31,  -163,  -163,  -163,   559,   559,
     282,   282,   282,   282,   515,   460,    51,  -163,    52,   478,
      54,  -163,   181,  -163,   281,  -163,    55,    49,  -163,   281,
     332,    59,   281,  -163,  -163,   281,  -163,  -163,    89,   390,
      55,  -163,    57,   496,  -163,  -163,    58,    61,   181,   281,
      65,  -163,  -163,  -163,  -163,  -163,  -163,    71,  -163,    66,
      76,   181,    76,    60,  -163,  -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    79,     0,     0,     0,    75,     0,
       0,     0,     0,    82,    83,    81,     0,     0,     0,     0,
      69,    62,     0,    14,     0,    80,    44,     3,     0,    29,
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
       0,    50,     0,    91,     0,    72,    88,     0,    70,     0,
      60,     0,    62,    49,    57,    62,    51,    52,    89,     0,
      88,    86,     0,     0,    59,    65,     0,     0,     0,    62,
       0,    85,    77,    68,    54,    58,    90,     0,    73,    87,
       0,     0,     0,     0,    78,    92,    74,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,    53,  -127,    -2,  -163,  -163,  -163,     9,  -163,
      44,  -163,  -163,  -163,   -25,   -41,  -163,  -163,  -163,   -24,
    -162,  -163,   -21,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,   -34,  -163,  -163,  -163,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    61,    29,    30,    31,    32,    33,
      34,    89,    90,    91,   105,    62,    35,   108,    63,    64,
      36,    59,    37,    98,   150,   172,    47,   136,   170,    38,
     169,   152,   161,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    66,     3,    85,    97,   148,    86,    49,   174,    12,
     176,    87,    88,     4,    53,    54,    43,    44,    92,    45,
      65,    93,    12,    13,    14,    15,    94,    56,    58,    16,
      50,   166,    17,    51,   101,    46,    55,    52,    18,    19,
      24,    95,    96,    67,   175,   126,    21,    99,    26,    22,
      48,     8,   130,    24,    72,    73,    74,   106,   103,    25,
     107,    26,    57,    57,   110,   127,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   128,
     124,   131,   134,   125,   135,    82,   137,   141,   142,   144,
     129,   145,   147,    60,   158,   162,   164,    83,    84,   165,
      28,   156,   140,   168,   157,    85,   151,   173,    86,   171,
      20,   177,   102,    87,    88,   154,   160,   155,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,   149,     0,     0,     4,     5,   153,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     0,    17,     0,    28,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,   138,    21,    28,
       0,    22,    23,     0,     0,    24,     0,     0,     0,     0,
       0,    25,     0,    26,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,     0,     0,    17,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,    20,     0,    21,     0,     0,
      22,    23,     0,     0,    24,     4,     0,     0,     0,     0,
      25,     0,    26,     0,    12,    13,    14,    15,     0,     0,
       0,    16,     0,     4,    17,     0,     0,     0,     8,     0,
      18,    19,    12,    13,    14,    15,    60,     0,    21,    16,
       0,    22,    17,     0,     0,    24,     0,     0,    18,    19,
       0,    25,     0,    26,     0,     0,    21,     0,     0,    22,
       0,     0,     0,    24,     4,     0,     0,     0,     0,    25,
       0,    26,     0,    12,    13,    14,    15,     0,     0,     0,
      16,     0,    70,    17,    71,    72,    73,    74,     0,    18,
      19,     0,    -1,    -1,    -1,    -1,     0,    21,     0,     0,
      22,     0,     0,     0,    24,     0,     0,     0,    68,    69,
      25,    70,    26,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,     0,     0,     0,     0,    68,
      69,     0,    70,   139,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,    79,    80,     0,     0,     0,    68,
      69,     0,    70,   104,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,    79,    80,     0,     0,    68,    69,
       0,    70,    81,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,     0,     0,    68,    69,     0,
      70,   100,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,     0,     0,    68,    69,     0,    70,
     159,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,    79,    80,    68,    69,     0,    70,   109,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    79,    80,
      68,    69,     0,    70,   132,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,    79,    80,    68,    69,     0,
      70,   133,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,     0,    68,    69,   143,    70,     0,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
      79,    80,     0,    68,    69,   146,    70,     0,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    79,    80,
       0,   163,    68,    69,     0,    70,     0,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,    69,
       0,    70,     0,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    70,     0,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,    70,
       0,    71,    72,    73,    74,    -1,    -1,     0,     0,    77,
      78,    79,    80
};

static const yytype_int16 yycheck[] =
{
       2,    22,     0,    36,    45,   132,    39,     9,   170,    12,
     172,    44,    45,     3,    16,    17,    39,    39,    36,    39,
      22,    39,    12,    13,    14,    15,    44,    18,    19,    19,
      40,   158,    22,    40,    55,    51,    39,    51,    28,    29,
      43,    43,    44,    51,   171,    86,    36,    39,    51,    39,
      40,     8,    93,    43,    23,    24,    25,    37,    60,    49,
      37,    51,    18,    19,    38,    51,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    51,
      82,    51,    40,    85,    39,    16,    38,    41,    39,    38,
      92,    39,    38,    34,     5,    38,    38,    28,    29,    38,
     102,   142,   104,    38,   145,    36,    51,    41,    39,    38,
      34,    51,    59,    44,    45,   140,   150,   141,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,    -1,   134,    -1,    -1,     3,     4,   139,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,   158,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,   171,
      -1,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,
      39,    40,    -1,    -1,    43,     3,    -1,    -1,    -1,    -1,
      49,    -1,    51,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,     3,    22,    -1,    -1,    -1,     8,    -1,
      28,    29,    12,    13,    14,    15,    34,    -1,    36,    19,
      -1,    39,    22,    -1,    -1,    43,    -1,    -1,    28,    29,
      -1,    49,    -1,    51,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    -1,    43,     3,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    20,    22,    22,    23,    24,    25,    -1,    28,
      29,    -1,    30,    31,    32,    33,    -1,    36,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    17,    18,
      49,    20,    51,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    42,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    17,
      18,    -1,    20,    41,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    17,    18,
      -1,    20,    40,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    17,    18,    -1,
      20,    40,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    17,    18,    -1,    20,
      40,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    17,    18,    -1,    20,    38,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      17,    18,    -1,    20,    38,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    17,    18,    -1,
      20,    38,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    17,    18,    37,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    17,    18,    37,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    17,    18,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    18,
      -1,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    19,    22,    28,    29,
      34,    36,    39,    40,    43,    49,    51,    57,    58,    59,
      60,    61,    62,    63,    64,    70,    74,    76,    83,    87,
      88,    89,    90,    39,    39,    39,    51,    80,    40,    58,
      40,    40,    51,    58,    58,    39,    62,    64,    62,    75,
      34,    58,    69,    72,    73,    58,    76,    51,    17,    18,
      20,    22,    23,    24,    25,    26,    27,    30,    31,    32,
      33,    40,    16,    28,    29,    36,    39,    44,    45,    65,
      66,    67,    36,    39,    44,    58,    58,    69,    77,    39,
      40,    76,    56,    58,    41,    68,    37,    37,    71,    38,
      38,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    69,    51,    51,    58,
      69,    51,    38,    38,    40,    39,    81,    38,    35,    42,
      58,    41,    39,    37,    38,    39,    37,    38,    57,    58,
      78,    51,    85,    58,    68,    73,    69,    69,     5,    40,
      85,    86,    38,    35,    38,    38,    57,    69,    38,    84,
      82,    38,    79,    41,    74,    57,    74,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    73,    75,
      74,    77,    78,    79,    76,    80,    81,    82,    76,    83,
      83,    83,    83,    83,    84,    84,    86,    85,    85,    87,
      87,    88,    89,    90,    90
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
       7,     4,     9,     2,     3
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
#line 130 "syntax.y"
                                                   {printf("Start Program\n");}
#line 1600 "syntax.tab.c"
    break;

  case 3:
#line 133 "syntax.y"
                                                {}
#line 1606 "syntax.tab.c"
    break;

  case 4:
#line 134 "syntax.y"
                                                  {}
#line 1612 "syntax.tab.c"
    break;

  case 5:
#line 136 "syntax.y"
                                                       { 
						
						printf("\nMphke sto stmt\n");
						
						(yyval.strval);
						/*
						if (){

						}
						*/
						
						printf("EXPRESSION SEMICOLON ");
						}
#line 1630 "syntax.tab.c"
    break;

  case 6:
#line 149 "syntax.y"
                                                        {
							printf("Line %d: if Statement\n", yylineno);
						}
#line 1638 "syntax.tab.c"
    break;

  case 7:
#line 152 "syntax.y"
                                                           {
							printf("Line %d: while Statement\n", yylineno);
						}
#line 1646 "syntax.tab.c"
    break;

  case 8:
#line 155 "syntax.y"
                                                         {
							printf("Line %d: for Statement\n", yylineno);
						}
#line 1654 "syntax.tab.c"
    break;

  case 9:
#line 158 "syntax.y"
                                                              {
							printf("Line %d: return statement\n", yylineno);
						}
#line 1662 "syntax.tab.c"
    break;

  case 10:
#line 161 "syntax.y"
                                                                  {
							printf("Line %d: break statement\n", yylineno);
							//make_stmt(&$break); 
							//$break.breaklist = newlist(nextquad()); 
							//emit(jump_op,NULL,NULL,0);
						}
#line 1673 "syntax.tab.c"
    break;

  case 11:
#line 167 "syntax.y"
                                                                     {
							printf("Line %d:continue statement\n", yylineno);
							//make_stmt(& $continue);
							//$continue.contlist = newlist(nextquad());
							// emit(jump_op,NULL,NULL,0); 
						}
#line 1684 "syntax.tab.c"
    break;

  case 12:
#line 173 "syntax.y"
                                                        {
							printf("Line %d: block \n", yylineno);
						}
#line 1692 "syntax.tab.c"
    break;

  case 13:
#line 176 "syntax.y"
                                                          {
							printf("Line %d: function definition Statement\n", yylineno);
						}
#line 1700 "syntax.tab.c"
    break;

  case 14:
#line 179 "syntax.y"
                                                            {
							printf("Line %d: Semicolon\n", yylineno);
						}
#line 1708 "syntax.tab.c"
    break;

  case 15:
#line 184 "syntax.y"
                                           {
					    printf("Line %d: Assignment expression: ", yylineno);
					   	(yyval.exprvalue)=(yyvsp[0].exprvalue);
					   }
#line 1717 "syntax.tab.c"
    break;

  case 16:
#line 188 "syntax.y"
                                                                {
							
							//edw panw kati me $1 kai $2?

							printf("Mphke expr ADD expr\n");
						  	
							(yyval.exprvalue) = newexpr(arithexpr_e);
							printf("expr ADD expr eftiakse to $$->%d\n", (yyval.exprvalue)->type);
							(yyval.exprvalue)->sym = newtemp();
							printf("expr ADD expr newtemp->%s\n", (yyval.exprvalue)->sym->name);
						  	emit(add_op, (yyvsp[-2].exprvalue), 0, (yyval.exprvalue),0,yylineno); //opcode,arg1,arg2,result,label,line
						  	//printf("enum expr $$: %d\n", $$->type); 
						}
#line 1735 "syntax.tab.c"
    break;

  case 17:
#line 201 "syntax.y"
                                                                {
					      //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(sub_op, $1, $2, $$,0,yylineno);

                                                }
#line 1746 "syntax.tab.c"
    break;

  case 18:
#line 207 "syntax.y"
                                                               {
						  //	$$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(mul_op, $1, $2, $$,0,yylineno);
						}
#line 1756 "syntax.tab.c"
    break;

  case 19:
#line 212 "syntax.y"
                                                               {
					          //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(div_op, $1, $2, $$,0,yylineno);

						}
#line 1767 "syntax.tab.c"
    break;

  case 20:
#line 218 "syntax.y"
                                                               {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(mod_op, $1, $2, $$,0,yylineno);
						}
#line 1777 "syntax.tab.c"
    break;

  case 21:
#line 224 "syntax.y"
                                                              {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_eq_op, $1, $2, $$,0,yylineno);
						}
#line 1787 "syntax.tab.c"
    break;

  case 22:
#line 231 "syntax.y"
                                                               {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_noteq_op, $1, $2, $$,0,yylineno);
						}
#line 1797 "syntax.tab.c"
    break;

  case 23:
#line 238 "syntax.y"
                                                                        {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(and_op, $1, $2, $$,0,yylineno);
						}
#line 1807 "syntax.tab.c"
    break;

  case 24:
#line 245 "syntax.y"
                                                                {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(or_op, $1, $2, $$,0,yylineno);
						}
#line 1817 "syntax.tab.c"
    break;

  case 25:
#line 252 "syntax.y"
                                                                        {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_greatereq_op, $1, $2, $$,0,yylineno);
						}
#line 1827 "syntax.tab.c"
    break;

  case 26:
#line 259 "syntax.y"
                                                                        {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_less_op, $1, $2, $$,0,yylineno);
						}
#line 1837 "syntax.tab.c"
    break;

  case 27:
#line 266 "syntax.y"
                                                                        {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_lesseq_op, $1, $2, $$,0,yylineno);
						}
#line 1847 "syntax.tab.c"
    break;

  case 28:
#line 273 "syntax.y"
                                                                        {
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_greater_op, $1, $2, $$,0,yylineno);
						}
#line 1857 "syntax.tab.c"
    break;

  case 29:
#line 280 "syntax.y"
                                                       {
							//$$ = $1;
						}
#line 1865 "syntax.tab.c"
    break;

  case 31:
#line 286 "syntax.y"
                                                                    {
						 //  check_arith($2);
                                                 // $$ = newexpr(arithexpr_e);
					         //$$->sym = newtemp();
						//emit(uminus_op, $2, NULL, $$, 0, yylineno);//exei ena arg
					   }
#line 1876 "syntax.tab.c"
    break;

  case 32:
#line 294 "syntax.y"
                                                         {
						//printf("Line %d: Not Expression\n", yylineno);
						//$$ = newexpr(boolexpr_e);
				               // $$->sym = newtemp();
						//$$ = newexpr(boolexpr_e);
									    }
#line 1887 "syntax.tab.c"
    break;

  case 33:
#line 300 "syntax.y"
                                                            {printf("Line %d: ++ lvalue\n", yylineno);
						 /*	check_arith(($2);
							if ($2->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								emit(add_op, $term, newexpr_constnum(1), $$,0,yylineno);
								emit(tablesetelem_op, $2, $2->index, $$,0,yylineno);
							}
							else {
								emit(add, $lvalue, newexpr_constnum(1), $lvalue);
								$term = newexpr(arithexpr_e);
								$term->sym = newtemp();
								emit(assign, $lvalue, NULL, $term);
							} */

																	
					        }
#line 1908 "syntax.tab.c"
    break;

  case 34:
#line 316 "syntax.y"
                                                             {printf("Line %d: lvalue++\n", yylineno);
								/*	check_arith(($lvalue);
									$$ = newexpr(var_e);
									$$->sym = newtemp();
										if ($1->type == tableitem_e) {
										    expr* val = emit_iftableitem($lvalue);
										    emit(assign_op, val, NULL, $$,0,yylineno);
                                                                                    emit(add_op, val, newexpr_constnum(1), val,0,yylineno);
										    emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
										}
										else {
											emit(assign_op, $1, NULL, $term);
											emit(add_op, $l, newexpr_constnum(1), $lvalue);
										} */


						}
#line 1930 "syntax.tab.c"
    break;

  case 35:
#line 333 "syntax.y"
                                                            {printf("Line %d: --lvalue\n", yylineno);
						   /*	check_arith(($2);
							if ($lvalue->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								emit(sub_op, $term, newexpr_constnum(1), $term);
								emit(tablesetelem_op, $lvalue, $lvalue->index, $term);
							}
							else {
								emit(sub_op, $2, newexpr_constnum(1), $2);
								$$ = newexpr(arithexpr_e);
								$$->sym = newtemp();
								emit(assign, $2, NULL, $$,0,yylineno);
							} */

                                                }
#line 1950 "syntax.tab.c"
    break;

  case 36:
#line 348 "syntax.y"
                                                            {printf("Line %d: lvalue--\n", yylineno);
							/*	check_arith(($2);
									$$ = newexpr(var_e);
									$$->sym = newtemp();
										if ($1->type == tableitem_e) {
										    expr* val = emit_iftableitem($2);
										    emit(assign_op, val, NULL, $$,0,yylineno);
                                                                                    emit(sub_op, val, newexpr_constnum(1), val,0,yylineno);
										    emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
										}
										else {
											emit(assign_op, $1, NULL, $term);
											emit(sub_op, $l, newexpr_constnum(1), $lvalue);
										} */

							}
#line 1971 "syntax.tab.c"
    break;

  case 37:
#line 364 "syntax.y"
                                                         {printf("Line %d: Primary\n", yylineno);
							(yyval.exprvalue) = (yyvsp[0].exprvalue);
						}
#line 1979 "syntax.tab.c"
    break;

  case 38:
#line 368 "syntax.y"
                                                      {
						/*
							if $lvalue->type = tableitem_e then {
							emit( // lvalue[index] = expr
							tablesetelem,$lvalue,$lvalue->index,$expr  Use result operand for the assigned value);
							$assignexpr = emit_iftableitem($lvalue);  Will always emit
							$assignexpr->type = assignexpr_e;
                                                  }
						     else {
							emit( // that is: lvalue = expr
								assign,
								$expr,
								NULL,
								$lvalue
							);
								$assignexpr = newexpr(assignexpr_e);
								$assignexpr->sym = newtemp();
								emit(assign, $lvalue, NULL, $assignexpr);
							}    */
						}
#line 2004 "syntax.tab.c"
    break;

  case 39:
#line 389 "syntax.y"
                                               {}
#line 2010 "syntax.tab.c"
    break;

  case 40:
#line 390 "syntax.y"
                                                       {}
#line 2016 "syntax.tab.c"
    break;

  case 41:
#line 391 "syntax.y"
                                                            {}
#line 2022 "syntax.tab.c"
    break;

  case 42:
#line 392 "syntax.y"
                                                                                             {}
#line 2028 "syntax.tab.c"
    break;

  case 43:
#line 393 "syntax.y"
                                                        {}
#line 2034 "syntax.tab.c"
    break;

  case 44:
#line 396 "syntax.y"
                                   { /*KSANA DES TO DEN BRISKEI EAN YPARXEI HDH TO KANEI KATAXWRHSH ETSI KI ALLIWS*/
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
#line 2064 "syntax.tab.c"
    break;

  case 45:
#line 421 "syntax.y"
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
#line 2091 "syntax.tab.c"
    break;

  case 46:
#line 445 "syntax.y"
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
						}
#line 2118 "syntax.tab.c"
    break;

  case 47:
#line 468 "syntax.y"
                                                         {(yyval.exprvalue)=(yyvsp[0].exprvalue);}
#line 2124 "syntax.tab.c"
    break;

  case 48:
#line 471 "syntax.y"
                                                        { printf("Line %d: lvalue.ID\n", yylineno); }
#line 2130 "syntax.tab.c"
    break;

  case 49:
#line 472 "syntax.y"
                                                                                 {printf("Line %d: lvalue [Expression]\n\n", yylineno);}
#line 2136 "syntax.tab.c"
    break;

  case 50:
#line 473 "syntax.y"
                                                               { printf("Line %d: Call.ID\n", yylineno); }
#line 2142 "syntax.tab.c"
    break;

  case 51:
#line 474 "syntax.y"
                                                                                       { printf("Line %d: Call [Expression]\n", yylineno);}
#line 2148 "syntax.tab.c"
    break;

  case 55:
#line 482 "syntax.y"
                                        {(yyval.callvalue)=(yyvsp[0].callvalue);}
#line 2154 "syntax.tab.c"
    break;

  case 56:
#line 483 "syntax.y"
                                                             {(yyval.callvalue)=(yyvsp[0].callvalue);}
#line 2160 "syntax.tab.c"
    break;

  case 60:
#line 491 "syntax.y"
                                                         {}
#line 2166 "syntax.tab.c"
    break;

  case 62:
#line 495 "syntax.y"
                                                         {}
#line 2172 "syntax.tab.c"
    break;

  case 69:
#line 508 "syntax.y"
                                                         {++scope;}
#line 2178 "syntax.tab.c"
    break;

  case 70:
#line 508 "syntax.y"
                                                                                                 {
								SymTable_hide(table, scope--);
								//printf("Line %d: Block\n", yylineno);
								}
#line 2187 "syntax.tab.c"
    break;

  case 71:
#line 559 "syntax.y"
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
#line 2218 "syntax.tab.c"
    break;

  case 72:
#line 584 "syntax.y"
                                                                                   {scope++;}
#line 2224 "syntax.tab.c"
    break;

  case 73:
#line 584 "syntax.y"
                                                                                                                        {scope--;}
#line 2230 "syntax.tab.c"
    break;

  case 75:
#line 585 "syntax.y"
                                                           {
							printf("Line %d: no name function at scope %d \n", yylineno, scope);
							//create temp name
							//char *funcname;
							char tempname[200]="_f";// tyxaio wste na nai arketa megalo na xwresei olo to onoma
							int number=1;
							struct SymbolTableEntry *tmp1;//insert to symbol table
						//while (tmp1!=NULL){
							int result;//epistrefei to length to converted string
							//h sprintf metatrepei ton integer number se string
							result=sprintf(tempname,"_f%u",number);//opou to number prpei na ayksanetai
						        printf("to mikos einai %d",result);
							//desmeysh mnhmhs gia to onoma ,den kseroume to sizee afou to number den einai stathero
							//funcname=(char*)malloc (3+numbers)*sizeof(char)); //_f mazi me \0 kai numbers einai ta psifia dipla
							//funcname= (char*)malloc(sizeof(char)*(3+numbers));
							//tempname = funcname;
						        int i;
		                                           //for( i = 0; i <= 200; i++) {
		                                             //   	tempname[i]++;
	                                                	//}
		                                            //  tempname[i]++;//gia na mpei sto telos o termatikos xarakthras sthn epomenh thesi
		                                           //  *tempname = '\0';


							SymTable_put(table, tempname, yylineno, scope, USERFUNC);
							number++;

						//}
							

						}
#line 2266 "syntax.tab.c"
    break;

  case 76:
#line 615 "syntax.y"
                                                                   {scope++;}
#line 2272 "syntax.tab.c"
    break;

  case 77:
#line 615 "syntax.y"
                                                                                                       {scope--;}
#line 2278 "syntax.tab.c"
    break;

  case 80:
#line 618 "syntax.y"
                                                         { printf("Line %d: String\n", yylineno);}
#line 2284 "syntax.tab.c"
    break;

  case 81:
#line 619 "syntax.y"
                                                      {printf("Line %d: Nil\n", yylineno);}
#line 2290 "syntax.tab.c"
    break;

  case 82:
#line 620 "syntax.y"
                                                       {printf("Line %d: True\n", yylineno);}
#line 2296 "syntax.tab.c"
    break;

  case 83:
#line 621 "syntax.y"
                                                        {printf("Line %d: False\n", yylineno);}
#line 2302 "syntax.tab.c"
    break;

  case 84:
#line 625 "syntax.y"
                                                         {
							
							
							enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
							//printf("%d\n", scope);

							/*
                            void SymTable_hide(SymTable_T oSymTable,int scope);
                            for(dummy_scope; dummy_scope >= 0; dummy_scope--){
                                if(SymTable_contains2(table, yytext, dummy_scope)){
                                    printf("ID %s already exists in table\n", yytext);
                                    printf("Perase to hide ? An nai den tha fenetai lgk kati");
                                    flag = 1;
                                    break;
                                }
                            }
                    		*/    

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
#line 2342 "syntax.tab.c"
    break;

  case 86:
#line 662 "syntax.y"
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
#line 2368 "syntax.tab.c"
    break;

  case 88:
#line 682 "syntax.y"
                                                                   {}
#line 2374 "syntax.tab.c"
    break;

  case 91:
#line 699 "syntax.y"
                                                                                      {
					 /*	
						emit(jump, NULL, NULL, $whilestart);
						patchlabel($whilecond, nextquad());
						patchlist($stmt.breaklist, nextquad());
						patchlist($stmt.contlist, $whilestart); */
					}
#line 2386 "syntax.tab.c"
    break;

  case 93:
#line 709 "syntax.y"
                                             {printf("Line %d: Return expression\n", yylineno);
						//emit(ret_op, NULL, NULL, NULL, 0, yylineno);
					        }
#line 2394 "syntax.tab.c"
    break;

  case 94:
#line 712 "syntax.y"
                                                                        {
							printf("Line %d: Return expression\n", yylineno);
							// emit(return_op, $expr); 
						}
#line 2403 "syntax.tab.c"
    break;


#line 2407 "syntax.tab.c"

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
#line 718 "syntax.y"


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