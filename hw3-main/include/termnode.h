#ifndef _TERMNODE_H
#define _TERMNODE_H

#include "ast.h"
#include "factornode.h"
#include "mulnode.h"

typedef struct factornode FactorNode;

typedef struct termnode{
    Node node;
    struct termnode* termnode;
    MulNode* mulnode;
    FactorNode* factornode;

} TermNode;

Node* newTermNode( int, int, TermNode*, MulNode*, FactorNode*, int, int );

void* TermNode_visit(void*);

#endif