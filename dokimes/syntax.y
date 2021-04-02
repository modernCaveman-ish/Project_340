%{
#include <stdio.h>
#include <stdlib.h>
#include "hashtbl.h"
#include "syntax.tab.h"


extern FILE* yyin;
extern int yylex();
void yyerror(const char *message);

int scope=0; /*orizoume to arxiko scope */
HASHTBL *hashtbl; /*dhlwnoume ton hashtable*/

%}

%error-verbose //gia oloklhrwmena syntaktika lathi

%union{  
  
    double numval; 
    char *strval;
  
}






%token <strval> IF "if"
%token <strval> ELSE "else"
%token <strval> WHILE "while"
%token <strval> FOR "for"
%token <strval> FUNCTION "function"
%token <strval> RETURN "return"
%token <strval> BREAK "break"
%token <strval> CONTINUE "continue"
%token <strval> LOCAL "local"
%token <strval> TRUE "true"
%token <strval> FALSE "false"
%token <strval> NIL "nil"

%token <strval> ASSIGNMENT "="
%token <strval> OROP   "||"
%token <strval> ANDOP  "&&"
%token <strval> NOTOP    "not"
%token <strval> ADD  "+"
%token<strVal> UMINUS 
%token <strval> SUB "-"
%token <strval> MUL  "*"
%token <strval> DIV "/"
%token <strval> MOD  "%"
%token <strval> EQ "=="
%token <strval> DIF "!="
%token <strval> INC   "++"
%token <strval> DEC "--"
%token <strval> GR "> "
%token <strval> GREQ ">="
%token <strval> LESS "<"
%token <strval> LESSEQ "<="


%token <strval> LEFT_CURLY_BRACE "{"
%token <strval> RIGHT_CURLY_BRACE "}"
%token <strval> LEFT_BRACKET "LEFT_BRACKET"
%token <strval> RIGHT_BRACKET "RIGHT_BRACKET"
%token <strval> RIGHT_PARENTHESIS "RIGHT_PARENTHESIS"
%token <strval> LEFT_PARENTHESIS "LEFT_PARENTHESIS"
%token <strval> SEMICOLON ";"
%token <strval> COMMA ","
%token <strval> COLON ":"
%token <strval> NAMESPACE "::"
%token <strval> DOT "."
%token <strval> DOUBLE_DOT ".."
%token <strval> WHITESPACE " "
%token <strval> TAB "    "
%token <strval> UNDERSCORE "_"

%token<strval> NUMBER
%token <strval> LETTER "letter"
%token <strval> QUOTE "quote"
%token <strval> STRING "string"
%token <strval> COMMENT "comment"
%token <strval> ID "id"
%token <strval> MULTIPLE_COMMENT "multiple comment"
%token <strval> NESTED_COMMENT "nested comment"

%token <strval> T_EOF 0   "end of file"


%type<strval> program stmt expr  term assignexpr primary lvalue member call callsuffix normcall methodcall 
%type<strval> elist objectdef indexed indexedelem block funcdef const idlist ifstmt whilestmt forstmt returnstmt 
%type <strval> closeif		   



%right      ASSIGNMENT
%left       OR
%left       AND
%nonassoc   EQ DIF
%nonassoc   GR GREQ LESS LESSEQ
%left       ADD SUB
%left       MUL DIV MOD
%right      NOTOP INC DEC UMINUS
%left       DOT DOUBLE_DOT
%left       LEFT_BRACKET RIGHT_BRACKET
%left       LEFT_PARENTHESIS RIGHT_PARENTHESIS

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%start program

%%

//syntaktikoi kanones-grammatikh

program : 				stmt {	printf(" Start Program\n");	 } ;

stmt :    				expr SEMICOLON
						|ifstmt {  printf("Line %d: if Statement\n", yylineno);}
						|whilestmt { printf("Line %d: while Statement\n", yylineno); }
						|forstmt   { printf("Line %d: for Statement\n", yylineno); }
						|returnstmt  { printf("Line %d: return statement\n", yylineno); }
						|BREAK SEMICOLON  { printf("Line %d: break statement\n", yylineno); }
						|CONTINUE SEMICOLON {printf("Line %d:continue statement\n", yylineno); }
						|block {printf("Line %d: block \n", yylineno);}
						|funcdef { printf("Line %d: function definition Statement\n", yylineno);}
							;
			
