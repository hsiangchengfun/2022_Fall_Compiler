#include "declarnode.h"
#include "list.h"
#include "info.h"

extern list* listRoot;
extern int scope;

Node* newDeclarNode( int firstLine, int firstColumn, DeclarNode* declarnode, IdentListNode* identlist, TypeNode* type, int lastLine, int lastColumn ){
    DeclarNode* temp = (DeclarNode*) malloc ( sizeof(DeclarNode) );
    temp->NextNode = declarnode;
    temp->identlistnode = identlist;
    temp->typenode = type;
    temp->node.type = _DeclarNode;
    temp->node.visit = DeclarNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
}

void* DeclarNode_visit(void* node){
    DeclarNode* temp = (DeclarNode*)node;

    // go to leftmost declarations
    if (temp->NextNode != NULL)
        temp->NextNode->node.visit(temp->NextNode);

    // add sym into symbol table
    IdentListNode* curr = temp->identlistnode;
    while(curr != NULL){
        if ( checkList(listRoot, curr->id, scope, Data) ){
            fprintf(stderr, REDEF_VAR, curr->node.loc.first_line, curr->node.loc.first_column, curr->id );
        }else{
            // add a symbol
            SHOW_NEWSYM(curr->id);

            returnType typeTemp;
            // check type
            if (temp->typenode->standtypenode != NULL){
                // standtypenode
                // 0: integer, 1: real, 2: string
                switch(temp->typenode->standtypenode->type){
                case 0:
                    typeTemp = Int;
                    break;

                case 1:
                    typeTemp = Real;
                    break;

                case 2:
                    typeTemp = String;
                    break;

                default:
                    break;
                }
                list_push_back( listRoot, newdatalist(curr->id, scope, typeTemp, Data) );
            }else{
                // ARRAY [ num .. num ] OF type

                list* listTemp = newarraylist(curr->id, scope, Array, Data);
                list_push_back( listRoot, listTemp);
                TypeNode* curr_type = temp->typenode;
                symbolobj* curr_array = listTemp->data;
                ((arraysymbolobj*)curr_array)->start = curr_type->array_start;
                ((arraysymbolobj*)curr_array)->end = curr_type->array_end;

                while(curr_type->type->type != NULL ){
                    ((arraysymbolobj*)curr_array)->data = (symbolobj*) malloc ( sizeof(arraysymbolobj) );
                    curr_array = ((arraysymbolobj*)curr_array)->data;
                    curr_type = curr_type->type;
                    ((arraysymbolobj*)curr_array)->start = curr_type->array_start;
                    ((arraysymbolobj*)curr_array)->end = curr_type->array_end;
                    ((arraysymbolobj*)curr_array)->type = Array;
                }
                curr_type = curr_type->type;
                ((arraysymbolobj*)curr_array)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                curr_array = ((arraysymbolobj*)curr_array)->data;
                
                // 0: integer, 1: real, 2: string
                switch (curr_type->standtypenode->type)
                {
                case 0:
                    /* code */
                    curr_array->type = Int;
                    break;

                case 1:
                    curr_array->type = Real;
                    break;

                case 2:
                    curr_array->type = String;
                    break;
                
                default:
                    break;
                }

            }
            
        }
        curr = curr->PrevNode;
    }

    return 0;
}
