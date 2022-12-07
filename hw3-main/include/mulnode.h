#ifndef _MULNODE_H
#define _MULNODE_H

#include "ast.h"

typedef struct MulNode{
    Node node;
    int type;   // 0: *, 1: /
    
} MulNode;

Node* newMulNode( int, int, int, int, int );

void* MulNode_visit(void*);

#endif