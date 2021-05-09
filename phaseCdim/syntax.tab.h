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
    STRING = 302,
    COMMENT = 303,
    ID = 304,
    MULTILINE_COMMENT = 305,
    NESTED_COMMENT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "syntax.y"
  

	struct expr* exprvalue;
	struct call* callvalue;
	struct symbol* symbolvalue;
	int intValue;
    double realValue; 
	char *strval;
 

#line 121 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
