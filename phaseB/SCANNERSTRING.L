%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "syntax.tab.h"

struct alpha_token_t {
  int     numLine;
  int     numToken;
  char*   content;
  char    *type;
  struct alpha_token_t* next; /*next token pointer*/
};

   extern void yyerror(char *message);

   int line_number = 1;
   int token_number = 0;

   char *content_string;
   char *content_type;

    int nested = 0;

struct alpha_token_t* addToList(struct alpha_token_t* head, int line_number, int token_number, char* content_string, char* content_type){

  struct alpha_token_t* temp;

  temp = head;

  printf("%d: #%d", yylineno, token_number);
  printf(" \"%s\"  %s\n", content_string, content_type);


  if(head == NULL){

    head = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));

    head->numLine = line_number;
    head->numToken = token_number;

    head->content = strdup(content_string);
    head->type = strdup(content_type);
    head->next = NULL;

    temp = head;
  } 
  else if(temp->next == NULL){

      temp->next = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));

      temp = temp->next;

      temp->numLine = line_number;
      temp->numToken = token_number;
      temp->content = strdup(content_string);
      temp->type = strdup(content_type);
      temp->next = NULL;
    
    } else if(temp->next != NULL){

    while(temp->next != NULL)
      temp = temp->next;

      if(temp->next == NULL){

        temp->next = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));
        temp = temp->next;

        temp->numLine = line_number;
        temp->numToken = token_number;
        temp->content = strdup(content_string);
        temp->type = strdup(content_type);
        temp->next = NULL;
      }
    }
  return head;
}

%}

%option noyywrap
%option yylineno
%option case-insensitive
%x SC_COMMENT
%x SC_STRING

/* REGEX */

digit       [0-9]
backslash	"\\"
double [0-9]+\.[0-9]*
integer {digit}+
letter      [a-zA-Z]
underscore \_
tab		"\\t"
quote \"
newline		"\\n"
whitespace  " "	
identifier ({letter}{1})(({letter})|({digit})|({underscore}))*
string	({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})

/*operators*/
assignment "="
add "+"
sub "-"
mul "*"
div "/"
mod "%"
icreament1 "++"
decreament "--"
greater ">"
less "<"
equal "=="
diff "!="
greater_equal ">="
less_equal  "<="

unrecognized .

left_curly_brace "{"
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

comment "//".*

%%

"if"		{token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return IF;}
"else"		{token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return ELSE;}
"while"		{token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return WHILE;}
"for"		{token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return FOR;}
"function"  {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return FUNCTION;}
"return" {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return RETURN;}
"break"     {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return BREAK;}
"continue"  {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return CONTINUE;}
"nil"     {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return NIL;}
"and"       {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return AND;}
"not"       {token_number++; content_type = "KEYWORD"; yylval.strval = strdup(yytext);return NOTOP;}
"or"        {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return OR;}
"local"     {token_number++; content_type = "KEYWORD";yylval.strval = strdup(yytext); return LOCAL;}
"true"      {token_number++; content_type = "KEYWORD"; yylval.strval = strdup(yytext);return TRUE;}
"false"     {token_number++; content_type = "KEYWORD"; yylval.strval = strdup(yytext);return FALSE;}

{identifier} {token_number++; content_type = "IDENTIFIER"; printf("TEST\n"); return ID;}
{assignment} {token_number++; content_type = "ASSINGMENT OPERATOR";yylval.strval = strdup(yytext); return  ASSIGNMENT;}
{add} {token_number++; content_type = "ADD OPERATOR";yylval.strval = strdup(yytext); return ADD;}
{sub} {token_number++; content_type = "SUBTRACT OPERATOR";yylval.strval = strdup(yytext); return SUB;}
{mul} {token_number++; content_type = "MULTIPLYOPERATOR";yylval.strval = strdup(yytext); return MUL;}
{div} {token_number++; content_type = "DIVISION OPERATOR";yylval.strval = strdup(yytext); return DIV;}
{mod} {token_number++; content_type = "MODULO OPERATOR";yylval.strval = strdup(yytext); return MOD;}
{icreament1} {token_number++; content_type = "INCREAMENTBY1 OPERATOR";yylval.strval = strdup(yytext); return INC;}
{decreament} {token_number++; content_type = "DECREAMENTBY1 OPERATOR";yylval.strval = strdup(yytext); return DEC;}
{greater} {token_number++; content_type = "GREATER THAN OPERATOR";yylval.strval = strdup(yytext); return GR;}
{less} {token_number++; content_type = "LESS THAN OPERATOR";yylval.strval = strdup(yytext); return LESS;}
{equal} {token_number++; content_type = "EQUAL OPERATOR";yylval.strval = strdup(yytext);return EQ;}
{diff} {token_number++; content_type = " DIFFERENT OPERATOR";yylval.strval = strdup(yytext); return DIF;}
{greater_equal} {token_number++; content_type = " GREATER OR EQUAL OPERATOR";yylval.strval = strdup(yytext); return GREQ;}
{less_equal} {token_number++; content_type = "LESS OR EQUAL OPERATOR";yylval.strval = strdup(yytext); return LESSEQ;}


