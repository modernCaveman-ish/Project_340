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

int loopcounter = 0;
int loopstart;
int loopend;
extern unsigned int currQuad;

//struct breaklist* breaklist;
//struct continuelist* continuelist;  

//struct stmt_t* stmt_t;
//stmt_t = (struct stmt_t *)malloc(sizeof(struct stmt_t));

//stmt_t.breaklist = (struct breaklist*)malloc(sizeof(struct breaklist));
//stmt_t.continuelist = (struct continuelist*)malloc(sizeof(struct continuelist));


%}

%start program
//%define parse.error verbose //gia oloklhrwmena syntaktika lathi

%union{  

	struct expr* exprvalue;
	struct call* callvalue;
	struct SymbolTableEntry * symbolvalue;
	int intValue;
    double realValue; 
	char *strval;
	struct stmt_t* stmt_t;
 
}


%type <stmt_t> stmt
%type <exprvalue> lvalue member primary assignexpr call term objectdef const elist indexed indexedelem expr

%type <callvalue> callsuffix normcall methodcall
%type <intValue> ifprefix elseprefix

%type <intValue> whilestart 
%type <intValue> whilecond loopstmt
/*
%type <intValue> forprefix M N
%type <strval> funcname 
%type <intvalue> funcbody
%type <symbolvalue> funcdef funcprefix */

%token <strval> IF 
%token ELSE
%token WHILE 
%token FOR 
%token FUNCTION 
%token RETURN 
%token BREAK 
%token CONTINUE 
%token LOCAL 
%token TRUE 
%token FALSE 
%token NIL

%token <realValue> NUMBER

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

%token <strval> STRING "string"
%token <strval> COMMENT "comment"
%token <strval> ID 
%token <strval> MULTIPLE_COMMENT "multiple comment"
%token <strval> NESTED_COMMENT "nested comment"

%token <strval> T_EOF 0   "end of file"
  
%right      ASSIGNMENT
%left       OR
%left       AND
%nonassoc   ELSE
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
					//	$$ = new_stmt(stmt);
						;
					
statements: 			statements stmt {};
						| {} %empty;
 
stmt :    				expr SEMICOLON { 
						
						printf("EXPRESSION SEMICOLON ");
						}
						| if{
							printf("Line %d: if Statement\n", yylineno);
						}
						| while{
							printf("Line %d: while Statement\n", yylineno);
						}
						| FOR{
							printf("Line %d: for Statement\n", yylineno);
						}
						| returnstmt  {
							printf("Line %d: return statement\n", yylineno);
						}
						| BREAK SEMICOLON {
							
							//printf("Line %d: break statement\n", yylineno);
							//make_stmt(&$1); //edw den pairnei ena struct stmt_t*?
							//make_stmt(stmt_t.breaklist);
							//stmt_t.breaklist = newlist(nextquad());
				 			//emit(jump_op, NULL, NULL, NULL, 0, yylineno);

							 if(loopcounter==0){
								printf("ERROR in line %d: BREAK outside of the loop \n", yylineno);
							}

							//$break.breaklist = newlist(nextquad()); emit(jump,NULL,NULL,0); 

						}
						| CONTINUE SEMICOLON {
							//printf("Line %d:continue statement\n", yylineno);
							
							if(loopcounter==0){
								printf("ERROR in line %d: CONTINUE outside of the loop \n", yylineno);
							}
							
							//make_stmt(& $continue);
							//$continue.contlist = newlist(nextquad()); 		
				      		//emit(jump_op, NULL, NULL, NULL, 0, yylineno);

							//$continue.contlist = newlist(nextquad()); emit(jump,NULL,NULL,0); 

						}

					//stmts->stmt{$stms=$stmt;}
					//stmts->stmt{$$=$1;}
					//stmts->$$=$1;	

						| block {
							printf("Line %d: block \n", yylineno);
						}
						| funcdef {
							printf("Line %d: function definition Statement\n", yylineno);
						}
						| SEMICOLON {
							//printf("Line %d: Semicolon\n", yylineno);
						}
						;
			
