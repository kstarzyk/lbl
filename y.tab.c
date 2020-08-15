/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "src/generator.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

Structure *program = NULL;


#line 92 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_NUMBER = 258,                /* T_NUMBER  */
    T_STRING = 259,                /* T_STRING  */
    T_REGEXP = 260,                /* T_REGEXP  */
    T_IDENT = 261,                 /* T_IDENT  */
    T_VREF = 262,                  /* T_VREF  */
    T_IREF = 263,                  /* T_IREF  */
    T_TRUE = 264,                  /* T_TRUE  */
    T_FALSE = 265,                 /* T_FALSE  */
    T_ASSIGN = 266,                /* T_ASSIGN  */
    T_COLON = 267,                 /* T_COLON  */
    T_COMMA = 268,                 /* T_COMMA  */
    T_PLUS_PLUS = 269,             /* T_PLUS_PLUS  */
    T_MINUS_MINUS = 270,           /* T_MINUS_MINUS  */
    T_PLUS_ASSIGN = 271,           /* T_PLUS_ASSIGN  */
    T_EQ = 272,                    /* T_EQ  */
    T_NEQ = 273,                   /* T_NEQ  */
    T_PLUS = 274,                  /* T_PLUS  */
    T_MINUS = 275,                 /* T_MINUS  */
    T_MULTIPLY = 276,              /* T_MULTIPLY  */
    T_DIVIDE = 277,                /* T_DIVIDE  */
    T_LEFT = 278,                  /* T_LEFT  */
    T_RIGHT = 279,                 /* T_RIGHT  */
    T_CLEFT = 280,                 /* T_CLEFT  */
    T_CRIGHT = 281,                /* T_CRIGHT  */
    T_TLEFT = 282,                 /* T_TLEFT  */
    T_TRIGHT = 283,                /* T_TRIGHT  */
    T_BLEFT = 284,                 /* T_BLEFT  */
    T_BRIGHT = 285,                /* T_BRIGHT  */
    T_ARGUMENTS = 286,             /* T_ARGUMENTS  */
    T_BEGIN = 287,                 /* T_BEGIN  */
    T_END = 288,                   /* T_END  */
    T_STATE = 289,                 /* T_STATE  */
    T_SEMICOLON = 290,             /* T_SEMICOLON  */
    T_NL = 291,                    /* T_NL  */
    T_PROCENT = 292,               /* T_PROCENT  */
    T_IF = 293,                    /* T_IF  */
    T_OSTREAM = 294,               /* T_OSTREAM  */
    T_ISTREAM = 295,               /* T_ISTREAM  */
    T_LOOP = 296,                  /* T_LOOP  */
    T_MINUS_ASSIGN = 297           /* T_MINUS_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_NUMBER 258
#define T_STRING 259
#define T_REGEXP 260
#define T_IDENT 261
#define T_VREF 262
#define T_IREF 263
#define T_TRUE 264
#define T_FALSE 265
#define T_ASSIGN 266
#define T_COLON 267
#define T_COMMA 268
#define T_PLUS_PLUS 269
#define T_MINUS_MINUS 270
#define T_PLUS_ASSIGN 271
#define T_EQ 272
#define T_NEQ 273
#define T_PLUS 274
#define T_MINUS 275
#define T_MULTIPLY 276
#define T_DIVIDE 277
#define T_LEFT 278
#define T_RIGHT 279
#define T_CLEFT 280
#define T_CRIGHT 281
#define T_TLEFT 282
#define T_TRIGHT 283
#define T_BLEFT 284
#define T_BRIGHT 285
#define T_ARGUMENTS 286
#define T_BEGIN 287
#define T_END 288
#define T_STATE 289
#define T_SEMICOLON 290
#define T_NL 291
#define T_PROCENT 292
#define T_IF 293
#define T_OSTREAM 294
#define T_ISTREAM 295
#define T_LOOP 296
#define T_MINUS_ASSIGN 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "src/parser.y"

	int fval;
    char* str;
    bool boolean;
    expression *expr;
    statement *stmt;
    enum Operator binop;

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_NUMBER = 3,                   /* T_NUMBER  */
  YYSYMBOL_T_STRING = 4,                   /* T_STRING  */
  YYSYMBOL_T_REGEXP = 5,                   /* T_REGEXP  */
  YYSYMBOL_T_IDENT = 6,                    /* T_IDENT  */
  YYSYMBOL_T_VREF = 7,                     /* T_VREF  */
  YYSYMBOL_T_IREF = 8,                     /* T_IREF  */
  YYSYMBOL_T_TRUE = 9,                     /* T_TRUE  */
  YYSYMBOL_T_FALSE = 10,                   /* T_FALSE  */
  YYSYMBOL_T_ASSIGN = 11,                  /* T_ASSIGN  */
  YYSYMBOL_T_COLON = 12,                   /* T_COLON  */
  YYSYMBOL_T_COMMA = 13,                   /* T_COMMA  */
  YYSYMBOL_T_PLUS_PLUS = 14,               /* T_PLUS_PLUS  */
  YYSYMBOL_T_MINUS_MINUS = 15,             /* T_MINUS_MINUS  */
  YYSYMBOL_T_PLUS_ASSIGN = 16,             /* T_PLUS_ASSIGN  */
  YYSYMBOL_T_EQ = 17,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 18,                     /* T_NEQ  */
  YYSYMBOL_T_PLUS = 19,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 20,                   /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 21,                /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 22,                  /* T_DIVIDE  */
  YYSYMBOL_T_LEFT = 23,                    /* T_LEFT  */
  YYSYMBOL_T_RIGHT = 24,                   /* T_RIGHT  */
  YYSYMBOL_T_CLEFT = 25,                   /* T_CLEFT  */
  YYSYMBOL_T_CRIGHT = 26,                  /* T_CRIGHT  */
  YYSYMBOL_T_TLEFT = 27,                   /* T_TLEFT  */
  YYSYMBOL_T_TRIGHT = 28,                  /* T_TRIGHT  */
  YYSYMBOL_T_BLEFT = 29,                   /* T_BLEFT  */
  YYSYMBOL_T_BRIGHT = 30,                  /* T_BRIGHT  */
  YYSYMBOL_T_ARGUMENTS = 31,               /* T_ARGUMENTS  */
  YYSYMBOL_T_BEGIN = 32,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 33,                     /* T_END  */
  YYSYMBOL_T_STATE = 34,                   /* T_STATE  */
  YYSYMBOL_T_SEMICOLON = 35,               /* T_SEMICOLON  */
  YYSYMBOL_T_NL = 36,                      /* T_NL  */
  YYSYMBOL_T_PROCENT = 37,                 /* T_PROCENT  */
  YYSYMBOL_T_IF = 38,                      /* T_IF  */
  YYSYMBOL_T_OSTREAM = 39,                 /* T_OSTREAM  */
  YYSYMBOL_T_ISTREAM = 40,                 /* T_ISTREAM  */
  YYSYMBOL_T_LOOP = 41,                    /* T_LOOP  */
  YYSYMBOL_T_MINUS_ASSIGN = 42,            /* T_MINUS_ASSIGN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_separator = 44,                 /* separator  */
  YYSYMBOL_top = 45,                       /* top  */
  YYSYMBOL_top_statements = 46,            /* top_statements  */
  YYSYMBOL_top_statement = 47,             /* top_statement  */
  YYSYMBOL_directive = 48,                 /* directive  */
  YYSYMBOL_pattern_block = 49,             /* pattern_block  */
  YYSYMBOL_block = 50,                     /* block  */
  YYSYMBOL_begin = 51,                     /* begin  */
  YYSYMBOL_end = 52,                       /* end  */
  YYSYMBOL_statement_list = 53,            /* statement_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_statement_if = 55,              /* statement_if  */
  YYSYMBOL_state = 56,                     /* state  */
  YYSYMBOL_state_block = 57,               /* state_block  */
  YYSYMBOL_declaration = 58,               /* declaration  */
  YYSYMBOL_arguments = 59,                 /* arguments  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_var_ref = 62,                   /* var_ref  */
  YYSYMBOL_expression_list = 63,           /* expression_list  */
  YYSYMBOL_binary_op = 64,                 /* binary_op  */
  YYSYMBOL_arguments_block = 65,           /* arguments_block  */
  YYSYMBOL_arg = 66                        /* arg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    67,    69,    71,    72,    76,    76,    76,
      76,    76,    76,    76,    79,    80,    88,    94,    96,   101,
     102,   105,   106,   111,   118,   119,   125,   127,   129,   133,
     147,   161,   172,   183,   189,   193,   194,   194,   196,   204,
     207,   212,   217,   218,   219,   220,   225,   227,   228,   229,
     230,   231,   239,   245,   254,   255,   262,   269,   270,   271,
     272,   273,   274,   275,   276,   280,   280,   282,   285
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_NUMBER", "T_STRING",
  "T_REGEXP", "T_IDENT", "T_VREF", "T_IREF", "T_TRUE", "T_FALSE",
  "T_ASSIGN", "T_COLON", "T_COMMA", "T_PLUS_PLUS", "T_MINUS_MINUS",
  "T_PLUS_ASSIGN", "T_EQ", "T_NEQ", "T_PLUS", "T_MINUS", "T_MULTIPLY",
  "T_DIVIDE", "T_LEFT", "T_RIGHT", "T_CLEFT", "T_CRIGHT", "T_TLEFT",
  "T_TRIGHT", "T_BLEFT", "T_BRIGHT", "T_ARGUMENTS", "T_BEGIN", "T_END",
  "T_STATE", "T_SEMICOLON", "T_NL", "T_PROCENT", "T_IF", "T_OSTREAM",
  "T_ISTREAM", "T_LOOP", "T_MINUS_ASSIGN", "$accept", "separator", "top",
  "top_statements", "top_statement", "directive", "pattern_block", "block",
  "begin", "end", "statement_list", "statement", "statement_if", "state",
  "state_block", "declaration", "arguments", "expression", "term",
  "var_ref", "expression_list", "binary_op", "arguments_block", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,    -6,    75,    -5,    -1,    -1,     2,    26,    73,    37,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    99,   -65,
     -65,    38,   -65,   -65,    60,   147,   -65,   147,   147,   147,
     147,   123,    50,   -65,   -65,   236,    15,    55,    29,   -65,
     -65,    88,     5,   -65,   -65,    61,   147,   -65,   212,   -65,
     236,     8,   173,    97,    97,    99,   224,   -65,   -65,   -65,
      99,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    52,
     147,   -65,   -65,   147,   147,   147,    76,    96,    11,   -65,
     100,    17,   -65,   -65,   161,   -65,    41,   -65,   147,   -65,
     147,    99,    64,    99,   -65,   -65,   236,   236,   236,   198,
      29,   118,   -65,   -65,   147,   -65,   -65,   -65,   -65,   236,
     236,    82,   -65,    85,   -65,   -65,   104,   186,   -65,   -65,
     -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    21,     0,     0,     0,     0,     0,     0,     4,
       5,     7,    11,    10,    12,    13,     9,     8,    21,    47,
      49,     0,    52,    53,     0,     0,    18,    54,     0,    54,
      54,     0,     0,    22,    24,    33,    46,    50,     0,    19,
      20,     0,     0,     1,     6,     0,    54,    48,     0,    46,
      55,     0,     0,    44,    45,    21,     0,    17,     3,     2,
       0,    63,    64,    57,    58,    59,    60,    61,    62,     0,
       0,    29,    30,     0,     0,     0,     0,     0,     0,    65,
       0,     0,    36,    15,     0,    16,     0,    43,     0,    41,
       0,    21,     0,    21,    23,    40,    28,    31,    32,     0,
       0,     0,    39,    66,     0,    35,    37,    14,    42,    56,
      25,     0,    26,     0,    51,    68,     0,     0,    34,    27,
      67,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -32,   -65,   -65,   116,   -65,   -65,    43,   -65,   -65,
     -16,    74,   -65,   -65,   -65,    54,   -65,   -24,    -2,   -65,
      63,   -65,   -65,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    60,     8,     9,    10,    11,    12,    13,    14,    15,
      32,    33,    34,    16,    81,    82,    17,    35,    49,    37,
      51,    69,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    48,    45,    50,    52,    50,    50,    56,    19,    20,
      83,    21,    22,    23,   103,    76,    36,    77,    84,    18,
      38,    88,    50,    80,     2,    24,    70,    41,    25,    71,
      72,    73,    42,    76,    27,    77,   115,   102,    89,    92,
      58,    59,     1,   105,    29,    30,    96,    39,    40,    97,
      98,    99,   107,    36,    88,    19,    20,    74,    36,    22,
      23,    46,     2,    47,   109,   108,   110,    95,     3,     4,
       5,     6,    24,    43,     7,   111,    57,   113,    19,    20,
     117,    21,    22,    23,    75,    58,    59,    85,   100,    36,
     112,    36,    53,    54,    80,    24,    58,    59,    25,    58,
      59,    26,    19,    20,    27,    21,    22,    23,   118,    86,
      88,   119,   104,    28,    29,    30,    31,    58,    59,    24,
      58,    59,    25,   101,   116,    44,    19,    20,    27,    21,
      22,    23,   120,     0,    94,   106,     0,    28,    29,    30,
      31,     0,     0,    24,     0,     0,    25,     0,    55,     0,
      19,    20,    27,    21,    22,    23,     0,     0,     0,     0,
       0,     0,    29,    30,     0,     0,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,    27,     0,    61,    62,
      63,    64,    65,    66,     0,    90,    29,    30,    67,    68,
      61,    62,    63,    64,    65,    66,    58,    59,    91,   121,
      67,    68,     0,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,    67,    68,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    67,    68,     0,   114,    61,
      62,    63,    64,    65,    66,     0,    87,     0,     0,    67,
      68,    61,    62,    63,    64,    65,    66,     0,     0,    93,
       0,    67,    68,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,    67,    68
};

static const yytype_int8 yycheck[] =
{
       2,    25,    18,    27,    28,    29,    30,    31,     3,     4,
      42,     6,     7,     8,    78,     4,    18,     6,    42,    25,
      25,    13,    46,     6,    25,    20,    11,    25,    23,    14,
      15,    16,     6,     4,    29,     6,   100,    26,    30,    55,
      35,    36,     5,    26,    39,    40,    70,     4,     5,    73,
      74,    75,    84,    55,    13,     3,     4,    42,    60,     7,
       8,    23,    25,     3,    88,    24,    90,    69,    31,    32,
      33,    34,    20,     0,    37,    91,    26,    93,     3,     4,
     104,     6,     7,     8,    29,    35,    36,    26,    12,    91,
      26,    93,    29,    30,     6,    20,    35,    36,    23,    35,
      36,    26,     3,     4,    29,     6,     7,     8,    26,    46,
      13,    26,    12,    38,    39,    40,    41,    35,    36,    20,
      35,    36,    23,    27,     6,     9,     3,     4,    29,     6,
       7,     8,    28,    -1,    60,    81,    -1,    38,    39,    40,
      41,    -1,    -1,    20,    -1,    -1,    23,    -1,    25,    -1,
       3,     4,    29,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    17,    18,
      19,    20,    21,    22,    -1,    12,    39,    40,    27,    28,
      17,    18,    19,    20,    21,    22,    35,    36,    25,    13,
      27,    28,    -1,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      28,    17,    18,    19,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    28,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    25,    31,    32,    33,    34,    37,    45,    46,
      47,    48,    49,    50,    51,    52,    56,    59,    25,     3,
       4,     6,     7,     8,    20,    23,    26,    29,    38,    39,
      40,    41,    53,    54,    55,    60,    61,    62,    25,    50,
      50,    25,     6,     0,    47,    53,    23,     3,    60,    61,
      60,    63,    60,    63,    63,    25,    60,    26,    35,    36,
      44,    17,    18,    19,    20,    21,    22,    27,    28,    64,
      11,    14,    15,    16,    42,    29,     4,     6,    65,    66,
       6,    57,    58,    44,    60,    26,    63,    24,    13,    30,
      12,    25,    53,    25,    54,    61,    60,    60,    60,    60,
      12,    27,    26,    66,    12,    26,    58,    44,    24,    60,
      60,    53,    26,    53,    30,    66,     6,    60,    26,    26,
      28,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    50,    50,    51,
      52,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    57,    57,    58,    59,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     2,     2,
       2,     0,     1,     3,     1,     4,     4,     5,     3,     2,
       2,     3,     3,     1,     5,     4,     1,     2,     4,     4,
       3,     3,     4,     3,     2,     2,     1,     1,     2,     1,
       1,     4,     1,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_STACK_PRINT (yyss, yyssp);

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* top: top_statements  */
#line 69 "src/parser.y"
                    {}
