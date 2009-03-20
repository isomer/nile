#include <stdio.h>
#include <stdlib.h>

void yyparse(void);

void yyerror(const char *error)
{
	fprintf(stderr,"%s\n",error);
	exit(1);
}

int main(int argc, char *argv[])
{
	yyparse();
}
