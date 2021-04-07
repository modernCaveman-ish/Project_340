/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    WHITESPACE = 300,
    TAB = 301,
    UNDERSCORE = 302,
    NUMBER = 303,
    LETTER = 304,
    QUOTE = 305,
    STRING = 306,
    COMMENT = 307,
    ID = 308,
    MULTIPLE_COMMENT = 309,
    NESTED_COMMENT = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "syntax.y" /* yacc.c:1909  */
  
	int intValue;
    double realValue; 
    char *strval;
  

#line 118 "syntax.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
