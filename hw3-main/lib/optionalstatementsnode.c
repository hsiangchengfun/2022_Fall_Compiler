#include "optionalstatementsnode.h"

Node* newOptionalStatementSNode( int firstLine, int firstColumn, StatementListNode* statementlistnode, int lastLine, int lastColumn ){
    OptionalStatementSNode* temp = (OptionalStatementSNode*) malloc ( sizeof(OptionalStatementSNode) );
    temp->statementlistnode = statementlistnode;
    temp->node.type = _OptionalStatementSNode;
    temp->node.visit = OptionalStatementSNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}


void* OptionalStatementSNode_visit(void* node){
    OptionalStatementSNode* temp = (OptionalStatementSNode*) node;
    // printf("%d: %d OptionalStatementSNode\n", temp->node.loc.first_line, temp->node.loc.first_column);
    temp->statementlistnode->node.visit(temp->statementlistnode);

    return -1;
}

