#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "vm.h"

//dhlwseis pinakwn 
double* numConsts;
char** stringConsts;
userfunc* userFuncs;
char** namedLibFuncs;
unsigned int totalNumConsts;
unsigned int totalStringConsts;
unsigned int totalUserFuncs;
unsigned int totalNamedLibFuncs;

avm_memcell stack[AVM_STACKSIZE];
avm_memcell ax, bx, cx;
extern avm_memcell retval;
 //unsigned top, topsp;

unsigned char executionFinished = 0;
unsigned	  pc = 0;
unsigned	  currLine = 0;
unsigned      codeSize = 0;
instruction*  code = (instruction*) 0;

    int magic_number;
    int total_chars, i,j;
    unsigned int  totalInstructions;
   // unsigned currInstr;
    char *temp;
    instruction *instructions;
    FILE *fp;

//unsigned consts_newstring(char*s);

//unsigned libfuncs_newused(char*s);

int lookUp1(char** stringConsts, char *s){
	int i=0;
	int flag = 0;

	for(i=0; i<totalStringConsts; i++){
		if(strcmp(stringConsts[i] ,s)==0){
			flag = 1;
		}
	}
	return flag;
}

unsigned consts_newstring(char*s){

 if(stringConsts==NULL){
	stringConsts = (char**)malloc(sizeof(char*));
	stringConsts[totalStringConsts] = s;
	totalStringConsts++;
    }else{

	if(lookUp1(stringConsts, s) == 1){
		int i=0;
		for(i=0;i<totalStringConsts; i++){
			if(strcmp(s,stringConsts[i])==0){
			//	totalNumConsts = i;
				//break;
				return i;
			}
		}
	}		

	char** strings_array;
	strings_array = (char**)malloc(sizeof(char*) * (totalStringConsts+1));
	int i=0;
	while(i<totalStringConsts){
		strings_array[i] = stringConsts[i];
		i++;
	}
		
	//free(stringConsts);
	
	stringConsts= strings_array;
		stringConsts[totalStringConsts] = s;
	
	totalStringConsts++;		
    }

	return totalStringConsts-1;
}

int lookUp2(double *numConsts, double n){
	int i=0;
	int flag = 0;

	for(i=0; i<totalNumConsts; i++){
		if(numConsts[i] == n){
			flag = 1;
		}
	}
	return flag;
}

unsigned int consts_newnumber(double n){
    if(numConsts==NULL){
	numConsts = (double*)malloc(sizeof(double));
	numConsts[totalNumConsts] = n;
	totalNumConsts++;
    }else if(numConsts != NULL){

	if(lookUp2(numConsts, n) == 0){
		int i=0;
		for(i=0;i<totalNumConsts; i++){
			if(numConsts[i] == n){
			//	totalNumConsts = i;
				//break;
				return i;
			}
		}
	}

	double* numbers_array;
	numbers_array = (double*)malloc(sizeof(double) * (totalNumConsts+1));
	int i=0;

	while(i<totalNumConsts){
		numbers_array[i] = numConsts[i];
		i++;
	}
	numbers_array[totalNumConsts] = n;
		
	free(numConsts);
		
	numConsts = numbers_array;	
	totalNumConsts++;		
	}

	return totalNumConsts-1;	
}

//----------------------------ARITHMITIKES PRAKSEIS------------------------------
/* Dispatcher just for arithmetic functions */
arithmetic_func_t arithmeticFuncs[] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};
typedef double (*arithmetic_func_t)(double x, double y);

void execute_arithmetic (instruction* instr){

	avm_memcell* lv  = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg1, &bx);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));
	assert(rv1 && rv2);

	if(rv1->type != number_m || rv2->type != number_m){
		avm_error("not a number in arithmetic!");
		executionFinished = 1;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type 		= number_m;
		lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
	}
}

double add_impl (double x, double y) { return x+y; }
double sub_impl (double x, double y) { return x-y; }
double mul_impl (double x, double y) { return x*y; }

double div_impl (double x, double y) {
/* Error check */ 	
	if (y!=0){
	 return x/y;
	}else{
	 avm_error("ERROR!division by zero\n");
         executionFinished=1;
	}

 } 
double mod_impl (double x, double y) {
 /* Error check */
	if (y!=0){
	 return ((unsigned) x) % ((unsigned) y);
	}else{
	 avm_error("ERROR!division by zero\n");
	executionFinished=1;
	}
}


