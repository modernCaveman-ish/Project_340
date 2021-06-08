#include "tables.h"
#include "vm.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

extern unsigned top, topsp;
extern unsigned char executionFinished;
extern avm_memcell ax, bx, cx;
extern avm_memcell retval;

void avm_tableincrefcounter (avm_table* t) 
	{ ++t->refCounter; } 

/* Automatic garbage collection for tables when reference counter gets zero. 
*/ 
void avm_tabledecrefcounter (avm_table* t) { 
	assert(t->refCounter > 0); 
	if (!--t->refCounter) 
		avm_tabledestroy(t); 
} 
void avm_tablebucketsinit (avm_table_bucket** p) { 
	unsigned i;
	for (i=0; i<AVM_TABLE_HASHSIZE; ++i) 
		p[i] = (avm_table_bucket*) 0; 
}

/* The reference counter is initially zero. */ 
avm_table* avm_tablenew (void) { 
	avm_table* t = (avm_table*)malloc(sizeof(avm_table)); 
	AVM_WIPEOUT(*t); 

	t->refCounter = t->total = 0; 
	avm_tablebucketsinit(t->numIndexed); 
	avm_tablebucketsinit(t->strIndexed); 
return t; 
}

void avm_tablebucketsdestroy (avm_table_bucket** p) { 
	unsigned i;
	for (i=0; i<AVM_TABLE_HASHSIZE; ++i, ++p) { 
		for (avm_table_bucket* b = *p; b;) { 
			avm_table_bucket* del = b; 
			b = b->next; 
			avm_memcellclear(&del->key); 
			avm_memcellclear(&del->value); 
			free(del); 
		} 
		p[i] = (avm_table_bucket*) 0; 
	} 
} 

void avm_tabledestroy (avm_table* t) { 
	avm_tablebucketsdestroy(t->strIndexed); 
	avm_tablebucketsdestroy(t->numIndexed); 
	free(t); 
} 


avm_memcell* avm_tablegetelem(
	avm_table* table, avm_memcell* index
);

void avm_tablesetelem (avm_table* table,
					   avm_memcell* index,
					   avm_memcell* content);


void execute_newtable (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	assert(lv && ( &stack[N-1] >= lv && lv > &stack[top] || lv == &retval));

	avm_memcellclear(lv);

	lv->type 			= table_m;
	lv->data.tableVal 	= avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal); //dn 3exname tin au3isi tou metriti anaforwn
											  //kathos kata ti dimiourgia o pinakas exei to counter sti timi 0
}

avm_memcell* avm_tablegetelem(
	avm_table* table, avm_memcell* index
);


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
         else { //endexetai to stoixio pou zitite gia to sigkekrimeno kleidi na min iparxei i na ipostirizi kleidi sigkekrimenou tipou
              char* ts = avm_tostring(t); 
              char* is = avm_tostring(i); 
              avm_warning("%s[%s]table element not found!", ts, is);
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
		avm_error("illegal use of type as table!", typeStrings[t->type]);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}