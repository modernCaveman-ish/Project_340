%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "tokens.h"
    #define  YY_DECL int alpha_yylex(yval) void * yval;

    extern FILE *yyin;
%}

%union{
    
}

%token IF                           "if"
%token ELSE                         "else"
%token WHILE                        "while"
%token FOR                          "for"
%token FUNCTION                     "function"
%token RETURN                       "return"
%token BREAK                        "break"
%token CONTINUE                     "continue"
%token AND                          "and"
%token NOT                          "not"
%token OR                           "or"
%token LOCAL                        "local"
%token TRUE                         "true"
%token FALSE                        "false"
%token NIL                          "nil"
%token ASSINGMENT                   "assignment"
%token ADD                          "add"
%token SUBTRACT                     "substract"
%token MULTIPLY                     "multiply"
%token DIVISION                     "division"
%token MODULO                       "modulo"

%token INCREAMENT1                  "increament1"
%token DECREAMENT                   "decreament"
%token EQUAL                        "equal"
%token DIFFERENT                    "different"
%token LESS_THAN                    "less_than"
%token GREATER_THAN                 "greater_than"
%token GREATER_EQUAL                "greater_equal"
%token LESS_EQUAL                   "less_equal"
%token LEFT_CURLY_BRACE             "left_curly_brace"
%token RIGHT_CURLY_BRACE            "right_curly_brace"
%token LEFT_BRACKET                 "lect_bracket"
%token RIGHT_BRACKET                "right_bracket"
%token RIGHT_PARENTHESIS            "right_parenthesis"
%token LEFT_PARENTHESIS             "left_parenthesis"
%token SEMICOLON                    ";"
%token COMMA                        ","
%token COLON                        ":"
%token NAMESPACE                    "\n"
%token DOT                          "."
%token DOUBLE_DOT                   ".."
%token WHITESPACE                   " "
%token TAB                          "\t"
%token BACKSLASH                    "\""
%token UNDERSCORE                   "_"
%token LETTER                       ""
%token QUOTE                        ""
%token STRING                       ""
%token COMMENT                      ""
%token INTEGER                      ""
%token DOUBLE                       ""
%token ID                           ""
%token MULTIPLE_COMMENT             ""
%token NESTED_COMMENT               ""

%%
program: stmt*

stmt: expr ;
    | ifstmt 
    | whilestmt 
    | forstmt 
    | returnstmt
    | break ;
    | continue;
    | block
    | funcdef
    | ;

expr: assignexpr
    | expr op expr
    | term

op: + | - | * | / | % | > | >= | < | <= | == | != | and | or

term: ( expr )
    | - expr
    | not exprHY 340 / Εαρινό εξάμηνο 2021 Σελ. 3
    | ++lvalue
    | lvalue++
    | --lvalue
    | lvalue--
    | primary

assginexpr: lvalue = expr

primary: lvalue
       | call
       | objectdef
       | ( funcdef )
       | const

lvalue: id
      | local id
      | :: id
      | member
member: lvalue . id
      | lvalue [ expr ]
      | call . id
      | call [ expr ]

call: call ( elist )
    | lvalue callsuffix
    | ( funcdef) ( elist )

callsuffix: normcall
          | methodcall

normcall: ( elist )
methodcall:.. id ( elist ) // equivalent to lvalue.id(lvalue, elist)

elist: [ expr [, expr]  ]

objectdef: [ [elist | indexed] ]
indexed: [indexedelem [, indexedelem]  ]
indexedelem: { expr : expr }

block: { [stmt*] }

funcdef: function [id] (idlist) block

const: number | string | nil | true | false
idlist: [id [, id] * ]

ifstmt: if ( expr ) stmt [ else stmt ]
whilestmt: while ( expr ) 
forstmt: for ( elist; expr; elist) stmt
returnstmt: return [expr];

%%  
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

    //kommati sintaktikis analisis prepei na mpei edw

    yyparse();
 
    fclose(yyin);
    return 0;
}
