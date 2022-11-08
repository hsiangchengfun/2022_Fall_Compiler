%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "error.h"

#define MAX_LINE_LENG      256
extern int line_no, col_no, opt_list;
extern char buffer[MAX_LINE_LENG];
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */
extern int yyleng;

extern int yylex(void);
static void yyerror(const char *msg);
%}

%token PROGRAM VAR ARRAY OF INTEGER REAL STRING FUNCTION PROCEDURE PBEGIN END IF THEN ELSE WHILE DO NOT AND OR

%token LPAREN RPAREN SEMICOLON DOT COMMA COLON LBRACE RBRACE DOTDOT ASSIGNMENT ADDOP SUBOP MULOP DIVOP LTOP GTOP EQOP GETOP LETOP NEQOP

%token IDENTIFIER REALNUMBER INTEGERNUM SCIENTIFIC LITERALSTR

%union {
  int val;
  char* text;
  double dval;
}


%%

    /* define your snytax here */
prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON
     declarations
     subprogram_declarations
     compound_statement
     DOT
;

identifier_list : IDENTIFIER
                | identifier_list COMMA IDENTIFIER
;

declarations : declarations VAR identifier_list COLON type SEMICOLON
             |
;

type : standard_type
     | ARRAY LBRACE num DOTDOT num RBRACE OF type
;

num : INTEGERNUM
    | REALNUMBER
    | SCIENTIFIC
;

standard_type : INTEGER
              | REAL
              | STRING
;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON
                        |
;

subprogram_declaration : 
                        subprogram_head
                        declarations
                        subprogram_declarations
                        compound_statement
;

subprogram_head : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
                | PROCEDURE IDENTIFIER arguments SEMICOLON
;
arguments : LPAREN parameter_list RPAREN
          | 
;

parameter_list : optional_var identifier_list COLON type
               | optional_var identifier_list COLON type SEMICOLON parameter_list
;

optional_var : VAR
             |
;

compound_statement : PBEGIN
                    optional_statements
                    END
;

optional_statements : statement_list
                    | 
;

statement_list : statement
               | statement_list SEMICOLON statement
;

statement : variable ASSIGNMENT expression
          | procedure_statement
          | compound_statement
          | IF expression THEN statement ELSE statement
          | WHILE expression DO statement
          |
;

variable : IDENTIFIER tail
;

tail : LBRACE expression RBRACE tail
     | 
;

procedure_statement : IDENTIFIER
                    | IDENTIFIER LPAREN expression_list RPAREN
;

expression_list : expression
                | expression_list COMMA expression
;

expression : boolexpression
           | boolexpression AND boolexpression
           | boolexpression OR boolexpression
;

boolexpression : simple_expression
               | simple_expression relop simple_expression
;

simple_expression : term
                  | simple_expression addop term
;

term : factor
     | term mulop factor
;

factor : IDENTIFIER tail
       | IDENTIFIER LPAREN expression_list RPAREN
       | num
       | LITERALSTR
       | LPAREN expression RPAREN
       | NOT factor
       | SUBOP factor
;



addop : ADDOP
      | SUBOP
;

mulop : MULOP
      | DIVOP
;

relop : LTOP
      | GTOP
      | EQOP
      | LETOP
      | GETOP
      | NEQOP
;




%%

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
    return 0;
}
