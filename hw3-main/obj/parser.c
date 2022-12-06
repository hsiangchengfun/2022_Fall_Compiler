/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 128 "obj/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 237 "obj/parser.c"

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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   127,   136,   148,   157,   163,   168,   187,
     196,   201,   209,   214,   219,   226,   237,   246,   262,   274,
     285,   290,   296,   304,   316,   321,   328,   339,   344,   351,
     356,   365,   372,   377,   382,   392,   400,   406,   417,   423,
     429,   437,   448,   453,   462,   467,   474,   484,   489,   498,
     504,   513,   518,   527,   536,   545,   553,   561,   566,   572,
     583,   588,   595,   600,   607,   613,   620,   626,   632,   638
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ELSE", "WHILE", "DO", "THEN",
  "IF", "OF", "FUNCTION", "PROCEDURE", "END", "ARRAY", "VAR", "NOT",
  "STRING", "ASSIGNMENT", "COLON", "COMMA", "INTEGER", "AND", "OR", "DOT",
  "DOTDOT", "GETOP", "GTOP", "LBRACE", "LETOP", "LPAREN", "LTOP", "ADDOP",
  "MULOP", "DIVOP", "EQOP", "NEQOP", "RBRACE", "REAL", "RPAREN",
  "SEMICOLON", "PBEGIN", "SUBOP", "NODE_TOKEN", "INTEGERNUM", "REALNUMBER",
  "SCIENTIFIC", "IDENTIFIER", "LITERALSTR", "$accept", "prog",
  "identifier_list", "declarations", "type", "num", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "optional_var", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable", "tail",
  "procedure_statement", "expression_list", "expression", "boolexpression",
  "simple_expression", "term", "factor", "addop", "mulop", "relop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -26,    29,     6,  -104,   -21,  -104,     0,   -14,     1,
    -104,  -104,    34,   -21,     4,    61,    11,    30,     3,    44,
    -104,    40,    10,    56,    56,    24,    24,    57,  -104,    75,
      52,  -104,    76,  -104,  -104,    34,  -104,    73,  -104,  -104,
    -104,    63,  -104,    87,    85,    65,    24,    24,    24,  -104,
    -104,  -104,    25,  -104,  -104,    99,    68,    47,    62,  -104,
     100,    24,    24,  -104,  -104,     5,    24,     4,    16,  -104,
    -104,    70,   -21,    -4,  -104,  -104,    71,  -104,    24,  -104,
       5,    24,    24,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,    24,    24,  -104,  -104,    24,     5,    74,     8,  -104,
    -104,  -104,  -104,    82,  -104,    78,    72,  -104,    12,  -104,
    -104,  -104,    62,    -7,  -104,   108,    86,    24,  -104,    16,
      10,  -104,  -104,     5,  -104,  -104,    79,    77,  -104,   105,
      87,    10,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     6,    16,     0,     0,     0,     0,     0,    28,     0,
       6,     0,     0,    21,    21,     0,     0,    40,    33,     0,
      27,    29,     0,    32,    15,    16,     2,     0,    14,    12,
      13,     0,     7,    25,     0,     0,     0,     0,     0,     9,
      10,    11,    39,    56,    55,     0,    44,    47,    49,    51,
       0,     0,     0,    37,    26,    36,     0,     0,     0,     5,
      24,     0,     0,     0,    19,    58,     0,    59,     0,    53,
      36,     0,     0,    68,    65,    67,    64,    60,    66,    69,
      61,     0,     0,    62,    63,     0,    36,     0,     0,    42,
      30,    31,    17,     0,    20,     0,     0,    57,     0,    35,
      45,    46,    50,    48,    52,     0,    39,     0,    41,     0,
       0,    18,    54,    36,    38,    43,     0,    22,    34,     0,
      25,     0,    23,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,   -10,    97,  -103,   -64,    45,    84,  -104,  -104,
      96,    -8,  -104,    -9,  -104,  -104,   -59,  -104,   -50,  -104,
      43,   -25,    17,    31,    33,   -39,  -104,  -104,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    41,    54,    42,    14,    19,    20,
      44,    71,    72,    28,    29,    30,    31,    32,    63,    33,
      98,    99,    56,    57,    58,    59,    91,    95,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    60,    79,    15,   103,    21,   100,    75,    25,    77,
      25,    26,    38,    26,    16,    17,    39,   127,     1,     8,
       3,   109,    76,    37,    87,     6,    38,   117,   133,     4,
      39,   117,    10,    40,    90,     5,    97,   115,     9,    46,
      11,   101,   -36,    18,    18,    18,   118,    40,    13,    27,
     122,    27,    61,    47,    78,   126,   114,    23,   102,    49,
      50,    51,   105,    36,   128,    48,   124,    49,    50,    51,
      52,    53,    83,    84,   -39,    85,    24,    86,    87,    22,
       8,    88,    89,    34,    61,    43,    62,    64,    90,    81,
      82,    65,   125,    66,    93,    94,   120,     8,   110,   111,
      68,    70,    69,    73,    74,    80,   119,    96,   104,   107,
     116,   121,   123,    61,   131,   129,   130,    35,   106,    67,
      45,   108,   132,   113,   112
};

