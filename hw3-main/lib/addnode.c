#include "addnode.h"

Node* newAddNode( int firstLine, int firstColumn, int positive, int lastLine, int lastColumn ){
    AddNode* temp = (AddNode*) malloc ( sizeof(AddNode) );
    temp->positive = positive;
    temp->node.type = _AddNode;
    temp->node.visit = AddNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* AddNode_visit(void* node){

    return 0;
}
