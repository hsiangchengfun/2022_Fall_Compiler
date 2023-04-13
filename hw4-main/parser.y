%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "loc.h"
#include "ast.h"
#include "error.h"
#include "codegen.h"

#define YYLTYPE LocType

#define MAX_LINE_LENG      256
extern int line_no, col_no, opt_list;
extern char buffer[MAX_LINE_LENG];
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */
extern int yyleng;

int pass_error = 0;
extern char *output = NULL;
static Node* root = NULL;
int scope = 0;


FILE *input_file;
FILE *output_file;



extern
#ifdef __cplusplus
"C"
#endif
int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);

%}

%locations

%token PROGRAM VAR ARRAY OF INTEGER REAL STRING FUNCTION PROCEDURE PBEGIN END IF THEN ELSE WHILE DO NOT AND OR

%token LPAREN RPAREN SEMICOLON DOT COMMA COLON LBRACE RBRACE DOTDOT ASSIGNMENT ADDOP SUBOP MULOP DIVOP LTOP GTOP EQOP GETOP LETOP NEQOP

%token IDENTIFIER REALNUMBER INTEGERNUM SCIENTIFIC LITERALSTR 

%code requires{
    #include "ast.h"
    #include "lib.h"
}

%union {
    int val;
    char* text;
    double dval;
    Node* node;
    ProgNode* ProgNode;
    ParameterListNode* ParameterListNode;
    IdentListNode* IdentListNode; 
    ProcedureStatementNode* ProcedureStatementNode;
    TypeNode* TypeNode;
    SimpleExpressionNode* SimpleExpressionNode;
    BoolExpNode* BoolExpNode;
    TailNode* TailNode;
    FactorNode* FactorNode;
    NumNode* NumNode;
    ExpressionListNode* ExpressionListNode;
    ExpressionNode* ExpressionNode;
    DeclarNode* DeclarNode;
    ArgumentsNode* ArgumentsNode;
    AddOpNode* AddOpNode;
    RelopNode* RelopNode;
    TermNode* TermNode;
    StandTypeNode* StandTypeNode;
    CompoundStatementNode* CompoundStatementNode;
    VarNode* VarNode;
    StatementNode* StatementNode;
    SubHeadNode* SubHeadNode;
    StatementListNode* StatementListNode;
    SubDeclarNode* SubDeclarNode;
    OptionalStatementSNode* OptionalStatementSNode;
    MulNode* MulNode;
    StatementlistNode* StatementlistNode;
    SubDeclarSNode* SubDeclarSNode;
    OptionalVarNode* OptionalVarNode;

}

%type <ProgNode> prog 
%type <IdentListNode> identifier_list 
%type <DeclarNode> declarations 
%type <SubDeclarSNode> subprogram_declarations 
%type <CompoundStatementNode> compound_statement 
%type <TypeNode> type 
%type <StandTypeNode> standard_type 
%type <SubDeclarNode> subprogram_declaration 
%type <SubHeadNode> subprogram_head 
%type <ArgumentsNode> arguments 
%type <ParameterListNode> parameter_list 
%type <OptionalVarNode>optional_var 
%type <OptionalStatementSNode> optional_statements 
%type <StatementListNode> statement_list 
%type <StatementNode> statement 
%type <VarNode> variable 
%type <TailNode> tail 
%type <ProcedureStatementNode> procedure_statement 
%type <ExpressionListNode> expression_list 
%type <ExpressionNode> expression 
%type <BoolExpNode> boolexpression 
%type <SimpleExpressionNode> simple_expression 
%type <TermNode> term 
%type <FactorNode> factor 
%type <AddOpNode> addop 
%type <MulNode> mulop 
%type <RelopNode> relop 
%type <NumNode> num 
/* %type <text>IDENTIFIER */
%type <text>  IDENTIFIER SCIENTIFIC LITERALSTR LPAREN RPAREN SEMICOLON DOT COMMA COLON LBRACE RBRACE DOTDOT ASSIGNMENT ADDOP SUBOP MULOP DIVOP LTOP GTOP EQOP GETOP LETOP NEQOP
%type <val> INTEGERNUM
%type <dval> REALNUMBER

%start prog
%%

    /* define your snytax here */
    /* @n return the sturct LocType of "n-th node", ex: @1 return the PROGRAM node's locType
       $n return the $$ result you assigned to the rule, ex: $1 */
