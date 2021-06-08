

void execute_call (instruction* instr){

	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	avm_callsaveenvironment();

	switch (func->type){

		case userfunc_m : { pc = func->data.funcVal;
						    assert(pc < AVM_ENDING_PC);
					        assert(code[pc].opcode == funcenter_v);
						    break;	
		}

		case string_m: avm_calllibfunc(func->data.strVal); 		break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;

		default: {
			char* s = avm_tostring(func);
			avm_error("call: cannot bind '%s' to function!", s);
			free(s);
			executionFinished = 1;
		}
	}
}

unsigned totalActuals = 0;

void avm_dec_top (void) {
	if(!top) { /*stack overflow */  
		avm_error("stack overflow");
		executionFinished = 1;
	}
	else
		--top;
}

void avm_push_envvalue (unsigned val){
	stack[top].type = number_m;
	stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenvironment (void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}

//userfunc* avm_getfuncinfo (unsigned address);

void execute_funcenter (instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->result, &ax);
	assert(func);
	assert(pc == func->data.funcVal); /*Func address should match PC*/

	/*Callee actions here*/
	totalActuals = 0;
	userfunc* funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->localSize;
}

unsigned avm_get_envvalue (unsigned i){
	assert(stack[i].type = number_m);
	unsigned val = (unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
	return val;
}

void execute_funcexit (instruction* unused){
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(++oldTop <= top) /* intentionally ignoring first */
		avm_memcellclear(&stack[oldTop]);
}

//typedef void (*library_func_t)(void);
//library_func_t avm_getlibraryfunc (char* id); /*Typical hashing*/

void avm_calllibfunc (char* id){
	library_func_t f = avm_getlibraryfunc(id);
	if(!f){
		avm_error("unsupported lib func '%s' called! ", id);
	}
	else {
		/*Notice that enter function and exit function are called manually*/
		topsp = top; /*Enter function sequence. No stack locals*/
		totalActuals = 0;
		(*f)();
		if(!executionFinished)/*an error may naturally occur inside*/
			execute_funcexit((instruction*) 0); /* Return sequence */
	}
}

unsigned avm_totalactuals (void) {
	return avm_get_envvalue (topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}


void execute_pusharg (instruction* instr) {
	avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
	assert(arg);

	/*This is actually stack[top] = arg, but we have to use avm_assign */
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

tostring_func_t tostringFuncs[]= { 
	number_tostring, 
	string_tostring, 
	bool_tostring, 
	table_tostring, 
	userfunc_tostring, 
	libfunc_tostring, 
	nil_tostring, 
	undef_tostring   
}; 


unsigned char avm_tobool (avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}

char* avm_tostring (avm_memcell* m){
	assert(m->type >= 0 && m->type = undef_m);
	return (*tostringFuncs[m->type])(m);
}




/*with the following every library function is manually added in the VM
library function resolution map
*/

//void avm_registerlibfunc (char* id, library_func_t addr);


/* implementation of the library function print
   it displays every argument at the console
*/

void libfunc_print(void){
	unsigned n = avm_totalactuals();
	for(unsigned i = 0; i < n; ++i){
		char* s = avm_tostring(avm_getactual(i));
		puts(s);
		free(s);
	}
}

void libfunc_typeof (void){

	unsigned n = avm_totalactuals();

	if(n != 1)
		avm_error("one argument (not %d) expected in 'typeof' !", n);
	else {
			/*thats how a library function returns a result, it has to only 
			set the retval register */
		avm_memcellclear(&retval); /*Dont forget to clean it up*/
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_totalarguments (void){
	/*Get topsp of previous activation record*/
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if(!p_topsp){
		avm_error("'totalrguments' called outside a function!");
		retval.type = nil_m;
	}
	else{
		/*Exctract the number of actual arguments for the previous activation record*/
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}
