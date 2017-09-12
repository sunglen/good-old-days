#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

main()
{
     pid_t val;
     int statval;
     pid_t pid;


     if (val=fork()) /*启动子进程*/
     {
        printf("PID before fork(): %d\n",(int)getpid());
        pid=waitpid(val,&statval,0);
        printf("The first return pid is %d\n",pid);
        if(val=fork())
        {
        pid=waitpid(val,&statval,0);
        printf("The middle return pid is %d\n",pid);
            if(val=fork()){
            pid=waitpid(val,&statval,0);
            printf("The larst return pid is %d\n",pid);
                          }
            else
            execl("/bin/cat","cat","myfstab",0);
        }
         else
         execl("/bin/sort","sort","fstab","-o","myfstab",0);


     }

     else
        execl("/bin/cp","cp","/etc/fstab","./",0);
}



