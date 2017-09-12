#include <stdio.h>
#include <unistd.h>
#include "fatal.c"

main(int argc,char **argv)
{
    int *statval;
    char enter;
    if(argc!=4)
    {
    printf("用法:make_bootdisk 格式化类型 设备类型 内核号\n例:make_bootdisk /dev/fd0H1440 /dev/fd0 2.2.13\n");
    exit(1);
    }
    printf("请插入一只1.44Mbytes的磁盘,准备好请按ENTER.\n");
    scanf("%c",&enter);
    if(enter=='\n')
    {
      if(!fork())if(execlp("fdformat","fdformat",argv[1],0)==-1)fatal("运行fdformat");
      waitpid(-1,statval,0);
      if(!fork())if(execlp("mkfs","mkfs","-t","ext2",argv[2],0)==-1)fatal("运行mkfs");
      waitpid(-1,statval,0);
      if(!fork())if(execlp("mkbootdisk","mkbootdisk","--device",argv[2],argv[3],0)==-1)fatal("运行mkbootdisk");
      waitpid(-1,statval,0);
      exit(0);
    }

}

