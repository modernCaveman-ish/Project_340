#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "hashtbl.h"
 

static char *mystrdup(const char *s)
{
	char *b;
	if(!(b=malloc(strlen(s)+1))) return NULL;
	strcpy(b, s);
	return b;
}




static hash_size def_hashfunc(const char *key)
{
	hash_size hash=0;
	
	while(*key) hash+=(unsigned char)*key++;

	return hash;
} 
 
HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *))
{
	HASHTBL *hashtbl;

	if(!(hashtbl=malloc(sizeof(HASHTBL)))) return NULL;

	if(!(hashtbl->nodes=calloc(size, sizeof(struct hashnode_s*)))) {
		free(hashtbl);
		return NULL;
	}

	hashtbl->size=size;

	if(hashfunc) hashtbl->hashfunc=hashfunc;
	else hashtbl->hashfunc=def_hashfunc;

	return hashtbl;
}

int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data ,int scope)
{
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

  /*if(HASHTBL_DEBUG && HASHTBL_SHOW_INSERT)*/
        printf("HASHTBL_INSERT(): KEY = %s, HASH = %d,  \tDATA = %s, SCOPE = %d\n", key, hash, (char*)data, scope);

	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;
	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}
	node->data=data;
	node->scope = scope;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;

	return 0;
}