static const yytype_uint8 yycheck[] =
{
      25,    26,    52,    13,    68,    14,    65,    46,     5,    48,
       5,     8,    16,     8,    10,    11,    20,   120,     3,    19,
      46,    80,    47,    13,    31,    46,    16,    19,   131,     0,
      20,    19,    46,    37,    41,    29,    61,    96,    38,    15,
      39,    66,    39,    40,    40,    40,    38,    37,    14,    46,
      38,    46,    27,    29,    29,   119,    95,    46,    67,    43,
      44,    45,    72,    23,   123,    41,   116,    43,    44,    45,
      46,    47,    25,    26,    17,    28,    46,    30,    31,    18,
      19,    34,    35,    39,    27,    29,    29,    12,    41,    21,
      22,    39,   117,    17,    32,    33,    18,    19,    81,    82,
      27,    14,    39,    18,    39,     6,    24,     7,    38,    38,
      36,    39,     4,    27,     9,    36,    39,    20,    73,    35,
      24,    78,   130,    92,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    46,     0,    29,    46,    50,    19,    38,
      46,    39,    51,    14,    55,    50,    10,    11,    40,    56,
      57,    61,    18,    46,    46,     5,     8,    46,    61,    62,
      63,    64,    65,    67,    39,    51,    23,    13,    16,    20,
      37,    52,    54,    29,    58,    58,    15,    29,    41,    43,
      44,    45,    46,    47,    53,    69,    70,    71,    72,    73,
      69,    27,    29,    66,    12,    39,    17,    55,    27,    39,
      14,    59,    60,    18,    39,    73,    69,    73,    29,    66,
       6,    21,    22,    25,    26,    28,    30,    31,    34,    35,
      41,    74,    76,    32,    33,    75,     7,    69,    68,    69,
      64,    69,    61,    53,    38,    50,    54,    38,    68,    64,
      70,    70,    72,    71,    73,    64,    36,    19,    38,    24,
      18,    39,    38,     4,    66,    69,    53,    52,    64,    36,
      39,     9,    59,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    54,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     1,     1,     1,     3,     0,     4,     6,     4,
       3,     0,     4,     6,     1,     0,     3,     1,     0,     1,
       3,     3,     1,     1,     6,     4,     0,     2,     4,     0,
       1,     4,     1,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     2,     4,     1,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 96 "parser.y"
         {
        struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
            id->string = (yyvsp[-8].string);
            // printf("id str %s\n",id->string);
            // printf("From here\n");
            // printf("%s\n",$1->string);
            // char* ss=$2;
            // printf("wjio;gj;poi %d\n",id->tokenType);
            // printf("%s\n",$4);
            // printf("%s\n",$5);
	    	(yyval.node)=newNode(NODE_prog);
	    	addChild((yyval.node),newNode(NODE_PROGRAM));
	    	addChild((yyval.node),id);
	    	addChild((yyval.node),(yyvsp[-6].node));
	    	addChild((yyval.node),(yyvsp[-3].node));
	    	addChild((yyval.node),(yyvsp[-2].node));
	    	addChild((yyval.node),(yyvsp[-1].node));
	    	ASTROOT = (yyval.node);
	    	// printf("Reduction(prog -> PROGRAM ID ( identifier_list ) ; declartions subprogram_declartions");
	    	// printf("compound_statement.)\n");	

            // print_SHOW_NEWSCP;
        /*
        printf("program node is @ line: %d, column: %d\n",
                    @1.first_line, @1.first_column);
        yylval.val, yylval.text, yylval.dval to get the data (type defined in %union) you assigned by scanner.
        */
    }
#line 1644 "obj/parser.c"
    break;

  case 3:
#line 127 "parser.y"
                            {

                    (yyval.node)=newNode(NODE_identifier_list);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
            id->string = (yyvsp[0].string);
			addChild((yyval.node),id);
                    // printf("Reduction(identifier_list -> ID1)\n");
                }
#line 1658 "obj/parser.c"
    break;

  case 4:
#line 136 "parser.y"
                                                  {
                   (yyval.node)=newNode(NODE_identifier_list);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_COMMA));
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
            id->string = (yyvsp[0].string);
			addChild((yyval.node),id);
                    // printf("Reduction(identifier_list -> identifier_list , ID)\n");
                }
