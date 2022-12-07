#ifndef _LIB_H
#define _LIB_H


#include "ast.h"
// #include "addnode.h"
#include "argumentsnode.h"
#include "boolexpnode.h"
#include "compoundstatementnode.h"
#include "declarnode.h"
#include "explistnode.h"
#include "expnode.h"
#include "factornode.h"
#include "identlistnode.h"
#include "mulnode.h"
#include "optionalstatementsnode.h"
#include "optionalvarnode.h"
#include "parameterlistnode.h"
#include "procedstatementnode.h"
#include "prognode.h"
#include "relopnode.h"
#include "simpleexpnode.h"
#include "standtypenode.h"
#include "statementlistnode.h"
#include "statementnode.h"
#include "subdeclarnode.h"
#include "subheadnode.h"
#include "tailnode.h"
#include "termnode.h"
#include "typenode.h"
#include "varnode.h"
#include "numnode.h"

//========================
typedef struct addnode{
    Node node;
    int positive;   // 1: positive, 0: negative
    
} AddNode;

Node* newAddNode( int, int, int, int, int );

void* AddNode_visit(void*);

//==============================



typedef struct argumentsnode{
    Node node;
    ParameterListNode* parameterlist;

} ArgumentsNode;

Node* newArgumentsNode( int, int, ParameterListNode*, int, int );

void* ArgumentsNode_visit(void*);


//===============
typedef struct simpleexpnode SimpleExpNode;

typedef struct boolexpnode{
    Node node;
    SimpleExpNode* first;
    RelopNode* relop;
    SimpleExpNode* least;

} BoolExpNode;

Node* newBoolExpNode( int, int, SimpleExpNode*, RelopNode*, SimpleExpNode*, int, int );

void* BoolExpNode_visit(void*);
//================


typedef struct optionalstatementsnode OptionalStatementSNode;

typedef struct compoundstatementnode{
    Node node;
    OptionalStatementSNode* statements;

} CompoundStatementNode;

void* CompoundStatementNode_visit(void*);

Node* newCompoundStatementNode( int, int, OptionalStatementSNode*, int, int );
//===================

// #include "ast.h"
// #include "typenode.h"
// #include "identlistnode.h"

typedef struct declarnode{
    Node node;
    struct declarnode* NextNode;
    IdentListNode* identlistnode;
    TypeNode* typenode;

} DeclarNode;

Node* newDeclarNode( int, int, DeclarNode*, IdentListNode*, TypeNode*, int, int );

void* DeclarNode_visit(void*);

//===================

// #include "ast.h"
// #include "expnode.h"

typedef struct expnode ExpNode;

typedef struct explistnode{
    Node node;
    struct explistnode* explistnode;
    ExpNode* expnode;

} ExpListNode;

Node* newExpListNode( int, int, ExpListNode*, ExpNode*, int, int );

void* ExpListNode_visit(void*);


//===================



// #include "ast.h"
// #include "boolexpnode.h"

typedef struct boolexpnode BoolExpNode;

typedef struct expnode{
    Node node;
    int type;   // 0: bool, 1: bool AND bool, 2: bool OR bool
    BoolExpNode* first;
    BoolExpNode* least;
    
} ExpNode;

Node* newExpNode( int, int, ExpNode*, int, ExpNode*, int, int );

void* ExpNode_visit(void*);


//===================

// #include "ast.h"
// #include "tailnode.h"
// #include "explistnode.h"
// #include "expnode.h"
// #include "numnode.h"

typedef struct tailnode TailNode;
typedef struct explistnode ExpListNode;
typedef struct expnode ExpNode;

typedef struct factornode{
    Node node;
    int type;
    char* id;
    TailNode* tailnode;
    ExpListNode* explistnode;
    NumNode* num;
    ExpNode* expnode;
    struct factornode* factornode;
    
} FactorNode;

Node* newFactorNode( int, int, int, char*, TailNode*, ExpListNode*, NumNode*, ExpNode*, FactorNode*, int, int );

void* FactorNode_visit(void*);

//===================



typedef struct identlistnode{
    Node node;
    char* id;
    struct identlistnode* PrevNode;

} IdentListNode;

Node* newIdentListNode( int, int, char*, IdentListNode*, int, int );

void* IdentListNode_visit(void*);



//===================


#include <stdio.h>
#include <stdlib.h>

#include "info.h"

typedef enum{ Int, Void, Real, String, Array } returnType;

typedef enum{ Function, Data } dataType;

typedef struct SymbolObj{
    returnType type;
} symbolobj;

typedef struct ArraySymbolObj{
    returnType type;
    symbolobj* data;
    int start;
    int end;
} arraysymbolobj;

typedef struct PassInObj{
    symbolobj* data;
    symbolobj* next;
} passinobj;

typedef struct FuncSymbolObj{
    returnType type;
    symbolobj* passInType;
    int check;
} funcsymbolobj;

typedef struct List{
    dataType nodeType;
    char* id;
    int scope;
    symbolobj* data;
    struct List* next;
    struct List* prev;
} list;

void list_push_back( list*, list* );

list* newdatalist( char*, int, returnType, dataType );

list* newarraylist( char*, int, returnType, dataType );

list* newfunclist( char*, int, returnType, dataType );

void list_printTable( list* );

int checkList( list*, char*, int, dataType );

void listRemove( list*, int );

int GetList( list* , list**, char* );




//===================



typedef struct MulNode{
    Node node;
    int type;   // 0: *, 1: /
    
} MulNode;

Node* newMulNode( int, int, int, int, int );

void* MulNode_visit(void*);

//===================



typedef struct numnode{
    Node node;
    int type;
    double num;
    double exp;

} NumNode;

