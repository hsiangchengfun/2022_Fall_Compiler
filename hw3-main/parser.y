%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "loc.h"
#include "node.h"
#include "node.c"
#include "error.h"
#include "info.h"
#include "symtab.h"
#include "symtab.c"

#define YYLTYPE LocType


// stderr
#define print_REDEF_FUN do { fprintf(stderr,REDEF_FUN,line_no,col_no,buffer); } while(0)
#define print_REDEF_ARG do { fprintf(stderr,REDEF_ARG,line_no,col_no,buffer); } while(0)
#define print_REDEF_VAR do { fprintf(stderr,REDEF_VAR,line_no,col_no,buffer); } while(0)
#define print_UNDEC_VAR do { fprintf(stderr,UNDEC_VAR,line_no,col_no,buffer); } while(0)
#define print_UNDEC_FUN do { fprintf(stderr,UNDEC_FUN,line_no,col_no,buffer); } while(0)
#define print_ARITH_TYPE do { fprintf(stderr,ARITH_TYPE,line_no,col_no,buffer); } while(0)
#define print_ASSIG_TYPE do { fprintf(stderr,ASSIG_TYPE,line_no,col_no,buffer); } while(0)
#define print_INDEX_TYPE do { fprintf(stderr,INDEX_TYPE,line_no,col_no,buffer); } while(0)
#define print_INDEX_MANY do { fprintf(stderr,INDEX_MANY,line_no,col_no,buffer); } while(0)
#define print_WRONG_ARGS do { fprintf(stderr,WRONG_ARGS,line_no,col_no,buffer); } while(0)
#define print_RETURN_VAL do { fprintf(stderr,RETURN_VAL,line_no,col_no,buffer); } while(0)


//stdin
#define print_SHOW_NEWSYM do { SHOW_NEWSYM(buffer); } while(0)
#define print_SHOW_NEWSCP do { SHOW_NEWSCP(); } while(0)
#define print_SHOW_CLSSCP do { SHOW_CLSSCP(); } while(0)
#define print_SHOW_SYMTAB_HEAD do { SHOW_SYMTAB_HEAD(); } while(0)
#define print_SHOW_SYMTAB_TAIL do { SHOW_SYMTAB_TAIL(); } while(0)
#define print_SYMTAB_ENTRY_FMT do { printf(SYMTAB_ENTRY_FMT,"ayh3",200,"sey"); } while(0)


#define MAX_LINE_LENG      256
extern int line_no, col_no, opt_list;
extern char buffer[MAX_LINE_LENG];
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */
extern int yyleng;

struct nodeType* ASTROOT = NULL;

extern
#ifdef __cplusplus
"C"
#endif
int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);
struct nodeType* newOpNode(int op);
%}

%locations

%union {
  int val;
  char* text;
  double dval;
  double sval;
  struct nodeType *node;
  char* string;
}

%token <node> PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE  
%token <node> END ARRAY VAR NOT STRING ASSIGNMENT COLON COMMA INTEGER AND OR
%token <node> DOT DOTDOT GETOP GTOP LBRACE LETOP LPAREN LTOP ADDOP MULOP DIVOP EQOP NEQOP
%token <node>   RBRACE REAL RPAREN SEMICOLON     PBEGIN  SUBOP
%token <node>  NODE_TOKEN 

%token <node> INTEGERNUM 
%token <node> REALNUMBER 
%token <node> SCIENTIFIC
%token <node> IDENTIFIER LITERALSTR

%type <node> prog
%type <node> identifier_list declarations type standard_type subprogram_declarations
%type <node> subprogram_declaration subprogram_head arguments parameter_list optional_var
%type <node> compound_statement optional_statements statement_list statement variable
%type <node> tail procedure_statement expression_list expression simple_expression term
%type <node> factor addop mulop relop  boolexpression num 

%%

    /* define your snytax here */
    /* @n return the sturct LocType of "n-th node", ex: @1 return the PROGRAM node's locType
       $n return the $$ result you assigned to the rule, ex: $1 */
prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON
     declarations
     subprogram_declarations
     compound_statement
     DOT {
            // struct nodeType* id;
            // id = newNode(NODE_IDENTIFIER);
            // id->string = $2;
            // printf("gdsgsdg %s\n",id->string);
            
            $$=newNode(NODE_prog);
            addChild($$,newNode(NODE_PROGRAM));
            
            addChild($$,$2);
            addChild($$,newNode(NODE_LPAREN));
            addChild($$,$4);
            addChild($$,newNode(NODE_RPAREN));
            // printf("type %d\n",$4->lineno);
            addChild($$,$7);
            addChild($$,$8);
            addChild($$,$9);
            ASTROOT = $$;

            // deleteNode($1);
            // deleteNode($3);
            // deleteNode($5);
            // deleteNode($6);
            // deleteNode($10);
	    	// printf("Reduction(prog -> PROGRAM ID ( identifier_list ) ; declartions subprogram_declartions");
	    	// printf("compound_statement.)\n");	

        /*
        printf("program node is @ line: %d, column: %d\n",
                    @1.first_line, @1.first_column);
        yylval.val, yylval.text, yylval.dval to get the data (type defined in %union) you assigned by scanner.
        */
    }
;

identifier_list : IDENTIFIER{

                    $$=newNode(NODE_identifier_list);
                    // struct nodeType* id;
                    // id = newNode(NODE_IDENTIFIER);
                    // id->string = $1;
                    // printf("%s\n");
                    addChild($$,$1);
                    // printf("Reduction(identifier_list -> ID1)\n");
                }
                | identifier_list COMMA IDENTIFIER{
                   $$=newNode(NODE_identifier_list);
                  addChild($$,$1);
                  addChild($$,newNode(NODE_COMMA));
                  // struct nodeType* id;
                  // id = newNode(NODE_IDENTIFIER);
                  // id->string = $3;
                  addChild($$,$3);
                  deleteNode($2);

                    // printf("Reduction(identifier_list -> identifier_list , ID)\n");
                }
;

declarations : declarations VAR identifier_list COLON type SEMICOLON{
            $$=newNode(NODE_declarations);
            // printf("here declare \n");
            addChild($$,$1);
            addChild($$,newNode(NODE_VAR));
            addChild($$,$3);
            addChild($$,newNode(NODE_COLON));
            addChild($$,$5);
            // deleteNode($2);
            // deleteNode($4);
            // deleteNode($6);
			// printf("Reduction(declartions -> declarations VAR identifier_list : type ;)\n");
		}
	| {
			$$=newNode(NODE_declarations);
			// printf("Reduction(declartions -> )\n");
		}
;

type : standard_type{
        $$=newNode(NODE_type);
        // $$=$1;
        addChild($$,$1);
    //   printf("Reduction(type -> standard_type)\n");
    }
     | ARRAY LBRACE num DOTDOT num RBRACE OF type{ 
      
        // struct nodeType* n;
        // struct nodeType* n2;
        // n = newNode(NODE_NUM);
        // n2 = newNode(NODE_NUM);
        $$=newNode(NODE_type);
        // $$=$1;
        addChild($$,newNode(NODE_ARRAY));
        addChild($$,newNode(NODE_LBRACE));
        // n->rValue = $3->rValue;
        addChild($$,$3);
        addChild($$,newNode(NODE_DOTDOT));


        // $$->nodeType=NODE_TYPE_ARRAY;
        // $3->nodeType = NODE_num;//init value
        // addChild($$,$3);
        // $5->nodeType = NODE_num;//size of array
        // n2->rValue = $5->rValue;
        addChild($$,$5);
        addChild($$,newNode(NODE_RBRACE));
        addChild($$,newNode(NODE_OF));
        addChild($$,$8);


        // deleteNode($2);
        // deleteNode($4);
        // deleteNode($6);
        // deleteNode($7);
    //   printf("Reduction(type -> ARRAY ( NUM .. NUM ) OF type)\n");
    }
;

