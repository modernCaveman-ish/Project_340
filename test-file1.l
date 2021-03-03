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

%%

/*------------------------------------KEYWORDS------------------------------------*/
"if"                {return IF;}
    "else"              {return ELSE;}
        "while"             {return WHILE;}
            "for"               {return FOR;}
                "function"          {return FUNCTION;}
                    "return"            {return RETURN;}
                        "break"             {return BREAK;}
                            "continue"          {return CONTINUE;}
                        "and"               {return AND;}
                    "not"               {return NOT;}
                "or"                {return OR;}
            "local"             {return LOCAL;}
        "true"              {return TRUE;}
    "false"             {return FALSE;}
"nil"               {return NIL;}

/*------------------------------------OPERETORS------------------------------------*/ 
"+"                 {return add;}
    "="                 {return equal;}
        "-"                 {return minus;}
            "*"                 {return mul;}
                "/"                 {return divide;}
                    "%"                 {return percent;}
                        "++"                {return plusplus;}
                            "--"                {return minusminus;}
                                ">"                 {return greater;}
                                    "<"                 {return lesser;}
                                ">="                {return greater_equal;}
                            "<="                {return lesser_equal;}
                        ";"                 {return semicolon;}
                    ","                 {return comma;}
                ":"                 {return colon;}
            "::"                {return coloncolon;}
        "."                 {return dot;}
    ".."                {return dotdot;}
"//"                {return comment;}

/*--------------------------------------BRACES--------------------------------------*/
"{"                 {return left_curly_brace;}
    "}"                 {return right_curly_brace;}
        "["                 {return leftbracket;}
            "]"                 {return rightbracket;}
    "("                 {return left_parenthesis;}
")"                 {return right_parenthesis;}

"digit"             {return digit;}
"integer"           {return digit+;}
"double"            {return intiger.integer;}
"newline"           {return \\n;}
"tab"               {return \\t;}
"backslash"         {return \\;}
"unerscore"         {return \_;}
"letter"            {return [a-z A-Z];}
"quote"             {return \";}
"string"            {return ({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote});}
"identifier"        {return {letter}({letter}|{digit}|{underscore})*leftbrace "{";}

%%

/*EXTRA*/
{numbers}           {yylval.number = atoi(yytext); return (NUM);}
";"                 {return (SEMICOLON);}
.                   {showError(); return(OTHER);}

{IF}                {return IF;}
{[a-z][a-z0-9]*}    {return ID;}
{[0-9]}             {return NUM};0

{operations}        {fprintf("Recognized id with value %s\n",yytext);}
{comments}          {fprintf("Recognized id with value %s\n",yytext);}
{identifier}        {fprintf("Recognized id with value %s\n",yytext);}

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
