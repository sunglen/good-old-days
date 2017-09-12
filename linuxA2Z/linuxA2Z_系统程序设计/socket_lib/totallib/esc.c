#include "Preamble.h"
#include <string.h>
#include <signal.h>

#define PORT 2121

main(int argc,char **argv)
{
 SOCKET *sp;
 FILE *fp;
 int sd,i;
 char namlen,c;

 if(argc!=4)fatal("command line parameters");
 if((fp=fopen(argv[3],"w"))==0)fatal("opening local file");
 if((sp=sopen())==0)fatal("sopen()");
 if((sd=sclient(sp,argv[1],PORT))==-1)fatal("sclient()");

 namlen=strlen(argv[2]);

 if(write(sd,&namlen,1)!=1)fatal("sending namlen");

 for(i=0;i<namlen;i++)
    if(write(sd,&argv[2][i],1)!=1)fatal("sending file name");

 while((i=read(sd,&c,1))!=0)
      if(i==-1)fatal("read remote file");
      else if(putc(c,fp)==EOF)fatal("writing local file");

 close(sd);
 fclose(fp);
 sclose(sp);
}

fatal(char *text)
{
    fprintf(stderr,"Error in %s\n",text);
    exit(1);
}
/*客户程序样本*/