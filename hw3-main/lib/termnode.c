#include <stdio.h>

#include "termnode.h"
#include "list.h"

Node* newTermNode( int firstLine, int firstColumn, TermNode* termnode, MulNode* mulnode, FactorNode* factornode, int lastLine, int lastColumn ){
    TermNode* temp = (TermNode*) malloc ( sizeof(TermNode) );
    temp->termnode = termnode;
    temp->mulnode = mulnode;
    temp->factornode = factornode;
    temp->node.type = _TermNode;
    temp->node.visit = TermNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* TermNode_visit(void* node){
    TermNode* temp = (TermNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", temp->node.loc.first_line, temp->node.loc.first_column);

    int* temp1, *temp2;
    int datatype = -1;

    if (temp->mulnode != 0){
        temp1 = temp->termnode->node.visit(temp->termnode);
        temp->mulnode->node.visit(temp->mulnode);
        temp2 = temp->factornode->node.visit(temp->factornode);

        if ( ((int)temp1 >= 0) && ((int)temp2 >= 0) && ((int)temp1 != temp2) ){
            if (temp->mulnode->type)
                fprintf(stderr, ARITH_TYPE, temp->mulnode->node.loc.first_line, temp->mulnode->node.loc.first_column, "/");
            else
                fprintf(stderr, ARITH_TYPE, temp->mulnode->node.loc.first_line, temp->mulnode->node.loc.first_column, "*");
            
        }
        if ( ((int)temp1 >= 0) && ((int)temp2 >= 0) && ((int)temp1 == temp2) ){
            datatype = (int)temp1;
            return datatype;
        }
        
    }else{
        return temp->factornode->node.visit(temp->factornode);
    }

    return datatype;
}
