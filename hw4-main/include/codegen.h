#ifndef __CODEGEN_H__
#define __CODEGEN_H__


#include "ast.h"
#include <stdlib.h>
#include "loc.h"
#include "lib.h"
#include "print.h"
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>


typedef struct prognode ProgNode;


void GENCODE(ProgNode* );
void GEN_END();
void GEN_BUILDINGS();
void GEN_PBEGIN();
void GEN_GET_FUNCTION(char* , int);
void GEN_FUNCTION_INIT(list* , int);
void GEN_DECLARE(char * , int );
void GEN_PROCEDURE(char* );
void GEN_ARRAY_FIELD(list* , int );
void GEN_ARRAY_ID(char* );
void GEN_FUNCTION();
void GEN_FUNCTION_END();
void GEN_FUNCTION_SET_ROOT(list* );
void GEN_FACTOR_BLOBAL(char *);
void GEN_FACTOR_SAVE_STRING(char* );
void GEN_FACTOR_IF_ADDOP(char* );
void GEN_FACTOR_NE();
void GEN_FACTOR_NEG();
void GEN_ADDOPNODE(int , int);
void GEN_MULNODE(int,int);
void GEN_NUM(int  , double ,int );
void GEN_RELOPNODE(int , int );
void GEN_VARIABLE(char* );
void GEN_IF();
void GEN_ELSE();
void GEN_THEN();
void GEN_WhileLoop();
void GEN_WhileLoop_mid();
void GEN_WhileLoopDone();
void GEN_VARIABLE_SET_LABEL();

#endif