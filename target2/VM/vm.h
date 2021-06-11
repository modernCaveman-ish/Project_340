
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

//unsigned totalInstr = 0;
//unsigned int currInstr = 0;


struct avm_memcell ax, bx, cx;
struct avm_memcell retval;
unsigned top, topsp;

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


avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg);
void execute_cycle (void);
void avm_memcellclear (avm_memcell* m);
void avm_error(char* s);
void avm_warning(char* s);
void memclear_string (avm_memcell* m);
void memclear_table (avm_memcell* m);
void avm_initialize(void);
static void avm_initstack();
//double consts_getnumber (unsigned index);
//char*  consts_getstring (unsigned index);
//char*  libfuncs_getused	(unsigned index);

typedef void (*execute_func_t)(instruction*);
typedef char* (*tostring_func_t)(avm_memcell*);
typedef unsigned char (*tobool_func_t)(avm_memcell*);
typedef void (*memclear_func_t)(avm_memcell*);


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
extern void execute_nop 	(instruction*);
extern void execute_jump 	(instruction*);
