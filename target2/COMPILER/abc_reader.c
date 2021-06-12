#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "target.h"

int main(){
    int magic_number;
    int total_chars, i,j;
    int totalStringConsts, totalNumConsts, totalUserFuncs;
    unsigned int totalNamedLibFuncs, totalInstructions;
    char *name;
    char **namedLibFuncs;
    char *temp;
    double *numConsts;
    userfunc *userFuncs;
    instruction *instructions;
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

    fread(&totalNamedLibFuncs, sizeof(unsigned int), 1, fp);
    printf("totalNamedLibFuncs: %d\n", totalNamedLibFuncs);
    namedLibFuncs = (char **)malloc(sizeof(char) * totalNamedLibFuncs);

    for(i=0; i<totalNamedLibFuncs; i++){
        printf("1\n");
        fread(&total_chars, sizeof(int), 1, fp);
        printf("2\n");
        namedLibFuncs[i] = (char *)malloc(sizeof(char) * total_chars);
        printf("3\n");
        for(j=0; j<total_chars; j++){
            printf("4\n");
            fread(&namedLibFuncs[i][j], sizeof(char), 1, fp);
            printf("5\n");
        }
        printf("6\n");
    }


    for(i=0; i<totalNamedLibFuncs; i++){
        temp = namedLibFuncs[i];
        //printf("namedLibFuncs[%d]: %s\n", i, namedLibFuncs[i]);
        printf("namedLibFuncs[%d]: %s\n", i, temp);
    }

    fread(&totalInstructions, sizeof(unsigned int), 1, fp);
    printf("totalInstructions: %d\n", totalInstructions);

    instructions = (instruction*)malloc(sizeof(instruction) * totalInstructions);
    for(i=0; i<totalInstructions; i++){
        fread(&instructions[i].opcode, sizeof(instructions[i].opcode), 1, fp);
        //result
        fread(&instructions[i].result.type, sizeof(instructions[i].result.type), 1, fp);
        fread(&instructions[i].result.val, sizeof(instructions[i].result.val), 1, fp);
        //arg1
        fread(&instructions[i].arg1.type, sizeof(instructions[i].arg1.type), 1, fp);
        fread(&instructions[i].arg1.val, sizeof(instructions[i].arg1.val), 1, fp);
        //arg2
        fread(&instructions[i].arg2.type, sizeof(instructions[i].arg2.type), 1, fp);
        fread(&instructions[i].arg2.val, sizeof(instructions[i].arg2.val), 1, fp);
    }

    printf("\n\tInstructions\n");
    //printf("\topcode\tresult.type, val\targ1.type, val\targ2,type, val\n");
    
    for(i=0; i<totalInstructions; i++){
        printf("instructions[%d].opcode: %d\n", i, instructions[i].opcode);
        printf("instructions[%d].result.type: %d\n", i, instructions[i].result.type);
        printf("instructions[%d].result.val: %d\n", i, instructions[i].result.val);
        printf("instructions[%d].arg1.type: %d\n", i, instructions[i].arg1.type);
        printf("instructions[%d].arg1.val: %d\n", i, instructions[i].arg1.val);
        printf("instructions[%d].arg2.type: %d\n", i, instructions[i].arg2.type);
        printf("instructions[%d].arg2.val: %d\n", i, instructions[i].arg2.val);
    }
    

    fclose(fp);
    return 0;
}