{left_curly_brace} {token_number++; content_type = "LEFT CURLY BRACE";yylval.strval = strdup(yytext); return LEFT_CURLY_BRACE;}
{right_curly_brace} {token_number++; content_type = "RIGHT CURLY BRACE";yylval.strval = strdup(yytext); return RIGHT_CURLY_BRACE;}
{leftbracket} {token_number++; content_type = "LEFT BRACKET";yylval.strval = strdup(yytext); return LEFT_BRACKET;}
{rightbracket} {token_number++; content_type = "RIGHT BRACKET";yylval.strval = strdup(yytext); return RIGHT_BRACKET;}
{right_parenthesis} {token_number++; content_type = "RIGHT PARENTHESIS";yylval.strval = strdup(yytext); return RIGHT_PARENTHESIS;}
{left-parenthesis} {token_number++; content_type = "LEFT PARENTHESIS";yylval.strval = strdup(yytext); return LEFT_PARENTHESIS;}
{semicolon} {token_number++; content_type = "SEMICOLON";yylval.strval = strdup(yytext); return SEMICOLON;}
{comma} {token_number++; content_type = "COMMA";yylval.strval = strdup(yytext); return COMMA;}
{colon} {token_number++; content_type = "COLON";yylval.strval = strdup(yytext); return COLON;}
{namespace} {token_number++; content_type = "NAMESPACE";yylval.strval = strdup(yytext); return NAMESPACE;}
{dot} {token_number++; content_type = "DOT";yylval.strval = strdup(yytext); return DOT;}
{double_dot} {token_number++; content_type = "DOUBLE DOT";yylval.strval = strdup(yytext); return DOUBLE_DOT;}

{tab}		{}

{quote} {token_number++; content_type = "QUOTE"; return QUOTE;} 

"\n"        {line_number++;}
{whitespace}         {}
{integer} {token_number++; content_type = "INTEGER"; return NUMBER;}
{double} { token_number++; content_type = "DOUBLE"; return NUMBER;}
{string} {token_number++;content_type = "STRING"; yylval.strval = strdup(yytext); return STRING;}  
{comment} {token_number++;content_type = "COMMENT"; return COMMENT;} 

--------------------------------------------------------

/*
  
  <SC_STRING>  /*{BEGIN(SC_COMMENT);}*/
                  {BEGIN(SC_STRING); token_number = content_type;
                    if(content_string==1){
                        content_string++;
                        printf("String Found: %s \n", content_string);
                      retrun SC_STRING;

                    //leipoun peritwseis an periexei enters i tabs 
                    }else{
                        printf("ERROR STRING NOT FOUND");
                    }
                  }

  <SC_STRING>"\n"   {token_number++ = '\n';}
  <SC_STRING>"\t"   {token_number++ = '\t';}

*/

--------------------------------------------------------

"/*"	{BEGIN(SC_COMMENT);
	token_number++;content_type = "MULTIPLE_COMMENT"; return MULTIPLE_COMMENT;
        }

<SC_COMMENT>"/*" {  nested++;
		    BEGIN(SC_COMMENT);
                    token_number++;content_type = "NESTED_COMMENT"; return NESTED_COMMENT;
		 }

<SC_COMMENT>[^(*/)|(^/*)]* 	{}
<SC_COMMENT>{comment}     {}
<SC_COMMENT>"*/" {   if(nested){				    	
                           BEGIN(SC_COMMENT); 
		     } else{
		           BEGIN(INITIAL);
		           token_number++;content_type = "MULTIPLE_COMMENT"; 
			   return MULTIPLE_COMMENT;
		       }
		 }


<<EOF>>     {return 0;}

%%
