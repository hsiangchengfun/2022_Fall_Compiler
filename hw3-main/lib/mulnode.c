#include "mulnode.h"
#include "stdlib.h"
Node* newMulNode( int firstLine, int firstColumn, int type, int lastLine, int lastColumn ){
    MulNode* temp = (MulNode*) malloc ( sizeof(MulNode) );
    temp->type = type;
    temp->node.type = _MulNode;
    temp->node.visit = MulNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* MulNode_visit(void* node){

    return 0;
}
