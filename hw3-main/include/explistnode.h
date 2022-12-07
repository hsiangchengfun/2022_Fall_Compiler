#ifndef _EXPLISTNODE_H
#define _EXPLISTNODE_H

#include "ast.h"
#include "expnode.h"

typedef struct expnode ExpNode;

typedef struct explistnode{
    Node node;
    struct explistnode* explistnode;
    ExpNode* expnode;

} ExpListNode;

Node* newExpListNode( int, int, ExpListNode*, ExpNode*, int, int );

void* ExpListNode_visit(void*);

#endif