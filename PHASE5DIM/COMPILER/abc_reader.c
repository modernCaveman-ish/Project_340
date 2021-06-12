#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "target.h"

unsigned char executionFinished = 0;
unsigned	  pc = 0;
unsigned	  currLine = 0;
unsigned      codeSize = 0;
instruction*  code = (instruction*) 0;


    int magic_number;
    int total_chars, i,j;
    int totalStringConsts, totalNumConsts, totalUserFuncs;
    unsigned int totalNamedLibFuncs, totalInstructions;
    char **stringConsts;
    char **namedLibFuncs;
   // unsigned currInstr;
    char *temp;
    double *numConsts;
    userfunc *userFuncs;
    instruction *instructions;
    FILE *fp;

char* vopcode[]={"assign_v", "add_v", "sub_v", 
	"mul_v", "div_v", "mod_v", 
	"uminus_v", "and_v", "or_v", 
	"not_v", "jeq_v"," jne_v", 
	"jle_v", "jge_v", "jlt_v", 
	"jgt_v"," call_v"," pusharg_v", 
	"funcenter_v", "funcexit_v", "newtable_v", 
	"tablegetelem_v", "tablesetelem_v", 
	"jump_v", "nop_v"
};

void print_label(vmarg *e){
   // if(e==NULL)return;
   // if(e->sym!=NULL)
    //printf("%d", e->type);

	printf("%d", e->val);
	printf("(label)\t");
}

void print_global(vmarg *e){
	printf("%d", e->val);
	printf("(global)\t");
}

void print_formal(vmarg *e){
	printf("%d", e->val);
	printf("(formal)\t");
}

void print_local(vmarg *e){
	printf("%d", e->val);
	printf("(local)\t");
}

void print_number(vmarg *e){
    printf("%f", numConsts[e->val]);
	printf("(number)\t");
}

void print_string2(vmarg *e){
    printf("%s", stringConsts[e->val]);
	printf("(string)\t");
}

void print_bool2(vmarg *e){
    printf("%d", e->val);
	printf("(boolean)\t");
}

void print_nil2(vmarg * e){
    printf("nil\t");
}

void print_libfunc(vmarg *e){
	printf("%s", namedLibFuncs[e->val]);
	printf("(libfunc)\t");
}

void print_userfunc(vmarg *e){
	printf("%s", userFuncs[e->val].id);
	printf("(userfunc)\t");
}

void print_retval(vmarg *e){

	printf("retval\t");
}

void (*vmarg_prints[12])(vmarg *) = {
    print_label,
    print_global,
    print_formal,
    print_local,
    print_number,
    print_string2,
    print_bool2,
    print_nil2,
	print_userfunc,
	print_libfunc,
	print_retval
};

void print_vmarg (struct vmarg *e) {
    if(e == NULL){
        printf(" ");
    } else if (e->type == empty){
		printf(" ");
	}else{
        //analogws to type prepei na ektypwseis to katallilo pedio tou expr
        //px constring_e ektypws to strconst
     /*   if(expr->type == 8){ //print ta noymera
         printf("%d\t\t\t", expr->numConst);
        }  else if(expr->type == 10){
            printf("%s\t\t\t", expr->strConst);
        } else if(expr->type == 9){
            printf("%c\t\t\t", expr->boolConst);
        }*/
        vmarg_prints[e->type](e);
     printf(" ");
    }
}

/*
void print_labels(instruction *q){
//check and print the lable if eligible
   struct instruction *tmpinstr = q;
   
   if (tmpinstr->opcode==jump_op||
        tmpinstr->opcode==if_greatereq_op||
        tmpinstr->opcode==if_less_op||
        tmpinstr->opcode==if_eq_op||tmpinstr->opcode==if_lesseq_op||tmpinstr->opcode==if_greater_op){
       printf("%d",tmpinstr->label);
   }
}*/

void Instruction_Print(){
	printf("\n\n\n");
//quad# opcode,result,arg1,arg2,label
	struct quad *tmpinstr;
	int i;
    
   // printf("instuction#\topcode\t\t\t result\t\t\targ1\t\t\targ2\t\t\tlabel\t\t\t\n");
	
    for(i=0;i<totalInstructions;i++){
        printf("%d ",i);
       
        printf("%s ", vopcode[instructions[i].opcode]);
        if(instructions[i].result.type != empty){
            print_vmarg(&instructions[i].result);
    
            print_vmarg(&instructions[i].arg1);
                //     if(i==3)break;
            print_vmarg(&instructions[i].arg2);
        }else if(instructions[i].arg1.type != empty){
            print_vmarg(&instructions[i].arg1);
            if(instructions[i].opcode!=call_v && instructions[i].opcode!=pusharg_v )
				print_vmarg(&instructions[i].arg2);
        }

        //print_labels(&quads[i]);
        printf("\n");
    }
}



int main(){
   
    fp = fopen("binary.abc", "rb");

    fread(&magic_number, sizeof(int), 1, fp);
    
    fread(&totalStringConsts, sizeof(int), 1, fp);

    stringConsts = (char**)malloc(sizeof(char) * totalStringConsts);
    
    for(i=0; i<totalStringConsts; i++){
        fread(&total_chars, sizeof(int), 1, fp);
        stringConsts[i] = (char*)malloc(sizeof(char) * total_chars);

        for(j=0; j<total_chars; j++){
            fread(&stringConsts[i][j], sizeof(char), 1, fp);
        }
        printf("%s ",  stringConsts[i]);
    }

    fread(&totalNumConsts, sizeof(totalNumConsts), 1, fp);

    numConsts = (double*)malloc(sizeof(double) * totalNumConsts);
    for(j=0; j< totalNumConsts; j++){
       fread(&numConsts[j], sizeof(double), 1, fp); 
    }

    printf("numConsts: ");
    for(i = 0; i<totalNumConsts-1; i++){
        printf("---%f, ", numConsts[i]);
    }
    printf("%f\n", numConsts[i]);

    fread(&totalUserFuncs, sizeof(int), 1, fp);

    userFuncs = (userfunc*)malloc(sizeof(userfunc) * totalUserFuncs);
    for(i=0; i<totalUserFuncs; i++){
        fread(&userFuncs[i].address, sizeof(unsigned int), 1, fp);
        fread(&userFuncs[i].localSize, sizeof(unsigned int), 1, fp);

        //twra bale id
        fread(&total_chars, sizeof(int), 1, fp);
        userFuncs[i].id = (char*)malloc(sizeof(char) * total_chars);
        for(j=0; j<total_chars; j++){
            fread(&userFuncs[i].id[j], sizeof(char), 1, fp);
        }
        printf("%s ",   userFuncs[i].id );

    }  

    fread(&totalNamedLibFuncs, sizeof(unsigned int), 1, fp);
    namedLibFuncs = (char **)malloc(sizeof(char) * totalNamedLibFuncs);

    for(i=0; i<totalNamedLibFuncs; i++){
        fread(&total_chars, sizeof(int), 1, fp);
        namedLibFuncs[i] = (char *)malloc(sizeof(char) * total_chars);
        for(j=0; j<total_chars; j++){
            fread(&namedLibFuncs[i][j], sizeof(char), 1, fp);
        }
         printf("%s ",   namedLibFuncs[i] );
    }


    for(i=0; i<totalNamedLibFuncs; i++){
        temp = namedLibFuncs[i];
    }

    fread(&totalInstructions, sizeof(unsigned int), 1, fp);

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

 Instruction_Print();

    fclose(fp);
    return 0;
}