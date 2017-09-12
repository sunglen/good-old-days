#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/param.h>
#include <setjmp.h>
#include "socklib.h"
#include "sopen.c"
#include "sclose.c"
#include "sclient.c"
#include "sserver.c"
#define NA_EXIT 0
#define NA_RESTART 1
#include "setup_daemon.c"
#include "fatal.c"

#define PORT 2122

#define MAX_LEN 80
#define MAX_USERS 10

#define LINE_READY 1
#define LOGGED_OUT 2

struct client
{
       int sd;
       char in_use;
       char next;
       char text[MAX_LEN+1];
}user[MAX_USERS];

jmp_buf env;

main(void)
{
     SOCKET *sp;
     int sd,i,flags;
     setup_daemon();
     signal(SIGCHLD,SIG_IGN);

     if((sp=sopen())==0)
       fatal("sopen()",NA_EXIT);
     setjmp(env);
     loop:
        if((sd=sserver(sp,PORT,1))!=-1)
           grab_user_slot(sd);
        else if(errno!=EWOULDBLOCK)
           fatal("sserver()",NA_EXIT);
        for(i=0;i<MAX_USERS;++i)
           if(user[i].in_use)
             switch(user_state(i))
             {
             case LINE_READY:
                  broadcast_line(i);
                  break;
             case LOGGED_OUT:
                  free_user_slot(i);
                  break;
             }
     goto loop;

}
user_state(int slot)
{
    char *ptr;
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
}

broadcast_line(int slot)
{
   int i,n;
   for(i=0;i<MAX_USERS;++i)
      if(user[i].in_use&&i!=slot)
      {
        n=strlen(user[slot].text);
        write(user[i].sd,user[slot].text,n);
      }
}

grab_user_slot(int sd)
{
   int i,flags;
   for(i=0;i<MAX_USERS;++i)
   {
      if(!user[i].in_use)
      {
         user[i].in_use=1;
         user[i].sd=sd;
         user[i].next=0;

         if((flags=fcntl(sd,F_GETFL))==-1||fcntl(sd,F_SETFL,flags|O_NDELAY)==-1)
         fatal("fcntl()",NA_EXIT);

         break;
     }
  }
  if(i==MAX_USERS)
  {
    write(sd,"Too many users - sorry...\n",26);
    close(sd);
  }
}

free_user_slot(int slot)
{
   user[slot].in_use=0;
   close(user[slot].sd);
}
/*服务程序样本--chat-daemon*/
