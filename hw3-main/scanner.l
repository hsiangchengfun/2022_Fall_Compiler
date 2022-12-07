%{
/*
 * scanner.l
 *
 * lex input file for pascal scanner
 *
 */

#include <stdio.h>
#include <string.h>
#include "node.h"
#include "parser.h"
#include "info.h"

int fileno(FILE *);

#define YY_USER_ACTION \
    yylloc.first_line = line_no; \
    yylloc.first_column = col_no; \
    col_no += yyleng;

#define MAX_LINE_LENG      256
#define LIST       if(mode==1)strcat(buffer, yytext)
#define LIST_FLUSH do{ if(opt_list) printf("%s", buffer); *buffer = 0; }while(0)
#define LOG(TYPE) \
    do{ LIST; \
        if(opt_token) \
        fprintf(stderr, "token(type:%-10s) on line %4d, %3d : %s\n", \
            #TYPE, line_no, col_no - yyleng, yytext); \
    } while(0)

// #define LOGcomment1 do{ } while(0)//fprintf(stderr,"[INFO ] line %4d:%3d comment string\n" , line_no , col_no - yyleng );}while(0)
// #define LOGcommentstart do{ LIST;} while(0)//fprintf(stderr,"[INFO ] line %4d:%3d comment string start\n" , line_no , col_no - yyleng ); }while(0)
// #define LOGcommentend do{ LIST;}while(0)//fprintf(stderr,"[INFO ] line %4d:%3d comment string end\n" , line_no , col_no - yyleng );}while(0)
// #define func do{*(buffer-1)="-";buffer = &(buffer -1);}while(0)

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
struct nodeType* newTokenNode(int Type);


#ifdef __cplusplus
extern "C" int yylex(void);
#endif
int mode=1;
int opt_list = 1, opt_token = 0;
int line_no = 1, col_no = 1;
char buffer[MAX_LINE_LENG];

%}

%option nounput
%option noinput

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]


%x TEST
%x COMMENT0
%x COMMENT1
%x minusnum
%%
                             /* v could do something */
{P}{R}{O}{G}{R}{A}{M}       {yylval.node = newTokenNode(PROGRAM);yylval.node->lineno=line_no; return(PROGRAM);    }
{V}{A}{R}                   {yylval.node = newTokenNode(VAR);return(VAR);}
{A}{R}{R}{A}{Y}             {yylval.node = newTokenNode(ARRAY);yylval.node->lineno=line_no; return(ARRAY);}
{O}{F}                      {yylval.node = newTokenNode(OF);return(OF);}
{I}{N}{T}{E}{G}{E}{R}       {yylval.node = newTokenNode(INTEGER);yylval.node->lineno=line_no; return(INTEGER);    }
{R}{E}{A}{L}                {yylval.node = newTokenNode(REAL);yylval.node->lineno=line_no; return(REAL);       }
{S}{T}{R}{I}{N}{G}          {yylval.node = newTokenNode(STRING);yylval.node->lineno=line_no;return(STRING);     }
{F}{U}{N}{C}{T}{I}{O}{N}    {yylval.node = newTokenNode(FUNCTION);yylval.node->lineno=line_no; return(FUNCTION);   }
{P}{R}{O}{C}{E}{D}{U}{R}{E} {yylval.node = newTokenNode(PROCEDURE);yylval.node->lineno=line_no;return(PROCEDURE);  }
{B}{E}{G}{I}{N}             {yylval.node = newTokenNode(PBEGIN); return(PBEGIN);     }
{E}{N}{D}                   {yylval.node = newTokenNode(END);yylval.node->lineno=line_no; return(END);        }
{I}{F}                      {yylval.node = newTokenNode(IF); return(IF);         }
{T}{H}{E}{N}                {yylval.node = newTokenNode(THEN); return(THEN);       }
{E}{L}{S}{E}                {yylval.node = newTokenNode(ELSE); return(ELSE);       }
{W}{H}{I}{L}{E}             {yylval.node = newTokenNode(WHILE);return(WHILE);      }
{D}{O}                      {yylval.node = newTokenNode(DO); return(DO);         }
{N}{O}{T}                   {yylval.node = newTokenNode(NOT); return(NOT);        }
{A}{N}{D}                   {yylval.node = newTokenNode(AND); return(AND);        }
{O}{R}                      {yylval.node = newTokenNode(OR); return(OR);         }

