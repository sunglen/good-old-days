#include <unistd.h>
#include <stdio.h>
/*#include "fatal.c" */

int my_dup(int oldfd,int newfd)
{
 int temp_fd[1000],i=0,j;
 close(newfd);
 while((temp_fd[i]=dup(oldfd))<newfd){i++;}
 for(j=i-1;j>=0;j--)close(temp_fd[j]);
 return 0;
}



