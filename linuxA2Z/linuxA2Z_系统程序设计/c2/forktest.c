#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

main()
{
     pid_t val;

     printf("PID before fork(): %d\n",(int)getpid());

     if (val=fork()) /*启动子进程*/
        printf("Parent PID: %d\n",(int)getpid());
       /*   */
     else
     {
        printf("Child PID: %d\n",(int)getpid());
        execl("/bin/ls","ls","-l",0);
     }
     printf("hi..\n");
}
/*在linux中先运行双亲进程*/



