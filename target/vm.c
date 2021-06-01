#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTION (unsigned) nop_v
#define AVM_ENDING_PC codeSize
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDTPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1

double consts_getnumber (unsigned index);
char* consts_getstring 	(unsigned index);
char* libfuncs_getused	(unsigned index);

typedef void (*execute_func_t)(instruction*);
typedef char* (*tostring_func_t)(avm_memcell*);

extern void execute_assign 	(instruction*);
extern void execute_add    	(instruction*);
extern void execute_sub 	(instruction*);
extern void execute_mul 	(instruction*);
extern void execute_div 	(instruction*);
extern void execute_mod 	(instruction*);
extern void execute_uminus 	(instruction*);
extern void execute_and 	(instruction*);
extern void execute_or 		(instruction*);
extern void execute_not 	(instruction*);
extern void execute_jeq 	(instruction*);
extern void execute_jne 	(instruction*);
extern void execute_jle 	(instruction*);
extern void execute_jge 	(instruction*);
extern void execute_jlt 	(instruction*);
extern void execute_jgt 	(instruction*);
extern void execute_call 	(instruction*);
extern void execute_pusharg 	(instruction*);
extern void execute_funcenter 	(instruction*);
extern void execute_funcexit 	(instruction*);
extern void execute_newtable 	(instruction*);
extern void execute_tablegetelem 	(instruction*);
extern void execute_tablesetelem 	(instruction*);
extern void execute_nop 	(instruction*);

//extern void avm_warning(char* format, ASDADSAD);
extern void avm_assign(avm_memcell* lv, avm_memcell* rv);
extern char* avm_tostring (avm_memcell*); /*caller frees*/
extern void avm_calllibfunc (char* funcName);
extern void avm_callsaveenvironment (void);
extern userfunc* avm_getfuncinfo (unsigned address);



execute_func_t executeFuncsp[]=(
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_uminus,
	execute_and,
	execute_or,
	execute_not,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop
);

unsigned char executionFinished = 0;
unsigned	  pc = 0;
unsigned	  currLine = 0;
unsigned      codeSize = 0;

instruction* code = (instruction*) 0;

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
			instr->opcode <= AVM_MAX_INSTRUCTION;
		);
		if (instr->srcLine)
			currLine = instr->srcLine;
		unsigned oldPC = pc;
		(*executeFuncs[inst->opcode])(instr);
		if (pc == oldPC)
			++pc;
	}
}

memclear_func_t memclearFuncs[]=(
	0,	/*number*/
	memclear_string,
	0,	/*bool*/
	memclear_table,
	0,	/*userfunc*/
	0,	/*livfunc*/
	0,	/*nil*/
	0,	/*undef*/
);

void avm_memcellclear (avm_memcell* m){
	if (m->type != undef_m){
		memclear_func_t f = memclearFuncs[m->type];
		if (f)
			(*f) (m);
		m->type = undef_m;
	}
}

void execute_assign (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* rv = avm_translate_operand(&instr->arg1, &ax);

	assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));
	assert(rv); //should do a similar assertion tests here

	avm_assign(lv, rv);
}

void avm_assign (avm_memcell *lv, avm_memcell *rv){
	if(lv == rv)		/*SAME cells? destructive to assign*/
		return;
	if(lv->type == table_m &&
	   rv->type == table_m && lv->data.tableVal == rv->data.tableVal)
	   return;
	if(rv->type == undef_m)	/* From undefined r->value ?!?! warning */
		avm_warning("assigning from 'undef' content!");
	avm_memcellclear(lv);	/* Clear old cell contents */

	memcpy(lv, rv, sizeof(avm_memcell)); /* In C++ dispatch instead */

	/* Take care of copied values or reference counting */

	if(lv->type == string_m)
	   lv->data.strVal = strfup(rv->data.strVal);
	else
	if(lv->type == table_m)
		avm_tableincrefcounter(lv->data.tableVal);\
}

