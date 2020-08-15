%option noyywrap

%{
#include <stdio.h>
#include <stdbool.h>

#define YY_DECL int yylex()
// #define yyterminate() return (END);


// to match *,[,],(,)," ,\,{,}in flex, you have 
// to use escape character(not needed for single quote character).
// ws [\t\n\r ]

#include "src/ast.h"
#include "y.tab.h"

%}

%option nounput
%option noinput

digit [0-9]
id [a-zA-Z_]
ws [\t\n\r ]
string (\".*\")

regex (\/.*\/)
multiline_comment ###([^*]|[\r\n]|(#+([^*/]|[\r\n])))*###
comment (#.*\n)
%%

{comment}       {}
{multiline_comment} {}
{ws}+ // ignore all whitespace
{digit}+\.{digit}+ 	{yylval.fval = atof(yytext); return T_NUMBER;}
{digit}+		    {yylval.fval = atoi(yytext); return T_NUMBER;}
{string}        {yylval.str = (char*)strdup(yytext); return T_STRING;}
{regex}        {yylval.str = (char*)strdup(yytext); return T_REGEXP;}
"arguments"     {return T_ARGUMENTS;}
"begin"         {return T_BEGIN;}
"end"           {return T_END;}
"state"         {return T_STATE;}
"true"          {return T_TRUE;}
"false"         {return T_FALSE;}
"loop"         {return T_LOOP;}
"!="            {return T_NEQ; }
"=="            {return T_EQ; }
"++"            {return T_PLUS_PLUS;}
"--"            {return T_MINUS_MINUS;}
"+="            {return T_PLUS_ASSIGN;}
"-="            {return T_MINUS_ASSIGN;}
{id}+           {yylval.str = (char*)strdup(yytext); return T_IDENT;}
@{id}+          {yylval.str = (char*)strdup(yytext); return T_VREF; }
${id}+          {yylval.str = (char*)strdup(yytext); return T_VREF; }
@{digit}       {yylval.str = (char*)strdup(yytext); return T_IREF; }
${digit}       {yylval.str = (char*)strdup(yytext); return T_IREF; }

"+"		        {yylval.str = (char*)strdup(yytext); return T_PLUS;}
"-"		        {return T_MINUS;}
"<<"		    {return T_OSTREAM;}
">>"		    {return T_ISTREAM;}
"@"             { return T_ARGUMENTS; }
"$"             { return T_STATE; }

"?"		        {return T_IF;}
","		        {return T_COMMA;}
":"		        {return T_COLON;}
";"		        {return T_SEMICOLON;}
"*"		        {return T_MULTIPLY;}
"("		        {return T_LEFT;}
")"		        {return T_RIGHT;}
"{"		        {return T_CLEFT;}
"}"		        {return T_CRIGHT;}
"<"		        {return T_TLEFT;}
">"		        {return T_TRIGHT;}
"="		        {return T_ASSIGN;}

"["             {return T_BLEFT;}
"]"             {return T_BRIGHT;}

"%"             {return T_PROCENT;}
%%

