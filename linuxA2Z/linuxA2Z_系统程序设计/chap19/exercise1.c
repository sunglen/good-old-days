#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void trapper(int);

main()
{
    int i;
    for(i=1;i<20;i++)
       signal(i,trapper);
    for(;;);
}

void trapper(int signum)
{
     signal(signum,trapper);
     printf("Just received signal number %d\n",signum);
}
