#include "parameterlistnode.h"

Node* newParameterListNode( int firstLine, int firsColumn, OptionalVarNode* optionalvarnode, IdentListNode* identlistnode, TypeNode* typenode, ParameterListNode* parameterlistnode, int lastLine, int lastColumn ){
    ParameterListNode* temp = (ParameterListNode*) malloc ( sizeof(ParameterListNode) );
    temp->optionalvarnode = optionalvarnode;
    temp->identlistnode = identlistnode;
    temp->typenode = typenode;
    temp->NextNode = parameterlistnode;
    temp->node.type = _ParameterListNode;
    temp->node.visit = ParameterListNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firsColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* ParameterListNode_visit(void* node){

    return 0;
}