/* strings --我的strings版本。*/
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 8192

main(int argc, char **argv)
{
	int c,n,i;
	char buf[BUFSIZE];
	
	/*命令行参数检查*/

	n=atoi(argv[2]);	
	
	while((c=getchar()) != EOF){
		if(isascii(c) &&
		  (isprint(c) || c=='\n' || c=='\t' || c==' ')){
		  	buf[i]=c;
			++i;
		}else if(i>=n){
			printf("%s\n",buf);
			i=0;
		}else{
			i=0;
		}
	}
	if(i>=n)printf("%s\n",buf);

	exit(0);
}
		
