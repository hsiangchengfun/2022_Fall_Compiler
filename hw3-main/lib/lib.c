#include "ast.h"
#include "stdbool.h"
#include "stdlib.h"
#include "lib.h"
#include "info.h"
#include "stdio.h"
#include "list.h"



Node* newAddOpNode( int fl, int fc, bool add, int ll, int lc ){
    AddOpNode* tmpnode = (AddOpNode*) malloc ( sizeof(AddOpNode) );
    tmpnode->add = add;
    tmpnode->node.type = NODE_AddOp;
    tmpnode->node.visit = AddOpNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* AddOpNode_visit(void* node){

    return 0;
}




Node* newArgumentsNode( int fl, int fc, ParameterListNode* parameterlist, int ll, int lc ){
    ArgumentsNode* tmpnode = (ArgumentsNode*) malloc ( sizeof(ArgumentsNode) );
    tmpnode->parameterlist = parameterlist;
    tmpnode->node.type = NODE_Arguments;
    tmpnode->node.visit = ArgumentsNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* ArgumentsNode_visit(void* node){

    return 0;
}



Node* newBoolExpNode( int fl, int fc, SimpleExpressionNode* first, RelopNode* relop, SimpleExpressionNode* least, int ll, int lc ){
    BoolExpNode* tmpnode = (BoolExpNode*) malloc ( sizeof(BoolExpNode) );
    tmpnode->first = first;
    tmpnode->relop = relop;
    tmpnode->least = least;
    tmpnode->node.type = NODE_BoolExp;
    tmpnode->node.visit = BoolExpNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* BoolExpNode_visit(void* node){
    BoolExpNode* tmpnode = (BoolExpNode*) node;
    
    int* tmpnode1, tmpnode2;
    int datatype = -1;

    if (tmpnode->relop != 0){
        tmpnode1 = (int*) tmpnode->first->node.visit(tmpnode->first);
        tmpnode->relop->node.visit(tmpnode->relop);
        tmpnode2 = (int*) tmpnode->least->node.visit(tmpnode->least);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            switch (tmpnode->relop->type){
                case 0:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, "<");
                    break;

                case 1:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, ">");
                    break;

                case 2:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, "=");
                    break;

                case 3:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, ">=");
                    break;

                case 4:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, "<=");
                    break;

                case 5:
                    fprintf(stderr, ARITH_TYPE, tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column, "!=");
                    break;

                default:
                break;
            }
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            return datatype;
        }

    }else{
        return tmpnode->first->node.visit(tmpnode->first);
    }   

    return -1;
}


//compound


extern list* listRoot;
extern int scope;

