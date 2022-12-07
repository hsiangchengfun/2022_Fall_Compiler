#ifndef __AST_H__
#define __AST_H__

#include <stdint.h>

#include "loc.h"

/* It's just for reference,
 * you can design your own
 * struct or class to impl inheritance in c/cpp */

typedef enum{ _ProgNode, 
				_IdentListNode, 
				_DeclarNode, 
				_TypeNode, 
				_StandTypeNode, 
				_SubDeclarSNode, 
				_SubDeclarNode, 
				_SubHeadNode, 
				_ArgumentsNode, 
				_ParameterListNode, 
				_OptionalVarNode, 
				_CompoundStatementNode, 
				_OptionalStatementSNode, 
				_StatementListNode, 
				_StatementNode, 
				_VarNode, 
				_TailNode, 
				_ProcedStatementNode, 
				_ExpListNode, 
				_ExpNode, 
				_BoolExpNode, 
				_SimpleExpNode, 
				_TermNode, 
				_FactorNode, 
				_AddNode, 
				_MulNode, 
				_RelopNode, 
				_NumNode, /* types */ } NodeType;

typedef struct NodeTag{
	NodeType type;
	LocType  loc;
	// I don't know what to do
	void* (*visit)(void*);
} Node;

/*
#define Obj void*

typedef struct ConsTag{
  Obj car;
  struct ConsTag *cdr;
} *Cons, ConsStr;
*/


#endif
