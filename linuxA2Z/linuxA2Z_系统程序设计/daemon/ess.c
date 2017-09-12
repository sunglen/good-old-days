#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <setjmp.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "socklib.h"
#include "sopen.c"
#include "sclose.c"
#include "sclient.c"
#include "sserver.c"

#define PORT 2121
#define NA_EXIT 0
#define NA_RESTART 1
jmp_buf env;
 

#include "fatal.c"
#include "setup_daemon.c"

main(void)
{
     SOCKET *sp;
     int sd;

     setup_daemon();
     signal(SIGCHLD,SIG_IGN);

     if((sp=sopen())==0)
       fatal("sopen()",NA_EXIT);

     setjmp(env);
     
     for(;;)
     {
        if((sd=sserver(sp,PORT,0))==-1)
        fatal("sserver()",NA_RESTART);

        switch(fork())
        {
        case 0:
        do_service(sd);
        break;
        case -1:
        fatal("fork()",NA_RESTART);
        break;
        }
        close(sd);
     }
}
do_service(int sd)
{
   int i,fd;
   char *name;
   char c,namlen;

   if(read(sd,&namlen,1)!=1)
      fatal("namlen read()",NA_EXIT);

   if((name=(char *)malloc(namlen+8))==0)
     fatal("malloc()",NA_EXIT);

   for(i=0;i<namlen;++i)
     if(read(sd,&name[i],1)!=1)
       fatal("file name read()",NA_EXIT);

   name[i]='\0';

   if(strchr(name,'/'))
     fatal("illegal file name",NA_EXIT);

   if((fd=open(name,O_RDONLY))==-1)
      fatal(strcat(name,"open()"),NA_EXIT);

   while((i=read(fd,&c,1))!=0)
     if(i==-1)
       fatal("file read()",NA_EXIT);
     else if(write(sd,&c,1)!=1)
       fatal("write()",NA_EXIT);

   exit(0);
}
/*服务程序样本--DAEMON*/