#line 1389 "y.tab.c"
    break;

  case 5: /* top_statements: top_statement  */
#line 71 "src/parser.y"
                              {
}
#line 1396 "y.tab.c"
    break;

  case 15: /* directive: T_PROCENT T_IDENT separator  */
#line 80 "src/parser.y"
                                {
    if (strcmp((yyvsp[-1].str), "cbc") == 0) {
      program->mode = CBC;
    } else if (strcmp((yyvsp[-1].str), "wbw") == 0) {
      program->mode = WBW;
    } else program->mode = LBL;
  }
#line 1408 "y.tab.c"
    break;

  case 16: /* pattern_block: T_REGEXP T_CLEFT statement_list T_CRIGHT  */
#line 88 "src/parser.y"
                                                        {
  statement* stmt = block_statement((yyvsp[-3].str), (yyvsp[-1].stmt)->list);
  append_statement(&program->blocks, stmt);
}
#line 1417 "y.tab.c"
    break;

  case 17: /* block: T_CLEFT statement_list T_CRIGHT  */
#line 94 "src/parser.y"
                                       {
    program->main = copy_stmt_list((yyvsp[-1].stmt)->list);
}
#line 1425 "y.tab.c"
    break;

  case 18: /* block: T_CLEFT T_CRIGHT  */
