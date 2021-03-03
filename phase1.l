%{

	//int number_of_tokens=0;
//alpha_token alpha_yylex ;
 
 //int alpha_yylex (void* ylval){
 	



%}

/*file options*/
%option noyywrap
%option	yylineno

/*regular expressions*/

/*keywords*/
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

/*operators*/
assignment "="
add "+"
sub "-"
mul "*"
div "/"
mod "%"
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
underscore \\_
letter [a-z A-Z]
quote \"
string	({quote})({letter}|{digit}|{newline}|{tab}|{backslash})*({quote})

left_curly_brace "{"
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

identifier {letter}({letter}|{digit}|{underscore})*

comment "//".*
multiple_line_comment_start "/*"
multiple_line_comment_end "*/"

%%

{if} {fprintf(yyout,"if keyword %s \n",yytext);}
{else} {fprintf(yyout,"else keyword %s \n",yytext);}
{while} {fprintf(yyout,"while keyword %s \n",yytext);}
{for}  {fprintf(yyout,"for keyword %s \n",yytext);}
{function} {fprintf(yyout,"function keyword %s \n",yytext);}
{break} {fprintf(yyout,"break keyword %s \n",yytext);}
{continue} {fprintf(yyout,"continue keyword %s \n",yytext);}
{and} {fprintf(yyout,"and keyword %s \n",yytext);}
{not} {fprintf(yyout,"not keyword %s \n",yytext);}
{or} {fprintf(yyout,"or keyword %s \n",yytext);}
{local} {fprintf(yyout,"local keyword %s \n",yytext);}
{true} {fprintf(yyout,"true keyword %s \n",yytext);}
{false} {fprintf(yyout,"false keyword %s \n",yytext);}
{nil} {fprintf(yyout,"nil keyword %s \n",yytext);}


{assignment} {fprintf(yyout,"assignment operator %s \n",yytext);}
{add} {fprintf(yyout,"add operator %s \n",yytext);}
{sub} {fprintf(yyout,"subtract operator %s \n",yytext);}
{mul} {fprintf(yyout,"multiply operator %s \n",yytext);}
{div} {fprintf(yyout,"divison operator %s \n",yytext);}
{mod} {fprintf(yyout,"modulo operator %s \n",yytext);}
{icreament1} {fprintf(yyout,"Increament by one operator %s \n",yytext);}
{decreament} {fprintf(yyout,"decreament by one %s \n",yytext);}
{greater} {fprintf(yyout,"Greater than operator %s \n",yytext);}
{less} {fprintf(yyout,"Less than operator %s \n",yytext);}
{equal} {fprintf(yyout,"Equal to operator %s \n",yytext);}
{diff} {fprintf(yyout,"Different than operator %s \n",yytext);}
{greater_equal} {fprintf(yyout,"Greater or equal operator %s \n",yytext);}
{less_equal}  {fprintf(yyout,"Less or equal operator %s \n",yytext);}

{digit} {fprintf(yyout,"Digit %s \n",yytext);}
{integer} {fprintf(yyout,"INTEGER %s \n",yytext);}
{double} {fprintf(yyout," double %s \n",yytext);}
{newline} {fprintf(yyout,"NEW LINE  %s \n",yytext);}
{tab}		{fprintf(yyout,"TAB %s \n",yytext);}
{backslash} {fprintf(yyout,"BACKSLASH %s \n",yytext);}
{underscore} {fprintf(yyout,"UNDERSCORE %s \n",yytext);}
{letter} {fprintf(yyout,"LETTER %s \n",yytext);}
{quote} {fprintf(yyout,"QUOTE %s \n",yytext);}
{string} {fprintf(yyout,"STRING %s \n",yytext);}

{left_curly_brace} {fprintf(yyout,"LEFT CURLY BRACE %s \n",yytext);}
{right_curly_brace} {fprintf(yyout,"RIGHT CURLY BRACE %s \n",yytext);}
{leftbracket} {fprintf(yyout,"LEFT BRACKET %s \n",yytext);}
{rightbracket} {fprintf(yyout,"RIGHT BRACKET %s \n",yytext);}
{right_parenthesis} {fprintf(yyout,"RIGHT PARENTHESIS %s \n",yytext);}
{left-parenthesis} {fprintf(yyout,"LEFT PARENTHESIS %s \n",yytext);}
{semicolon} {fprintf(yyout,"SEMICOLON %s \n",yytext);}
{comma} {fprintf(yyout,"COMMA %s \n",yytext);}
{colon} {fprintf(yyout,"COLON %s \n",yytext);}
{namespace} {fprintf(yyout,"NAMESPACE %s \n",yytext);}
{dot} {fprintf(yyout,"DOT %s \n",yytext);}
{double_dot} {fprintf(yyout,"DOUBLE DOT %s \n",yytext);}

{identifier} {fprintf(yyout,"IDENTIFIER %s \n",yytext);}

{comment} {fprintf(yyout,"SINGLE LINE COMMENT %s \n",yytext);}
{multiple_line_comment_start} {fprintf(yyout,"MULTIPLE LINE COMMENT %s \n",yytext);}
{multiple_line_comment_end} {fprintf(yyout,"MULTIPLE LINE COMMENT %s \n",yytext);}

%%

int main(int argc,char** argv){
	
	
	extern FILE *yyin,*yyout;
	yyin =fopen("test.txt","r");
	yyout =fopen("result.txt","w");
	
	// fprintf(stdout,"total tokens\n",number_of_tokens);
	
	yylex();
	
    return 0;

}








