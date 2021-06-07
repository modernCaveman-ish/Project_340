#include "target.h"
#include "hashtbl.h"
#include "quads.h"
#include "string.h"

struct instruction* instructions = (struct instruction*) 0;
unsigned totalInstr = 0;
unsigned int currInstr = 0;
incomplete_jump* ij_head =(incomplete_jump*) 0;
unsigned ij_total = 0;

extern quad * quads;
extern int currQuad;
extern int total;
//pinakes
char** stringConsts = NULL;
double* numConsts = NULL;
char** namedLibfuncs = NULL;
userfunc** userFuncs = NULL;

struct func_stack{
   //int x;
   struct SymbolTableEntry *x;
   struct func_stack *next;
};

struct func_stack *func_stack =NULL;

void funcpush(struct SymbolTableEntry *x){
   // printf("push\n");
    struct func_stack *temp;
    temp = (struct func_stack*)malloc(sizeof(struct func_stack));

    temp->x = x;

    temp->next = func_stack;
    func_stack = temp;
}

struct SymbolTableEntry* funcpop(){
    struct func_stack* temp;

    if(func_stack == NULL){
        printf("Error stack is empty\n");
        return NULL;
    }  else {
        temp = func_stack;
        func_stack = func_stack->next;
        free(temp);
    }
    return temp->x;
}

struct SymbolTableEntry* top(){
    struct func_stack* temp;

    if(func_stack == NULL){
        printf("Error stack is empty\n");
        return NULL;
    }  else {
        temp = func_stack;
        //func_stack = func_stack->next;
       // free(temp);
    }
    return temp;
}

unsigned int totalStringConsts=0;

unsigned consts_newstring(char*s){

	
 if(stringConsts==NULL){
	stringConsts = (char**)malloc(sizeof(char*));
	stringConsts[totalStringConsts] = s;
	totalStringConsts++;
    }else{
	char** strings_array;
	strings_array = (char**)malloc(sizeof(char*) * (totalStringConsts+1));
	int i=0;
	while(i<totalStringConsts){
		strings_array[i] = stringConsts[i];
		i++;
	}
		
	//free(stringConsts);
	
	stringConsts= strings_array;
		stringConsts[totalStringConsts] = s;
	
	totalStringConsts++;		
    }

//	printf("\n\n\n%d", totalStringConsts-1 );
	return totalStringConsts-1;
}

unsigned int totalNumConsts=0;

unsigned int consts_newnumber(double n){
    if(numConsts==NULL){
	numConsts = (double*)malloc(sizeof(double));
	numConsts[totalNumConsts] = n;
	totalNumConsts++;
    }else{
	double* numbers_array;
	numbers_array = (double*)malloc(sizeof(double) * (totalNumConsts+1));
	int i=0;
	while(i<totalNumConsts){
		numbers_array[i] = numConsts[i];
		i++;
	}
	numbers_array[totalNumConsts] = n;
		
	free(numConsts);
		
	numConsts = numbers_array;	
	totalNumConsts++;		
     }

	return totalNumConsts-1;	
}

unsigned int totalNamedLibfuncs=0;