prog: PROGRAM IDENTIFIER LPAREN identifier_list 
      RPAREN SEMICOLON declarations 
      subprogram_declarations 
      compound_statement DOT { 
        int fl,fc,ll,lc;
        fl=@1.first_line;
        fc=@1.first_column;
        ll=@10.first_line;
        lc=@10.first_column;
        root = (Node*)newProgNode( fl ,fc , $2, $4, $7, $8, $9, ll, lc );
        // addChild($$,$2);
        
    }
    ;

identifier_list: IDENTIFIER { 
                  $$ = newIdentListNode( @1.first_line, @1.first_column, $1, NULL, @1.first_line, @1.first_column ); 
        
                }
                | IDENTIFIER COMMA identifier_list { 
                  $$ = newIdentListNode( @1.first_line, @1.first_column, $1, $3, @1.first_line, @1.first_column ); 
                }
    ;

declarations: declarations VAR 
              identifier_list COLON 
              type SEMICOLON { 
                $$ = newDeclarNode( @1.first_line, @1.first_column, $1, $3, $5, @6.first_line, @6.first_column ); 
              }
              | { 
                $$ = NULL; 
              }
    ;

type: standard_type {
                $$ = newTypeNode( @1.first_line, @1.first_column, $1, 0, 0, NULL, @1.first_line, @1.first_column ); 
                 }
    | ARRAY LBRACE INTEGERNUM DOTDOT INTEGERNUM RBRACE OF type { 
                $$ = newTypeNode( @1.first_line, @1.first_column, NULL, $3, $5, $8, @8.first_line, @8.first_column ); 
                }
    ;

num: REALNUMBER { 
            $$ = newNumNode( @1.first_line, @1.first_column, 0, $1, NULL, @1.first_line, @1.first_column ); 
            }
    | INTEGERNUM { 
            $$ = newNumNode( @1.first_line, @1.first_column, 1, $1, NULL, @1.first_line, @1.first_column ); 
            }
    | SCIENTIFIC { 
            $$ = newNumNode( @1.first_line, @1.first_column, 2, 0, $1, @1.first_line, @1.first_column ); 
            }
    ;

standard_type: INTEGER { 
                      $$ = newStandTypeNode( @1.first_line, @1.first_column, 0, @1.first_line, @1.first_column ); 
                      }
              | REAL { 
                      $$ = newStandTypeNode( @1.first_line, @1.first_column, 1, @1.first_line, @1.first_column );
                      }
              | STRING { 
                      $$ = newStandTypeNode( @1.first_line, @1.first_column, 2, @1.first_line, @1.first_column ); 
                      }
    ;

subprogram_declarations: subprogram_declarations subprogram_declaration SEMICOLON { 
                      $$ = newSubDeclarSNode( @1.first_line, @1.first_column, $1, $2, @3.first_line, @3.first_column ); 
                      }
                    | { 
                      $$ = NULL;
                       }
    ;

subprogram_declaration: subprogram_head declarations subprogram_declarations compound_statement { 
                        
                        $$ = newSubDeclarNode( @1.first_line, @1.first_column, $1, $2, $3, $4, @4.first_line, @4.first_column ); 
                        }
    ;

subprogram_head: FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON {
                         $$ = newSubHeadNode( @1.first_line, @1.first_column, 0, $2, $5, $3, @6.first_line, @6.first_column ); 
                         
                         }
                | PROCEDURE IDENTIFIER arguments SEMICOLON { 
                        $$ = newSubHeadNode( @1.first_line, @1.first_column, 1, $2, NULL, $3, @4.first_line, @4.first_column ); 
                        }
    ;

arguments: LPAREN parameter_list RPAREN { 
                        $$ = newArgumentsNode( @1.first_line, @1.first_column, $2, @3.first_line, @3.first_column ); 
                        }
                    | { 
                        $$ = NULL; 
                      }
    ;

parameter_list: optional_var identifier_list COLON type { 
                        $$ = newParameterListNode( @1.first_line, @1.first_column, $1, $2, $4, NULL, @4.first_line, @4.first_column ); 
                        
                        }
                | optional_var identifier_list COLON type SEMICOLON parameter_list { 
                        $$ = newParameterListNode( @1.first_line, @1.first_column, $1, $2, $4, $6, @6.first_line, @6.first_column ); 
                        }
    ;

optional_var: VAR { 
                  $$ = newOptionalVarNode( @1.first_line, @1.first_column ); 
                  }
                | { 
                  $$ = NULL; 
                  }
    ;

