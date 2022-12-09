#ifndef __LIB_H__
#define __LIB_H__

#include "stdbool.h"
#include "stdlib.h"
#include "ast.h"
#include "lib.h"





typedef struct parameterlistnode ParameterListNode;
typedef struct procedurestatementnode ProcedureStatementNode;
typedef struct typenode TypeNode;
typedef struct simpleexpressionnode SimpleExpressionNode;
typedef struct Boolexpressionnode BoolExpNode;
typedef struct tailnode TailNode;
typedef struct factornode FactorNode;
typedef struct numnode NumNode;
typedef struct expressionlistnode ExpressionListNode;
typedef struct expressionnode ExpressionNode;
typedef struct declarnode DeclarNode;
typedef struct argumentsnode ArgumentsNode;
typedef struct addopnode AddOpNode;
typedef struct relopnode RelopNode;
typedef struct identlistnode IdentListNode;
typedef struct termnode TermNode;
typedef struct standtypenode StandTypeNode;
typedef struct compoundstatementnode CompoundStatementNode;
typedef struct varnode VarNode;
typedef struct statementnode StatementNode;
typedef struct subheadnode SubHeadNode;
typedef struct statementlistnode StatementListNode;
typedef struct subdeclarnode SubDeclarNode;
typedef struct subheadnode SubHeadNode;
typedef struct optionalstatementsnode OptionalStatementSNode;
typedef struct MulNode MulNode;
typedef struct statementlistnode StatementlistNode;
typedef struct prognode ProgNode;
typedef struct subdeclarsnode SubDeclarSNode;
typedef struct optionalvarnode OptionalVarNode;




//Addop

typedef struct addopnode{
    Node node;
    bool add;   
    
} AddOpNode;

AddOpNode* newAddOpNode( int, int, bool, int, int );

int AddOpNode_visit(void*);



//Argument

typedef struct argumentsnode{
    Node node;
    ParameterListNode* parameterlist;

} ArgumentsNode;

ArgumentsNode* newArgumentsNode( int, int, ParameterListNode*, int, int );

int ArgumentsNode_visit(void*);


//BoolExpression

typedef struct Boolexpressionnode{
    Node node;
    SimpleExpressionNode* first;
    RelopNode* relop;
    SimpleExpressionNode* least;

} BoolExpNode;

BoolExpNode* newBoolExpNode( int, int, SimpleExpressionNode*, RelopNode*, SimpleExpressionNode*, int, int );

int BoolExpNode_visit(void*);


//Compoundstatement

typedef struct compoundstatementnode{
    Node node;
    OptionalStatementSNode* statements;

} CompoundStatementNode;

int CompoundStatementNode_visit(void*);

CompoundStatementNode* newCompoundStatementNode( int, int, OptionalStatementSNode*, int, int );



//Decalartion

typedef struct declarnode{
    Node node;
    struct declarnode* NextNode;
    IdentListNode* identlistnode;
    TypeNode* typenode;

} DeclarNode;

DeclarNode* newDeclarNode( int, int, DeclarNode*, IdentListNode*, TypeNode*, int, int );

int DeclarNode_visit(void*);



//Expression

typedef struct expressionnode{
    Node node;
    int type;   // 0: bool, 1: bool AND bool, 2: bool OR bool
    BoolExpNode* first;
    BoolExpNode* least;
    
} ExpressionNode;

ExpressionNode* newExpNode( int, int, BoolExpNode*, int, BoolExpNode*, int, int );

int ExpNode_visit(void*);



//Expressionlist

typedef struct expressionlistnode{
    Node node;
    struct expressionlistnode* expressionlistnode;
    ExpressionNode* expressionnode;

} ExpressionListNode;

ExpressionListNode* newExpressionListNode( int, int, ExpressionListNode*, ExpressionNode*, int, int );

int ExpressionListNode_visit(void*);



//Identifierlist
typedef struct identlistnode{
    Node node;
    char* id;
    struct identlistnode* PrevNode;

} IdentListNode;

IdentListNode* newIdentListNode( int, int, char*, IdentListNode*, int, int );

int IdentListNode_visit(void*);



//Mulop
typedef struct MulNode{
    Node node;
    int type;
    
} MulNode;

MulNode* newMulNode( int, int, int, int, int );

int MulNode_visit(void*);


//Numop
typedef struct numnode{
    Node node;
    int type;
    double num;
    double exp;

} NumNode;

NumNode* newNumNode( int, int, int, double, char*, int, int );

int NumNode_visit(void*);



//Factor

typedef struct factornode{
    Node node;
    int type;
    char* id;
    TailNode* tailnode;
    ExpressionListNode* expressionlistnode;
    NumNode* num;
    ExpressionNode* expressionnode;
    struct factornode* factornode;
    
} FactorNode;

FactorNode* newFactorNode( int, int, int, char*, TailNode*, ExpressionListNode*, NumNode*, ExpressionNode*, FactorNode*, int, int );

int FactorNode_visit(void*);




//Optionalstatement
typedef struct optionalstatementsnode{
    Node node;
    StatementListNode* statementlistnode;

} OptionalStatementSNode;

OptionalStatementSNode* newOptionalStatementSNode( int, int, StatementListNode*, int, int );

int OptionalStatementSNode_visit(void*);




//OptionalVar
typedef struct optionalvarnode{
    Node node;
    
} OptionalVarNode;

int OptionalVarNode_visit(void*);

