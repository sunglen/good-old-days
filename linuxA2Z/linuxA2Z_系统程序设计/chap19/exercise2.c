#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void trapper(int); /*一定要定义函数原形*/

main()
{
    char c;
    signal(SIGALRM,trapper);
    while(1)
    {
         printf("Please input a char\n");
         alarm(5L);
         c=getchar();
         printf("The char is %c\n",c);
    }
}

void trapper(int signum) /*一定要标明void!,与函数原形相同*/
{
   signal(signum,trapper);
   printf("You have wasted 5 secs\n");
   alarm(5L);
}