#line 1673 "obj/parser.c"
    break;

  case 5:
#line 148 "parser.y"
                                                                    {
            (yyval.node)=newNode(NODE_declarations);
			addChild((yyval.node),(yyvsp[-5].node));
			addChild((yyval.node),newNode(NODE_VAR));
			addChild((yyval.node),(yyvsp[-3].node));
			addChild((yyval.node),newNode(NODE_COLON));
			addChild((yyval.node),(yyvsp[-1].node));
			// printf("Reduction(declartions -> declarations VAR identifier_list : type ;)\n");
		}
#line 1687 "obj/parser.c"
    break;

  case 6:
#line 157 "parser.y"
          {
			(yyval.node)=newNode(NODE_declarations);
			// printf("Reduction(declartions -> )\n");
		}
#line 1696 "obj/parser.c"
    break;

  case 7:
#line 163 "parser.y"
                    {
    (yyval.node)=newNode(NODE_type);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(type -> standard_type)\n");
    }
#line 1706 "obj/parser.c"
    break;

  case 8:
#line 168 "parser.y"
                                                 { 
      
            struct nodeType* n;
			struct nodeType* n2;
	    	n = newNode(NODE_NUM);
	    	n2 = newNode(NODE_NUM);
			(yyval.node)=newNode(NODE_type);
			addChild((yyval.node),newNode(NODE_ARRAY));
            n->rValue = (yyvsp[-5].node);
            addChild((yyval.node),n);
			addChild((yyval.node),newNode(NODE_DOTDOT));
			n2->rValue = (yyvsp[-3].node);
			addChild((yyval.node),n2);
			addChild((yyval.node),newNode(NODE_OF));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(type -> ARRAY ( NUM .. NUM ) OF type)\n");
    }
#line 1728 "obj/parser.c"
    break;

  case 9:
#line 187 "parser.y"
                {
			(yyval.node)=newNode(NODE_standard_type);
            // printf("From here\n");
            // printf("%s\n",$1->string);
            // char* ss=$2;
            // printf("%d\n",$$->tokenType);
			addChild((yyval.node),newNode(NODE_INTEGERNUM));
			// printf("Reduction(standard_type -> INTEGER)\n");
		}
#line 1742 "obj/parser.c"
    break;

  case 10:
#line 196 "parser.y"
                    {
			(yyval.node)=newNode(NODE_standard_type);
			addChild((yyval.node),newNode(NODE_REALNUMBER));
			// printf("Reduction(standard_type -> REAL)\n");
		}
#line 1752 "obj/parser.c"
    break;

  case 11:
#line 201 "parser.y"
                {
    		(yyval.node)=newNode(NODE_num);
			addChild((yyval.node),newNode(NODE_SCIENTIFIC));
			// printf("Reduction(standard_type -> STRING)\n");
    	}
#line 1762 "obj/parser.c"
    break;

  case 12:
#line 209 "parser.y"
                       {
			(yyval.node)=newNode(NODE_standard_type);
			addChild((yyval.node),newNode(NODE_INTEGER));
			// printf("Reduction(standard_type -> INTEGER)\n");
		}
#line 1772 "obj/parser.c"
    break;

  case 13:
#line 214 "parser.y"
              {
			(yyval.node)=newNode(NODE_standard_type);
			addChild((yyval.node),newNode(NODE_REAL));
			// printf("Reduction(standard_type -> REAL)\n");
		}
