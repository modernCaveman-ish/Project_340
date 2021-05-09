%{
#include <stdio.h>
#include <stdlib.h>
#include "hashtbl.h"
#include "quads.h"
#include <string.h>

int yyerror(char *yaccProvidedMessage);
int yylex(void);

SymbolType enum_hold = 0;

extern FILE* yyin;
extern char *yytext;
extern int yylex();
extern int yylineno;

int scope=0; /*orizoume to arxiko scope */

SymTable_T table;

int loopCounter = 0;

int step = 0;

%}

%start program
//%define parse.error verbose //gia oloklhrwmena syntaktika lathi

%union{  

	struct expr* exprvalue;
	struct call* callvalue;
	struct symbol* symbolvalue;
	int intValue;
    double realValue; 
	char *strval;
 
}


%type <strval> stmt
%type <exprvalue> lvalue member primary assignexpr call term objectdef const elist indexed indexedelem expr

%type <callvalue> callsuffix normcall methodcall

/*
%type <strval> funcname 
%type <intvalue> funcbody
%type <symbolvalue> funcdef funcprefix 
*/
%token <realValue> NUMBER

%token IF 
%token ELSE "else"
%token WHILE "while"
%token FOR "for"
%token FUNCTION "function"
%token RETURN "return"
%token BREAK "break"
%token CONTINUE "continue"
%token LOCAL "local"
%token TRUE "true"
%token FALSE "false"
%token NIL "nil"

%token ASSIGNMENT 
%token OR   
%token AND
%token NOTOP    
%token ADD  
%token UMINUS 
%token SUB 
%token MUL  
%token DIV 
%token MOD  
%token EQ 
%token DIF 
%token INC   
%token DEC 

%token GR 
%token GREQ 
%token LESS 
%token LESSEQ 

%token LEFT_CURLY_BRACE "{"
%token RIGHT_CURLY_BRACE "}"
%token LEFT_BRACKET "LEFT_BRACKET"
%token RIGHT_BRACKET "RIGHT_BRACKET"
%token RIGHT_PARENTHESIS 
%token LEFT_PARENTHESIS 
%token SEMICOLON ";"
%token COMMA ","
%token COLON ":"
%token NAMESPACE "::"
%token DOT "."
%token DOUBLE_DOT ".."

%token UNDERSCORE "_"

//%token <realValue>  NUMBER
/*%token <strval> LETTER "letter" */
/*%token <strval> QUOTE "quote" */

%token <strval> STRING "string"
%token <strval> COMMENT "comment"
%token <strval> ID 
%token <strval> MULTILINE_COMMENT "multiline comment"
%token <strval> NESTED_COMMENT "nested comment"

%token <strval> T_EOF 0   "end of file"
  
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

stmt :    				expr SEMICOLON { 

						step++;
						printf("Step: %d stmt\n", step);
						
						printf("\nMphke sto stmt\n");
						
						$$;
						/*
						if (){
						}
						*/
						
						printf("EXPRESSION SEMICOLON ");
						}
						| ifstmt{
							printf("Line %d: if Statement\n", yylineno);
						}
						| whilestmt{
							printf("Line %d: while Statement\n", yylineno);
						}
						| forstmt{
							printf("Line %d: for Statement\n", yylineno);
						}
						| returnstmt  {
							printf("Line %d: return statement\n", yylineno);
						}
						| BREAK SEMICOLON {
							printf("Line %d: break statement\n", yylineno);
							//make_stmt(&$break); 
							//$break.breaklist = newlist(nextquad()); 
							//emit(jump_op,NULL,NULL,0);
						}
						| CONTINUE SEMICOLON {
							printf("Line %d:continue statement\n", yylineno);
							//make_stmt(& $continue);
							//$continue.contlist = newlist(nextquad());
							// emit(jump_op,NULL,NULL,0); 
						}
						| block {
							printf("Line %d: block \n", yylineno);
						}
						| funcdef {
							printf("Line %d: function definition Statement\n", yylineno);
						}
						| SEMICOLON {
							printf("Line %d: Semicolon\n", yylineno);
						}
						;
			
