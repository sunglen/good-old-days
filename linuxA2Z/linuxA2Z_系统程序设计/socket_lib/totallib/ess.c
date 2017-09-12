#include "Preamble.h"
#include <string.h>
#include <signal.h>

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
        if((sd=sserver(sp,PORT,S_DELAY))==-1)
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
   int i,fd;
   char *name;
   char c,namlen;

   if(read(sd,&namlen,1)!=1)
      fatal("namlen read()");

   if((name=(char *)malloc(namlen+8))==0)
     fatal("malloc()");

   for(i=0;i<namlen;++i)
     if(read(sd,&name[i],1)!=1)
       fatal("file name read()");

   name[i]='\0';

   if(strchr(name,'/'))
     fatal("illegal file name");

   if((fd=open(name,O_RDONLY))==-1)
      fatal(strcat(name,"open()"));

   while((i=read(fd,&c,1))!=0)
     if(i==-1)
       fatal("file read()");
     else if(write(sd,&c,1)!=1)
       fatal("write()");

   exit(0);
}



