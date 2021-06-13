#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (){

    char* string1 = "do this";
    char *string2 = "not";

    strcat(string1[2], string2);
    printf("%s\n", string1);
    
    return 0;
}