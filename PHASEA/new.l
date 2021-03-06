%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tokens.h"


int line_number = 1;
int token_number = 0;

char *content_string;
char *content_type;


%}

%option noyywrap
%option yylineno
%option case-insensitive


/* regex */

/*keywords*/

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

digit [0-9]
integer {digit}+
double integer.integer+
newline		"\\n"
whitespace  " "	
tab		"\\t"
backslash	"\\"
underscore \\_
letter [a-z A-Z]
quote \"
string	({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})


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
multiple_line_comment_start "/*"
multiple_line_comment_end "*/"


%%


{if}		{token_number++; content_type = "IF KEYWORD"; return IF;}
{else}		{token_number++; content_type = "ELSE KEYWORD"; return ELSE;}
{while}		{token_number++; content_type = "WHILE KEYWORD"; return WHILE;}
{for}		{token_number++; content_type = "KEYWORD"; return FOR;}
{function}  {token_number++; content_type = "KEYWORD"; return FUNCTION;}
{return} {token_number++; content_type = "KEYWORD"; return RETURN;}
{break}     {token_number++; content_type = "KEYWORD"; return BREAK;}
{continue}  {token_number++; content_type = "KEYWORD"; return CONTINUE;}
{and}       {token_number++; content_type = "KEYWORD"; return AND;}
{not}       {token_number++; content_type = "KEYWORD"; return NOT;}
{or}        {token_number++; content_type = "KEYWORD"; return OR;}
{local}     {token_number++; content_type = "KEYWORD"; return LOCAL;}
{true}      {token_number++; content_type = "KEYWORD"; return TRUE;}
{false}     {token_number++; content_type = "KEYWORD"; return FALSE;}


{assignment} {token_number++; content_type = "ASSINGMENT OPERATOR"; return ASSINGMENT;}
{add} {token_number++; content_type = "ADD OPERATOR"; return ADD;}
{sub} {token_number++; content_type = "SUBTRACT OPERATOR"; return SUBTRACT;}
{mul} {token_number++; content_type = "MULTIPLYOPERATOR"; return MULTIPLY;}
{div} {token_number++; content_type = "DIVISION OPERATOR"; return DIVISION;}
{mod} {token_number++; content_type = "MODULO OPERATOR"; return MODULO;}
{icreament1} {token_number++; content_type = "INCREAMENTBY1 OPERATOR"; return INCREAMENT1;}
{decreament} {token_number++; content_type = "DECREAMENTBY1 OPERATOR"; return DECREAMENT;}
{greater} {token_number++; content_type = "GREATER THAN OPERATOR"; return GREATER_THAN;}
{less} {token_number++; content_type = "LESS THAN OPERATOR"; return LESS_THAN;}
{equal} {token_number++; content_type = "EQUAL OPERATOR";return EQUAL;}
{diff} {token_number++; content_type = " DIFFERENT OPERATOR"; return DIFFERENT;}
{greater_equal} {token_number++; content_type = " GREATER OR EQUAL OPERATOR"; return GREATER_EQUAL;}
{less_equal} {token_number++; content_type = "LESS OR EQUALOPERATOR"; return LESS_EQUAL;}
 

{left_curly_brace} {token_number++; content_type = "LEFT CURLY BRACE"; return LEFT_CURLY_BRACE;}
{right_curly_brace} {token_number++; content_type = "RIGHT CURLY BRACE"; return RIGHT_CURLY_BRACE;}
{leftbracket} {token_number++; content_type = "LEFT BRACKET"; return LEFT_BRACKET;}
{rightbracket} {token_number++; content_type = "RIGHT BRACKET"; return RIGHT_BRACKET;}
{right_parenthesis} {token_number++; content_type = "RIGHT PARENTHESIS"; return RIGHT_PARENTHESIS;}
{left-parenthesis} {token_number++; content_type = "LEFT PARENTHESIS"; return LEFT_PARENTHESIS;}
{semicolon} {token_number++; content_type = "SEMICOLON"; return SEMICOLON;}
{comma} {token_number++; content_type = "COMMA"; return COMMA;}
{colon} {token_number++; content_type = "COLON"; return COLON;}
{namespace} {token_number++; content_type = "NAMESPACE"; return NAMESPACE;}
{dot} {token_number++; content_type = "DOT"; return DOT;}
{double_dot} {token_number++; content_type = "DOUBLE DOT"; return DOUBLE_DOT;}
{whitespace}  {} 
{tab}		{}
{backslash} {token_number++; content_type = "BACKSLASH"; return BACKSLASH;}
{underscore} {token_number++; content_type = "UNDERSCORE"; return UNDERSCORE;}
{digit} {token_number++; content_type = "DIGIT"; return DIGIT;}
{integer} {token_number++; content_type = "INTEGER"; return INTEGER;}
{double} { content_type = "DOUBLE"; return DOUBLE;}
{letter} {token_number++; content_type = "LETTER"; return LETTER ;}
{quote} {token_number++; content_type = "QUOTE"; return QUOTE;}
{string} {content_type = "STRING"; return STRING;}
{comment} {content_type = "SINGLE LINE COMMENT"; return SINGLE_LINE_COMMENT;}

"\n"        {line_number++;}

"/*"([^*]|\*+[^*/])*\*+"/"      {token_number++; content_type = "MULTILINE_COMMENT"; return MULTILINE_COMMENT;  /*multiline comment but not nested*/}


<<EOF>>     {return 0;}

%%
void printToken(){

}

/*
void printTokenList(struct alpha_token_t* head){

  struct alpha_token_t* temp = head;

 while(temp != NULL){
  printf("in line %d token_number %d", temp->numLine, temp->numToken);
  printf(" string_content: %s  content_type: %s\n", temp->content, temp->type);
  temp = temp->next;
 }

}
*/

struct alpha_token_t* addToList(struct alpha_token_t* head, int line_number, int token_number, char* content_string, char* content_type){

  struct alpha_token_t* temp;
  
  temp = head;

  printf("%d: #%d", line_number, token_number);
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

    //printf("Printing List...\n");

    //printTokenList(temp);

    
    fclose(yyin);
    yyterminate();

    return 0;
}
