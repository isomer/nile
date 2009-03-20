%{
#include "ast.h"
#include "parse.tab.hpp"

#define YYDECL int yylex(void);
#include <string.h>
%}

%option yylineno
%option noyywrap
%option never-interactive

%%
[0-9]+			{ yylval.num=atoi(yytext); return TOK_INT; }
fn			{ return TOK_FN; }
[a-zA-Z][a-zA-Z0-9]* 	{ yylval.str=strdup(yytext);return TOK_ID; }
==			{ return TOK_EQ; }
[-{}\[\]()+*/<>=;,.:]	{ return *yytext; }
[\ \t]+			{ return TOK_WHITE; }
\"([^"]|\\\")*\"	{ yytext[strlen(yytext)-1]='\0'; yylval.str=strdup(yytext+1);return TOK_STRING; }
\n			{ return TOK_EOL; }
