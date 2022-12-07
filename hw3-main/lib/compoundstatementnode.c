#include "compoundstatementnode.h"
#include "list.h"

extern list* listRoot;
extern int scope;

Node* newCompoundStatementNode( int firstLine, int firstColumn, OptionalStatementSNode* optionalstatementsnode, int lastLine, int lastColumn ){
    CompoundStatementNode* temp = (CompoundStatementNode*) malloc ( sizeof(CompoundStatementNode) );
    temp->statements = optionalstatementsnode;
    temp->node.type = _CompoundStatementNode;
    temp->node.visit = CompoundStatementNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* CompoundStatementNode_visit(void* node){
    CompoundStatementNode* temp = (CompoundStatementNode*) node;
    // printf("%d: %d CompoundStatementNode\n", temp->node.loc.first_line, temp->node.loc.first_column);
    if (temp->statements != NULL)
        temp->statements->node.visit(temp->statements);

    return 0;
}