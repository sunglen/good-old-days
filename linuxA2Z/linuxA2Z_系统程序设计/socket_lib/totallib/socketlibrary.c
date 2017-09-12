#include "Preamble.h"

/*sopen函数*/
SOCKET *sopen(void)
{
 SOCKET *sp;
 if((sp=(SOCKET *)malloc(sizeof(SOCKET)))==0)
 return 0;
 if((sp->sd=socket(AF_INET,SOCK_STREAM,0))==-1)
 {
     free(sp);
     return 0;
 }
 sp->sinlen=sizeof(sp->sin);
 sp->bindflag=S_RESET;
 return sp;
}

/*sclose函数*/
sclose(SOCKET *sp)
{
 int sd;
 sd=sp->sd;
 free(sp);
 return close(sd);
}

/*sclient函数*/
sclient(SOCKET *sp,char *name,int port)
{
   struct hostent *hostent;
   if((hostent=gethostbyname(name))==0)
   return -1;

   sp->sin.sin_family=(short)hostent->h_addrtype;
   sp->sin.sin_port=htons((unsigned short)port);
   sp->sin.sin_addr.s_addr= *(unsigned long *)hostent->h_addr;

   if(connect(sp->sd,(struct sockaddr *)&sp->sin,sp->sinlen)==-1)
   return -1;

   return sp->sd;
}

/*sserver函数*/
sserver(SOCKET *sp,int port,int sync)
{
   int flags;
   struct hostent *hostent;
   char localhost[S_NAMLEN+1];
   if(sp->bindflag==S_RESET)
   {
     if(gethostname(localhost,S_NAMLEN)==-1||(hostent=gethostbyname(localhost))==0)
     return -1;
     sp->sin.sin_family=(short)hostent->h_addrtype;
     sp->sin.sin_port=htons((unsigned short)port);
     sp->sin.sin_addr.s_addr= *(unsigned long *)hostent->h_addr;

     if(bind(sp->sd,(struct sockaddr *)&sp->sin,sp->sinlen)==-1||listen(sp->sd,5)==-1)
     return -1;
     sp->bindflag=S_SET;
   }
   switch(sync)
   {
   case S_DELAY:
        if((flags=fcntl(sp->sd,F_GETFL))==-1||fcntl(sp->sd,F_SETFL,flags&~O_NDELAY)==-1)
        return -1;
        break;
   case S_NDELAY:
        if((flags=fcntl(sp->sd,F_GETFL))==-1||fcntl(sp->sd,F_SETFL,flags|O_NDELAY)==-1)
        return -1;
        break;
   default:
        return -1;
  }
  return accept(sp->sd,(struct sockaddr *)&sp->sin,&sp->sinlen);
}