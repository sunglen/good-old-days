%{
/* add line number for each line */
#include <stdlib.h>
#include <stdio.h>
int lineno=1;
%}
%%
.*\n { printf("%d %s", lineno++, yytext); }
%%
int main()
{
yylex();
return 0;
}

