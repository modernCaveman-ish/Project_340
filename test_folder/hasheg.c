#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TABLE_SIZE 3

//entry periexei key value kai pointer se allo entry
typedef struct entry_t{
    char *key;
    char *value;
    struct entry_t *next;
}entry_t;

//hashtable array of pointers to an entry
typedef struct {
    entry_t **entries;
}ht_t;

entry_t *ht_pair(const char *key, const char *value){
    //allocate the entry
    entry_t *entry = malloc(sizeof(entry)*1);
    entry->key = malloc(strlen(key)+1);
    entry->value = malloc(strlen(value)+1);

    //copy the key and vlaue in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    //next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

ht_t *ht_create(void){
    //allocate table
    ht_t *hashtable = malloc(sizeof(ht_t)*1);

    //allocate table entries
    hashtable->entries = malloc(sizeof(entry_t*)*TABLE_SIZE);

    //set each to null(needed for proper operation)
    int i = 0;
    for(; i<TABLE_SIZE; ++i){
        hashtable->entries[i]=NULL;
    }
    return hashtable;
}

void ht_set(ht_t *hashtable, const char *key, const char *value){
    unsigned int slot = hash(key);

    //try to look up an entry set
    entry_t *entry = hashtable->entries[slot];

    //no entry means slot empty,insert immediatly
    if(entry == NULL){
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }
    entry_t *prev;

    //walk through each entry until either the end is reached
    //or a matching key is found
    while(entry!=NULL){
        //check key
        if(strcmp(entry->key, key)==0){
            //match found, replace value
            free(entry->value);{
                //match found, replace value
                free(entry->value);
                entry->value = malloc(strlen(value)+1);
                strcpy(entry->value, value);
                return;
            }
            //walk to next
            prev = entry;
            entry = prev->next;
        }

        //end of chain reached without a match, add new
        prev->next = ht_pair(key,value);
    }
}

char *ht_get(ht_t *hashtable, const char *key){
    unsigned int slot = hash(key);

    //try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    //no slot means no entry
    if(entry == NULL){
        return NULL;
    }

    //walk through each entry in the slot, which could just be a single thing
    while(entry != NULL){
        //return value if found
        if (strcmp(entry->key, key)==0){
            return entry->value;
        }

        //proceed to next key if available
        entry = entry->next;
    }

    //reaching here means there were >= 1 entries but no key match
    return NULL;
}

void ht_dump(ht_t *hashtable){
    for(int i = 0; i<TABLE_SIZE; ++i){
        entry_t *entry = hashtable->entries[i];

        if (entry==NULL){
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;){
            printf("%s=%s ", entry->key, entry->value);
            break;
        }
        entry = entry->next;
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