expr:	    			assignexpr {
						step++;
						printf("Step: %d assignexpr\n", step);
					    printf("Line %d: Assignment expression: ", yylineno);
					   	$$=$1;
					   }
						| expr ADD expr	{
							
							//edw panw kati me $1 kai $2?

							printf("Mphke expr ADD expr\n");
						  	
							$$ = newexpr(arithexpr_e);
							$$->sym = newtemp();
						  	emit(add_op, $1, 0, $$,0,yylineno); //opcode,arg1,arg2,result,label,line
						}	
						| expr SUB expr	{
					      //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(sub_op, $1, $2, $$,0,yylineno);

                                                }	
						| expr MUL expr{
						  //	$$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(mul_op, $1, $2, $$,0,yylineno);
						}		
						| expr DIV expr{
					          //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(div_op, $1, $2, $$,0,yylineno);

						}	
 						| expr MOD expr{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(mod_op, $1, $2, $$,0,yylineno);
						}
	
						| expr EQ expr{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_eq_op, $1, $2, $$,0,yylineno);
						}
	

						| expr DIF expr{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_noteq_op, $1, $2, $$,0,yylineno);
						}
	

						| expr AND expr		{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(and_op, $1, $2, $$,0,yylineno);
						}
	

						| expr OR expr	{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(or_op, $1, $2, $$,0,yylineno);
						}
	

						| expr GREQ expr	{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_greatereq_op, $1, $2, $$,0,yylineno);
						}
	
	
						| expr LESS expr	{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_less_op, $1, $2, $$,0,yylineno);
						}
	
	
						| expr LESSEQ expr	{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_lesseq_op, $1, $2, $$,0,yylineno);
						}
	
	
						| expr GR expr		{
						  //    $$ = newexpr(arithexpr_e);
						  //	$$->sym = newtemp();
						  //	emit(if_greater_op, $1, $2, $$,0,yylineno);
						}
	
	
						| term {
							$$ = $1;

						}
						 ;
							
term :					LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {}
		   			    | SUB expr %prec UMINUS {
						 //  check_arith($2);
                                                 // $$ = newexpr(arithexpr_e);
					         //$$->sym = newtemp();
						//emit(uminus_op, $2, NULL, $$, 0, yylineno);//exei ena arg
					   }


					    | NOTOP expr {
						//printf("Line %d: Not Expression\n", yylineno);
						//$$ = newexpr(boolexpr_e);
				               // $$->sym = newtemp();
						//$$ = newexpr(boolexpr_e);
									    }
						| INC lvalue{printf("Line %d: ++ lvalue\n", yylineno);
						 /*	check_arith(($2);
							if ($2->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								emit(add_op, $term, newexpr_constnum(1), $$,0,yylineno);
								emit(tablesetelem_op, $2, $2->index, $$,0,yylineno);
							}
							else {
								emit(add, $lvalue, newexpr_constnum(1), $lvalue);
								$term = newexpr(arithexpr_e);
								$term->sym = newtemp();
								emit(assign, $lvalue, NULL, $term);
							} */

																	
					        }
						| lvalue INC {printf("Line %d: lvalue++\n", yylineno);
								/*	check_arith(($lvalue);
									$$ = newexpr(var_e);
									$$->sym = newtemp();
										if ($1->type == tableitem_e) {
										    expr* val = emit_iftableitem($lvalue);
										    emit(assign_op, val, NULL, $$,0,yylineno);
                                                                                    emit(add_op, val, newexpr_constnum(1), val,0,yylineno);
										    emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
										}
										else {
											emit(assign_op, $1, NULL, $term);
											emit(add_op, $l, newexpr_constnum(1), $lvalue);
										} */


						}
						| DEC lvalue{printf("Line %d: --lvalue\n", yylineno);
						   /*	check_arith(($2);
							if ($lvalue->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								emit(sub_op, $term, newexpr_constnum(1), $term);
								emit(tablesetelem_op, $lvalue, $lvalue->index, $term);
							}
							else {
								emit(sub_op, $2, newexpr_constnum(1), $2);
								$$ = newexpr(arithexpr_e);
								$$->sym = newtemp();
								emit(assign, $2, NULL, $$,0,yylineno);
							} */

                                                }
						| lvalue DEC{printf("Line %d: lvalue--\n", yylineno);
							/*	check_arith(($2);
									$$ = newexpr(var_e);
									$$->sym = newtemp();
										if ($1->type == tableitem_e) {
										    expr* val = emit_iftableitem($2);
										    emit(assign_op, val, NULL, $$,0,yylineno);
                                                                                    emit(sub_op, val, newexpr_constnum(1), val,0,yylineno);
										    emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
										}
										else {
											emit(assign_op, $1, NULL, $term);
											emit(sub_op, $l, newexpr_constnum(1), $lvalue);
										} */

							}
						| primary{
							step++;
						printf("Step: %d primary\n", step);
								printf("Line %d: Primary\n", yylineno);
							$$ = $1;

						};