#line 1782 "obj/parser.c"
    break;

  case 14:
#line 219 "parser.y"
            {
    		(yyval.node)=newNode(NODE_standard_type);
			addChild((yyval.node),newNode(NODE_STRING));
			// printf("Reduction(standard_type -> STRING)\n");
    	}
#line 1792 "obj/parser.c"
    break;

  case 15:
#line 226 "parser.y"
                                                                                  {
     
      (yyval.node)=newNode(NODE_subprogram_declarations);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			// printf("Reduction(subprogram_declarations -> subprogram_declarations subprogram_declaration ;)\n");	

            // printf("create a scope\n");


		}
#line 1808 "obj/parser.c"
    break;

  case 16:
#line 237 "parser.y"
          {

        // printf("create a scope\n");
			(yyval.node)=newNode(NODE_subprogram_declarations);
			// printf("Reduction(subprogram_declarations -> )\n");	
		}
#line 1819 "obj/parser.c"
    break;

  case 17:
#line 249 "parser.y"
                                          {
             (yyval.node)=newNode(NODE_subprogram_declaration);
							addChild((yyval.node),(yyvsp[-3].node));
							addChild((yyval.node),(yyvsp[-2].node));
							addChild((yyval.node),(yyvsp[-1].node));
            //   printf("Reduction(subprogram_declaration -> subprogram_head declarations compound_statement)\n"); 



            // print_SHOW_NEWSCP;            
            }
#line 1835 "obj/parser.c"
    break;

  case 18:
#line 262 "parser.y"
                                                                             {//funcion declaration
      (yyval.node)=newNode(NODE_subprogram_head);
			addChild((yyval.node),newNode(NODE_FUNCTION));
			struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = (yyvsp[-4].string);
            addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[-3].node));
			addChild((yyval.node),newNode(NODE_COLON));
			addChild((yyval.node),(yyvsp[-1].node));
    //   printf("Reduction(subprogram_head -> FUNCTION ID arguments : standard_type ;)\n");  
    }
#line 1852 "obj/parser.c"
    break;

  case 19:
#line 274 "parser.y"
                                                          {//procedure declaration
     (yyval.node)=newNode(NODE_subprogram_head);
			addChild((yyval.node),newNode(NODE_PROCEDURE));
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
            id->string = (yyvsp[-2].string);
            addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[-1].node));
    //   printf("Reduction(subprogram_head -> PROCEDURE ID arguments)\n"); 
    }
#line 1867 "obj/parser.c"
    break;

  case 20:
#line 285 "parser.y"
                                        {
      (yyval.node)=newNode(NODE_arguments);
			addChild((yyval.node),(yyvsp[-1].node));
    //   printf("Reduction(arguments -> ( parameter_list ) )\n");
    }
#line 1877 "obj/parser.c"
    break;

  case 21:
#line 290 "parser.y"
    {
    (yyval.node)=newNode(NODE_arguments);
    //   printf("Reduction(arguments ->  )\n");
    }
#line 1886 "obj/parser.c"
    break;

  case 22:
#line 296 "parser.y"
                                                        {
     (yyval.node)=newNode(NODE_parameter_list);
			addChild((yyval.node),(yyvsp[-3].node));
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_COLON));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(parameter_list -> optional_var identifier_list : type )\n");
    }
#line 1899 "obj/parser.c"
    break;

  case 23:
#line 304 "parser.y"
                                                                                 {
      (yyval.node)=newNode(NODE_parameter_list);
			addChild((yyval.node),(yyvsp[-5].node));
			addChild((yyval.node),(yyvsp[-4].node));
			addChild((yyval.node),newNode(NODE_COLON));
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_SEMICOLON));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
    }
#line 1914 "obj/parser.c"
    break;

  case 24:
#line 316 "parser.y"
                  {
        (yyval.node)=newNode(NODE_optional_var);
				addChild((yyval.node),newNode(NODE_VAR));
        // printf("Reduction(optional_var -> VAR )\n");
      }
#line 1924 "obj/parser.c"
    break;

  case 25:
#line 321 "parser.y"
        {
         (yyval.node)=newNode(NODE_optional_var);
        // printf("Reduction(optional_var ->  )\n");
      }
#line 1933 "obj/parser.c"
    break;

  case 26:
