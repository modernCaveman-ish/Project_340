
#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m)) 
#define CURR_SIZE_T (total*sizeof(struct instruction))
#define NEW_SIZE_T (EXPAND_SIZE*sizeof(struct instruction + CURR_SIZE_T)


double* numConsts;
unsigned int totalNumConsts;
char** stringConsts ;
unsigned int totalStringConsts ;
char** namedLibfuncs ;
unsigned int totalNamedLibfuncs ;
userfunc** userFuncs ;
unsigned int totalUserFuncs ;


enum vmopcode { 
	assign_v, 	add_v,	sub_v,
	mul_v,	div_v,	mod_v,
	uminus_v,	and_v,	or_v,
	not_v,	jeq_v,	jne_v,
	jle_v,	jge_v,	jlt_v,
	jgt_v,	call_v,	pusharg_v,
	funcenter_v, funcexit_v,	newtable_v,
	tablegetelem_v,	tablesetelem_v,	nop_v,
	jump_v
} ; 
	
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
	retval_a    =10  
} vmarg_t; 


struct vmarg { 
	vmarg_t type; 
	unsigned  val; 
}; 

struct instruction { 
	vmopcode opcode; 
	vmarg result; 
	vmarg arg1; 
	vmarg arg2; 
	unsigned int srcLine; 
}; 

struct userfunc { 
	unsigned int address; 
	unsigned int localSize; 
	char* id; 
}; 

incomplete_jump* ij_head =(incomplete_jump*) 0;
unsigned ij_total = 0;

struct incomplete_jump {
	unsigned 	instrNo; // The jump instruction number.
	unsigned    iaddress;// The i-code jump-target address.  
	struct incomplete_jump* next;// A trivial linked list. 
} ; 

extern void generate_ADD (quad*);  
extern void generate_SUB (quad*);   
extern void generate_MUL (quad*);  
extern void generate_DIV (quad*);   
extern void generate_MOD (quad*); 
extern void generate_NEWTABLE (quad*);  
extern void generate_TABLEGETELM (quad*);   
extern void generate_TABLESETELEM (quad*);  
extern void generate_ASSIGN (quad*);   
extern void generate_NOP (quad* );  
extern void generate_JUMP (quad*);  
extern void generate_IF_EQ (quad*);  
extern void generate_IF_NOTEQ (quad*);  
extern void generate_IF_GREATER (quad*);   
extern void generate_IF_GREATEREQ (quad*);  
extern void generate_IF_LESS (quad*);  
extern void generate_IF_LESSEQ (quad*);  
extern void generate_NOT (quad*);  
extern void generate_OR (quad*);  
extern void generate_PARAM (quad*);  
extern void generate_CALL (quad*);  
extern void generate_GETRETVAL (quad*);  
extern void generate_FUNCSTART (quad* );  
extern void generate_RETURN (quad* );  
extern void generate_FUNCEND (quad* );
unsigned nextinstrlabel (void) ;
void expand_t(void);
void emit_vm(instruction t);
