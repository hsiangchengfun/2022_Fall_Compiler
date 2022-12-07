#include "typenode.h"

void* TypeNode_visit(void* node){

    return 0;
}

Node* newTypeNode( int firstLine, int firstColumn, StandTypeNode* standtypenode, int array_start, int array_end, TypeNode* type, int lastLine, int lastColumn ){
    TypeNode* temp = (TypeNode*) malloc ( sizeof(TypeNode) );
    temp->standtypenode = standtypenode;
    temp->array_start = array_start;
    temp->array_end = array_end;
    temp->type = type;
    temp->node.type = _TypeNode;
    temp->node.visit = TypeNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.last_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}