OptionalVarNode* newOptionalVarNode( int, int );



//Parameterlist

typedef struct parameterlistnode{
    Node node;
    OptionalVarNode* optionalvarnode;
    IdentListNode* identlistnode;
    TypeNode* typenode;
    struct parameterlistnode* NextNode;

} ParameterListNode;

ParameterListNode* newParameterListNode( int, int, OptionalVarNode*, IdentListNode*, TypeNode*, ParameterListNode*, int, int );

int ParameterListNode_visit(void*);



//Procedure
typedef struct procedurestatementnode{
    Node node;
    char* id;
    ExpressionListNode* expressionlistnode;

} ProcedureStatementNode;

ProcedureStatementNode* newProcedureStatementNode( int, int, char*, ExpressionListNode*, int, int );

int ProcedureStatementNode_visit(void*);



//Prog
ProgNode* newProgNode( int fl, int fc, char* id, IdentListNode* identlist, DeclarNode* declars, SubDeclarSNode* subdeclars, CompoundStatementNode* compoundstatement, int ll, int lc );

int ProgNode_visit();

typedef struct prognode{
    Node node;
    char* id;
    IdentListNode* identlist;
    DeclarNode* declar;
    SubDeclarSNode* subdeclar;
    CompoundStatementNode* compoundstatement;

} ProgNode;



//Relop
typedef struct relopnode{
    Node node;
    int type;

} RelopNode;

RelopNode* newRelopNode( int, int, int, int, int );

int RelopNode_visit(void*);



//SimpleExpression
typedef struct simpleexpressionnode{
    Node node;
    TermNode* termnode;
    SimpleExpressionNode* simpleexpressionnode;
    AddOpNode* addnode;

} SimpleExpressionNode;

SimpleExpressionNode* newSimpleExpressionNode( int, int, SimpleExpressionNode*, AddOpNode*, TermNode*, int, int );

int SimpleExpressionNode_visit(void*);


//StandardType
typedef struct standtypenode{
    Node node;
    int type; // 0: integer, 1: real, 2: string
} StandTypeNode;

int StandTypeNode_visit(void*);

StandTypeNode* newStandTypeNode( int, int, int, int, int );



//Statement
typedef struct statementnode{
    Node node;
    int type;
    VarNode* varnode;
    ExpressionNode* expressionnode;
    ProcedureStatementNode* procedurestatementnode;
    CompoundStatementNode* compoundstatementnode;
    struct statementnode* statementnode1;
    struct statementnode* statementnode2;

} StatementNode;

StatementNode* newStatementNode( int, int, int, VarNode*, ExpressionNode*, ProcedureStatementNode*, CompoundStatementNode*, StatementNode*, StatementNode*, int, int );

int StatementNode_visit(void*);


//StatementList

typedef struct statementlistnode{
    Node node;
    struct statementlistnode* nextList;
    StatementNode* statementnode;

} StatementListNode;

StatementListNode* newStatementListNode( int, int, struct statementlistnode*, StatementNode*, int, int );

int StatementListNode_visit(void*);




//Subprogramdecalartion
typedef struct subdeclarsnode{
    Node node;
    struct subdeclarsnode* PrevNode;
    struct subdeclarnode* NextNode;

} SubDeclarSNode;

typedef struct subdeclarnode{
    Node node;
    SubHeadNode* head;
    DeclarNode* declarnode;
    SubDeclarSNode* subdeclarsnode;
    CompoundStatementNode* compoundstatementnode;

} SubDeclarNode;

SubDeclarNode* newSubDeclarNode( int, int, SubHeadNode*, DeclarNode*, SubDeclarSNode*, CompoundStatementNode*, int, int );

int SubDeclarNode_visit(void*);

int SubDeclarSNode_visit(void*);

SubDeclarSNode* newSubDeclarSNode( int, int, SubDeclarSNode*, SubDeclarNode*, int, int );

int checkExist( StatementNode*, char* );



//Subprogramhead
typedef struct subheadnode{
    Node node;
    int type;   // 0: FUNCTION, 1: PROCEDURE
    char* id;
    StandTypeNode* standard_type;
    ArgumentsNode* arguments;

} SubHeadNode;

int SubHeadNode_visit(void*);

SubHeadNode* newSubHeadNode( int, int, int, char*, StandTypeNode*, ArgumentsNode*, int, int );



//Tail
typedef struct tailnode{
    Node node;
    ExpressionNode* expressionnode;
    struct tailnode* tailnode;
    
} TailNode;

TailNode* newTailNode( int, int, ExpressionNode*, TailNode*, int, int );

int TailNode_visit(void*);



//Term

typedef struct termnode{
    Node node;
    struct termnode* termnode;
    MulNode* mulnode;
    FactorNode* factornode;

} TermNode;

TermNode* newTermNode( int, int, TermNode*, MulNode*, FactorNode*, int, int );

int TermNode_visit(void*);



//Type

typedef struct typenode{
    Node node;
    StandTypeNode* standtypenode;
    int array_start;
    int array_end;
    struct typenode* type;
    
} TypeNode;

int TypeNode_visit(void*);

TypeNode* newTypeNode( int, int, StandTypeNode*, int, int, TypeNode*, int, int );





//Var
typedef struct varnode{
    Node node;
    char* id;
    TailNode* tailnode; 
    
} VarNode;

VarNode* newVarNode( int, int, char*, TailNode*, int, int );

int VarNode_visit(void*);









#endif