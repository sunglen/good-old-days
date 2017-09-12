#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
main()
{
int i=0;
while(socket(AF_INET,SOCK_STREAM,0)!=-1){i++;}
printf("The MAX socket count is %d\n",i);
}