void execute_call (instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	avm_callsaveenvironment();

	switch (func->type){
		case userfunc_m : (pc = func->data.funcVal;
						   assert(pc < AVM_ENDING_PC);
					       assert(code[pc].opcode == funcenter_v);
						   break;	
		)

		case string_m: avm_calllibfunc(func->data.strVal); break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;

		default: {
			char* s = avm_tostring(func);
			avm_error("call: cannot bind '%s' to function!", s);
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

void execute_funcenter (instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	assert(pc == func->data.funcVal); /*Func address should match PC*/

	/*Callee actions here*/
	totalActuals = 0;
	userfunc* funcInfo = avm_getfuncinfo(pc);
	tops = top;
	top = top - funcInfo->localSize;
}

unsigned avm_get_envvalue (unsigned i){
	assert(stack[i].type = number_m);
	unsigned val = (unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
	return val;
}

void execute_funcexit (instruction* unused){
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVETOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(++oldTop <= top) /* intentinally ignoring first */
		avm_memcellclear(&stack[oldTop]);
}

typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc (char* id); /*Typical hashing*/

void avm_calllibfunc (char* id){
	library_func_t f = avm_getlibraryfunc(id);
	if(!f){
		avm_error("unsupported lib func '%s' called! ", id);
	}
	else {
		/*Notice that enter function and exit function are called manually*/
		topsp = top; /*Enter function sequence. No stack locals*/
		totalActuals = 0;
		(*f)();
		if(!executionFinished)/*an error may naturally occur inside*/
			xecute_funcexit((instruction*) 0);
	}
}

void avm_totalactuals (void) {
	return avm_get_envvalue (topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell *avm_gtactual ()unsigned i{}
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];


/* implementation of the library function print
   it displays every argument at the console
*/

void libfunc_print(void){
	unsigned n = avm_totalactuals();
	for(unsigned i = 0; i < n; ++i){
		char* s = avm_tostring(avm_getactual(i));
		puts(s);
		free(s);
	}
}

/*with the following every library function is manually added in the VM
library function resolution map
*/

void avm_registerlibfunc (char* id, library_func_t addr);

void execute_pusharg (instruction *instr) {
	avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
	assert(arg);
	/*This is actually stack[top] = arg, but we have to use avm_assign */

	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}





enum avm_memcell_t { 
	number_m =0, 
	string_m =1, 
	bool_m 	 =2, 
	table_m  =3, 
	userfunc_m =4, 
	libfunc_m =5, 
	nil_m	  =6, 
	undef_m   =7 
}; 

//avm_memcell ax, bx, cx;
//avm_memcell retval;

unsigned top, topsp;

struct avm_table avm_table;

struct avm_memcell { 
	avm_memcell_t type; 
	union {
		double		numVal; 	
		char* 		strVal;
		unsigned char boolVal;
		avm_table* 	tableVal;
		unsigned 		funcVal;
		char* 		    libfuncVal; 
	} data; 
}; 

static void avm_initstack(){

	unsigned int i;

	for(i=0;i < AVM_STACKSIZE;++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type = undef_m;
	}
}

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {  

	switch	(arg->type) {
	/* Variables */

		case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
		case local_a:  return &stack[topsp-arg->val];
		case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
		case retval_a: return &retval;
 		case number_a: {
  			reg->type = number_m;
  			reg->data.numVal = (consts_getnumber(arg->val));
  			return reg;                                         
		}
        
		case string_a: {
  			reg->type = string_m;
  			reg->data.strVal = strdup(consts_getstring(arg->val));
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
  			reg->data.libfuncVal = libfuncs_getused(arg->val); 
			return reg;
		} 
		default: assert(0);
	}
}

void execute_newtable (instruction* instr) {
   avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
   assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));

   avm_memcellclear(lv);

   lv->type          = table_m;
   lv->data.tableVal = avm_tablenew();
   avm_tableincrefcounter(lv->data.tableVal);
}

avm_memcell*  avm_tablegetelem (
                 avm_table*    table,
                 avm_memcell*  index
              )

void          avm_tablesetelem (
                 avm_table*    table, 
                 avm_memcell*  index, 
                 avm_memcell*  content
              )

void execute_tablegetelem (instruction* instr) {

     avm_memcell* lv     = avm_translate_operand(&instr->result, (avm_memcell*) 0);
     avm_memcell* t      = avm_translate_operand(&instr->arg2, (avm_memcell*) 0);
     avm_memcell* i      = avm_translate_operand(&instr->arg2, &ax);

     assert (lv && &stack[N-1] >= lv && lv > &stack[top]  || lv==&retval);
     assert (t && &stack[N-1] >= t && t > &stack[top]);
     assert(i);

     avm_memcellclear(lv);
     lv->type = nil_m;      /* Default value. */

     if (t->type != table_m) {
         avm_error("illegal use of type as table!",typeStrings[t->type]);
     } 
     else  {
         avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
         if (content)
              avm_assign(lv, content); 
         else {
              char* ts = avm_tostring(t); 
              char* is = avm_tostring(i); 
              avm_warning("%s[%s]table element not found!",ts,is);
              free(ts);
              free(is);
         }
     }
}

void execute_tablesetelem (instruction* instr) {
	
	avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

	assert (t && &stack[N-1] >= t && t > &stack[top]);  
	assert (i && c);
	if (t->type != table_m)
		avm_error("illegal use of type as table!",typeStrings[t->type]);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}

