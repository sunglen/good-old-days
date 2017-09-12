#include <unistd.h>
#include <stdio.h>
#include "fatal.c"

main()
{
      int fda[2];
      char buf[1];

      if(pipe(fda)==-1)
         fatal("creating pipe");
      printf("The fda[0] is %d\n The fda[1] is %d\n",fda[0],fda[1]);
      switch (fork())
      {
      case -1:
          fatal("forking child");
          break;
      case 0:
          printf("Child Process is runing\n");
          close(fda[1]);
          read(fda[0],buf,1);
          printf("%c\n",buf[0]);
          break;
      default:
          printf("Parent Process is runnig\n");
          close(fda[0]);
          write(fda[1],"a",1);
          break;
      }
}

