#ifndef _SUBDECLARNODE_H
#define _SUBDECLARNODE_H

#include "ast.h"
#include "subheadnode.h"
#include "declarnode.h"
#include "compoundstatementnode.h"

struct subdeclarnode;

typedef struct subdeclarsnode{
    Node node;
    struct subdeclarsnode* PrevNode;
    struct subdeclarnode* NextNode;

} SubDeclarSNode;

typedef struct subdeclarnode{
    Node node;
    SubHeadNode* head;
    DeclarNode* declarnode;
    SubDeclarSNode* subdeclarsnode;
    CompoundStatementNode* compoundstatementnode;

} SubDeclarNode;

Node* newSubDeclarNode( int, int, SubHeadNode*, DeclarNode*, SubDeclarSNode*, CompoundStatementNode*, int, int );

void* SubDeclarNode_visit(void*);

void* SubDeclarSNode_visit(void*);

Node* newSubDeclarSNode( int, int, SubDeclarSNode*, SubDeclarNode*, int, int );

int checkExist( StatementNode*, char* );

#endif
