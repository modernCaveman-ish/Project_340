%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "test_token.h"

%}

%option noyywrap
%option yylineno
%option case-insensitive


/* Isodynamies klasewn */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ALPHANUM    {LETTER}|{DIGIT}


/*KEY WORDS AND KEY ELEMENTS*/
/*CODE FOR COMMENTS*/
%%

"if"		{token_number++; content_type = "KEYWORD"; printf("Found if!!\n"); return IF;}
"else"		{token_number++; content_type = "KEYWORD"; return ELSE;}
"while"		{token_number++; content_type = "KEYWORD"; return WHILE;}
"for"		{token_number++; content_type = "KEYWORD"; return FOR;}
"\n"        {line_number++;}
" "         {continue;}



"/*"        {   int c;             


                while(1)
                {
                    printf("Got in here\n");

                    while( (c = input()) != '*' && (c = input()) != EOF)
                        printf("%c", c); /*skip simple letters*/

                    /*Time for nested comments*/
                    
                    if(c == '/'){
                        if((c = input()) == '/'){

                            while ( (c = input()) != '\n' || (c = input()) != EOF)
                                ;
                            
                            if( c == EOF )  {printf("EOF found in comment\n"); break;}

                            printf("Nested C++ Style Comment Found\n");
                        
                        } else if( (c = input()) == '*'){
                            printf("Possible C Style Nested Comment Found\n");
                        }

                        /*while( (c = input()) != '\n')*/
                    }

                    if(c == '*'){
                        while( (c = input()) == '*')
                            ;
                        if( c== '/' )
                            break;  /*found the end*/ 
                    }

                    if(c == EOF){
                        printf("EOF found in comment\n");
                        break;
                    }
                    
                }


            }


"//"        {       int c;    
                    
                    while((c = input()) != EOF || (c = input()) != '\n'){
                        continue;
                    }

            }




<<EOF>>     {return 0;}

%%


int main(int argc, char* argv[]) {

    int token;
    struct alpha_token_t* head = NULL;
    struct alpha_token_t* temp = NULL;

    printf("WTF\n");

    if(argc > 1){
        yyin = fopen(argv[1], "r");

        if(yyin == NULL){
            printf("Error with opening text file...\n");
            return -1;
        }
    }else if(argc == 0) {
        printf("File to read from not entered...\n");
        return -1;
    }

    do{
        /*Create and assign new alpha_token_t and expand the list*/
        token = yylex();
        content_string = yytext;
        
        /*
            Values poy kratane shmantikes times
            token: Epistrefei to token poy entwphse h yylex()
            line_number: To line Number poy brisketai to kathe token
            token_number: O arithmos toy token poy entwpisthke, px prwto, deftero, trito
            content_string: To token, poio akribws einai
            content_type: h kathgoria sthn opoia katatasetai to token pou entwphstike
        */
        
        


        if(token == 0)
            break;


        /* TODO MAKE THE LIST AND PRINT IT */

        head = addToList(head, line_number, token_number, content_string, content_type);

    } while(token != 0);

    temp = head;

    printf("Printing List...\n");

    printTokenList(temp);

    
    fclose(yyin);
    yyterminate();

    return 0;
}