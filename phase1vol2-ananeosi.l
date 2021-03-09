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

/*

 %x STRING 

 %% 
/* STRINGS */
\"           {strcpy(str_buf, " "); BEGIN(STRING);}   //mpainoume ston upoanaliti
<STRING>\"   {BEGIN(INITIAL); printf("edw mpanei to string \n); return STRING;}   //vgainoume apo ton ipoanaliti kai epistrefoume..

/*~~~~~~~~~~~~EnasTropos~~~~~~~~~~~~*/
//pianei kai ta alfarithmitika kai .\ \" \n \t \v \i \f \l ktl ktl anagnwrizei ta panta aftou tou tipou
//nea grammi gia ta strings
<STRING>(\\.|[^"\\])  {
                          if(strlen(yytext)== 2){
                            if(strcmp(yytext, "\\n") == 0){
                                strcat(str_buf, "\n");
                            }else if(stcmp(yytext,"\\t") == 0){
                                strcat(str_buf, "\t");
                            }else if(stcmp(yytext,"\\r") == 0){
                                strcat(str_buf, "\r");
                            }else if(stcmp(yytext,"\\f") == 0){
                                strcat(str_buf, "\f");
                            }else if(stcmp(yytext,"\\b") == 0){
                                strcat(str_buf, "\b");
                            }else if(stcmp(yytext,"\\v") == 0){
                                strcat(str_buf, "\v");
                            }
                          }else{
                                strcat(str_buf, &yytext[1]);   
                            }
                     }
                          strcat(str_buf, yytext);
                      } //vrikame eidiko xaraktira i aplo, ektipwse ton

<STRING><<EOF>>       {printf("End of string without closing it.");}  //ftasame sto telos tou arxeiou enw eimaste se string peta ERROR

<STRING>(\\\n|\\\r\n) {}   //nea grammi sta strings den ekteleite kwdikas

//gia windows \r\n
<STRING>(\n|\r\n)     {printf("New line found without \\");}  //nea grammi xwris \ sto telos peta ERROR

//mpainoume ston ipoanaliti
"\\"                                {printf("Comment found\n"); BEGIN(SINGLE_LINE_COMMENT);}
<SINGLE_LINE_COMMENT>(\n|\r\n)      {BEGIN(INITIAL); printf("Comment \n");} \\girname apo ton ipoanaliti
<SINGLE_LINE_COMMENT>.              { }

/*~~~~~~~~~~~~~~~~DuoTropos~~~~~~~~~~~~~~~~*/

<STATE_STRING>\n                {yyerror("Illegal input in string", 1); return 0;}
<STATE_STRING>\\n               {*str_bur_ptr++ = '\n';}
<STATE_STRING>\\f               {*str_bur_ptr++ = '\f';}
<STATE_STRING>\\t               {*str_bur_ptr++ = '\t';}
<STATE_STRING>\\r               {*str_bur_ptr++ = '\r';}
<STATE_STRING>\\b               {*str_bur_ptr++ = '\b';}
<STATE_STRING>\\v               {*str_bur_ptr++ = '\v';}
<STATE_STRING>\\\\              {*str_bur_ptr++ = '\\';}
<STATE_STRING>\\\"              {*str_bur_ptr++ = '"';}
<STATE_STRING>\\\n              {lineno++;}
<STATE_STRING>\\{ALPHANUM_}?    {*str_buf_ptr++ == yytext[1];}
<STATE_STRING><<EOF>>           {yyerror("Unterminated string", 1); return 0;}

{WHITESPACE}                    {}
\n                              {lineno++;}


*/
