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
typedef struct Boolexpressionnode BoolExpNode;
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




typedef struct addopnode{
    Node node;
    bool add;   
    
} AddOpNode;

Node* newAddOpNode( int, int, bool, int, int );

void* AddOpNode_visit(void*);



//argument






typedef struct argumentsnode{
    Node node;
    ParameterListNode* parameterlist;

} ArgumentsNode;

Node* newArgumentsNode( int, int, ParameterListNode*, int, int );

void* ArgumentsNode_visit(void*);


//bool exp



typedef struct Boolexpressionnode{
    Node node;
    SimpleExpressionNode* first;
    RelopNode* relop;
    SimpleExpressionNode* least;

} BoolExpNode;

Node* newBoolExpNode( int, int, SimpleExpressionNode*, RelopNode*, SimpleExpressionNode*, int, int );

void* BoolExpNode_visit(void*);


//compoundstatement


typedef struct compoundstatementnode{
    Node node;
    OptionalStatementSNode* statements;

} CompoundStatementNode;

void* CompoundStatementNode_visit(void*);

Node* newCompoundStatementNode( int, int, OptionalStatementSNode*, int, int );



//DFeacalartion
// #include "ast.h"



typedef struct declarnode{
    Node node;
    struct declarnode* NextNode;
    IdentListNode* identlistnode;
    TypeNode* typenode;

} DeclarNode;

Node* newDeclarNode( int, int, DeclarNode*, IdentListNode*, TypeNode*, int, int );

void* DeclarNode_visit(void*);




//expss



typedef struct expressionnode{
    Node node;
    int type;   // 0: bool, 1: bool AND bool, 2: bool OR bool
    BoolExpNode* first;
    BoolExpNode* least;
    
} ExpressionNode;

Node* newExpNode( int, int, ExpressionNode*, int, ExpressionNode*, int, int );

void* ExpNode_visit(void*);

//explist



typedef struct expressionlistnode{
    Node node;
    struct expressionlistnode* expressionlistnode;
    ExpressionNode* expressionnode;

} ExpressionListNode;

Node* newExpressionListNode( int, int, ExpressionListNode*, ExpressionNode*, int, int );

void* ExpressionListNode_visit(void*);



//identifier
typedef struct identlistnode{
    Node node;
    char* id;
    struct identlistnode* PrevNode;

} IdentListNode;

Node* newIdentListNode( int, int, char*, IdentListNode*, int, int );

void* IdentListNode_visit(void*);



//mulop

typedef struct MulNode{
    Node node;
    int type;   // 0: *, 1: /
    
} MulNode;

Node* newMulNode( int, int, int, int, int );

void* MulNode_visit(void*);


//num
typedef struct numnode{
    Node node;
    int type;
    double num;
    double exp;

} NumNode;

Node* newNumNode( int, int, int, double, char*, int, int );

void* NumNode_visit(void*);



//factor


// #include "Expressionlist.h"
// #include "Expression.h"
// #include "Num.h"




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

Node* newFactorNode( int, int, int, char*, TailNode*, ExpressionListNode*, NumNode*, ExpressionNode*, FactorNode*, int, int );

void* FactorNode_visit(void*);

//identifierlist



//Mulop


//opt stt
typedef struct optionalstatementsnode{
    Node node;
    StatementListNode* statementlistnode;

} OptionalStatementSNode;

Node* newOptionalStatementSNode( int, int, StatementListNode*, int, int );

void* OptionalStatementSNode_visit(void*);




//opt var
typedef struct optionalvarnode{
    Node node;
    
} OptionalVarNode;

void* OptionalVarNode_visit(void*);

Node* newOptionalVarNode( int, int );

//paralist


typedef struct parameterlistnode{
    Node node;
    OptionalVarNode* optionalvarnode;
    IdentListNode* identlistnode;
    TypeNode* typenode;
    struct parameterlistnode* NextNode;

} ParameterListNode;

Node* newParameterListNode( int, int, OptionalVarNode*, IdentListNode*, TypeNode*, ParameterListNode*, int, int );

void* ParameterListNode_visit(void*);



