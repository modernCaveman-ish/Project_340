#include <stdio.h>


struct alpha_token_t {

    struct alpha_token_t* next;
    int line_number = line_number;  //arithmos gia kathe grammi
    //int token_number = 
    char* token_string;             //to periexomeno gia kathe string
    enum token_types type;          //to periexomeno gia token ?!?! what is dis
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


int line_number = 1;            //o arithmos tis grammis
int token_number = 0;           //o arithmos tou token - tou periexomenou tou
