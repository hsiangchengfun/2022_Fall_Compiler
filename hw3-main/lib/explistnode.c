#include "explistnode.h"

Node* newExpListNode( int firstLine, int firstColumn, ExpListNode* explistnode, ExpNode* expnode, int lastLine, int lastColumn ){
    ExpListNode* temp = (ExpListNode*) malloc ( sizeof(ExpListNode) );
    temp->explistnode = explistnode;
    temp->expnode = expnode;
    temp->node.type = _ExpListNode;
    temp->node.visit = ExpListNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* ExpListNode_visit(void* node){
    ExpListNode* temp = (ExpListNode*) node;

    if (temp->explistnode != 0)
        temp->explistnode->node.visit(temp->explistnode);

    if (temp->expnode != 0)
        temp->expnode->node.visit(temp->expnode);

    return -1;
}
