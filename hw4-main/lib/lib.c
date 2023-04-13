#include "ast.h"
#include "stdbool.h"
#include "stdlib.h"
#include "lib.h"
#include "info.h"
#include "stdio.h"
#include "print.h"
#include "string.h"
#include "codegen.h"
#include <ctype.h>

#define BOOL int


char* buffer;
// stderr
#define print_REDEF_FUN(buffer) do { fprintf(stderr,REDEF_FUN,tmpnode->node.loc.first_line, tmpnode->node.loc.first_column+1,buffer); } while(0)
#define print_REDEF_ARG(buffer) do { fprintf(stderr,REDEF_ARG,tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column,buffer); } while(0)
#define print_REDEF_VAR(buffer) do { fprintf(stderr,REDEF_VAR,curr->node.loc.first_line, curr->node.loc.first_column,buffer); } while(0)
#define print_UNDEC_VAR(buffer) do { fprintf(stderr,UNDEC_VAR,tmpnode->node.loc.first_line, tmpnode->node.loc.first_column,buffer); } while(0)
#define print_UNDEC_FUN(buffer) do { fprintf(stderr,UNDEC_FUN,tmpnode->node.loc.first_line, tmpnode->node.loc.first_column,buffer); } while(0)
#define print_ARITH_TYPE(buffer) do { fprintf(stderr,ARITH_TYPE,tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column,buffer); } while(0)
#define print_ASSIG_TYPE(buffer) do { fprintf(stderr,ASSIG_TYPE,tmpnode->varnode->node.loc.first_line, tmpnode->varnode->node.loc.first_column); } while(0)
#define print_INDEX_TYPE(buffer) do { fprintf(stderr,INDEX_TYPE,tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column,buffer); } while(0)
#define print_INDEX_MANY(buffer) do { fprintf(stderr,INDEX_MANY,tmpnode->node.loc.first_line, tmpnode->node.loc.first_column,buffer); } while(0)
#define print_WRONG_ARGS(buffer) do { fprintf(stderr,WRONG_ARGS,tmpnode->node.loc.first_line, tmpnode->node.loc.first_column,buffer); } while(0)
#define print_RETURN_VAL(buffer) do { fprintf(stderr,RETURN_VAL,tmpnode->relop->node.loc.first_line, tmpnode->relop->node.loc.first_column,buffer); } while(0)

extern char *output;
extern int TO_FUNC;



//stdin
#define print_SHOW_NEWSYM do { SHOW_NEWSYM(buffer); } while(0)
#define print_SHOW_NEWSCP do { SHOW_NEWSCP(); } while(0)
#define print_SHOW_CLSSCP do { SHOW_CLSSCP(); } while(0)
#define print_SHOW_SYMTAB_HEAD do { SHOW_SYMTAB_HEAD(); } while(0)
#define print_SHOW_SYMTAB_TAIL do { SHOW_SYMTAB_TAIL(); } while(0)
#define print_SYMTAB_ENTRY_FMT do { printf(SYMTAB_ENTRY_FMT,"ayh3",200,"sey"); } while(0)




//Addop
AddOpNode* newAddOpNode( int fl, int fc, bool add, int ll, int lc ){
    AddOpNode* tmpnode = (AddOpNode*) malloc ( sizeof(AddOpNode) );
    tmpnode->add = add;
    tmpnode->node.type = NODE_AddOp;
    tmpnode->node.visit = AddOpNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = ll;
    tmpnode->node.loc.last_column = lc;

    // gen("new addop node\n");

    return tmpnode;
}

int AddOpNode_visit(void* node){

    if(((AddOpNode*)node)->add)return 1;
    else return 0;
}


//Argument