expr :    				 assignexpr printf("Line %d: Assignment expression\n", yylineno);
						|expr op expr {}
 						| term ;
			
op : 					ADD
						| SUB 
						| MUL
						| DIV
						| MOD
						| GR
						| GREQ 
						| LESS
						| LESSEQ
						| EQ
						| DIF 
						| ANDOP 
						| OROP		

term :					 LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
		   			        | SUB expr %prec UMINUS
					        | NOTOP expr 	{printf("Line %d: Not Expression\n", yylineno);}
						| INC lvalue    {printf("Line %d: ++ lvalue\n", yylineno);}
						| lvalue INC     {printf("Line %d: lvalue++\n", yylineno);}
						| DEC lvalue   	{printf("Line %d: --lvalue\n", yylineno);}
						| lvalue DEC    {printf("Line %d: lvalue--\n", yylineno);}
						| primary   {printf("Line %d: Primary\n", yylineno);}
			                        ;

assignexpr : 			        lvalue ASSIGNMENT expr ;			


primary :				lvalue
						| call
						| objectdef
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS
						| const
                                                ;   
			
lvalue :    			        ID
						| LOCAL ID           
						| NAMESPACE ID     
						| member
                                                ;
			
member :				 lvalue DOT ID   { printf("Line %d: lvalue.ID\n", yylineno); }
		    			        | lvalue LEFT_BRACKET expr RIGHT_BRACKET {printf("Line %d: lvalue [Expression]\n\n", yylineno);}
						| call DOT ID  {	printf("Line %d: Call.ID\n", yylineno);}
						| call LEFT_BRACKET expr RIGHT_BRACKET {	printf("Line %d: Call [Expression]\n", yylineno);}
                                                ;
			
call : 					call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
						| lvalue callsuffix
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
			                        ; 
callsuffix : 			       normcall
						| methodcall
						;
			
normcall :				 LEFT_PARENTHESIS elist RIGHT_PARENTHESIS

methodcall :        	                 DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS 

elist :					 LEFT_BRACKET expr LEFT_BRACKET COMMA expr RIGHT_BRACKET  RIGHT_BRACKET

objectdef :				 LEFT_BRACKET LEFT_BRACKET elist | indexed RIGHT_BRACKET RIGHT_BRACKET

indexed :			   	 LEFT_BRACKET indexedelem LEFT_BRACKET COMMA indexedelem RIGHT_BRACKET  RIGHT_BRACKET

indexedelem :		 	         LEFT_CURLY_BRACE expr COLON expr RIGHT_CURLY_BRACE

block :				 	 LEFT_BRACKET stmt RIGHT_BRACKET 

funcdef :			 	FUNCTION LEFT_BRACKET ID RIGHT_BRACKET LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block

const :				 	NUMBER 
						| STRING
						| NIL
						| TRUE
 						| FALSE
                                        ;

idlist :		             	LEFT_BRACKET ID LEFT_BRACKET COMMA ID RIGHT_BRACKET  RIGHT_BRACKET ;

ifstmt :			 	IF LEFT_PARENTHESIS
					 expr RIGHT_PARENTHESIS stmt
					 closeif ;

closeif:                                 ELSE   {scope++;} 
					  stmt  | %empty  {}
                                          ; 

whilestmt :			 	WHILE LEFT_PARENTHESIS {scope++;}
					 expr RIGHT_PARENTHESIS stmt  

forstmt :			    FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt 

returnstmt :		               RETURN ;



%%



int main(int argc, char* argv[]) {


 if(!(hashtbl = hashtbl_create(10, NULL))) {
        fprintf(stderr, "ERROR: hashtbl_create() failed!\n");
        exit(EXIT_FAILURE);
    }
    


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

    yyparse();


 
    fclose(yyin);
    

    return 0;
}



