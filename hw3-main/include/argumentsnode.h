#ifndef _ARGUMENTSNODE_H
#define _ARGUMENTSNODE_H

#include "ast.h"
#include "parameterlistnode.h"

typedef struct argumentsnode{
    Node node;
    ParameterListNode* parameterlist;

} ArgumentsNode;

Node* newArgumentsNode( int, int, ParameterListNode*, int, int );

void* ArgumentsNode_visit(void*);

#endif