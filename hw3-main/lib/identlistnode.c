#include <stdlib.h>

#include "identlistnode.h"


Node* newIdentListNode( int firstLine, int firstColumn, char* id, IdentListNode* identlistnode, int lastLine, int lastColumn ){
    IdentListNode* temp = (IdentListNode*) malloc ( sizeof(IdentListNode) );
    temp->id = id;
    temp->PrevNode = identlistnode;
    temp->node.type = _IdentListNode;
    temp->node.visit = IdentListNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}


void* IdentListNode_visit(void* node){

    return 0;
}
