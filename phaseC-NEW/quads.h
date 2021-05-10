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
	tablegetelem_op, tablesetelem_op,jump_op

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

	constnum_e,
	constbool_e,
	consttring_e,

	nil_e,
}expr_t ;

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

struct breaklist{
	int numquad;
	struct breaklist* next;
} ;

struct continuelist{
	int numquad;
	struct continuelist* next;
} ;

struct stmt_t{
	//int breaklist, contList;
	//int ta exei
	//akouw eee nai alla giati????/elega mhpws htane opws ta egrapsa kai meta desmeyame block me malloc kai pernousame ta
	  //data //pou?
	struct breaklist* breaklist;
	struct contList* continuelist;
};

//void make_stmt (struct stmt_t* s);

//int newlist (int i);

void print_labels(quad *q);
void print_symbol(expr *e);
void print_num(expr *e);
void print_string(expr *e);
void print_bool(expr * e);
unsigned int nextquad(); 
void Quad_Print();
void expand();	
struct expr* emit_iftableitem(struct expr* e);
struct expr* lvalue_expr (SymbolTableEntry* sym);
unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
struct expr* newexpr_conststring (char* s);
struct SymbolTableEntry *newtemp();
char * newtempname() ;
void resettemp();
void emit(iopcode op,struct expr* arg1,struct expr* arg2,struct expr* result,unsigned label,unsigned line);
void enterscopespace();
void exitscopespace();
void resetfunctionlocalsoffset();
void resetformalargsoffset() ;
struct expr* newexpr (expr_t t);
expr* newexpr_conststring (char* s);
expr* newexpr_constnum (double i);
expr* newexpr_constbool (unsigned int b);
struct expr* member_item (struct expr* lv, char* name);
struct expr* assignexpr_lvalue_expr(struct expr* lvalue, struct expr* exp);
void patchlabel (unsigned int quadNo, unsigned int label);
void patchlist(int list, int label);
struct expr* newexpr_constnil();
void patchlist(int list, int label);
void make_stmt (struct stmt_t* s);
int newlist (int i);
#endif
