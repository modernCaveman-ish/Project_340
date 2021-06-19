%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "syntax.tab.h"
    #include <assert.h>
    #include <string.h>

struct alpha_token_t {
  int        numLine;
  int     numToken;
  char*   content;
  char    *type;
  struct alpha_token_t* next; /*next token pointer*/
};

struct comment_struct {
  int comment_counter;
  char *content;
  struct comment_struct *next;
};

struct alpha_token_t* head = NULL;
struct alpha_token_t* temp = NULL;

char *str_buff ;
int str_buff_i=0;
int buff_len = 0;

int yycount = 0;

extern void yyerror(char *message);
char *temp_content;/*added*/
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

    } 
  else if(temp->next != NULL){

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

/*
size_t ms_length(const char *pcStr)
{
    size_t uiLength = 0U;
    assert(pcStr != NULL);
    while (*(pcStr + uiLength) != '\0')
        uiLength++;
    return uiLength;
}

char *ms_concat(char *dest, const char *src){
    char *new_dest = (char *) malloc(sizeof(ms_length(dest) + ms_length(src)));
    int i = 0;

    assert(dest != NULL);
    assert(src != NULL);
    assert(new_dest != NULL);

    while(i<ms_length(dest)){
        *(new_dest + i) = *(dest + i);
        i++;
    }
    
    i=0;
    while(i<ms_length(src)){
        *(new_dest + ms_length(dest) + i) = *(src + i);
        i++;
    }


    return new_dest;
}
*/

%}

%option noyywrap
%option yylineno
%option case-insensitive
%x COMMENT
%x SC_STRING


/* REGEX */

digit       [0-9]
backslash	"\\"
integer {digit}+
double [0-9]+\.[0-9]*
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

"if"		{token_number++; content_type = "KEYWORD";return IF;}
"else"		{token_number++; content_type = "KEYWORD";return ELSE;}
"while"		{token_number++; content_type = "KEYWORD"; return WHILE;}
"for"		{token_number++; content_type = "KEYWORD"; return FOR;}
"function"  {token_number++; content_type = "KEYWORD"; return FUNCTION;}
"return" {token_number++; content_type = "KEYWORD"; return RETURN;}
"break"     {token_number++; content_type = "KEYWORD"; return BREAK;}
"continue"  {token_number++; content_type = "KEYWORD"; return CONTINUE;}
"nil"     {token_number++; content_type = "KEYWORD"; return NIL;}
"and"       {token_number++; content_type = "KEYWORD"; return AND;}
"not"       {token_number++; content_type = "KEYWORD"; return NOTOP;}
"or"        {token_number++; content_type = "KEYWORD"; return OR;}
"local"     {token_number++; content_type = "KEYWORD";return LOCAL;}
"true"      {token_number++; content_type = "KEYWORD"; return TRUE;}
"false"     {token_number++; content_type = "KEYWORD"; return FALSE;}

{identifier} {token_number++; content_type = "IDENTIFIER";return ID;}
{assignment} {token_number++; content_type = "ASSINGMENT OPERATOR"; return  ASSIGNMENT;}
{add} {token_number++; content_type = "ADD OPERATOR"; return ADD;}
{sub} {token_number++; content_type = "SUBTRACT OPERATOR"; return SUB;}
{mul} {token_number++; content_type = "MULTIPLYOPERATOR"; return MUL;}
{div} {token_number++; content_type = "DIVISION OPERATOR"; return DIV;}
{mod} {token_number++; content_type = "MODULO OPERATOR";return MOD;}
{icreament1} {token_number++; content_type = "INCREAMENTBY1 OPERATOR"; return INC;}
{decreament} {token_number++; content_type = "DECREAMENTBY1 OPERATOR"; return DEC;}
{greater} {token_number++; content_type = "GREATER THAN OPERATOR"; return GR;}
{less} {token_number++; content_type = "LESS THAN OPERATOR"; return LESS;}
{equal} {token_number++; content_type = "EQUAL OPERATOR";return EQ;}
{diff} {token_number++; content_type = " DIFFERENT OPERATOR"; return DIF;}
{greater_equal} {token_number++; content_type = " GREATER OR EQUAL OPERATOR"; return GREQ;}
{less_equal} {token_number++; content_type = "LESS OR EQUAL OPERATOR"; return LESSEQ;}

{left_curly_brace} {token_number++; content_type = "LEFT CURLY BRACE"; return LEFT_CURLY_BRACE;}
{right_curly_brace} {token_number++; content_type = "RIGHT CURLY BRACE"; return RIGHT_CURLY_BRACE;}
{leftbracket} {token_number++; content_type = "LEFT BRACKET"; return LEFT_BRACKET;}
{rightbracket} {token_number++; content_type = "RIGHT BRACKET";return RIGHT_BRACKET;}
{right_parenthesis} {token_number++; content_type = "RIGHT PARENTHESIS";return RIGHT_PARENTHESIS;}
{left-parenthesis} {token_number++; content_type = "LEFT PARENTHESIS"; return LEFT_PARENTHESIS;}
{semicolon} {token_number++; content_type = "SEMICOLON"; return SEMICOLON;}
{comma} {token_number++; content_type = "COMMA"; return COMMA;}
{colon} {token_number++; content_type = "COLON"; return COLON;}
{namespace} {token_number++; content_type = "NAMESPACE"; return NAMESPACE;}
{dot} {token_number++; content_type = "DOT"; return DOT;}
{double_dot} {token_number++; content_type = "DOUBLE DOT"; return DOUBLE_DOT;}

