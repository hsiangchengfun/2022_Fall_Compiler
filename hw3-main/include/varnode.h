#ifndef _VARNODE_H
#define _VARNODE_H

#include "ast.h"
#include "tailnode.h"

typedef struct varnode{
    Node node;
    char* id;
    TailNode* tailnode; 
    
} VarNode;

Node* newVarNode( int, int, char*, TailNode*, int, int );

void* VarNode_visit(void*);

#endif