ArgumentsNode* newArgumentsNode( int fl, int fc, ParameterListNode* parameterlist, int ll, int lc ){
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

int ArgumentsNode_visit(void* node){

    return 0;
}


//Boolexpression
BoolExpNode* newBoolExpNode( int fl, int fc, SimpleExpressionNode* first, RelopNode* relop, SimpleExpressionNode* least, int ll, int lc ){
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

int BoolExpNode_visit(void* node){
    BoolExpNode* tmpnode = (BoolExpNode*) node;
    
    int tmpnode1;
    int tmpnode2;
    int datatype = -1;

    if (tmpnode->relop != 0){
        tmpnode1 = tmpnode->first->node.visit(tmpnode->first);
        int type = tmpnode->relop->node.visit(tmpnode->relop);
        tmpnode2 = tmpnode->least->node.visit(tmpnode->least);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            switch (tmpnode->relop->type){
                case 0:
                    
                    print_ARITH_TYPE("<");
                    break;

                case 1:
                    print_ARITH_TYPE(">");
                    break;

                case 2:
                    print_ARITH_TYPE("=");
                    break;

                case 3:
                    print_ARITH_TYPE(">=");
                    break;

                case 4:
                    print_ARITH_TYPE("<=");
                    break;

                case 5:
                    print_ARITH_TYPE("!=");
                    break;

                default:
                break;
            }
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            GEN_RELOPNODE(type,datatype);
            return datatype;
        }

    }else{
        return (int)tmpnode->first->node.visit(tmpnode->first);
    }   

    return -1;
}



//Compoundstatement
extern list* listRoot;
extern int scope;

CompoundStatementNode* newCompoundStatementNode( int fl, int fc, OptionalStatementSNode* optionalstatementsnode, int ll, int lc ){
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

int CompoundStatementNode_visit(void* node){
    CompoundStatementNode* tmpnode = (CompoundStatementNode*) node;
    // printf("%d: %d CompoundStatementNode\n", tmpnode->node.loc.first_line, tmpnode->node.loc.first_column);
    if (tmpnode->statements != NULL)
        tmpnode->statements->node.visit(tmpnode->statements);

    return 0;
}



//Declaration
DeclarNode* newDeclarNode( int fl, int fc, DeclarNode* declarnode, IdentListNode* identlist, TypeNode* type, int ll, int lc ){
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

int DeclarNode_visit(void* node){
    DeclarNode* tmpnode = (DeclarNode*)node;

    // go to leftmost declarations
    if (tmpnode->NextNode != NULL)
        tmpnode->NextNode->node.visit(tmpnode->NextNode);

    // add sym into symbol table
    IdentListNode* curr = tmpnode->identlistnode;
    while(curr != NULL){
        if ( checkList(listRoot, curr->id, scope, Data) ){
            print_REDEF_VAR(curr->id);
            // fprintf(stderr, REDEF_VAR, curr->node.loc.first_line, curr->node.loc.first_column, curr->id );
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
                    // declar_gen_int(curr->id);
                    GEN_DECLARE(curr->id , 0);
                    break;

                case 1:
                    typetmpnode = Real;
                    // declar_gen_real(curr->id);
                    GEN_DECLARE(curr->id , 1);

                    break;

                case 2:
                    typetmpnode = String;
                    // declar_gen_string(curr->id);
                    GEN_DECLARE(curr->id , 2);

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
                GEN_ARRAY_FIELD(listtmpnode,curr_type->standtypenode->type);

            }
            
        }
        curr = curr->PrevNode;
    }

    return 0;
}


//Expression
ExpressionNode* newExpNode( int fl, int fc, BoolExpNode* first, int op, BoolExpNode* least, int ll, int lc ){
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

int ExpNode_visit(void* node){
    ExpressionNode* tmpnode = (ExpressionNode*) node;
    

    switch (tmpnode->type)
    {
    case 0: 
        return (int)tmpnode->first->node.visit(tmpnode->first);
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

//ExpresionList
ExpressionListNode* newExpressionListNode( int fl, int fc, ExpressionListNode* expressionlistnode, ExpressionNode* expressionnode, int ll, int lc ){
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

int ExpressionListNode_visit(void* node){
    ExpressionListNode* tmpnode = (ExpressionListNode*) node;

    if (tmpnode->expressionlistnode != 0)
        tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);

    if (tmpnode->expressionnode != 0)
        tmpnode->expressionnode->node.visit(tmpnode->expressionnode);

    return -1;
}


//Factor

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

FactorNode* newFactorNode( int fl, int fc, int type, char* id, TailNode* tailnode, ExpressionListNode* expressionlistnode, NumNode* numnode, ExpressionNode* expressionnode, FactorNode* factornode, int ll, int lc ){
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

int FactorNode_visit(void* node){
    FactorNode* tmpnode = (FactorNode*)node;


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
            print_UNDEC_VAR(tmpnode->id);
        }

        TailNode* curr = tmpnode->tailnode;

        GEN_FACTOR_BLOBAL(tmpnode->id);

        if (listtmpnode != 0)
            while (curr != 0){
                curr = curr->tailnode;
                if (currtmpnode->type == Array){
                    currtmpnode = ((arraysymbolobj*)currtmpnode)->data;
                }else{
                    print_INDEX_MANY(tmpnode->id);
                    break;
                }
                datatype = currtmpnode->type;
            }

        if (tmpnode->tailnode != 0){

            tmpnode->tailnode->node.visit(tmpnode->tailnode);
        }
        GEN_GET_FUNCTION(tmpnode->id , 0);
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
            print_UNDEC_FUN(tmpnode->id);
        }

        if (tmpnode->expressionlistnode != 0) tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);

        GEN_GET_FUNCTION(tmpnode->id,1);


        if (listtmpnode != 0){
            // check arguments
            symbolobj* tmpnodenode = ((funcsymbolobj*)listtmpnode->data)->passInType;
            if ( checkArguments( tmpnode->expressionlistnode, &tmpnodenode, 0 ) )
                print_WRONG_ARGS(tmpnode->id);
            
        }

        return datatype;
        break; 

    case 2:
        // num

        return tmpnode->num->node.visit(tmpnode->num);
        break;
    
    case 3:
        // LITERALSTR

        GEN_FACTOR_SAVE_STRING(tmpnode->id);
        GEN_FACTOR_IF_ADDOP(tmpnode->id);
        return 3;
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

        GEN_FACTOR_NE();

        break;

    case 6:
        // SUBOP factor

        if (tmpnode->factornode != 0)
            tmpnode->factornode->node.visit(tmpnode->factornode);

        GEN_FACTOR_NEG();


        break;
    
    default:
        break;
    }

    return -1;
}


//IdentifierList
IdentListNode* newIdentListNode( int fl, int fc, char* id, IdentListNode* identlistnode, int ll, int lc ){
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


int IdentListNode_visit(void* node){

    return 0;
}


//Mulop
MulNode* newMulNode( int fl, int fc, int type, int ll, int lc ){
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

int MulNode_visit(void* node){
    MulNode* temp = (MulNode*) node;
    return temp->type;
    return 0;
}


//Numop

NumNode* newNumNode( int fl, int fc, int type, double num, char* string, int ll, int lc ){
    NumNode* tmpnode = (NumNode*) malloc ( sizeof(NumNode) );
    tmpnode->type = type;
    if (type == 2){
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

int NumNode_visit(void* node){
    NumNode* tmpnode = (NumNode*) node;

    switch (tmpnode->type)
    {
    case 0:
        // REALNUMBER
        // num_gen_real(tmpnode->num);
        GEN_NUM(0,tmpnode->num,0);
        return 2;
        break;

    case 1:
        // INTERGERNUM
        // num_gen_int(tmpnode->num);
        GEN_NUM(tmpnode->num,0,1);

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




//OptionalStatement
OptionalStatementSNode* newOptionalStatementSNode( int fl, int fc, StatementListNode* statementlistnode, int ll, int lc ){
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


int OptionalStatementSNode_visit(void* node){
    OptionalStatementSNode* tmpnode = (OptionalStatementSNode*) node;
    tmpnode->statementlistnode->node.visit(tmpnode->statementlistnode);

    return -1;
}


//OptionalVar
int OptionalVarNode_visit(void* node){
    
    return 0;
}

OptionalVarNode* newOptionalVarNode( int fl, int fc ){
    OptionalVarNode* tmpnode = (OptionalVarNode*) malloc ( sizeof(OptionalVarNode) );
    tmpnode->node.type = NODE_OptionalVar;
    tmpnode->node.visit = OptionalVarNode_visit;
    tmpnode->node.loc.first_line = fl;
    tmpnode->node.loc.first_column = fc;
    tmpnode->node.loc.last_line = fl;
    tmpnode->node.loc.last_column = fc;

    return tmpnode;
}


//ParameterList
ParameterListNode* newParameterListNode( int fl, int fc, OptionalVarNode* optionalvarnode, IdentListNode* identlistnode, TypeNode* typenode, ParameterListNode* parameterlistnode, int ll, int lc ){
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

int ParameterListNode_visit(void* node){

    return 0;
}






//Procedurestatament
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

ProcedureStatementNode* newProcedureStatementNode( int fl, int fc, char* id, ExpressionListNode* expressionlistnode, int ll, int lc ){
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

int ProcedureStatementNode_visit(void* node){
    ProcedureStatementNode* tmpnode = (ProcedureStatementNode*) node;


    list* listTemp;
    if ( GetList( listRoot, &listTemp, tmpnode->id ) ){
        // variable is declared

        // check arguments
        symbolobj* tmpnodenode = ((funcsymbolobj*)listTemp->data)->passInType;
        if ( (tmpnodenode != 0) && (tmpnode->expressionlistnode != 0) )
            if ( checkProcedArguments( tmpnode->expressionlistnode, &tmpnodenode, 0 ) )
                print_WRONG_ARGS(tmpnode->id);
    }else{
        // undeclared variables
        print_UNDEC_FUN(tmpnode->id);
    }

    if (tmpnode->expressionlistnode != 0)
        tmpnode->expressionlistnode->node.visit(tmpnode->expressionlistnode);


    GEN_PROCEDURE(tmpnode->id);

    return 0;
}






//Prog
list* listRoot;
extern int scope;

ProgNode* newProgNode( int fl, int fc, char* id, IdentListNode* identlist, DeclarNode* declar, SubDeclarSNode* subdeclars, CompoundStatementNode* compoundstatement, int ll, int lc ){
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

    // gen("new Prog Node\n");


    return tmpnode;
};

int ProgNode_visit(void* node){
    // I don't know what to do
    ProgNode* tmpnode = (ProgNode*)node;

    // create a scope
    SHOW_NEWSCP();
    // gen("new Prog Node\n");

    // add sym into symbol table
    SHOW_NEWSYM(tmpnode->id);
    listRoot = newdatalist(tmpnode->id, scope, Void, Data);


    // Visit inside
    if (tmpnode->identlist != NULL)
        tmpnode->identlist->node.visit(tmpnode->identlist);
    if (tmpnode->declar != NULL)
        tmpnode->declar->node.visit(tmpnode->declar);

    GEN_BUILDINGS();


    if (tmpnode->subdeclar != NULL)
        tmpnode->subdeclar->node.visit(tmpnode->subdeclar);

    GEN_PBEGIN();
    TO_FUNC = 0;

    if (tmpnode->compoundstatement != NULL)
        tmpnode->compoundstatement->node.visit(tmpnode->compoundstatement);

    GEN_END();


    SHOW_CLSSCP();
    SHOW_SYMTAB_HEAD();
    // print table
    list_printTable(listRoot);
    SHOW_SYMTAB_TAIL();

    return 0;
}


//Relop
RelopNode* newRelopNode( int fl, int fc, int type, int ll, int lc ){
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
extern int RelOp_EQ;

int RelopNode_visit(void* node){
    RelopNode* tmpnode = (RelopNode*) node;

    // if_c(tmpnode->type);
    if(((RelopNode*)node)->type == 2)RelOp_EQ = 1;

    return tmpnode->type;
}



//SimpleExpression

SimpleExpressionNode* newSimpleExpressionNode( int fl, int fc, SimpleExpressionNode* simpleexpressionnode, AddOpNode* addnode, TermNode* termnode, int ll, int lc ){
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

extern int AddOp_Add;
int SimpleExpressionNode_visit(void* node){
    SimpleExpressionNode* tmpnode = (SimpleExpressionNode*) node;

    int tmpnode1, tmpnode2; 
    int datatype = -1;

    if ( tmpnode->addnode != 0 ){

        AddOp_Add=1;


        tmpnode1 = (int)tmpnode->simpleexpressionnode->node.visit(tmpnode->simpleexpressionnode);
        int positive = tmpnode->addnode->node.visit(tmpnode->addnode);
        tmpnode2 = (int)tmpnode->termnode->node.visit(tmpnode->termnode);
        


        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            if (tmpnode->addnode->add)
                // print_ARITH_TYPE("+");
                fprintf(stderr, ARITH_TYPE, tmpnode->addnode->node.loc.first_line, tmpnode->addnode->node.loc.first_column, "+");
            else
                //print_ARITH_TYPE("-");
                fprintf(stderr, ARITH_TYPE, tmpnode->addnode->node.loc.first_line, tmpnode->addnode->node.loc.first_column, "-");
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            GEN_ADDOPNODE(positive, datatype);
            return datatype;
        }
            
    }else{
        return tmpnode->termnode->node.visit(tmpnode->termnode);
    }
    return datatype;
}


//StandardType
StandTypeNode* newStandTypeNode( int fl, int fc, int type, int ll, int lc ){
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

int StandTypeNode_visit(void* node){

    return 0;
}



//Statement
extern list* listRoot;
extern int scope;

StatementNode* newStatementNode( int fl, int fc, int type, VarNode* varnode, ExpressionNode* expressionnode, ProcedureStatementNode* procedurestatementnode, CompoundStatementNode* compoundstatementnode, StatementNode* statementnode1, StatementNode* statementnode2, int ll, int lc ){
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

int StatementNode_visit(void* node){
    StatementNode* tmpnode = (StatementNode*) node;

    // store the node from symbol table
    list* listTemp;
    // counter for counting elements
    // store data type
    long int tmpnode1;
    long int tmpnode2;

    switch (tmpnode->type)
    {
    case 0:
    // variable ASSIGNMENT expression

        // visit variable
        tmpnode1 = (long)tmpnode->varnode->node.visit(tmpnode->varnode);

        // visit expression
        tmpnode2 = (long)tmpnode->expressionnode->node.visit(tmpnode->expressionnode);
        GEN_VARIABLE(tmpnode->varnode->id);


        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) )
                print_ASSIG_TYPE("");
            
        else if ( GetList(listRoot, &listTemp, tmpnode->varnode->id) ){
            if (listTemp->nodeType == Function){
                if ( ((funcsymbolobj*)listTemp->data)->check > 1 ){
                    ((funcsymbolobj*)listTemp->data)->check--;
                    print_ASSIG_TYPE("");
                }
            }
        }

        break;

    case 1:// procdure_statement
        
        tmpnode->procedurestatementnode->node.visit(tmpnode->procedurestatementnode);
        break;
    
    case 2:// compound_statement
        
        tmpnode->compoundstatementnode->node.visit(tmpnode->compoundstatementnode);
        break;

    case 3:// IF expression THEN statement ELSE statement
        
        if (tmpnode->expressionnode != 0)
            tmpnode->expressionnode->node.visit(tmpnode->expressionnode);
        GEN_IF();

        if (tmpnode->statementnode1 != 0)
            tmpnode->statementnode1->node.visit(tmpnode->statementnode1);
        GEN_ELSE();

        if (tmpnode->statementnode2 != 0)
            tmpnode->statementnode2->node.visit(tmpnode->statementnode2);
        GEN_THEN();

        break;

    case 4:// WHILE expression DO statement
        GEN_WhileLoop();
        if (tmpnode->expressionnode != 0)
            tmpnode->expressionnode->node.visit(tmpnode->expressionnode);
        GEN_WhileLoop_mid();
        if (tmpnode->statementnode1 != 0)
            tmpnode->statementnode1->node.visit(tmpnode->statementnode1);
        GEN_WhileLoopDone();
        break;
    
    default:
        break;
    }

    return 0;
}



//StatementList

StatementListNode* newStatementListNode( int fl, int fc, StatementListNode* statementlistnode, StatementNode* statementnode, int ll, int lc ){
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

int StatementListNode_visit(void* node){
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


//Subprogramhead
extern int scope;
extern list* listRoot;

SubHeadNode* newSubHeadNode( int fl, int fc, int type, char* id, StandTypeNode* standard_type, ArgumentsNode* arguments, int ll, int lc ){
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

int SubHeadNode_visit(void* node){

    return 0;
}


//SubprogramDeclarations
SubDeclarSNode* newSubDeclarSNode( int fl, int fc, SubDeclarSNode* prevnode, SubDeclarNode* nextnode, int ll, int lc ){
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

int SubDeclarSNode_visit(void* node){
    SubDeclarSNode* tmpnode = (SubDeclarSNode*) node;
    TO_FUNC = 1;

    if(tmpnode->PrevNode != NULL){
        tmpnode->PrevNode->node.visit(tmpnode->PrevNode);
    }
    
    tmpnode->NextNode->node.visit(tmpnode->NextNode);
    GEN_FUNCTION_END();

    return 0;
}




//SubprogramDeclaration
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

SubDeclarNode* newSubDeclarNode( int fl, int fc, SubHeadNode* subheadnode, DeclarNode* declarnode, SubDeclarSNode* subdeclarsnode, CompoundStatementNode* compoundstatementnode, int ll, int lc ){
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

int SubDeclarNode_visit(void* node){
    SubDeclarNode* tmpnode = (SubDeclarNode*) node;

    if (tmpnode->head != NULL){
        
        list* tmpnodeList;
        int check = 0;
        if (tmpnode->head->type){
            // PROCEDURE
            
            tmpnodeList = newfunclist( tmpnode->head->id, scope, Void, Function );
            if ( checkList(listRoot, tmpnode->head->id, scope, Function) ){
                print_REDEF_FUN(tmpnode->head->id);
                // fprintf(stderr, REDEF_FUN, tmpnode->node.loc.first_line, tmpnode->node.loc.first_column+1, tmpnode->head->id);

            }else{
                SHOW_NEWSYM(tmpnode->head->id);
                list_push_back( listRoot, tmpnodeList );
            }

        }else{
            TO_FUNC = 1;

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
            GEN_FUNCTION_SET_ROOT(tmpnodeList);

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
                passinobjTemp = (passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType;
                if ( checkList(listRoot, idList->id, scope, Data) ){
                    fprintf(stderr, REDEF_ARG, idList->node.loc.first_line, idList->node.loc.first_column, idList->id );
                }else{
                    SHOW_NEWSYM(idList->id);
                    list_push_back( listRoot, newdatalist(idList->id, scope, typeTemp, Data) );
                }
                passinobjTemp->next = NULL;
                while( idList->PrevNode != NULL ){
                    passinobjTemp->next = (symbolobj*)(passinobj*) malloc ( sizeof(passinobj) );
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

                passinobjTemp = (passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType;
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
                    passinobj* passinobjTemp = (passinobj*)((funcsymbolobj*)tmpnodeList->data)->passInType;
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

                }

            }

        }
        GEN_FUNCTION();

        
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
    
    list_printTable(listRoot); // print table
    SHOW_SYMTAB_TAIL();
    scope--;
    listRemove(listRoot, scope);
    
    return 0;
}



//Tail

TailNode* newTailNode( int fl, int fc, ExpressionNode* expressionnode, TailNode* tailnode, int ll, int lc ){
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

int TailNode_visit(void* node){
    TailNode* tmpnode = (TailNode*) node;

    
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


//Term

TermNode* newTermNode( int fl, int fc, TermNode* termnode, MulNode* mulnode, FactorNode* factornode, int ll, int lc ){
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

int TermNode_visit(void* node){
    TermNode* tmpnode = (TermNode*) node;

   
    long int tmpnode1, tmpnode2;
    int datatype = -1;

    if (tmpnode->mulnode != 0){
        tmpnode1 = (long)tmpnode->termnode->node.visit(tmpnode->termnode);
        int ismul = tmpnode->mulnode->node.visit(tmpnode->mulnode);
        tmpnode2 = (long)tmpnode->factornode->node.visit(tmpnode->factornode);

        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 != tmpnode2) ){
            if (tmpnode->mulnode->type)
                fprintf(stderr, ARITH_TYPE, tmpnode->mulnode->node.loc.first_line, tmpnode->mulnode->node.loc.first_column, "/");
            else
                fprintf(stderr, ARITH_TYPE, tmpnode->mulnode->node.loc.first_line, tmpnode->mulnode->node.loc.first_column, "*");
            
        }
        if ( ((int)tmpnode1 >= 0) && ((int)tmpnode2 >= 0) && ((int)tmpnode1 == tmpnode2) ){
            datatype = (int)tmpnode1;
            GEN_MULNODE(ismul,datatype);

            return datatype;
        }
        
    }else{
        return (int)tmpnode->factornode->node.visit(tmpnode->factornode);
    }

    return datatype;
}

//Type
int TypeNode_visit(void* node){

    return 0;
}

TypeNode* newTypeNode( int fl, int fc, StandTypeNode* standtypenode, int array_start, int array_end, TypeNode* type, int ll, int lc ){
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


//Var

VarNode* newVarNode( int fl, int fc, char* id, TailNode* tailnode, int ll, int lc ){
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

int VarNode_visit(void* node){
    VarNode* tmpnode = (VarNode*) node;
    
    list* listTemp = NULL;
    int datatype = -1;
    symbolobj* currTemp = NULL;

    if ( GetList( listRoot, &listTemp, tmpnode->id ) ){

        currTemp = listTemp->data;
        datatype = currTemp->type;
    }else{
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
        GEN_ARRAY_ID(tmpnode->id);

        tmpnode->tailnode->node.visit(tmpnode->tailnode);
    }

    GEN_VARIABLE_SET_LABEL(tmpnode->id, datatype);


    return datatype;
}




struct declarnode* nthchild_decl( int n , struct declarnode* node ){
    struct declarnode* child = node->NextNode;
    for(int i=1;i<n;i++)child = child->NextNode;

    return child;
}


struct parameterlistnode* nthchild_paralist( int n , struct parameterlistnode* node ){
    struct parameterlistnode* child = node->NextNode;
    for(int i=1;i<n;i++)child = child->NextNode;

    return child;
}

// struct subdeclarnode* nthchild__subdeclars( int n , struct subdeclarsnode* node ){
//     struct subdeclarnode* child = node->NextNode;
//     for(int i=1;i<n;i++)child = child->NextNode;

//     return child;
// }



// void addChild(struct Node *node, struct Node *child)
// {
//   child->parent = node;
//   node->child_num++;
   

//   if(node->child == NULL)
//   {
//     node->child = child;
//   }

//   else
//   {
//     child->lsibling = node->child->lsibling;
//     child->rsibling = node->child;
//     node->child->lsibling->rsibling = child;
//     node->child->lsibling = child;
//   }
// }

