//exercise 2-A-14: 输出1-99之间不能被2和3整除的数字，每10个数字一行排列。
#include <iostream.h>
#include <stdio.h>

main(void)
{
	int i, n=0;
	
	for(i=1;i<=99;i++){
		if(i%2==0 || i%3==0)
			continue;
		printf("%2d ",i);
		if(++n%10==0)
			cout<<endl;
	}

	cout<<endl;

	return 0;
}
