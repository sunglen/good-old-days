//test selsort

#include <stdio.h>
#include <stdlib.h>

void selsort(int *, int);

main(void)
{
	int i, mydata[20];
	
	srand(10);
	
	printf("排序前：\n");
	for(i=0;i<20;i++){
		mydata[i]=rand()%50;		
		printf("%d ", mydata[i]);
	}	
	
	selsort(mydata, 20);

	printf("\n排序后：\n");
	for(i=0;i<20;i++){
		printf("%d ", mydata[i]);
	}	
      
	printf("\n");
	return 0;
}

