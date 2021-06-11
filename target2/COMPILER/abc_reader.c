#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int magic_number;
    int total_chars, i,j;
    int totalStringConsts, totalNumConsts;
    char *name;
    int *numConsts;
    FILE *fp;

    fp = fopen("binary.abc", "rb");

    fread(&magic_number, sizeof(int), 1, fp);
    printf("magic_number: %d\n", magic_number);
    
    fread(&totalStringConsts, sizeof(int), 1, fp);
    printf("totalStringConsts: %d\n", totalStringConsts);

    for(i=0; i<totalStringConsts; i++){
        fread(&total_chars, sizeof(int), 1, fp);
        printf("malloc total_chars: %d\n", total_chars);
        name = (char*)malloc(sizeof(char) * total_chars);

        for(j=0; j<total_chars; j++){
            fread(&name[j], sizeof(char), 1, fp);
        }
        printf("name is: %s\n", name);
        name = realloc(name, sizeof(char));
    }

    fread(&totalNumConsts, sizeof(totalNumConsts), 1, fp);
    printf("totalNumConsts: %d\n", totalNumConsts);



    fclose(fp);
    return 0;
}