//--------------------------------------TABLES-------------------------------------------


extern void memclear_string (avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

void avm_tableincrefcounter (avm_table* t) 
	{ ++t->refCounter; } 

void avm_tabledecrefcounter (avm_table* t) { 
	assert(t->refCounter > 0); 
	if (!--t->refCounter) 
		avm_tabledestroy(t); 
}
void avm_tablebucketsinit (avm_table_bucket** p) { 
	unsigned i;
	for (i=0; i<AVM_TABLE_HASHSIZE; ++i) 
		p[i] = (avm_table_bucket*) 0; 
}
extern void memclear_table (avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

/* The reference counter is initially zero. */ 
avm_table* avm_tablenew (void) { 
	avm_table* t = (avm_table*)malloc(sizeof(avm_table)); 
	AVM_WIPEOUT(*t); 

	t->refCounter = t->total = 0; 
	avm_tablebucketsinit(t->numIndexed); 
	avm_tablebucketsinit(t->strIndexed); 
return t; 
}

void avm_tablebucketsdestroy (avm_table_bucket** p) { 
	unsigned i;
	for (i=0; i<AVM_TABLE_HASHSIZE; ++i, ++p) { 
	        avm_table_bucket* b;
		for ( b = *p; b;) { 
			avm_table_bucket* del = b; 
			b = b->next; 
			avm_memcellclear(&del->key); 
			avm_memcellclear(&del->value); 
			free(del); 
		} 
		p[i] = (avm_table_bucket*) 0; 
	} 
} 
 
void avm_tabledestroy (avm_table* t) { 
	avm_tablebucketsdestroy(t->strIndexed); 
	avm_tablebucketsdestroy(t->numIndexed); 
	free(t); 
} 

avm_memcell*  avm_tablegetelem (
                 avm_table*    table,
                 avm_memcell*  index
              );

void          avm_tablesetelem (
                 avm_table*    table, 
                 avm_memcell*  index, 
                 avm_memcell*  content
              );



void execute_newtable (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	assert(lv && ( &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));

	avm_memcellclear(lv);

	lv->type 			= table_m;
	lv->data.tableVal 	= avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal); 
}

void execute_tablegetelem (instruction* instr) {

     avm_memcell* lv     = avm_translate_operand(&instr->result, (avm_memcell*) 0);
     avm_memcell* t      = avm_translate_operand(&instr->arg2, (avm_memcell*) 0);
     avm_memcell* i      = avm_translate_operand(&instr->arg2, &ax);

     assert (lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top]  || lv==&retval);
     assert (t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
     assert(i);

     avm_memcellclear(lv);
     lv->type = nil_m;      /* Default value. */

     if (t->type != table_m) {
	//avm_error("illegal use of type as table!",typeStrings[t->type]);
         avm_error("illegal use of type as table!");
     } 
     else  {
         //avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
	    avm_memcell* content;
         if (content)
              avm_assign(lv, content); 
         else { //endexetai to stoixio pou zitite gia to sigkekrimeno kleidi na min iparxei i na ipostirizi kleidi sigkekrimenou tipou
              char* ts = avm_tostring(t); 
              char* is = avm_tostring(i); 
              //avm_warning("%s[%s]table element not found!", ts, is);
		 avm_warning("table element not found!");
              free(ts);
              free(is);
         }
     }
}
void execute_tablesetelem (instruction* instr) {
	
	avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

	assert (t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);  
	assert (i && c);
	if (t->type != table_m)
		//avm_error("illegal use of type as table!", typeStrings[t->type]);
		avm_error("illegal use of type as table!");
	else
		//avm_tablesetelem(t->data.tableVal, i, c);
;
}
 
//-----------------------------------ASSIGNMENT------------------------------------------

void execute_assign (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* rv = avm_translate_operand(&instr->arg1, &ax);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv==&retval));
	assert(rv); //should do a similar assertion tests here

	avm_assign(lv, rv);
}

