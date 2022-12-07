
#include "standtypenode.h"

Node* newStandTypeNode( int firstLine, int firstColumn, int type, int lastLine, int lastColumn ){
    StandTypeNode* temp = (StandTypeNode*) malloc ( sizeof(StandTypeNode) );
    temp->type = type;  // 0: integer, 1: real, 2: string
    temp->node.type = _StandTypeNode;
    temp->node.visit = StandTypeNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* StandTypeNode_visit(void* node){

    return 0;
}