expr:	    			assignexpr {
					    printf("Line %d: Assignment expression\n", yylineno);
					   	$$=$1;
					   }
						| expr ADD expr	{	
						        printf("Line %d: Add expression\n", yylineno);
					  	
							$$ = newexpr(arithexpr_e);
							$$->sym = newtemp();
						  	emit(add_op, $1, $3, $$,0,yylineno); 
						  
						}	
						| expr SUB expr	{
					        $$ = newexpr(arithexpr_e);
						  	$$->sym = newtemp();
						  	emit(sub_op, $1, $3, $$,0,yylineno);

                                                }	
						| expr MUL expr{
						  	$$ = newexpr(arithexpr_e);
						  	$$->sym = newtemp();
						  	emit(mul_op, $1, $3, $$,0,yylineno);
						}		
						| expr DIV expr{
					                $$ = newexpr(arithexpr_e);
						  	$$->sym = newtemp();
						  	emit(div_op, $1, $3, $$,0,yylineno);

						}	
 						| expr MOD expr{
						        $$ = newexpr(arithexpr_e);
						 	$$->sym = newtemp();
						 	emit(mod_op, $1, $3, $$,0,yylineno);
						}
	
						| expr EQ expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;
							tmpexprtrue = newexpr_constbool(1);//true
							tmpexprfalse = newexpr_constbool(0);//false 	
							//tmpexprfalse->boolConst = 0;
							//tmpexprtrue->boolConst = 1;

							emit(if_eq_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno);						     
							
		
						}
						| expr DIF expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_noteq_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno);						
						}
	
						| expr AND expr		{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();							
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(and_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno); 						
	
						}
						| expr OR expr	{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(or_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno);					
	
						}
						| expr GREQ expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_greatereq_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno);					
						}
	
						| expr LESS expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_less_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op, tmpexprfalse,NULL, $$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op,tmpexprtrue,NULL,$$,0,yylineno); 
						}
	
						| expr LESSEQ expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();

							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_lesseq_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op,tmpexprfalse,NULL,$$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno);
							emit(assign_op, tmpexprtrue,NULL, $$,0,yylineno); 						
						}
	
	
						| expr GR expr{
						        $$ = newexpr(boolexpr_e);
						        $$->sym = newtemp();
							
							struct expr* tmpexprtrue;
							struct expr* tmpexprfalse;

							tmpexprtrue = newexpr_constbool(1);
							tmpexprfalse = newexpr_constbool(0); 

							emit(if_greater_op, $1 , $3,$$, nextquad()+3,yylineno);
							emit(assign_op,tmpexprfalse,NULL,$$,0,yylineno);
							emit(jump_op,NULL,NULL,NULL, nextquad()+2,yylineno); 
							emit(assign_op, tmpexprtrue,NULL, $$,0,yylineno); 								
						}
	
	
						| term {
							$$ = $1;
						}
						 ;
							
term :					LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {$$ = $2;}
		   			    | SUB expr %prec UMINUS {
						        check_arith($2);
                                			$$ = newexpr(arithexpr_e);
					            	$$->sym = newtemp();
						      emit(uminus_op, $2, NULL, $$, 0, yylineno);
						}
					    | NOTOP expr {
						  printf("Line %d: Not Expression\n", yylineno);
						        $$ = newexpr(boolexpr_e);
				                        $$->sym = newtemp();
						        emit(not_op, $2, NULL, $$, 0, yylineno);
				                 }
						| INC lvalue{
							printf("Line %d: ++ lvalue\n", yylineno);
						 	check_arith($2);
							if ($2->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);
								emit(add_op, $$, tmpexpr, $$,0,yylineno);
								emit(tablesetelem_op, $2, $2->index, $$,0,yylineno);
							}
							else {
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);

								emit(add_op, $2,tmpexpr, $2,0,yylineno);
								$$ = newexpr(arithexpr_e);
								$$->sym = newtemp();
								emit(assign_op, $2, NULL, $$,0,yylineno);
							} 

						}
						|lvalue INC {        
							       printf("Line %d: lvalue++\n", yylineno);
							       check_arith($1);
							       $$ = newexpr(var_e);
								$$->sym = newtemp();
								if ($1->type == tableitem_e) {
								     struct expr* tmpexpr;
						                     tmpexpr = newexpr_constnum(1);
	 	
							             expr* val = emit_iftableitem($1);
								     emit(assign_op, val, NULL, $$,0,yylineno);
                                                                     emit(add_op, val,tmpexpr, val,0,yylineno);
								     emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
								}
								else {
									struct expr* tmpexpr;
						                        tmpexpr = newexpr_constnum(1);
									emit(assign_op, $1, NULL, $$,0,yylineno);
									emit(add_op, $1, tmpexpr, $1,0,yylineno);
								}  
                                                }
						| DEC lvalue {
						         printf("Line %d: --lvalue\n", yylineno);
						    	check_arith($2);
							if ($2->type == tableitem_e) {
								$$ = emit_iftableitem($2);
								struct expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);
								emit(sub_op, $$,tmpexpr, $$,0,yylineno);
								emit(tablesetelem_op, $2, $2->index, $$,0,yylineno);
							}
							else {
								expr* tmpexpr;
						                tmpexpr = newexpr_constnum(1);

								emit(sub_op, $2,tmpexpr, $2,0,yylineno);
								$$ = newexpr(arithexpr_e);
								$$->sym = newtemp();
								emit(assign_op, $2, NULL, $$,0,yylineno);
							}  

                                                }
						|lvalue DEC{
						        printf("Line %d: lvalue--\n", yylineno);
						
							       check_arith($1);
							       $$ = newexpr(var_e);
								$$->sym = newtemp();
								if ($1->type == tableitem_e) {
								     struct expr* tmpexpr;
						                     tmpexpr = newexpr_constnum(1);
	 	
							             expr* val = emit_iftableitem($1);
								     emit(assign_op, val, NULL, $$,0,yylineno);
                                                                     emit(add_op, val,tmpexpr, val,0,yylineno);
								     emit(tablesetelem_op, $1, $1->index, val,0,yylineno);
								}
								else {
									struct expr* tmpexpr;
						                        tmpexpr = newexpr_constnum(1);
									emit(assign_op, $1, NULL, $$,0,yylineno);
									emit(sub_op, $1, tmpexpr, $1,0,yylineno);
								}  


						}
						| primary{//printf("Line %d: Primary\n", yylineno);
							$$ = $1;
						};