compound_statement: PBEGIN optional_statements END {  
                  $$ = newCompoundStatementNode( @1.first_line, @1.first_column, $2, @3.first_line, @3.first_column ); 
                  }
    ;

optional_statements: statement_list { 
                  $$ = newOptionalStatementSNode( @1.first_line, @1.first_column, $1, @1.first_line, @1.first_column ); 
                  }
                | { 
                  $$ = NULL; 
                  }
    ;

statement_list: statement { 
                  $$ = newStatementListNode( @1.first_line, @1.first_column, NULL, $1, @1.first_line, @1.first_column ); 
                  }
                | statement_list SEMICOLON statement {  
                  $$ = newStatementListNode( @1.first_line, @1.first_column, $1, $3, @1.first_line, @1.first_column ); 
                  }
    ;

statement: variable ASSIGNMENT expression { 
                  $$ = newStatementNode( @1.first_line, @1.first_column, 0, $1, $3, NULL, NULL, NULL, NULL, @3.first_line, @3.first_column ); 
                }
                | procedure_statement { 
                    $$ = newStatementNode( @1.first_line, @1.first_column, 1, NULL, NULL, $1, NULL, NULL, NULL, @1.first_line, @1.first_column ); 
                    }
                | compound_statement { 
                    $$ = newStatementNode( @1.first_line, @1.first_column, 2, NULL, NULL, NULL, $1, NULL, NULL, @1.first_line, @1.first_column ); 
                    }
                | IF expression THEN statement ELSE statement { 
                    $$ = newStatementNode( @1.first_line, @1.first_column, 3, NULL, $2, NULL, NULL, $4, $6, @6.first_line, @6.first_column ); 
                    
                    }
                | WHILE expression DO statement { 
                    $$ = newStatementNode( @1.first_line, @1.first_column, 4, NULL, $2, NULL, NULL, $4, NULL, @4.first_line, @4.first_column ); 
                    }
                | { 
                  $$ = NULL; 
                  }
    ;

variable: IDENTIFIER tail {   
                  $$ = newVarNode( @1.first_line, @1.first_column, $1, $2, @2.first_line, @2.first_column ); 
                  
                  }
    ;

tail: LBRACE expression RBRACE tail { 
                $$ = newTailNode( @1.first_line, @1.first_column, $2, $4, @4.first_line, @4.first_column ); 
                }
            | { 
                $$ = NULL; 
                }
    ;

procedure_statement: IDENTIFIER { 
                      $$ = newProcedureStatementNode( @1.first_line, @1.first_column, $1, NULL, @1.first_line, @1.first_column ); 
                      }
                    | IDENTIFIER LPAREN expression_list RPAREN {  
                        $$ = newProcedureStatementNode( @1.first_line, @1.first_column, $1, $3, @4.first_line, @4.first_column ); 
                        
                        }
    ;

expression_list: expression { 
                      $$ = newExpressionListNode( @1.first_line, @1.first_column, NULL, $1, @1.first_line, @1.first_column ); 
                      
                      }
                | expression_list COMMA expression { 
                      $$ = newExpressionListNode( @1.first_line, @1.first_column, $1, $3, @3.first_line, @3.first_column ); 
                      
                      }
    ;

expression: boolexpression { 
                $$ = newExpNode( @1.first_line, @1.first_column, $1, 0, NULL, @1.first_line, @1.first_column ); 
                }
          | boolexpression AND boolexpression { 
                $$ = newExpNode( @1.first_line, @1.first_column, $1, 1, $3, @3.first_line, @3.first_column ); 
                }
          | boolexpression OR boolexpression { 
                $$ = newExpNode( @1.first_line, @1.first_column, $1, 2, $3, @3.first_line, @3.first_column ); 
                }
    ;

boolexpression: simple_expression { 
                  $$ = newBoolExpNode( @1.first_line, @1.first_column, $1, NULL, NULL, @1.first_line, @1.first_column ); 
                  }
              | simple_expression relop simple_expression { 
                  $$ = newBoolExpNode( @1.first_line, @1.first_column, $1, $2, $3, @3.first_line, @3.first_column ); 
                  }
    ;

simple_expression: term { 
                    $$ = newSimpleExpressionNode( @1.first_line, @1.first_column, NULL, NULL, $1, @1.first_line, @1.first_column ); 
                    }
                  | simple_expression addop term { 
                    $$ = newSimpleExpressionNode( @1.first_line, @1.first_column, $1, $2, $3, @3.first_line, @3.first_column ); 
                    }
    ;

