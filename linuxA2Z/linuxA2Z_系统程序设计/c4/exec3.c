#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "fatal.c"
#define SIZE 4

main(int argc,char **argv)
{
    int infd,outfd,fda[2],val,count=1;
    char *buf;
    infd=open(argv[1],O_RDONLY);
    outfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
    pipe(fda);
    val=fork();
    while(count>0)
    {
      if(val)
      {
      count=read(infd,buf,SIZE);if(count==-1)fatal("read from infile");
      close(fda[0]);
      if(write(fda[1],buf,SIZE)==-1)fatal("write to fda[1]");
      }
      else
      {
      close(fda[1]);
      count=read(fda[0],buf,SIZE);if(count==-1)fatal("read from fda[0]");
      if(write(outfd,buf,SIZE)==-1)fatal("write to outfile");
      }
   }
   close(infd);close(outfd);

}

