#include <stdio.h>

#include "statementnode.h"
#include "list.h"

extern list* listRoot;
extern int scope;

Node* newStatementNode( int firstLine, int firstColumn, int type, VarNode* varnode, ExpNode* expnode, ProcedStatementNode* procedstatementnode, CompoundStatementNode* compoundstatementnode, StatementNode* statementnode1, StatementNode* statementnode2, int lastLine, int lastColumn ){
    StatementNode* temp = (StatementNode*) malloc ( sizeof(StatementNode) );
    temp->type = type;
    temp->varnode = varnode;
    temp->expnode = expnode;
    temp->procedstatementnode = procedstatementnode;
    temp->compoundstatementnode = compoundstatementnode;
    temp->statementnode1 = statementnode1;
    temp->statementnode2 = statementnode2;
    temp->node.type = _StatementNode;
    temp->node.visit = StatementNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* StatementNode_visit(void* node){
    StatementNode* temp = (StatementNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", temp->node.loc.first_line, temp->node.loc.first_column);

    // store the node from symbol table
    list* listTemp;
    // counter for counting elements
    int counter;
    // store data type
    int* temp1, *temp2;

    switch (temp->type)
    {
    case 0:
    // variable ASSIGNMENT expression

        // visit variable
        temp1 = (int*) temp->varnode->node.visit(temp->varnode);

        // visit expression
        temp2 = (int*) temp->expnode->node.visit(temp->expnode);

        // debug
        // fprintf(stderr, "Data Type: %d\n", temp1);
        // fprintf(stderr, "Data Type: %d\n", temp2);

        if ( ((int)temp1 >= 0) && ((int)temp2 >= 0) && ((int)temp1 != temp2) )
            fprintf(stderr, ASSIG_TYPE, temp->varnode->node.loc.first_line, temp->varnode->node.loc.first_column);
        else if ( GetList(listRoot, &listTemp, temp->varnode->id) ){
            if (listTemp->nodeType == Function){
                if ( ((funcsymbolobj*)listTemp->data)->check > 1 ){
                    ((funcsymbolobj*)listTemp->data)->check--;
                    fprintf(stderr, ASSIG_TYPE, temp->varnode->node.loc.first_line, temp->varnode->node.loc.first_column);
                }
            }
        }

        break;

    case 1:
    // procdure_statement
        
        temp->procedstatementnode->node.visit(temp->procedstatementnode);
        break;
    
    case 2:
    // compound_statement
        
        temp->compoundstatementnode->node.visit(temp->compoundstatementnode);
        break;

    case 3:
    // IF expression THEN statement ELSE statement
        
        if (temp->expnode != 0)
            temp->expnode->node.visit(temp->expnode);

        if (temp->statementnode1 != 0)
            temp->statementnode1->node.visit(temp->statementnode1);

        if (temp->statementnode2 != 0)
            temp->statementnode2->node.visit(temp->statementnode2);

        break;

    case 4:
    // WHILE expression DO statement
        
        if (temp->expnode != 0)
            temp->expnode->node.visit(temp->expnode);

        if (temp->statementnode1 != 0)
            temp->statementnode1->node.visit(temp->statementnode1);

        break;
    
    default:
        break;
    }

    return 0;
}
