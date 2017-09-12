#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHM_SIZE 1
#define SHM_FLAGS IPC_CREAT|0644

main(int argc,char **argv)
{
    int infd,outfd,shmid,val,count=1,status;
    char *shmaddr;
    infd=open(argv[1],O_RDONLY);
    outfd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    shmid=shmget(IPC_PRIVATE,SHM_SIZE,SHM_FLAGS);

    val=fork();
    shmaddr=shmat(shmid,0,0);


    if(val)
    {
      while(count>0)
      {
       printf("The parent count is %d\n",count);
       count=read(infd,shmaddr,SHM_SIZE);
      }
      waitpid(val,&status,0);
      shmdt(shmaddr);
      shmctl(shmid,IPC_RMID,NULL);
    }
    else
    {
      while(count>0)
      {
       count=write(outfd,shmaddr,SHM_SIZE);
       printf("The child count is %d\n",count);
      }
      shmdt(shmaddr);
    }



}
/* 这是一个失败的程序,第十七章第四题.I need more  help.*/