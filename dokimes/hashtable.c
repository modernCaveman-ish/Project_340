#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 509
#define HASH_MULTIPLIER 65599
 

struct bind
{
    char *name;
    //void *value;
    int line;
    int scope;
    struct bind *next;
};

typedef struct SymTable
{
    int length;
    struct bind *head;
  
}*SymTable_T;

//ta prakatw structs dinontai sto fronthsthrio
//typos metavlitis
typedef struct Variable { 
	const char *name; //onoma
	unsigned int scope; //emveleia
	unsigned int line; //grammh dhlwshs
	struct Variable *next;
} Variable; 

//typos synarthshs
typedef struct Function { 
	const char *name; //onoma synarhtshs
	struct SymbolTableEntry *arguments;	//orismata synarthshs 
	unsigned int scope; //emveleia
	unsigned int line; //grammh dhlwshs
} Function; 

typedef enum SymbolType { 
	GLOBAL, LOCAL, FORMAL, 
 	USERFUNC, LIBFUNC 
};

typedef struct SymbolTableEntry { 
	int isActive; //energh metavliti sto trexon scope
	union { 
 		Variable *varVal; 
 		Function *funcVal; 
	 } value; //to value mporei na einai h metavlitis h synarhtshs
 
		enum SymbolType type; //global local klp
		struct SymbolTableEntry *next;
} SymbolTableEntry; 

//hash function
static unsigned int SymTable_hash(const char *pcKey)
{
    size_t ui;
    unsigned int uiHash = 0U;
    for (ui = 0U; pcKey[ui] != '\0'; ui++)
    uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
    return uiHash%SIZE;
}

//create new Symbol table
SymTable_T SymTable_new(void)
{
    SymTable_T oSymTable;
 
    oSymTable = (SymTable_T) malloc (sizeof(struct SymTable));
    oSymTable->length = 0;
    oSymTable->head = NULL;
 
    return oSymTable;
}

//struct SymbolTableEntry* 
//insert new symbol ston pinaka
int SymTable_put(SymTable_T oSymTable, const char *Name,int line,int scope)
{
    struct bind *tmpbind ;
    //assert(oSymTable);
   // assert(Name);
 
    if (SymTable_contains2(oSymTable, Name,scope) == 1 )
   {
	    printf("Symbol already defined in scope\n") ;
        return 0; //mhn kaneis insert yparxei symbolo me idio onoma sto idio scope
   }
    	
    tmpbind = ( struct bind* ) malloc(sizeof (struct bind) );
    tmpbind-> name= strdup(Name);
    tmpbind->line = line;
   tmpbind->scope=scope;
   //tmpbind->value = (void*)pvValue;
   // oSymTable->length++;
 
    tmpbind->next = oSymTable->head;
    oSymTable->head = tmpbind;
    
    return 1;
    
}

/*
//anazhthsh genika ston symtable me to onoma
int SymTable_contains(SymTable_T oSymTable, const char *Name)
{
    struct bind *tmpbind;
 
    assert(oSymTable);
    assert(Name);
    tmpbind = oSymTable->head;
 
    while ( tmpbind != NULL )
        {
            if ( !strcmp(tmpbind->name,Name) )
                 return 1;
 
                tmpbind = tmpbind->next;
        }
 
    return 0;
}
*/

//look up se sygkekrimeno scope
int SymTable_contains2(SymTable_T oSymTable, const char *Name,int scope)
{
    struct SymbolTableEntry *tmpbind;
    struct SymbolTableEntry *look;
 
    //assert(oSymTable);
   // assert(Name);
    tmpbind = oSymTable->head;
 
    while (tmpbind != NULL )
        {       
		if(look->type == GLOBAL || look->type == LOCAL || look->type == FORMAL) {
			if(strcmp(look->value.varVal->name, Name) == 0 && look->value.varVal->scope == scope) {
				return 1;
			}else {
				tmpbind = tmpbind->next;
			}
		}else {
			if(strcmp(look->value.funcVal->name,Name) == 0 && look->value.funcVal->scope == scope) {
				return 1;
			}else {
				tmpbind = tmpbind->next;
			}
		}
		
		       /*
                if(!strcmp(tmpbind->name, Name) && (tmpbind->scope == scope))
               {  //printf("Symbol already defined in scope\n") ;
                 //vrika to symbolo
				return 1;
            }
                tmpbind = tmpbind->next;
        }
               */
    return 0;
}
}
/*
void *SymTable_get(SymTable_T oSymTable, const char *Name)
{
        struct bind *rootbind, *tmpbind;
 
        assert(oSymTable);
        assert(Name);
 
        rootbind = oSymTable->head;
        tmpbind = oSymTable->head;
 
        while ( tmpbind != NULL )
        {
            if ( !strcmp(tmpbind->key,Name) )
        {
            return (void*)tmpbind->value;
        }
 
                tmpbind = tmpbind->next;
        }
    return NULL;
}
*/

//print ton symtable
void SymTable_Print(SymTable_T oSymTable)
{
    struct Variable *tmp;
 
    //assert(oSymTable);
 
    tmp = oSymTable->head;
 
        while (tmp != NULL)
        {
            printf("name: %s\tline:%d \tscope:%d \t%d\n", tmp->name, tmp->line,tmp->scope);
            tmp = tmp->next;
        }
}


int main(void)
{
    SymTable_T oSymTable;

    oSymTable = SymTable_new();
    SymTable_put(oSymTable, "dimitra",88,1);
    SymTable_put(oSymTable, "dimitra",65,1);
   // SymTable_put(oSymTable, "dimitra",88,1);
	//SymTable_put(oSymTable, "dimitra",5,0);
  //  SymTable_put(oSymTable, "onoma",5,0);//diaforetiko scope
    
   
    SymTable_Print(oSymTable);
    
    //printf("%d\n", SymTable_contains(oSymTable,"dimitrha") );//gia na dw genika an yparxei symbolo onoma ston pinaka
   printf("%d\n", SymTable_contains2(oSymTable,"onoma",0) );//gia na dw an yparxei sto idio scope
    return 0;
    
}
