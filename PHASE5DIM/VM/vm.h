#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m)) 

#define EXPAND_SIZE 1024
#define CURR_SIZE_T (totalInstr*sizeof(struct instruction))
#define NEW_SIZE_T (EXPAND_SIZE * sizeof(struct instruction) + CURR_SIZE_T)

#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v
#define AVM_ENDING_PC codeSize
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1

#define AVM_TABLE_HASHSIZE 211 

//unsigned totalInstr = 0;
//unsigned int currInstr = 0;


struct avm_memcell ax, bx, cx;
struct avm_memcell retval;
//unsigned top, topsp;

typedef enum vmopcode { 
	assign_v, 	add_v,	sub_v,
	mul_v,	div_v,	mod_v,
	uminus_v,	and_v,	or_v,
	not_v,	jeq_v,	jne_v,
	jle_v,	jge_v,	jlt_v,
	jgt_v,	call_v,	pusharg_v,
	funcenter_v, funcexit_v,	newtable_v,
	tablegetelem_v,	tablesetelem_v,	jump_v,
	nop_v
} vmopcode;

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
} userfunc; 

typedef enum avm_memcell_t { 
	number_m =0, 
	string_m =1, 
	bool_m 	 =2, 
	table_m  =3, 
	userfunc_m =4, 
	libfunc_m =5, 
	nil_m	  =6, 
	undef_m   =7 
}avm_memcell_t; 

typedef struct avm_table avm_table;

typedef struct avm_memcell { 
	avm_memcell_t type; 
	union {
		double		numVal; 	
		char* 		strVal;
		unsigned char boolVal;
		 avm_table* 	tableVal;
		unsigned 		funcVal;
		char* 		    libfuncVal; 
	} data; 
}avm_memcell; 

typedef struct avm_table_bucket { 
	avm_memcell key; 
	avm_memcell value; 
	struct avm_table_bucket* next; 
} avm_table_bucket; 

typedef struct avm_table { 
	unsigned 		refCounter;
	avm_table_bucket* 	strIndexed[AVM_TABLE_HASHSIZE];
	avm_table_bucket* 	numIndexed[AVM_TABLE_HASHSIZE];
	unsigned 			   total; 
} avm_table; 

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg);
void avm_memcellclear (avm_memcell* m);
void avm_error(char* s);
void avm_warning(char* s);
//-----------------------------------
#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

typedef double (*arithmetic_func_t)(double x, double y);
typedef void (*execute_func_t)(instruction*);
typedef void (*memclear_func_t)(avm_memcell*);
typedef char* (*tostring_func_t)(avm_memcell*);
typedef unsigned char (*tobool_func_t)(avm_memcell*);

void execute_arithmetic (instruction* instr);
void execute_add (instruction* instr);
void execute_sub (instruction* instr);
void execute_mul (instruction* instr);
void execute_div (instruction* instr);
void execute_mod (instruction* instr);

double add_impl (double x, double y);
double sub_impl (double x, double y);
double mul_impl (double x, double y);
double div_impl (double x, double y);
double mod_impl (double x, double y);

//-------------------------------------
char* number_tostring (avm_memcell*);
char* string_tostring (avm_memcell*);
char* bool_tostring (avm_memcell*);
char* table_tostring (avm_memcell*);
char* userfunc_tostring (avm_memcell*);
char* libfunc_tostring (avm_memcell*);
char* nil_tostring (avm_memcell*);
char* undef_tostring (avm_memcell*);

char* avm_tostring( avm_memcell* m );

unsigned char number_tobool (avm_memcell* m) ;
unsigned char string_tobool (avm_memcell* m) ;
unsigned char bool_tobool (avm_memcell* m);
unsigned char table_tobool (avm_memcell* m) ;
unsigned char userfunc_tobool (avm_memcell* m) ;
unsigned char libfunc_tobool (avm_memcell* m);
unsigned char nil_tobool (avm_memcell* m) ;
unsigned char undef_tobool (avm_memcell* m) ;

unsigned char avm_tobool (avm_memcell* m);

void memclear_string (avm_memcell* m);
//----------------------------------------------
void memclear_table (avm_memcell* m);
void avm_tablebucketsinit (avm_table_bucket** p);
avm_table* 		avm_tablenew (void);
void avm_tablebucketsdestroy (avm_table_bucket** p);
void 			avm_tabledestroy (avm_table* t);
avm_memcell*  avm_tablegetelem (
        	 avm_table*    table,
                 avm_memcell*  index
              );

void          avm_tablesetelem (
                 avm_table*    table, 
                 avm_memcell*  index, 
                 avm_memcell*  content
              );

void execute_newtable (instruction* instr);
void execute_tablegetelem (instruction* instr);
void execute_tablesetelem (instruction* instr);
//-------------------------------
void execute_assign (instruction* instr);
void avm_assign (avm_memcell* lv, avm_memcell* rv);
//FUNCTIONS
void execute_call(instruction *instr);
void avm_dec_top(void);
void avm_push_envvalue(unsigned int val);
void avm_callsaveenvironment();
unsigned avm_get_envvalue (unsigned i);
unsigned avm_totalactuals();
avm_memcell *avm_getactual(unsigned i);
//userfunc* avm_getfuncinfo (unsigned address);
void execute_funcenter(instruction *instr);
void execute_funcexit(instruction *unused);
void execute_pusharg(instruction* instr);
typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc (char* id);
void avm_calllibfunc(char* id);
void libfunc_print(void);
void libfunc_typeof (void);

void libfunc_totalarguments (void);

//-------------------------------------------------------
void execute_jeq (instruction* instr);


void execute_cycle (void);
static void avm_initstack();
void avm_initialize(void);