Node* newNumNode( int, int, int, double, char*, int, int );

void* NumNode_visit(void*);

//===================

// #include "statementlistnode.h"

typedef struct statementlistnode StatementlistNode;

typedef struct optionalstatementsnode{
    Node node;
    StatementlistNode* statementlistnode;

} OptionalStatementSNode;

Node* newOptionalStatementSNode( int, int, StatementlistNode*, int, int );

void* OptionalStatementSNode_visit(void*);


//===================



typedef struct optionalvarnode{
    Node node;
    
} OptionalVarNode;

void* OptionalVarNode_visit(void*);

Node* newOptionalVarNode( int, int );


//===================

// #include "optionalvarnode.h"
// #include "identlistnode.h"
// #include "typenode.h"

typedef struct parameterlistnode{
    Node node;
    OptionalVarNode* optionalvarnode;
    IdentListNode* identlistnode;
    TypeNode* typenode;
    struct parameterlistnode* NextNode;

} ParameterListNode;

Node* newParameterListNode( int, int, OptionalVarNode*, IdentListNode*, TypeNode*, ParameterListNode*, int, int );

void* ParameterListNode_visit(void*);


//===================


// #include "explistnode.h"

typedef struct procedstatementnode{
    Node node;
    char* id;
    ExpListNode* explistnode;

} ProcedStatementNode;

Node* newProcedStatementNode( int, int, char*, ExpListNode*, int, int );

void* ProcedStatementNode_visit(void*);

//===================


// #include "identlistnode.h"
// #include "declarnode.h"
// #include "subdeclarnode.h"
// #include "compoundstatementnode.h"

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

//===================

typedef struct relopnode{
    Node node;
    int type;

} RelopNode;

Node* newRelopNode( int, int, int, int, int );

void* RelopNode_visit(void*);


//===================

// #include "simpleexpnode.h"
// #include "Addnode.h"
// #include "termnode.h"

typedef struct termnode TermNode;
typedef struct simpleexpnode SimpleExpNode;
// typedef struct addnode AddNode;

typedef struct simpleexpnode{
    Node node;
    TermNode* termnode;
    SimpleExpNode* simpleexpnode;
    AddNode* addnode;

} SimpleExpNode;

Node* newSimpleExpNode( int, int, SimpleExpNode*, AddNode*, TermNode*, int, int );

void* SimpleExpNode_visit(void*);


//===================


typedef struct standtypenode{
    Node node;
    int type; // 0: integer, 1: real, 2: string
} StandTypeNode;

void* StandTypeNode_visit(void*);

Node* newStandTypeNode( int, int, int, int, int );

//===================

// #include "statementnode.h"

typedef struct statementnode StatementNode;

typedef struct statementlistnode{
    Node node;
    struct statementlistnode* nextList;
    StatementNode* statementnode;

} StatementListNode;

Node* newStatementListNode( int, int, struct statementlistnode*, StatementNode*, int, int );

void* StatementListNode_visit(void*);


//===================


// #include "varnode.h"
// #include "expnode.h"
// #include "procedstatementnode.h"
// #include "compoundstatementnode.h"

typedef struct compoundstatementnode CompoundStatementNode;

typedef struct statementnode{
    Node node;
    int type;
    VarNode* varnode;
    ExpNode* expnode;
    ProcedStatementNode* procedstatementnode;
    CompoundStatementNode* compoundstatementnode;
    struct statementnode* statementnode1;
    struct statementnode* statementnode2;

} StatementNode;

Node* newStatementNode( int, int, int, VarNode*, ExpNode*, ProcedStatementNode*, CompoundStatementNode*, StatementNode*, StatementNode*, int, int );

void* StatementNode_visit(void*);


//===================

// #include "subheadnode.h"
// #include "declarnode.h"
// #include "compoundstatementnode.h"

struct subdeclarnode;

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


//===================

// #include "standtypenode.h"
// #include "argumentsnode.h"

typedef struct subheadnode{
    Node node;
    int type;   // 0: FUNCTION, 1: PROCEDURE
    char* id;
    StandTypeNode* standard_type;
    ArgumentsNode* arguments;

} SubHeadNode;

void* SubHeadNode_visit(void*);

Node* newSubHeadNode( int, int, int, char*, StandTypeNode*, ArgumentsNode*, int, int );


//===================

// #include "expnode.h"
// #include "tailnode.h"

typedef struct expnode ExpNode;

typedef struct tailnode{
    Node node;
    ExpNode* expnode;
    struct tailnode* tailnode;
    
} TailNode;

Node* newTailNode( int, int, ExpNode*, TailNode*, int, int );

void* TailNode_visit(void*);


//===================
typedef struct factornode FactorNode;

typedef struct termnode{
    Node node;
    struct termnode* termnode;
    MulNode* mulnode;
    FactorNode* factornode;

} TermNode;

Node* newTermNode( int, int, TermNode*, MulNode*, FactorNode*, int, int );

void* TermNode_visit(void*);

//===================
typedef struct typenode{
    Node node;
    StandTypeNode* standtypenode;
    int array_start;
    int array_end;
    struct typenode* type;
    
} TypeNode;

void* TypeNode_visit(void*);

Node* newTypeNode( int, int, StandTypeNode*, int, int, TypeNode*, int, int );

//===================
typedef struct varnode{
    Node node;
    char* id;
    TailNode* tailnode; 
    
} VarNode;

Node* newVarNode( int, int, char*, TailNode*, int, int );

void* VarNode_visit(void*);

//===================


//===================


//===================


//===================


//===================


//===================


//===================


//===================


//===================


#endif