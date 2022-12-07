#include <stdio.h>

#include "expnode.h"

Node* newExpNode( int firstLine, int firstColumn, ExpNode* first, int op, ExpNode* least, int lastLine, int lastColumn ){
    ExpNode* temp = (ExpNode*) malloc ( sizeof(ExpNode) );
    temp->first = first;
    temp->least = least;
    temp->type = op;
    temp->node.type = _ExpNode;
    temp->node.visit = ExpNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* ExpNode_visit(void* node){
    ExpNode* temp = (ExpNode*) node;
    
    // debug
    // fprintf(stderr, "%d: %d has an ExpNode\n", temp->node.loc.first_line, temp->node.loc.first_column);

    switch (temp->type)
    {
    case 0: 
        return temp->first->node.visit(temp->first);
        break;

    case 1:
        temp->first->node.visit(temp->first);
        // do something here
        temp->least->node.visit(temp->least);
        break;

    case 2:
        temp->first->node.visit(temp->first);
        // do something here
        temp->least->node.visit(temp->least);
        break;
    
    default:
        break;
    }

    return -1;
}
