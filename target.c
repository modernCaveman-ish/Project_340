#include "target.h"

struct instruction* instructions = (struct instruction*) 0;
unsigned totalInstr = 0;
unsigned int currInstr = 0;

extern int yylineno;


//EMIT
void emit_vm(struct instruction * instruction){
		if(currInstr == totalInstr)
			expand_t();
		
		struct	instruction *p = instructions+currInstr++;
		p->op = op;
		p->result = result;
		p->arg1 = arg1;
		p->arg2 = arg2;
		p->srcLine = line;			
}
void expand_t(void){

	assert (totalInstr==currInstr);
	struct instruction* p = (struct instruction*) malloc (NEW_SIZE_T);
	if(instructions){
		memcpy(p, instructions, CURR_SIZE_T);
		free(instructions);
	}
	instructions = p;
	totalInstr += EXPAND_SIZE;
}

unsigned nextinstrlabel (void) 
   { return currInstr; }

/*
void patchlabel (unsigned int quadNo, unsigned int label) { 
   assert(quadNo < currQuad);
   quads[quadNo].label = label;
   
}*/

/*pinakes statherwn timwn kai synarthsewn*/
unsigned consts_newstring(char*s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(char*s);
unsigned userfuncs_newfunc(symbol*sym);

void make_operand (expr* e, vmarg* arg) {
	
	switch (e->type) { 
	
		/* All those below use a variable for storage */ 
		case var_e : 
		case tableitem_e: 
		case arithexpr_e: 
		case boolexpr_e: 
		case newtable_e:{	

        assert(e->sym); 
			arg->val = e->sym->offset; 

			switch (e->sym->space) { 
				case programvar: arg->type = global_a; break; 
				case functionlocal: arg->type = local_a; break; 
				case formalarg: arg->type = formal_a; break;
				default: assert(0); 
            }
            break;
        }        
        /*Constants*/
        case constbool_e: { 
			arg->val = e->boolConst; 
			arg->type = bool_a; 	break; 
		} 
		case consttring_e: {
			arg->val = consts_newstring(e->strConst); 
			arg->type = string_a; break; 
		} 
		
		case costnum_e: {
			arg->val = consts_newnumber(e->numConst);
			arg->type = number_a; break; 
		} 
		case nil_e: arg->type = nil_a ; break; 

		/* Functions */ 
		case programfunc_e: {
			arg->type = userfunc_a;
            arg->val = e->sym>taddress;
			/* or alternatively ...*/
			arg->val = userfuncs_newfunc(e->sym);
			break; 
		} 
		case libraryfunc_e: {
			arg->type = libfunc_a; 
			arg->val = libfuncs_newused(e->sym->name); 
			break; 
		} 
		default: assert(0); 
	}
}


void make_numberopearand (vmarg* arg, double val) { 
	arg->val = consts_newnumber(val); 
	arg->type = number_a; 
} 
void make_booloperand (vmarg* arg, unsigned val) { 
	arg->val = val; 
	arg->type = bool_a; 
} 
void make_retvaloperand (vmarg* arg) {
	arg->type = retval_a; 
} 

void add_incomplete_jump (unsigned instrNo, unsigned iaddress);

void patch_incomplete_jumps() { 
	for each incomplete jump x do { 
 	   if x.iaddress = intermediate code size then 
		instructions[x.instrNo].result = target code size; 
	else 
		instructions[x.instrNo].result = quads[x.iaddress].taddress;
 	}
}

void generate (vmopcode op,quad* quad) { 
    instruction t; 
    t.opcode = op; 
    make_operand(quad->arg1, &t.arg1); 
    make_operand(quad->arg2, &t.arg2); 
    make_operand(quad->result, &t.result); 
    quad.taddress = nextinstructionlabel(); 
    emit_vm(t); 
} 

generate_ADD (quad) { generate(add_v, quad); } 
generate_SUB (quad) { generate(sub_v,quad);}
generate_MUL (quad) { generate(mul_v, quad); } 
generate_DIV (quad) { generate(div_v, quad); } 
generate_MOD (quad) { generate(mod_v, quad); }
generate_NEWTABLE (quad) { generate(newtable_v, quad); } 
generate_TABLEGETELM (quad) { generate(tablegetelem_v, quad); } 
generate_TABLESETELEM (quad) { generate(tablesetelem_v, quad); } 
generate_ASSIGN (quad) { generate(assign_v, quad); } 
generate_NOP () { instruction t; t.opcode=nop_v; emit_vm(t)};

void generate_relational (vmopcode op,quad *quad) {
	instruction t;
	t.opcode = op;
	make_operand(quad->arg1, &t.arg1);
	make_operand(quad->arg2, &t.arg2);
	
	t->result->type = label_a;
	if (quad.label < currprocessedquad(quad))
		t->result->val = quads[quad->label]->taddress;
	}else{
		add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->taddress = nextinstructionlabel();
	emit_vm(t);
}

void generate_JUMP (quad)             { generate_relational(jump_v, quad); }
void generate_IF_EQ (quad)            { generate_relational(jeq_v, quad); }
void generate_IF_NOTEQ( quad)          { generate_relational(jne_v, quad); }
void generate_IF_GREATER (quad)       { generate_relational(jgt_v, quad); }
void generate_IF_GREATEREQ(quad)      { generate_relational(jge_v, quad); }
void generate_IF_LESS (quad)          { generate_relational(jlt_v, quad); }
void generate_IF_LESSEQ (quad)        { generate_relational(jle_v, quad); } 


void generate_NOT (quad *quad) {

	quad->taddress = nextinstructionlabel(); 
	instruction t;
	t.opcode = jeq_v;

	make_operand(quad->arg1, &t.arg1);
	make_booloperand(&t->arg2,false);
	t.result.type = label_a;
	t.result.value = nextinstructionlabel()+3; 
	emit_vm(t);

	t.opcode = assign_v;

	make_booloperand(&t.arg1,false);
	reset_operand(&t.arg2);
	make_operand(quad.result, &t.result); 
	emit_vm(t);

	t.opcode = jump_v;
	reset_operand (&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.value = nextinstructionlabel()+2;  
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,true);
	reset_operand(&t.arg2);
	make_operand(quad.result, &t.result);
	emit_vm(t);
}


void generate_OR (quad *quad) {

	quad->taddress = nextinstructionlabel();
	instruction t;

	t->opcode = jeq_v;
	make_operand(quad->arg1, &t.arg1);
	make_booloperand(&t->arg2, true);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+4; 
	emit(t);

	make_operand(quad->arg2, &t.arg1);
	t->result->value = nextinstructionlabel()+3; 
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t->arg1 ,false);
	reset_operand(&t->arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);

	t.opcode = jump_v;
	reset_operand (&t.arg1);
	reset_operand(&t.arg2);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+2;
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,true);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);
}


