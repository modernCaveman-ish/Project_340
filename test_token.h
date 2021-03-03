#include <stdio.h>


struct alpha_token_t {

    struct alpha_token_t* next;
    int line_number;
    char* token_string;
    enum token_types type;
};

enum token_types {
    INTEGER,
    STRING,
    COMMENT,
    CHARACTER
};