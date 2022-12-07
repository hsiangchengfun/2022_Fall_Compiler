#include "argumentsnode.h"

Node* newArgumentsNode( int firstLine, int firstColumn, ParameterListNode* parameterlist, int lastLine, int lastColumn ){
    ArgumentsNode* temp = (ArgumentsNode*) malloc ( sizeof(ArgumentsNode) );
    temp->parameterlist = parameterlist;
    temp->node.type = _ArgumentsNode;
    temp->node.visit = ArgumentsNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* ArgumentsNode_visit(void* node){

    return 0;
}