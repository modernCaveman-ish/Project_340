%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "syntax.tab.h"

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
  
  /*
  printf("%d: #%d", yylineno, token_number);
  printf(" \"%s\" %s\n", content_string, content_type); 
  */

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

%}

%option noyywrap
%option yylineno
%option case-insensitive

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

{quote} {token_number++; content_type = "QUOTE"; return QUOTE;} 

"\n"        {line_number++;}
{whitespace}         {}
{integer} {token_number++; content_type = "INTEGER"; return NUMBER;}
{double} { token_number++; content_type = "DOUBLE"; return NUMBER;}
{string} {token_number++;content_type = "STRING";  return STRING;}  


{comment}    {

        head = addToList(head, yylineno, token_number, "//", "ONE_LINE_COMMENT");
   	}


"/*"	{	
 
    head = addToList(head, yylineno, token_number, "/*", "MULTI_LINE_COMMENT");
    token_number++;
    
  temp_content = yytext;

   // printf("Brhke multilinecomment\n");

    /*Work */
    static int active_comments = 1;
    int current = 0;
    int next = 0;
    struct comment_struct *comment_list;

    //  printf("Brhke multilinecomment\n");

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
                //printf("Closing tag detected, active_comments: %d\n", active_comments);
                active_comments--;
                current = input();
                next = input();
                if(active_comments == 0){
                    break; /*End of comments*/
                } else if(active_comments != 0){
                    //content_type = NESTED_COMMENT;
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
        printf("End of Comments detected, Number of active_comments %d\n", active_comments);

    }

}


<<EOF>>     {return 0;}

%%

