%{
#include <stdio.h>
#include <stdlib.h>
#include "hashtbl.h"
#include <string.h>

int yyerror(char *yaccProvidedMessage);
int yylex(void);

SymbolType enum_hold = 0;

extern FILE* yyin;
extern char *yytext;
extern int yylex();
extern int yylineno;

int scope=0; /*orizoume to arxiko scope */
//HASHTBL *hashtbl; /*dhlwnoume ton hashtable*/

SymTable_T table;

%}

%start program
//%define parse.error verbose //gia oloklhrwmena syntaktika lathi

%union{  
	int intValue;
    double realValue; 
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

%token <strval> ASSIGNMENT 
%token <strval> OR   
%token <strval> AND
%token <strval> NOTOP    
%token <strval> ADD  
%token <strVal> UMINUS 
%token <strval> SUB 
%token <strval> MUL  
%token <strval> DIV 
%token <strval> MOD  
%token <strval> EQ 
%token <strval> DIF 
%token <strval> INC   
%token <strval> DEC 

%token <strval> GR 
%token <strval> GREQ 
%token <strval> LESS 
%token <strval> LESSEQ 

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

%token <strval> UNDERSCORE "_"

%token<strval>  NUMBER
%token <strval> LETTER "letter"
%token <strval> QUOTE "quote"
%token <strval> STRING "string"
%token <strval> COMMENT "comment"
%token <strval> ID 
%token <strval> MULTI_LINE_COMMENT "multiple comm"
%token <strval> ONE_LINE_COMMENT "single line comm"
%token <strval> NESTED_COMMENT "nested comm"


%token <strval> T_EOF 0   "end of file"

%type <strval> program stmt expr  term assignexpr primary lvalue member call callsuffix normcall methodcall elists
%type <strval> elist objectdef indexed indexedelem block funcdef const idlist ifstmt whilestmt forstmt returnstmt    

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

%%

//syntaktikoi kanones-grammatikh

program : 				statements {printf("Start Program\n");}
						;


statements: 			statements stmt {}
						| {} %empty;

stmt :    				expr SEMICOLON {printf("EXPRESSION SEMICOLON ");}
						| ifstmt// {printf("Line %d: if Statement\n", yylineno);}
						| whilestmt {printf("Line %d: while Statement\n", yylineno);}
						| forstmt   {printf("Line %d: for Statement\n", yylineno);}
						| returnstmt  {printf("Line %d: return statement\n", yylineno);}
						| BREAK SEMICOLON  {printf("Line %d: break statement\n", yylineno);}
						| CONTINUE SEMICOLON {printf("Line %d:continue statement\n", yylineno);}
						| block //{printf("Line %d: block \n", yylineno);}
						| funcdef //{printf("Line %d: function definition Statement\n", yylineno);}
						| SEMICOLON {printf("Line %d: Semicolon\n", yylineno);}
						;
			
expr:	    			assignexpr {printf("Line %d: Assignment expression: ", yylineno);}
						| expr ADD expr		
						| expr SUB expr		
						| expr MUL expr		
						| expr DIV expr		
 						| expr MOD expr		
						| expr EQ expr
						| expr DIF expr
						| expr AND expr	
						| expr OR expr
						| expr GREQ expr	
						| expr LESS expr	
						| expr LESSEQ expr	
						| expr GR expr		
						| term ;
							
term :					LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
		   			    | SUB expr %prec UMINUS
					    | NOTOP expr 	{printf("Line %d: Not Expression\n", yylineno);}
						| INC lvalue    {printf("Line %d: ++ lvalue\n", yylineno);}
						| lvalue INC    {printf("Line %d: lvalue++\n", yylineno);}
						| DEC lvalue   	{printf("Line %d: --lvalue\n", yylineno);}
						| lvalue DEC    {printf("Line %d: lvalue--\n", yylineno);}
						| primary   
			            ;

assignexpr : 			lvalue ASSIGNMENT expr ;			

primary :				lvalue
						| call
						| objectdef
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS
						| const
                        ;   
			
lvalue :    			ID { /*KSANA DES TO DEN BRISKEI EAN YPARXEI HDH TO KANEI KATAXWRHSH ETSI KI ALLIWS*/
							int dummy_scope = scope;
							int enum_scope;
							int flag = 0; /*0 gia false, 1 gia true*/

							//printf("Mphke ID dummy_scope = %d\n", dummy_scope);
							
							/*psakse ean yparxei genika ston table*/
							for(dummy_scope; dummy_scope >= 0; dummy_scope--){
								if(SymTable_contains2(table, yytext, dummy_scope)){
									printf("ID %s already exists in table\n", yytext);
									flag = 1;
									break;
								}
							}
							
							if(flag == 0){
								if(scope == 0) enum_scope = 0;
								else if(scope > 0) enum_scope = 1;

								SymTable_put(table, yytext, yylineno, scope, enum_scope);
							}
						}
						| LOCAL ID{
								//printf("\n\n%s\n\n", yytext);
								struct SymbolTableEntry *tmp;
									
									if(scope!=0 ){
										tmp = SymTable_get(table,yytext,0);
										if(tmp !=NULL && tmp->type == LIBFUNC && scope != 0){
											yyerror("ERROR LIBFUNC");
											exit(0);
										}
									}

								SymbolType type = 0;
								tmp = SymTable_get(table,yytext,scope);

									if(tmp == NULL){
										if(scope==0){ type = GLOBAL; } else { type = LOCAL2; }

										SymTable_put(table, yytext, yylineno, scope, type );
									}
									
								}           


						| NAMESPACE ID  { 				/*GLOBAL*/
							struct SymbolTableEntry *temp;
							int contains = 0; /*0 = false || 1 = true */

							/*Kane eisagwgh sth lista afou prwta elegkseis ean einai hdh mesa*/
							contains = SymTable_contains2(table, yytext, 0);
							
							if(contains == 1){
								temp = SymTable_get(table, yytext, 0);
								
								/*
								printf("Printing what found for NAMESPACE: ");
								SymTableEntry_print(temp);
								*/
								
								printf("Found\n");
							} else if(contains == 0) {
								printf("ERROR %s NOT FOUND", yytext);
								yyerror("");
								//exit(0);
							}
						}   

						| member
                        ;
			
member :				lvalue DOT ID   { printf("Line %d: lvalue.ID\n", yylineno); }
		    			| lvalue LEFT_BRACKET expr RIGHT_BRACKET {printf("Line %d: lvalue [Expression]\n\n", yylineno);}
						| call DOT ID  { printf("Line %d: Call.ID\n", yylineno); }
						| call LEFT_BRACKET expr RIGHT_BRACKET { printf("Line %d: Call [Expression]\n", yylineno);}
	                    ;
			
call : 					call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
						| lvalue callsuffix
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
			            ;

callsuffix : 			normcall
						| methodcall
						;
			
normcall :				LEFT_PARENTHESIS elist RIGHT_PARENTHESIS ;

methodcall :        	DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS ;

elists:					COMMA expr elists 
						| %empty {} 
						;

elist:					expr elists 
						| %empty {} 
						;						

objectdef :				LEFT_BRACKET elist RIGHT_BRACKET | LEFT_BRACKET indexed RIGHT_BRACKET ;

indexeds:				indexeds COMMA indexedelem 
						| %empty ;

indexed:				indexedelem indexeds
						;

indexedelem :		 	LEFT_CURLY_BRACE expr COLON expr RIGHT_CURLY_BRACE ;

block :				 	LEFT_CURLY_BRACE {++scope;} statements RIGHT_CURLY_BRACE {
								SymTable_hide(table, scope--);
								//printf("Line %d: Block\n", yylineno);
                                                                };

funcdef :			 	FUNCTION ID { 
						struct SymbolTableEntry *tmp1;
						/*
						tmp1 = SymTable_get(table,yytext,0);
							if(tmp1 !=NULL && tmp1->type == LIBFUNC){
								yyerror("ERROR LIBFUNC");
								exit(0);
							}
						*/
							
							if(SymTable_contains2(table, yytext, scope) == 0){
									SymTable_put(table, yytext, yylineno, scope, USERFUNC);
							}else {
										tmp1 = SymTable_get(table, yytext, scope);
										if(tmp1->type == LIBFUNC){
											yyerror("SHADOWS LIBFUNC");
											//exit(0);
										} else if(tmp1->type == USERFUNC){
											printf("ERROR USERFUNC %s ALREADY DEFINED\n", yytext);
										}else{
											printf("ERROR VARIABLE WITH THAT NAME %s IS ALREADY DEFINED\n", yytext);
											//exit(0);
										}
							}

								} LEFT_PARENTHESIS {scope++;} idlist RIGHT_PARENTHESIS  {scope--;} block
						| FUNCTION {
							printf("Line %d: no name function at scope %d \n", yylineno, scope);
							//create temp name
							//char *funcname;
							char tempname[200]="_f";// tyxaio wste na nai arketa megalo na xwresei olo to onoma
							int number=1;
							struct SymbolTableEntry *tmp1;//insert to symbol table
						//while (tmp1!=NULL){
							int result;//epistrefei to length to converted string
							//h sprintf metatrepei ton integer number se string
							result=sprintf(tempname,"_f%u",number);//opou to number prpei na ayksanetai
						        printf("to mikos einai %d",result);
							//desmeysh mnhmhs gia to onoma ,den kseroume to sizee afou to number den einai stathero
							//funcname=(char*)malloc (3+numbers)*sizeof(char)); //_f mazi me \0 kai numbers einai ta psifia dipla
							//funcname= (char*)malloc(sizeof(char)*(3+numbers));
							//tempname = funcname;
						        int i;
		                                           //for( i = 0; i <= 200; i++) {
		                                             //   	tempname[i]++;
	                                                	//}
		                                            //  tempname[i]++;//gia na mpei sto telos o termatikos xarakthras sthn epomenh thesi
		                                           //  *tempname = '\0';


							SymTable_put(table, tempname, yylineno, scope, USERFUNC);
							number++;

						//}
							

						} LEFT_PARENTHESIS {scope++;} idlist RIGHT_PARENTHESIS {scope--;} block ;

const :				 	NUMBER 
						| STRING { printf("Line %d: String\n", yylineno);}
						| NIL {printf("Line %d: Nil\n", yylineno);}
                                                | TRUE {printf("Line %d: True\n", yylineno);}
						| FALSE {printf("Line %d: False\n", yylineno);}

                        ;

idlists:				idlists COMMA ID {
							
							
							enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
							//printf("%d\n", scope);
							if(SymTable_contains2(table, yytext, scope) == 0){
								struct SymbolTableEntry *tmp = SymTable_get(table,yytext,0);
								if(tmp !=NULL && tmp->type == LIBFUNC){
									yyerror("ERROR LIBFUNC");
									exit(0);
								}


								SymTable_put(table, yytext, yylineno, scope, enum_hold); 
							}else{
								yyerror ("FORMAL ERROR");
							}

				
	
						}
						| %empty ;

idlist:					ID {

						enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
                                                        // printf("%d\n", scope);
							if(SymTable_contains2(table, yytext, scope) == 0){
								struct SymbolTableEntry *tmp = SymTable_get(table,yytext,0);
								if(tmp !=NULL && tmp->type == LIBFUNC){
									yyerror("ERROR LIBFUNC");
									exit(0);
								}


								SymTable_put(table, yytext, yylineno, scope, enum_hold); 
							}else{
								yyerror ("FORMAL ERROR");
							}



						} idlists | %empty {};

ifstmt:					IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt 
						| IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt ;

whilestmt :			 	WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ;

forstmt :			    FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt ;

returnstmt :		    RETURN SEMICOLON 
						| RETURN expr SEMICOLON //{printf("Line %d: Return expression\n", yylineno);}

						;
						
%%

	int yyerror(char *yaccProvidedMessage){
		puts(yaccProvidedMessage);
		return 1;
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

    
	table = SymTable_new();

	SymTable_put(table, "print",0,0, LIBFUNC);
        SymTable_put(table, "input",0,0, LIBFUNC);
	SymTable_put(table, "objectmemberkeys",0,0, LIBFUNC);
	SymTable_put(table, "objecttotalmembers",0,0, LIBFUNC);
	SymTable_put(table, "objectcopy",0,0, LIBFUNC);
	SymTable_put(table, "totalarguments",0,0, LIBFUNC);
	SymTable_put(table, "argument",0,0, LIBFUNC);
	SymTable_put(table, "typeof",0,0, LIBFUNC);
	SymTable_put(table, "strtonum",0,0, LIBFUNC);
	SymTable_put(table, "sqrt",0,0, LIBFUNC);
	SymTable_put(table, "cos",0,0, LIBFUNC);
	SymTable_put(table, "sin",0,0, LIBFUNC);

    yyparse();
 
	SymTable_Print(table);

    fclose(yyin);
    return 0;
}
