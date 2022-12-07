#ifndef _COMPOUNDSTATEMENTNODE_H
#define _COMPOUNDSTATEMENTNODE_H

#include "ast.h"
#include "optionalstatementsnode.h"

typedef struct optionalstatementsnode OptionalStatementSNode;

typedef struct compoundstatementnode{
    Node node;
    OptionalStatementSNode* statements;

} CompoundStatementNode;

void* CompoundStatementNode_visit(void*);

Node* newCompoundStatementNode( int, int, OptionalStatementSNode*, int, int );

#endif