//procedure
typedef struct procedurestatementnode{
    Node node;
    char* id;
    ExpressionListNode* expressionlistnode;

} ProcedureStatementNode;

Node* newProcedureStatementNode( int, int, char*, ExpressionListNode*, int, int );

void* ProcedureStatementNode_visit(void*);



//prog
Node* newProgNode( int firstLine, int firstColumn, char* id, IdentListNode* identlist, DeclarNode* declars, SubDeclarSNode* subdeclars, CompoundStatementNode* compoundstatement, int lastLine, int lastColumn );

void* ProgNode_visit();

typedef struct prognode{
    Node node;
    char* id;
    IdentListNode* identlist;
    DeclarNode* declar;
    SubDeclarSNode* subdeclar;
    CompoundStatementNode* compoundstatement;

} ProgNode;



//relop
typedef struct relopnode{
    Node node;
    int type;

} RelopNode;

Node* newRelopNode( int, int, int, int, int );

void* RelopNode_visit(void*);



//simple exp




typedef struct simpleexpressionnode{
    Node node;
    TermNode* termnode;
    SimpleExpressionNode* simpleexpressionnode;
    AddOpNode* addnode;

} SimpleExpressionNode;

Node* newSimpleExpressionNode( int, int, SimpleExpressionNode*, AddOpNode*, TermNode*, int, int );

void* SimpleExpressionNode_visit(void*);


//stdtyupe
typedef struct standtypenode{
    Node node;
    int type; // 0: integer, 1: real, 2: string
} StandTypeNode;

void* StandTypeNode_visit(void*);

Node* newStandTypeNode( int, int, int, int, int );



//sttmnt
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

Node* newStatementNode( int, int, int, VarNode*, ExpressionNode*, ProcedureStatementNode*, CompoundStatementNode*, StatementNode*, StatementNode*, int, int );

void* StatementNode_visit(void*);


//sttmnt list

typedef struct statementlistnode{
    Node node;
    struct statementlistnode* nextList;
    StatementNode* statementnode;

} StatementListNode;

Node* newStatementListNode( int, int, struct statementlistnode*, StatementNode*, int, int );

void* StatementListNode_visit(void*);




//subprogdecla


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

Node* newSubDeclarNode( int, int, SubHeadNode*, DeclarNode*, SubDeclarSNode*, CompoundStatementNode*, int, int );

void* SubDeclarNode_visit(void*);

void* SubDeclarSNode_visit(void*);

Node* newSubDeclarSNode( int, int, SubDeclarSNode*, SubDeclarNode*, int, int );

int checkExist( StatementNode*, char* );



//subproghead
typedef struct subheadnode{
    Node node;
    int type;   // 0: FUNCTION, 1: PROCEDURE
    char* id;
    StandTypeNode* standard_type;
    ArgumentsNode* arguments;

} SubHeadNode;

void* SubHeadNode_visit(void*);

Node* newSubHeadNode( int, int, int, char*, StandTypeNode*, ArgumentsNode*, int, int );



//tail


typedef struct tailnode{
    Node node;
    ExpressionNode* expressionnode;
    struct tailnode* tailnode;
    
} TailNode;

Node* newTailNode( int, int, ExpressionNode*, TailNode*, int, int );

void* TailNode_visit(void*);



//term

typedef struct termnode{
    Node node;
    struct termnode* termnode;
    MulNode* mulnode;
    FactorNode* factornode;

} TermNode;

Node* newTermNode( int, int, TermNode*, MulNode*, FactorNode*, int, int );

void* TermNode_visit(void*);



//type

typedef struct typenode{
    Node node;
    StandTypeNode* standtypenode;
    int array_start;
    int array_end;
    struct typenode* type;
    
} TypeNode;

void* TypeNode_visit(void*);

Node* newTypeNode( int, int, StandTypeNode*, int, int, TypeNode*, int, int );





//var
typedef struct varnode{
    Node node;
    char* id;
    TailNode* tailnode; 
    
} VarNode;

Node* newVarNode( int, int, char*, TailNode*, int, int );

void* VarNode_visit(void*);









#endif