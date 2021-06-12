#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vm.h"

unsigned char executionFinished = 0;
unsigned	  pc = 0;
unsigned	  currLine = 0;
unsigned      codeSize = 0;
instruction*  code = (instruction*) 0;


typedef enum vmarg_t { 
	label_a		=0,
	global_a	=1,
	formal_a 	=2,
	local_a		=3,
	number_a 	=4,
	string_a 	=5,
	bool_a 		=6,
	nil_a		=7,
	userfunc_a  =8, 
	libfunc_a   =9, 
	retval_a    =10,
	empty		=11
} vmarg_t; 

typedef struct vmarg { 
	vmarg_t type; 
	unsigned  val; 
}vmarg; 

typedef struct instruction { 
	enum vmopcode opcode; 
	struct vmarg result; 
	struct vmarg arg1; 
	struct vmarg arg2; 
	unsigned int srcLine; 
}instruction; 

typedef struct userfunc { 
	unsigned int address; 
	unsigned int localSize; 
	char* id; 

}userfunc;

    int magic_number;
    int total_chars, i,j;
    int totalStringConsts, totalNumConsts, totalUserFuncs;
    unsigned int totalNamedLibFuncs, totalInstructions;
    char **stringConsts;
    char **namedLibFuncs;
   // unsigned currInstr;
    char *temp;
    double *numConsts;
    userfunc **userFuncs;
    instruction *instructions;
    FILE *fp;

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

/*
void print_labels(instruction *q){
//check and print the lable if eligible
   struct instruction *tmpinstr = q;
   
   if (tmpinstr->opcode==jump_op||
        tmpinstr->opcode==if_greatereq_op||
        tmpinstr->opcode==if_less_op||
        tmpinstr->opcode==if_eq_op||tmpinstr->opcode==if_lesseq_op||tmpinstr->opcode==if_greater_op){
       printf("%d",tmpinstr->label);
   }
}*/

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

double div_impl (double x, double y) {/* Error check */ 
	//double z = 0;

	if (y!=0){
	 return x/y;
	}else{
	 avm_error("ERROR!division by zero\n");
	 //z = x/y;
	}
	//return z;
 } 
double mod_impl (double x, double y) { /* Error check */
	//double z = 0;

	if (y!=0){
	 return ((unsigned) x) % ((unsigned) y);
	}else{
	 avm_error("ERROR!division by zero\n");
	 //z = ((unsigned) x) % ((unsigned) y);
	}

	//return z;
}

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
	   lv->data.strVal = strfup(rv->data.strVal);
	else
	if(lv->type == table_m)
		avm_tableincrefcounter(lv->data.tableVal);
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