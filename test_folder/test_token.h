#include <stdio.h>
#include <string.h>

#define IF      1
#define ELSE    2
#define WHILE   3
#define FOR     4
#define MULTILINE_COMMENT  5




/*
struct alpha_token_t {

    struct alpha_token_t* next;
    int line_number = line_number;
    //int token_number = 
    char* token_string;
    enum token_types type;
};
*/

struct alpha_token_t {
  int     numLine;
  int     numToken;
  char*   content;
  char    *type;
  struct alpha_token_t* next; /*next token pointer*/
};

/*
enum token_types {
    KEYWORD,
    OPERATOR,
    INTCONST,
    STRING,
    PUNCTUATION,
    ID,
    COMMENTS
};
*/

int line_number = 1;
int token_number = 0;

char *content_string;
char *content_type;



void printToken(){

}


void printTokenList(struct alpha_token_t* head){

  struct alpha_token_t* temp = head;
  /*
  while(temp->next != NULL){

    printf("in line %d token_number %d", temp->numLine, temp->numToken);
    printf(" string_content: %s  content_type: %s\n", temp->content, temp->content);

    temp = temp->next;
  }

  if(temp->next == NULL){
    printf("in line %d token_number %d", temp->numLine, temp->numToken);
    printf(" string_content: %s  content_type: %s\n", temp->content, temp->content);
  }
  */

 while(temp != NULL){
  printf("in line %d token_number %d", temp->numLine, temp->numToken);
  printf(" string_content: %s  content_type: %s\n", temp->content, temp->type);\
  temp = temp->next;
 }

}


struct alpha_token_t* addToList(struct alpha_token_t* head, int line_number, int token_number, char* content_string, char* content_type){

  struct alpha_token_t* temp;
  
  temp = head;

  printf("in line %d token_number %d", line_number, token_number);
  printf(" string_content: %s  content_type: %s\n", content_string, content_type);


  if(head == NULL){

    head = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));
            
    head->numLine = line_number;
    head->numToken = token_number;

    head->content = strdup(content_string);
    head->type = strdup(content_type);
       printf("here!!\n");
    head->next = NULL;

    temp = head;
  } 
  else if(temp->next == NULL){
                
      temp->next = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));
                
      temp = temp->next;
                
      temp->numLine = line_number;
      temp->numToken = token_number;
      temp->content = strdup(content_string);
      temp->type = strdup(content_type);
      temp->next = NULL;
    
    } 
  else if(temp->next != NULL){
        
    while(temp->next != NULL)
      temp = temp->next;

    if(temp->next == NULL){

      temp->next = (struct alpha_token_t*)malloc(sizeof(struct alpha_token_t));
      temp = temp->next;

      temp->numLine = line_number;
      temp->numToken = token_number;
      temp->content = strdup(content_string);
      temp->type = strdup(content_type);
      temp->next = NULL;

    }

  }
    
    
  return head;
}