num : INTEGERNUM{
			$$=newNode(NODE_num);
      // struct nodeType* integer;
      // integer = newNode(NODE_INTEGERNUM);
      // integer->iValue = $1;
      // printf("%d\n",$1);
			addChild($$,$1);
			// printf("Reduction(standard_type -> INTEGER)\n");
		}
	| REALNUMBER{
			$$=newNode(NODE_num);
      // struct nodeType* realnum;
      // realnum = newNode(NODE_REALNUMBER);
      // realnum->rValue = $1;
			addChild($$,$1);
			// addChild($$,newNode(NODE_REALNUMBER));
			// printf("Reduction(standard_type -> REAL)\n");
		}
    | SCIENTIFIC{
    		$$=newNode(NODE_num);
			  // struct nodeType* scientific;
        // scientific = newNode(NODE_SCIENTIFIC);
        // scientific->sValue = $1;
        addChild($$,$1);
        
        			// printf("Reduction(standard_type -> STRING)\n");
    	}
;


standard_type : INTEGER{
			$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_INTEGER));


      // $$=$1;
      // $$->nodeType=NODE_TYPE_INT;
			// printf("Reduction(standard_type -> INTEGER)\n");
		}
	| REAL{
			$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_REAL));
      // $$=$1;
      // $$->nodeType=NODE_TYPE_REAL;
			// printf("Reduction(standard_type -> REAL)\n");
		}
    | STRING{
    		$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_STRING));
      // $$=$1;
      // $$->nodeType=NODE_TYPE_STRING;
			// printf("Reduction(standard_type -> STRING)\n");
    	}
;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON{
     
      $$=newNode(NODE_subprogram_declarations);
			addChild($$,$1);
			addChild($$,$2);
      deleteNode($3);

			// printf("Reduction(subprogram_declarations -> subprogram_declarations subprogram_declaration ;)\n");	

            // printf("create a scope\n");


		}
	| {

        // printf("create a scope\n");
			$$=newNode(NODE_subprogram_declarations);
			// printf("Reduction(subprogram_declarations -> )\n");	
		}
;

subprogram_declaration : 
                        subprogram_head
                        declarations
                        subprogram_declarations
                        compound_statement{
             $$=newNode(NODE_subprogram_declaration);
							addChild($$,$1);
							addChild($$,$2);
							addChild($$,$3);
            //   printf("Reduction(subprogram_declaration -> subprogram_head declarations compound_statement)\n"); 



            // print_SHOW_NEWSCP;            
            } 
;

subprogram_head : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON{//funcion declaration
      $$=newNode(NODE_subprogram_head);
			addChild($$,newNode(NODE_FUNCTION));
      // $2->nodeType=NODE_FUNCTION;

			// struct nodeType* id;
	    // 	id = newNode(NODE_ID);
      //       id->string = $2;
      addChild($$,$2);
			addChild($$,$3);
			addChild($$,newNode(NODE_COLON));
			addChild($$,$5);
      addChild($$,newNode(SEMICOLON));
      // deleteNode($1);
      // deleteNode($4);
      // deleteNode($6);
    //   printf("Reduction(subprogram_head -> FUNCTION ID arguments : standard_type ;)\n");  
    }
                | PROCEDURE IDENTIFIER arguments SEMICOLON{//procedure declaration
     $$=newNode(NODE_subprogram_head);
          //  $2->nodeType=NODE_PROCEDURE;

			// addChild($$,newNode(NODE_PROCEDURE));
			// struct nodeType* id;
	    // 	id = newNode(NODE_IDENTIFIER);
      //       id->string = $2;
      addChild($$,$2);
			addChild($$,$3);
      addChild($$,$4);
      // deleteNode($1);
    //   printf("Reduction(subprogram_head -> PROCEDURE ID arguments)\n"); 
    } 
;
arguments : LPAREN parameter_list RPAREN{
      $$=newNode(NODE_arguments);
      addChild($$,newNode(NODE_LPAREN));
      			addChild($$,$2);
            addChild($$,newNode(NODE_RPAREN));

      // $$=$2;
      // deleteNode($1);
      // deleteNode($3);
    //   printf("Reduction(arguments -> ( parameter_list ) )\n");
    }
  | {
    $$=newNode(NODE_arguments);
    //   printf("Reduction(arguments ->  )\n");
    }
 
