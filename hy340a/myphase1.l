%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tokens.h"
    #define  YY_DECL int alpha_yylex(yval) void * yval;



   int line_number = 1;
   int token_number = 0;

   char *content_string;
   char *content_type;
   char *temp_content;/*added*/

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


/*=============================

void createCommentToken(struct alpha_token_t comment, char *comment_content){
    int active_comments = 1;
    int current = 0;
    int next = 0;
    struct comment_struct *comment_list;

    comment_list = (struct comment_struct *)malloc(sizeof(struct comment_struct));
    comment_list->comment_counter++;

    current = input();
    next = input();

    while((current != EOF && next != EOF) && (current != 0 && next != 0)){

        if(current == '*' && next != '*'){
            if(next == '/'){ 
                printf("Closing tag detected\n");
                active_comments--;
                if(active_comments = 0){
                    break; 
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
        
    }

}

*/





%}

%option noyywrap
%option yylineno
%option case-insensitive
%x SC_COMMENT

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

"if"		{token_number++; content_type = "KEYWORD"; return IF;}
"else"		{token_number++; content_type = "KEYWORD"; return ELSE;}
"while"		{token_number++; content_type = "KEYWORD"; return WHILE;}
"for"		{token_number++; content_type = "KEYWORD"; return FOR;}
"function"  {token_number++; content_type = "KEYWORD"; return FUNCTION;}
"return" {token_number++; content_type = "KEYWORD"; return RETURN;}
"break"     {token_number++; content_type = "KEYWORD"; return BREAK;}
"continue"  {token_number++; content_type = "KEYWORD"; return CONTINUE;}
"nil"     {token_number++; content_type = "KEYWORD"; return NIL;}
"and"       {token_number++; content_type = "KEYWORD"; return AND;}
"not"       {token_number++; content_type = "KEYWORD"; return NOT;}
"or"        {token_number++; content_type = "KEYWORD"; return OR;}
"local"     {token_number++; content_type = "KEYWORD"; return LOCAL;}
"true"      {token_number++; content_type = "KEYWORD"; return TRUE;}
"false"     {token_number++; content_type = "KEYWORD"; return FALSE;}

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
{less_equal} {token_number++; content_type = "LESS OR EQUAL OPERATOR"; return LESS_EQUAL;}
 

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


{tab}		{}
{backslash} {token_number++; content_type = "BACKSLASH"; return BACKSLASH;}
{letter} {token_number++; content_type = "LETTER"; return LETTER ;}
{quote} {token_number++; content_type = "QUOTE"; return QUOTE;} 

"\n"        {line_number++;}
{whitespace}         {}
{identifier} {token_number++; content_type = "IDENTIFIER"; return ID;}
{integer} {token_number++; content_type = "INTEGER"; return INTEGER;}
{double} { token_number++; content_type = "DOUBLE"; return DOUBLE;}
{string} {token_number++;content_type = "STRING"; return STRING;}  
{comment} {token_number++;content_type = "COMMENT"; return COMMENT;} 

"/*"	{	
 
  temp_content = yytext;
  printf("Found this in comment: %s\n", temp_content);

    /*Work */
    int active_comments = 1;
    int current = 0;
    int next = 0;
    struct comment_struct *comment_list;

    comment_list = (struct comment_struct *)malloc(sizeof(struct comment_struct));
    comment_list->comment_counter++;

    current = input();
    next = input();

    while((current != EOF && next != EOF) && (current != 0 && next != 0)){
        /*Check for / and * */
        if(current == '*' && next != '*'){
            if(next == '/'){ /*closing comments */
                printf("Closing tag detected\n");
                active_comments--;
                if(active_comments = 0){
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
            if(current == '/'){
                printf("found nested comment opening, nested comments so far: %d\n", comment_list->comment_counter);
                comment_list->comment_counter++;
                current = input();
                next = input();
            } else {
                current = next;
                next = input();
            }
        }
        
    }

printf("Checked for nested comments\n");
  

}

{unrecognized}		{
		         printf("Unrecognized character!!! Line number: %d\n", yylineno);
                         //exit(EXIT_FAILURE);
			}


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
        token = alpha_yylex();
        content_string = yytext;
        
 
        if(token == 0)
            break;


        /* TODO MAKE THE LIST AND PRINT IT */

        head = addToList(head, line_number, token_number, content_string, content_type);

    } while(token != 0);

    temp = head;
 
    fclose(yyin);
    yyterminate();

    return 0;
}
