#include "quads.h"

unsigned programVarOffset = 0;
unsigned functionlocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

struct quad* quads = (struct quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

//fix emit_iftableitem

/*
struct epxr* emit_iftableitem(struct expr* e){
    if (e->type != tableitem_e)
        return e;
    else{
        struct expr* result = newexpr(var_e);
        result->sym = newtemp();
        result->type = e->type;

        emit(tablegetelem_op, e, e->index, result,0,yylineno);
        return result;
    }
}
*/


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

void enterscopespace ()
    { ++scopeSpaceCounter; }

void exitscopespace ()
    { assert(scopeSpaceCounter>1); --scopeSpaceCounter; }


//EMIT
void emit(	iopcode op,
			struct	expr* arg1,
			struct	expr* arg2,
			struct	expr* result,
			unsigned label,
			unsigned line){

            //printf("To $2->%s\n", arg2->sym->name);
            printf("mphke sthn emit\n");

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

    case var_s: e->type=var_e;break;
    case programfunc_s: e->type=programfunc_e;break;
    case libraryfunc_s:	e->type=libraryfunc_e;break;
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
struct expr* newexpr (expr_t t) {
	struct expr* e = (struct expr*) malloc(sizeof(struct expr)); 
	memset(e, 0, sizeof(struct expr));
	e->type = t;
	return e;
}

struct expr* newexpr_conststring (char* s) {
	struct expr* e = newexpr(consttring_e); 
	e->strConst = strdup(s);
	return e;
}

struct expr* newexpr_constnum (double i) {
	expr* e = newexpr(costnum_e); 
	e->numConst = i;
	return e;
}

struct expr* newexpr_constbool (unsigned int b) {
	struct expr* e = newexpr(constbool_e);
	//e->boolConst = !!b;//true h false
	return e;
}

//dimiourgiste mia print sta quads opws orizei to FAQ

/*void Quad_Print(){

//quad# opcode,result,arg1,arg2,label}
	struct quad *tmpquad;
	int i=0;

	for(i=0;i<currQuad;i++){

//logika prp na elgxoume ti sygkrinoume
 printf("quad: %d\t opcode: %s \t result:%s \t arg1 %s\t agr2:%s \t label :%d \t\n",i, iopcode, tmpquad->result->strConst, tmpquad->arg1->strConst, tmpquad->arg2->strConst, tmpquad->label);

        }
*/

//BAZW KAI AFTO SE SXOLIO
/*
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
*/

/*

struct expr* member_item (struct expr* lv, char* name) {
	lv = emit_iftableitem(lv); // Emit code if r-value use of table item
	struct expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = lv->sym;
	ti->index = newexpr_conststring(name); // Const string index
	return ti;
}

struct expr* make_call (expr* lv, expr* reversed_elist) {
	struct expr* func = emit_iftableitem(lv);
	while (reversed_elist) {
		emit(param, reversed_elist, NULL, NULL);
		reversed_elist = reversed_elist->next;
	}
	emit(call_op, func,NULL, NULL);
	expr* result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval_op, NULL, NULL, result);
	return result;

}
void comperror (char* format, ...);


void check_arith(expr* e) , const char* context){
    if  (e->type== constbool_e      ||
        e->type == consttring_e     ||
        e->type == nil_e            ||
        e->type == newtable_e       ||
        e->type == programfunc_e    ||
        e->type == libraryfunc_e    ||
        e->type == boolexpr_e)
      comperror("Illegal expr used in %s!", context);
}



void resetformalargsoffset() 
    { formalArgOffset = 0; }

void resetfunctionlocalsoffset() 
    { functionLocalOffset = 0; }

void restorecurrscopeoffset (unsigned n) {
    switch (currscopespace()) {
      case programvar : programVarOffset = n; break;
      case functionlocal : functionLocalOffset = n; break; 
      case formalarg  : formalArgOffset = n; break; 
      default: assert(0);
	}
}

unsigned nextquadlabel (void) 
   { return currQuad; }

void patchlabel (unsigned int quadNo, unsigned int label) { 
   assert(quadNo - 1 < currQuad);
   quads[quadNo - 1].label = label;
   
}
*/