"("                         {yylval.node = newTokenNode(LPAREN); return(LPAREN);     }
")"                         {yylval.node = newTokenNode(RPAREN); return(RPAREN);     }
";"                         {yylval.node = newTokenNode(SEMICOLON); return(SEMICOLON);  }
"."                         {yylval.node = newTokenNode(DOT); return(DOT);        }
","                         {yylval.node = newTokenNode(COMMA); return(COMMA);      }
":"                         {yylval.node = newTokenNode(COLON); return(COLON);      }
"["                         {yylval.node = newTokenNode(LBRACE); return(LBRACE);     }
"]"                         {yylval.node = newTokenNode(RBRACE); return(RBRACE);     }
".."                        {yylval.node = newTokenNode(DOTDOT); return(DOTDOT);     }
":="                        {yylval.node = newTokenNode(ASSIGNMENT); return(ASSIGNMENT); }
"+"                         {yylval.node = newTokenNode(NODE_addop);yylval.node->lineno=line_no;yylval.node->op = NODE_ADDOP; return(ADDOP);      }
"-"                         {yylval.node = newTokenNode(NODE_addop);yylval.node->lineno=line_no;yylval.node->op = NODE_SUBOP; return(SUBOP);      }
"*"                         {yylval.node = newTokenNode(NODE_mulop);yylval.node->lineno=line_no;yylval.node->op = NODE_MULOP; return(MULOP);      }
"/"                         {yylval.node = newTokenNode(NODE_mulop);yylval.node->lineno=line_no;yylval.node->op = NODE_DIVOP; return(DIVOP);      }
">"                         {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_GTOP; return(GTOP);       }
"<"                         {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_LTOP; return(LTOP);       }
"="                         {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_EQOP; return(EQOP);       }
">="                        {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_GETOP; return(GETOP);      }
"<="                        {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_LETOP; return(LETOP);      }
"!="                        {yylval.node = newTokenNode(NODE_relop);yylval.node->lineno=line_no;yylval.node->op = NODE_NEQOP; return(NEQOP);      }

  /* define identifier here */

  /* define INTEGERNUM, REALNUMBER, SCIENTIFIC here */

  /* define single/multiple line comment here */

  /* define string constant (LITERALSTR) here */

  /* define pragma here */

 /*
    yylval.text = strdup, strndup ... (yytext)
    yylval.dval = atoi, atof, strtod, strtol ... (yytext)
 */

  /* define identifier here */
[a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]+         {yylval.node=newTokenNode(NODE_IDENTIFIER); yylval.node->nodeType=NODE_IDENTIFIER;yylval.node->lineno=line_no; yylval.node->string=strdup(yytext); return(IDENTIFIER);}
[a-zA-Z][a-zA-Z0-9]*           {yylval.node=newTokenNode(NODE_IDENTIFIER); yylval.node->nodeType=NODE_IDENTIFIER;yylval.node->lineno=line_no; yylval.node->string=strdup(yytext);return(IDENTIFIER);}

  /* define INTEGERNUM, REALNUMBER, SCIENTIFIC here */
([0-9]+)                      {yylval.node=newTokenNode(NODE_INTEGERNUM); yylval.node->lineno=line_no; yylval.node->iValue = atoi(yytext);return(INTEGERNUM);}

[0-9]+"."[0-9]+             {yylval.node=newTokenNode(NODE_REALNUMBER); yylval.node->lineno=line_no; yylval.node->rValue = atof(yytext);return(REALNUMBER);}
[0-9]+"."*[0-9]*[Ee][+-]*[0-9]+ {yylval.node=newTokenNode(NODE_SCIENTIFIC); yylval.node->lineno=line_no; yylval.node->sValue = atof(yytext);return(SCIENTIFIC);}



  /* define single/multiple line comment here */
  /* comment0 => pair */
  /* comment1 => //   */

"//".*                    {LIST_FLUSH;}
   /* ^"//".* */
 
<INITIAL>"/*"           {LIST;BEGIN COMMENT0;}
<COMMENT0>"*"[^/\n]     {LIST;BEGIN COMMENT0;}
<COMMENT0>[^*\n]*            {LIST;BEGIN COMMENT0;}
<COMMENT0>"*/"          {LIST;BEGIN INITIAL;}



  /* define string constant (LITERALSTR) here */

[\"][^"\n"]*[\"]      {yylval.node = newTokenNode(NODE_LITERALSTR);yylval.node->lineno=line_no;yylval.node->string=strdup(yytext);return(LITERALSTR);} 



  /* define pragma here */

"#"[ ]*"pragma"[ ]*"list"[ ]*"on"      {
  mode = 1 ;
  LIST;
}

"#"[ ]*"pragma"[ ]*"list"[ ]*"off"     {
  mode = 0 ;
}






[ \t\f\r]    LIST;

\n {
  LIST;
  LIST_FLUSH;
  line_no++, col_no = 1;
}

.  { LIST; fprintf(stderr, "[ERROR] line %4d:%3d lexical analyzer error %s\n", line_no, col_no - yyleng, yytext); }


%%



void commenteof()
{
 fprintf (stderr, "unexpected EOF inside comment at line %d\n", line_no);
 exit (1);
}


struct nodeType* newTokenNode(int Type) {
    struct nodeType* node = newNode(Type);//all the node's default type is Node_Token.
    node->tokenType = Type;
    return node;
}



