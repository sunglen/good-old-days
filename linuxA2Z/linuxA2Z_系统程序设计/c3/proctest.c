#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

main()
{
     pid_t val;
     int statval;
     pid_t pid;

     printf("PID before fork(): %d\n",(int)getpid());

     if (val=fork()) /*启动子进程*/
     {

        pid=waitpid(val,&statval,0);
        printf("The statval is %d\n",statval);
        printf("The return pid is %d\n",pid);
        printf("Parent PID: %d\n",(int)getpid());
     }

     else
     {
        printf("Child PID: %d\n",(int)getpid());
        execl("/bin/ls","ls","-l",0);
     }
     printf("hi..we all run this code if you see this twice.\n");
}
/*在linux中先运行双亲进程*/