;
parameter_list : optional_var identifier_list COLON type{
                  $$=newNode(NODE_parameter_list);
                  addChild($$,$1);
                  addChild($$,$2);
                  addChild($$,newNode(NODE_COLON));
                  addChild($$,$4);
                        // deleteNode($3);

    //   printf("Reduction(parameter_list -> optional_var identifier_list : type )\n");
    }
               | optional_var identifier_list COLON type SEMICOLON parameter_list{
                  $$=newNode(NODE_parameter_list);
                  addChild($$,$1);
                  addChild($$,$2);
                  addChild($$,newNode(NODE_COLON));
                  addChild($$,$4);
                  addChild($$,newNode(NODE_SEMICOLON));
                  addChild($$,$6);
                  // deleteNode($3);
                  // deleteNode($5);
    //   printf("Reduction(parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
    } 
;

optional_var : VAR{
        $$=newNode(NODE_optional_var);
				addChild($$,newNode(NODE_VAR));
        // printf("Reduction(optional_var -> VAR )\n");
      }
      | {
         $$=newNode(NODE_optional_var);
        // printf("Reduction(optional_var ->  )\n");
      }
             
;

compound_statement : PBEGIN
                    optional_statements
                    END{
      $$=newNode(NODE_compound_statement);
			addChild($$,newNode(NODE_PBEGIN));
			addChild($$,$2);
      $3->nodeType=NODE_END;
      addChild($$,$3);
			addChild($$,newNode(NODE_END));
      // deleteNode($1);
    //   printf("Reduction(compound_statement -> begin optional_statements END )\n");
    }
;

optional_statements : statement_list{
    $$=newNode(NODE_optional_statements);
			addChild($$,$1);
          // $$=$1;

    //   printf("Reduction(optional_statements -> statement_list )\n");
    } 
                    | {
        $$=newNode(NODE_optional_statements);
      // $$=$1;

        // printf("Reduction(optional_statements ->  )\n");
      }
          
;

statement_list : statement {
      $$=newNode(NODE_statement_list);
			addChild($$,$1);
    //   printf("Reduction(statements_list -> statement )\n");
    }
               | statement_list SEMICOLON statement{
     $$=newNode(NODE_statement_list);
			addChild($$,$1);
			// addChild($$,newNode(NODE_SEMICOLON));
			addChild($$,$3);
      deleteNode($2);

    //   printf("Reduction(statements_list -> statement_list ; statement )\n");
    }
;

statement : variable ASSIGNMENT expression{
      $$=newNode(NODE_statement);
			addChild($$,$1);
			addChild($$,newNode(NODE_ASSIGNMENT));
			addChild($$,$3);

      // $$=$2;
      // $$->nodeType=NODE_ASSIGNMENT;
      // addChild($$,$1);
      // addChild($$,$3);
    //   printf("Reduction(statement -> variable := expression )\n");  
    }
  | procedure_statement{
$$=newNode(NODE_statement);
			addChild($$,$1);

      // $$=$1;

    //   printf("Reduction(statement -> procedure_statement )\n");
    }
  | compound_statement{
    $$=newNode(NODE_statement);
			addChild($$,$1);


            // $$=$1;

    //   printf("Reduction(statement -> compound_statement )\n");
    }
  | IF expression THEN statement ELSE statement{
     $$=newNode(NODE_statement);
			addChild($$,newNode(NODE_IF));
			addChild($$,$2);
			addChild($$,newNode(NODE_THEN));
			addChild($$,$4);
			addChild($$,newNode(NODE_ELSE));
			addChild($$,$6);


    // $$=newNode(NODE_IF);
    //   addChild($$,$2);
    //   addChild($$,$4);
    //   addChild($$,$6);
    //   deleteNode($1);
    //   deleteNode($3);
    //   deleteNode($5);
    //   printf("Reduction(statement -> IF expression THEN statement ELSE statement )\n");
    }
  | WHILE expression DO statement{
      $$=newNode(NODE_statement);
			addChild($$,newNode(NODE_WHILE));
			addChild($$,$2);
			addChild($$,newNode(NODE_DO));
			addChild($$,$4);

      // $$=newNode(NODE_WHILE);
      // addChild($$,$2);
      // addChild($$,$4);
      // deleteNode($1);
      // deleteNode($3);

    //   printf("Reduction(statement -> WHILE expression DO statement )\n");
    }
  | {
    $$=newNode(NODE_statement);
    //   printf("Reduction(statement ->  )\n");
    }
