/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    MULTIPLE_COMMENT = 307,
    NESTED_COMMENT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "syntax.y"
  
	int intValue;
    double realValue; 
    char *strval;
  

#line 119 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