#line 96 "src/parser.y"
                     {
    (yyval.stmt) = statement_list(NULL);
}
#line 1433 "y.tab.c"
    break;

  case 19: /* begin: T_BEGIN block  */
#line 101 "src/parser.y"
                      { program->begin = copy_stmt_list((yyvsp[0].stmt)->list); }
#line 1439 "y.tab.c"
    break;

  case 20: /* end: T_END block  */
#line 102 "src/parser.y"
                      { program->end = copy_stmt_list((yyvsp[0].stmt)->list); }
#line 1445 "y.tab.c"
    break;

  case 21: /* statement_list: %empty  */
#line 105 "src/parser.y"
        { (yyval.stmt) = statement_list(NULL); }
#line 1451 "y.tab.c"
    break;

  case 22: /* statement_list: statement  */
#line 106 "src/parser.y"
                 { 
        // printf("STATEMENT\n");
        statement* list = statement_list(NULL); 
        append_statement(&list->list, (yyvsp[0].stmt)); 
        (yyval.stmt) = list; 
    }
#line 1462 "y.tab.c"
    break;

  case 23: /* statement_list: statement_list separator statement  */
#line 111 "src/parser.y"
                                           {
        append_statement(&(yyvsp[-2].stmt)->list, (yyvsp[0].stmt));
        // printf("TUTAJ APPEND NORMALNIE\n");
        (yyval.stmt) = (yyvsp[-2].stmt);
    }