void avm_assign (avm_memcell *lv, avm_memcell *rv){
	
	if(lv == rv)		/*SAME cells? destructive to assign*/
		return;

	if(lv->type == table_m && /*SAME tables? no need to assign*/
	   rv->type == table_m && 
	   lv->data.tableVal == rv->data.tableVal)
	   return;

	if(rv->type == undef_m)	/* From undefined r->value ?!?! warning */
		avm_warning("assigning from 'undef' content!");
	
	avm_memcellclear(lv);	/* Clear old cell contents */

	memcpy(lv, rv, sizeof(avm_memcell)); /* In C++ dispatch instead */

	/* Now take care of copied values or reference counting */

	if(lv->type == string_m)
	   lv->data.strVal = strdup(rv->data.strVal);
	else
	if(lv->type == table_m)
		avm_tableincrefcounter(lv->data.tableVal);
}

char* typeStrings[] = {
    "number",
    "string",
    "bool",
    "table",
    "userfunc",
    "libfunc",
    "nil",
    "undef"
};

tobool_func_t toboolFuncs[]={
	0,//number_tobool,
	0,//string_tobool,
	0,//bool_tobool,
	0,//table_tobool,
	0,//userfunc_tobool,
	0,//libfunc_tobool,
	0,//nil_tobool,
	0,//undef_tobool
};

unsigned char avm_tobool (avm_memcell* m){
	assert((m->type >= 0 && m->type) < undef_m);
	return (*toboolFuncs[m->type])(m);
}

//unsigned char number_tobool (avm_memcell* m) { return m->data.numVal != 0; }
//unsigned char string_tobool (avm_memcell* m) { return m->data.strVal[0] != 0; }
//unsigned char bool_tobool (avm_memcell* m) { return m->data.boolVal; }
//unsigned char table_tobool (avm_memcell* m) { return 1; }
//unsigned char userfunc_tobool (avm_memcell* m) { return 1; }
//unsigned char libfunc_tobool (avm_memcell* m) { return 1; }
//unsigned char nil_tobool (avm_memcell* m) { return 0; }
//unsigned char undef_tobool (avm_memcell* m) { assert(0); return 0; }

//---------------------------------------------------------------------------------------------
void avm_error(char* s){
	printf("Runtime Error: %s \n", s);
	executionFinished = 1; 
}
 
void avm_warning(char* s){
	printf("Runtime Warning: %s \n", s);
}


//--------------------------------------------FUNCTIONS------------------------------------------

void execute_call (instruction* instr){

	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	avm_callsaveenvironment();

	switch (func->type){

		case userfunc_m : { pc = func->data.funcVal;
						    assert(pc < AVM_ENDING_PC);
					        assert(code[pc].opcode == funcenter_v);
						    break;	
		}

		case string_m: avm_calllibfunc(func->data.strVal); 		break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;

		default: {
			char* s = avm_tostring(func);
			//avm_error("call: cannot bind '%s' to function!", s);
			avm_error("call: cannot bind s to function!");
			free(s);
			executionFinished = 1;
		}
	}
}


unsigned totalActuals = 0;

void avm_dec_top (void) {
	if(!top) { /*stack overflow */  
		avm_error("stack overflow");
		executionFinished = 1;
	}
	else
		--top;
}

