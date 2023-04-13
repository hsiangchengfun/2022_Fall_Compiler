#include "ast.h"
#include "codegen.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib.h"
#include <string.h>
#include "print.h"

extern char *output;
extern int f=0;



#define gen(fmt, ...) fprintf(fd, fmt)


FILE *fd;
char *prog;
extern char *output;






//========================================
list* ARRAY_ARRAY[250];
int ARRAY_TYPE_ARRAY[250]={};
int ARRAY_NUM = 0;
//========================================
int VARIABLE_index = 0;
char VARIABLE_TYPE_ARRAY[250];
char* VARIABLE_ARRAY[250];
//========================================
int FACTOR_STRING_NUM = 0;
char* FACTOR_STRING_ARRAY[250];
//========================================
int DECLARE_ARRAY_NUM = 0;
char* DECLARE_ARRAY[250];
char TYPE_ARRAY[250];
//========================================
int AddOp_Add = 0;
int RELOP_NUM = 1;
extern int RelOp_EQ = 0;
//========================================
extern TO_FUNC = 0;
int FUNCTION_LIST_ARRAY_NUM = 0;
list* FUNCTION_LIST_ARRAY[250];
int FUNCTION_INVOKESTATIC_TYPE[250] = {};
char* FUNCTION_ARRAY[250];
char FUNCTION_TYPE_ARRAY[250];
int FUNCTION_ARRAY_NUM = 0;
//========================================


void GENCODE(ProgNode* root){
    char fn[128];
    prog = root->id;
    sprintf(fn, "%s.j", root->id);
    fd = fopen(output ? output : fn, "w"); 
    fprintf(fd, ".class public %s\n",prog);
    fprintf(fd, ".super java/lang/Object\n");

}


