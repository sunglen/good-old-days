
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
 sp->bindflag=0; /*S_RESET;*/
 return sp;
}

