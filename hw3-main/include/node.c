#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

struct nodeType* newNode(int type) {
    struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->child = NULL;
    node->lsibling = node;
    node->rsibling = node;

    return node;
}

void addChild(struct nodeType *node, struct nodeType *child) {
    child->parent = node;
    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->lsibling = node->child->lsibling;
        child->rsibling = node->child;
        node->child->lsibling->rsibling = child;
        node->child->lsibling = child;
    }
}

void deleteNode(struct nodeType *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct nodeType *node, int ident) {
    static char blank[1024];
    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType) {
        /********* modified **********/
        case NODE_ADDOP:
            printf("%s/+\n", blank);
            break;
        case NODE_SUBOP:
            printf("%s/-\n", blank);
            break;
        case NODE_MULOP:
            printf("%s/*\n", blank);
            break;
        case NODE_DIVOP:
            printf("%s/ /\n", blank);
            break;    
        case NODE_NUM:
            printf("%s%lf\n", blank, node->rValue);
            ident += 8;
        case NODE_num:
            printf("%s NODE_num\n", blank);
            ident += 8;
            break;

        case NODE_INTEGERNUM:
            printf("%s NODE_INTEGERNUM %d\n", blank, node->iValue);
            ident += 8;
            break;
        case NODE_REALNUMBER:
            printf("%s NODE_REALNUMBER %lf\n", blank, node->rValue);
            ident += 8;
            break;
        case NODE_SCIENTIFIC:
            printf("%s NODE_SCIENTIFIC %lf\n", blank, node->sValue);
            ident += 8;
            break;
        case NODE_boolexpression:
            printf("%s/NODE_boolexpression\n", blank);
            ident += 8;
            break;


        case NODE_IDENTIFIER:
            printf("%s%s\n", blank, node->string);
            ident += 8;
            break;
        case NODE_PROGRAM:
            printf("%s/NODE_PROGRAM\n", blank);
            ident += 8;
            break;            
        case NODE_IF:
            printf("%s/NODE_IF\n", blank);
            break;
        case NODE_ELSE:
            printf("%s/NODE_ELSE\n", blank);
            break;
        case NODE_WHILE:
            printf("%s/NODE_WHILE\n", blank);
            break;
        case NODE_DO:
            printf("%s/NODE_DO\n", blank);
            break;
        case NODE_THEN:
            printf("%s/NODE_THEN\n", blank);
            break;
        case NODE_OF:
            printf("%s/NODE_OF\n", blank);
            break;
        case NODE_FUNCTION:
            printf("%s/NODE_FUNCTION\n", blank);
            break;
        case NODE_PROCEDURE:
            printf("%s/NODE_PROCEDURE\n", blank);
            break;
        case NODE_STRING:
            printf("%s/NODE_STRING\n", blank);
            break;
        case NODE_ASSIGNMENT:
            printf("%s/:=\n", blank);
            break;
        case NODE_COLON:
            printf("%s/:\n", blank);
            break;
        case NODE_INTEGER:
            printf("%s/NODE_INTEGER\n", blank);
            break;                            
        case NODE_COMMA:
            printf("%s/,\n", blank);
            break;
        case NODE_PBEGIN:
            printf("%s/NODE_PBEGIN\n", blank);
            break;
        case NODE_END:
            printf("%s/NODE_END\n", blank);
            break;
        case NODE_ARRAY:
            printf("%s/NODE_ARRAY\n", blank);
            break;
        case NODE_VAR:
            printf("%s/NODE_VAR\n", blank);
            break;
        case NODE_NOT:
            printf("%s/NODE_NOT\n", blank);
            break;                            
        case NODE_DOT:
            printf("%s/.\n", blank);
            break;
         case NODE_DOTDOT:
            printf("%s/..\n", blank);
            break;
        case NODE_EQOP:
            printf("%s/=\n", blank);
            break;
        case NODE_NEQOP:
            printf("%s/!=\n", blank);
            break;
        case NODE_GETOP:
            printf("%s/>=\n", blank);
            break;
        case NODE_GTOP:
            printf("%s/>\n", blank);
            break;
        case NODE_LBRACE:
            printf("%s/[\n", blank);
            break;                            
        case NODE_LPAREN:
            printf("%s/(\n", blank);
            break;
        case NODE_LETOP:
            printf("%s/<=\n", blank);
            break;                            
        case NODE_LTOP:
            printf("%s/<\n", blank);
            break;
        case NODE_RBRACE:
            printf("%s/]\n", blank);
            break;
        case NODE_REAL:
            printf("%s/NODE_REAL\n", blank);
            break;
        case NODE_RPAREN:
            printf("%s/)\n", blank);
            break;
        case NODE_SEMICOLON:
            printf("%s/;\n", blank);
            break;
        // case NODE_CHAR:
        //     printf("%s/CHAR\n", blank);
        //     break;                            
        case NODE_String:
            printf("%s%s\n", blank,node->string);
            break;
        case NODE_Char:
            printf("%s%s\n", blank,node->string);
            break;
                                                  
        case NODE_prog:
            printf("%s/NODE_prog\n", blank);
            ident += 8;
            break;
        case NODE_identifier_list:
            printf("%s/NODE_identifier_list\n", blank);
            ident += 8;
            break;
        case NODE_declarations:
            printf("%s/NODE_declarations\n", blank);
            ident += 8;
            break;
        case NODE_type:
            printf("%s/NODE_type\n", blank);
            ident += 8;
            break;
        case NODE_standard_type:
            printf("%s/NODE_standard_type\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_declaration:
            printf("%s/NODE_subprogram_declaration\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_declarations:
            printf("%s/NODE_subprogram_declarations\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_head:
            printf("%s/NODE_subprogram_head\n", blank);
            ident += 8;
            break;
        case NODE_arguments:
            printf("%s/NODE_arguments\n", blank);
            ident += 8;
            break;
        case NODE_parameter_list:
            printf("%s/NODE_parameter_list\n", blank);
            ident += 8;
            break;
        case NODE_optional_var:
            printf("%s/NODE_optional_var\n", blank);
            ident += 8;
            break;
        case NODE_compound_statement:
            printf("%s/NODE_compound_statement\n", blank);
            ident += 8;
            break;
        case NODE_optional_statements:
            printf("%s/NODE_optional_statements\n", blank);
            ident += 8;
            break;
        case NODE_statement_list:
            printf("%s/NODE_statement_list\n", blank);
            ident += 8;
            break;
        case NODE_variable:
            printf("%s/NODE_variable\n", blank);
            ident += 8;
            break;
        case NODE_tail:
            printf("%s/NODE_tail\n", blank);
            ident += 8;
            break;
        case NODE_procedure_statement:
            printf("%s/NODE_procedure_statement\n", blank);
            ident += 8;
            break;            
        case NODE_expression_list:
            printf("%s/NODE_expression_list\n", blank);
            ident += 8;
            break;    
        case NODE_expression:
            printf("%s/NODE_expression\n", blank);
            ident += 8;
            break;
        case NODE_simple_expression:
            printf("%s/NODE_simple_expressiong\n", blank);
            ident += 8;
            break;
        case NODE_term:
            printf("%s/NODE_term\n", blank);
            ident += 8;
            break;
        case NODE_factor:
            printf("%s/NODE_factor\n", blank);
            ident += 8;
            break;
        case NODE_addop:
            printf("%s/NODE_addop\n", blank);
            ident += 8;
            break;
        case NODE_mulop:
            printf("%s/NODE_mulop\n", blank);
            ident += 8;
            break;
        case NODE_relop:
            printf("%s/NODE_relop\n", blank);
            ident += 8;
            break;
        case NODE_statement:
            printf("%s/NODE_statement\n", blank);
            ident += 8;
            break;                 
        /*****************************************/        
        
        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
          break;
    }

    struct nodeType *child = node->child;
    if(child != NULL) {
        do {
            printTree(child, ident);
            child = child->rsibling;
        } while(child != node->child);
    }
}

