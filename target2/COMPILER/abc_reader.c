#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "target.h"

int main(){
    int magic_number;
    int total_chars, i,j;
    int totalStringConsts, totalNumConsts, totalUserFuncs, totalNamedLibFuncs;
    char *name;
    double *numConsts;
    userfunc *userFuncs;
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

    numConsts = (double*)malloc(sizeof(double) * totalNumConsts);
    for(j=0; j< totalNumConsts; j++){
       fread(&numConsts[j], sizeof(double), 1, fp); 
    }

    printf("numConsts: ");
    for(i = 0; i<totalNumConsts-1; i++){
        printf("%f, ", numConsts[i]);
    }
    printf("%f\n", numConsts[i]);

    fread(&totalUserFuncs, sizeof(int), 1, fp);
    printf("totalUserFuncs: %d\n", totalUserFuncs);

    userFuncs = (userfunc*)malloc(sizeof(userfunc) * totalUserFuncs);
    for(i=0; i<totalUserFuncs; i++){
        fread(&userFuncs[i].address, sizeof(unsigned int), 1, fp);
        fread(&userFuncs[i].localSize, sizeof(unsigned int), 1, fp);

        //proxeiro print
        //printf("userFuncs[%d].address = %d\n", i, userFuncs[i].address);
        //printf("userFuncs[%d].localSize = %d\n", i, userFuncs[i].localSize);

        //twra bale id
        fread(&total_chars, sizeof(int), 1, fp);
        userFuncs[i].id = (char*)malloc(sizeof(char) * total_chars);
        for(j=0; j<total_chars; j++){
            fread(&userFuncs[i].id[j], sizeof(char), 1, fp);
        }
        //proxeiro print
        //printf("userFuncs[%d].id: %s\n", i, userFuncs[i].id);
    }  
    
    //kanoniko print
    for(i=0; i<totalUserFuncs; i++){
        printf("userFuncs[%d].address = %d\n", i, userFuncs[i].address);
        printf("userFuncs[%d].localSize = %d\n", i, userFuncs[i].localSize);
        printf("userFuncs[%d].id: %s\n", i, userFuncs[i].id);
    }

    fread(&totalNamedLibFuncs, sizeof(int), 1, fp);
    printf("totalNamedLibFuncs: %d\n", totalNamedLibFuncs);


    fclose(fp);
    return 0;
}