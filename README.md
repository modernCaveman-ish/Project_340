# Project_340


%{
#include <stdlib.h>
#include <string.h>

#include "Expressions.h"
#include "Common.h"
#include "Statements.h"
#include "util.h"
#include "DecisionMakerBisonParser.h"

#define YY_DECL int yylex(YYSTYPE *lvalp)
%}

/*DIMIOURGEI ENA HEADER FILE POU PERIEXEI DILWSEIS TIPWN*/
%option header-file="./scanner.h"

/*DILWNEI KATHOLIKI METAVLITI yylineno KRATAEI*/
        /*TREXOUSA GRAMMI TOU ARXEIOU*/
%option yylineno

/*XRISIMOPOIEI TO PARAGOMENO LEX*/
%option prefix ="PREFIX"

/*KEYWORDS*/
if "if"
    else "else"
        while "while"
            for  "for"
                function "function"
                    return "return"
                        break "break"
                            continue "continue"
                        and "and"
                    not "not"
                or "or"
            local "local"
        true "true"
    false "false"
nil "nil"

/*OPERETORS*/
assignment "="
    add "+"
        sub "-"
            mul "*"
                div "/"
                    perc "%"
                        icreament1 "++"
                            decreament "--"
                        greater ">"
                    less "<"
             equal "=="
         diff "!="
    greater_equal ">="
less_equal  "<="

/*REST*/

digit [0-9]
    integer {digit}+
        double integer.integer
    newline		"\\n"
tab		"\\t"
    backslash	"\\"
        underscore \_
    letter [a-z A-Z]
quote \"
    string	({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})
        left_curly_brace "}"
    right_curly_brace "}"
leftbracket "["
    rightbracket "]"
        right_parenthesis ")"
    left-parenthesis "("
semicolon ";"
    comma ","
        colon ":"
    namespace "::"
dot "."
    double_dot ".."
        identifier {letter}({letter}|{digit}|{underscore})*leftbrace "{"
    comment "//".*
multiple_line_comment"/*"

multiple_line_comment"*/"

%%

/*EXTRA*/
{numbers}       {yylval.number = atoi(yytext); return (NUM);}
";"             {return (SEMICOLON);}
.               {showError(); return(OTHER);}

{operations}    {fprintf("Recognized id with value %s\n",yytext);}
{comments}      {fprintf("Recognized id with value %s\n",yytext);}
{identifier}    {fprintf("Recognized id with value %s\n",yytext);}

%%

/*tmhma kwdika xrhsth*/
int main(int argc,char** argv){
	
	if(argc>1){
		if(!yyin=fopen(argv[1],"r"))){
		   fprintf(stderr,"Cannot read file : %s\n",argv[1]);
		   return 1;	
		}
	}
	else{
		yyin=stdin;
	}
	alpha_yylex();
	return 0;
}
