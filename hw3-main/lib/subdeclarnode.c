#include <stdlib.h>
#include <string.h>

#include "subdeclarnode.h"
#include "list.h"

extern list* listRoot;
extern int scope;

int checkExist(StatementNode* curr, char* id){
    if (curr != NULL){
        if ( (curr->type == 0) ){
            if ( !strcmp(id, curr->varnode->id) ){
                return 1;
            }
        }else{
            if (curr->statementnode1 != 0){
                if (checkExist(curr->statementnode1, id))
                    return 1;
            }
            if (curr->statementnode2 != 0){
                if (checkExist(curr->statementnode2, id))
                    return 1;
            }
        }
    }

    return 0;
}

Node* newSubDeclarNode( int firstLine, int firstColumn, SubHeadNode* subheadnode, DeclarNode* declarnode, SubDeclarSNode* subdeclarsnode, CompoundStatementNode* compoundstatementnode, int lastLine, int lastColumn ){
    SubDeclarNode* temp = (SubDeclarNode*) malloc ( sizeof(SubDeclarNode) );
    temp->head = subheadnode;
    temp->declarnode = declarnode;
    temp->subdeclarsnode = subdeclarsnode;
    temp->compoundstatementnode = compoundstatementnode;
    temp->node.type = _SubDeclarNode;
    temp->node.visit = SubDeclarNode_visit;
    temp->node.loc.first_line = firstLine;
    temp->node.loc.first_column = firstColumn;
    temp->node.loc.last_line = lastLine;
    temp->node.loc.last_column = lastColumn;

    return temp;
};

