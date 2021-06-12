#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "vm.h"
#include "arith.h"
#include "assign.h"

double* numConsts;
char** stringConsts;
userfunc** userFuncs;
char** namedLibfuncs;
unsigned int totalNumConsts;
unsigned int totalStringConsts;
unsigned int totalUserFuncs;
unsigned int totalNamedLibfuncs;



typedef void (*execute_func_t)(instruction*);
typedef char* (*tostring_func_t)(avm_memcell*);
typedef unsigned char (*tobool_func_t)(avm_memcell*);

avm_memcell stack[AVM_STACKSIZE];

unsigned char executionFinished = 0;
unsigned	  pc = 0;
unsigned	  currLine = 0;
unsigned      codeSize = 0;
instruction*  code = (instruction*) 0;


execute_func_t executeFuncs[]={
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
	execute_nop,
	execute_jump
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

extern void memclear_string (avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

extern void memclear_table (avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}


void avm_error(char* s){
	printf("Runtime Error: %s \n", s);
	executionFinished = 1; 
}
 
void avm_warning(char* s){
	printf("Runtime Warning: %s \n", s);
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


/*
int main(int argc, char** argv){
	FILE *fr;
	fr=fopen("binary.abc","rb");
	//error message
	//edw tha kalei th read pou diavazei to binary
	//se enan buffer apothikeume ta data
	//size_t fread(&buffer,sizetoubuffer,1,fr);//read one element
	//an diavase size_t=0 error
	fclose(fr);
}
*/
