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

main(int argc,char **argv)
{
 SOCKET *sp;
 int sd;
 char count;

 if(argc!=2)fatal("command line parameters");
 if((sp=sopen())==0)fatal("sopen()");
 if((sd=sclient(sp,argv[1],PORT))==-1)fatal("sclient()");
 printf("当前用户数为:");
 while(read(sd,&count,1)==1)write(1,&count,1);


 close(sd);
 sclose(sp);
}

fatal(char *text)
{
    fprintf(stderr,"Error in %s\n",text);
    exit(1);
}
/*客户程序样本-练习题2,第18章*/