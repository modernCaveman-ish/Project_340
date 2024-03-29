#ifndef HASH
#define HASH

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 509
#define HASH_MULTIPLIER 65599

//ta prakatw structs dinontai sto fronthsthrio
//typos metavlitis
typedef struct Variable { 
	const char *name; //onoma
	unsigned int scope; //emveleia
	unsigned int line; //grammh dhlwshs
} Variable; 

//typos synarthshs
typedef struct Function { 
	const char *name; //onoma synarhtshs
	//struct SymbolTableEntry *arguments;	//orismata synarthshs 
	unsigned int scope; //emveleia
	unsigned int line; //grammh dhlwshs
} Function; 

typedef enum SymbolType { 
	GLOBAL, LOCAL2, FORMAL, 
 	USERFUNC, LIBFUNC 
}SymbolType;

enum scopespace_t {
	programvar, functionlocal, formalarg
};

enum symbol_t { var_s, programfunc_s, libraryfunc_s };


typedef struct num_list{
	int number;
	struct num_list *next ;
 
}num_list; 

typedef struct SymbolTableEntry { 
	int isActive; //energh metavliti sto trexon scope
	union { 
 		Variable *varVal; 
 		Function *funcVal; 
	 } value; //to value mporei na einai h metavlitis h synarhtshs

		enum SymbolType type; //global local klp
		struct SymbolTableEntry *next;

	enum symbol_t		typet;
	char*				name;
	enum scopespace_t	space;
	unsigned			offset;
	unsigned			line;	
	unsigned            totalLocals;
	unsigned    		iaddress; 
	unsigned    		taddress; 
    	num_list*           returnList;	
	
} SymbolTableEntry; 

struct SymTable_T{
     struct SymbolTableEntry* head;
     int length;
};

typedef struct SymTable_T *SymTable_T;

//create new Symbol table
SymTable_T SymTable_new(void);

SymbolTableEntry* SymTable_put(SymTable_T oSymTable, const char *Name,int line,int scope, enum SymbolType type);

struct SymbolTableEntry* SymTable_contains2(SymTable_T oSymTable, const char *Name,int scope);

SymbolTableEntry* SymTable_get(SymTable_T oSymTable, const char *Name,int scope);

void SymTable_hide(SymTable_T oSymTable,int scope);

void SymTable_Print(SymTable_T oSymTable); 

#endif