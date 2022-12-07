#include <stdio.h>

#include "boolexpnode.h"
#include "info.h"

Node* newBoolExpNode( int firstLine, int firstColumn, SimpleExpNode* first, RelopNode* relop, SimpleExpNode* least, int lastLine, int lastColumn ){
    BoolExpNode* temp = (BoolExpNode*) malloc ( sizeof(BoolExpNode) );
    temp->first = first;
    temp->relop = relop;
    temp->least = least;
    temp->node.type = _BoolExpNode;
    temp->node.visit = BoolExpNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* BoolExpNode_visit(void* node){
    BoolExpNode* temp = (BoolExpNode*) node;
    
    int* temp1, temp2;
    int datatype = -1;

    if (temp->relop != 0){
        temp1 = (int*) temp->first->node.visit(temp->first);
        temp->relop->node.visit(temp->relop);
        temp2 = (int*) temp->least->node.visit(temp->least);

        if ( ((int)temp1 >= 0) && ((int)temp2 >= 0) && ((int)temp1 != temp2) ){
            switch (temp->relop->type){
                case 0:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, "<");
                    break;

                case 1:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, ">");
                    break;

                case 2:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, "=");
                    break;

                case 3:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, ">=");
                    break;

                case 4:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, "<=");
                    break;

                case 5:
                    fprintf(stderr, ARITH_TYPE, temp->relop->node.loc.first_line, temp->relop->node.loc.first_column, "!=");
                    break;

                default:
                break;
            }
            
        }
        if ( ((int)temp1 >= 0) && ((int)temp2 >= 0) && ((int)temp1 == temp2) ){
            datatype = (int)temp1;
            return datatype;
        }

    }else{
        return temp->first->node.visit(temp->first);
    }   

    return -1;
}