void* SubDeclarNode_visit(void* node){
    SubDeclarNode* temp = (SubDeclarNode*) node;

    if (temp->head != NULL){
        
        list* tempList;
        int check = 0;
        if (temp->head->type){
            // PROCEDURE
            
            tempList = newfunclist( temp->head->id, scope, Void, Function );
            if ( checkList(listRoot, temp->head->id, scope, Function) ){
                fprintf(stderr, REDEF_FUN, temp->node.loc.first_line, temp->node.loc.first_column+1, temp->head->id);

            }else{
                SHOW_NEWSYM(temp->head->id);
                list_push_back( listRoot, tempList );
            }

        }else{
            
            // FUNCTION
            switch (temp->head->standard_type->type)
            {
            case 0:
                /* code */
                tempList = newfunclist( temp->head->id, scope, Int, Function );
                break;

            case 1:
                tempList = newfunclist( temp->head->id, scope, Real, Function );
                break;

            case 2:
                tempList = newfunclist( temp->head->id, scope, String, Function );
                break;
            
            default:
                break;
            }

            StatementListNode* checkReturnType = NULL;
            if ( temp->compoundstatementnode->statements != NULL )
                checkReturnType = temp->compoundstatementnode->statements->statementlistnode;
            while(checkReturnType != NULL){

                check = checkExist(checkReturnType->statementnode, temp->head->id);
                if (check)
                    break;

                checkReturnType = checkReturnType->nextList;
            }
            
            if ( checkList(listRoot, temp->head->id, scope, Function) ){
                list* listTemp;
                GetList(listRoot, &listTemp, temp->head->id);
                ((funcsymbolobj*)listTemp->data)->check = 2;
                fprintf(stderr, REDEF_FUN, temp->node.loc.first_line, temp->node.loc.first_column, temp->head->id);
                fprintf(stderr, RETURN_VAL, temp->node.loc.first_line, temp->node.loc.first_column, temp->head->id);
                // if (check){
                //     fprintf(stderr, ASSIG_TYPE, checkReturnType->statementnode->node.loc.first_line, checkReturnType->statementnode->node.loc.first_column);
                // }
            }else{
                SHOW_NEWSYM(temp->head->id);
                list_push_back( listRoot, tempList );
                if (!check)
                fprintf(stderr, RETURN_VAL, temp->node.loc.first_line, temp->node.loc.first_column, temp->head->id);
            }

        }
        
        // create a scope
        SHOW_NEWSCP();
        scope++;

        // pass in data type
        ParameterListNode* curr = NULL;
        passinobj* passinobjTemp = NULL;


        if (temp->head->arguments != NULL)
            curr = temp->head->arguments->parameterlist;

        if (curr != 0){
            // initialize the funcList

            ((funcsymbolobj*)tempList->data)->passInType = (symbolobj*) malloc ( sizeof(passinobj) );
            // add pass in data type
            returnType typeTemp;
            if (curr->typenode->standtypenode != NULL){
                // standtype
                switch(curr->typenode->standtypenode->type){
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

                IdentListNode* idList = curr->identlistnode;
                ((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                ((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data->type = typeTemp;
                passinobjTemp = ((funcsymbolobj*)tempList->data)->passInType;
                if ( checkList(listRoot, idList->id, scope, Data) ){
                    fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                }else{
                    SHOW_NEWSYM(idList->id);
                    list_push_back( listRoot, newdatalist(idList->id, scope, typeTemp, Data) );
                }
                passinobjTemp->next = NULL;
                while( idList->PrevNode != NULL ){
                    passinobjTemp->next = (passinobj*) malloc ( sizeof(passinobj) );
                    ((passinobj*)passinobjTemp->next)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                    idList = idList->PrevNode;
                    passinobjTemp = (passinobj*)(passinobjTemp->next);
                    passinobjTemp->data->type = typeTemp;
                    if ( checkList(listRoot, idList->id, scope, Data) ){
                        fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                    }else{
                        SHOW_NEWSYM(idList->id);
                        list_push_back( listRoot, newdatalist(idList->id, scope, typeTemp, Data) );
                    }
                }

            }else{
                // array
                
                IdentListNode* idList = curr->identlistnode;

                ((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data = (symbolobj*) malloc ( sizeof(arraysymbolobj) );
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data)->type = Array;
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data)->start = curr->typenode->array_start;
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tempList->data)->passInType)->data)->end = curr->typenode->array_end;

                passinobjTemp = ((funcsymbolobj*)tempList->data)->passInType;
                TypeNode* currType = curr->typenode;
                symbolobj* currArray = passinobjTemp->data;

                while(currType->type->type != NULL){
                    ((arraysymbolobj*)currArray)->data = (symbolobj*) malloc ( sizeof(arraysymbolobj) );
                    currArray = ((arraysymbolobj*)currArray)->data;
                    currType = currType->type;
                    ((arraysymbolobj*)currArray)->start = currType->array_start;
                    ((arraysymbolobj*)currArray)->end = currType->array_end;
                    ((arraysymbolobj*)currArray)->type = Array;
                }
                currType = currType->type;
                ((arraysymbolobj*)currArray)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                currArray = ((arraysymbolobj*)currArray)->data;
                
                // 0: integer, 1: real, 2: string
                switch (currType->standtypenode->type)
                {
                case 0:
                    /* code */
                    currArray->type = Int;
                    break;

                case 1:
                    currArray->type = Real;
                    break;

                case 2:
                    currArray->type = String;
                    break;
                
                default:
                    break;
                }
                
                passinobjTemp->next = NULL;
                list* listTemp;
                if ( checkList(listRoot, idList->id, scope, Data) ){
                    fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                }else{
                    SHOW_NEWSYM(idList->id);
                    listTemp = newarraylist(idList->id, scope, Array, Data);
                    list_push_back( listRoot, listTemp);
                    TypeNode* curr_type = curr->typenode;
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

                while(idList->PrevNode != NULL){
                    
                    if ( checkList(listRoot, idList->id, scope, Data) ){
                        fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                    }else{
                        SHOW_NEWSYM(idList->id);
                        listTemp = newarraylist(idList->id, scope, Array, Data);
                        list_push_back( listRoot, listTemp);
                        TypeNode* curr_type = curr->typenode;
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

                    idList = idList->PrevNode;
                    passinobj* passinobjTemp = ((funcsymbolobj*)tempList->data)->passInType;
                    TypeNode* currType = curr->typenode;
                    symbolobj* currArray = passinobjTemp->data;
                    ((arraysymbolobj*)currArray)->start = currType->array_start;
                    ((arraysymbolobj*)currArray)->end = currType->array_end;
                    ((arraysymbolobj*)currArray)->type = Array;

                    while(currType->type->type != NULL){
                        ((arraysymbolobj*)currArray)->data = (symbolobj*) malloc ( sizeof(arraysymbolobj) );
                        currArray = ((arraysymbolobj*)currArray)->data;
                        currType = currType->type;
                        ((arraysymbolobj*)currArray)->start = currType->array_start;
                        ((arraysymbolobj*)currArray)->end = currType->array_end;
                        ((arraysymbolobj*)currArray)->type = Array;
                    }
                    currType = currType->type;
                    ((arraysymbolobj*)currArray)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                    currArray = ((arraysymbolobj*)currArray)->data;
                    
                    // 0: integer, 1: real, 2: string
                    switch (currType->standtypenode->type)
                    {
                    case 0:
                        /* code */
                        currArray->type = Int;
                        break;

                    case 1:
                        currArray->type = Real;
                        break;

                    case 2:
                        currArray->type = String;
                        break;
                    
                    default:
                        break;
                    }
                    
                }

            }

            // continue passing argument
            while(curr->NextNode != NULL){
                curr = curr->NextNode;
                // parameterList

                // add pass in data type
                returnType typeTemp;
                if (curr->typenode->standtypenode != NULL){
                    // standtype
                    switch(curr->typenode->standtypenode->type){
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

                    IdentListNode* idList = curr->identlistnode;
                    passinobjTemp->next = NULL;
                    while( idList != NULL ){
                        passinobjTemp->next = (symbolobj*) malloc ( sizeof(passinobj) );
                        ((passinobj*)passinobjTemp->next)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                        ((passinobj*)passinobjTemp->next)->data->type = typeTemp;
                        if ( checkList(listRoot, idList->id, scope, Data) ){
                            fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                        }else{
                            SHOW_NEWSYM(idList->id);
                            list_push_back( listRoot, newdatalist(idList->id, scope, typeTemp, Data) );
                        }
                        idList = idList->PrevNode;
                        passinobjTemp = (passinobj*)(passinobjTemp->next);
                    }

                }
                else{
                    // array
                    
                    // do something

                }

            }

        }
        
    }
    
    if (temp->declarnode != NULL){
        temp->declarnode->node.visit(temp->declarnode);
    }

    if (temp->subdeclarsnode != NULL){
        temp->subdeclarsnode->node.visit(temp->subdeclarsnode);
    }

    if (temp->compoundstatementnode != NULL){
        temp->compoundstatementnode->node.visit(temp->compoundstatementnode);
    }

    list* listTemp;
    if ( GetList(listRoot, &listTemp, temp->head->id) )
        ((funcsymbolobj*)listTemp->data)->check = 1;

    SHOW_CLSSCP();
    SHOW_SYMTAB_HEAD();
    // print table
    list_printTable(listRoot);
    SHOW_SYMTAB_TAIL();
    scope--;
    listRemove(listRoot, scope);
    
    return 0;
}