#line 1472 "y.tab.c"
    break;

  case 24: /* statement: statement_if  */
#line 118 "src/parser.y"
                        { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1478 "y.tab.c"
    break;

  case 25: /* statement: T_IF expression T_COLON expression  */
#line 119 "src/parser.y"
                                       {
        statement* list = statement_list(NULL); 
        statement* sexpr = expr_statement((yyvsp[0].expr));
        append_statement(&list->list, sexpr); 
        (yyval.stmt) = if_statement((yyvsp[-2].expr), list, NULL);
        free_expression((yyvsp[0].expr));
}
#line 1490 "y.tab.c"
    break;

  case 26: /* statement: T_LOOP T_CLEFT statement_list T_CRIGHT  */
#line 125 "src/parser.y"
                                           {
    (yyval.stmt) = loop_statement(NULL, (yyvsp[-1].stmt));
}
#line 1498 "y.tab.c"
    break;

  case 27: /* statement: T_LOOP expression T_CLEFT statement_list T_CRIGHT  */
#line 127 "src/parser.y"
                                                      {
    (yyval.stmt) = loop_statement((yyvsp[-3].expr), (yyvsp[-1].stmt));
}
#line 1506 "y.tab.c"
    break;

  case 28: /* statement: term T_ASSIGN expression  */
#line 129 "src/parser.y"
                             {
        (yyval.stmt) = assign_statement((yyvsp[-2].expr), (yyvsp[0].expr));
        free_expression((yyvsp[-2].expr));
        free_expression((yyvsp[0].expr));
}
#line 1516 "y.tab.c"
    break;

  case 29: /* statement: term T_PLUS_PLUS  */
#line 133 "src/parser.y"
                     {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = PLUS,
                .lhs = copy_expression((yyvsp[-1].expr)),
                .rhs = &(expression){
                  .type = Number,
                  .value = 1,
                },
            }
        };
        (yyval.stmt) = assign_statement((yyvsp[-1].expr), &expr);
        free_expression((yyvsp[-1].expr));
}
#line 1536 "y.tab.c"
    break;

  case 30: /* statement: term T_MINUS_MINUS  */
