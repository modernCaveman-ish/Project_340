#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int get_length(char *str_buff){
  char *temp = str_buff;
  int length = 0;
    int i=0;


  while(temp[i] != '\0'){

    length++;
    i++;
  }

  return length;
}

size_t ms_length(const char *pcStr)
{
    size_t uiLength = 0U;
    assert(pcStr != NULL);
    while (*(pcStr + uiLength) != '\0')
        uiLength++;
    return uiLength;
}

char *ms_concat(char *dest, const char *src){
    char *new_dest = (char *) malloc(sizeof(ms_length(dest) + ms_length(src)));
    int i = 0;

    assert(dest != NULL);
    assert(src != NULL);
    assert(new_dest != NULL);

    while(i<ms_length(dest)){
        *(new_dest + i) = *(dest + i);
        i++;
    }
    
    i=0;
    while(i<ms_length(src)){
        *(new_dest + ms_length(dest) + i) = *(src + i);
        i++;
    }


    return new_dest;
}


int main () {
    char *str_buff = "ada";
    int length;


    length = get_length(str_buff);

    printf("To length einai :%d\n", length);

    //strcat("\n", &str_buff);

    str_buff = ms_concat(str_buff, "\n");
    str_buff = ms_concat(str_buff, "dadda");
    //strcat(str_buff, "malaka");

    printf("%s\n", str_buff);

    return 0;
    
}