{tab}		{}

"\n"        {line_number++;}
{whitespace}         {}
{integer} {token_number++; content_type = "INTEGER";yylval.realValue = atoi(yytext); return NUMBER;}

{double} { token_number++; content_type = "DOUBLE";yylval.realValue = atof(yytext);return NUMBER;}


\"                                { BEGIN(SC_STRING); printf("ksekinaei to string\n");
                                      str_buff_i=0;
                                      str_buff = (char*)malloc(1000*sizeof(char));

                                  }
<SC_STRING>\"                     { BEGIN(INITIAL); str_buff[str_buff_i++] = '\0'; printf("telos toy string\nTo String einai: %s\n", str_buff);  /*head = addToList(head, yylineno, token_number, str_buff, "STRING");*/

token_number++;content_type = strdup("STRING"); yylval.strval = str_buff; return STRING;

} 


<SC_STRING>\\n                {//printf("Brhke NEWLINE\n");
                                   // str_buff = strcat(str_buff, "\n");
                                    str_buff[str_buff_i++] = '\n';
                                      //printf("EKTIPWSE TO BACKSLASHHH N %s\n ", str_buff);

                                  }

                              
<SC_STRING>\\\\                  {//printf("Brhke NEWLINE\n");
                                   // str_buff = strcat(str_buff, "\\");
                                    str_buff[str_buff_i++] = '\\';
                                      //printf("EKTIPWSE TO BACKSLASHHH N %s\n ", str_buff);

                                  }

<SC_STRING>\\t                    {//printf("Brhke TAB\n");
                                   // str_buff = strcat(str_buff, "\t");
                                    str_buff[str_buff_i++] = '\t';
                                      //printf("EKTIPWSE TO BACKSLASHHH T %s\n ", str_buff);
                                  }

<SC_STRING>(\\.|[^"\\])           {
                                  //printf("prin to baloume sto str_buff: %s\n", yytext);
                                  str_buff[str_buff_i++] = yytext[0];
                                 // printf("\n%d %d\n", strlen(yytext), sizeof(str_buff));
                                  //  str_buff = strcat(str_buff, yytext);
                                    //printf("str_buff now: %s\n", str_buff);
                                  }

<SC_STRING><<EOF>>                { printf("klisimo tou string");  return SC_STRING;}


"//".*                            { printf("found single line comment in line: %d\n", yylineno); }

"/*"	{	
 
    //token_number++;content_type = "STRING"; yylval.strval = strdup(str_buff); return STRING;

    head = addToList(head, yylineno, token_number, "/*", "MULTILINE_COMMENT");
    token_number++;
    
  temp_content = yytext;
  //printf("Found this in comment: %s\n", temp_content);

    /*Work */
    int active_comments = 1;
    int current = 0;
    int next = 0;
    struct comment_struct *comment_list;

    comment_list = (struct comment_struct *)malloc(sizeof(struct comment_struct));
    /*comment_list->comment_counter++;*/

    current = input();
    next = input();

    //content_type = MULTI_LINE_COMMENT;

    while((current != EOF && next != EOF) && (current != 0 && next != 0)){
        /*Check for / and * */
        //printf("current: %c next: %c\n", current, next);
        if(current == '*' && next != '*'){
            if(next == '/'){    /*closing comments */
                active_comments--;
                //printf("Closing tag detected, active_comments: %d\n", active_comments);
                //current = input();
                //next = input();
                if(active_comments == 0){
                    break; /*End of comments*/
                }
            else { 
                current = input();
                next = input();
            }
           
            }
            else {
                current = input();
                next = input();
            }
        }
        else if(current == '*' && next == '*'){ 
            current = next;
            next = input();
        }
        else if(current != '*' && next != '*'){
            if(next == '/'){
                current = next;
                next = input();
            } else{
                current = input();
                next = input();
            }
        }
        else if(current != '*' && next == '*'){
            if(current == '/'){     /*opening comment*/
                active_comments++;
                //printf("Found nested comment opening, open comments so far: %d\n", active_comments);
                head = addToList(head, yylineno, token_number, "/*", "NESTED_COMMENT");
                token_number++;
                current = input();
                next = input();
            } else {
                current = next;
                next = input();
            }
        }
        
    }

    if(active_comments != 0){
        printf("Error, number of open comments %d\n", active_comments);
      return -1;
    }

}


<COMMENT><<EOF>> {
			printf("COMMENT ERROR <<Open Comment >>. \n"); 
			return -1;
		 }
<<EOF>>     {return 0;}

%%