assignexpr : 			lvalue ASSIGNMENT expr{
						
							if ($1->type == tableitem_e){
								emit(
								tablesetelem_op,$1,$1->index,$3,0,yylineno);
								$$ = emit_iftableitem($1); 
								$$->type = assignexpr_e;
                                                         }
						     else {
								emit( 
								  assign_op,$3,
								  NULL,
								 $1,0,yylineno
							    );
								$$ = newexpr(assignexpr_e);
								$$->sym = newtemp();
								emit(assign_op, $1, NULL, $$,0,yylineno);
							}    
						} ;			

primary :				lvalue {
						$$=emit_iftableitem($1);
						//$$=$1;
						}
						| call {$$=$1;}
						| objectdef {	
							//$$ = newexpr(newtable_e);
							//$$ = $1;
						}
						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {}
						| const {$$=$1;}
                       				 ;   
			
lvalue :    			ID { 
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
								SymbolTableEntry *e;
								tmp = SymTable_get(table,yytext,scope);

									if(tmp == NULL){
										if(scope==0){ type = GLOBAL; } else { type = LOCAL2; }

										SymTable_put(table, yytext, yylineno, scope, type );
									}
									//$$=lvalue_expr(e);
								
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
							//$$=lvalue_expr(e);
						}   

						| member {$$=$1;}
                        ;
			
member :				lvalue DOT ID   {
						 printf("Line %d: lvalue.ID\n", yylineno); 
						 $$ = member_item($1, $3);
					}
		    			| lvalue LEFT_BRACKET expr RIGHT_BRACKET {
						printf("Line %d: lvalue table expression\n\n", yylineno);
						 
						$1 = emit_iftableitem($1);
						$$ = newexpr(tableitem_e);
						$$->sym = $1->sym;
						$$->index = $3; 
					}
						| call DOT ID  { printf("Line %d: Call.ID\n", yylineno); }
						| call LEFT_BRACKET expr RIGHT_BRACKET { printf("Line %d: Call table Expression\n", yylineno);}
	                   			 ;
			
call : 					call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
						// $$=make_call($1,$3);
						}
						| lvalue callsuffix {
								//$1 = emit_iftableitem($1); 
								//if ($2.method ){
								//struct expr* t = $1;
								//$1 = emit_iftableitem(member_item(t, $2.name));
								//$2.elist->next = t; 
								//}
							//$$= make_call($1, $2.elist);
						} 

						| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
						     //   struct expr* tmpfunction;
							//tmpfunction = newexpr(programfunc_e);
							//tmpfunction->sym = $2;
							//$$ = make_call(tmpfunction, $5); 
						}
			          		  ;

callsuffix : 			                normcall{
							//$$=$1;
						}
						| methodcall {
							//$$=$1;
						}
						;
			
normcall :				LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
						//$$.elist = $2; 
						//$$.method = 0;
						//$$.name = NULL;
					};

methodcall :        			DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
						//$$.elist = $4; 
						//$$.method = 1;
						//$$.name = $2.val;

					};

elists:					COMMA expr elists 
						| %empty {} 
						;

elist:					expr elists 
						| %empty {} 
						;						

