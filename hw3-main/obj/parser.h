/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_OBJ_PARSER_H_INCLUDED
# define YY_YY_OBJ_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ELSE = 259,
    WHILE = 260,
    DO = 261,
    THEN = 262,
    IF = 263,
    OF = 264,
    FUNCTION = 265,
    PROCEDURE = 266,
    END = 267,
    ARRAY = 268,
    VAR = 269,
    NOT = 270,
    STRING = 271,
    ASSIGNMENT = 272,
    COLON = 273,
    COMMA = 274,
    INTEGER = 275,
    AND = 276,
    OR = 277,
    DOT = 278,
    DOTDOT = 279,
    GETOP = 280,
    GTOP = 281,
    LBRACE = 282,
    LETOP = 283,
    LPAREN = 284,
    LTOP = 285,
    ADDOP = 286,
    MULOP = 287,
    DIVOP = 288,
    EQOP = 289,
    NEQOP = 290,
    RBRACE = 291,
    REAL = 292,
    RPAREN = 293,
    SEMICOLON = 294,
    PBEGIN = 295,
    SUBOP = 296,
    NODE_TOKEN = 297,
    INTEGERNUM = 298,
    REALNUMBER = 299,
    SCIENTIFIC = 300,
    IDENTIFIER = 301,
    LITERALSTR = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "parser.y"

  int val;
  char* text;
  double dval;
  struct nodeType *node;
  char* number;
  char* string;

#line 114 "obj/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_OBJ_PARSER_H_INCLUDED  */
