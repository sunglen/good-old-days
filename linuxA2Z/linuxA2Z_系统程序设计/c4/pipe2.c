#include <unistd.h>
#include <stdio.h>
#include "fatal.c"
#include "mydup.c"

main()
{
      int fda[2];

      if(pipe(fda)==-1)
        fatal("creating pipe");

      switch (fork())
      {
      case -1:
        fatal("forking child");
        break;
      case 0:
     /*   close(1);*/
        my_dup(fda[1],1);
      /*  close(fda[1]); */
        close(fda[0]);
        execlp("ls","ls","-l",0);
        fatal("trying to exec ls");
        break;
      default:
     /*   close(0);*/
        my_dup(fda[0],0);
       /* close(fda[0]);*/
        close(fda[1]);
        execlp("wc","wc","-w",0);
        fatal("trying to exec wc");
        break;
      }
}