void avm_push_envvalue (unsigned val){
	stack[top].type = number_m;
	stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenvironment (void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}

unsigned avm_get_envvalue (unsigned i){
	assert(stack[i].type = number_m);
	unsigned val = (unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
	return val;
}


unsigned avm_totalactuals (void) {
	return avm_get_envvalue (topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

//userfunc* avm_getfuncinfo (unsigned address);

void execute_funcenter (instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	assert(pc == func->data.funcVal); /*Func address should match PC*/

	/*Callee actions here*/
	totalActuals = 0;
	//userfunc* funcInfo = avm_getfuncinfo(pc);
	//topsp = top;
	//top = top - funcInfo->localSize;
}


void execute_funcexit (instruction* unused){
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(++oldTop <= top) /* intentionally ignoring first */
		avm_memcellclear(&stack[oldTop]);
}

void execute_pusharg (instruction* instr) {
	avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
	assert(arg);

	/*This is actually stack[top] = arg, but we have to use avm_assign */
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

//typedef void (*library_func_t)(void);
//library_func_t avm_getlibraryfunc (char* id); /*Typical hashing*/

char* avm_getlibraryfunc (char* id){
	int i = 0;
	for(i = 0; i < totalNamedLibFuncs; i++){
		if(strcmp(namedLibFuncs[i], id) == 0){
			return namedLibFuncs[i];
		}
	}
	return NULL;
}



void avm_calllibfunc (char* id){
	//library_func_t f = avm_getlibraryfunc(id);
	char *f;
	f=avm_getlibraryfunc(id);
	if(!f){
		//avm_error("unsupported lib func '%s' called! ", id);
		avm_error("unsupported lib func '%s' called! ");
	}
	else {
		/*Notice that enter function and exit function are called manually*/
		//topsp = top; /*Enter function sequence. No stack locals*/
		//totalActuals = 0;
		
	 	//(*f) (); /* Call library function. */ 
 	if (!executionFinished) /* An error may naturally occur inside. */ 
 		execute_funcexit((instruction*) 0); /* Return sequence. */
 	}	
}



/* implementation of the library function print
   it displays every argument at the console
*/

void libfunc_print(void){
	unsigned n = avm_totalactuals();
	unsigned i;
	for( i = 0; i < n; ++i){
		char* s = avm_tostring(avm_getactual(i));
		puts(s);
		free(s);
	}
}
/*with the following every library function is manually added in the VM
library function resolution map
*/
//void avm_registerlibfunc (char* id, library_func_t addr);

void libfunc_typeof (void){

	unsigned n = avm_totalactuals();

	if(n != 1)
		//avm_error("one argument (not %d) expected in 'typeof' !", n);
		avm_error("one argument (not %d) expected in 'typeof' !");
	else {
			/*thats how a library function returns a result, it has to only 
			set the retval register */
		avm_memcellclear(&retval); /*Dont forget to clean it up*/
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_totalarguments (void){
	/*Get topsp of previous activation record*/
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if(!p_topsp){
		avm_error("'totalrguments' called outside a function!");
		retval.type = nil_m;
	}
	else{
		/*Exctract the number of actual arguments for the previous activation record*/
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

tostring_func_t tostringFuncs[]= { 
	0,//number_tostring, 
	0,//string_tostring, 
	0,//bool_tostring, 
	0,//table_tostring, 
	0,//userfunc_tostring, 
	0,//libfunc_tostring, 
	0,//nil_tostring, 
	0,//undef_tostring   
}; 
 //char* number_tostring (avm_memcell*);
 //char* string_tostring (avm_memcell*);
 //char* bool_tostring (avm_memcell*);
 //char* table_tostring (avm_memcell*);
//char* userfunc_tostring (avm_memcell*);
 //char* libfunc_tostring (avm_memcell*);
// char* nil_tostring (avm_memcell*);
// char* undef_tostring (avm_memcell*);


char* avm_tostring (avm_memcell* m){
	//assert(m->type >= 0 && m->type = undef_m);
	assert(m->type >= 0 && m->type == undef_m);
	return (*tostringFuncs[m->type])(m);
}


//-----------------------------------------------------------------------------------------
execute_func_t executeFuncs[]={
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	0,//execute_uminus,
	0,//execute_and,
	0,//execute_or,
	0,//execute_not,
	0,//execute_jeq,
	0,//execute_jne,
	0,//execute_jle,
	0,//execute_jge,
	0,//execute_jlt,
	0,//execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	0,//execute_nop,
	0,//execute_jump
};

memclear_func_t memclearFuncs[]= {
	0,	/*number*/
	memclear_string,
	0,	/*bool*/
	memclear_table,
	0,	/*userfunc*/
	0,	/*livfunc*/
	0,	/*nil*/
	0	/*undef*/
};


avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {  

	switch	(arg->type) {
	/* Variables */

		case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
		case local_a:  return &stack[topsp-arg->val];
		case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
		case retval_a: return &retval;
 		case number_a: {
  			reg->type = number_m;
  			//reg->data.numVal = (consts_newnumber(arg->val));
  			return reg;                                         
		}
        
		case string_a: {
  			reg->type = string_m;
  			//reg->data.strVal = strdup(consts_newstring(arg->val));
  			return reg;                                         
		}
    
		case bool_a: {
  			reg->type = bool_m;
  			reg->data.boolVal = arg->val; 
			
  			return reg;                                         
  		}
		
		case nil_a: reg->type = nil_m; return reg;

		case userfunc_a: {
  			reg->type = userfunc_m;
  			reg->data.funcVal = arg->val; /* Address already stored */ 
  			return reg;
		}

		case libfunc_a: {
  			reg->type = libfunc_m;
  			//reg->data.libfuncVal = libfuncs_getused(arg->val); 
			return reg;
		} 
		default: assert(0);
	}
}


void execute_cycle (void){
	if(executionFinished)
		return;
	else
	if(pc == AVM_ENDING_PC){
		executionFinished = 1;
		return;
	}
	else{
		assert(pc < AVM_ENDING_PC);
		instruction* instr = code + pc;
		assert(
			instr->opcode >= 0 &&
			instr->opcode <= AVM_MAX_INSTRUCTIONS
		);
		if (instr->srcLine)
			currLine = instr->srcLine;
		unsigned oldPC = pc;
		(*executeFuncs[instr->opcode])(instr);
		if (pc == oldPC)
			++pc;
	}
}

void avm_memcellclear (avm_memcell* m){
	if (m->type != undef_m){
		memclear_func_t f = memclearFuncs[m->type];
		if (f)
			(*f) (m);
		m->type = undef_m;
	}
}


void avm_initialize(void){
	avm_initstack();

	//avm_registerlibfunc("print", libfunc_print);
	//avm_registerlibfunc("typeof", libfunc_typeof);

	/*Same for all the rest library functions*/
}


static void avm_initstack(){

	unsigned int i;

	for(i=0;i < AVM_STACKSIZE;++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type = undef_m;
	}
}

char* vopcode[]={"assign_v", "add_v", "sub_v", 
	"mul_v", "div_v", "mod_v", 
	"uminus_v", "and_v", "or_v", 
	"not_v", "jeq_v"," jne_v", 
	"jle_v", "jge_v", "jlt_v", 
	"jgt_v"," call_v"," pusharg_v", 
	"funcenter_v", "funcexit_v", "newtable_v", 
	"tablegetelem_v", "tablesetelem_v", 
	"jump_v", "nop_v"
};


void print_label(vmarg *e){
   // if(e==NULL)return;
   // if(e->sym!=NULL)
    //printf("%d", e->type);

	printf("%d", e->val);
	printf("(label)\t");
}

void print_global(vmarg *e){
	printf("%d", e->val);
	printf("(global)\t");
}

void print_formal(vmarg *e){
	printf("%d", e->val);
	printf("(formal)\t");
}

void print_local(vmarg *e){
	printf("%d", e->val);
	printf("(local)\t");
}

void print_number(vmarg *e){
    printf("%f", numConsts[e->val]);
	printf("(number)\t");
}

void print_string2(vmarg *e){
    printf("%s", stringConsts[e->val]);
	printf("(string)\t");
}

void print_bool2(vmarg *e){
    printf("%d", e->val);
	printf("(boolean)\t");
}

void print_nil2(vmarg * e){
    printf("nil\t");
}

void print_libfunc(vmarg *e){
	printf("%s", namedLibFuncs[e->val]);
	printf("(libfunc)\t");
}

void print_userfunc(vmarg *e){
	printf("%s", userFuncs[e->val].id);
	printf("(userfunc)\t");
}

void print_retval(vmarg *e){

	printf("retval\t");
}

void (*vmarg_prints[12])(vmarg *) = {
    print_label,
    print_global,
    print_formal,
    print_local,
    print_number,
    print_string2,
    print_bool2,
    print_nil2,
	print_userfunc,
	print_libfunc,
	print_retval
};

void print_vmarg (struct vmarg *e) {
    if(e == NULL){
        printf(" ");
    } else if (e->type == empty){
		printf(" ");
	}else{
        //analogws to type prepei na ektypwseis to katallilo pedio tou expr
        //px constring_e ektypws to strconst
     /*   if(expr->type == 8){ //print ta noymera
         printf("%d\t\t\t", expr->numConst);
        }  else if(expr->type == 10){
            printf("%s\t\t\t", expr->strConst);
        } else if(expr->type == 9){
            printf("%c\t\t\t", expr->boolConst);
        }*/
        vmarg_prints[e->type](e);
     printf(" ");
    }
}


void Instruction_Print(){
	printf("\n\n\n");
//quad# opcode,result,arg1,arg2,label
	struct quad *tmpinstr;
	int i;
    
   // printf("instuction#\topcode\t\t\t result\t\t\targ1\t\t\targ2\t\t\tlabel\t\t\t\n");
	
    for(i=0;i<totalInstructions;i++){
        printf("%d ",i);
       
        printf("%s ", vopcode[instructions[i].opcode]);
        if(instructions[i].result.type != empty){
            print_vmarg(&instructions[i].result);
    
            print_vmarg(&instructions[i].arg1);
                //     if(i==3)break;
            print_vmarg(&instructions[i].arg2);
        }else if(instructions[i].arg1.type != empty){
            print_vmarg(&instructions[i].arg1);
            if(instructions[i].opcode!=call_v && instructions[i].opcode!=pusharg_v )
				print_vmarg(&instructions[i].arg2);
        }

        //print_labels(&quads[i]);
        printf("\n");
    }
}


int main(){
   
    fp = fopen("binary.abc", "rb");

    fread(&magic_number, sizeof(int), 1, fp);
    
    fread(&totalStringConsts, sizeof(int), 1, fp);

    stringConsts = (char**)malloc(sizeof(char) * totalStringConsts);
    
    for(i=0; i<totalStringConsts; i++){
        fread(&total_chars, sizeof(int), 1, fp);
        stringConsts[i] = (char*)malloc(sizeof(char) * total_chars);

        for(j=0; j<total_chars; j++){
            fread(&stringConsts[i][j], sizeof(char), 1, fp);
        }
        printf("%s ",  stringConsts[i]);
    }

    fread(&totalNumConsts, sizeof(totalNumConsts), 1, fp);

    numConsts = (double*)malloc(sizeof(double) * totalNumConsts);
    for(j=0; j< totalNumConsts; j++){
       fread(&numConsts[j], sizeof(double), 1, fp); 
    }

    printf("numConsts: ");
    for(i = 0; i<totalNumConsts-1; i++){
        printf("---%f, ", numConsts[i]);
    }
    printf("%f\n", numConsts[i]);

    fread(&totalUserFuncs, sizeof(int), 1, fp);

    userFuncs = (userfunc*)malloc(sizeof(userfunc) * totalUserFuncs);
    for(i=0; i<totalUserFuncs; i++){
        fread(&userFuncs[i].address, sizeof(unsigned int), 1, fp);
        fread(&userFuncs[i].localSize, sizeof(unsigned int), 1, fp);

        //twra bale id
        fread(&total_chars, sizeof(int), 1, fp);
        userFuncs[i].id = (char*)malloc(sizeof(char) * total_chars);
        for(j=0; j<total_chars; j++){
            fread(&userFuncs[i].id[j], sizeof(char), 1, fp);
        }
        printf("%s ",   userFuncs[i].id );

    }  

    fread(&totalNamedLibFuncs, sizeof(unsigned int), 1, fp);
    namedLibFuncs = (char **)malloc(sizeof(char) * totalNamedLibFuncs);

    for(i=0; i<totalNamedLibFuncs; i++){
        fread(&total_chars, sizeof(int), 1, fp);
        namedLibFuncs[i] = (char *)malloc(sizeof(char) * total_chars);
        for(j=0; j<total_chars; j++){
            fread(&namedLibFuncs[i][j], sizeof(char), 1, fp);
        }
         printf("%s ",   namedLibFuncs[i] );
    }


    for(i=0; i<totalNamedLibFuncs; i++){
        temp = namedLibFuncs[i];
    }

    fread(&totalInstructions, sizeof(unsigned int), 1, fp);

    instructions = (instruction*)malloc(sizeof(instruction) * totalInstructions);
    for(i=0; i<totalInstructions; i++){
        fread(&instructions[i].opcode, sizeof(instructions[i].opcode), 1, fp);
        //result
        fread(&instructions[i].result.type, sizeof(instructions[i].result.type), 1, fp);
        fread(&instructions[i].result.val, sizeof(instructions[i].result.val), 1, fp);
        //arg1
        fread(&instructions[i].arg1.type, sizeof(instructions[i].arg1.type), 1, fp);
        fread(&instructions[i].arg1.val, sizeof(instructions[i].arg1.val), 1, fp);
        //arg2
        fread(&instructions[i].arg2.type, sizeof(instructions[i].arg2.type), 1, fp);
        fread(&instructions[i].arg2.val, sizeof(instructions[i].arg2.val), 1, fp);
    }

 Instruction_Print();

    fclose(fp);
    return 0;
}