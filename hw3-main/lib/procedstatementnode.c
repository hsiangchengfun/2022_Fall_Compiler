#include <stdio.h>

#include "procedstatementnode.h"
#include "list.h"

extern list* listRoot;
extern int scope;

int checkProcedArguments(ExpListNode* listNode, symbolobj** curr, int num){
    if (listNode->explistnode != 0){
        if (checkArguments(listNode->explistnode, curr, num+1))
            return 1;
    }

    if ( ((passinobj*)*curr)->data->type == (int)listNode->expnode->node.visit(listNode->expnode) ){
        if (((passinobj*)*curr) != 0)
            *curr = ((passinobj*)*curr)->next;
        else
            return 1;
        if ( (num == 0) && ( ((passinobj*)*curr) != 0) )
            return 1;

        return 0;
    }

    return 1;

}

Node* newProcedStatementNode( int firstLine, int firstColumn, char* id, ExpListNode* explistnode, int lastLine, int lastColumn ){
    ProcedStatementNode* temp = (ProcedStatementNode*) malloc ( sizeof(ProcedStatementNode) );
    temp->id = id;
    temp->explistnode = explistnode;
    temp->node.type = _ProcedStatementNode;
    temp->node.visit = ProcedStatementNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* ProcedStatementNode_visit(void* node){
    ProcedStatementNode* temp = (ProcedStatementNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", temp->node.loc.first_line, temp->node.loc.first_column);

    list* listTemp;
    if ( GetList( listRoot, &listTemp, temp->id ) ){
        // variable is declared

        // check arguments
        symbolobj* tempnode = ((funcsymbolobj*)listTemp->data)->passInType;
        if ( (tempnode != 0) && (temp->explistnode != 0) )
            if ( checkProcedArguments( temp->explistnode, &tempnode, 0 ) )
                fprintf(stderr, WRONG_ARGS, temp->node.loc.first_line, temp->node.loc.first_column, temp->id);
    }else{
        // undeclared variables
        fprintf(stderr, UNDEC_FUN, temp->node.loc.first_line, temp->node.loc.first_column, temp->id );
    }

    if (temp->explistnode != 0)
        temp->explistnode->node.visit(temp->explistnode);

    return -1;
}
