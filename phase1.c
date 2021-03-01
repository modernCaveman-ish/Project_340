%{
alpha_token alpha_yylex ;
 
 int alpha_yylex (void* ylval){
 	
 	
 }


%}

/*file options*/
%option noyywrap
%option	yylineno

/*regular expressions*/

//keywords
if "if"
else "else"
while "while"
for  "for"
function "function"
return "return"
break "break"
continue "continue"
and "and"
not "not"
or "or"
local "local"
true "true"
false "false"
nil "nil"

//operators
assignment "="
add "+"
sub "-"
mul "*"
div "/"
perc "%"
icreament1 "++"
decreament "--"
greater ">"
less "<"
equal "=="
diff "!="
greater_equal ">="
less_equal  "<="

digit [0-9]
integer {digit}+
double integer.integer
newline		"\\n"
tab		"\\t"
backslash	"\\"
underscore \_
letter [a-z A-Z]
quote \"
string	({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})

left_curly_brace "}"
right_curly_brace "}"
leftbracket "["
rightbracket "]"
right_parenthesis ")"
left-parenthesis "("
semicolon ";"
comma ","
colon ":"
namespace "::"
dot "."
double_dot ".."

identifier {letter}({letter}|{digit}|{underscore})*leftbrace "{"

comment "//".*
multiple_line_comment"/*"
multiple_line_comment"*/"

%%
/*tmhma kanonwn*/

{identifier} {fprintf("Recognized id with value %s\n",yytext);}


%%

/*tmhma kwdika xrhsth*/
int main(int argc,char** argv){
	
	if(argc>1){
		if(!yyin=fopen(argv[1],"r"))){
		   fprintf(stderr,"Cannot read file : %s\n",argv[1]);
		   return 1;	
		}
	}
	else{
		yyin=stdin;
	}
	alpha_yylex();
	return 0;
}








