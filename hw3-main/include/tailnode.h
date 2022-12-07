#ifndef _TAILNODE_H
#define _TAILNODE_H

#include "ast.h"
#include "expnode.h"
#include "tailnode.h"

typedef struct expnode ExpNode;

typedef struct tailnode{
    Node node;
    ExpNode* expnode;
    struct tailnode* tailnode;
    
} TailNode;

Node* newTailNode( int, int, ExpNode*, TailNode*, int, int );

void* TailNode_visit(void*);

#endif