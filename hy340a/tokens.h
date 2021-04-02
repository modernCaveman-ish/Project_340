#include <stdio.h>
#include <string.h>

#define IF      1
#define ELSE    2
#define WHILE   3
#define FOR     4
#define FUNCTION 5
#define RETURN 6
#define BREAK 7
#define CONTINUE 8
#define AND 9
#define NOT 10
#define OR 11
#define LOCAL 12
#define TRUE 13
#define FALSE 14
#define NIL 15
#define ASSINGMENT 15
#define ADD 16
#define SUBTRACT 17
#define MULTIPLY 18
#define DIVISION 19
#define MODULO 20

#define INCREAMENT1 21
#define DECREAMENT 22
#define EQUAL 23
#define DIFFERENT 24
#define LESS_THAN 25
#define GREATER_THAN 26
#define GREATER_EQUAL 27
#define LESS_EQUAL 28
#define LEFT_CURLY_BRACE 29
#define RIGHT_CURLY_BRACE 30
#define LEFT_BRACKET 31
#define RIGHT_BRACKET 32
#define RIGHT_PARENTHESIS 33
#define LEFT_PARENTHESIS 34
#define SEMICOLON 35
#define COMMA 36
#define COLON 37
#define NAMESPACE 38
#define DOT 39
#define DOUBLE_DOT 40
#define WHITESPACE 41
#define TAB 42
#define BACKSLASH 43
#define UNDERSCORE 44
#define LETTER 45
#define QUOTE 46
#define STRING 47
#define COMMENT 48
#define INTEGER 49
#define DOUBLE 50
#define ID 51
#define MULTIPLE_COMMENT 52
#define NESTED_COMMENT 53


struct alpha_token_t {
  int     numLine;
  int     numToken;
  char*   content;
  char    *type;
  struct alpha_token_t* next; /*next token pointer*/
};

struct comment_struct {
  int comment_counter;
  char *content;
  struct comment_struct *next;
};
