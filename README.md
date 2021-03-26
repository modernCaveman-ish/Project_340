PHASE B

/*~~~~~~~~~~~~~~~~~~~~~~~~Frontistirio 2~~~~~~~~~~~~~~~~~~~~~~~~*/
YACC

- Μια γεννήτρια συντακτικών αναλυτών για 
τις γλώσσες C/C++
- Μετατρέπει την περιγραφή μιας context-free γραμματικής σε ένα 
LALR συντακτικό αναλυτή γραμμένο:
    (LALR = Look-Ahead Left-to-right parse, Rightmost-derivation)
- Θα χρησιμοποιήσουμε το bison, μια 
βελτιωμένη έκδοση του yacc
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                %{
                    Πρόλογος

                        #include <stdio.h>
                        #include “def.h”
                        void print_token_value (FILE *, int, YYSTYPE); 
                        extern int lineno;

                %}
                
                    Δηλώσεις yacc

                %%
                    Περιγραφή γραμματικής
                %%

                    Επίλογος (προαιρετικό)

                        int main(int argc, char **argv) {
                        yyparse();
                        return 0;
                        }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
%token ΤΟΚΕΝ – Ορίζει το τερματικό σύμβολο ΤΟΚΕΝ

%union – Ορίζει ένα union με τους τύπους που μπορούν 
να πάρουν τα σύμβολα (τερματικά και μη)

%union { int intVal; char * strVal; symrec *tptr; }
δηλώνει ότι τα σύμβολα μπορούν να έχουν τύπο int, char * ή 
symrec

%token <intVal> ΤΟΚΕΝ – Ορίζει το τερματικό σύμβολο 
ΤΟΚΕΝ, με τύπο αυτό που αντιστοιχεί στο intVal πεδίο 
του union

%type <intVal> expr – Ορίζει το μη τερματικό σύμβολο 
expr με τύπο αυτό που αντιστοιχεί στο intVal πεδίο του 
union.

%start symbol – Ορίζει το αρχικό σύμβολο της 
γραμματικής

%destructor { code } symbols – Ορίζει ένα τμήμα 
κώδικα που εκτελείται για τα δοθέντα σύμβολα όταν αυτά 
σταματήσουν να χρησιμοποιούνται

%expect n – Δηλώνει ότι αναμένουμε η γραμματική μας 
να έχει n conflicts

-Αυξανόμενη προτεραιότητα από πάνω προς τα κάτω, π.χ.
    %left ADD, SUB /* + -*/ (left σημαίνει ότι έχουμε αριστερή προσεταιριστικότητα)
    %left MUL, DIV /* * / */ (right σημαίνει ότι έχουμε δεξιά προσεταιριστικότητα)
    %right EXP /* ^ */ 
    %nonassoc EQ /* == * (nonassoc σημαίνει ότι δεν υπάρχει προσεταιριστικότητα)

PARAMETROI 10/11-45

/*~~~~~~~~~~~~~~~~~~~~~~~~LEX~~~~~~~~~~~~~~~~~~~~~~~~*/

%{
    #include "parser.h"
%}

%option noyywrap
%option yylineno

id          [a_zA-Z][a-zA-Z_0-9]*
integer     [0-9]+

%%

"+"         {return '+';}
"-"         {return '-';}
"*"         {return '*';}
"/"         {return '/';}
"("         {return '(';}
")"         {return ')';}
"="         {return '=';}
[\n]+       {return '\n';}

{integer}   {return INTEGER;}
{id}        {return ID;}

[\t]+       {}

.           {fprintf(stderr, "CANNOT MATCH CHARACTER %s with any rule\n", yytext);}

/*~~~~~~~~~~~~~~~~~~~~~~~~LEX~~~~~~~~~~~~~~~~~~~~~~~~*/
                      /*prologos*/

%{
    #include <stdio.h>
    int yyerror (char* yaccProvidedMessage);
    int yylex (void);

    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;
%}

%start program

%token ID INTEGER
%right '='
%left ','
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '(' ')'

%%

program:            assignments expressions
                    |   /*kenos kanonas*/
                    ;

expression:         INTEGER
                    | ID
                    | expression '+' expression
                    | expression '-' expression
                    | expression '*' expression
                    | expression '/' expression
                    | '(' expression ')'
                    | '-' expression %prec UMINUS /*allagi protereotitas kanona*/
                    ;

epxr:               expression '\n' 

epxression:         expressions expr    /*dimiourgia mi kenis listas expressions*/
                    | expr
                    ;

assignment:         ID '=' expressions '\n' 

assignments:        assignments assignments
                    |   /*dimiourgia listas pou mpori na einai keni*/
                    ;


                        /*epilogos*/
int yyerror (char * yaccProvideMessage){
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
}                    

int main(int argc, char** argv){
    if(argc > 1){
        if (!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    }
    else
        yyin = stdin;
    yyparse();
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    ENTOLES EKTELESIMOU

bison --yacc --defines --output=parser.c parser.yaccProvidedMessage

flex --outfile=scanner.c scanner.l

gcc -o calc scanner.c parser.c
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            Μπορούμε να παρεμβάλλουμε ανάμεσα 
            στα σύμβολα των δεξιών μερών των 
            κανόνων κάποια actions, δηλαδή c, c++ 
            κώδικα μέσα σε { }

expr: ID    { printf(“Found ID\n”); }
            | expr '+' { int a = 3; } expr { int b; }
            | /* empty */ { printf(“empty\n”); }
            ;   