void GEN_PBEGIN(){
    fprintf(fd, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(fd, ".limit locals 50\n");
    fprintf(fd, ".limit stack 50\n");
    for (int i = 0; i < DECLARE_ARRAY_NUM; i++){
        switch (TYPE_ARRAY[i])
        {
        case 'F':
            fprintf(fd, "    ldc 0.0\n");
            fprintf(fd, "    putstatic %s/%s F\n",prog,DECLARE_ARRAY[i]);
            break;
        case 'I':
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    putstatic %s/%s I\n",prog,DECLARE_ARRAY[i]);
            break;
        case 'S':
            fprintf(fd, "    ldc \"\"\n");
            fprintf(fd, "    putstatic %s/%s Ljava/lang/String;\n",prog,DECLARE_ARRAY[i]);
            break;
        }
    }

    for (int i = 0; i < ARRAY_NUM; i++){
        symbolobj* tmp = ARRAY_ARRAY[i]->data;
        symbolobj* tmp1 = ((arraysymbolobj*)tmp)->data;
        int LENGTH0 = ( ((arraysymbolobj*)tmp)->end  - ((arraysymbolobj*)tmp)->start ) + 1;
        int LENGTH1 = ( ((arraysymbolobj*)tmp1)->end - ((arraysymbolobj*)tmp1)->start )+ 1;
        
        
        if(tmp->type == Array){
            if(ARRAY_TYPE_ARRAY[1]==0){
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    ldc %d\n",LENGTH1);
                fprintf(fd, "    multianewarray [[I 2\n");
                fprintf(fd, "    putstatic %s/%s [[I\n",prog,ARRAY_ARRAY[i]->id);
            }else if(ARRAY_TYPE_ARRAY[1]==1){
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    ldc %d\n",LENGTH1);
                fprintf(fd, "    multianewarray [[F 2\n");
                fprintf(fd, "    putstatic %s/%s [[F\n",prog,ARRAY_ARRAY[i]->id);
            }
            else{
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    ldc %d\n",LENGTH1);
                fprintf(fd, "    multianewarray [[Ljava/lang/String; 2\n");
                fprintf(fd, "    putstatic %s/%s [[Ljava/lang/String;\n",prog,ARRAY_ARRAY[i]->id);
            }


        }else{
            if(ARRAY_TYPE_ARRAY[1] == 0){
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    multianewarray [I 1\n");
                fprintf(fd, "    putstatic %s/%s [I\n",prog,ARRAY_ARRAY[i]->id);
            }else if(ARRAY_TYPE_ARRAY[1] == 1){
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    multianewarray [F 1\n");
                fprintf(fd, "    putstatic %s/%s [F\n",prog,ARRAY_ARRAY[i]->id);
            }
            else{
                fprintf(fd, "    ldc %d\n",LENGTH0);
                fprintf(fd, "    multianewarray [Ljava/lang/String; 1\n");
                fprintf(fd, "    putstatic %s/%s [Ljava/lang/String;\n",prog,ARRAY_ARRAY[i]->id);
            }



        }
        

    }
}


void GEN_END(){
    fprintf(fd, "    return\n");
    fprintf(fd, ".end method\n");
    fclose(fd);
}



void GEN_DECLARE(char * id, int type){
    switch(type){
        case 0:
        //for int
        if(!TO_FUNC){
            DECLARE_ARRAY[DECLARE_ARRAY_NUM] = id;
            TYPE_ARRAY[DECLARE_ARRAY_NUM] = 'I';
            DECLARE_ARRAY_NUM++;
            fprintf(fd, ".field public static %s I\n",id);
        }
        else if(TO_FUNC){
            fprintf(fd, ".field public static %s I\n",id);
            FUNCTION_ARRAY[FUNCTION_ARRAY_NUM] = id;
            FUNCTION_TYPE_ARRAY[FUNCTION_ARRAY_NUM] = 'I';
            FUNCTION_ARRAY_NUM++;
        }
        case 1:
        //for real
        if(!TO_FUNC){
            DECLARE_ARRAY[DECLARE_ARRAY_NUM] = id;
            TYPE_ARRAY[DECLARE_ARRAY_NUM] = 'F';
            DECLARE_ARRAY_NUM++;
            fprintf(fd, ".field public static %s F\n",id);
        }
        else if(TO_FUNC){
            fprintf(fd, ".field public static %s F\n",id);
            FUNCTION_ARRAY[FUNCTION_ARRAY_NUM] = id;
            FUNCTION_TYPE_ARRAY[FUNCTION_ARRAY_NUM] = 'F';
            FUNCTION_ARRAY_NUM++;
        }
        case 2:
        //for string
        if(!TO_FUNC){
            DECLARE_ARRAY[DECLARE_ARRAY_NUM] = id;
            TYPE_ARRAY[DECLARE_ARRAY_NUM] = 'S';
            DECLARE_ARRAY_NUM++;
            fprintf(fd, ".field public static %s Ljava/lang/String;\n",id);
        }
        else if(TO_FUNC){
            fprintf(fd, ".field public static %s Ljava/lang/String;\n",id);
            FUNCTION_ARRAY[FUNCTION_ARRAY_NUM] = id;
            FUNCTION_TYPE_ARRAY[FUNCTION_ARRAY_NUM] = 'S';
            FUNCTION_ARRAY_NUM++;
        }
    }
}


void GEN_ARRAY_ID(char* str){
    fprintf(fd, "    %s\n",str);  
}

void GEN_ARRAY_FIELD(list* arr, int type){
    ARRAY_ARRAY[ARRAY_NUM] = arr;
    ARRAY_TYPE_ARRAY[DECLARE_ARRAY_NUM] = type;
    ARRAY_NUM++;
    symbolobj* tmp = ((arraysymbolobj*)tmp)->data;
    if(tmp->type== Array){
        if(type == 0)fprintf(fd, ".field public static %s [[I\n",arr->id);
        else if(type==1)fprintf(fd, ".field public static %s [[F\n",arr->id);
        else fprintf(fd, ".field public static %s [[Ljava/lang/String;\n",arr->id);

    }else{
        if(type == 0)fprintf(fd, ".field public static %s [I\n",arr->id);
        else if(type==1)fprintf(fd, ".field public static %s [F\n",arr->id);
        else fprintf(fd, ".field public static %s [Ljava/lang/String;\n",arr->id);
    }


}

void GEN_GET_FUNCTION(char* str, int type){
    for(int i = 0; i < FUNCTION_LIST_ARRAY_NUM; i++){
        int ch = strcmp(FUNCTION_LIST_ARRAY[i]->id, str);
        if (ch == 0) {
            GEN_FUNCTION_INIT(FUNCTION_LIST_ARRAY[i],i); 
            break;
        }
    }
}

void GEN_FUNCTION_INIT(list* root, int index){
    if (!FUNCTION_INVOKESTATIC_TYPE[index])
    {
        symbolobj* tmp = root->data;
        char* pass;
        passinobj* tmpPassInType = (passinobj*)((funcsymbolobj*)tmp)->passInType;
        pass= (!tmpPassInType)? "" :(tmpPassInType->data->type == Int)? "I" : ((tmpPassInType->data->type) == Real) ? "F" : "Ljava/lang/String;";
        switch (tmp->type)
        {
        case Int:
            fprintf(fd, "    invokestatic %s/%s_%d(%s)I\n",prog,root->id,index,pass);
            break;
        case Real:
            fprintf(fd, "    invokestatic %s/%s_%d(%s)F\n",prog,root->id,index,pass);
            break;
        case String:
            fprintf(fd, "    invokestatic %s/%s_%d(%s)Ljava/lang/String;\n",prog,root->id,index,pass);
            break;
        default:
            break;
        }
        FUNCTION_INVOKESTATIC_TYPE[index]++;
    }
}

void GEN_PROCEDURE(char* id){
    if (!(strcmp(id, "writelnI")))fprintf(fd, "    invokestatic %s/writelnI(I)V\n",prog);
    else if(!(strcmp(id, "writelnR")))fprintf(fd, "    invokestatic %s/writelnR(F)V\n",prog);
    else if(!(strcmp(id, "writelnS")))fprintf(fd, "    invokestatic %s/writelnS(Ljava/lang/String;)V\n",prog);
}

void GEN_NUM(int INT , double REAL,int type){
    if(type==0)fprintf(fd, "    ldc %f\n",REAL);
    else fprintf(fd, "    ldc %d\n",INT);
}


void GEN_FACTOR_BLOBAL(char *str){
    if(TO_FUNC){
        for (int i = 0; i < FUNCTION_ARRAY_NUM; i++){
            if (!strcmp(FUNCTION_ARRAY[i], str)){
                switch (FUNCTION_TYPE_ARRAY[i])
                {
                case 'F':
                    fprintf(fd, "    fload %d\n",i);
                    break;
                case 'I':
                    fprintf(fd, "    iload %d\n",i);
                    break;
                case 'S':
                    break;
                }
                return;
            }
        }
    }

    if(DECLARE_ARRAY_NUM != 0){
        for (int i = 0; i < DECLARE_ARRAY_NUM; i++){
            if (!strcmp(DECLARE_ARRAY[i], str)) {
                switch (TYPE_ARRAY[i])
                {
                case 'F':
                    fprintf(fd, "    getstatic %s/%s F\n",prog,DECLARE_ARRAY[i]);
                    break;
                case 'I':
                    fprintf(fd, "    getstatic %s/%s I\n",prog,DECLARE_ARRAY[i]);
                    break;
                case 'S':
                    fprintf(fd, "    getstatic %s/%s Ljava/lang/String;\n",prog,DECLARE_ARRAY[i]);
                    break;
                }
                return;
            }
        }
    }

    if (!TO_FUNC){
        if(FUNCTION_LIST_ARRAY_NUM != 0){
            for(int i = 0; i < FUNCTION_LIST_ARRAY_NUM; i++){
                if (!strcmp(FUNCTION_LIST_ARRAY[i]->id, str)) {
                    GEN_FUNCTION_INIT(FUNCTION_LIST_ARRAY[i],i); 
                    return;
                }
            }
        }
        fprintf(fd, "    invokestatic %s/%s()I\n",prog,str);
    }
    
}

void GEN_FACTOR_IF_ADDOP(char* str){
    if(!AddOp_Add)fprintf(fd, "    ldc %s\n",str);
}

void GEN_FACTOR_SAVE_STRING(char* str){
    FACTOR_STRING_ARRAY[FACTOR_STRING_NUM] = str;
    FACTOR_STRING_NUM++;
}



void GEN_FACTOR_NE(){
    fprintf(fd, "    ldc 1\n");
    fprintf(fd, "    ifne L%d\n",RELOP_NUM);
    fprintf(fd, "    ldc 1\n");
    fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
    fprintf(fd, "L%d:\n",RELOP_NUM);
    fprintf(fd, "    ldc 0\n");
    fprintf(fd, "L%d:\n",RELOP_NUM+1);
    RELOP_NUM++;
}

void GEN_FACTOR_NEG(){
    fprintf(fd, "    fneg\n");
}

void GEN_VARIABLE_SET_LABEL(char* str, int type){   
    VARIABLE_ARRAY[VARIABLE_index] = str;
    VARIABLE_TYPE_ARRAY[VARIABLE_index] = (type == 0)? 'I': (type == 1 )? 'F' : 'S';
    VARIABLE_index++;
}


void GEN_VARIABLE(char* str){
    if (!TO_FUNC){
        for (int i = 0; i <= VARIABLE_index; i++){
            if (!(strcmp(VARIABLE_ARRAY[i], str))) {
                switch (VARIABLE_TYPE_ARRAY[i])
                {
                case 'F':
                    fprintf(fd, "    putstatic %s/%s F\n",prog,VARIABLE_ARRAY[i]);
                    break;
                case 'I':
                    fprintf(fd, "    putstatic %s/%s I\n",prog,VARIABLE_ARRAY[i]);
                    break;
                case 'S':
                    fprintf(fd, "    putstatic %s/%s Ljava/lang/String;\n",prog,VARIABLE_ARRAY[i]);
                    break;
                }
                return;
            }
        }
    }else if(TO_FUNC){
        for (int i = 0; i < FUNCTION_ARRAY_NUM; i++){
            if (!(strcmp(FUNCTION_ARRAY[i], str))){
                
                if(FUNCTION_TYPE_ARRAY[i] == 'I')fprintf(fd, "    istore %d\n",i);
                else if (FUNCTION_TYPE_ARRAY[i] == 'F')fprintf(fd, "    Fstore %d\n",i);
                return;
            }
        }
    }
}

void GEN_ADDOPNODE(int pos, int type){
    if (type == 0){
        char* op = (pos)? "iadd" : "isub" ;
        fprintf(fd,"    %s\n",op);
    }else if(type == 3 && AddOp_Add){   
        fprintf(fd, "new java/lang/StringBuffer\n");
        fprintf(fd, "dup\n");
        fprintf(fd, "invokespecial java/lang/StringBuffer/<init>()V\n");
        fprintf(fd, "    ldc %s\n",FACTOR_STRING_ARRAY[0]);
        fprintf(fd, "invokevirtual java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;\n");
        fprintf(fd, "    ldc %s\n",FACTOR_STRING_ARRAY[FACTOR_STRING_NUM-1]);
        fprintf(fd, "invokevirtual java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;\n");
        fprintf(fd, "invokevirtual java/lang/StringBuffer/toString()Ljava/lang/String;\n");
    }else{
        char* op = (pos)? "fadd" : "fsub" ;
        fprintf(fd,"    %s\n",op);
    }
}

void GEN_MULNODE(int pos, int isfloat){
    if (!isfloat){
        char * op = (pos) ? "idiv" : "imul";
        fprintf(fd, "    %s\n",op);        
    }else{
        char * op = (pos) ? "fdiv" : "fmul";
        fprintf(fd, "    %s\n",op);   
    }
}

void GEN_RELOPNODE(int pos, int type){
    if (type == 2){
        switch (pos)
        {
        case 0:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc -1\n");
            fprintf(fd, "    if_icmpeq L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 1:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "    if_icmpeq L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 2:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    if_icmpeq L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 3:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc -1\n");
            fprintf(fd, "    if_icmpgt L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 4:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "    if_icmplt L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 5:
            fprintf(fd, "    fcmpg\n");
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    if_icmpne L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);  
        }
        RELOP_NUM++;
    }else{
        switch (pos)
        {
        case 0:
            fprintf(fd, "    if_icmplt L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 1:
            fprintf(fd, "    if_icmpgt L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 2:
            fprintf(fd, "    if_icmpeq L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 3:
            fprintf(fd, "    if_icmpge L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 4:
            fprintf(fd, "    if_icmple L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        case 5:
            fprintf(fd, "    if_icmpne L%d\n",RELOP_NUM);
            fprintf(fd, "    ldc 0\n");
            fprintf(fd, "    goto L%d\n",RELOP_NUM+1);
            fprintf(fd, "L%d:\n",RELOP_NUM);
            fprintf(fd, "    ldc 1\n");
            fprintf(fd, "L%d:\n",RELOP_NUM+1);
        }
        RELOP_NUM++;
    }
    RELOP_NUM++;
}






void GEN_FUNCTION(){   
    if (FUNCTION_LIST_ARRAY_NUM != 0){
        symbolobj* tmp = FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM-1]->data;
        char* pass;
        passinobj* tmpPassInType = (passinobj*)((funcsymbolobj*)tmp)->passInType;
        
        pass= (!tmpPassInType)? "" :(tmpPassInType->data->type == Int)? "I" : ((tmpPassInType->data->type) == Real) ? "F" : "Ljava/lang/String;";
        
        switch (tmp->type)
        {
        case Int:
            fprintf(fd, ".method public static %s_%d(%s)I\n",FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM-1]->id,FUNCTION_LIST_ARRAY_NUM-1,pass);
        case Real:
            fprintf(fd, ".method public static %s_%d(%s)F\n",FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM-1]->id,FUNCTION_LIST_ARRAY_NUM-1,pass);
         case String:
            fprintf(fd, ".method public static %s_%d(%s)Ljava/lang/String;\n",FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM-1]->id,FUNCTION_LIST_ARRAY_NUM-1,pass);
        default:
            break;
        }
        fprintf(fd, ".limit locals 50\n");
        fprintf(fd, ".limit stack 50\n");
        if(tmpPassInType != NULL){
            if(tmpPassInType->data->type == "Int")fprintf(fd, "    iload 0\n");
        }
    }
}

void GEN_FUNCTION_SET_ROOT(list* root){
    FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM] = root;
    FUNCTION_LIST_ARRAY_NUM++;
}

void GEN_FUNCTION_END(){
    if (FUNCTION_LIST_ARRAY_NUM != 0){
        if(FUNCTION_LIST_ARRAY[FUNCTION_LIST_ARRAY_NUM-1]->data->type == "Int"){
            fprintf(fd, "    ireturn\n");
            fprintf(fd, "    ireturn\n");
        }
    }
    fprintf(fd, ".end method\n");
}


void GEN_WhileLoop(){
    fprintf(fd, "L%d:\n",RELOP_NUM);
    RELOP_NUM++;
}

void GEN_WhileLoop_mid(){
    fprintf(fd, "    ifeq L%d\n",RELOP_NUM);
}
void GEN_WhileLoopDone(){
    fprintf(fd, "    goto L%d\n",RELOP_NUM-3);
    fprintf(fd, "L%d:\n",RELOP_NUM);
    RELOP_NUM++;
}


void GEN_IF(){
    if(RelOp_EQ) fprintf(fd, "    ifeq L%d\n",RELOP_NUM);
    else fprintf(fd, "    ifne L%d\n",RELOP_NUM);
    RELOP_NUM++;
}

void GEN_ELSE(){
    fprintf(fd, "    goto L%d\n",RELOP_NUM);
    fprintf(fd, "L%d:\n",RELOP_NUM-1);
}

void GEN_THEN(){
    fprintf(fd, "L%d:\n",RELOP_NUM);
    RELOP_NUM++;
    RelOp_EQ = 0;
}



void GEN_BUILDINGS(){
  gen(
      ".method public static writelnI(I)V\n"
      ".limit locals 5\n"
      ".limit stack 5\n"
      "    getstatic java/lang/System/out Ljava/io/PrintStream;\n"
      "    iload 0\n"
      "    invokevirtual java/io/PrintStream/println(I)V\n"
      "    return\n"
      ".end method\n"
      "\n"
      ".method public static writelnR(F)V\n"
      "    .limit locals 5\n"
      "    .limit stack 5\n"
      "    getstatic java/lang/System/out Ljava/io/PrintStream;\n"
      "    fload 0\n"
      "    invokevirtual java/io/PrintStream/println(F)V\n"
      "    return\n"
      ".end method\n"
      "\n"
      ".method public static writelnS(Ljava/lang/String;)V\n"
      "    .limit locals 5\n"
      "    .limit stack 5\n"
      "    getstatic java/lang/System/out Ljava/io/PrintStream;\n"
      "    aload 0\n"
      "    invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n"
      "    return\n"
      ".end method\n"
      "\n"
      ".method public static readlnI()I\n"
      "    .limit locals 10\n"
      "    .limit stack 10\n"
      "    ldc 0\n"
      "    istore 1\n"
      "LAB1:\n"
      "    getstatic java/lang/System/in Ljava/io/InputStream;\n"
      "    invokevirtual java/io/InputStream/read()I\n"
      "    istore 2\n"
      "    iload 2\n"
      "    ldc 10\n"
      "    isub\n"
      "    ifeq LAB2\n"
      "    iload 2\n"
      "    ldc 32\n"
      "    isub\n"
      "    ifeq LAB2\n"
      "    iload 2\n"
      "    ldc 48\n"
      "    isub\n"
      "    ldc 10\n"
      "    iload 1\n"
      "    imul\n"
      "    iadd\n"
      "    istore 1\n"
      "    goto LAB1\n"
      "LAB2:\n"
      "    iload 1\n"
      "    ireturn\n"
      ".end method\n");
}