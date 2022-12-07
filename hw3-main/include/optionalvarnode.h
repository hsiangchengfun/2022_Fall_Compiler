#ifndef _OPTIONALVARNODE_H
#define _OPTIONALVARNODE_H

#include "ast.h"

typedef struct optionalvarnode{
    Node node;
    
} OptionalVarNode;

void* OptionalVarNode_visit(void*);

Node* newOptionalVarNode( int, int );

#endif