;

variable : IDENTIFIER tail{
            $$=newNode(NODE_variable);
			// struct nodeType* id;
	    // 	id = newNode(NODE_IDENTIFIER);
	    // 	id->string=$1;
			addChild($$,$1);
			addChild($$,$2);
      // $$=$1;
      // $1->nodeType=NODE_SYM_REF;
      // addChild($$,$2);
    //   printf("Reduction(variable -> ID tail )\n");
    }
;

tail : LBRACE expression RBRACE tail{
      $$=newNode(NODE_tail);
      addChild($$,newNode(NODE_LBRACE));

			addChild($$,$2);
      addChild($$,newNode(NODE_RBRACE));
			addChild($$,$4);
      // deleteNode($1);
      // deleteNode($3);
    //   printf("Reduction(tail -> ( expression ) tail )\n");
    }
  |{
    $$=newNode(NODE_tail);	
    //   printf("Reduction(tail -> )\n");  
    } 
;

procedure_statement : IDENTIFIER {
      $$=newNode(NODE_procedure_statement);
			// struct nodeType* id;
      // id = newNode(NODE_IDENTIFIER);
      // id->string=$1;
			addChild($$,$1);
// $$=newNode(NODE_procedure_statement);
//       $1->nodeType=NODE_IDENTIFIER;
//       addChild($$,$1);


    //   printf("Reduction(procedure_statement -> ID )\n");
    }
  | IDENTIFIER LPAREN expression_list RPAREN{
      $$=newNode(NODE_procedure_statement);
			// struct nodeType* id;
      // id = newNode(NODE_IDENTIFIER);
      // id->string=$1;
			addChild($$,$1);
      addChild($$,newNode(NODE_LPAREN));
			addChild($$,$3);
      addChild($$,newNode(NODE_RPAREN));
// $$=newNode(NODE_procedure_statement);
//       $1->nodeType=NODE_IDENTIFIER;
//       addChild($$,$1);
//       addChild($$,$3);
//       deleteNode($2);
//       deleteNode($4);
        // printf("Reduction(procedure_statement -> ID ( expression_list ) )\n");
    }
;

expression_list : expression {
      $$=newNode(NODE_expression_list);
			addChild($$,$1);
            // $$=$1;

    //   printf("Reduction(expression_list -> expression )\n");
    }
  | expression_list COMMA expression{
      $$=newNode(NODE_expression_list);
			addChild($$,$1);
			addChild($$,newNode(NODE_COMMA));
			addChild($$,$3);
      // $$=$1;
      // addChild($$,$3);
      // deleteNode($2);
    //   printf("Reduction(expression_list -> expression_list COMMA expression )\n");
    }
;

expression : boolexpression { 
                $$=newNode(NODE_expression);
                // printf("here bool\n");
                addChild($$,$1);
                      // $$=$1;

                // printf("Reduction(expression -> boolexpression )\n");
            }
           | boolexpression AND boolexpression{
                $$=newNode(NODE_expression);
                addChild($$,$1);
                addChild($$,newNode(NODE_AND));
                addChild($$,$3);
                // printf("Reduction(expression -> boolexpression )\n");
           }
           | boolexpression OR boolexpression{

                $$=newNode(NODE_expression);
                addChild($$,$1);
                addChild($$,newNode(NODE_OR));
                addChild($$,$3);
                // printf("Reduction(expression -> boolexpression )\n");
           }
;

