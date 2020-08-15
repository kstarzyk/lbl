/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
