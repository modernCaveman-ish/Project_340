#include <stdio.h>
#include <stdlib.h>
#include "quads.h"

#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m)) 
#define CURR_SIZE_T (totalInstr*sizeof(struct instruction))
#define NEW_SIZE_T (EXPAND_SIZE * sizeof(struct instruction) + CURR_SIZE_T)

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

//unsigned ij_total = 0;

typedef struct incomplete_jump {
	unsigned 	instrNo; // The jump instruction number.
	unsigned    iaddress;// The i-code jump-target address.  
	struct incomplete_jump* next;// A trivial linked list. 
} incomplete_jump; 

//incomplete_jump* ij_head =(incomplete_jump*) 0;


extern void generate_ADD (quad* quad);  
extern void generate_SUB (quad* quad);   
extern void generate_MUL (quad* quad);  
extern void generate_DIV (quad* quad);   
extern void generate_MOD (quad* quad); 
extern void generate_NEWTABLE (quad* quad);  
extern void generate_TABLEGETELM (quad* quad);   
extern void generate_TABLESETELEM (quad* quad);  
extern void generate_ASSIGN (quad* quad);   
extern void generate_NOP (quad* quad);  
extern void generate_JUMP (quad* quad);  
extern void generate_IF_EQ (quad* quad);  
extern void generate_IF_NOTEQ (quad* quad);  
extern void generate_IF_GREATER (quad* quad);   
extern void generate_IF_GREATEREQ (quad* quad);  
extern void generate_IF_LESS (quad* quad);  
extern void generate_IF_LESSEQ (quad* quad);  
void generate_AND (quad *quad);
extern void generate_NOT (quad* quad);  
extern void generate_OR (quad* quad);  
extern void generate_PARAM (quad* quad);  
extern void generate_CALL (quad* quad);  
extern void generate_GETRETVAL (quad* quad);  
extern void generate_FUNCSTART (quad* quad);  
extern void generate_RETURN (quad* quad);  
extern void generate_FUNCEND (quad* quad);
typedef void (*generator_func_t) (quad*);
unsigned nextinstructionlabel (void) ;
void patch_incomplete_jumps();
void expand_t(void);
void emit_vm(instruction  instruction);
void make_operand (struct expr* e, vmarg *arg);
void generate_relational (enum vmopcode op,struct quad *quad);
extern struct incomplete_jump* ij_head;
void Instruction_Print();
void generate_all ();
void funcpush(struct SymbolTableEntry *x);
struct SymbolTableEntry* funcpop();
void backpatch (unsigned int instNo, unsigned int label);
void append(SymbolTableEntry *x, int y);
void patch_incomplete_jumps();
void print_instruction();