unsigned libfuncs_newused(char*s){

 if(namedLibfuncs==NULL){
	namedLibfuncs = (char**)malloc(sizeof(char*));
	namedLibfuncs[totalNamedLibfuncs] = s;
	totalNamedLibfuncs++;
    }else{
	char** libfuncs_array;
	libfuncs_array = (char**)malloc(sizeof(char*) * (totalNamedLibfuncs+1));
	int i=0;
	while(i<totalNamedLibfuncs){
		libfuncs_array[i] = namedLibfuncs[i];
		i++;
	}
	
		
	free(namedLibfuncs);
		
	namedLibfuncs = libfuncs_array;	
	namedLibfuncs[totalNamedLibfuncs] = s;
	totalNamedLibfuncs++;		
     }

	return totalNamedLibfuncs-1;	

}
unsigned int totalUserFuncs = 0;
unsigned userfuncs_newfunc(SymbolTableEntry*sym){

 if(userFuncs==NULL){
		userFuncs = (userfunc**)malloc(sizeof(struct userfunc*));
			userFuncs[totalUserFuncs] = (userfunc *)malloc(sizeof(struct userfunc));
		userFuncs[totalUserFuncs]->address = sym->iaddress;
		userFuncs[totalUserFuncs]->localSize = sym->totalLocals;
		userFuncs[totalUserFuncs]->id = strdup(sym->name);
		totalUserFuncs++;
    }else{
		userfunc** userfuncs_array;
		userfuncs_array = (userfunc**)malloc(sizeof(userfunc*) * (totalUserFuncs+1));
		int i=0;
		while(i<totalUserFuncs){
			userfuncs_array [i] = userFuncs[i];
			i++;
		}
		//=(userFuncs = (userfunc*)malloc(sizeof(struct userfunc*));
		userfuncs_array[totalUserFuncs]=(userfunc*)malloc(sizeof(struct userfunc));
		userfuncs_array[totalUserFuncs]->address = sym->iaddress;
		userfuncs_array[totalUserFuncs]->localSize = sym->totalLocals;
		userfuncs_array[totalUserFuncs]->id =  strdup(sym->name);
			
		free(userFuncs);
			
		userFuncs = userfuncs_array ;
		totalUserFuncs++;		
    }

	return totalUserFuncs-1;	

}

//EMIT
void emit_vm(instruction  instruction){
		if(currInstr == totalInstr)
			expand_t();
		
		struct	instruction *p = instructions+currInstr++;
		p->opcode = instruction.opcode;
		p->result = instruction.result;
		p->arg1 = instruction.arg1;
		p->arg2 = instruction.arg2;
		p->srcLine = instruction.srcLine;			
}

void expand_t(void){

	assert (totalInstr==currInstr);
	struct instruction* p = (struct instruction*) malloc(NEW_SIZE_T);
	if(instructions){
		memcpy(p, instructions, sizeof(CURR_SIZE_T));
		free(instructions);
	}
	instructions = p;
	totalInstr += EXPAND_SIZE;
}

unsigned nextinstructionlabel (void) 
   { return currInstr; }

int currprocessedquad(quad* quad){return currQuad;}

