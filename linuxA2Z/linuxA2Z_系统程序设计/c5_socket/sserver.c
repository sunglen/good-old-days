



#include <netinet/in.h>

#define S_DELAY 0
#define S_NDELAY 1
#define S_RESET 0
#define S_SET 1
#define S_NAMLEN 64


typedef struct
{
    struct sockaddr_in sin;
    int sinlen;
    int bindflag;
    int sd;
}SOCKET;







sserver(SOCKET *sp,int port,int sync)

SOCKET *sp;
int port,sync;
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