void generate_PARAM(quad* quad) {

	quad.taddress = nextinstructionlabel();
	instruction t;

	t->opcode = pusharg_v;
	make_operand(quad->arg1, &t.arg1);
	emit_vm(t);
}

void generate_CALL(quad * quad) {
	quad->taddress = nextinstructionlabel();
	instruction t;

	t->opcode = call_v;
	make_operand(quad->arg1, &t.result);
	emit_vm(t);	
}

void generate_GETRETVAL(quad *quad) {
	quad->taddress = nextinstructionlabel();
	instruction t;

	t.opcode = assign_v;
	make_operand(quad->result, &t.result);
	make_retvaloperand(&t.arg1);
	emit_vm(t);
}


void generate_FUNCSTART(quad *quad) {	

	f = quad->result->sym;
	f->taddress = nextinstructionlabel(); 
	quad->taddress = nextinstructionlabel();

  //push(funcstack,f);
	
   instruction t;
	t.opcode = funcenter_v;
	make_operand(quad->result, &t.result); 
	
	emit_vm(t);
}

void generate_RETURN(quad *quad) {

	quad->taddress = nextinstructionlabel(); 
	instruction t;

		t->opcode = assign_v;
		make_retvaloperand(&t.result);
		make_operand(quad->result, &t.arg1);
 
		emit_vm(t);

    //f=top(funcstack);
	    t.opcode = jump_v; 
        reset_operand(&t.arg1);
    	reset_operand(&t.arg2);
	    t.result.type = label_a; 
	    emit_vm(t);
}

void generate_FUNCEND(quad* quad) {

	//f = pop(funcstack);
    //backpatch(f.returnList,nextinstructionlabel());

	quad->taddress = nextinstructionlabel(); 
	instruction t;
	t->opcode = funcexit_v;
	make_operand(quad->result, &t.result); 

	emit_vm(t);                    
	
}

generator_func_t generators[] = {

	generate_ASSIGN,
	generate_ADD, 
	generate_SUB, 
	generate_MUL, 
	generate_DIV, 
	generate_MOD,
	generate_NOT, 
    generate_OR, 
	generate_IF_EQ, 
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ, 
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RETURN, 
	generate_GETRETVAL,
	generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
	generate_TABLEGETELM,
	generate_TABLESETELEM, 
	generate_NOP,
   	generate_JUMP,
   	
};


void generate_all () {
	unsigned i;
	for (i = 0; i<total; ++i) {
		(*generators[quads[i].op])(quads+i);
	}
} 

char* vmopcode[]={"assign_v", "add_v", "sub_v", 
	"mul_v", "div_v", "mod_v", 
	"uminus_v", "and_v", "or_v", 
	"not_v", "jeq_v"," jne_v", 
	"jle_v", "jge_v", "jlt_v", 
	"jgt_v"," call_v"," pusharg_v", 
	"funcenter_v", "funcexit_v", "newtable_v", 
	"funcend_op", "tablegetelem_v", 
	"tablesetelem_v", "nop_v","jump_v"};

void print_symbol(expr *e){
   // if(e==NULL)return;
   // if(e->sym!=NULL)
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

void (*vmarg_prints[11])(vmarg *) = {
    print_symbol,
    print_symbol,
    print_symbol,
    print_symbol,
    print_num,
    print_string,
    printf_bool,
    print_nil,
    print_symbol,
    print_symbol,
    print_symbol,
};

void print_expr (struct vmarg *e) {
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
        vmarg_prints[e->type](e);
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

       printf("%d",tmpquad->label);
   }
}

void Instruction_Print(){
//quad# opcode,result,arg1,arg2,label
	struct instruction *tmpinstr;
	int i;
    
    printf("quad#\topcode\t\t\t result\t\t\targ1\t\t\targ2\t\t\tlabel\t\t\t\n");
	
    for(i=0;i<currInstr;i++){
        printf("%d\t",i);
       
        printf("%s\t\t", vmopcode[quads[i].op]);
        if(quads[i].result != NULL){
            print_expr(quads[i].result);
    
            print_expr(quads[i].arg1);
                //     if(i==3)break;
            print_expr(quads[i].arg2);
        }else if(quads[i].arg1){
            print_expr(quads[i].arg1);
            print_expr(quads[i].arg2);
        }
        print_labels(&quads[i]);
        printf("\n");
    }
}