objectdef :				LEFT_BRACKET elist RIGHT_BRACKET{
						//tablemake
						//struct expr* t = newexpr(newtable_e);
						//struct expr* tmpexpr;
						//t->sym = newtemp();
						//emit(tablecreate_op, t, NULL, NULL,0,yylineno);
						//for (int i = 0; $2; $2 = $2->next){
							//emit(tablesetelem_op, t, newexpr_constnum(i++), $2);
						//}
						//	$$ = t;
					}
					 | LEFT_BRACKET indexed RIGHT_BRACKET {
						//tablemake
						//struct expr* t = newexpr(newtable_e);
						//t->sym = newtemp();
						//emit(tablecreate, t, NULL, NULL);
						//foreach <index, value> in $indexed do
						//emit(tablesetelem_op, t, index, value);
						//$$ = t;

					} ;

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
funcname:                            ID{
							struct SymbolTableEntry *tmp1;
							
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
										}  //$$ = id.value;
				     };

funcprefix:                          FUNCTION funcname{
						
							$$ = newsymbol($2, function_s);
							$$.iaddress = nextquadlabel(); 
							emit(funcstart_op, $$, NULL, NULL);
							//push(scopeoffsetstack, currscopeoffset()); 
							enterscopespace(); 
							resetformalargsoffset(); 
				    };
funcargs:                          LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS {
						        enterscopespace(); 
					               resetfunctionlocalsoffset();
				     };
funcbody:                           block{
						$$ = currscopeoffset(); 
						existscopespace();
				    };
funcstart:                          {};
funcend:                            {};
funcdef:                            funcprefix funcargs funcstart funcbody funcend{
				     
					existscopespace();// Exiting function definition space
					$1.totalLocals = $4; //Store #locals in symbol entry
					//int offset = pop_and_top(scopeoffsetStack); ? pop and get pre scope offset
					//restorecurrscopeoffset(offset); ? Restore previous scope offset
					//$funcdef = $funcprefix; ? The function definition returns the symbol
					//emit(funcend_op, $1, NULL, NULL);
					
					}; 
                                      
 */


funcdef :			 	FUNCTION ID { 
						struct SymbolTableEntry *tmp1;
							
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
							char tempname[200];
							int number=1;
							//struct SymbolTableEntry *tmp1;
							sprintf(tempname,"_f%u",number);//opou to number prpei na ayksanetai
						   	SymTable_put(table, tempname, yylineno, scope, USERFUNC);
							number++;
							
						} LEFT_PARENTHESIS {scope++;} idlist RIGHT_PARENTHESIS {scope--;} block ;

const :				        	NUMBER {
						       $$=newexpr_constnum($1);
						}
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

ifprefix:				IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS{
	 					struct expr* tmpexpr;
						tmpexpr = newexpr_constbool(1); 
						emit(if_eq_op, tmpexpr,NULL,$3, nextquad() + 2,yylineno);
						$$ = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno);
					};

if:					ifprefix stmt
					{
						patchlabel($1, nextquad());
					};
					
elseprefix:				ELSE{	$$ = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno);
					};

if:			                ifprefix stmt elseprefix stmt{
						patchlabel($1, $3 + 1);
						patchlabel($3, nextquad());

					};



loopstart:				{ ++loopcounter; } ;


loopend:				{ --loopcounter; };


loopstmt:				loopstart stmt loopend { $$ = $2; };

whilestart: 				WHILE
					{
					    $$ = nextquad();
						loopstart=nextquad();
					};

whilecond:				LEFT_PARENTHESIS expr RIGHT_PARENTHESIS 
					{   struct expr* tmpexpr;
						tmpexpr = newexpr_constbool(1);

						emit(if_eq_op, $2, tmpexpr,NULL, nextquad() + 2,yylineno);
						$$ = nextquad();
						emit(jump_op, NULL, NULL,NULL, 0,yylineno); 
					}
					;

while:			      		whilestart whilecond loopstmt stmt
					{       printf("Line %d: While Expression\n", yylineno);
						emit(jump_op, NULL, NULL, NULL,$1,yylineno);
						patchlabel($2, nextquad());
						//loopEnd = nextquad();
						//patchlist($3.breaklist, nextquad());
						//patchlist($4.continuelist, $1); 
					} ;

/*
N:					{
						$$ = nextquad();
						emit(jump_op, NULL, NULL, NULL, 0, yylineno);
					}			
					;

M:					{
						$$ = nextquad();
					}
					;
					

forprefix:				FOR  LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON
					{       struct expr* tmpexpr;
						tmpexpr=newexpr_constbool(1);
						$$.test = $5;
						$$.enter = nextquad();
						emit(if_eq, $6, newexpr_constbool(1),NULL, 0,yylineno);
					};

for:					 forprefix N elist  RIGHT_PARENTHESIS N stmt N
					{
						patchlabel($1.enter, $5+1); //true jump
						patchlabel($2, nextquad());//false jump
						patchlabel($5, $1.test);  //loop jump
						patchlabel($7, $2+1);  //closure jump
						//patchlist($stmt.breaklist, nextquad());
						//patchlist($stmt.continuelist, $2+1);
					};


*/

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