term: factor { 
                $$ = newTermNode( @1.first_line, @1.first_column, NULL, NULL, $1, @1.first_line, @1.first_column ); 
                }
    | term mulop factor { 
                $$ = newTermNode( @1.first_line, @1.first_column, $1, $2, $3, @3.first_line, @3.first_column ); 
                }
    ;

factor: IDENTIFIER tail { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 0, $1, $2, NULL, NULL, NULL, NULL, @2.first_line, @2.first_column ); 
                }
          | IDENTIFIER LPAREN expression_list RPAREN { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 1, $1, NULL, $3, NULL, NULL, NULL, @4.first_line, @4.first_column ); 
                }
          | num { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 2, NULL, NULL, NULL, $1, NULL, NULL, @1.first_line, @1.first_column ); 
                }
          | LITERALSTR { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 3, $1, NULL, NULL, NULL, NULL, NULL, @1.first_line, @1.first_column ); 
                }
          | LPAREN expression RPAREN { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 4, NULL, NULL, NULL, NULL, $2, NULL, @3.first_line, @3.first_column ); 
                }
          | NOT factor { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 5, NULL, NULL, NULL, NULL, NULL, NULL, @2.first_line, @2.first_column ); 
                }
          | SUBOP factor { 
                $$ = newFactorNode( @1.first_line, @1.first_column, 6, NULL, NULL, NULL, NULL, NULL, $2, @2.first_line, @2.first_column ); 
                
                }
    ;

addop: ADDOP {  
                  $$ = newAddOpNode( @1.first_line, @1.first_column, 1, @1.first_line, @1.first_column ); 
                  }
      | SUBOP { 
                  $$ = newAddOpNode( @1.first_line, @1.first_column, 0, @1.first_line, @1.first_column ); 
                  }
    ;

mulop: MULOP {  
                  $$ = newMulNode( @1.first_line, @1.first_column, 0, @1.first_line, @1.first_column ); 
                  }
    | DIVOP {   
                  $$ = newMulNode( @1.first_line, @1.first_column, 1, @1.first_line, @1.first_column ); 
                  }
    ;

relop: LTOP { 
                  $$ = newRelopNode( @1.first_line, @1.first_column, 0, @1.first_line, @1.first_column ); 
                  }
    | GTOP {  
                  $$ = newRelopNode( @1.first_line, @1.first_column, 1, @1.first_line, @1.first_column ); 
                  }
    | EQOP { 
                  $$ = newRelopNode( @1.first_line, @1.first_column, 2, @1.first_line, @1.first_column ); 
                  }
    | GETOP { 
                  $$ = newRelopNode( @1.first_line, @1.first_column, 3, @1.first_line, @1.first_column ); 
                  }
    | LETOP { 
                  $$ = newRelopNode( @1.first_line, @1.first_column, 4, @1.first_line, @1.first_column ); 
                  }
    | NEQOP {   
                  $$ = newRelopNode( @1.first_line, @1.first_column, 5, @1.first_line, @1.first_column ); 
                  }
    ;



%%
void yyerror(const char *msg) {
    fprintf(stderr,
            "[ERROR] line %4d:%3d %s, Unmatched token: %s\n",
            line_no, col_no - yyleng, buffer, yytext);
    pass_error = 1;
}

int main(int argc, char *argv[]) {

    char c;
    while((c=getopt(argc, argv, "o:")) != -1){
      switch(c){
        case 'o':
          output = optarg;
          break;
        case '?':
            fprintf(stderr, "Illegal option:-%c\n", isprint(optopt)?optopt:'#');
            break;
        default:
            fprintf( stderr, "Usage: %s [-o output] filename\n", argv[0]), exit(0);
            break;
      }
    }

    FILE *fp = argc == 1 ? stdin : fopen(argv[optind], "r");

    if(fp == NULL)
        fprintf( stderr, "Open file error\n" ), exit(-1);

    yyin = fp;
    yyparse();
    /* char fn[128]; 
    FILE *fd;
    fd = fopen(output , "w+"); */
    /* fprintf(fd,".class public foo\n.super java/lang/Object\n"); */
    /* fclose(fd); */
    if(!pass_error && root){
      
      GENCODE(root);
      root->visit(root);
    
      // do pass here
    }


    
    return 0;
}
