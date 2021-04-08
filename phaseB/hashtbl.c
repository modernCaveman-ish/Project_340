#include "hashtbl.h"
//create new Symbol table
SymTable_T SymTable_new(void)
{
    SymTable_T oSymTable;
 
    oSymTable = (SymTable_T) malloc (sizeof(struct SymTable_T));
    oSymTable->length = 0;
    oSymTable->head = NULL;
 
    return oSymTable;
}

//insert new symbol ston pinaka
int SymTable_put(SymTable_T oSymTable, const char *Name,int line,int scope, enum SymbolType type)
{
    struct SymbolTableEntry *tmpbind;
    struct SymbolTableEntry *temp_entry;
    //assert(oSymTable);
    //assert(Name);
    
    tmpbind = ( struct SymbolTableEntry* ) malloc(sizeof (struct SymbolTableEntry) );
    tmpbind->type = type;
    tmpbind->isActive = 1;
  
    if(type==USERFUNC){
        Function *funcVal = ( struct Function* ) malloc(sizeof (struct Function) );
        funcVal->name= strdup(Name);
        funcVal->line = line;
        funcVal->scope=scope;
        tmpbind->value.funcVal = funcVal;
    }else if(type==LIBFUNC){
        Function *funcVal = ( struct Function* ) malloc(sizeof (struct Function) );
        funcVal->name= strdup(Name);
        funcVal->line = line;
        funcVal->scope=scope;
        tmpbind->value.funcVal = funcVal;
    }else {
        Variable *varVal = ( struct Variable* ) malloc(sizeof (struct Variable) );
        varVal->name= strdup(Name);
        varVal->line = line;
        varVal->scope=scope;
        tmpbind->value.varVal = varVal;
    }  
    oSymTable->length++;
    /*
    tmpbind->next = oSymTable->head;
    oSymTable->head = tmpbind;
    */
    
    /*SymTable_Put apo 255*/
    if(oSymTable->head  == NULL){
            tmpbind -> next = NULL;
            oSymTable->head = tmpbind;
        }else{/* eisagwgi san prwto stoixeio panta */
            /*tmpbind -> next = oSymTable->head;
            oSymTable->head = tmpbind;*/
            temp_entry = oSymTable->head;
            while(temp_entry-> next!= NULL){
                temp_entry = temp_entry->next;
            }
            temp_entry->next = tmpbind;
        }
    
    //tmpbind->value.funcVal->name
    /*printf("Twra mphke to %s, twra to head einai to %s\n", tmpbind->value.funcVal->name, oSymTable->head->value.funcVal->name);*/

    return 1;  
}

//look up se sygkekrimeno scope
int SymTable_contains2(SymTable_T oSymTable, const char *Name,int scope)
{
    struct SymbolTableEntry *tmpbind; 
    //assert(oSymTable);
    //assert(Name);
    tmpbind = oSymTable->head;
 
    while (tmpbind != NULL )
        {       
        if(tmpbind->isActive){
            if(tmpbind->type == GLOBAL || tmpbind->type == LOCAL2 || tmpbind->type == FORMAL) {
                if(strcmp(tmpbind->value.varVal->name, Name) == 0 && tmpbind->value.varVal->scope == scope) {
                    return 1;
                }else {
                    tmpbind = tmpbind->next;
                }
                    }else {
                        if(strcmp(tmpbind->value.funcVal->name,Name) == 0 && tmpbind->value.funcVal->scope == scope) {
                        return 1;
                    }else {
                    tmpbind = tmpbind->next;
                }
            }
        }else{
            tmpbind = tmpbind->next;
        }
    }
       
    return 0;
    
}

SymbolTableEntry* SymTable_get(SymTable_T oSymTable, const char *Name,int scope)
{
    struct SymbolTableEntry *tmpbind; 
    //assert(oSymTable);
   // assert(Name);
    tmpbind = oSymTable->head;
 
    while (tmpbind != NULL )
        {       
        if(tmpbind->isActive){
            if(tmpbind->type == GLOBAL || tmpbind->type == LOCAL2 || tmpbind->type == FORMAL) {
                if(strcmp(tmpbind->value.varVal->name, Name) == 0 && tmpbind->value.varVal->scope == scope) {
                    return tmpbind;
                }else {
                    tmpbind = tmpbind->next;
                }
            }else {
                if(strcmp(tmpbind->value.funcVal->name,Name) == 0 && tmpbind->value.funcVal->scope == scope) {
                    return tmpbind;
                }else {
                    tmpbind = tmpbind->next;
                }
            }
        }else{
            tmpbind = tmpbind->next;
        }
    }
		       
    return NULL;
}

void SymTable_hide(SymTable_T oSymTable,int scope)
{
    struct SymbolTableEntry *tmp;
    tmp = oSymTable->head;

    while(tmp != NULL)
    {
    if(tmp->value.funcVal->scope == scope){
        tmp->isActive = 0;        
    }

    tmp = tmp->next;
    }
}

//print ton symtable
void SymTable_Print(SymTable_T oSymTable)
{
     SymbolTableEntry *tmpbind;
 
    //assert(oSymTable);
 
    tmpbind = oSymTable->head;
 
        while (tmpbind != NULL)
        {
            //printf("name: %s\tline:%d \tscope:%d \t%d\n", tmp->name, tmp->line,tmp->scope);
           
            if(tmpbind->type == GLOBAL || tmpbind->type == LOCAL2 || tmpbind->type == FORMAL) {
                
                printf("name: %s\t (type:%d) \t (line:%d) \t(scope:%d) \t\n",tmpbind->value.varVal->name, tmpbind->type, tmpbind->value.varVal->line,tmpbind->value.varVal->scope);
   
            }else {

                printf("name: %s\t (type:%d) \t (line:%d) \t(scope:%d) \t\n",tmpbind->value.funcVal->name, tmpbind->value.funcVal->line,tmpbind->value.funcVal->scope);
            }
            tmpbind = tmpbind->next;
        }
}


/*print for single element*/
void SymTableEntry_print(SymbolTableEntry  *entry){
    printf("name: %s\tline: %d\tscope: %d\t\n", entry->value.varVal->name, entry->value.varVal->line, entry->value.varVal->scope);
}
