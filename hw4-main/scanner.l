%{
/*
 * scanner.l
 *
 * lex input file for pascal scanner
 *
 */

#include <stdio.h>
#include <string.h>
// #include "node.h"
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
{P}{R}{O}{G}{R}{A}{M}       {LOG(KEYWORD); return(PROGRAM);    }
{V}{A}{R}                   {LOG(KEYWORD); return(VAR);        }
{A}{R}{R}{A}{Y}             {LOG(KEYWORD); return(ARRAY);      }
{O}{F}                      {LOG(KEYWORD); return(OF);         }
{I}{N}{T}{E}{G}{E}{R}       {LOG(KEYWORD); return(INTEGER);    }
{R}{E}{A}{L}                {LOG(KEYWORD); return(REAL);       }
{S}{T}{R}{I}{N}{G}          {LOG(KEYWORD); return(STRING);     }
{F}{U}{N}{C}{T}{I}{O}{N}    {LOG(KEYWORD); return(FUNCTION);   }
{P}{R}{O}{C}{E}{D}{U}{R}{E} {LOG(KEYWORD); return(PROCEDURE);  }
{B}{E}{G}{I}{N}             {LOG(KEYWORD); return(PBEGIN);     }
{E}{N}{D}                   {LOG(KEYWORD); return(END);        }
{I}{F}                      {LOG(KEYWORD); return(IF);         }
{T}{H}{E}{N}                {LOG(KEYWORD); return(THEN);       }
{E}{L}{S}{E}                {LOG(KEYWORD); return(ELSE);       }
{W}{H}{I}{L}{E}             {LOG(KEYWORD); return(WHILE);      }
{D}{O}                      {LOG(KEYWORD); return(DO);         }
{N}{O}{T}                   {LOG(KEYWORD); return(NOT);        }
{A}{N}{D}                   {LOG(KEYWORD); return(AND);        }
{O}{R}                      {LOG(KEYWORD); return(OR);         }

"("                         { LOG(KEYWORD); return(LPAREN);     }
")"                         { LOG(KEYWORD); return(RPAREN);     }
";"                         { LOG(KEYWORD); return(SEMICOLON);  }
"."                         { LOG(KEYWORD); return(DOT);        }
","                         { LOG(KEYWORD); return(COMMA);      }
":"                         { LOG(KEYWORD); return(COLON);      }
"["                         { LOG(KEYWORD); return(LBRACE);     }
"]"                         { LOG(KEYWORD); return(RBRACE);     }
".."                        { LOG(KEYWORD); return(DOTDOT);     }
":="                        { LOG(KEYWORD); return(ASSIGNMENT); }
"+"                         { LOG(KEYWORD); return(ADDOP);      }
"-"                         { LOG(KEYWORD); return(SUBOP);      }
"*"                         { LOG(KEYWORD); return(MULOP);      }
"/"                         { LOG(KEYWORD); return(DIVOP);      }
">"                         { LOG(KEYWORD); return(GTOP);       }
"<"                         { LOG(KEYWORD); return(LTOP);       }
"="                         { LOG(KEYWORD); return(EQOP);       }
">="                        { LOG(KEYWORD); return(GETOP);      }
"<="                        { LOG(KEYWORD); return(LETOP);      }
"!="                        { LOG(KEYWORD); return(NEQOP);      }

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
[a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]+         {yylval.text = strdup(yytext); return(IDENTIFIER);}
[a-zA-Z][a-zA-Z0-9]*           {yylval.text = strdup(yytext);return(IDENTIFIER);}

  /* define INTEGERNUM, REALNUMBER, SCIENTIFIC here */
([0-9]+)                      {yylval.val = atoi(yytext);return(INTEGERNUM);}

[0-9]+"."[0-9]+             {yylval.dval = atof(yytext);return(REALNUMBER);}
[0-9]+"."*[0-9]*[Ee][+-]*[0-9]+ {yylval.text = strdup(yytext);return(SCIENTIFIC);}



  /* define single/multiple line comment here */
  /* comment0 => pair */
  /* comment1 => //   */

"//".*                    {LIST_FLUSH;}
   /* ^"//".* */
 
<INITIAL>"/*"           {LIST;BEGIN COMMENT0;}
<COMMENT0>"*"[^/\n]     {LIST;line_no++; BEGIN COMMENT0;}
<COMMENT0>[^*\n]*            {LIST;line_no++;BEGIN COMMENT0;}
<COMMENT0>"*/"          {LIST;BEGIN INITIAL;}

<COMMENT0>\n         {
LIST;
LIST_FLUSH;
line_no++, col_no = 1;
}

  /* define string constant (LITERALSTR) here */

[\"][^"\n"]*[\"]      {yylval.text = strdup(yytext);return(LITERALSTR);} 



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







