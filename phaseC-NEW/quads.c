#include "quads.h"

unsigned programVarOffset = 0;
unsigned functionlocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

/*

lvalue -> id{
    symbol = ; //lookup $id or create new
    $lvalue = newexpr(var_e);
    $lvalue -> sym = symbol;
}

const -> number{
    $const = newexpr(constnum_e);
    $const -> numCost = $number;
}

expr -> expr1 + expr2{
    $expr = newexpr(arithexpr_e);
    $expr -> sym = newtemp();
    emit(add, $expr1, $expr2, $expr);
}

assignexpr->lvalue = expr{
    emit(assign, $expr, NULL, $lvalue); //other checks and emits here as well
}

epxr* emit_iftableitem(expr* e){
    if (e->type != tableitem_e)
        return e;
    else{
        epxr* result = newexpr(var_e);
        result->sym = newtemp();
        emit(tablegetelem, e, e->index, result);

        return result;
    }
}

*/

void enterscopespace(void){++scopeSpaceCounter;}

void exitscopespace(void){assert(scopeSpaceCounter>1); --scopeSpaceCounter;}

struct quad*   quads = (struct quad*) 0;
unsigned    total = 0;
unsigned int    currQuad = 0;

void expand(void){
	assert (total==currQuad);
	struct quad* p = (struct quad*) malloc (NEW_SIZE);
	if(quads){
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads = p;
	total += EXPAND_SIZE;
}

enum scopespace_t currscopespace(void){
	if(scopeSpaceCounter == 1)
		return programvar;
	else
	if(scopeSpaceCounter % 2 == 0)
		return formalarg;
	else
		return functionlocal;
}

unsigned currscopeoffset (void){
    switch (currscopespace()){
        case programvar         : return programVarOffset;
        case functionlocal      : return functionlocalOffset;
        case formalarg          : return formalArgOffset;
        default                 : assert(0);
    }
}

void inccurrscopeoffset (void){
    switch (currscopespace()){
        case programvar          : ++programVarOffset; break;
        case functionlocal      : ++functionlocalOffset; break;
        case formalarg          : ++formalArgOffset; break;
        default                 : assert(0);
    }
}


void emit(	iopcode op,
			struct	expr* arg1,
			struct	expr* arg2,
			struct	expr* result,
			unsigned label,
			unsigned line){

			if(currQuad == total)
				expand();
			
			struct	quad *p = quads+currQuad++;
			p->op = op;
			p->arg1 = arg1;
			p->arg2 = arg2;
			p->result = result;
			p->label = label;
			p->line = line;
			
}

struct expr*lvalue_expr (SymbolTableEntry* sym){

  assert (sym);
  struct expr*e =(struct expr*)malloc (sizeof(struct expr));
  memset(e,0,sizeof(struct expr));

    e->next =(struct expr*)0;
    e->sym = sym;

    switch (sym->typet){

    case var_s:			e->type=var_e;break;
    case programfunc_s: 		e->type=programfunc_e;break;
    case libraryfunc_s:	       e->type=libraryfunc_e;break;
    default:assert(0);

    }

return e;
}

int tempcounter = 0;
extern SymTable_T table;

char * newtempname() { 
    
    char tempname[200];// tyxaio wste na nai arketa megalo na xwresei olo to onoma
	//int number=0;
    sprintf(tempname,"_t%u",tempcounter);//opou to number prpei na
    char *newtempname2 = strdup(tempname);
    return newtempname2;
}

void resettemp() { tempcounter = 0; }

extern int scope;
struct SymbolTableEntry *newtemp() {
    char *name = newtempname();
    //sym = lookup(name, currscope());

    struct SymbolTableEntry* sym = SymTable_contains2(table, name, scope);

    if (sym == NULL)
      //  return newsymbol(name);
       return SymTable_put(table, name, 0, scope,  GLOBAL);//fix

    else
        return sym;
}

//add newexpr
//fix emit_iftableitem
//dimiourgiste mia print sta quads opws orizei to FAQ

struct expr* assignexpr_lvalue_expr(struct expr* lvalue, struct expr* exp){
    struct expr* assignexpr;
    if (lvalue->type = tableitem_e){
        emit( tablesetelem_op,lvalue,lvalue->index,exp,0,0);
        assignexpr = emit_iftableitem(lvalue);
        assignexpr->type = assignexpr_e;
    }else{
        emit(assign_op, exp, NULL, lvalue, 0, 0);
        assignexpr =  newexpr(assignexpr_e);
        assignexpr->sym = newtemp();
        emit(assign_op, lvalue, NULL, assignexpr, 0,0);
    }
}
