#include <stdio.h>

#include "tailnode.h"
#include "info.h"

Node* newTailNode( int firstLine, int firstColumn, ExpNode* expnode, TailNode* tailnode, int lastLine, int lastColumn ){
    TailNode* temp = (TailNode*) malloc ( sizeof(TailNode) );
    temp->expnode = expnode;
    temp->tailnode = tailnode;
    temp->node.type = _TailNode;
    temp->node.visit = TailNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* TailNode_visit(void* node){
    TailNode* temp = (TailNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", temp->node.loc.first_line, temp->node.loc.first_column);
    int datatype = -1;

    if (temp->expnode != 0){
        int temp2 = temp->expnode->node.visit(temp->expnode);
        if ( (temp2 != -1) && (temp2 != 0)  )
            datatype = 1;
    }
    if (datatype == 1)
        fprintf(stderr, INDEX_TYPE, temp->expnode->node.loc.first_line, temp->expnode->node.loc.first_column);


    if (temp->tailnode != 0){
        int temp2 = temp->tailnode->node.visit(temp->tailnode);
        if ( (temp2 != -1) && (temp2 != 0)  )
            datatype = 1;
    }
    
    return datatype;
}