void make_operand (expr* e, vmarg* arg) {
	
	if(e==NULL){
		arg->type=empty;
		return;
	}

	switch (e->type) { 
	
		/* All those below use a variable for storage */ 
		case var_e : 
		case tableitem_e: 
		case arithexpr_e: 
		case boolexpr_e: 
		case newtable_e:
		case assignexpr_e:{	

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

void reset_operand(vmarg* arg){
	arg->type = empty;
	arg->val = 0;
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

void make_niloperand(vmarg* arg){
	arg->val = 0;
	arg->type = nil_a;
}
//void add_incomplete_jump (unsigned instrNo, unsigned iaddress);

void patch_incomplete_jumps() { 
	struct incomplete_jump* x;
	x=ij_head;
	while(x!=NULL) { //for each incomplete jump x do
 	   if( x->iaddress =nextquad()){ // intermediate code size 
		instructions[x->instrNo].result.val = nextinstructionlabel(); //target code size; 
	   }else{ 
		instructions[x->instrNo].result.val = quads[x->iaddress].iaddress;
 	    }
	}
} 

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
void generate_NOP (quad* quad) { instruction t; t.opcode=nop_v; emit_vm(t);};

void generate_relational (enum vmopcode op,struct quad *quad) {
	instruction t;
	t.opcode = op;
	make_operand(quad->arg1, &t.arg1);
	make_operand(quad->arg2, &t.arg2);
	
	t.result.type = label_a;
	if (quad->label < currprocessedquad(quad)){
		t.result.val = quads[quad->label].iaddress;
	}else{
		//add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->iaddress = nextinstructionlabel();
	emit_vm(t);
}

void generate_JUMP (quad* quad)             { generate_relational(jump_v, quad); }
void generate_IF_EQ (quad* quad)            { generate_relational(jeq_v, quad); }
void generate_IF_NOTEQ( quad* quad)         { generate_relational(jne_v, quad); }
void generate_IF_GREATER (quad* quad)       { generate_relational(jgt_v, quad); }
void generate_IF_GREATEREQ(quad* quad)      { generate_relational(jge_v, quad); }
void generate_IF_LESS (quad* quad)          { generate_relational(jlt_v, quad); }
void generate_IF_LESSEQ (quad* quad)        { generate_relational(jle_v, quad); } 

void generate_NOT (quad *quad) {

	quad->iaddress = nextinstructionlabel(); 
	instruction t;

	t.opcode = jeq_v;
	make_operand(quad->arg1, &t.arg1);
	make_booloperand(&t.arg2,0);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+3; 
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result); 
	emit_vm(t);

	t.opcode = jump_v;
	reset_operand (&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;  
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);
}

void generate_AND (quad *quad) {

	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = jeq_v;
	make_operand(quad->arg1, &t.arg1);
	make_booloperand(&t.arg2, 0);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+4; 
	emit_vm(t);

	make_operand(quad->arg2, &t.arg1);
	t.result.val = nextinstructionlabel()+3; 
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1 ,1);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);

	t.opcode = jump_v;
	reset_operand (&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);
}

void generate_OR (quad *quad) {

	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = jeq_v;
	make_operand(quad->arg1, &t.arg1);
	make_booloperand(&t.arg2, 1);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+4; 
	emit_vm(t);

	make_operand(quad->arg2, &t.arg1);
	t.result.val = nextinstructionlabel()+3; 
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1 ,0);
	reset_operand(&t.arg2);
	make_operand(quad->result, &t.result);
	emit_vm(t);

	t.opcode = jump_v;
	reset_operand (&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;
	emit_vm(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(quad->arg1, &t.result);
	emit_vm(t);
}

void generate_PARAM(quad* quad) {

	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = pusharg_v;
	make_operand(quad->arg1, &t.arg1);
	t.result.type=empty;
	emit_vm(t);
}

void generate_CALL(quad * quad) {
	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = call_v;
	make_operand(quad->result, &t.result);
	t.result.type=empty;
	emit_vm(t);	
}

void generate_GETRETVAL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = assign_v;
	make_operand(quad->result, &t.arg1);
	make_retvaloperand(&t.arg2);
		t.result.type=empty;
	emit_vm(t);
}

void generate_FUNCSTART(quad *quad) {	
	struct SymbolTableEntry *f;
	f = quad->arg1->sym;
	f->iaddress = nextinstructionlabel(); 
	quad->iaddress = nextinstructionlabel();
    
  	funcpush(f);
	
   	instruction t;
	t.opcode = funcenter_v;
	make_operand(quad->arg1, &t.arg1); 
	reset_operand (&t.result); 
	reset_operand(&t.arg2);
	
	emit_vm(t);
}

void generate_RETURN(quad *quad) {

	quad->iaddress = nextinstructionlabel(); 
	instruction t;

		t.opcode = assign_v;
		make_retvaloperand(&t.result);
		make_operand(quad->arg1, &t.arg1);
 		emit_vm(t);
	    SymbolTableEntry *f;
    	f=top();
	    t.opcode = jump_v; 
       	    reset_operand(&t.arg1);
    	    reset_operand(&t.arg2);
	    t.result.type = label_a; 
	    emit_vm(t);
}

void generate_FUNCEND(quad* quad) {

	SymbolTableEntry *f  = funcpop();
    //backpatch(f.returnList,nextinstructionlabel());

	quad->iaddress = nextinstructionlabel(); 
	instruction t;
	t.opcode = funcexit_v;
	make_operand(quad->arg1, &t.arg1); 
	 reset_operand(&t.arg2);

	emit_vm(t);                    
	
}

void generate_UMINUS(quad * quad){


	quad->iaddress = nextinstructionlabel();
	instruction t;

	t.opcode = mul_v;
	make_operand(quad->arg1, &t.arg1);
	emit_vm(t);

	t.opcode = assign_v;
	make_operand(quad->result, &t.result);
	make_retvaloperand(&t.arg1);
	emit_vm(t);

}

generator_func_t generators[] = {

	generate_ASSIGN,
	generate_ADD, 
	generate_SUB, 
	generate_MUL, 
	generate_DIV, 
	generate_MOD,
	generate_UMINUS,
	generate_AND,
	generate_OR,
	generate_NOT, 
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
   	generate_JUMP,
	generate_NOP
};

void generate_all () {
	unsigned i;
	for (i = 0; i<currQuad; ++i) {
		(*generators[quads[i].op])(quads+i);
	}
} 

char* vopcode[]={"assign_v", "add_v", "sub_v", 
	"mul_v", "div_v", "mod_v", 
	"uminus_v", "and_v", "or_v", 
	"not_v", "jeq_v"," jne_v", 
	"jle_v", "jge_v", "jlt_v", 
	"jgt_v"," call_v"," pusharg_v", 
	"funcenter_v", "funcexit_v", "newtable_v", 
	"tablegetelem_v", "tablesetelem_v", 
	"jump_v", "nop_v"
};

void print_label(vmarg *e){
   // if(e==NULL)return;
   // if(e->sym!=NULL)
    //printf("%d", e->type);

	printf("%d", e->val);
	printf("(label)\t");
}

void print_global(vmarg *e){
	printf("%d", e->val);
	printf("(global)\t");
}

void print_formal(vmarg *e){
	printf("%d", e->val);
	printf("(formal)\t");
}

void print_local(vmarg *e){
	printf("%d", e->val);
	printf("(local)\t");
}

void print_number(vmarg *e){
    printf("%f", numConsts[e->val]);
	printf("(number)\t");
}

void print_string2(vmarg *e){
    printf("%s", stringConsts[e->val]);
	printf("(string)\t");
}

void print_bool2(vmarg *e){
    printf("%d", e->val);
	printf("(boolean)\t");
}

void print_nil2(vmarg * e){
    printf("nil\t");
}

void print_libfunc(vmarg *e){
	printf("%s", namedLibfuncs[e->val]);
	printf("(libfunc)\t");
}

void print_userfunc(vmarg *e){
	printf("%s", userFuncs[e->val]->id);
	printf("(userfunc)\t");
}

void print_retval(vmarg *e){

	printf("retval\t");
}

void (*vmarg_prints[12])(vmarg *) = {
    print_label,
    print_global,
    print_formal,
    print_local,
    print_number,
    print_string2,
    print_bool2,
    print_nil2,
	print_userfunc,
	print_libfunc,
	print_retval
};

void print_vmarg (struct vmarg *e) {
    if(e == NULL){
        printf(" ");
    } else if (e->type == empty){
		printf(" ");
	}else{
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
     printf(" ");
    }
}

/*
void print_labels(instruction *q){

//check and print the lable if eligible
   struct instruction *tmpinstr = q;
   
   if (tmpinstr->opcode==jump_op||
        tmpinstr->opcode==if_greatereq_op||
        tmpinstr->opcode==if_less_op||
        tmpinstr->opcode==if_eq_op||tmpinstr->opcode==if_lesseq_op||tmpinstr->opcode==if_greater_op){

       printf("%d",tmpinstr->label);
   }
}*/

void Instruction_Print(){
	printf("\n\n\n");
//quad# opcode,result,arg1,arg2,label
	struct quad *tmpinstr;
	int i;
    
   // printf("instuction#\topcode\t\t\t result\t\t\targ1\t\t\targ2\t\t\tlabel\t\t\t\n");
	
    for(i=0;i<currInstr;i++){
        printf("%d ",i);
       
        printf("%s ", vopcode[instructions[i].opcode]);
        if(instructions[i].result.type != empty){
            print_vmarg(&instructions[i].result);
    
            print_vmarg(&instructions[i].arg1);
                //     if(i==3)break;
            print_vmarg(&instructions[i].arg2);
        }else if(instructions[i].arg1.type != empty){
            print_vmarg(&instructions[i].arg1);
            if(instructions[i].opcode!=call_v && instructions[i].opcode!=pusharg_v )
				print_vmarg(&instructions[i].arg2);
        }

        //print_labels(&quads[i]);
        printf("\n");
    }
}