#line 330 "parser.y"
                       {
      (yyval.node)=newNode(NODE_compound_statement);
			addChild((yyval.node),newNode(NODE_PBEGIN));
			addChild((yyval.node),(yyvsp[-1].node));
			addChild((yyval.node),newNode(NODE_END));
    //   printf("Reduction(compound_statement -> begin optional_statements END )\n");
    }
#line 1945 "obj/parser.c"
    break;

  case 27:
#line 339 "parser.y"
                                    {
    (yyval.node)=newNode(NODE_optional_statements);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(optional_statements -> statement_list )\n");
    }
#line 1955 "obj/parser.c"
    break;

  case 28:
#line 344 "parser.y"
                      {
         (yyval.node)=newNode(NODE_optional_statements);
        // printf("Reduction(optional_statements ->  )\n");
      }
#line 1964 "obj/parser.c"
    break;

  case 29:
#line 351 "parser.y"
                           {
      (yyval.node)=newNode(NODE_statement_list);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statements_list -> statement )\n");
    }
#line 1974 "obj/parser.c"
    break;

  case 30:
#line 356 "parser.y"
                                                   {
     (yyval.node)=newNode(NODE_statement_list);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_SEMICOLON));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statements_list -> statement_list ; statement )\n");
    }
#line 1986 "obj/parser.c"
    break;

  case 31:
#line 365 "parser.y"
                                          {
      (yyval.node)=newNode(NODE_statement);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_ASSIGNMENT));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statement -> variable := expression )\n");  
    }
#line 1998 "obj/parser.c"
    break;

  case 32:
#line 372 "parser.y"
                       {
(yyval.node)=newNode(NODE_statement);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statement -> procedure_statement )\n");
    }
#line 2008 "obj/parser.c"
    break;

  case 33:
#line 377 "parser.y"
                      {
    (yyval.node)=newNode(NODE_statement);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statement -> compound_statement )\n");
    }
#line 2018 "obj/parser.c"
    break;

  case 34:
#line 382 "parser.y"
                                               {
     (yyval.node)=newNode(NODE_statement);
			addChild((yyval.node),newNode(NODE_IF));
			addChild((yyval.node),(yyvsp[-4].node));
			addChild((yyval.node),newNode(NODE_THEN));
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_ELSE));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statement -> IF expression THEN statement ELSE statement )\n");
    }
#line 2033 "obj/parser.c"
    break;

  case 35:
#line 392 "parser.y"
                                 {
      (yyval.node)=newNode(NODE_statement);
			addChild((yyval.node),newNode(NODE_WHILE));
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_DO));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(statement -> WHILE expression DO statement )\n");
    }
#line 2046 "obj/parser.c"
    break;

  case 36:
#line 400 "parser.y"
    {
    (yyval.node)=newNode(NODE_statement);
    //   printf("Reduction(statement ->  )\n");
    }
#line 2055 "obj/parser.c"
    break;

  case 37:
#line 406 "parser.y"
                          {
            (yyval.node)=newNode(NODE_variable);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
	    	id->string=(yyvsp[-1].string);
			addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(variable -> ID tail )\n");
    }
#line 2069 "obj/parser.c"
    break;

  case 38:
#line 417 "parser.y"
                                    {
      (yyval.node)=newNode(NODE_tail);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(tail -> ( expression ) tail )\n");
    }
#line 2080 "obj/parser.c"
    break;

  case 39:
#line 423 "parser.y"
   {
    (yyval.node)=newNode(NODE_tail);	
    //   printf("Reduction(tail -> )\n");  
    }
#line 2089 "obj/parser.c"
    break;

  case 40:
#line 429 "parser.y"
                                 {
      (yyval.node)=newNode(NODE_procedure_statement);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
	    	id->string=(yyvsp[0].string);
			addChild((yyval.node),id);
    //   printf("Reduction(procedure_statement -> ID )\n");
    }
#line 2102 "obj/parser.c"
    break;

  case 41:
#line 437 "parser.y"
                                            {
        (yyval.node)=newNode(NODE_procedure_statement);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
	    	id->string=(yyvsp[-3].string);
			addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[-1].node));
        // printf("Reduction(procedure_statement -> ID ( expression_list ) )\n");
    }
#line 2116 "obj/parser.c"
    break;

  case 42:
