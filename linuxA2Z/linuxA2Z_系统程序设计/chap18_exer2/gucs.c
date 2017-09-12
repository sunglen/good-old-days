#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include "socklib.h"
#include "sopen.c"
#include "sclose.c"
#include "sclient.c"
#include "sserver.c"

#define PORT 2121
#define FLAGS (O_CREAT|O_TRUNC|O_RDWR)
#define MODE600 (S_IRUSR|S_IWUSR)

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
  int fda[2];int fd;
  int *statval;
  char count;
  if(pipe(fda)==-1)fatal("pipe()");
  if(fork())
  {
    close(1);
    dup(fda[1]);
    close(fda[1]);
    close(fda[0]);
    execlp("who","who",0);
    fatal("trying to exec who");
  }
  else
  {
    close(0);
    dup(fda[0]);
    close(fda[0]);
    close(fda[1]);
    close(1);
    if((fd=open("tmp",FLAGS,MODE600))==-1)fatal("creat tmp");
    printf("fd is %d\n",fd);
    if(!fork())execlp("wc","wc","-l",0);
    waitpid(-1,statval,0);
   /* if(read(fd,&count,1)==-1)fatal("read from tmp");
    if(write(sd,&count,1)==-1)fatal("write to sd");    */
    lseek(fd,6,SEEK_SET);
    while(read(fd,&count,1)==1)write(sd,&count,1);

  }

}

/*服务程序样本-练习题2,第18章*/
/* char *ptr;
 int n;
 ptr=&user[slot].text[user[slot].next];
 while((n=read(user[slot].sd,ptr,1))==1)
 {
      if(*ptr=='\n')
      {
         *(ptr+1)='\0';
         user[slot].next=0;
         return LINE_READY;
      }
      if(++user[slot].next==MAX_LEN)
        --user[slot].next;
      else
        ++ptr;
 }
 if(n==0)
   return LOGGED_OUT;
   return 0;


adcast_line(int slot)

int i,n;
for(i=0;i<MAX_USERS;++i)
   if(user[i].in_use&&i!=slot)
   {
     n=strlen(user[slot].text);
     write(user[i].sd,user[slot].text,n);
   }
   if((fd_fifo=open("myfifo",O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR))==-1)fatal("open myfifo")

  */
