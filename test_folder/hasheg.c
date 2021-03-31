#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TABLE_SIZE 3

//entry periexei name scope kai pointer se allo entry
typedef struct Variable{
    const char *name;
    unsigned int scope;
    unsigned int line;
}Variable;

//hashtable array of pointers to an entry
typedef struct ht_t{
    const char *name;
    //list of arguments
    unsigned int scope;
    unsigned int line;
    Variable **entries;
}ht_t;

enum SymbolType { 
 GLOBAL, LOCAL, FORMAL, 
 USERFUNC, LIBFUNC 
}; 

/*
typedef struct SymbolTableEntry { 
    bool isActive; 
    union { 
        Variable *varVal; 
        ht_t *funcVal; 
    } value; 
enum SymbolType type; 
} SymbolTableEntry; 
*/

Variable *ht_pair(const char *name, const char *scope){
    //allocate the entry
    Variable *entry = malloc(sizeof(entry)*1);
    entry->name = malloc(strlen(name)+1);
    entry->scope = malloc(strlen(scope)+1);

    //copy the name and vlaue in place
    strcpy(entry->name, name);
    strcpy(entry->scope, scope);

    //line starts out null but may be set later on
    entry->line = NULL;

    return entry;
}

ht_t *ht_create(void){
    //allocate table
    ht_t *hashtable = malloc(sizeof(ht_t)*1);

    //allocate table entries
    hashtable->entries = malloc(sizeof(Variable*)*TABLE_SIZE);

    //set each to null(needed for proper operation)
    int i = 0;
    for(; i<TABLE_SIZE; ++i){
        hashtable->entries[i]=NULL;
    }
    return hashtable;
}

void ht_set(ht_t *hashtable, const char *name, const char *scope){
    unsigned int slot = hash(name);

    //try to look up an entry set
    Variable *entry = hashtable->entries[slot];

    //no entry means slot empty,insert immediatly
    if(entry == NULL){
        hashtable->entries[slot] = ht_pair(name, scope);
        return;
    }
    Variable *prev;

    //walk through each entry until either the end is reached
    //or a matching name is found
    while(entry!=NULL){
        //check name
        if(strcmp(entry->name, name)==0){
            //match found, replace scope
            free(entry->scope);{
                //match found, replace scope
                free(entry->scope);
                entry->scope = malloc(strlen(scope)+1);
                strcpy(entry->scope, scope);
                return;
            }
            //walk to line
            prev = entry;
            entry = prev->line;
        }

        //end of chain reached without a match, add new
        prev->line = ht_pair(name,scope);
    }
}

char *ht_get(ht_t *hashtable, const char *name){
    unsigned int slot = hash(name);

    //try to find a valid slot
    Variable *entry = hashtable->entries[slot];

    //no slot means no entry
    if(entry == NULL){
        return NULL;
    }

    //walk through each entry in the slot, which could just be a single thing
    while(entry != NULL){
        //return scope if found
        if (strcmp(entry->name, name)==0){
            return entry->scope;
        }

        //proceed to line name if available
        entry = entry->line;
    }

    //reaching here means there were >= 1 entries but no name match
    return NULL;
}

void ht_dump(ht_t *hashtable){
    for(int i = 0; i<TABLE_SIZE; ++i){
        Variable *entry = hashtable->entries[i];

        if (entry==NULL){
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;){
            printf("%s=%s ", entry->name, entry->scope);
            break;
        }
        entry = entry->line;
    }
    printf("\n");
}

int main(int argc, char **argv){
    ht_t *ht  = ht_create();

    ht_set(ht, "name1", "frappa");
    ht_set(ht, "name2", "papagia");
    ht_set(ht, "name3", "neratzi");
    ht_set(ht, "name4", "cola");
    ht_set(ht, "name5", "banana");
    ht_set(ht, "name6", "cherry");

    ht_dump(ht);

    return 0;
}
