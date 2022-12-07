#ifndef _FACTORNODE_H
#define _FACTORNODE_H

#include "ast.h"
#include "tailnode.h"
#include "explistnode.h"
#include "expnode.h"
#include "numnode.h"

typedef struct tailnode TailNode;
typedef struct explistnode ExpListNode;
typedef struct expnode ExpNode;

typedef struct factornode{
    Node node;
    int type;
    char* id;
    TailNode* tailnode;
    ExpListNode* explistnode;
    NumNode* num;
    ExpNode* expnode;
    struct factornode* factornode;
    
} FactorNode;

Node* newFactorNode( int, int, int, char*, TailNode*, ExpListNode*, NumNode*, ExpNode*, FactorNode*, int, int );

void* FactorNode_visit(void*);

#endif