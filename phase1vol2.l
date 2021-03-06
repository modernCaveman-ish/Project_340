%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "test_token.h"

%}

%option noyywrap
%option yylineno
%option case-insensitive

/* Isodynamies klasewn */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ALPHANUM    {LETTER}|{DIGIT}

/*KEY WORDS AND KEY ELEMENTS*/
/*CODE FOR COMMENTS*/
%%

/*-----------------------KEYWORDS-----------------------*/

"if"		    {token_number++; content_type = "KEYWORD"; return IF;}
"else"		    {token_number++; content_type = "KEYWORD"; return ELSE;}
"while"		    {token_number++; content_type = "KEYWORD"; return WHILE;}
"for"		    {token_number++; content_type = "KEYWORD"; return FOR;}
"function"      {token_number++; content_type = "KEYWORD"; return FUNCTION;}
"return"        {token_number++; content_type = "KEYWORD"; return RETURN;}
"break"         {token_number++; content_type = "KEYWORD"; return BREAK;}
"continue"      {token_number++; content_type = "KEYWORD"; return CONTINUE;}
"and"           {token_number++; content_type = "KEYWORD"; return AND;}
"not"           {token_number++; content_type = "KEYWORD"; return NOT;}
"or"            {token_number++; content_type = "KEYWORD"; return OR;}
"local"         {token_number++; content_type = "KEYWORD"; return LOCAL;}
"true"          {token_number++; content_type = "KEYWORD"; return TRUE;}
"false"         {token_number++; content_type = "KEYWORD"; return FALSE;}
"nil"           {token_number++; content_type = "KEYWORD"; return NIL;}

/*----------------------OPERATROS-----------------------*/

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

/*------------------------BRACES-----------------------*/

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

"\n"                {line_number++;}
" "                 {continue;}

"/*"([^*]|\*+[^*/])*\*+"/"      {token_number++; content_type = "MULTILINE_COMMENT"; return MULTILINE_COMMENT;  /*multiline comment but not nested*/}


<<EOF>>     {return 0;}

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

    do{
        /*Create and assign new alpha_token_t and expand the list*/
        token = yylex();
        content_string = yytext;
        
        /*
            Values poy kratane shmantikes times
            token: Epistrefei to token poy entwphse h yylex()
            line_number: To line Number poy brisketai to kathe token
            token_number: O arithmos toy token poy entwpisthke, px prwto, deftero, trito
            content_string: To token, poio akribws einai
            content_type: h kathgoria sthn opoia katatasetai to token pou entwphstike
        */

        if(token == 0)
            break;


        /* TODO MAKE THE LIST AND PRINT IT */

        head = addToList(head, line_number, token_number, content_string, content_type);

    } while(token != 0);

    temp = head;

    printf("Printing List...\n");

    printTokenList(temp);

    
    fclose(yyin);
    yyterminate();

    return 0;
}
