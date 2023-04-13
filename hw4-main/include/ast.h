#ifndef __AST_H__
#define __AST_H__

#include <stdint.h>

#include "loc.h"
#define REAL_AS_DOUBLE 0

#if REAL_AS_DOUBLE
  #define real    double
  #define ator    atof
  #define RFMT    "%lf"
  #define REALFMT "D"
  #define realfmt "d"
  #define ldc_real "ldc2_w"
  #define REAL_SIZE 2
#else
  #define real    float
  #define ator    (float)atof
  #define RFMT    "%f"
  #define REALFMT "F"
  #define realfmt "f"
  #define ldc_real "ldc"
  #define REAL_SIZE 1
#endif
/* It's just for reference,
 * you can design your own
 * struct or class to impl inheritance in c/cpp */

typedef enum{   NODE_Prog, 
				NODE_IdentList, 
				NODE_Declaration, 
				NODE_Type, 
				NODE_StandardType, 
				NODE_SubProgramDeclarationS, 
				NODE_SubProgramDeclaration, 
				NODE_SubProgramHead, 
				NODE_Arguments, 
				NODE_ParameterList, 
				NODE_OptionalVar, 
				NODE_CompoundStatement, 
				NODE_OptionalStatementS, 
				NODE_StatementList, 
				NODE_Statement, 
				NODE_Var, 
				NODE_Tail, 
				NODE_ProcedureStatement, 
				NODE_ExpList, 
				NODE_Exp, 
				NODE_BoolExp,
 				NODE_SimpleExp, 
				NODE_Term, 
				NODE_Factor, 
				NODE_AddOp, 
				NODE_MulOp, 
				NODE_RelOp, 
				NODE_Num, /* types */ } NodeType;

typedef struct NodeTag{
	NodeType type;
	LocType  loc;
	int (*visit)(void*);


} Node;

// /*
// #define Obj void*

// typedef struct ConsTag{
//   Obj car;
//   struct ConsTag *cdr;
// } *Cons, ConsStr;
// */

	
#endif