assignexpr : 			lvalue ASSIGNMENT expr{
						step++;
						printf("Step: %d assignexpr: lvalue ASSIGNMENT expr\n", step);
						
							if ($1->type == tableitem_e){
								emit(
								tablesetelem_op,$1,$1->index,$3,0,yylineno);
								$$ = emit_iftableitem($1); 
								$$->type = assignexpr_e;
                             }
						     else {
								emit( 
								  assign_op,
								  $3,
								  NULL,
								  $1,0,yylineno
							    );
								$$ = newexpr(assignexpr_e);
								$$->sym = newtemp();
								emit(assign_op, $1, NULL, $$,0,yylineno);
							}    
						} ;			

primary :				lvalue {step++;
						printf("Step: %d primary lvalue\n", step);	
							$$=emit_iftableitem($1);
							}
						| call {}
						| objectdef {}
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {}
						| const {$$=$1;}
                        ;   
			
lvalue :    			ID { /*KSANA DES TO DEN BRISKEI EAN YPARXEI HDH TO KANEI KATAXWRHSH ETSI KI ALLIWS*/
							
							step++;
							printf("Step: %d lvalue ID\n", step);


							
							int dummy_scope = scope;
							int enum_scope;
							int flag = 0; /*0 gia false, 1 gia true*/
							SymbolTableEntry *e;
							//printf("Mphke ID dummy_scope = %d\n", dummy_scope);
							
							/*psakse ean yparxei genika ston table*/
							for(dummy_scope; dummy_scope >= 0; dummy_scope--){
								if(e=SymTable_contains2(table, yytext, dummy_scope)){
									printf("ID %s already exists in table\n", yytext);
									flag = 1;
									break;
								}
							}
							
							if(flag == 0){
								if(scope == 0) enum_scope = 0;
								else if(scope > 0) enum_scope = 1;

								e=SymTable_put(table, yytext, yylineno, scope, enum_scope);
							}
							$$=lvalue_expr(e);

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
						//	int contains = 0; /*0 = false || 1 = true */

							/*Kane eisagwgh sth lista afou prwta elegkseis ean einai hdh mesa*/
						//	contains = SymTable_contains2(table, yytext, 0);
							
							if( SymTable_contains2(table, yytext, 0)){
								temp = SymTable_get(table, yytext, 0);
								
								/*
								printf("Printing what found for NAMESPACE: ");
								SymTableEntry_print(temp);
								*/
								
								printf("Found\n");
							} else {
								printf("ERROR %s NOT FOUND", yytext);
								yyerror("");
								//exit(0);
							}
						}   

						| member {$$=$1;}
                        ;
			
member :				lvalue DOT ID   { printf("Line %d: lvalue.ID\n", yylineno); }
		    			| lvalue LEFT_BRACKET expr RIGHT_BRACKET {printf("Line %d: lvalue [Expression]\n\n", yylineno);}
						| call DOT ID  { printf("Line %d: Call.ID\n", yylineno); }
						| call LEFT_BRACKET expr RIGHT_BRACKET { printf("Line %d: Call [Expression]\n", yylineno);}
	                    ;
			
call : 					call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {}
						| lvalue callsuffix {}
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {}
			            ;

callsuffix : 			normcall{$$=$1;}
						| methodcall {$$=$1;}
						;
			
normcall :				LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {};

methodcall :        	DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {};

