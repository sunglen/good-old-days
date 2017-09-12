int sserver(SOCKET *sp,int port,int sync)

/*SOCKET *sp;*/
/*int port,sync;*/
{
   int flags;
   struct hostent *hostent;
   char localhost[65];
   if(sp->bindflag==0)
   {
     if(gethostname(localhost,64)==-1||(hostent=gethostbyname(localhost))==0)
     return -1;
     sp->sin.sin_family=(short)hostent->h_addrtype;
     sp->sin.sin_port=htons((unsigned short)port);
     sp->sin.sin_addr.s_addr= *(unsigned long *)hostent->h_addr;

     if(bind(sp->sd,(struct sockaddr *)&sp->sin,sp->sinlen)==-1||listen(sp->sd,5)==-1)
     return -1;
     sp->bindflag=1;
   }
   switch(sync)
   {
   case 0:
        if((flags=fcntl(sp->sd,F_GETFL))==-1||fcntl(sp->sd,F_SETFL,flags&~O_NDELAY)==-1)
        return -1;
        break;
   case 1:
        if((flags=fcntl(sp->sd,F_GETFL))==-1||fcntl(sp->sd,F_SETFL,flags|O_NDELAY)==-1)
        return -1;
        break;
   default:
        return -1;
  }
  return accept(sp->sd,(struct sockaddr *)&sp->sin,&sp->sinlen);
}
