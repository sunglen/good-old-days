#include "Preamble.h"
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
