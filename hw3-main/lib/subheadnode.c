#include "subheadnode.h"
#include "list.h"

extern int scope;
extern list* listRoot;

Node* newSubHeadNode( int firstLine, int firstColumn, int type, char* id, StandTypeNode* standard_type, ArgumentsNode* arguments, int lastLine, int lastColumn ){
    SubHeadNode* temp = (SubHeadNode*) malloc ( sizeof(SubHeadNode) );
    temp->type = type;
    temp->id = id;
    temp->standard_type = standard_type;
    temp->arguments = arguments;
    temp->node.type = _SubHeadNode;
    temp->node.visit = SubHeadNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* SubHeadNode_visit(void* node){

    return 0;
}