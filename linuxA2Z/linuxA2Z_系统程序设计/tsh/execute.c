#include "forkexec.c"

execute(int j)
{
   int i,fd,fds[2];

   if(infile[0]!='\0')
     cmdlin[0].infd=open(infile,O_RDONLY);

   if(outfile[0]!='\0')
     if(append==FALSE)
       cmdlin[j-1].outfd=open(outfile,O_WRONLY|O_CREAT|O_TRUNC,0666);
     else
       cmdlin[j-1].outfd=open(outfile,O_WRONLY|O_CREAT|O_APPEND,0666);

   if(backgnd==TRUE)
     signal(SIGCHLD,SIG_IGN);
   else
     signal(SIGCHLD,SIG_DFL);

   for(i=0;i<j;++i)
   {
     if(i<j-1)
     {
       pipe(fds);
       cmdlin[i].outfd=fds[1];
       cmdlin[i+1].infd=fds[0];
     }

  forkexec(&cmdlin[i]);

  if((fd=cmdlin[i].infd)!=0)
    close(fd);
  if((fd=cmdlin[i].outfd)!=1)
    close(fd);
  }

  if(backgnd==FALSE)
    while(wait(NULL)!=lastpid);
}



