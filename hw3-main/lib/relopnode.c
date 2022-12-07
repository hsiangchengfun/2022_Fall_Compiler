#include "relopnode.h"

Node* newRelopNode( int firstLine, int firstColumn, int type, int lastLine, int lastColumn ){
    RelopNode* temp = (RelopNode*) malloc ( sizeof(RelopNode) );
    temp->type = type;
    temp->node.type = _RelopNode;
    temp->node.visit = RelopNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* RelopNode_visit(void* node){
    RelopNode* temp = (RelopNode*) node;

    return temp->type;
}