Node* newCompoundStatementNode( int fl, int fc, OptionalStatementSNode* optionalstatementsnode, int ll, int lc ){
    CompoundStatementNode* tmpnode = (CompoundStatementNode*) malloc ( sizeof(CompoundStatementNode) );
    tmpnode->statements = optionalstatementsnode;
    tmpnode->node.type = NODE_CompoundStatement;
    tmpnode->node.visit = CompoundStatementNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* CompoundStatementNode_visit(void* node){
    CompoundStatementNode* tmpnode = (CompoundStatementNode*) node;
    // printf("%d: %d CompoundStatementNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    if (tmpnode->statements != NULL)
        tmpnode->statements->node.visit(tmpnode->statements);

    return 0;
}


extern list* listRoot;
extern int scope;

Node* newDeclarNode( int fl, int fc, DeclarNode* declarnode, IdentListNode* identlist, TypeNode* type, int ll, int lc ){
    DeclarNode* tmpnode = (DeclarNode*) malloc ( sizeof(DeclarNode) );
    tmpnode->NextNode = declarnode;
    tmpnode->identlistnode = identlist;
    tmpnode->typenode = type;
    tmpnode->node.type = NODE_Declaration;
    tmpnode->node.visit = DeclarNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* DeclarNode_visit(void* node){
    DeclarNode* tmpnode = (DeclarNode*)node;

    // go to leftmost declarations
    if (tmpnode->NextNode != NULL)
        tmpnode->NextNode->node.visit(tmpnode->NextNode);

    // add sym into symbol table
    IdentListNode* curr = tmpnode->identlistnode;
    while(curr != NULL){
        if ( checkList(listRoot, curr->id, scope, Data) ){
            fprintf(stderr, REDEF_VAR, curr->node.loc.first_line, curr->node.loc.first_column, curr->id );
        }else{
            // add a symbol
            SHOW_NEWSYM(curr->id);

            returnType typetmpnode;
            // check type
            if (tmpnode->typenode->standtypenode != NULL){
                // standtypenode
                // 0: integer, 1: real, 2: string
                switch(tmpnode->typenode->standtypenode->type){
                case 0:
                    typetmpnode = Int;
                    break;

                case 1:
                    typetmpnode = Real;
                    break;

                case 2:
                    typetmpnode = String;
                    break;

                default:
                    break;
                }
                list_push_back( listRoot, newdatalist(curr->id, scope, typetmpnode, Data) );
            }else{
                // ARRAY [ num .. num ] OF type

                list* listtmpnode = newarraylist(curr->id, scope, Array, Data);
                list_push_back( listRoot, listtmpnode);
                TypeNode* curr_type = tmpnode->typenode;
                symbolobj* curr_array = listtmpnode->data;
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


//exp


Node* newExpNode( int fl, int fc, ExpressionNode* first, int op, ExpressionNode* least, int ll, int lc ){
    ExpressionNode* tmpnode = (ExpressionNode*) malloc ( sizeof(ExpressionNode) );
    tmpnode->first = first;
    tmpnode->least = least;
    tmpnode->type = op;
    tmpnode->node.type = NODE_Exp;
    tmpnode->node.visit = ExpNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* ExpNode_visit(void* node){
    ExpressionNode* tmpnode = (ExpressionNode*) node;
    
    // debug
    // fprintf(stderr, "%d: %d has an ExpressionNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);

    switch (tmpnode->type)
    {
    case 0: 
        return tmpnode->first->node.visit(tmpnode->first);
        break;

    case 1:
        tmpnode->first->node.visit(tmpnode->first);
        // do something here
        tmpnode->least->node.visit(tmpnode->least);
        break;

    case 2:
        tmpnode->first->node.visit(tmpnode->first);
        // do something here
        tmpnode->least->node.visit(tmpnode->least);
        break;
    
    default:
        break;
    }

    return -1;
}

//exp liost
Node* newExpressionListNode( int fl, int fc, ExpressionListNode* expressionlistnode, ExpressionNode* expressionnode, int ll, int lc ){
    ExpressionListNode* tmpnode = (ExpressionListNode*) malloc ( sizeof(ExpressionListNode) );
    tmpnode->expressionlistnode = expressionlistnode;
    tmpnode->expressionnode = expressionnode;
    tmpnode->node.type = NODE_Exp;
    tmpnode->node.visit = ExpressionListNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* ExpressionListNode_visit(void* node){
    ExpressionListNode* tmpnode = (ExpressionListNode*) node;

    if (tmpnode->expressionlistnode != 0)
        tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);

    if (tmpnode->expressionnode != 0)
        tmpnode->expressionnode->node.visit(tmpnode->expressionnode);

    return -1;
}


// factor

extern list* listRoot;
extern int scope;

int checkArguments(ExpressionListNode* listNode, symbolobj** curr, int num){
    if (listNode->expressionlistnode != 0){
        if (checkArguments(listNode->expressionlistnode, curr, num+1))
            return 1;
    }

    if ( ((passinobj*)*curr)->data->type == (int)listNode->expressionnode->node.visit(listNode->expressionnode) ){
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

Node* newFactorNode( int fl, int fc, int type, char* id, TailNode* tailnode, ExpressionListNode* expressionlistnode, NumNode* numnode, ExpressionNode* expressionnode, FactorNode* factornode, int ll, int lc ){
    FactorNode* tmpnode = (FactorNode*) malloc ( sizeof(FactorNode) );
    tmpnode->type = type;
    tmpnode->id = id;
    tmpnode->tailnode = tailnode;
    tmpnode->expressionlistnode = expressionlistnode;
    tmpnode->num = numnode;
    tmpnode->expressionnode = expressionnode;
    tmpnode->factornode = factornode;
    tmpnode->node.type = NODE_Factor;
    tmpnode->node.visit = FactorNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* FactorNode_visit(void* node){
    FactorNode* tmpnode = (FactorNode*)node;

    // debug
    // fprintf(stderr, "%d: %d has an FactorNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    
    int datatype = -1;
    list* listtmpnode = NULL;
    symbolobj* currtmpnode = NULL;

    switch (tmpnode->type)
    {
    case 0:
        // IDENTIFIER tail
        if ( GetList( listRoot, &listtmpnode, tmpnode->id ) ){
            currtmpnode = listtmpnode->data;
            datatype = currtmpnode->type;
        }else{
            fprintf(stderr, UNDEC_VAR, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id );
        }

        TailNode* curr = tmpnode->tailnode;
        if (listtmpnode != 0)
            while (curr != 0){
                curr = curr->tailnode;
                if (currtmpnode->type == Array){
                    currtmpnode = ((arraysymbolobj*)currtmpnode)->data;
                }else{
                    fprintf(stderr, INDEX_MANY, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id);
                    break;
                }
                datatype = currtmpnode->type;
            }

        if (tmpnode->tailnode != 0){

            // debug
            // fprintf(stderr, "%d: %d has an Node\n", tmpnode->tailnode->node.loc.first_line, tmpnode->tailnode->node.loc.first_column);

            tmpnode->tailnode->node.visit(tmpnode->tailnode);
        }

        return datatype;
        break;

    case 1:
        // IDENTIFIER LPAREN expression_list RPAREN

        if ( GetList( listRoot, &listtmpnode, tmpnode->id ) ){
            currtmpnode = listtmpnode->data;
            while (currtmpnode->type == Array){
                currtmpnode = ((arraysymbolobj*)currtmpnode)->data;
            }
            datatype = currtmpnode->type;
        }else{
            fprintf(stderr, UNDEC_FUN, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id );
        }

        if (tmpnode->expressionlistnode != 0)
            tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);

        if (listtmpnode != 0){
            // check arguments
            symbolobj* tmpnodenode = ((funcsymbolobj*)listtmpnode->data)->passInType;
            if ( checkArguments( tmpnode->expressionlistnode, &tmpnodenode, 0 ) )
                fprintf(stderr, WRONG_ARGS, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id);
            
        }

        return datatype;
        break; 

    case 2:
        // num

        // debug
        // fprintf(stderr, "test: %d\n", tmpnode->num->node.visit(tmpnode->num));
        
        return tmpnode->num->node.visit(tmpnode->num);
        break;
    
    case 3:
        // LITERALSTR

        break;

    case 4:
        // LPAREN expression RPAREN

        if (tmpnode->expressionnode != 0)
            return tmpnode->expressionnode->node.visit(tmpnode->expressionnode);
        break;

    case 5:
        // NOT factor

        if (tmpnode->factornode != 0)
            tmpnode->factornode->node.visit(tmpnode->factornode);
        break;

    case 6:
        // SUBOP factor

        if (tmpnode->factornode != 0)
            tmpnode->factornode->node.visit(tmpnode->factornode);
        break;
    
    default:
        break;
    }

    return -1;
}


//identifier
Node* newIdentListNode( int fl, int fc, char* id, IdentListNode* identlistnode, int ll, int lc ){
    IdentListNode* tmpnode = (IdentListNode*) malloc ( sizeof(IdentListNode) );
    tmpnode->id = id;
    tmpnode->PrevNode = identlistnode;
    tmpnode->node.type = NODE_IdentList;
    tmpnode->node.visit = IdentListNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}


void* IdentListNode_visit(void* node){

    return 0;
}


//mulop
Node* newMulNode( int fl, int fc, int type, int ll, int lc ){
    MulNode* tmpnode = (MulNode*) malloc ( sizeof(MulNode) );
    tmpnode->type = type;
    tmpnode->node.type = NODE_MulOp;
    tmpnode->node.visit = MulNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* MulNode_visit(void* node){

    return 0;
}


//num

Node* newNumNode( int fl, int fc, int type, double num, char* string, int ll, int lc ){
    NumNode* tmpnode = (NumNode*) malloc ( sizeof(NumNode) );
    tmpnode->type = type;
    if (type == 2){
        // sscanf(string, "%llfE%llf", tmpnode->num, tmpnode->exp);
    }else{
        tmpnode->num = num;
        tmpnode->exp = 0.0f;
    }
    tmpnode->node.type = NODE_Num;
    tmpnode->node.visit = NumNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
};

void* NumNode_visit(void* node){
    NumNode* tmpnode = (NumNode*) node;

    switch (tmpnode->type)
    {
    case 0:
        // REALNUMBER
        return 2;
        break;

    case 1:
        // INTERGERNUM
        return 0;
        break;

    case 2:
        // SCIENTIFIC
        break;
    
    default:
        break;
    }

    return -1;
}


//opt stt


Node* newOptionalStatementSNode( int fl, int fc, StatementListNode* statementlistnode, int ll, int lc ){
    OptionalStatementSNode* tmpnode = (OptionalStatementSNode*) malloc ( sizeof(OptionalStatementSNode) );
    tmpnode->statementlistnode = statementlistnode;
    tmpnode->node.type = NODE_OptionalStatementS;
    tmpnode->node.visit = OptionalStatementSNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}


void* OptionalStatementSNode_visit(void* node){
    OptionalStatementSNode* tmpnode = (OptionalStatementSNode*) node;
    // printf("%d: %d OptionalStatementSNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    tmpnode->statementlistnode->node.visit(tmpnode->statementlistnode);

    return -1;
}


//opt var
void* OptionalVarNode_visit(void* node){
    
    return 0;
}

Node* newOptionalVarNode( int fl, int fc ){
    OptionalVarNode* tmpnode = (OptionalVarNode*) malloc ( sizeof(OptionalVarNode) );
    tmpnode->node.type = NODE_OptionalVar;
    tmpnode->node.visit = OptionalVarNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = fl;
    tmpnode->node.loc.last_column = fc;

    return tmpnode;
}


//para list
Node* newParameterListNode( int fl, int fc, OptionalVarNode* optionalvarnode, IdentListNode* identlistnode, TypeNode* typenode, ParameterListNode* parameterlistnode, int ll, int lc ){
    ParameterListNode* tmpnode = (ParameterListNode*) malloc ( sizeof(ParameterListNode) );
    tmpnode->optionalvarnode = optionalvarnode;
    tmpnode->identlistnode = identlistnode;
    tmpnode->typenode = typenode;
    tmpnode->NextNode = parameterlistnode;
    tmpnode->node.type = NODE_ParameterList;
    tmpnode->node.visit = ParameterListNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* ParameterListNode_visit(void* node){

    return 0;
}






//procedurestt
extern list* listRoot;
extern int scope;

int checkProcedArguments(ExpressionListNode* listNode, symbolobj** curr, int num){
    if (listNode->expressionlistnode != 0){
        if (checkArguments(listNode->expressionlistnode, curr, num+1))
            return 1;
    }

    if ( ((passinobj*)*curr)->data->type == (int)listNode->expressionnode->node.visit(listNode->expressionnode) ){
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

Node* newProcedureStatementNode( int fl, int fc, char* id, ExpressionListNode* expressionlistnode, int ll, int lc ){
    ProcedureStatementNode* tmpnode = (ProcedureStatementNode*) malloc ( sizeof(ProcedureStatementNode) );
    tmpnode->id = id;
    tmpnode->expressionlistnode = expressionlistnode;
    tmpnode->node.type = NODE_ProcedureStatement;
    tmpnode->node.visit = ProcedureStatementNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* ProcedureStatementNode_visit(void* node){
    ProcedureStatementNode* tmpnode = (ProcedureStatementNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);

    list* listTemp;
    if ( GetList( listRoot, &listTemp, tmpnode->id ) ){
        // variable is declared

        // check arguments
        symbolobj* tmpnodenode = ((funcsymbolobj*)listTemp->data)->passInType;
        if ( (tmpnodenode != 0) && (tmpnode->expressionlistnode != 0) )
            if ( checkProcedArguments( tmpnode->expressionlistnode, &tmpnodenode, 0 ) )
                fprintf(stderr, WRONG_ARGS, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id);
    }else{
        // undeclared variables
        fprintf(stderr, UNDEC_FUN, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id );
    }

    if (tmpnode->expressionlistnode != 0)
        tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);

    return -1;
}



//Prog


list* listRoot;
extern int scope;

Node* newProgNode( int fl, int fc, char* id, IdentListNode* identlist, DeclarNode* declar, SubDeclarSNode* subdeclars, CompoundStatementNode* compoundstatement, int ll, int lc ){
    // initialize my ProgNode
    ProgNode* tmpnode = (ProgNode*) malloc ( sizeof(ProgNode) );
    tmpnode->id = id;
    tmpnode->identlist = identlist;
    tmpnode->declar = declar;
    tmpnode->subdeclar = subdeclars;
    tmpnode->compoundstatement = compoundstatement;
    tmpnode->node.type = NODE_Prog;
    tmpnode->node.visit = ProgNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
};

void* ProgNode_visit(void* node){
    // I don't know what to do
    ProgNode* tmpnode = (ProgNode*)node;

    // create a scope
    SHOW_NEWSCP();

    // add sym into symbol table
    SHOW_NEWSYM(tmpnode->id);
    listRoot = newdatalist(tmpnode->id, scope, Void, Data);

    // Visit inside
    if (tmpnode->identlist != NULL)
        tmpnode->identlist->node.visit(tmpnode->identlist);
    if (tmpnode->declar != NULL)
        tmpnode->declar->node.visit(tmpnode->declar);
    if (tmpnode->subdeclar != NULL)
        tmpnode->subdeclar->node.visit(tmpnode->subdeclar);
    if (tmpnode->compoundstatement != NULL)
        tmpnode->compoundstatement->node.visit(tmpnode->compoundstatement);

    SHOW_CLSSCP();
    SHOW_SYMTAB_HEAD();
    // print table
    list_printTable(listRoot);
    SHOW_SYMTAB_TAIL();

    return 0;
}


//relop
Node* newRelopNode( int fl, int fc, int type, int ll, int lc ){
    RelopNode* tmpnode = (RelopNode*) malloc ( sizeof(RelopNode) );
    tmpnode->type = type;
    tmpnode->node.type = NODE_RelOp;
    tmpnode->node.visit = RelopNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* RelopNode_visit(void* node){
    RelopNode* tmpnode = (RelopNode*) node;

    return tmpnode->type;
}

//simple exp


Node* newSimpleExpressionNode( int fl, int fc, SimpleExpressionNode* simpleexpressionnode, AddOpNode* addnode, TermNode* termnode, int ll, int lc ){
    SimpleExpressionNode* tmpnode = (SimpleExpressionNode*) malloc ( sizeof(SimpleExpressionNode) );
    tmpnode->termnode = termnode;
    tmpnode->simpleexpressionnode = simpleexpressionnode;
    tmpnode->addnode = addnode;
    tmpnode->node.type = NODE_SimpleExp;
    tmpnode->node.visit = SimpleExpressionNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* SimpleExpressionNode_visit(void* node){
    SimpleExpressionNode* tmpnode = (SimpleExpressionNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    int* tmpnode1, *tmpnode2; 
    int datatype = -1;

    if ( tmpnode->addnode != 0 ){
        tmpnode1 = tmpnode->simpleexpressionnode->node.visit(tmpnode->simpleexpressionnode);
        tmpnode->addnode->node.visit(tmpnode->addnode);
        tmpnode2 = tmpnode->termnode->node.visit(tmpnode->termnode);
        
        // debug
        // fprintf(stderr, "test: %d %d\n", (int)tmpnode1, (int)tmpnode2);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            if (tmpnode->addnode->add)
                fprintf(stderr, ARITH_TYPE, tmpnode->addnode->node.loc.first_line, tmpnode->addnode->node.loc.first_column, "+");
            else
                fprintf(stderr, ARITH_TYPE, tmpnode->addnode->node.loc.first_line, tmpnode->addnode->node.loc.first_column, "-");
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            return datatype;
        }
            
    }else{
        return tmpnode->termnode->node.visit(tmpnode->termnode);
    }
    return datatype;
}


//stdtype
Node* newStandTypeNode( int fl, int fc, int type, int ll, int lc ){
    StandTypeNode* tmpnode = (StandTypeNode*) malloc ( sizeof(StandTypeNode) );
    tmpnode->type = type;  // 0: integer, 1: real, 2: string
    tmpnode->node.type = NODE_StandardType;
    tmpnode->node.visit = StandTypeNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* StandTypeNode_visit(void* node){

    return 0;
}



//sttmnt

extern list* listRoot;
extern int scope;

Node* newStatementNode( int fl, int fc, int type, VarNode* varnode, ExpressionNode* expressionnode, ProcedureStatementNode* procedurestatementnode, CompoundStatementNode* compoundstatementnode, StatementNode* statementnode1, StatementNode* statementnode2, int ll, int lc ){
    StatementNode* tmpnode = (StatementNode*) malloc ( sizeof(StatementNode) );
    tmpnode->type = type;
    tmpnode->varnode = varnode;
    tmpnode->expressionnode = expressionnode;
    tmpnode->procedurestatementnode = procedurestatementnode;
    tmpnode->compoundstatementnode = compoundstatementnode;
    tmpnode->statementnode1 = statementnode1;
    tmpnode->statementnode2 = statementnode2;
    tmpnode->node.type = NODE_Statement;
    tmpnode->node.visit = StatementNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* StatementNode_visit(void* node){
    StatementNode* tmpnode = (StatementNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);

    // store the node from symbol table
    list* listTemp;
    // counter for counting elements
    int counter;
    // store data type
    int* tmpnode1, *tmpnode2;

    switch (tmpnode->type)
    {
    case 0:
    // variable ASSIGNMENT expression

        // visit variable
        tmpnode1 = (int*) tmpnode->varnode->node.visit(tmpnode->varnode);

        // visit expression
        tmpnode2 = (int*) tmpnode->expressionnode->node.visit(tmpnode->expressionnode);

        // debug
        // fprintf(stderr, "Data Type: %d\n", tmpnode1);
        // fprintf(stderr, "Data Type: %d\n", tmpnode2);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) )
            fprintf(stderr, ASSIG_TYPE, tmpnode->varnode->node.loc.first_line, tmpnode->varnode->node.loc.first_column);
        else if ( GetList(listRoot, &listTemp, tmpnode->varnode->id) ){
            if (listTemp->nodeType == Function){
                if ( ((funcsymbolobj*)listTemp->data)->check > 1 ){
                    ((funcsymbolobj*)listTemp->data)->check--;
                    fprintf(stderr, ASSIG_TYPE, tmpnode->varnode->node.loc.first_line, tmpnode->varnode->node.loc.first_column);
                }
            }
        }

        break;

    case 1:
    // procdure_statement
        
        tmpnode->procedurestatementnode->node.visit(tmpnode->procedurestatementnode);
        break;
    
    case 2:
    // compound_statement
        
        tmpnode->compoundstatementnode->node.visit(tmpnode->compoundstatementnode);
        break;

    case 3:
    // IF expression THEN statement ELSE statement
        
        if (tmpnode->expressionnode != 0)
            tmpnode->expressionnode->node.visit(tmpnode->expressionnode);

        if (tmpnode->statementnode1 != 0)
            tmpnode->statementnode1->node.visit(tmpnode->statementnode1);

        if (tmpnode->statementnode2 != 0)
            tmpnode->statementnode2->node.visit(tmpnode->statementnode2);

        break;

    case 4:
    // WHILE expression DO statement
        
        if (tmpnode->expressionnode != 0)
            tmpnode->expressionnode->node.visit(tmpnode->expressionnode);

        if (tmpnode->statementnode1 != 0)
            tmpnode->statementnode1->node.visit(tmpnode->statementnode1);

        break;
    
    default:
        break;
    }

    return 0;
}

//state,emt list


Node* newStatementListNode( int fl, int fc, StatementListNode* statementlistnode, StatementNode* statementnode, int ll, int lc ){
    StatementListNode* tmpnode = (StatementListNode*) malloc ( sizeof(StatementListNode) );
    tmpnode->nextList = statementlistnode;
    tmpnode->statementnode = statementnode;
    tmpnode->node.type = NODE_StatementList;
    tmpnode->node.visit = StatementListNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.first_column = lc;

    return tmpnode;
}

void* StatementListNode_visit(void* node){
    StatementListNode* tmpnode = (StatementListNode*) node;
    // printf("%d: %d StatementListNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    if (tmpnode->nextList != 0){
        tmpnode->nextList->node.visit(tmpnode->nextList);
    }
    if (tmpnode->statementnode != 0){
        tmpnode->statementnode->node.visit(tmpnode->statementnode);
    }

    return 0;
}


//subproghead
extern int scope;
extern list* listRoot;

Node* newSubHeadNode( int fl, int fc, int type, char* id, StandTypeNode* standard_type, ArgumentsNode* arguments, int ll, int lc ){
    SubHeadNode* tmpnode = (SubHeadNode*) malloc ( sizeof(SubHeadNode) );
    tmpnode->type = type;
    tmpnode->id = id;
    tmpnode->standard_type = standard_type;
    tmpnode->arguments = arguments;
    tmpnode->node.type = NODE_SubProgramHead;
    tmpnode->node.visit = SubHeadNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* SubHeadNode_visit(void* node){

    return 0;
}

//subprog decsss
Node* newSubDeclarSNode( int fl, int fc, SubDeclarSNode* prevnode, SubDeclarNode* nextnode, int ll, int lc ){
    SubDeclarSNode* tmpnode = (SubDeclarSNode*) malloc ( sizeof(SubDeclarSNode) );
    tmpnode->PrevNode = prevnode;
    tmpnode->NextNode = nextnode;
    tmpnode->node.type = NODE_SubProgramDeclarationS;
    tmpnode->node.visit = SubDeclarSNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* SubDeclarSNode_visit(void* node){
    SubDeclarSNode* tmpnode = (SubDeclarSNode*) node;
    
    if(tmpnode->PrevNode != NULL){
        tmpnode->PrevNode->node.visit(tmpnode->PrevNode);
    }
    
    tmpnode->NextNode->node.visit(tmpnode->NextNode);

    return 0;
}

//subprogdcc

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

Node* newSubDeclarNode( int fl, int fc, SubHeadNode* subheadnode, DeclarNode* declarnode, SubDeclarSNode* subdeclarsnode, CompoundStatementNode* compoundstatementnode, int ll, int lc ){
    SubDeclarNode* tmpnode = (SubDeclarNode*) malloc ( sizeof(SubDeclarNode) );
    tmpnode->head = subheadnode;
    tmpnode->declarnode = declarnode;
    tmpnode->subdeclarsnode = subdeclarsnode;
    tmpnode->compoundstatementnode = compoundstatementnode;
    tmpnode->node.type = NODE_SubProgramDeclaration;
    tmpnode->node.visit = SubDeclarNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
};

void* SubDeclarNode_visit(void* node){
    SubDeclarNode* tmpnode = (SubDeclarNode*) node;

    if (tmpnode->head != NULL){
        
        list* tmpnodeList;
        int check = 0;
        if (tmpnode->head->type){
            // PROCEDURE
            
            tmpnodeList = newfunclist( tmpnode->head->id, scope, Void, Function );
            if ( checkList(listRoot, tmpnode->head->id, scope, Function) ){
                fprintf(stderr, REDEF_FUN, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column+1, tmpnode->head->id);

            }else{
                SHOW_NEWSYM(tmpnode->head->id);
                list_push_back( listRoot, tmpnodeList );
            }

        }else{
            
            // FUNCTION
            switch (tmpnode->head->standard_type->type)
            {
            case 0:
                /* code */
                tmpnodeList = newfunclist( tmpnode->head->id, scope, Int, Function );
                break;

            case 1:
                tmpnodeList = newfunclist( tmpnode->head->id, scope, Real, Function );
                break;

            case 2:
                tmpnodeList = newfunclist( tmpnode->head->id, scope, String, Function );
                break;
            
            default:
                break;
            }

            StatementListNode* checkReturnType = NULL;
            if ( tmpnode->compoundstatementnode->statements != NULL )
                checkReturnType = tmpnode->compoundstatementnode->statements->statementlistnode;
            while(checkReturnType != NULL){

                check = checkExist(checkReturnType->statementnode, tmpnode->head->id);
                if (check)
                    break;

                checkReturnType = checkReturnType->nextList;
            }
            
            if ( checkList(listRoot, tmpnode->head->id, scope, Function) ){
                list* listTemp;
                GetList(listRoot, &listTemp, tmpnode->head->id);
                ((funcsymbolobj*)listTemp->data)->check = 2;
                fprintf(stderr, REDEF_FUN, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->head->id);
                fprintf(stderr, RETURN_VAL, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->head->id);
                // if (check){
                //     fprintf(stderr, ASSIG_TYPE, checkReturnType->statementnode->node.loc.first_line, checkReturnType->statementnode->node.loc.first_column);
                // }
            }else{
                SHOW_NEWSYM(tmpnode->head->id);
                list_push_back( listRoot, tmpnodeList );
                if (!check)
                fprintf(stderr, RETURN_VAL, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->head->id);
            }

        }
        
        // create a scope
        SHOW_NEWSCP();
        scope++;

        // pass in data type
        ParameterListNode* curr = NULL;
        passinobj* passinobjTemp = NULL;


        if (tmpnode->head->arguments != NULL)
            curr = tmpnode->head->arguments->parameterlist;

        if (curr != 0){
            // initialize the funcList

            ((funcsymbolobj*)tmpnodeList->data)->passInType = (symbolobj*) malloc ( sizeof(passinobj) );
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
                ((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data = (symbolobj*) malloc ( sizeof(symbolobj) );
                ((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data->type = typeTemp;
                passinobjTemp = ((funcsymbolobj*)tmpnodeList->data)->passInType;
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

                ((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data = (symbolobj*) malloc ( sizeof(arraysymbolobj) );
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data)->type = Array;
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data)->start = curr->typenode->array_start;
                ((arraysymbolobj*)((passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType)->data)->end = curr->typenode->array_end;

                passinobjTemp = ((funcsymbolobj*)tmpnodeList->data)->passInType;
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
                    passinobj* passinobjTemp = ((funcsymbolobj*)tmpnodeList->data)->passInType;
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
    
    if (tmpnode->declarnode != NULL){
        tmpnode->declarnode->node.visit(tmpnode->declarnode);
    }

    if (tmpnode->subdeclarsnode != NULL){
        tmpnode->subdeclarsnode->node.visit(tmpnode->subdeclarsnode);
    }

    if (tmpnode->compoundstatementnode != NULL){
        tmpnode->compoundstatementnode->node.visit(tmpnode->compoundstatementnode);
    }

    list* listTemp;
    if ( GetList(listRoot, &listTemp, tmpnode->head->id) )
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



//tail

Node* newTailNode( int fl, int fc, ExpressionNode* expressionnode, TailNode* tailnode, int ll, int lc ){
    TailNode* tmpnode = (TailNode*) malloc ( sizeof(TailNode) );
    tmpnode->expressionnode = expressionnode;
    tmpnode->tailnode = tailnode;
    tmpnode->node.type = NODE_Tail;
    tmpnode->node.visit = TailNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* TailNode_visit(void* node){
    TailNode* tmpnode = (TailNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    int datatype = -1;

    if (tmpnode->expressionnode != 0){
        int tmpnode2 = tmpnode->expressionnode->node.visit(tmpnode->expressionnode);
        if ( (tmpnode2 != -1) && (tmpnode2 != 0)  )
            datatype = 1;
    }
    if (datatype == 1)
        fprintf(stderr, INDEX_TYPE, tmpnode->expressionnode->node.loc.first_line, tmpnode->expressionnode->node.loc.first_column);


    if (tmpnode->tailnode != 0){
        int tmpnode2 = tmpnode->tailnode->node.visit(tmpnode->tailnode);
        if ( (tmpnode2 != -1) && (tmpnode2 != 0)  )
            datatype = 1;
    }
    
    return datatype;
}


//term

Node* newTermNode( int fl, int fc, TermNode* termnode, MulNode* mulnode, FactorNode* factornode, int ll, int lc ){
    TermNode* tmpnode = (TermNode*) malloc ( sizeof(TermNode) );
    tmpnode->termnode = termnode;
    tmpnode->mulnode = mulnode;
    tmpnode->factornode = factornode;
    tmpnode->node.type = NODE_Term;
    tmpnode->node.visit = TermNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* TermNode_visit(void* node){
    TermNode* tmpnode = (TermNode*) node;

    // debug
    // fprintf(stderr, "%d: %d has an Node\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);

    int* tmpnode1, *tmpnode2;
    int datatype = -1;

    if (tmpnode->mulnode != 0){
        tmpnode1 = tmpnode->termnode->node.visit(tmpnode->termnode);
        tmpnode->mulnode->node.visit(tmpnode->mulnode);
        tmpnode2 = tmpnode->factornode->node.visit(tmpnode->factornode);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            if (tmpnode->mulnode->type)
                fprintf(stderr, ARITH_TYPE, tmpnode->mulnode->node.loc.first_line, tmpnode->mulnode->node.loc.first_column, "/");
            else
                fprintf(stderr, ARITH_TYPE, tmpnode->mulnode->node.loc.first_line, tmpnode->mulnode->node.loc.first_column, "*");
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            return datatype;
        }
        
    }else{
        return tmpnode->factornode->node.visit(tmpnode->factornode);
    }

    return datatype;
}

//type
void* TypeNode_visit(void* node){

    return 0;
}

Node* newTypeNode( int fl, int fc, StandTypeNode* standtypenode, int array_start, int array_end, TypeNode* type, int ll, int lc ){
    TypeNode* tmpnode = (TypeNode*) malloc ( sizeof(TypeNode) );
    tmpnode->standtypenode = standtypenode;
    tmpnode->array_start = array_start;
    tmpnode->array_end = array_end;
    tmpnode->type = type;
    tmpnode->node.type = NODE_Type;
    tmpnode->node.visit = TypeNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.last_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}


//var

extern list* listRoot;
extern int scope;

Node* newVarNode( int fl, int fc, char* id, TailNode* tailnode, int ll, int lc ){
    VarNode* tmpnode = (VarNode*) malloc ( sizeof(VarNode) );
    tmpnode->id = id;
    tmpnode->tailnode = tailnode;
    tmpnode->node.type = NODE_Var;
    tmpnode->node.visit = VarNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    return tmpnode;
}

void* VarNode_visit(void* node){
    VarNode* tmpnode = (VarNode*) node;
    
    list* listTemp = NULL;
    int datatype = -1;
    symbolobj* currTemp = NULL;

    if ( GetList( listRoot, &listTemp, tmpnode->id ) ){
        // if ( (listTemp->nodeType == Function) && ( ((funcsymbolobj*)listTemp->data)->check == 1 ) )
        //     fprintf(stderr, ASSIG_TYPE, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);

        currTemp = listTemp->data;
        datatype = currTemp->type;
    }else{
        // undeclared variables
        fprintf(stderr, UNDEC_VAR, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id );
    }

    TailNode* curr = tmpnode->tailnode;
    if (listTemp != 0)
        while (curr != 0){
            
            curr = curr->tailnode;
            if (currTemp->type == Array){
                currTemp = ((arraysymbolobj*)currTemp)->data;
            }else{
                fprintf(stderr, INDEX_MANY, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column, tmpnode->id);
                break;
            }
            datatype = currTemp->type;
        }
    // check id tail
    if (tmpnode->tailnode != 0){
        tmpnode->tailnode->node.visit(tmpnode->tailnode);
    }



    return datatype;
}
