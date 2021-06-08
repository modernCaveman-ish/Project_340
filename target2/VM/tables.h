#define AVM_TABLE_HASHSIZE 211 

typedef struct avm_table_bucket { 
	avm_memcell key; 
	avm_memcell value; 
	struct avm_table_bucket* next; 
} avm_table_bucket; 


typedef struct avm_table { 
	unsigned 		refCounter;
	avm_table_bucket* 	strIndexed[AVM_TABLE_HASHSIZE];
	avm_table_bucket* 	numIndexed[AVM_TABLE_HASHSIZE];
	unsigned 			   total; 
} avm_table; 

avm_table* 		avm_tablenew (void);
void 			avm_tabledestroy (avm_table* t);
avm_memcell*  avm_tablegetelem (
                 avm_table*    table,
                 avm_memcell*  index
              );

void          avm_tablesetelem (
                 avm_table*    table, 
                 avm_memcell*  index, 
                 avm_memcell*  content
              );
void execute_newtable (instruction* instr);
void execute_tablegetelem (instruction* instr);
void execute_tablesetelem (instruction* instr);