#line 448 "parser.y"
                             {
    (yyval.node)=newNode(NODE_expression_list);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(expression_list -> expression )\n");
    }
#line 2126 "obj/parser.c"
    break;

  case 43:
#line 453 "parser.y"
                                    {
     (yyval.node)=newNode(NODE_expression_list);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),newNode(NODE_COMMA));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(expression_list -> expression_list COMMA expression )\n");
    }
#line 2138 "obj/parser.c"
    break;

  case 44:
#line 462 "parser.y"
                            { 
                (yyval.node)=newNode(NODE_expression);
                addChild((yyval.node),(yyvsp[0].node));
                // printf("Reduction(expression -> boolexpression )\n");
            }
#line 2148 "obj/parser.c"
    break;

  case 45:
#line 467 "parser.y"
                                              {
                (yyval.node)=newNode(NODE_expression);
                addChild((yyval.node),(yyvsp[-2].node));
                addChild((yyval.node),(yyvsp[-1].node));
                addChild((yyval.node),(yyvsp[0].node));
                // printf("Reduction(expression -> boolexpression )\n");
           }
#line 2160 "obj/parser.c"
    break;

  case 46:
#line 474 "parser.y"
                                             {

                (yyval.node)=newNode(NODE_expression);
                addChild((yyval.node),(yyvsp[-2].node));
                addChild((yyval.node),(yyvsp[-1].node));
                addChild((yyval.node),(yyvsp[0].node));
                // printf("Reduction(expression -> boolexpression )\n");
           }
#line 2173 "obj/parser.c"
    break;

  case 47:
#line 484 "parser.y"
                                   {
      (yyval.node)=newNode(NODE_boolexpression);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(boolexpression -> simple_expression )\n");
    }
#line 2183 "obj/parser.c"
    break;

  case 48:
#line 489 "parser.y"
                                             {
    (yyval.node)=newNode(NODE_boolexpression);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(boolexpression -> simple_expression relop simple_expression )\n");
    }
#line 2195 "obj/parser.c"
    break;

  case 49:
#line 498 "parser.y"
                         {
    
        (yyval.node)=newNode(NODE_simple_expression);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(simple_expression -> term )\n");
    }
#line 2206 "obj/parser.c"
    break;

  case 50:
#line 504 "parser.y"
                                {
     (yyval.node)=newNode(NODE_simple_expression);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(simple_expression -> simple_expression addop term )\n");
    }
#line 2218 "obj/parser.c"
    break;

  case 51:
#line 513 "parser.y"
              {
        (yyval.node)=newNode(NODE_term);
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(term -> factor )\n");
    }
#line 2228 "obj/parser.c"
    break;

  case 52:
#line 518 "parser.y"
                     {
      (yyval.node)=newNode(NODE_term);
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(term -> term mulop factor )\n");
    }
#line 2240 "obj/parser.c"
    break;

  case 53:
#line 527 "parser.y"
                        {
        (yyval.node)=newNode(NODE_factor);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
	    	id->string=(yyvsp[-1].string);
			addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[0].node));
        // printf("Reduction(factor -> ID tail )\n");
    }
#line 2254 "obj/parser.c"
    break;

  case 54:
#line 536 "parser.y"
                                                 {
        (yyval.node)=newNode(NODE_factor);
			struct nodeType* id;
	    	id = newNode(NODE_IDENTIFIER);
	    	id->string=(yyvsp[-3].string);
			addChild((yyval.node),id);
			addChild((yyval.node),(yyvsp[-1].node));
    //   printf("Reduction(factor -> ID ( expression_list ) )\n");
    }
#line 2268 "obj/parser.c"
    break;

  case 55:
#line 545 "parser.y"
              {
      (yyval.node)=newNode(NODE_factor);
			struct nodeType* num;
	    	num = newNode(NODE_NUM);
	    	num->rValue=(yyvsp[0].node);
	    	addChild((yyval.node),num);
    //   printf("Reduction(factor -> NUM )\n");
    }
#line 2281 "obj/parser.c"
    break;

  case 56:
#line 553 "parser.y"
                   {
        (yyval.node)=newNode(NODE_factor);
			struct nodeType* str;
	    	str = newNode(NODE_LITERALSTR);
	    	str->string=(yyvsp[0].string);
	    	addChild((yyval.node),str);
        // printf("Reduction(factor -> String )\n");
    }
