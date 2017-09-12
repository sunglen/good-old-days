



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







sclient(SOCKET *sp,char *name,int port)
{
   struct hostent *hostent;
   if((hostent=gethostbyname(name))==0)
   return -1;

   sp->sin.sin_family(short)hostent->h_addrtype;
   sp->sin.sin_port=htons((unsigned short)port);
   sp->sin.sin_addr.s_addr= *(unsigned long *)hostent->h_addr;

   if(connct(sp->sd,(struct sockaddr *)&sp->sin,sp->sinlen)==-1)
   return -1;

   return sp->sd;
}
