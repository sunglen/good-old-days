#include <stdio.h>

main(void)
{
	int i, n=0;
	
	for(i=1;i<=99;i++){
		if(i%2==0 || i%3==0)
			continue;
		printf("%2d ",i);
		if(++n%10==0)
			printf("\n");
	}

	printf("\n");
}