elists:					COMMA expr elists 
						| %empty {} 
						;

elist:					expr elists 
						| %empty {} 
						;						

objectdef :				LEFT_BRACKET elist RIGHT_BRACKET | LEFT_BRACKET indexed RIGHT_BRACKET {} ;

indexeds:				indexeds COMMA indexedelem 
						| %empty ;

indexed:				indexedelem indexeds
						;

indexedelem :		 	LEFT_CURLY_BRACE expr COLON expr RIGHT_CURLY_BRACE {};

block :				 	LEFT_CURLY_BRACE {++scope;} statements RIGHT_CURLY_BRACE {
								SymTable_hide(table, scope--);
								//printf("Line %d: Block\n", yylineno);
								};
 /*                                                                
funcname:                            ID{};
funcprefix:                          FUNCTION funcname{
						
							$funprefix = newsymbol($funcname, function_s);
							$funcprefix.iaddress = nextquadlabel(); 
							emit(funcstart, $funcprefix, NULL, NULL);
							push(scopeoffsetstack, currscopeoffset()); 
							enterscopespace(); 
							resetformalargsoffset(); 
				    };
funcargs:                          LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS {
						       // enterscopespace(); 
					              //  resetfunctionlocalsoffset();
				     };
funcbody:                           block{
						//$funcbody = currscopeoffset(); 
						//existscopespace();
				    };
funcstart:                          {};
funcend:                            {};
funcdef:                            funcprefix funcargs funcstart funcbody funcend{
				     
					//existscopespace();  Exiting function definition space
					//$funcprefix.totalLocals = $funcbody;  Store #locals in symbol entry
					//int offset = pop_and_top(scopeoffsetStack);  pop and get pre scope offset
					//restorecurrscopeoffset(offset);  Restore previous scope offset
					//$funcdef = $funcprefix;  The function definition returns the symbol
					//emit(funcend, $funcprefix, NULL, NULL);
					
					}; 
                                      
 */


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

const :				 	NUMBER  {$$=newexpr_constnum($1); printf("\n\n%f\n\n", $1);}
						| STRING { printf("Line %d: String\n", yylineno);
							$$=newexpr_conststring($1);
						}
						| NIL {printf("Line %d: Nil\n", yylineno);
							$$=newexpr_constnil();
						}
                        | TRUE {printf("Line %d: True\n", yylineno);
							$$=newexpr_constbool(1);
						}
						| FALSE {printf("Line %d: False\n", yylineno);
							$$=newexpr_constbool(0);
						}

                        ;

idlists:				idlists COMMA ID {
							
							
							enum_hold = FORMAL;
							//printf("Putting in function argument variable\n");
							//printf("%d\n", scope);

							/*
                            void SymTable_hide(SymTable_T oSymTable,int scope);
                            for(dummy_scope; dummy_scope >= 0; dummy_scope--){
                                if(SymTable_contains2(table, yytext, dummy_scope)){
                                    printf("ID %s already exists in table\n", yytext);
                                    printf("Perase to hide ? An nai den tha fenetai lgk kati");
                                    flag = 1;
                                    break;
                                }
                            }
                    		*/    

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

whilestart: 				WHILE {}
					{
					    //	$whilestart = nextquad();
					}
whilecond:				LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {}
					{  /*
						emit(if_eq, $expr, newexpr_constbool(1), nextquad() + 2);
						$whilecond = nextquad();
						emit(jump, NULL, NULL, 0); */
					}
					;

whilestmt :			 	WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
					 /*	
						emit(jump, NULL, NULL, $whilestart);
						patchlabel($whilecond, nextquad());
						patchlist($stmt.breaklist, nextquad());
						patchlist($stmt.contlist, $whilestart); */
					} ;

forstmt :			    FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt ;

returnstmt :		    RETURN SEMICOLON {printf("Line %d: Return expression\n", yylineno);
						//emit(ret_op, NULL, NULL, NULL, 0, yylineno);
					        }
						| RETURN expr SEMICOLON {
							printf("Line %d: Return expression\n", yylineno);
							// emit(return_op, $expr); 
						}
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
Quad_Print();
    fclose(yyin);
    return 0;
}
