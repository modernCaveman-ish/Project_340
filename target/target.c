#include "target.h"
#include "hashtbl.h"
#include "quads.h"

struct instruction* instructions = (struct instruction*) 0;
unsigned totalInstr = 0;
unsigned int currInstr = 0;

extern int yylineno;

//EMIT
void emit_vm(struct instruction * instruction){
		if(currInstr == totalInstr)
			expand_t();
		
		struct	instruction *p = instructions+currInstr++;
		p->opcode = instruction->opcode;
		p->result = instruction->result;
		p->arg1 = instruction->arg1;
		p->arg2 = instruction->arg2;
		p->srcLine = instruction->srcLine;			
}


void expand_t(void){

	assert (totalInstr==currInstr);
	struct instruction* p = (struct instruction*) malloc (sizNEW_SIZE_T);
	if(instructions){
		memcpy(p, instructions, sizeof(CURR_SIZE_T));
		free(instructions);
	}
	instructions = p;
	totalInstr += EXPAND_SIZE;
}

unsigned nextinstrlabel (void) 
   { return currInstr; }

/*
void patchlabel (unsigned int quadNo, unsigned int label) { 
   assert(quadNo < currInstr);
   quads[quadNo].label = label;*/
   
unsigned consts_newstring(char*s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(char*s);
unsigned userfuncs_newfunc(SymbolTableEntry*sym);


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
		
		case constnum_e: {
			arg->val = consts_newnumber(e->numConst);
			arg->type = number_a; break; 
		} 
		case nil_e: arg->type = nil_a ; break; 

		/* Functions */ 
		case programfunc_e: {
			arg->type = userfunc_a;
            arg->val = e->sym->iaddress; 
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

/*
void patch_incomplete_jumps() { 
	for each incomplete jump x do { 
 	   if x.iaddress = intermediate code size then 
		instructions[x.instrNo].result = target code size; 
	else 
		instructions[x.instrNo].result = quads[x.iaddress].taddress;
 	}
} */

void generate (vmopcode op,quad* quad) { 
    instruction t; 
    t.opcode = op; 
    make_operand(quad->arg1, &t.arg1); 
    make_operand(quad->arg2, &t.arg2); 
    make_operand(quad->result, &t.result); 
    quad->iaddress = nextinstructionlabel(); 
    emit_vm(t); 
} 

void generate_ADD (quad* quad) { generate(add_v, quad); } 
void generate_SUB (quad* quad) { generate(sub_v,quad);}
void generate_MUL (quad* quad) { generate(mul_v, quad); } 
void generate_DIV (quad* quad) { generate(div_v, quad); } 
void generate_MOD (quad* quad) { generate(mod_v, quad); }
void generate_NEWTABLE (quad* quad) { generate(newtable_v, quad); } 
void generate_TABLEGETELM (quad* quad) { generate(tablegetelem_v, quad); } 
void generate_TABLESETELEM (quad* quad) { generate(tablesetelem_v, quad); } 
void generate_ASSIGN (quad* quad) { generate(assign_v, quad); } 
void generate_NOP (quad* quad) { instruction t; t.opcode=nop_v; emit_vm(t)};

void generate_relational (enum vmopcode op,struct quad *quad) {
	instruction t;
	t.opcode = op;
	make_operand(quad->arg1, &t.arg1);
	make_operand(quad->arg2, &t.arg2);
	
	t->result->type = label_a;
	if (quad.label < currprocessedquad(quad))
		t->result->val = quads[quad->label]->iaddress;
	}else{
		add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->iaddress = nextinstructionlabel();
	emit_vm(t);
}

void generate_JUMP (quad* quad)             { generate_relational(jump_v, quad); }
void generate_IF_EQ (quad* quad)            { generate_relational(jeq_v, quad); }
void generate_IF_NOTEQ( quad* quad)          { generate_relational(jne_v, quad); }
void generate_IF_GREATER (quad* quad)       { generate_relational(jgt_v, quad); }
void generate_IF_GREATEREQ(quad* quad)      { generate_relational(jge_v, quad); }
void generate_IF_LESS (quad* quad)          { generate_relational(jlt_v, quad); }
void generate_IF_LESSEQ (quad* quad)        { generate_relational(jle_v, quad); } 


void generate_NOT (quad *quad) {

	quad->iaddress = nextinstructionlabel(); 
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
	t->result.type = label_a;
	t->result.value = nextinstructionlabel()+2;  
	emit_vm(t);

	t->opcode = assign_v;
	make_booloperand(&t.arg1,true);
	reset_operand(&t.arg2);
	make_operand(quad.result, &t.result);
	emit_vm(t);
}


void generate_OR (quad *quad) {

	quad->iaddress = nextinstructionlabel();
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

	quad->iaddress = nextinstructionlabel();
	instruction t;

	t->opcode = pusharg_v;
	make_operand(quad->arg1, &t.arg1);
	emit_vm(t);
}

void generate_CALL(quad * quad) {
	quad->iaddress = nextinstructionlabel();
	instruction t;

	t->opcode = call_v;
	make_operand(quad->arg1, &t.result);
	emit_vm(t);	
}

void generate_GETRETVAL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = assign_v;
	make_operand(quad->result, &t.result);
	make_retvaloperand(&t.arg1);
	emit_vm(t);
}


void generate_FUNCSTART(quad *quad) {	

	f = quad->result->sym;
	f->iaddress = nextinstructionlabel(); 
	quad->iaddress = nextinstructionlabel();

  //push(funcstack,f);
	
   instruction t;
	t.opcode = funcenter_v;
	make_operand(quad->result, &t.result); 
	
	emit_vm(t);
}

void generate_RETURN(quad *quad) {

	quad->iaddress = nextinstructionlabel(); 
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

	quad->iaddress = nextinstructionlabel(); 
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

