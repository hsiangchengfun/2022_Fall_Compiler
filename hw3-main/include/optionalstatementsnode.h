#ifndef _OPTIONALSTATEMENTSNODE_H
#define _OPTIONALSTATEMENTSNODE_H

#include "ast.h"
#include "statementlistnode.h"

typedef struct statementlistnode StatementlistNode;

typedef struct optionalstatementsnode{
    Node node;
    StatementlistNode* statementlistnode;

} OptionalStatementSNode;

Node* newOptionalStatementSNode( int, int, StatementlistNode*, int, int );

void* OptionalStatementSNode_visit(void*);

#endif