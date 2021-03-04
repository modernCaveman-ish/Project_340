#include <stdio.h>


struct alpha_token_t {

    struct alpha_token_t* next;
    int line_number = line_number;
    //int token_number = 
    char* token_string;
    enum token_types type;
};

enum token_types {
    KEYWORD,
    OPERATOR,
    INTCONST,
    STRING,
    PUNCTUATION,
    ID,
    COMMENTS
};


int line_number = 1;
int token_number = 0;