#line 147 "src/parser.y"
                       {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = MINUS,
                .lhs = copy_expression((yyvsp[-1].expr)),
                .rhs = &(expression){
                  .type = Number,
                  .value = 1,
                },
            }
        };
        (yyval.stmt) = assign_statement((yyvsp[-1].expr), &expr);
        free_expression((yyvsp[-1].expr));
}
#line 1556 "y.tab.c"
    break;

  case 31: /* statement: term T_PLUS_ASSIGN expression  */
#line 161 "src/parser.y"
                                  {                
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op = PLUS,
                .lhs = copy_expression((yyvsp[-2].expr)),
                .rhs = copy_expression((yyvsp[0].expr)),
            }
        };
        (yyval.stmt) = assign_statement((yyvsp[-2].expr), &expr);
        free_expression((yyvsp[-2].expr));
}
#line 1573 "y.tab.c"
    break;

  case 32: /* statement: term T_MINUS_ASSIGN expression  */
#line 172 "src/parser.y"
                                    {
        expression expr = {
            .type = BinaryOp,
            .bop = {
                .op =  MINUS,
                .lhs = copy_expression((yyvsp[-2].expr)),
                .rhs = copy_expression((yyvsp[0].expr)),
            }
        };
        (yyval.stmt) = assign_statement((yyvsp[-2].expr), &expr);
        free_expression((yyvsp[-2].expr));
}
#line 1590 "y.tab.c"
    break;

  case 33: /* statement: expression  */
