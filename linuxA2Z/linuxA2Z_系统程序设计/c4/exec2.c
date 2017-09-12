#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "fatal.c"

main()
{
    int fda[2];char *buf;
    int return_val=0,i=0;
    pipe(fda);
    fcntl(fda[1],F_SETFL,O_NONBLOCK);

   if(fork())
   {
     close(fda[0]);
     while(return_val!=-1)
     {
      return_val=write(fda[1],"a",1);
      i++;
     }
   }
    else
    {
    read(fda[0],buf,1);
    }
   printf("管道的容量是: %d bytes\n",i);
}


