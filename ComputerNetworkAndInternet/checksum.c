/*checksum.c: generate 16 bit checksum.*/
#include <stdio.h>

int main(void)
{
	int tn0,tn1;
	int sum=0;
	while((tn0=getc(stdin))!=EOF && (tn1=getc(stdin))!=EOF){
		tn0<<=8;
		sum+=(tn0|tn1);
	}
	while(sum>0xffff){
		sum=(sum&0x0000ffff)+(sum>>16);
	}
	printf("checksum:%X\n",sum);
}
