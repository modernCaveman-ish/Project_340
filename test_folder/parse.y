%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "tokens.h"
    #define  YY_DECL int alpha_yylex(yval) void * yval;

    extern FILE *yyin;
%}
/* xrisimopoiite gia na paroume poio analitika minimata lathous */
%error-verbose;

%token IF                           "if"
%token ELSE                         "else"
%token WHILE                        "while"
%token FOR                          "for"
%token FUNCTION                     "function"
%token RETURN                       "return"
%token BREAK                        "break"
%token CONTINUE                     "continue"
%token AND                          "&&"
%token NOT                          "not"
%token OR                           "||"
%token LOCAL                        "local"
%token TRUE                         "true"
%token FALSE                        "false"
%token NIL                          "nil"
%token ASSINGMENT                   "="
%token ADD                          "+"
%token SUBTRACT                     "-"
%token MULTIPLY                     "*"
%token DIVISION                     "/"
%token MODULO                       "%"

%token INCREAMENT1                  "++"
%token DECREAMENT                   "--"
%token EQUAL                        "=="
%token DIFFERENT                    "!="
%token LESS_THAN                    "<"
%token GREATER_THAN                 ">"
%token GREATER_EQUAL                ">="
%token LESS_EQUAL                   "<="
%token LEFT_CURLY_BRACE             "{"
%token RIGHT_CURLY_BRACE            "}"
%token LEFT_BRACKET                 "["
%token RIGHT_BRACKET                "]"
%token RIGHT_PARENTHESIS            "("
%token LEFT_PARENTHESIS             ")"
%token SEMICOLON                    ";"
%token COMMA                        ","
%token COLON                        ":"
%token NAMESPACE                    "::"
%token DOT                          "."
%token DOUBLE_DOT                   ".."
%token WHITESPACE                   " "
%token TAB                          "\t"
%token BACKSLASH                    "\""
%token UNDERSCORE                   "\_"
%token LETTER                       "[a-zA-Z]"
%token QUOTE                        "\""
%token STRING                       "({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})"
%token COMMENT                      ""//".*"
%token INTEGER                      "{digit}+"
%token DOUBLE                       "[0-9]+\.[0-9]*"

%token MULTIPLE_COMMENT             ""
%token NESTED_COMMENT               ""

%union{int valint; float valfloat; char valchar; char* valstr;}

%token <valstr>         ID              "id"
%token <valint>         ICONST          "iconst"
%token <valfloat>       FCONST          "fconst"
%token <valchar>        CCONST          "cconst"
%token <valstr>         SCONST          "sconst"

%token EOF              0           "EOF"

%left   COMMA
%right  ASSINGMENT
%left   OR
%left   AND
%left   EQUAL
%left   LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL
%left   ADD SUBTRACT
%left   MULTIPLY DIVISION MODULO
%right  INCREAMENT1 DECREAMENT
%left   RIGHT_PARENTHESIS LEFT_PARENTHESIS RIGHT_BRACKET LEFT_BRACKET

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
