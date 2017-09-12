#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include "socklib.h"
#include "sopen.c"
#include "sclose.c"
#include "sclient.c"
#include "sserver.c"

#define PORT 2121
#define MODE600 (S_IRUSR|S_IWUSR)
main(void)
{
     SOCKET *sp;
     int sd,temp_fd;

     signal(SIGCHLD,SIG_IGN);

     if((sp=sopen())==0)
       fatal("sopen()");
     if((temp_fd=open("temp_file",O_RDWR|O_CREAT|O_TRUNC,MODE600))==-1)fatal("open temp_file");
     for(;;)
     {
        if((sd=sserver(sp,PORT,0))==-1)
        fatal("sserver()");

        switch(fork())
        {
        case 0:
        do_service(sd,temp_fd);
        break;
        case -1:
        fatal("fork()");
        break;
        }
        close(sd);
     }
}
fatal(char *text)
{
     fprintf(stderr,"Error in %s\n",text);
     exit(1);
}
do_service(int sd,int temp_fd)
{
   char buf;
   int i;
   for(i=0;i<5;i++)
   {
     if(read(sd,&buf,1)==-1)fatal("read from sd");
     if(write(temp_fd,&buf,1)==-1)fatal("write to temp_file");
   }
   for(i=0;i<5;i++)
   {
     if(read(temp_fd,&buf,1)==-1)fatal("read from temp_file");
     if(write(sd,&buf,1)==-1)fatal("write to sd");
   }
   close(sd);
   close(temp_fd);

   exit(0);
}
/*服务程序样本*/