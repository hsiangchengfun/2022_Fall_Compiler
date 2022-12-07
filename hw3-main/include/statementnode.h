#ifndef _STATEMENTNODE_H
#define _STATEMENTNODE_H

#include "ast.h"
#include "varnode.h"
#include "expnode.h"
#include "procedstatementnode.h"
#include "compoundstatementnode.h"

typedef struct compoundstatementnode CompoundStatementNode;

typedef struct statementnode{
    Node node;
    int type;
    VarNode* varnode;
    ExpNode* expnode;
    ProcedStatementNode* procedstatementnode;
    CompoundStatementNode* compoundstatementnode;
    struct statementnode* statementnode1;
    struct statementnode* statementnode2;

} StatementNode;

Node* newStatementNode( int, int, int, VarNode*, ExpNode*, ProcedStatementNode*, CompoundStatementNode*, StatementNode*, StatementNode*, int, int );

void* StatementNode_visit(void*);

#endif