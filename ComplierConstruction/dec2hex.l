%{
/* change all numbers from dec to hex */
#include <stdio.h>
#include <stdlib.h>
int count=0;
%}
digit [0-9]
number {digit}+
%%
{number} {	int n=atoi(yytext);
		printf("%x", n);
		if(n>9) count++;	
	 }
%%
main()
{
yylex();
fprintf(stderr, "number of replacements = %n\n", count);
return 0;
}

