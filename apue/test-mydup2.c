#include <stdio.h>
#include <unistd.h>

int mydup2(int, int);

int main(void)
{
	char *s="hello";
	if(mydup2(1, 100) != 100)
		exit(1);
	if(write(100, s, 5) != 5)
		exit(1);
	return 0;
}

