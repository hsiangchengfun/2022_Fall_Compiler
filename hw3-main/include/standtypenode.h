#ifndef _STANDTYPENODE_H
#define _STANDTYPENODE_H

#include "ast.h"

typedef struct standtypenode{
    Node node;
    int type; // 0: integer, 1: real, 2: string
} StandTypeNode;

void* StandTypeNode_visit(void*);

Node* newStandTypeNode( int, int, int, int, int );



#endif