#line 183 "src/parser.y"
                 {
    (yyval.stmt) = expr_statement((yyvsp[0].expr));
    free_expression((yyvsp[0].expr));
}
#line 1599 "y.tab.c"
    break;

  case 34: /* statement_if: T_IF expression T_CLEFT statement_list T_CRIGHT  */
#line 189 "src/parser.y"
                                                              {
    (yyval.stmt) = if_statement((yyvsp[-3].expr), (yyvsp[-1].stmt), NULL);
}
#line 1607 "y.tab.c"
    break;

  case 38: /* declaration: T_IDENT T_COLON expression T_COMMA  */
#line 196 "src/parser.y"
                                                {
  if ((yyvsp[-1].expr)->type == List) {
  add_state_var(program, (yyvsp[-3].str), "array", (yyvsp[-1].expr)); 
  } else {
  add_state_var(program, (yyvsp[-3].str), "number", (yyvsp[-1].expr)); 
  }
}
#line 1619 "y.tab.c"
    break;

  case 40: /* expression: expression binary_op term  */
#line 207 "src/parser.y"
                                      { 
      (yyval.expr) = binary_expression((yyvsp[-1].binop), (yyvsp[-2].expr), (yyvsp[0].expr)); 
      free_expression((yyvsp[-2].expr)); 
      free_expression((yyvsp[0].expr));
    }
#line 1629 "y.tab.c"
    break;

  case 41: /* expression: T_BLEFT expression_list T_BRIGHT  */
#line 212 "src/parser.y"
                                       { 
      expression* expr = expression_list(NULL);
      expr = copy_expression((yyvsp[-1].expr));
      (yyval.expr) = expr;
    }
#line 1639 "y.tab.c"
    break;

  case 42: /* expression: T_IDENT T_LEFT expression_list T_RIGHT  */