#line 2294 "obj/parser.c"
    break;

  case 57:
#line 561 "parser.y"
                                  {
        (yyval.node)=newNode(NODE_factor);
			addChild((yyval.node),(yyvsp[-1].node));
        // printf("Reduction(factor -> ( expression ) )\n");
    }
#line 2304 "obj/parser.c"
    break;

  case 58:
#line 566 "parser.y"
                   {
     (yyval.node)=newNode(NODE_factor);
			addChild((yyval.node),newNode(NODE_NOT));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(factor -> ( NOT factor ) )\n");
    }
#line 2315 "obj/parser.c"
    break;

  case 59:
#line 572 "parser.y"
                     {
     
     (yyval.node)=newNode(NODE_factor);
			addChild((yyval.node),newNode(NODE_SUBOP));
			addChild((yyval.node),(yyvsp[0].node));
    //   printf("Reduction(factor -> ( SUBOP factor ) )\n");
    }
#line 2327 "obj/parser.c"
    break;

  case 60:
#line 583 "parser.y"
             {
    (yyval.node)=newNode(NODE_addop);
			addChild((yyval.node),newNode(NODE_ADDOP));
    //   printf("Reduction(addop -> PLUS )\n");
    }
#line 2337 "obj/parser.c"
    break;

  case 61:
#line 588 "parser.y"
           {
    (yyval.node)=newNode(NODE_addop);
			addChild((yyval.node),newNode(NODE_SUBOP));
    //   printf("Reduction(addop -> MINUS )\n");
    }
#line 2347 "obj/parser.c"
    break;

  case 62:
#line 595 "parser.y"
             {
      (yyval.node)=newNode(NODE_mulop);
			addChild((yyval.node),newNode(NODE_MULOP));
    //   printf("Reduction(mulop -> STAR )\n");
    }
#line 2357 "obj/parser.c"
    break;

  case 63:
#line 600 "parser.y"
           {
      (yyval.node)=newNode(NODE_mulop);
			addChild((yyval.node),newNode(NODE_DIVOP));
    //   printf("Reduction(mulop -> SLASH )\n");
    }
#line 2367 "obj/parser.c"
    break;

  case 64:
#line 607 "parser.y"
             {
      (yyval.node)=newNode(NODE_relop);
    //   printf("LTOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_LTOP));
    //   printf("Reduction(relop -> LT )\n");
    }
#line 2378 "obj/parser.c"
    break;

  case 65:
#line 613 "parser.y"
            {

     (yyval.node)=newNode(NODE_relop);
    //  printf("GTOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_GTOP));
    //   printf("Reduction(relop -> GT )\n");
    }
#line 2390 "obj/parser.c"
    break;

  case 66:
#line 620 "parser.y"
            {
      (yyval.node)=newNode(NODE_relop);
    //   printf("EQOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_EQOP));
    //   printf("Reduction(relop -> EQUAL )\n");
    }
#line 2401 "obj/parser.c"
    break;

  case 67:
#line 626 "parser.y"
             {
      (yyval.node)=newNode(NODE_relop);
    //   printf("LETOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_LETOP));
    //   printf("Reduction(relop -> LE )\n");
    }
#line 2412 "obj/parser.c"
    break;

  case 68:
#line 632 "parser.y"
             {
      (yyval.node)=newNode(NODE_relop);
    //   printf("GETOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_GETOP));
    //   printf("Reduction(relop -> GE )\n");
    }
#line 2423 "obj/parser.c"
    break;

  case 69:
#line 638 "parser.y"
             {
      (yyval.node)=newNode(NODE_relop);
    //   printf("NEQOP %d\n",NODE_relop);
			addChild((yyval.node),newNode(NODE_NEQOP));
    //   printf("Reduction(relop -> NEQOP )\n");
    }
#line 2434 "obj/parser.c"
    break;


#line 2438 "obj/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 646 "parser.y"


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
    SymbolTable.size = 0;
    SymbolTable.status=1;
    ScopeStack[0]=&SymbolTable;
    printf("create a new Scope\n");
    /* printf("Create a new SymbolTable\n"); */
    semanticCheck(ASTROOT);
    printf("close a scope\n");
    /* printf("Close a SymbolTable\n"); */
    printf("\nEnd!\n");


    return 0;
}