boolexpression : simple_expression {
                $$=newNode(NODE_boolexpression);
                addChild($$,$1);
      //           $$=$2;
      // //addChild($$,$2);
      // addChild($$,$1);
      // addChild($$,$3);
      //       $$=$1;

              //   printf("Reduction(boolexpression -> simple_expression )\n");
              }
            | simple_expression relop simple_expression{
                $$=newNode(NODE_boolexpression);
                addChild($$,$1);
                addChild($$,$2);
                addChild($$,$3);
      //           $$=$2;
      // //addChild($$,$2);
      // addChild($$,$1);
      // addChild($$,$3);
              //   printf("Reduction(boolexpression -> simple_expression relop simple_expression )\n");
              }
;

simple_expression : term {
    
        $$=newNode(NODE_simple_expression);
			  addChild($$,$1);
              // $$=$1;

    //   printf("Reduction(simple_expression -> term )\n");
    }
  | simple_expression addop term{
        $$=newNode(NODE_simple_expression);
        addChild($$,$1);
        addChild($$,$2);
        addChild($$,$3);
      //   $$=$2;
      // addChild($$,$1);
      // addChild($$,$3);
    //   printf("Reduction(simple_expression -> simple_expression addop term )\n");
    }
;

term : factor {
        $$=newNode(NODE_term);
			  addChild($$,$1);
              // $$=$1;

    //   printf("Reduction(term -> factor )\n");
    }
  | term mulop factor{
      $$=newNode(NODE_term);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,$3);
      // $$=$2;
      // addChild($$,$1);
      // addChild($$,$3);
    //   printf("Reduction(term -> term mulop factor )\n");
    }
;

factor : IDENTIFIER tail{
        $$=newNode(NODE_factor);
			  // struct nodeType* id;
	    	// id = newNode(NODE_IDENTIFIER);
	    	// id->string=$1;
        addChild($$,$1);
        addChild($$,$2);
      //   $$=$1;
      // $$->nodeType=NODE_IDENTIFIER;
      // addChild($$,$2);
        // printf("Reduction(factor -> ID tail )\n");
    }
       | IDENTIFIER LPAREN expression_list RPAREN{
          $$=newNode(NODE_factor);
			    // struct nodeType* id;
	    	  // id = newNode(NODE_IDENTIFIER);
	    	  // id->string=$1;
          addChild($$,$1);
          addChild($$,newNode(NODE_LPAREN));
          addChild($$,$3);
          addChild($$,newNode(NODE_RPAREN));
      //     $$=$1;
      // $$->nodeType=NODE_IDENTIFIER;
      // //addChild($$,$1);
      // addChild($$,$3);
      // deleteNode($2);
      // deleteNode($4);

    //   printf("Reduction(factor -> ID ( expression_list ) )\n");
    }
       | num  {
          $$=newNode(NODE_factor);
          // struct nodeType* number;
          // number = newNode(NODE_num);
          // printf("heyhey %lf\n",$1->rValue);
          // number->rValue=$1->rValue;
          addChild($$,$1);
          // $$=$1;
          // $$->nodeType=NODE_num;
    //   printf("Reduction(factor -> NUM )\n");
    }
       | LITERALSTR{
          $$=newNode(NODE_factor);
          struct nodeType* str;
          str = newNode(NODE_LITERALSTR);
          str->string=$1;
          addChild($$,$1);
      //     $$=$1;
      // $$->nodeType=NODE_LITERALSTR;
        // printf("Reduction(factor -> String )\n");
    }
       | LPAREN expression RPAREN {
          $$=newNode(NODE_factor);
          addChild($$,newNode(NODE_LPAREN));
          addChild($$,$2);
          addChild($$,newNode(NODE_RPAREN));
      //     $$=$2;
      // deleteNode($1);
      // deleteNode($3);
        // printf("Reduction(factor -> ( expression ) )\n");
    }
       | NOT factor{
          $$=newNode(NODE_factor);
          addChild($$,newNode(NODE_NOT));
          addChild($$,$2);
      //     $$=newNode(NODE_factor);
      // int lineno=$1->lineno;
      // $1=newOpNode(OP_NOT);
      // $1->lineno=lineno;

      // addChild($$,$1);
      // addChild($$,$2);
    //   printf("Reduction(factor -> ( NOT factor ) )\n");
    }
       | SUBOP factor{
     
          $$=newNode(NODE_factor);
          addChild($$,newNode(NODE_SUBOP));
          addChild($$,$2);
      //     $$=newNode(NODE_factor);
      // int lineno=$1->lineno;
      // $1=newOpNode(OP_SUB);
      // $1->lineno=lineno;

      // addChild($$,$1);
      // addChild($$,$2);
    //   printf("Reduction(factor -> ( SUBOP factor ) )\n");
    }