#line 217 "src/parser.y"
                                             { (yyval.expr) = call_expression((yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 1645 "y.tab.c"
    break;

  case 43: /* expression: T_LEFT expression T_RIGHT  */
#line 218 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr);}
#line 1651 "y.tab.c"
    break;

  case 44: /* expression: T_OSTREAM expression_list  */
#line 219 "src/parser.y"
                                { (yyval.expr) = call_expression("printf", (yyvsp[0].expr)); }
#line 1657 "y.tab.c"
    break;

  case 45: /* expression: T_ISTREAM expression_list  */
#line 220 "src/parser.y"
                                { (yyval.expr) = call_expression("scanf", (yyvsp[0].expr));
    }
#line 1664 "y.tab.c"
    break;

  case 47: /* term: T_NUMBER  */
#line 227 "src/parser.y"
                { (yyval.expr) = number_expression((yyvsp[0].fval)); }
#line 1670 "y.tab.c"
    break;

  case 48: /* term: T_MINUS T_NUMBER  */
#line 228 "src/parser.y"
                       { (yyval.expr) = number_expression(-(yyvsp[0].fval)); }
#line 1676 "y.tab.c"
    break;

  case 49: /* term: T_STRING  */
#line 229 "src/parser.y"
               { (yyval.expr) = string_expression((yyvsp[0].str)); }
#line 1682 "y.tab.c"
    break;

  case 50: /* term: var_ref  */
#line 230 "src/parser.y"
              { (yyval.expr) = (yyvsp[0].expr); }
#line 1688 "y.tab.c"
    break;

  case 51: /* term: var_ref T_BLEFT expression T_BRIGHT  */
#line 231 "src/parser.y"
                                          {
      (yyval.expr) = index_expression((yyvsp[-3].expr), (yyvsp[-1].expr));
      free_expression((yyvsp[-3].expr)); 
      free_expression((yyvsp[-1].expr));
    }
#line 1698 "y.tab.c"
    break;

  case 52: /* var_ref: T_VREF  */
#line 239 "src/parser.y"
             { 
        enum VarScope scope;
        if ((yyvsp[0].str)[0] == '@') scope = ARGUMENTS;
        if ((yyvsp[0].str)[0] == '$') scope = STATE;
        memmove((yyvsp[0].str), (yyvsp[0].str)+1, strlen((yyvsp[0].str)));
        (yyval.expr) = var_ref(scope, (yyvsp[0].str)); 
    }
#line 1710 "y.tab.c"
    break;

  case 53: /* var_ref: T_IREF  */
#line 245 "src/parser.y"
               {
      enum VarScope scope;
      if ((yyvsp[0].str)[0] == '@') scope = ARGUMENTS;
      if ((yyvsp[0].str)[0] == '$') scope = STATE;
      memmove((yyvsp[0].str), (yyvsp[0].str)+1, strlen((yyvsp[0].str)));
      (yyval.expr) = var_ref_index(scope, atoi((yyvsp[0].str)));
    }
#line 1722 "y.tab.c"
    break;

  case 54: /* expression_list: %empty  */
#line 254 "src/parser.y"
                 { (yyval.expr) = expression_list(NULL); }
#line 1728 "y.tab.c"
    break;

  case 55: /* expression_list: expression  */
#line 255 "src/parser.y"
                 { 
        expression* expr = expression_list(NULL); 
        expression* temp = copy_expression((yyvsp[0].expr));
        append_expression(&expr->list, temp); 
        (yyval.expr) = expr;
        free_expression(temp);
    }
#line 1740 "y.tab.c"
    break;

  case 56: /* expression_list: expression_list T_COMMA expression  */
#line 262 "src/parser.y"
                                         {
        append_expression(&(yyvsp[-2].expr)->list, (yyvsp[0].expr));
        (yyval.expr) = (yyvsp[-2].expr);
        free_expression((yyvsp[0].expr));
    }
#line 1750 "y.tab.c"
    break;

  case 57: /* binary_op: T_PLUS  */
#line 269 "src/parser.y"
                   { (yyval.binop) = PLUS; }
#line 1756 "y.tab.c"
    break;

  case 58: /* binary_op: T_MINUS  */
#line 270 "src/parser.y"
              { (yyval.binop) = MINUS; }
#line 1762 "y.tab.c"
    break;

  case 59: /* binary_op: T_MULTIPLY  */
#line 271 "src/parser.y"
                 { (yyval.binop) = MULTIPLY; }
#line 1768 "y.tab.c"
    break;

  case 60: /* binary_op: T_DIVIDE  */
#line 272 "src/parser.y"
               { (yyval.binop) = DIVIDE; }
#line 1774 "y.tab.c"
    break;

  case 61: /* binary_op: T_TLEFT  */
#line 273 "src/parser.y"
              { (yyval.binop) = LT; }
#line 1780 "y.tab.c"
    break;

  case 62: /* binary_op: T_TRIGHT  */
#line 274 "src/parser.y"
               { (yyval.binop) = GT; }
#line 1786 "y.tab.c"
    break;

  case 63: /* binary_op: T_EQ  */
#line 275 "src/parser.y"
           { (yyval.binop) = EQ; }
#line 1792 "y.tab.c"
    break;

  case 64: /* binary_op: T_NEQ  */
#line 276 "src/parser.y"
            { (yyval.binop) = NEQ; }
#line 1798 "y.tab.c"
    break;

  case 67: /* arg: T_IDENT T_TLEFT T_IDENT T_TRIGHT  */
#line 283 "src/parser.y"
{
    add_argument(program, (yyvsp[-3].str), (yyvsp[-1].str), true);
}
#line 1806 "y.tab.c"
    break;

  case 68: /* arg: T_STRING T_COLON arg  */
#line 285 "src/parser.y"
                         {
  exit(1);
}
#line 1814 "y.tab.c"
    break;


#line 1818 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 291 "src/parser.y"


void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
  // gen_structure(program);
  printf("ERR: %s\n", s);
	exit(1);
}

char *remove_ext (char* myStr, char extSep, char pathSep) {
    char *retStr, *lastExt, *lastPath;

    // Error checks and allocate string.
    if (myStr == NULL) return NULL;
    if ((retStr = malloc (strlen (myStr) + 1)) == NULL) return NULL;
    // Make a copy and find the relevant characters.
    strcpy (retStr, myStr);
    lastExt = strrchr (retStr, extSep);
    lastPath = (pathSep == 0) ? NULL : strrchr (retStr, pathSep);
    // If it has an extension separator.
    if (lastExt != NULL) {
        // and it's to the right of the path separator.
        if (lastPath != NULL) {
            if (lastPath < lastExt) {
                // then remove it.
                *lastExt = '\0';
            }
        } else {
            // Has extension separator with no path separator.
            *lastExt = '\0';
        }
    }

    // Return the modified string.

    return retStr;
}

void preparse(int des_p[2]) {
  if (dup2(des_p[1], STDOUT_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }
    close(des_p[1]);
    close(des_p[0]);
}

void parse() {
    Structure s;
    program = &s;
    init_structure(program);

    do {
       yyparse();
      //  printf("%s\n", yytname[YYTRANSLATE(yytokentype)]);
       
    } while (!feof(yyin));

    gen_structure(program);
    free_structure(program);
}

void postparse() {
    fflush(stdout);
    close(STDOUT_FILENO);
    exit(EXIT_SUCCESS);
}

char* HELP_MESSAGE = "lang compiler (build 12412)\n\
  usage: langc [flags] file\n\
  flags:\n\
      -g    emits c code to stdout\n";

typedef struct {
  bool compile;
  bool generate;
  bool use_stdin;
  char *source_path;
  char *target_bin_name;
} CompilerOptions;

CompilerOptions get_default_options() {
  CompilerOptions opts = {
    .compile = true,
    .generate = false,
    .use_stdin = false,
    .source_path = NULL,
    .target_bin_name = NULL
  };
  return opts;
}

void parse_arguments(int argc, char **argv, CompilerOptions *options) {
  char *outname = NULL;
  int c;

  opterr = 0;

  while ((c = getopt(argc, argv, "go:")) != -1)
    switch (c) {
    case 'g':
      options->generate = true;
      options->compile = false;
      break;
    case 'c':
      outname = optarg;
      break;
    case '?':
      if (optopt == 'c')
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      exit(1);
    default:
      abort();
    }

  options->source_path = argv[optind];
  options->use_stdin = options->source_path == NULL;
  options->target_bin_name =
      !options->use_stdin ? outname != NULL ? outname : remove_ext(argv[optind], '.', '/') : "main";
  
  // for (index = optind; index < argc; index++)
  // printf ("Non-option argument %s\n", argv[index]);
}

int main(int argc, char **argv) {
  CompilerOptions options = get_default_options();
  parse_arguments(argc, argv, &options);

  int des_p[2];
  if (options.compile) {
    if (pipe(des_p) == -1) {
      perror("Pipe failed");
      exit(1);
    }
  }
  if (options.source_path != NULL) {
    yyin = fopen(options.source_path, "r");
  } else if (isatty(STDIN_FILENO)) {
    printf("%s", HELP_MESSAGE);
    exit(1);
  } else {
    yyin = stdin;
  }
  if (options.compile) {
    if (fork() == 0) {
      if (dup2(des_p[1], STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
      }
      close(des_p[1]);
      close(des_p[0]);
      parse();
      postparse();
    }
  } else {
    parse();
    return EXIT_SUCCESS;
  }

  if (fork() == 0) {
    close(STDIN_FILENO); // closing stdin
    dup(des_p[0]);       // replacing stdin with pipe read
    close(des_p[1]);     // closing pipe write
    close(des_p[0]);

    char *prog2[] = {"gcc", "-o", options.target_bin_name,
                     "-x",  "c",  "vendors/tiny-regex-c/re.c",
                     "-",   NULL};
    execvp(prog2[0], prog2);
    perror("execvp failed");
    exit(1);
  }

  if (options.compile) {
    close(des_p[0]);
    close(des_p[1]);
    wait(0);
    wait(0);
  }

  return 0;
}

int yywrap(void) { return 0; }
