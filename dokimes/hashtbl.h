#include<stdlib.h>

typedef size_t hash_size;

struct hashnode_s {
	char *key;
	void *data;
	int scope;
	struct hashnode_s *next;
};

typedef struct hashtbl {
	hash_size size;
	struct hashnode_s **nodes;
	hash_size (*hashfunc)(const char *);
} HASHTBL;

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *));
int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data, int scope);
