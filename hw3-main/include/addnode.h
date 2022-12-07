#ifndef _ADDNODE_H_
#define _ADDNODE_H_

#include "ast.h"

typedef struct addnode{
    Node node;
    int positive;   // 1: positive, 0: negative
    
} AddNode;

Node* newAddNode( int, int, int, int, int );

void* AddNode_visit(void*);

#endif