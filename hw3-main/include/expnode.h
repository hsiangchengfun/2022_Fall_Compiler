#ifndef _EXPNODE_H
#define _EXPNODE_H

#include "ast.h"
#include "boolexpnode.h"

typedef struct boolexpnode BoolExpNode;

typedef struct expnode{
    Node node;
    int type;   // 0: bool, 1: bool AND bool, 2: bool OR bool
    BoolExpNode* first;
    BoolExpNode* least;
    
} ExpNode;

Node* newExpNode( int, int, ExpNode*, int, ExpNode*, int, int );

void* ExpNode_visit(void*);

#endif