#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "socklib.h"
#include "sopen.c"
#include "sclose.c"
#include "sclient.c"
#include "sserver.c"

#define PORT 2121

main(void)
{
     SOCKET *sp;
     int sd;

     signal(SIGCHLD,SIG_IGN);

     if((sp=sopen())==0)
       fatal("sopen()");

     for(;;)
     {
        if((sd=sserver(sp,PORT,0))==-1)
        fatal("sserver()");

        switch(fork())
        {
        case 0:
        do_service(sd);
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
do_service(int sd)
{
   int i;
   char *mess_rec;
   char *mess="Would you like an apple?";
   for(i=0;i<24;i++)
   if(write(sd,&mess[i],1)==-1)fatal("send message");
   for(i=0;i<6;i++)
   if(read(sd,&mess_rec[i],1)==-1)fatal("receive message");
   mess_rec[i]='\0';
   printf("The mess is: %s\n",mess_rec);
   for(i=0;i<6;i++)
   if(write(sd,&mess_rec[i],1)==-1)fatal("answer");
   exit(0);
}
/*服务程序样本*/



