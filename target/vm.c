

enum avm_memcell_t { 
	number_m =0, 
	string_m =1, 
	bool_m 	 =2, 
	table_m  =3, 
	userfunc_m =4, 
	libfunc_m =5, 
	nil_m	  =6, 
	undef_m   =7 
}; 
struct avm_table avm_table;

struct avm_memcell { 
	avm_memcell_t type; 
	union {
		double		numVal; 	
		char* 		strVal;
		unsigned char boolVal;
		avm_table* 	tableVal;
		unsigned 		funcVal;
		char* 		    libfuncVal; 
	} data; 
}; 


static void avm_initstack(){

	unsigned int i;

	for(i=0;i < AVM_STACKSIZE;++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type = undef_m;
	}
}


avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {  

	switch	(arg->type) {
	/* Variables */

		case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
		case local_a:  return &stack[topsp-arg->val];
		case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
		case retval_a: return &retval;
 		case number_a: {
  			reg->type = number_m;
  			reg->data.numVal = (consts_getnumber(arg->val));
  			return reg;                                         
		}
        
		case string_a: {
  			reg->type = string_m;
  			reg->data.strVal = strdup(consts_getstring(arg->val));
  			return reg;                                         
		}
    
		case bool_a: {
  			reg->type = bool_m;
  			reg->data.boolVal = arg->val; 
			
  			return reg;                                         
  		}
		case nil_a: reg->type = nil_m; return reg;

		case userfunc_a: {
  			reg->type = userfunc_m;
  			reg->data.funcVal = arg->val; /* Address already stored */ 
  			return reg;
		}

		case libfunc_a: {
  			reg->type = libfunc_m;
  			reg->data.libfuncVal = libfuncs_getused(arg->val); 
			return reg;
		} 
		default: assert(0);
	}
}




void execute_newtable (instruction* instr) {
   avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
   assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));

   avm_memcellclear(lv);

   lv->type          = table_m;
   lv->data.tableVal = avm_tablenew();
   avm_tableincrefcounter(lv->data.tableVal);
}

avm_memcell*  avm_tablegetelem (
                 avm_table*    table,
                 avm_memcell*  index
              )

void          avm_tablesetelem (
                 avm_table*    table, 
                 avm_memcell*  index, 
                 avm_memcell*  content
              )


void execute_tablegetelem (instruction* instr) {

     avm_memcell* lv     = avm_translate_operand(&instr->result, (avm_memcell*) 0);
     avm_memcell* t      = avm_translate_operand(&instr->arg2, (avm_memcell*) 0);
     avm_memcell* i      = avm_translate_operand(&instr->arg2, &ax);

     assert (lv && &stack[N-1] >= lv && lv > &stack[top]  || lv==&retval);
     assert (t && &stack[N-1] >= t && t > &stack[top]);
     assert(i);

     avm_memcellclear(lv);
     lv->type = nil_m;      /* Default value. */

     if (t->type != table_m) {
         avm_error("illegal use of type as table!",typeStrings[t->type]);
     } 
     else  {
         avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
         if (content)
              avm_assign(lv, content); 
         else {
              char* ts = avm_tostring(t); 
              char* is = avm_tostring(i); 
              avm_warning("%s[%s]table element not found!",ts,is);
              free(ts);
              free(is);
         }
     }
}

void execute_tablesetelem (instruction* instr) {
	
	avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

	assert (t && &stack[N-1] >= t && t > &stack[top]);  
	assert (i && c);
	if (t->type != table_m)
		avm_error("illegal use of type as table!",typeStrings[t->type]);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}
