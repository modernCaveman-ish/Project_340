#ifndef QUADS
#define QUADS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashtbl.h"
#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(struct quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(struct quad) + CURR_SIZE)


typedef enum iopcode {
	assign_op, add_op, sub_op, 
	mul_op, div_op, mod_op, 
	uminus_op, and_op, or_op, 
	not_op, if_eq_op, if_noteq_op, 
	if_lesseq_op, if_greatereq_op, if_less_op, 
	if_greater_op, call_op, param_op, 
	ret_op, getretval_op, funcstart_op, 
	funcend_op, tablecreate_op, 
	tablegetelem_op, tablesetelem_op, jump_op
} iopcode;


typedef enum expr_t {
	var_e,
	tableitem_e,

	programfunc_e,
	libraryfunc_e,

	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,

	costnum_e,
	constbool_e,
	consttring_e,

	nil_e,
}expr_t ;




/*
struct symbol
{
	enum symbol_t			type;
	char*				name;
	enum scopespace_t		space;
	unsigned			offset;
	unsigned			line;	
};*/



typedef struct expr{
	enum expr_t type;
	struct SymbolTableEntry* sym;
	struct expr* index;
	double numConst;
	char* strConst;
	unsigned char boolConst;
	struct expr* next;
}expr;

typedef struct quad{
	enum iopcode op;
	struct expr* result;
	struct expr* arg1;
	struct expr* arg2;
	unsigned int label;
	unsigned int line;	
}quad;

struct call {
	struct expr* elist;
	unsigned char method;
	char* name;
};


	
struct expr* lvalue_expr (SymbolTableEntry* sym);


#endif