#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "assign.h"

extern avm_memcell ax;
extern avm_memcell stack[AVM_STACKSIZE];

void execute_assign (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* rv = avm_translate_operand(&instr->arg1, &ax);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv==&retval));
	assert(rv); //should do a similar assertion tests here

	avm_assign(lv, rv);
}

void avm_assign (avm_memcell *lv, avm_memcell *rv){
	
	if(lv == rv)		/*SAME cells? destructive to assign*/
		return;

	if(lv->type == table_m && /*SAME tables? no need to assign*/
	   rv->type == table_m && 
	   lv->data.tableVal == rv->data.tableVal)
	   return;

	if(rv->type == undef_m)	/* From undefined r->value ?!?! warning */
		avm_warning("assigning from 'undef' content!");
	
	avm_memcellclear(lv);	/* Clear old cell contents */

	memcpy(lv, rv, sizeof(avm_memcell)); /* In C++ dispatch instead */

	/* Now take care of copied values or reference counting */

	if(lv->type == string_m)
	   lv->data.strVal = strfup(rv->data.strVal);
	else
	if(lv->type == table_m)
		avm_tableincrefcounter(lv->data.tableVal);
}