;



addop : ADDOP{
    $$=newNode(NODE_addop);
			addChild($$,newNode(NODE_ADDOP));

      // $$=newOpNode(NODE_ADDOP);
      // $$->lineno=$1->lineno;
      // deleteNode($1);
    //   printf("Reduction(addop -> PLUS )\n");
    }
    | SUBOP{
    $$=newNode(NODE_addop);
			addChild($$,newNode(NODE_SUBOP));
    // $$=newOpNode(NODE_SUBOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(addop -> MINUS )\n");
    }
;

mulop : MULOP{
      $$=newNode(NODE_mulop);
      // $$=newOpNode(NODE_MULOP);
      // $$->lineno=$1->lineno;
      // deleteNode($1);
			addChild($$,newNode(NODE_MULOP));
    //   printf("Reduction(mulop -> STAR )\n");
    }
    | DIVOP{
      // $$=newOpNode(NODE_DIVOP);
      // $$->lineno=$1->lineno;
      // deleteNode($1);
      $$=newNode(NODE_mulop);
			addChild($$,newNode(NODE_DIVOP));
    //   printf("Reduction(mulop -> SLASH )\n");
    }
;

relop : LTOP {
      $$=newNode(NODE_relop);
    //   printf("LTOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_LTOP));
    // $$=newOpNode(NODE_LTOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(relop -> LT )\n");
    }
      | GTOP{

     $$=newNode(NODE_relop);
    //  printf("GTOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_GTOP));
    // $$=newOpNode(NODE_GTOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(relop -> GT )\n");
    }
      | EQOP{
      $$=newNode(NODE_relop);
    //   printf("EQOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_EQOP));
    // $$=newOpNode(NODE_EQOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(relop -> EQUAL )\n");
    }
      | LETOP{
      $$=newNode(NODE_relop);
    //   printf("LETOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_LETOP));
    // $$=newOpNode(NODE_LETOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(relop -> LE )\n");
    }
      | GETOP{
      $$=newNode(NODE_relop);
    //   printf("GETOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_GETOP));
    // $$=newOpNode(NODE_GETOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    //   printf("Reduction(relop -> GE )\n");
    }
      | NEQOP{
      $$=newNode(NODE_relop);
    // $$=newOpNode(NODE_NEQOP);
    //   $$->lineno=$1->lineno;
    //   deleteNode($1);
    // //   printf("NEQOP %d\n",NODE_relop);
			addChild($$,newNode(NODE_NEQOP));
    //   printf("Reduction(relop -> NEQOP )\n");
    }
;

%%
struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}


void yyerror(const char *msg) {
    fprintf(stderr,
            "[ERROR] line %4d:%3d %s, Unmatched token: %s\n",
            line_no, col_no - yyleng, buffer, yytext);
}

int main(int argc, const char *argv[]) {

    if(argc > 2)
        fprintf( stderr, "Usage: ./parser [filename]\n" ), exit(0);

    FILE *fp = argc == 1 ? stdin : fopen(argv[1], "r");

    if(fp == NULL)
        fprintf( stderr, "Open file error\n" ), exit(-1);

    yyin = fp;
    yyparse();
    if(ASTROOT){
        // do pass here
    }


    printTree(ASTROOT,0);
    /* printf("sdjgoioij %d\n",ASTROOT->child->dtype); */
    SymbolTable.size = 0;
    SymbolTable.status=1;
    ScopeStack[0]=&SymbolTable;
    printf("create a scope1\n");
    /* printf("Create a new SymbolTable\n"); */
    semanticCheck(ASTROOT);
    printf("close a scope\n");
    /* printf("Close a SymbolTable\n"); */
    printf("\nEnd!\n");


    return 0;
}
