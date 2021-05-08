#include "quads.h"
#include "hashtbl.h"
unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0; 
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

struct quad* quads = (struct quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

extern int yylineno;

//fix emit_iftableitem

struct expr* emit_iftableitem(struct expr* e){
    if (e->type != tableitem_e)
        return e;
    else{
        struct expr* result = newexpr(var_e);
        result->sym = newtemp();
        result->type = e->type;
	result->strConst=result->sym->name;
        emit(tablegetelem_op, e, e->index, result,0,yylineno);
        return result;
    }
}

unsigned int nextquad (void) {
 return currQuad+1;
 }


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
        case functionlocal      : return functionLocalOffset ;
        rmalarg          : return formalArgOffset;
        default                 : assert(0);
    }
}

void inccurrscopeoffset (void){
    switch (currscopespace()){
        case programvar          : ++programVarOffset; break;
        case functionlocal      : ++functionLocalOffset ; break;
        case formalarg          : ++formalArgOffset; break;
        default                 : assert(0);
    }
}

void enterscopespace ()
    { ++scopeSpaceCounter; }

void exitscopespace ()
    { assert(scopeSpaceCounter>1); --scopeSpaceCounter; }

void resetformalargsoffset() 
    { formalArgOffset = 0; }

void resetfunctionlocalsoffset() 
    { functionLocalOffset = 0; }

void restorecurrscopeoffset (unsigned n) {
    switch (currscopespace()) {
      case programvar : programVarOffset = n; break;
      case functionlocal : functionLocalOffset  = n; break; 
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


//EMIT
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
    tempcounter++;
}

void resettemp() { tempcounter = 0; }

extern int scope;

struct SymbolTableEntry *newtemp() {
    char *name = newtempname(); 
    struct SymbolTableEntry* sym = SymTable_contains2(table, name, scope);
    //sym = lookup(name, currscope());
   
  
    if (sym == NULL)
      //  return newsymbol(name);
       return SymTable_put(table, name, yylineno, scope, GLOBAL);

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
	struct expr* e = newexpr(constnum_e); 
	e->numConst = i;
	return e;
}

struct expr* newexpr_constbool (unsigned int b) {
	struct expr* e = newexpr(constbool_e);
		if(b == 1){
			e->boolConst =1;
	        }else{
			e->boolConst = 0;
		}
	return e;
}

struct expr* newexpr_constnil () {
	struct expr* e = newexpr(nil_e);
	//e->boolConst = b;
	return e;
}

struct expr* member_item (struct expr* lv, char* name) {
	lv = emit_iftableitem(lv); // Emit code if r-value use of table item
	struct expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = lv->sym;
	ti->strConst=ti->sym->name;
	ti->index = newexpr_conststring(name); // Const string index
	return ti;
}

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


char * opcode[]={ "assign_op", "add_op", "sub_op", 
	"mul_op", "div_op", "mod_op", 
	"uminus_op", "and_op", "or_op", 
	"not_op", "if_eq_op", "if_noteq_op", 
	"if_lesseq_op", "if_greatereq_op", "if_less_op", 
	"if_greater_op", "call_op",  "param_op" 
	"ret_op", "getretval_op", "funcstart_op", 
	"funcend_op", "tablecreate_op", 
	"tablegetelem_op"," tablesetelem_op", "jump_op"};


void print_symbol(expr *e){
    printf("%s", e->sym->name);
}


void print_num(expr *e){
    printf("%f", e->numConst);
}

void print_string(expr *e){
    printf("%s", e->strConst);
}

void printf_bool(expr * e){
    printf("%s", e->boolConst==1?"true":"false");
}

void print_nil(expr * e){
    printf("nil");
}

void (*expr_prints[12])(expr *) = {
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_num,
    printf_bool,
    print_string,
    print_nil
};




void print_expr (struct expr *e) {
    if(e == NULL){
        printf("\t\t\t");
    } else{
        //analogws to type prepei na ektypwseis to katallilo pedio tou expr
        //px constring_e ektypws to strconst
     /*   if(expr->type == 8){ //print ta noymera
         printf("%d\t\t\t", expr->numConst);
        }  else if(expr->type == 10){
            printf("%s\t\t\t", expr->strConst);
        } else if(expr->type == 9){
            printf("%c\t\t\t", expr->boolConst);
        }*/
        expr_prints[e->type](e);
     printf("\t\t\t");
    }
}


void print_labels(quad *q){

//check and print the lable if eligible
   struct quad *tmpquad = q;

   if (tmpquad->op==jump_op||
        tmpquad->op==if_greatereq_op||
        tmpquad->op==if_less_op||
        tmpquad->op==if_eq_op||tmpquad->op==if_lesseq_op||tmpquad->op==if_greater_op){

       printf("%d\n",tmpquad->label);
   }
    
    
}

void Quad_Print(){
//quad# opcode,result,arg1,arg2,label
	struct quad *tmpquad;
	int i;
    
    printf("quad#\topcode\t\t\tresult\t\t\targ1\t\t\targ2\t\t\tlabel\t\t\t \n");
	
    for(i=0;i<currQuad;i++){
        printf("%d\t",i);
        
        printf("%s\t\t\t", opcode[quads[i].op]);
        if(quads[i].result != NULL){
            print_expr(quads[i].result);
            print_expr(quads[i].arg1);
            print_expr(quads[i].arg2);
        }
        print_labels(&quads[i]);
        printf("\n");
    }
}
/*
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

void comperror (char* format, ...);const char* context
*/

void check_arith(expr* e){
    if  (e->type== constbool_e      ||
        e->type == consttring_e     ||
        e->type == nil_e            ||
        e->type == newtable_e       ||
        e->type == programfunc_e    ||
        e->type == libraryfunc_e    ||
        e->type == boolexpr_e)
      printf("Illegal expr used \n");
}


