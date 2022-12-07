#include <stdlib.h>
#include <stdio.h>

#include "info.h"
#include "prognode.h"
#include "list.h"

list* listRoot;
extern int scope;

Node* newProgNode( int firstLine, int firstColumn, char* id, IdentListNode* identlist, DeclarNode* declar, SubDeclarSNode* subdeclars, CompoundStatementNode* compoundstatement, int lastLine, int lastColumn ){
    // initialize my ProgNode
    ProgNode* temp = (ProgNode*) malloc ( sizeof(ProgNode) );
    temp->id = id;
    temp->identlist = identlist;
    temp->declar = declar;
    temp->subdeclar = subdeclars;
    temp->compoundstatement = compoundstatement;
    temp->node.type = _ProgNode;
    temp->node.visit = ProgNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
};

void* ProgNode_visit(void* node){
    // I don't know what to do
    ProgNode* temp = (ProgNode*)node;

    // create a scope
    SHOW_NEWSCP();

    // add sym into symbol table
    SHOW_NEWSYM(temp->id);
    listRoot = newdatalist(temp->id, scope, Void, Data);

    // Visit inside
    if (temp->identlist != NULL)
        temp->identlist->node.visit(temp->identlist);
    if (temp->declar != NULL)
        temp->declar->node.visit(temp->declar);
    if (temp->subdeclar != NULL)
        temp->subdeclar->node.visit(temp->subdeclar);
    if (temp->compoundstatement != NULL)
        temp->compoundstatement->node.visit(temp->compoundstatement);

    SHOW_CLSSCP();
    SHOW_SYMTAB_HEAD();
    // print table
    list_printTable(listRoot);
    SHOW_SYMTAB_TAIL();

    return 0;
}
